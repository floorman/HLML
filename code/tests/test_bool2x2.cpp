/*
===========================================================================

HLML.

MIT License

Copyright (c) 2019 Dan Moody

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

===========================================================================
*/

// THIS FILE WAS AUTOMATICALLY GENERATED BY A TOOL.
// EDITING THIS FILE MAY CAUSE SIDE EFFECTS.
// DO SO AT YOUR OWN RISK.

#include "../../code/out/gen/hlml_functions_matrix.h"

#include <temper/temper.h>

static bool2x2 g_identityMatrix;

static bool2x2 g_matrixMulLHS = bool2x2(
		true, true,
		true, true
	);
static bool2x2 g_matrixMulRHS = bool2x2(
		true, true,
		true, true
	);
static bool2x2 g_matrixMulAnswer = bool2x2(
		true, true,
		true, true
	);

TEMPER_TEST( TestAssignment_bool2x2 )
{
	bool2x2 mat;

	// fill single value
	mat = bool2x2( true );
	TEMPER_EXPECT_TRUE( mat[0] == bool2( true, false ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool2( false, true ) );

	// row filling
	mat = bool2x2(
		bool2( false, true ),
		bool2( true, true )
	);
	TEMPER_EXPECT_TRUE( mat[0] == bool2( false, true ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool2( true, true ) );

	// all values filled
	mat = bool2x2(
		true, true,
		true, true
	);
	TEMPER_EXPECT_TRUE( mat[0] == bool2( true, true ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool2( true, true ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_bool2x2 )
{
	bool2x2 mat;

	TEMPER_EXPECT_TRUE( mat[0] == bool2( true, false ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool2( false, true ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_Scalar_bool2x2 )
{
	bool2x2 id = bool2x2(
		true, false,
		false, true
	);

	bool2x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_Scalar_bool2x2 )
{
	bool2x2 mat = bool2x2(
		false, true,
		true, true
	);
	bool2x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == bool2x2(
		false, true,
		true, true
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_bool2x2 )
{
	TEMPER_RUN_TEST( TestAssignment_bool2x2 );
	TEMPER_RUN_TEST( TestArray_bool2x2 );
	TEMPER_RUN_TEST( TestIdentity_Scalar_bool2x2 );
	TEMPER_RUN_TEST( TestTranspose_Scalar_bool2x2 );
}
