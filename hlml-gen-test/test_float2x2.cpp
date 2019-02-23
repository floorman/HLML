/*
===========================================================================

hlml.
Copyright (c) Dan Moody 2019 - Present.

This file is part of hlml.

hlml is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

hlml is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with hlml.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

// GENERATED FILE.  DO NOT EDIT.

#include "../out/gen/hlml_functions_matrix.h"

#include <temper.h>

TEMPER_TEST( TestAssignment_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestArithmetic_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestArray_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestRelational_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestIdentity_float2x2 ) {
	float2x2 id = float2x2(
		1.0f, 0.0f,
		0.0f, 1.0f
	);

	float2x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestInverse_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestDeterminant_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestTranslate_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestRotate_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_float2x2 ) {
	TEMPER_SKIP_TEST( TestAssignment_float2x2, "TODO" );
	TEMPER_SKIP_TEST( TestArithmetic_float2x2, "TODO" );
	TEMPER_SKIP_TEST( TestArray_float2x2, "TODO" );
	TEMPER_SKIP_TEST( TestRelational_float2x2, "TODO" );

	TEMPER_RUN_TEST( TestIdentity_float2x2 );
	TEMPER_SKIP_TEST( TestTranspose_float2x2, "TODO" );

	TEMPER_SKIP_TEST( TestInverse_float2x2, "TODO" );
	TEMPER_SKIP_TEST( TestDeterminant_float2x2, "TODO" );

	TEMPER_SKIP_TEST( TestTranslate_float2x2, "TODO" );
	TEMPER_SKIP_TEST( TestRotate_float2x2, "TODO" );
	TEMPER_SKIP_TEST( TestScale_float2x2, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_float2x2, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_float2x2, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_float2x2, "TODO" );
};