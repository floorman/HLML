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

#include "cmd_args.h"

#include "gen_common.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARG_HELP		"--help"
#define ARG_TYPES		"--types"
#define ARG_VECTORS		"--vectors"
#define ARG_MATRICES	"--matrices"
#define ARG_ZERO_INIT	"--zero-init"
#define ARG_SSE			"--sse"

static int ShowUsage( void ) {
	printf(
		"Args:\n"
		"    " ARG_HELP "\n"
		"        Shows this help and exits.\n"
		"\n"
		"    " ARG_TYPES "=<args> (required)\n"
		"        The vector and matrix types you want to generate (Boolean vectors will always be generated).\n"
		"        Currently, the only supported args are:\n"
		"            - int (int32_t)\n"
		"            - uint (uint32_t)\n"
		"            - float\n"
		"            - double\n"
		"        Types must be separated by comma, without spaces.\n"
		"\n"
		"    " ARG_VECTORS "=<args>\n"
		"        What size vectors you want to generate.  Min: %d, Max: %d\n"
		"\n"
		"    " ARG_MATRICES "=<args>\n"
		"        What size matrices you want to generate.  Min %d, Max: %d\n"
		"\n"
		"    " ARG_ZERO_INIT "\n"
		"        Pass this if you want vectors to have all their components initialised to 0, and all matrices to be set to identity by default.\n"
		"\n"
		"    " ARG_SSE "\n"
		"        Pass this if you want to generate SSE helper functions (currently, only __m128 is supported).\n"
		"\n"
		, GEN_COMPONENT_COUNT_MIN, GEN_COMPONENT_COUNT_MAX
		, GEN_COMPONENT_COUNT_MIN, GEN_COMPONENT_COUNT_MAX
	);

	return 1;
}

static const char* GetNextArgValue( const char* arg, const size_t arglen, char* outString, size_t* outStringLength ) {
	assert( arg );

	if ( arglen == 0 ) {
		return NULL;
	}

	const char* lastPos = arg;
	const char* next = arg;

	while ( ( next = strchr( next, ',' ) ) != NULL ) {
		size_t valuelen = (size_t) ( next - lastPos );

		strncpy( outString, lastPos, valuelen );
		outString[valuelen] = 0;

		next++;
		lastPos = next;

		if ( outStringLength ) {
			*outStringLength = valuelen;
		}

		return next;
	}

	size_t valuelen = (size_t) ( arg + arglen ) - ( (size_t) lastPos );

	strncpy( outString, lastPos, valuelen );
	outString[valuelen] = 0;

	if ( outStringLength ) {
		*outStringLength = valuelen;
	}

	return lastPos;
}

int Cmd_ParseArgs( int argc, char** argv ) {
	printf( "Parsing command line arguments...\n" );

	for ( int argIndex = 0; argIndex < argc; argIndex++ ) {
		const char* arg = argv[argIndex];
		size_t arglen = strlen( arg );

		if ( strncmp( arg, ARG_HELP, strlen( ARG_HELP ) ) == 0 ) {
			// user has passed the arg to show the help/usage text, so show it and then exit
			return ShowUsage();
		} else if ( strncmp( arg, ARG_TYPES, strlen( ARG_TYPES ) ) == 0 ) {
			// user is specifying what vector/matrix types they want to generate
			char typeStrings[GEN_TYPE_COUNT][GEN_STRING_LENGTH_TYPE_NAME];
			u32 numTypeNames = 0;

			const char* equalsPos = (const char*) strchr( arg, '=' );
			if ( !equalsPos ) {
				return ShowUsage();
			}

			equalsPos++;
			arglen -= (size_t) ( equalsPos - arg );

			char typeName[GEN_STRING_LENGTH_TYPE_NAME];
			size_t typeNameLen = 0;

			const char* next = equalsPos;

			// get each value which is separated by the commas
			while ( ( next = GetNextArgValue( next, arglen, typeName, &typeNameLen ) ) != NULL ) {
				printf( "Found type: \"%s\".\n", typeName );

				strncpy( typeStrings[numTypeNames++], typeName, typeNameLen );

				arglen -= typeNameLen;
			}

			// all the types have been found from the arg, now check they are types that the generator supports
			for ( u32 i = 0; i < numTypeNames; i++ ) {
				const char* queriedTypeName = typeStrings[i];

				bool32 found = false;

				for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
					const genType_t type = (genType_t) typeIndex;
					const char* typeString = Gen_GetTypeString( type );

					if ( strncmp( queriedTypeName, typeString, strlen( typeString ) ) == 0 ) {
						Gen_AddOptionType( &g_optionsTypes, type );

						found = true;
						break;
					}
				}

				if ( !found ) {
					printf( "ERROR: Unrecognised type \"%s\".  Please refer to the help to show which types are supported:\n", queriedTypeName );
					return ShowUsage();
				}
			}
		} else if ( strncmp( arg, ARG_VECTORS, strlen( ARG_VECTORS ) ) == 0 ) {
			// user is specifying the sizes of the vector types they want
			const char* equalsPos = (const char*) strchr( arg, '=' );
			if ( !equalsPos ) {
				return ShowUsage();
			}

			equalsPos++;
			arglen -= (size_t) ( equalsPos - arg );

			const char* next = equalsPos;

			char vectorSizeStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
			size_t vectorSizeStrLen = 0;

			// get each value which is separated by the commas
			while ( ( next = GetNextArgValue( next, arglen, vectorSizeStr, &vectorSizeStrLen ) ) != NULL ) {
				printf( "Found vector size: \"%s\".\n", vectorSizeStr );

				u32 vectorSize = strtoul( vectorSizeStr, NULL, 10 );

				if ( vectorSize < GEN_COMPONENT_COUNT_MIN || vectorSize > GEN_COMPONENT_COUNT_MAX ) {
					printf( "ERROR: Vector size specified (%s) is not within the allowed component-count that vectors can have.  Min: %d, Max: %d.\n",
						vectorSizeStr, GEN_COMPONENT_COUNT_MIN, GEN_COMPONENT_COUNT_MAX );
				}

				Gen_AddOptionVector( &g_optionsVector, vectorSize );

				arglen -= vectorSizeStrLen;
			}
		} else if ( strncmp( arg, ARG_MATRICES, strlen( ARG_MATRICES ) ) == 0 ) {
			// user is specifying the row/col combinations they want for their matrices
			const char* equalsPos = (const char*) strchr( arg, '=' );
			if ( !equalsPos ) {
				return ShowUsage();
			}

			equalsPos++;
			arglen -= (size_t) ( equalsPos - arg );

			const char* next = equalsPos;

			char matrixSizeStr[GEN_STRING_LENGTH_TYPE_NAME];
			size_t matrixSizeStrLen = 0;

			// get each value which is separated by the commas
			while ( ( next = GetNextArgValue( next, arglen, matrixSizeStr, &matrixSizeStrLen ) ) != NULL ) {
				printf( "Found matrix size: \"%s\".\n", matrixSizeStr );

				u32 numRows = 0;
				u32 numCols = 0;

				// if the row/col combo isn't in the correct format then we can't process it
				if ( sscanf( matrixSizeStr, "%dx%d", &numRows, &numCols ) == EOF ) {
					printf( "ERROR: Invalid matrix size specification: \"%s\".  Must be NxM (where N is the number of rows, and M the columns).\n", matrixSizeStr );
					return EXIT_FAILURE;
				}

				Gen_AddOptionMatrix( &g_optionsMatrix, { numRows, numCols } );

				// for non-square matrices, we have to add some more types
				if ( numRows != numCols ) {
					//	- both square types (NxN and MxM) - required for matrix-multiplication functionality
					Gen_AddOptionMatrix( &g_optionsMatrix, { numRows, numRows } );
					Gen_AddOptionMatrix( &g_optionsMatrix, { numCols, numCols } );

					// add the transposed type - required for functions like transpose() etc.
					Gen_AddOptionMatrix( &g_optionsMatrix, { numCols, numRows } );

					// because we've had to add both non-square matrix types, we now need the vector types they use
					Gen_AddOptionVector( &g_optionsVector, numRows );
					Gen_AddOptionVector( &g_optionsVector, numCols );
				}

				arglen -= matrixSizeStrLen;
			}
		} else if ( strncmp( arg, ARG_ZERO_INIT, strlen( ARG_ZERO_INIT ) ) == 0 ) {
			// user requested zero-initialisation for their types
			printf( "Zero-initialisation was requested.\n" );

			g_optionFlags |= GEN_OPTION_FLAG_ZERO_INIT;
		} else if ( strncmp( arg, ARG_SSE, strlen( ARG_SSE ) ) == 0 ) {
			// user requested SSE helpers
			printf( "SSE helpers were requested.\n" );

			g_optionFlags |= GEN_OPTION_FLAG_SSE;
		} else {
			// continue
		}
	}

	printf( "\n" );

	return 0;
}