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

static double2x2 g_matrixMulLHS_double2x2    = double2x2( 		6.000000, 6.000000,
		6.000000, 6.000000
 );

static double2x2 g_matrixMulRHS_double2x2    = double2x2( 		1.000000, 1.000000,
		2.000000, 2.000000
 );

static double2x2 g_matrixMulAnswer_double2x2 = double2x2( 		18.000000, 18.000000,
		18.000000, 18.000000
 );


TEMPER_TEST( TestAssignment_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 mat;

	mat.rows[0] = double2( 999.000000, 0.000000 );
	mat.rows[1] = double2( 0.000000, 999.000000 );

	TEMPER_CHECK_TRUE( mat.rows[0].x == 999.0 );
	TEMPER_CHECK_TRUE( mat.rows[0].y == 0.0 );
	TEMPER_CHECK_TRUE( mat.rows[1].x == 0.0 );
	TEMPER_CHECK_TRUE( mat.rows[1].y == 999.0 );
}

TEMPER_TEST( TestCtor_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 mat;

	// fill single value
	mat = double2x2( 999.0 );
	TEMPER_CHECK_TRUE( mat[0] == double2( 999.000000, 0.000000 ) );
	TEMPER_CHECK_TRUE( mat[1] == double2( 0.000000, 999.000000 ) );

	// row filling
	mat = double2x2(
		double2( 0.000000, 1.000000 ),
		double2( 4.000000, 5.000000 )
	);
	TEMPER_CHECK_TRUE( mat[0] == double2( 0.000000, 1.000000 ) );
	TEMPER_CHECK_TRUE( mat[1] == double2( 4.000000, 5.000000 ) );

	// all values filled
	mat = double2x2(
		16.000000, 15.000000,
		12.000000, 11.000000
	);
	TEMPER_CHECK_TRUE( mat[0] == double2( 16.000000, 15.000000 ) );
	TEMPER_CHECK_TRUE( mat[1] == double2( 12.000000, 11.000000 ) );
}

TEMPER_TEST( TestArray_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 mat;
	identity( mat );

	TEMPER_CHECK_TRUE( mat[0] == double2( 1.0, 0.0 ) );
	TEMPER_CHECK_TRUE( mat[1] == double2( 0.0, 1.0 ) );
}

TEMPER_TEST( TestIncrement_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 answer;
	double2x2 mat;

	// prefix
	answer = double2x2(
		1.000000, 1.000000,
		1.000000, 1.000000
	);

	mat = double2x2(
		0.000000, 0.000000,
		0.000000, 0.000000

	);
	++mat;
	TEMPER_CHECK_TRUE( mat == answer );

	// postfix
	answer = double2x2(
		1.000000, 1.000000,
		1.000000, 1.000000
	);

	mat = double2x2(
		0.000000, 0.000000,
		0.000000, 0.000000

	);
	mat++;
	TEMPER_CHECK_TRUE( mat == answer );
}

TEMPER_TEST( TestDecrement_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 answer;
	double2x2 mat;

	// prefix
	answer = double2x2(
		0.000000, 0.000000,
		0.000000, 0.000000
	);

	mat = double2x2(
		1.000000, 1.000000,
		1.000000, 1.000000

	);
	--mat;
	TEMPER_CHECK_TRUE( mat == answer );

	// postfix
	answer = double2x2(
		0.000000, 0.000000,
		0.000000, 0.000000
	);

	mat = double2x2(
		1.000000, 1.000000,
		1.000000, 1.000000

	);
	mat--;
	TEMPER_CHECK_TRUE( mat == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 answer = double2x2(
		7.000000, 7.000000,
		8.000000, 8.000000
	);

	double2x2 a = double2x2(
		6.000000, 6.000000,
		6.000000, 6.000000
	);

	double2x2 b = double2x2(
		1.000000, 1.000000,
		2.000000, 2.000000
	);

	double2x2 c = caddm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 answer = double2x2(
		5.000000, 5.000000,
		4.000000, 4.000000
	);

	double2x2 a = double2x2(
		6.000000, 6.000000,
		6.000000, 6.000000
	);

	double2x2 b = double2x2(
		1.000000, 1.000000,
		2.000000, 2.000000
	);

	double2x2 c = csubm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 answer = double2x2(
		6.000000, 6.000000,
		12.000000, 12.000000
	);

	double2x2 a = double2x2(
		6.000000, 6.000000,
		6.000000, 6.000000
	);

	double2x2 b = double2x2(
		1.000000, 1.000000,
		2.000000, 2.000000
	);

	double2x2 c = cmulm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 answer = double2x2(
		6.000000, 6.000000,
		3.000000, 3.000000
	);

	double2x2 a = double2x2(
		6.000000, 6.000000,
		6.000000, 6.000000
	);

	double2x2 b = double2x2(
		1.000000, 1.000000,
		2.000000, 2.000000
	);

	double2x2 c = cdivm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 answer = g_matrixMulAnswer_double2x2;

	double2x2 a = g_matrixMulLHS_double2x2;
	double2x2 b = g_matrixMulRHS_double2x2;
	double2x2 c = a * b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestMultiplyVector_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2 answerVec = { 4.000000, 16.000000 };

	double2x2 a = double2x2(
		1.000000, 2.000000,
		5.000000, 6.000000
	);
	double2 b = { 2.000000, 1.000000 };
	double2 c = a * b;

	TEMPER_CHECK_TRUE( c == answerVec );
}

TEMPER_TEST( TestDivideMatrix_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 answer = double2x2( 		1.000000, 0.0,
		0.0, 1.000000
 );

	double2x2 a = double2x2( 		6.000000, 2.000000,
		2.000000, 7.000000
 );
	double2x2 b = double2x2( 		6.000000, 2.000000,
		2.000000, 7.000000
 );
	double2x2 c = a / b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestRelational_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	bool2x2 allTrue = { 		true, true,
		true, true
 };

	double2x2 mat0 = double2x2( 		1.000000, 1.000000,
		1.000000, 1.000000
 );
	double2x2 mat1 = double2x2( 		2.000000, 2.000000,
		2.000000, 2.000000
 );
	double2x2 mat2 = double2x2( 		3.000000, 3.000000,
		3.000000, 3.000000
 );
	double2x2 mat3 = double2x2( 		4.000000, 4.000000,
		4.000000, 4.000000
 );

	bool2x2 test0  = mat0 <= mat0;
	bool2x2 test1  = mat0 >= mat0;
	bool2x2 test2  = mat0 <  mat1;
	bool2x2 test3  = mat0 <  mat2;
	bool2x2 test4  = mat0 <  mat3;

	bool2x2 test5  = mat1 >  mat0;
	bool2x2 test6  = mat1 <= mat1;
	bool2x2 test7  = mat1 >= mat1;
	bool2x2 test8  = mat1 <  mat2;
	bool2x2 test9  = mat1 <  mat3;

	bool2x2 test10 = mat2 >  mat0;
	bool2x2 test11 = mat2 >  mat1;
	bool2x2 test12 = mat2 <= mat2;
	bool2x2 test13 = mat2 >= mat2;
	bool2x2 test14 = mat2 <  mat3;

	bool2x2 test15 = mat3 >  mat0;
	bool2x2 test16 = mat3 >  mat1;
	bool2x2 test17 = mat3 >  mat2;
	bool2x2 test18 = mat3 <= mat3;
	bool2x2 test19 = mat3 >= mat3;

	TEMPER_CHECK_TRUE( test0  == allTrue );
	TEMPER_CHECK_TRUE( test1  == allTrue );
	TEMPER_CHECK_TRUE( test2  == allTrue );
	TEMPER_CHECK_TRUE( test3  == allTrue );
	TEMPER_CHECK_TRUE( test4  == allTrue );

	TEMPER_CHECK_TRUE( test5  == allTrue );
	TEMPER_CHECK_TRUE( test6  == allTrue );
	TEMPER_CHECK_TRUE( test7  == allTrue );
	TEMPER_CHECK_TRUE( test8  == allTrue );
	TEMPER_CHECK_TRUE( test9  == allTrue );

	TEMPER_CHECK_TRUE( test10 == allTrue );
	TEMPER_CHECK_TRUE( test11 == allTrue );
	TEMPER_CHECK_TRUE( test12 == allTrue );
	TEMPER_CHECK_TRUE( test13 == allTrue );
	TEMPER_CHECK_TRUE( test14 == allTrue );

	TEMPER_CHECK_TRUE( test15 == allTrue );
	TEMPER_CHECK_TRUE( test16 == allTrue );
	TEMPER_CHECK_TRUE( test17 == allTrue );
	TEMPER_CHECK_TRUE( test18 == allTrue );
	TEMPER_CHECK_TRUE( test19 == allTrue );
}

TEMPER_TEST( TestIdentity_Scalar_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 id;
	id[0] = double2( 1.000000, 0.000000 );
	id[1] = double2( 0.000000, 1.000000 );

	double2x2 mat;

	identity( mat );
	TEMPER_CHECK_TRUE( mat == id );
}

TEMPER_TEST( TestTranspose_Scalar_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 answerTransposed = double2x2(
		0.000000, 4.000000,
		1.000000, 5.000000
	);

	double2x2 mat = double2x2(
		0.000000, 1.000000,
		4.000000, 5.000000
	);
	double2x2 trans = transpose( mat );

	TEMPER_CHECK_TRUE( trans == answerTransposed );
}

TEMPER_TEST( TestDeterminant_Scalar_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 mat = double2x2(
		6.000000, 2.000000,
		2.000000, 6.000000
	);

	double det = determinant( mat );

	TEMPER_CHECK_TRUE( doubleeq( det, 32.0 ) );
}

TEMPER_TEST( TestInverse_Scalar_double2x2, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 id;
	identity( id );

	double2x2 mat = double2x2(
		2.000000, 4.000000,
		6.000000, 8.000000
	);
	double2x2 matInverse = inverse( mat );

	TEMPER_CHECK_TRUE( mat * matInverse == id );
}

