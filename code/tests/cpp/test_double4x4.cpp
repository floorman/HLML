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

static double4x4 g_matrixMulLHS_double4x4    = double4x4( 		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000, 18.000000
 );

static double4x4 g_matrixMulRHS_double4x4    = double4x4( 		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000, 6.000000
 );

static double4x4 g_matrixMulAnswer_double4x4 = double4x4( 		72.000000, 72.000000, 72.000000, 72.000000,
		72.000000, 72.000000, 72.000000, 72.000000,
		144.000000, 144.000000, 144.000000, 144.000000,
		216.000000, 216.000000, 216.000000, 216.000000
 );


TEMPER_TEST( TestAssignment_double4x4 )
{
	double4x4 mat;

	mat.rows[0] = double4( 999.000000, 0.000000, 0.000000, 0.000000 );
	mat.rows[1] = double4( 0.000000, 999.000000, 0.000000, 0.000000 );
	mat.rows[2] = double4( 0.000000, 0.000000, 999.000000, 0.000000 );
	mat.rows[3] = double4( 0.000000, 0.000000, 0.000000, 999.000000 );

	TEMPER_EXPECT_TRUE( mat.rows[0].x == 999.0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].y == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].z == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].w == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].x == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].y == 999.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].z == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].w == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].x == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].y == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].z == 999.0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].w == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[3].x == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[3].y == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[3].z == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[3].w == 999.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestCtor_double4x4 )
{
	double4x4 mat;

	// fill single value
	mat = double4x4( 999.0 );
	TEMPER_EXPECT_TRUE( mat[0] == double4( 999.000000, 0.000000, 0.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 0.000000, 999.000000, 0.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double4( 0.000000, 0.000000, 999.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double4( 0.000000, 0.000000, 0.000000, 999.000000 ) );

	// row filling
	mat = double4x4(
		double4( 0.000000, 1.000000, 2.000000, 3.000000 ),
		double4( 4.000000, 5.000000, 6.000000, 7.000000 ),
		double4( 8.000000, 9.000000, 10.000000, 11.000000 ),
		double4( 12.000000, 13.000000, 14.000000, 15.000000 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == double4( 0.000000, 1.000000, 2.000000, 3.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 4.000000, 5.000000, 6.000000, 7.000000 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double4( 8.000000, 9.000000, 10.000000, 11.000000 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double4( 12.000000, 13.000000, 14.000000, 15.000000 ) );

	// all values filled
	mat = double4x4(
		16.000000, 15.000000, 14.000000, 13.000000,
		12.000000, 11.000000, 10.000000, 9.000000,
		8.000000, 7.000000, 6.000000, 5.000000,
		4.000000, 3.000000, 2.000000, 1.000000
	);
	TEMPER_EXPECT_TRUE( mat[0] == double4( 16.000000, 15.000000, 14.000000, 13.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 12.000000, 11.000000, 10.000000, 9.000000 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double4( 8.000000, 7.000000, 6.000000, 5.000000 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double4( 4.000000, 3.000000, 2.000000, 1.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_double4x4 )
{
	double4x4 mat;
	identity( mat );

	TEMPER_EXPECT_TRUE( mat[0] == double4( 1.0, 0.0, 0.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 0.0, 1.0, 0.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double4( 0.0, 0.0, 1.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double4( 0.0, 0.0, 0.0, 1.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_double4x4 )
{
	double4x4 answer;
	double4x4 mat;

	// prefix
	answer = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000
	);

	mat = double4x4(
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000

	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == answer );

	// postfix
	answer = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000
	);

	mat = double4x4(
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000

	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_double4x4 )
{
	double4x4 answer;
	double4x4 mat;

	// prefix
	answer = double4x4(
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000
	);

	mat = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000

	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == answer );

	// postfix
	answer = double4x4(
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000
	);

	mat = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000

	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_double4x4 )
{
	double4x4 answer = double4x4(
		7.000000, 7.000000, 7.000000, 7.000000,
		8.000000, 8.000000, 8.000000, 8.000000,
		15.000000, 15.000000, 15.000000, 15.000000,
		24.000000, 24.000000, 24.000000, 24.000000
	);

	double4x4 a = double4x4(
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000, 18.000000
	);

	double4x4 b = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	);

	double4x4 c = caddm( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_double4x4 )
{
	double4x4 answer = double4x4(
		5.000000, 5.000000, 5.000000, 5.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		9.000000, 9.000000, 9.000000, 9.000000,
		12.000000, 12.000000, 12.000000, 12.000000
	);

	double4x4 a = double4x4(
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000, 18.000000
	);

	double4x4 b = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	);

	double4x4 c = csubm( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_double4x4 )
{
	double4x4 answer = double4x4(
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		36.000000, 36.000000, 36.000000, 36.000000,
		108.000000, 108.000000, 108.000000, 108.000000
	);

	double4x4 a = double4x4(
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000, 18.000000
	);

	double4x4 b = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	);

	double4x4 c = cmulm( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_double4x4 )
{
	double4x4 answer = double4x4(
		6.000000, 6.000000, 6.000000, 6.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		3.000000, 3.000000, 3.000000, 3.000000
	);

	double4x4 a = double4x4(
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000, 18.000000
	);

	double4x4 b = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	);

	double4x4 c = cdivm( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_double4x4 )
{
	double4x4 answer = g_matrixMulAnswer_double4x4;

	double4x4 a = g_matrixMulLHS_double4x4;
	double4x4 b = g_matrixMulRHS_double4x4;
	double4x4 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyVector_double4x4 )
{
	double4 answerVec = { 28.000000, 68.000000, 108.000000, 148.000000 };

	double4x4 a = double4x4(
		1.000000, 2.000000, 3.000000, 4.000000,
		5.000000, 6.000000, 7.000000, 8.000000,
		9.000000, 10.000000, 11.000000, 12.000000,
		13.000000, 14.000000, 15.000000, 16.000000
	);
	double4 b = { 2.000000, 1.000000, 4.000000, 3.000000 };
	double4 c = a * b;

	TEMPER_EXPECT_TRUE( c == answerVec );

	TEMPER_PASS();
}

TEMPER_TEST( TestDivideMatrix_double4x4 )
{
	double4x4 answer = double4x4( 		1.000000, 0.0, 0.0, 0.0,
		0.0, 1.000000, 0.0, 0.0,
		0.0, 0.0, 1.000000, 0.0,
		0.0, 0.0, 0.0, 1.000000
 );

	double4x4 a = double4x4( 		6.000000, 2.000000, 3.000000, 4.000000,
		2.000000, 7.000000, 5.000000, 3.000000,
		3.000000, 5.000000, 7.000000, 2.000000,
		4.000000, 3.000000, 2.000000, 6.000000
 );
	double4x4 b = double4x4( 		6.000000, 2.000000, 3.000000, 4.000000,
		2.000000, 7.000000, 5.000000, 3.000000,
		3.000000, 5.000000, 7.000000, 2.000000,
		4.000000, 3.000000, 2.000000, 6.000000
 );
	double4x4 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double4x4 )
{
	bool4x4 allTrue = { 		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
 };

	double4x4 mat0 = double4x4( 		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000
 );
	double4x4 mat1 = double4x4( 		2.000000, 2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000, 2.000000
 );
	double4x4 mat2 = double4x4( 		3.000000, 3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000, 3.000000
 );
	double4x4 mat3 = double4x4( 		4.000000, 4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000, 4.000000
 );

	bool4x4 test0  = mat0 <= mat0;
	bool4x4 test1  = mat0 >= mat0;
	bool4x4 test2  = mat0 <  mat1;
	bool4x4 test3  = mat0 <  mat2;
	bool4x4 test4  = mat0 <  mat3;

	bool4x4 test5  = mat1 >  mat0;
	bool4x4 test6  = mat1 <= mat1;
	bool4x4 test7  = mat1 >= mat1;
	bool4x4 test8  = mat1 <  mat2;
	bool4x4 test9  = mat1 <  mat3;

	bool4x4 test10 = mat2 >  mat0;
	bool4x4 test11 = mat2 >  mat1;
	bool4x4 test12 = mat2 <= mat2;
	bool4x4 test13 = mat2 >= mat2;
	bool4x4 test14 = mat2 <  mat3;

	bool4x4 test15 = mat3 >  mat0;
	bool4x4 test16 = mat3 >  mat1;
	bool4x4 test17 = mat3 >  mat2;
	bool4x4 test18 = mat3 <= mat3;
	bool4x4 test19 = mat3 >= mat3;

	TEMPER_EXPECT_TRUE( test0  == allTrue );
	TEMPER_EXPECT_TRUE( test1  == allTrue );
	TEMPER_EXPECT_TRUE( test2  == allTrue );
	TEMPER_EXPECT_TRUE( test3  == allTrue );
	TEMPER_EXPECT_TRUE( test4  == allTrue );

	TEMPER_EXPECT_TRUE( test5  == allTrue );
	TEMPER_EXPECT_TRUE( test6  == allTrue );
	TEMPER_EXPECT_TRUE( test7  == allTrue );
	TEMPER_EXPECT_TRUE( test8  == allTrue );
	TEMPER_EXPECT_TRUE( test9  == allTrue );

	TEMPER_EXPECT_TRUE( test10 == allTrue );
	TEMPER_EXPECT_TRUE( test11 == allTrue );
	TEMPER_EXPECT_TRUE( test12 == allTrue );
	TEMPER_EXPECT_TRUE( test13 == allTrue );
	TEMPER_EXPECT_TRUE( test14 == allTrue );

	TEMPER_EXPECT_TRUE( test15 == allTrue );
	TEMPER_EXPECT_TRUE( test16 == allTrue );
	TEMPER_EXPECT_TRUE( test17 == allTrue );
	TEMPER_EXPECT_TRUE( test18 == allTrue );
	TEMPER_EXPECT_TRUE( test19 == allTrue );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_Scalar_double4x4 )
{
	double4x4 id;
	id[0] = double4( 1.000000, 0.000000, 0.000000, 0.000000 );
	id[1] = double4( 0.000000, 1.000000, 0.000000, 0.000000 );
	id[2] = double4( 0.000000, 0.000000, 1.000000, 0.000000 );
	id[3] = double4( 0.000000, 0.000000, 0.000000, 1.000000 );

	double4x4 mat;

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_Scalar_double4x4 )
{
	double4x4 answerTransposed = double4x4(
		0.000000, 4.000000, 8.000000, 12.000000,
		1.000000, 5.000000, 9.000000, 13.000000,
		2.000000, 6.000000, 10.000000, 14.000000,
		3.000000, 7.000000, 11.000000, 15.000000
	);

	double4x4 mat = double4x4(
		0.000000, 1.000000, 2.000000, 3.000000,
		4.000000, 5.000000, 6.000000, 7.000000,
		8.000000, 9.000000, 10.000000, 11.000000,
		12.000000, 13.000000, 14.000000, 15.000000
	);
	double4x4 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == answerTransposed );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_Scalar_double4x4 )
{
	double4x4 mat = double4x4(
		6.000000, 2.000000, 3.000000, 4.000000,
		2.000000, 7.000000, 5.000000, 3.000000,
		3.000000, 5.000000, 7.000000, 2.000000,
		4.000000, 3.000000, 2.000000, 6.000000
	);

	double det = determinant( mat );

	TEMPER_EXPECT_TRUE( doubleeq( det, 285.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_Scalar_double4x4 )
{
	double4x4 id;
	identity( id );

	double4x4 mat = double4x4(
		1.000000, 0.000000, 0.000000, 1.000000,
		0.000000, 2.000000, 1.000000, 2.000000,
		2.000000, 1.000000, 0.000000, 1.000000,
		2.000000, 0.000000, 1.000000, 4.000000
	);
	double4x4 matInverse = inverse( mat );

	TEMPER_EXPECT_TRUE( mat * matInverse == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_Scalar_double4x4 )
{
	double4x4 mat;
	identity( mat );

	double3 translation = double3( 2.000000, 3.000000, 4.000000 );

	mat = translate( mat, translation );

	TEMPER_EXPECT_TRUE( doubleeq( mat.rows[0].w, 2.0 ) );
	TEMPER_EXPECT_TRUE( doubleeq( mat.rows[1].w, 3.0 ) );
	TEMPER_EXPECT_TRUE( doubleeq( mat.rows[2].w, 4.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRotate_double4x4 )
{
	double4x4 mat;
	identity( mat );

	double3 rollVec = { 0.000000, 0.000000, 1.000000 };
	double4x4 roll = rotate( mat, radians( 45.0 ), rollVec );
	double4x4 answerRoll = double4x4(
		0.707107, -0.707107, 0.000000, 0.000000,
		0.707107, 0.707107, 0.000000, 0.000000,
		0.000000, 0.000000, 1.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	);

	double4x4 yaw = rotate( mat, radians( 45.0 ), double3( 0.000000, 1.000000, 0.000000 ) );
	double4x4 answerYaw = double4x4( 		0.707107, 0.000000, 0.707107, 0.000000,
		0.000000, 1.000000, 0.000000, 0.000000,
		-0.707107, 0.000000, 0.707107, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
 );
	TEMPER_EXPECT_TRUE( yaw == answerYaw );

	double4x4 pitch = rotate( mat, radians( 45.0 ), double3( 1.000000, 0.000000, 0.000000 ) );
	double4x4 answerPitch = double4x4( 		1.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.707107, -0.707107, 0.000000,
		0.000000, 0.707107, 0.707107, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
 );
	TEMPER_EXPECT_TRUE( pitch == answerPitch );
	TEMPER_EXPECT_TRUE( roll == answerRoll );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_Scalar_double4x4 )
{
	double3 scaleVec = { 2.000000, 2.000000, 2.000000 };
	double4x4 mat;
	identity( mat );

	double4x4 scaled = scale( mat, scaleVec );

	TEMPER_EXPECT_TRUE( doubleeq( scaled.rows[0].x, 2.000000 ) );
	TEMPER_EXPECT_TRUE( doubleeq( scaled.rows[1].y, 2.000000 ) );
	TEMPER_EXPECT_TRUE( doubleeq( scaled.rows[2].z, 2.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestOrtho_double4x4 )
{
	double4x4 answerOrtho_LH_ZO = double4x4(
		0.112500, 0.000000, 0.000000, 0.000000,
		0.000000, -0.200000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.009901, 0.009901,
		0.000000, 0.000000, 0.000000, 1.000000
	);
	double4x4 answerOrtho_LH_NO = double4x4(
		0.112500, 0.000000, 0.000000, -0.000000,
		0.000000, -0.200000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.019802, -0.980198,
		0.000000, 0.000000, 0.000000, 1.000000
	);
	double4x4 answerOrtho_RH_ZO = double4x4(
		0.112500, 0.000000, 0.000000, -0.000000,
		0.000000, -0.200000, 0.000000, 0.000000,
		0.000000, 0.000000, -0.009901, 0.009901,
		0.000000, 0.000000, 0.000000, 1.000000
	);
	double4x4 answerOrtho_RH_NO = double4x4(
		0.112500, 0.000000, 0.000000, -0.000000,
		0.000000, -0.200000, 0.000000, 0.000000,
		0.000000, 0.000000, -0.019802, -0.980198,
		0.000000, 0.000000, 0.000000, 1.000000
	);

	double width     = 1280.0;
	double height    = 720.0;
	double aspect    = width / height;
	double orthoSize = 5.0;

	double left   = -aspect * orthoSize;
	double right  =  aspect * orthoSize;
	double top    = -orthoSize;
	double bottom =  orthoSize;

	double4x4 mat_LH_ZO = ortho_lh_zo( left, right, top, bottom, -1.0, 100.0 );
	double4x4 mat_LH_NO = ortho_lh_no( left, right, top, bottom, -1.0, 100.0 );
	double4x4 mat_RH_ZO = ortho_rh_zo( left, right, top, bottom, -1.0, 100.0 );
	double4x4 mat_RH_NO = ortho_rh_no( left, right, top, bottom, -1.0, 100.0 );

	TEMPER_EXPECT_TRUE( mat_LH_ZO == answerOrtho_LH_ZO );
	TEMPER_EXPECT_TRUE( mat_LH_NO == answerOrtho_LH_NO );
	TEMPER_EXPECT_TRUE( mat_RH_ZO == answerOrtho_RH_ZO );
	TEMPER_EXPECT_TRUE( mat_RH_NO == answerOrtho_RH_NO );

	TEMPER_PASS();
}

TEMPER_TEST( TestPerspective_double4x4 )
{
	double4x4 answerPerspective_LH_ZO = double4x4(
		0.347270, 0.000000, 0.000000, 0.000000,
		0.000000, 0.617370, 0.000000, 0.000000,
		0.000000, 0.000000, 1.001001, -0.100100,
		0.000000, 0.000000, 1.000000, 0.000000
	);
	double4x4 answerPerspective_LH_NO = double4x4(
		0.347270, 0.000000, 0.000000, 0.000000,
		0.000000, 0.617370, 0.000000, 0.000000,
		0.000000, 0.000000, 1.002002, -0.200200,
		0.000000, 0.000000, 1.000000, 0.000000
	);
	double4x4 answerPerspective_RH_ZO = double4x4(
		0.347270, 0.000000, 0.000000, 0.000000,
		0.000000, 0.617370, 0.000000, 0.000000,
		0.000000, 0.000000, -1.001001, -0.100100,
		0.000000, 0.000000, -1.000000, 0.000000
	);
	double4x4 answerPerspective_RH_NO = double4x4(
		0.347270, 0.000000, 0.000000, 0.000000,
		0.000000, 0.617370, 0.000000, 0.000000,
		0.000000, 0.000000, -1.002002, -0.200200,
		0.000000, 0.000000, -1.000000, 0.000000
	);

	double aspect = 1280.0 / 720.0;

	double4x4 mat_LH_ZO = perspective_lh_zo( 90.0, aspect, 0.1, 100.0 );
	double4x4 mat_LH_NO = perspective_lh_no( 90.0, aspect, 0.1, 100.0 );
	double4x4 mat_RH_ZO = perspective_rh_zo( 90.0, aspect, 0.1, 100.0 );
	double4x4 mat_RH_NO = perspective_rh_no( 90.0, aspect, 0.1, 100.0 );

	TEMPER_EXPECT_TRUE( mat_LH_ZO == answerPerspective_LH_ZO );
	TEMPER_EXPECT_TRUE( mat_LH_NO == answerPerspective_LH_NO );
	TEMPER_EXPECT_TRUE( mat_RH_ZO == answerPerspective_RH_ZO );
	TEMPER_EXPECT_TRUE( mat_RH_NO == answerPerspective_RH_NO );

	TEMPER_PASS();
}

TEMPER_TEST( TestLookAt_double4x4 )
{
	double4x4 answerLookAt_LH = double4x4(
		0.707107, 0.000000, -0.707107, 0.000000,
		0.000000, 1.000000, 0.000000, 0.000000,
		0.707107, 0.000000, 0.707107, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	);
	double4x4 answerLookAt_RH = double4x4(
		-0.707107, 0.000000, 0.707107, 0.000000,
		0.000000, 1.000000, 0.000000, 0.000000,
		-0.707107, 0.000000, -0.707107, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	);

	double3 currentPos = { 0.000000, 0.000000, 0.000000 };
	double3 targetPos = { 1.000000, 0.000000, 1.000000 };
	double3 up = { 0.000000, 1.000000, 0.000000 };

	double4x4 mat_LH = lookat_lh( currentPos, targetPos, up );
	double4x4 mat_RH = lookat_rh( currentPos, targetPos, up );

	TEMPER_EXPECT_TRUE( mat_LH == answerLookAt_LH );
	TEMPER_EXPECT_TRUE( mat_RH == answerLookAt_RH );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_double4x4 )
{
	TEMPER_RUN_TEST( TestAssignment_double4x4 );
	TEMPER_RUN_TEST( TestCtor_double4x4 );
	TEMPER_RUN_TEST( TestArray_double4x4 );
	TEMPER_RUN_TEST( TestIncrement_double4x4 );
	TEMPER_RUN_TEST( TestDecrement_double4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Addition_double4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_double4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_double4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Division_double4x4 );
	TEMPER_RUN_TEST( TestMultiplyMatrix_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestMultiplyVector_double4x4 );
	TEMPER_RUN_TEST( TestDivideMatrix_double4x4 );
	TEMPER_RUN_TEST( TestRelational_double4x4 );
	TEMPER_RUN_TEST( TestIdentity_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestTranspose_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestDeterminant_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestInverse_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestTranslate_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestRotate_double4x4 );
	TEMPER_RUN_TEST( TestScale_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestOrtho_double4x4 );
	TEMPER_RUN_TEST( TestPerspective_double4x4 );
	TEMPER_RUN_TEST( TestLookAt_double4x4 );
}
