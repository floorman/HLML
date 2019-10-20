/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

The HLML Generator is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

The HLML Generator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The HLML Generator.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

#include "defines.h"
#include "allocator.h"
#include "string_builder.h"

#include "GeneratorVector.h"
#include "GeneratorMatrix.h"

#include "GeneratorScalarTests.h"
#include "GeneratorVectorTests.h"
#include "GeneratorMatrixTests.h"

#include "gen_common.h"
#include "gen_common_sse.h"

#include "gen_funcs_vector.h"
#include "gen_funcs_vector_sse.h"
#include "gen_funcs_matrix.h"
#include "gen_funcs_matrix_sse.h"

#include "os_process.h"

#include "file_io.h"

#include "timer.h"

#include "cmd_args.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static void GenerateTypeHeader( void ) {
	char headerFilePath[1024] = { 0 };
	snprintf( headerFilePath, 1024, "%s%s", GEN_OUT_FOLDER_PATH, GEN_HEADER_TYPES );

	stringBuilder_t sb = String_Create( 2 * KB_TO_BYTES );

	String_Append( &sb, GEN_FILE_HEADER );
	String_Append( &sb,
		"#pragma once\n"
		"\n"
		"#include <stdint.h>\n"
		"\n"
		"// ensure that a bool is 4 bytes\n"
		"typedef uint32_t bool32_t;\n" );

	FS_WriteEntireFile( headerFilePath, sb.str, sb.length );

	Mem_Reset();
}

static void GenerateVectors( void ) {
	GeneratorVector gen;

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 componentIndex = 0; componentIndex < g_optionsVector.vectorSizesCount; componentIndex++ ) {
			u32 numComponents = g_optionsVector.vectorSizes[componentIndex];

			printf( "Generating %s%d...", typeString, numComponents );

			gen.Generate( type, numComponents );

			printf( "OK.\n" );
		}
	}
}

static void GenerateMatrices( void ) {
	GeneratorMatrix gen;

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 sizeIndex = 0; sizeIndex < g_optionsMatrix.count; sizeIndex++ ) {
			matrixSize_t* size = &g_optionsMatrix.sizes[sizeIndex];

			u32 numRows = size->numRows;
			u32 numCols = size->numCols;

			printf( "Generating %s%dx%d...", typeString, numRows, numCols );

			gen.Generate( type, numRows, numCols );

			printf( "OK.\n" );
		}
	}
}

static void GenerateFunctionsScalar( void ) {
	char fileNameHeader[1024];
	snprintf( fileNameHeader, 1024, "%s%s", GEN_OUT_GEN_FOLDER_PATH, GEN_HEADER_FUNCTIONS_SCALAR );

	stringBuilder_t sb = String_Create( 8 * KB_TO_BYTES );

	String_Append( &sb, GEN_FILE_HEADER );
	String_Append( &sb,
		"#pragma once\n"
		"\n"
		"#include \"../" GEN_HEADER_CONSTANTS "\"\n"
		"\n"
		"#include <math.h>\n"
		"#include <stdint.h>\n"
		"\n" );

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		const char* memberTypeString = Gen_GetMemberTypeString( type );

		printf( "Generating %s...", memberTypeString );

		String_Append( &sb, "// " );
		String_Append( &sb, memberTypeString );
		String_Append( &sb, "\n" );

		// scalar only funcs
		Gen_Floateq( type, &sb );

		Gen_Sign( type, &sb );

		Gen_Radians( type, &sb );
		Gen_Degrees( type, &sb );

		Gen_MinMax( type, &sb );
		Gen_Clamp( type, &sb );

		// generic/scalar/vector funcs
		Gen_Saturate( type, 1, &sb );

		Gen_Lerp( type, 1, &sb );

		Gen_Step( type, 1, &sb );
		Gen_Smoothstep( type, 1, &sb );

		String_Append( &sb, "\n" );

		printf( "OK.\n" );
	}

	FS_WriteEntireFile( fileNameHeader, sb.str, sb.length );

	Mem_Reset();
}

static void GenerateFunctionsVector( void ) {
	char filePathHeader[64] = { 0 };
	snprintf( filePathHeader, 64, "%s%s", GEN_OUT_GEN_FOLDER_PATH, GEN_HEADER_FUNCTIONS_VECTOR );

	stringBuilder_t contentHeader = String_Create( 32 * KB_TO_BYTES );

	String_Append( &contentHeader, GEN_FILE_HEADER );
	String_Append( &contentHeader,
		"#pragma once\n"
		"\n" );

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 componentIndex = 0; componentIndex < g_optionsVector.vectorSizesCount; componentIndex++ ) {
			u32 numComponents = g_optionsVector.vectorSizes[componentIndex];

			String_Appendf( &contentHeader, "#include \"%s%d.h\"\n", typeString, numComponents );
		}

		String_Appendf( &contentHeader, "\n" );
	}

	String_Appendf( &contentHeader, "#include \"" GEN_HEADER_FUNCTIONS_SCALAR "\"\n" );
	String_Appendf( &contentHeader, "#include \"" GEN_HEADER_OPERATORS_VECTOR "\"\n" );
	String_Appendf( &contentHeader, "\n" );

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 componentIndex = 0; componentIndex < g_optionsVector.vectorSizesCount; componentIndex++ ) {
			u32 numComponents = g_optionsVector.vectorSizes[componentIndex];

			printf( "Algebra %s%d...", typeString, numComponents );

			String_Appendf( &contentHeader, "// %s%d\n", typeString, numComponents );

			// generic/scalar funcs
			Gen_Saturate( type, numComponents, &contentHeader );
			Gen_Lerp( type, numComponents, &contentHeader );

			Gen_Step( type, numComponents, &contentHeader );
			Gen_Smoothstep( type, numComponents, &contentHeader );

			// generic/scalar/vector funcs
			Gen_VectorLength( type, numComponents, &contentHeader );
			Gen_VectorNormalize( type, numComponents, &contentHeader );
			Gen_VectorDot( type, numComponents, &contentHeader );
			Gen_VectorCross( type, numComponents, &contentHeader );
			Gen_VectorAngle( type, numComponents, &contentHeader );
			Gen_VectorDistance( type, numComponents, &contentHeader );
			Gen_VectorPack( type, numComponents, &contentHeader );
			Gen_VectorUnpack( type, numComponents, &contentHeader );

			String_Append( &contentHeader, "\n" );

			printf( "OK.\n" );
		}
	}

	FS_WriteEntireFile( filePathHeader, contentHeader.str, contentHeader.length );

	Mem_Reset();
}

static void GenerateFunctionsMatrix( void ) {
	char filePathHeader[64] = { 0 };
	snprintf( filePathHeader, 64, "%s%s", GEN_OUT_GEN_FOLDER_PATH, GEN_HEADER_FUNCTIONS_MATRIX );

	stringBuilder_t contentHeader = String_Create( 128 * KB_TO_BYTES );
	String_Append( &contentHeader, GEN_FILE_HEADER );
	String_Append( &contentHeader,
		"#pragma once\n"
		"\n" );

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 sizeIndex = 0; sizeIndex < g_optionsMatrix.count; sizeIndex++ ) {
			matrixSize_t* size = &g_optionsMatrix.sizes[sizeIndex];

			u32 numRows = size->numRows;
			u32 numCols = size->numCols;

			String_Appendf( &contentHeader, "#include \"%s%dx%d.h\"\n", typeString, numRows, numCols );
		}

		String_Appendf( &contentHeader, "\n" );
	}

	String_Appendf( &contentHeader, "#include \"" GEN_HEADER_FUNCTIONS_VECTOR "\"\n" );
	String_Appendf( &contentHeader, "#include \"" GEN_HEADER_OPERATORS_MATRIX "\"\n" );
	String_Appendf( &contentHeader, "\n" );

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		for ( u32 sizeIndex = 0; sizeIndex < g_optionsMatrix.count; sizeIndex++ ) {
			matrixSize_t* size = &g_optionsMatrix.sizes[sizeIndex];

			u32 numRows = size->numRows;
			u32 numCols = size->numCols;

			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
			Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

			printf( "Basic functions %s...", fullTypeName );

			String_Appendf( &contentHeader, "// %s\n", fullTypeName );

			Gen_MatrixIdentity( type, numRows, numCols, &contentHeader );
			Gen_MatrixTranspose( type, numRows, numCols, &contentHeader );

			Gen_MatrixDeterminant( type, numRows, numCols, &contentHeader );
			Gen_MatrixInverse( type, numRows, numCols, &contentHeader );

			Gen_MatrixCompMulDiv( type, numRows, numCols, &contentHeader );

			Gen_MatrixTranslate( type, numRows, numCols, &contentHeader );
			Gen_MatrixRotate( type, numRows, numCols, &contentHeader );
			Gen_MatrixScale( type, numRows, numCols, &contentHeader );

			Gen_MatrixOrtho( type, numRows, numCols, &contentHeader );
			Gen_MatrixPerspective( type, numRows, numCols, &contentHeader );
			Gen_MatrixLookAt( type, numRows, numCols, &contentHeader );

			String_Append( &contentHeader, "\n" );

			printf( "OK.\n" );
		}
	}

	FS_WriteEntireFile( filePathHeader, contentHeader.str, contentHeader.length );

	Mem_Reset();
}

static void GenerateFunctionsScalarSSE( void ) {
	if ( ( g_optionFlags & GEN_OPTION_FLAG_SSE ) == 0 ) {
		return;
	}

	char filePathHeader[64] = { 0 };
	snprintf( filePathHeader, 64, "%s%s.h", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_FUNCTIONS_SCALAR_SSE );

	stringBuilder_t contentHeader = String_Create( 4 * KB_TO_BYTES );
	String_Append( &contentHeader, GEN_FILE_HEADER );
	String_Append( &contentHeader,
		"#pragma once\n"
		"\n"
		"// HLML includes\n"
		"#include \"../hlml_constants_sse.h\"\n"
		"\n"
		"// others\n"
		"#include <xmmintrin.h>\n"
		"#include <assert.h>\n"
		"\n"
	);

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( !Gen_TypeSupportsSSE( type ) ) {
			continue;
		}

		const char* memberTypeString = Gen_GetMemberTypeString( type );

		printf( "SIMD vector functions %s...", memberTypeString );

		String_Appendf( &contentHeader, "// %s\n", memberTypeString );

		Gen_SSE_Radians( type, &contentHeader );
		Gen_SSE_Degrees( type, &contentHeader );

		Gen_SSE_Lerp( type, 1, &contentHeader );

		String_Append( &contentHeader, "\n" );

		printf( "OK.\n" );
	}

	FS_WriteEntireFile( filePathHeader, contentHeader.str, contentHeader.length );

	Mem_Reset();
}

static void GenerateFunctionsVectorSSE( void ) {
	if ( ( g_optionFlags & GEN_OPTION_FLAG_SSE ) == 0 ) {
		return;
	}

	char filePathHeader[64] = { 0 };
	snprintf( filePathHeader, 64, "%s%s.h", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_FUNCTIONS_VECTOR_SSE );

	stringBuilder_t contentHeader = String_Create( 16 * KB_TO_BYTES );

	String_Append( &contentHeader, GEN_FILE_HEADER );
	String_Append( &contentHeader,
		"#pragma once\n"
		"\n"
		"// HLML includes\n"
		"#include \"" GEN_FILENAME_FUNCTIONS_VECTOR_SSE ".h\"\n"
		"#include \"../" GEN_HEADER_CONSTANTS_SSE "\"\n"
		"\n"
		"#include <immintrin.h>\n"
		"\n"
	);

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( !Gen_TypeSupportsSSE( type ) ) {
			continue;
		}

		const char* registerName = Gen_SSE_GetRegisterName( type );

		for ( u32 componentIndex = 0; componentIndex < g_optionsVector.vectorSizesCount; componentIndex++ ) {
			u32 numComponents = g_optionsVector.vectorSizes[componentIndex];

			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
			Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

			char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
			Gen_SSE_GetFullTypeName( fullTypeName, sseTypeName );

			String_Appendf( &contentHeader, "// %s\n", fullTypeName );
			String_Appendf( &contentHeader, "struct %s\n", sseTypeName );
			String_Append(  &contentHeader, "{\n" );
			for ( u32 i = 0; i < numComponents; i++ ) {
				String_Appendf( &contentHeader, "\t%s %c;\n", registerName, GEN_COMPONENT_NAMES_VECTOR[i] );
			}
			String_Append(  &contentHeader, "};\n" );
			String_Append(  &contentHeader, "\n" );
		}
	}

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( !Gen_TypeSupportsSSE( type ) ) {
			continue;
		}

		for ( u32 componentIndex = 0; componentIndex < g_optionsVector.vectorSizesCount; componentIndex++ ) {
			u32 numComponents = g_optionsVector.vectorSizes[componentIndex];

			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
			Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

			printf( "SIMD vector functions %s...", fullTypeName );

			char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
			Gen_SSE_GetFullTypeName( fullTypeName, sseTypeName );

			String_Appendf( &contentHeader, "// %s\n", fullTypeName );
			Gen_SSE_VectorDot( type, numComponents, &contentHeader );
			Gen_SSE_VectorCross( type, numComponents, &contentHeader );
			Gen_SSE_VectorLength( type, numComponents, &contentHeader );
			Gen_SSE_VectorNormalize( type, numComponents, &contentHeader );
			Gen_SSE_VectorDistance( type, numComponents, &contentHeader );
			// Gen_SSE_VectorAngle( type, numComponents, &contentHeader );

			String_Append( &contentHeader, "\n" );

			printf( "OK.\n" );
		}
	}

	FS_WriteEntireFile( filePathHeader, contentHeader.str, contentHeader.length );

	Mem_Reset();
}

static void GenerateFunctionsMatrixSSE( void ) {
	if ( ( g_optionFlags & GEN_OPTION_FLAG_SSE ) == 0 ) {
		return;
	}

	char filePathHeader[64] = { 0 };
	snprintf( filePathHeader, 64, "%s%s.h", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_FUNCTIONS_MATRIX_SSE );

	stringBuilder_t contentHeader = String_Create( 80 * KB_TO_BYTES );

	String_Append( &contentHeader, GEN_FILE_HEADER );
	String_Append( &contentHeader,
		"#pragma once\n"
		"\n"
		"#include <immintrin.h>\n"
		"\n"
		"#include \"" GEN_FILENAME_FUNCTIONS_VECTOR_SSE ".h\"\n"
		"\n"
	);

	Gen_SSE_MacroNegate( GEN_TYPE_FLOAT, &contentHeader );

	// generate type forward declarations
	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( !Gen_TypeSupportsSSE( type ) ) {
			continue;
		}

		const char* registerName = Gen_SSE_GetRegisterName( type );

		for ( u32 sizeIndex = 0; sizeIndex < g_optionsMatrix.count; sizeIndex++ ) {
			matrixSize_t* size = &g_optionsMatrix.sizes[sizeIndex];

			u32 numRows = size->numRows;
			u32 numCols = size->numCols;

			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
			Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

			char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
			Gen_SSE_GetFullTypeName( fullTypeName, sseTypeName );

			String_Appendf( &contentHeader, "// %s\n", fullTypeName );
			String_Appendf( &contentHeader, "struct %s\n", sseTypeName );
			String_Append(  &contentHeader, "{\n" );
			String_Appendf( &contentHeader, "\t%s m[%d][%d];\n", registerName, numRows, numCols );
			String_Append(  &contentHeader, "};\n" );
			String_Append(  &contentHeader, "\n" );
		}
	}
	String_Appendf( &contentHeader, "\n" );

	// generate functions
	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( !Gen_TypeSupportsSSE( type ) ) {
			continue;
		}

		for ( u32 sizeIndex = 0; sizeIndex < g_optionsMatrix.count; sizeIndex++ ) {
			matrixSize_t* size = &g_optionsMatrix.sizes[sizeIndex];

			u32 numRows = size->numRows;
			u32 numCols = size->numCols;

			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
			Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

			printf( "SIMD matrix functions %s...", fullTypeName );

			String_Appendf( &contentHeader, "// %s\n", fullTypeName );

			Gen_SSE_MatrixIdentity( type, numRows, numCols, &contentHeader );
			Gen_SSE_MatrixTranspose( type, numRows, numCols, &contentHeader );

			Gen_SSE_MatrixDeterminant( type, numRows, numCols, &contentHeader );
			Gen_SSE_MatrixInverse( type, numRows, numCols, &contentHeader );

			for ( u32 opIndex = 0; opIndex < GEN_OP_ARITHMETIC_COUNT; opIndex++ ) {
				genOpArithmetic_t op = (genOpArithmetic_t) opIndex;
				Gen_SSE_MatrixArithmeticComponentWise( type, numRows, numCols, op, &contentHeader );
			}

			Gen_SSE_MatrixMultiply( type, numRows, numCols, &contentHeader );

			Gen_SSE_MatrixTranslate( type, numRows, numCols, &contentHeader );
			// Gen_SSE_MatrixRotate( type, numRows, numCols, &contentHeader );
			Gen_SSE_MatrixScale( type, numRows, numCols, &contentHeader );

			String_Append( &contentHeader, "\n" );

			printf( "OK.\n" );
		}
	}

	FS_WriteEntireFile( filePathHeader, contentHeader.str, contentHeader.length );

	Mem_Reset();
}

static void GenerateOperatorsVector( void ) {
	char filePathHeader[64] = { 0 };
	snprintf( filePathHeader, 64, "%s%s", GEN_OUT_GEN_FOLDER_PATH, GEN_HEADER_OPERATORS_VECTOR );

	stringBuilder_t contentHeader = String_Create( 128 * KB_TO_BYTES );
	String_Append( &contentHeader, GEN_FILE_HEADER );
	String_Append( &contentHeader, "#pragma once\n" );
	String_Append( &contentHeader, "\n" );

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 componentIndex = 0; componentIndex < g_optionsVector.vectorSizesCount; componentIndex++ ) {
			u32 numComponents = g_optionsVector.vectorSizes[componentIndex];

			String_Appendf( &contentHeader, "#include \"%s%d.h\"\n", typeString, numComponents );
		}

		String_Append( &contentHeader, "\n" );
	}

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		for ( u32 componentIndex = 0; componentIndex < g_optionsVector.vectorSizesCount; componentIndex++ ) {
			u32 numComponents = g_optionsVector.vectorSizes[componentIndex];

			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
			Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

			printf( "Vector operators %s...", fullTypeName );

			String_Appendf( &contentHeader, "// %s\n", fullTypeName );

			Gen_VectorOperatorsArithmetic( type, numComponents, &contentHeader );
			Gen_OperatorsIncrement( type, 1, numComponents, &contentHeader );
			Gen_OperatorsRelational( type, 1, numComponents, &contentHeader );
			Gen_OperatorsBitwise( type, 1, numComponents, &contentHeader );

			String_Append( &contentHeader, "\n" );

			printf( "OK.\n" );
		}
	}

	FS_WriteEntireFile( filePathHeader, contentHeader.str, contentHeader.length );

	Mem_Reset();
}

static void GenerateOperatorsMatrix( void ) {
	char filePathHeader[64];
	snprintf( filePathHeader, 64, "%s%s", GEN_OUT_GEN_FOLDER_PATH, GEN_HEADER_OPERATORS_MATRIX );

	stringBuilder_t contentHeader = String_Create( 512 * KB_TO_BYTES );
	String_Append( &contentHeader, GEN_FILE_HEADER );
	String_Append( &contentHeader, "#pragma once\n" );
	String_Append( &contentHeader, "\n" );

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 sizeIndex = 0; sizeIndex < g_optionsMatrix.count; sizeIndex++ ) {
			matrixSize_t* size = &g_optionsMatrix.sizes[sizeIndex];

			u32 numRows = size->numRows;
			u32 numCols = size->numCols;

			String_Appendf( &contentHeader, "#include \"%s%dx%d.h\"\n", typeString, numRows, numCols );
		}

		String_Append( &contentHeader, "\n" );
	}

	String_Append( &contentHeader, "#include \"" GEN_HEADER_FUNCTIONS_VECTOR "\"\n" );
	String_Append( &contentHeader, "\n" );

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		for ( u32 sizeIndex = 0; sizeIndex < g_optionsMatrix.count; sizeIndex++ ) {
			matrixSize_t* size = &g_optionsMatrix.sizes[sizeIndex];

			u32 numRows = size->numRows;
			u32 numCols = size->numCols;

			if ( numRows != numCols ) {
				continue;
			}

			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
			Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

			String_Appendf( &contentHeader, "%s inverse( const %s& mat );\n", fullTypeName, fullTypeName );
		}

		String_Append( &contentHeader, "\n" );
	}

	// header and inl code
	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		for ( u32 sizeIndex = 0; sizeIndex < g_optionsMatrix.count; sizeIndex++ ) {
			matrixSize_t* size = &g_optionsMatrix.sizes[sizeIndex];

			u32 numRows = size->numRows;
			u32 numCols = size->numCols;

			char fullTypeName[64];
			Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

			printf( "Matrix operators %s...", fullTypeName );

			String_Appendf( &contentHeader, "// %s\n", fullTypeName );

			Gen_MatrixOperatorsArithmetic( type, numRows, numCols, &contentHeader );
			Gen_OperatorsIncrement( type, numRows, numCols, &contentHeader );
			Gen_OperatorsRelational( type, numRows, numCols, &contentHeader );
			Gen_OperatorsBitwise( type, numRows, numCols, &contentHeader );

			String_Append( &contentHeader, "\n" );

			printf( "OK.\n" );
		}
	}

	FS_WriteEntireFile( filePathHeader, contentHeader.str, contentHeader.length );

	Mem_Reset();
}

static void GenerateTestsScalar( void ) {
	GeneratorScalarTest gen;

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		const char* typeString = Gen_GetTypeString( type );

		printf( "Generating test_scalar_%s.cpp...", typeString );

		gen.Generate( type );

		printf( "OK.\n" );
	}
}

static void GenerateTestsVector( void ) {
	GeneratorVectorTests gen;

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 componentIndex = 0; componentIndex < g_optionsVector.vectorSizesCount; componentIndex++ ) {
			u32 numComponents = g_optionsVector.vectorSizes[componentIndex];

			printf( "Generating test_%s%d.cpp...", typeString, numComponents );

			gen.Generate( type, numComponents );

			printf( "OK.\n" );
		}
	}
}

static void GenerateTestsMatrix( void ) {
	GeneratorMatrixTests gen;

	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 sizeIndex = 0; sizeIndex < g_optionsMatrix.count; sizeIndex++ ) {
			matrixSize_t* size = &g_optionsMatrix.sizes[sizeIndex];

			u32 numRows = size->numRows;
			u32 numCols = size->numCols;

			printf( "Generating test_%s%dx%d.cpp...", typeString, numRows, numCols );

			gen.Generate( type, numRows, numCols );

			printf( "OK.\n" );
		}
	}
}

static void GenerateTestsMain( void ) {
	char filePathMain[1024] = { 0 };
	snprintf( filePathMain, 1024, "%smain.cpp", GEN_TESTS_FOLDER_PATH );

	stringBuilder_t sb = String_Create( 8 * KB_TO_BYTES );

	String_Append( &sb, GEN_FILE_HEADER );

	String_Append( &sb, "#define NOMINMAX\n" );
	String_Append( &sb, "\n" );

	// TODO(DM): if we do end up using this as our final include solution, make the filename a constant
	String_Append( &sb, "#include \"hlml.h\"\n" );
	String_Append( &sb, "\n" );

	String_Append( &sb, "#include <temper/temper.h>\n" );
	String_Append( &sb, "\n" );

	// scalar tests
	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		const char* memberTypeString = Gen_GetMemberTypeString( type );

		String_Appendf( &sb, "#include \"test_scalar_%s.cpp\"\n", memberTypeString );
	}

	String_Append( &sb, "\n" );

	// vector tests
	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		for ( u32 componentIndex = 0; componentIndex < g_optionsVector.vectorSizesCount; componentIndex++ ) {
			u32 numComponents = g_optionsVector.vectorSizes[componentIndex];

			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
			Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

			String_Appendf( &sb, "#include \"test_%s.cpp\"\n", fullTypeName );
		}

		String_Append( &sb, "\n" );
	}

	// matrix tests
	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		for ( u32 sizeIndex = 0; sizeIndex < g_optionsMatrix.count; sizeIndex++ ) {
			matrixSize_t* size = &g_optionsMatrix.sizes[sizeIndex];

			u32 numRows = size->numRows;
			u32 numCols = size->numCols;

			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
			Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

			String_Appendf( &sb, "#include \"test_%s.cpp\"\n", fullTypeName );
		}

		String_Append( &sb, "\n" );
	}

	String_Append( &sb, "static void OnSuiteEnd( void* userdata )\n" );
	String_Append( &sb, "{\n" );
	String_Append( &sb, "\t( (void) userdata );\n" );
	String_Append( &sb, "\tprintf( \"\\n\" );\n" );
	String_Append( &sb, "}\n" );
	String_Append( &sb, "\n" );

	String_Append( &sb, "TEMPER_DEFS();\n" );
	String_Append( &sb, "\n" );

	String_Append( &sb, "int main( int argc, char** argv )\n" );
	String_Append( &sb, "{\n" );
	String_Append( &sb, "\tTEMPER_SET_COMMAND_LINE_ARGS( argc, argv );\n" );
	String_Append( &sb, "\n" );
	String_Append( &sb, "\tTEMPER_SET_SUITE_END_CALLBACK( OnSuiteEnd, nullptr );\n" );
	String_Append( &sb, "\n" );

	// run the scalar tests first
	// the vector/matrix functions make heavy use of these per-component
	// so if these fail, the problem might be easier to diagnose
	String_Append( &sb, "\t// scalar tests\n" );
	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		String_Appendf( &sb, "\tTEMPER_RUN_SUITE( Test_%s );\n", Gen_GetMemberTypeString( type ) );
	}

	String_Append( &sb, "\n" );

	// now do vector and matrix types
	String_Appendf( &sb, "\t// vector tests\n" );
	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		for ( u32 sizeIndex = 0; sizeIndex < g_optionsVector.vectorSizesCount; sizeIndex++ ) {
			u32 numComponents = g_optionsVector.vectorSizes[sizeIndex];

			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
			Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

			String_Appendf( &sb, "\tTEMPER_RUN_SUITE( Test_%s );\n", fullTypeName );
		}

		String_Appendf( &sb, "\n" );
	}

	String_Appendf( &sb, "\t// matrix tests\n" );
	for ( u32 typeIndex = 0; typeIndex < g_optionsTypes.typesCount; typeIndex++ ) {
		genType_t type = (genType_t) g_optionsTypes.types[typeIndex];

		for ( u32 sizeIndex = 0; sizeIndex < g_optionsMatrix.count; sizeIndex++ ) {
			matrixSize_t* size = &g_optionsMatrix.sizes[sizeIndex];

			u32 numRows = size->numRows;
			u32 numCols = size->numCols;

			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
			Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

			String_Appendf( &sb, "\tTEMPER_RUN_SUITE( Test_%s );\n", fullTypeName );
		}

		String_Appendf( &sb, "\n" );
	}

	String_Append( &sb, "\tTEMPER_SHOW_STATS();\n" );
	String_Append( &sb, "\n" );
	String_Append( &sb, "\treturn TEMPER_EXIT_CODE();\n" );
	String_Append( &sb, "}" );
	String_Append( &sb, "\n" );

	FS_WriteEntireFile( filePathMain, sb.str, sb.length );

	Mem_Reset();
}

// DM: running doxygen on MacOS isn't supported yet because I don't have access to a Mac
// when I get access to one, I'll get it working
#ifdef _WIN32
static bool32 GenerateDoxygenPages( void ) {
	printf( "Generating doxygen documentation..." );

	const char* doxygenPath = NULL;
#if defined( _WIN32 )
	doxygenPath = "doxygen/windows/doxygen.exe";
#elif defined( __linux__ )
	doxygenPath = "doxygen/linux/doxygen";
#elif defined( __APPLE__ )
	doxygenPath = "doxygen/macos/doxygen";
#endif // defined( _WIN32 )

	const char* args[] = {
		"doxygen/config"
	};

	process_t doxygenProc = OS_StartProcess( doxygenPath, args, _countof( args ) );

	if ( !doxygenProc.ptr ) {
		return false;
	}

	if ( OS_WaitForProcess( doxygenProc ) != 0 ) {
		return false;
	}

	printf( "OK.\n" );

	return true;
}
#endif // _WIN32

int main( int argc, char** argv ) {
	printf( "HLML Generator.\n" );
	printf( "(c) Dan Moody 2019 - Present.\n" );
	printf( "\n" );

	// init generator to default options
	{
		memset( &g_optionsTypes, 0, sizeof( g_optionsTypes ) );
		// bool vectors/matrices are always generated
		Gen_AddOptionType( &g_optionsTypes, GEN_TYPE_BOOL );

		memset( &g_optionsVector, 0, sizeof( g_optionsVector ) );
		memset( &g_optionsMatrix, 0, sizeof( g_optionsMatrix ) );

		g_optionFlags = 0;
	}

	if ( Cmd_ParseArgs( argc, argv ) != 0 ) {
		return EXIT_FAILURE;
	}

	printf( "Generating...\n" );
	printf( "\n" );

	FS_DeleteAllFilesInFolder( GEN_OUT_GEN_FOLDER_PATH );
	FS_CreateFolder( GEN_OUT_GEN_FOLDER_PATH );

	FS_CreateFolder( GEN_TESTS_FOLDER_PATH );

	printf( "\n" );

	Mem_Init( 2 * MB_TO_BYTES );

	Time_Init();

	float64 start = Time_NowMS();

	printf( "======= Generating core headers. =======\n" );
	GenerateTypeHeader();
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating types. =======\n" );
	GenerateVectors();
	GenerateMatrices();
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating functions. =======\n" );
	GenerateFunctionsScalar();
	GenerateFunctionsVector();
	GenerateFunctionsMatrix();
	GenerateFunctionsScalarSSE();
	GenerateFunctionsVectorSSE();
	GenerateFunctionsMatrixSSE();
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating operators. =======\n" );
	GenerateOperatorsVector();
	GenerateOperatorsMatrix();
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating tests. =======\n" );
	GenerateTestsScalar();
	GenerateTestsVector();
	GenerateTestsMatrix();
	GenerateTestsMain();
	printf( "======= Done. =======\n\n" );

	float64 end = Time_NowMS();

	printf( "Code generation time taken: %f ms\n", end - start );

	printf( "\n" );

	// DM: temporarily turning off documentation generation for all non-windows configs
	// because GitHub has a limit on LFS space, which the doxygen executable for linux exceeds
	// TODO(DM): turn this back on when a solution for that gets found
#ifdef _WIN32
	printf( "======= Generating doxygen documentation pages. =======\n" );
	if ( !GenerateDoxygenPages() ) {
		return EXIT_FAILURE;
	}
	printf( "======= Done. =======\n\n" );
#endif

	printf( "Generation finished.\n" );

	Mem_Shutdown();

	return 0;
}
