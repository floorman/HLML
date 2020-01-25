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

TEMPER_TEST( TestAssignment_bool3x3, void )
{
	bool3x3 mat;

	mat.rows[0] = bool3( true, false, false );
	mat.rows[1] = bool3( false, true, false );
	mat.rows[2] = bool3( false, false, true );

	TEMPER_EXPECT_TRUE( mat.rows[0].x == true );
	TEMPER_EXPECT_TRUE( mat.rows[0].y == false );
	TEMPER_EXPECT_TRUE( mat.rows[0].z == false );
	TEMPER_EXPECT_TRUE( mat.rows[1].x == false );
	TEMPER_EXPECT_TRUE( mat.rows[1].y == true );
	TEMPER_EXPECT_TRUE( mat.rows[1].z == false );
	TEMPER_EXPECT_TRUE( mat.rows[2].x == false );
	TEMPER_EXPECT_TRUE( mat.rows[2].y == false );
	TEMPER_EXPECT_TRUE( mat.rows[2].z == true );

	TEMPER_PASS();
}

TEMPER_TEST( TestCtor_bool3x3, void )
{
	bool3x3 mat;

	// fill single value
	mat = bool3x3( true );
	TEMPER_EXPECT_TRUE( mat[0] == bool3( true, false, false ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool3( false, true, false ) );
	TEMPER_EXPECT_TRUE( mat[2] == bool3( false, false, true ) );

	// row filling
	mat = bool3x3(
		bool3( false, true, true ),
		bool3( true, true, true ),
		bool3( true, true, true )
	);
	TEMPER_EXPECT_TRUE( mat[0] == bool3( false, true, true ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool3( true, true, true ) );
	TEMPER_EXPECT_TRUE( mat[2] == bool3( true, true, true ) );

	// all values filled
	mat = bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	);
	TEMPER_EXPECT_TRUE( mat[0] == bool3( true, true, true ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool3( true, true, true ) );
	TEMPER_EXPECT_TRUE( mat[2] == bool3( true, true, true ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_bool3x3, void )
{
	bool3x3 mat;
	identity( mat );

	TEMPER_EXPECT_TRUE( mat[0] == bool3( true, false, false ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool3( false, true, false ) );
	TEMPER_EXPECT_TRUE( mat[2] == bool3( false, false, true ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_Scalar_bool3x3, void )
{
	bool3x3 id;
	id[0] = bool3( true, false, false );
	id[1] = bool3( false, true, false );
	id[2] = bool3( false, false, true );

	bool3x3 mat;

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_Scalar_bool3x3, void )
{
	bool3x3 answerTransposed = bool3x3(
		false, true, true,
		true, true, true,
		true, true, true
	);

	bool3x3 mat = bool3x3(
		false, true, true,
		true, true, true,
		true, true, true
	);
	bool3x3 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == answerTransposed );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_bool3x3 )
{
	TEMPER_RUN_TEST( TestAssignment_bool3x3 );
	TEMPER_RUN_TEST( TestCtor_bool3x3 );
	TEMPER_RUN_TEST( TestArray_bool3x3 );
	TEMPER_RUN_TEST( TestIdentity_Scalar_bool3x3 );
	TEMPER_RUN_TEST( TestTranspose_Scalar_bool3x3 );
}
