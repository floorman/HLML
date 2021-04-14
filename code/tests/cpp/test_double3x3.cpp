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

static double3x3 g_matrixMulLHS_double3x3    = double3x3( 		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000
 );

static double3x3 g_matrixMulRHS_double3x3    = double3x3( 		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000
 );

static double3x3 g_matrixMulAnswer_double3x3 = double3x3( 		36.000000, 36.000000, 36.000000,
		36.000000, 36.000000, 36.000000,
		72.000000, 72.000000, 72.000000
 );


TEMPER_TEST( TestAssignment_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 mat;

	mat.rows[0] = double3( 999.000000, 0.000000, 0.000000 );
	mat.rows[1] = double3( 0.000000, 999.000000, 0.000000 );
	mat.rows[2] = double3( 0.000000, 0.000000, 999.000000 );

	TEMPER_CHECK_TRUE( mat.rows[0].x == 999.0 );
	TEMPER_CHECK_TRUE( mat.rows[0].y == 0.0 );
	TEMPER_CHECK_TRUE( mat.rows[0].z == 0.0 );
	TEMPER_CHECK_TRUE( mat.rows[1].x == 0.0 );
	TEMPER_CHECK_TRUE( mat.rows[1].y == 999.0 );
	TEMPER_CHECK_TRUE( mat.rows[1].z == 0.0 );
	TEMPER_CHECK_TRUE( mat.rows[2].x == 0.0 );
	TEMPER_CHECK_TRUE( mat.rows[2].y == 0.0 );
	TEMPER_CHECK_TRUE( mat.rows[2].z == 999.0 );
}

TEMPER_TEST( TestCtor_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 mat;

	// fill single value
	mat = double3x3( 999.0 );
	TEMPER_CHECK_TRUE( mat[0] == double3( 999.000000, 0.000000, 0.000000 ) );
	TEMPER_CHECK_TRUE( mat[1] == double3( 0.000000, 999.000000, 0.000000 ) );
	TEMPER_CHECK_TRUE( mat[2] == double3( 0.000000, 0.000000, 999.000000 ) );

	// row filling
	mat = double3x3(
		double3( 0.000000, 1.000000, 2.000000 ),
		double3( 4.000000, 5.000000, 6.000000 ),
		double3( 8.000000, 9.000000, 10.000000 )
	);
	TEMPER_CHECK_TRUE( mat[0] == double3( 0.000000, 1.000000, 2.000000 ) );
	TEMPER_CHECK_TRUE( mat[1] == double3( 4.000000, 5.000000, 6.000000 ) );
	TEMPER_CHECK_TRUE( mat[2] == double3( 8.000000, 9.000000, 10.000000 ) );

	// all values filled
	mat = double3x3(
		16.000000, 15.000000, 14.000000,
		12.000000, 11.000000, 10.000000,
		8.000000, 7.000000, 6.000000
	);
	TEMPER_CHECK_TRUE( mat[0] == double3( 16.000000, 15.000000, 14.000000 ) );
	TEMPER_CHECK_TRUE( mat[1] == double3( 12.000000, 11.000000, 10.000000 ) );
	TEMPER_CHECK_TRUE( mat[2] == double3( 8.000000, 7.000000, 6.000000 ) );
}

TEMPER_TEST( TestArray_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 mat;
	identity( mat );

	TEMPER_CHECK_TRUE( mat[0] == double3( 1.0, 0.0, 0.0 ) );
	TEMPER_CHECK_TRUE( mat[1] == double3( 0.0, 1.0, 0.0 ) );
	TEMPER_CHECK_TRUE( mat[2] == double3( 0.0, 0.0, 1.0 ) );
}

TEMPER_TEST( TestIncrement_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 answer;
	double3x3 mat;

	// prefix
	answer = double3x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
	);

	mat = double3x3(
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000

	);
	++mat;
	TEMPER_CHECK_TRUE( mat == answer );

	// postfix
	answer = double3x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
	);

	mat = double3x3(
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000

	);
	mat++;
	TEMPER_CHECK_TRUE( mat == answer );
}

TEMPER_TEST( TestDecrement_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 answer;
	double3x3 mat;

	// prefix
	answer = double3x3(
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000
	);

	mat = double3x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000

	);
	--mat;
	TEMPER_CHECK_TRUE( mat == answer );

	// postfix
	answer = double3x3(
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000
	);

	mat = double3x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000

	);
	mat--;
	TEMPER_CHECK_TRUE( mat == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 answer = double3x3(
		7.000000, 7.000000, 7.000000,
		8.000000, 8.000000, 8.000000,
		15.000000, 15.000000, 15.000000
	);

	double3x3 a = double3x3(
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000
	);

	double3x3 b = double3x3(
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000
	);

	double3x3 c = caddm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 answer = double3x3(
		5.000000, 5.000000, 5.000000,
		4.000000, 4.000000, 4.000000,
		9.000000, 9.000000, 9.000000
	);

	double3x3 a = double3x3(
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000
	);

	double3x3 b = double3x3(
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000
	);

	double3x3 c = csubm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 answer = double3x3(
		6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000,
		36.000000, 36.000000, 36.000000
	);

	double3x3 a = double3x3(
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000
	);

	double3x3 b = double3x3(
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000
	);

	double3x3 c = cmulm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 answer = double3x3(
		6.000000, 6.000000, 6.000000,
		3.000000, 3.000000, 3.000000,
		4.000000, 4.000000, 4.000000
	);

	double3x3 a = double3x3(
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000
	);

	double3x3 b = double3x3(
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000
	);

	double3x3 c = cdivm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 answer = g_matrixMulAnswer_double3x3;

	double3x3 a = g_matrixMulLHS_double3x3;
	double3x3 b = g_matrixMulRHS_double3x3;
	double3x3 c = a * b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestMultiplyVector_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3 answerVec = { 16.000000, 44.000000, 72.000000 };

	double3x3 a = double3x3(
		1.000000, 2.000000, 3.000000,
		5.000000, 6.000000, 7.000000,
		9.000000, 10.000000, 11.000000
	);
	double3 b = { 2.000000, 1.000000, 4.000000 };
	double3 c = a * b;

	TEMPER_CHECK_TRUE( c == answerVec );
}

TEMPER_TEST( TestDivideMatrix_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 answer = double3x3( 		1.000000, 0.0, 0.0,
		0.0, 1.000000, 0.0,
		0.0, 0.0, 1.000000
 );

	double3x3 a = double3x3( 		6.000000, 2.000000, 3.000000,
		2.000000, 7.000000, 5.000000,
		3.000000, 5.000000, 7.000000
 );
	double3x3 b = double3x3( 		6.000000, 2.000000, 3.000000,
		2.000000, 7.000000, 5.000000,
		3.000000, 5.000000, 7.000000
 );
	double3x3 c = a / b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestRelational_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	bool3x3 allTrue = { 		true, true, true,
		true, true, true,
		true, true, true
 };

	double3x3 mat0 = double3x3( 		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
 );
	double3x3 mat1 = double3x3( 		2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000
 );
	double3x3 mat2 = double3x3( 		3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000
 );
	double3x3 mat3 = double3x3( 		4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000
 );

	bool3x3 test0  = mat0 <= mat0;
	bool3x3 test1  = mat0 >= mat0;
	bool3x3 test2  = mat0 <  mat1;
	bool3x3 test3  = mat0 <  mat2;
	bool3x3 test4  = mat0 <  mat3;

	bool3x3 test5  = mat1 >  mat0;
	bool3x3 test6  = mat1 <= mat1;
	bool3x3 test7  = mat1 >= mat1;
	bool3x3 test8  = mat1 <  mat2;
	bool3x3 test9  = mat1 <  mat3;

	bool3x3 test10 = mat2 >  mat0;
	bool3x3 test11 = mat2 >  mat1;
	bool3x3 test12 = mat2 <= mat2;
	bool3x3 test13 = mat2 >= mat2;
	bool3x3 test14 = mat2 <  mat3;

	bool3x3 test15 = mat3 >  mat0;
	bool3x3 test16 = mat3 >  mat1;
	bool3x3 test17 = mat3 >  mat2;
	bool3x3 test18 = mat3 <= mat3;
	bool3x3 test19 = mat3 >= mat3;

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

TEMPER_TEST( TestIdentity_Scalar_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 id;
	id[0] = double3( 1.000000, 0.000000, 0.000000 );
	id[1] = double3( 0.000000, 1.000000, 0.000000 );
	id[2] = double3( 0.000000, 0.000000, 1.000000 );

	double3x3 mat;

	identity( mat );
	TEMPER_CHECK_TRUE( mat == id );
}

TEMPER_TEST( TestTranspose_Scalar_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 answerTransposed = double3x3(
		0.000000, 4.000000, 8.000000,
		1.000000, 5.000000, 9.000000,
		2.000000, 6.000000, 10.000000
	);

	double3x3 mat = double3x3(
		0.000000, 1.000000, 2.000000,
		4.000000, 5.000000, 6.000000,
		8.000000, 9.000000, 10.000000
	);
	double3x3 trans = transpose( mat );

	TEMPER_CHECK_TRUE( trans == answerTransposed );
}

TEMPER_TEST( TestDeterminant_Scalar_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 mat = double3x3(
		6.000000, 2.000000, 3.000000,
		2.000000, 7.000000, 2.000000,
		3.000000, 2.000000, 6.000000
	);

	double det = determinant( mat );

	TEMPER_CHECK_TRUE( doubleeq( det, 165.0 ) );
}

TEMPER_TEST( TestInverse_Scalar_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 id;
	identity( id );

	double3x3 mat = double3x3(
		6.000000, 2.000000, 3.000000,
		2.000000, 7.000000, 2.000000,
		3.000000, 2.000000, 6.000000
	);
	double3x3 matInverse = inverse( mat );

	TEMPER_CHECK_TRUE( mat * matInverse == id );
}

TEMPER_TEST( TestTranslate_Scalar_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 mat;
	identity( mat );

	double2 translation = double2( 2.000000, 3.000000 );

	mat = translate( mat, translation );

	TEMPER_CHECK_TRUE( doubleeq( mat.rows[0].z, 2.0 ) );
	TEMPER_CHECK_TRUE( doubleeq( mat.rows[1].z, 3.0 ) );
}

TEMPER_TEST( TestRotate_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double3x3 mat;
	identity( mat );

	double3x3 roll = rotate( mat, radians( 45.0 ) );
	double3x3 answerRoll = double3x3(
		0.707107, -0.707107, 0.000000,
		0.707107, 0.707107, 0.000000,
		0.000000, 0.000000, 1.000000
	);

	TEMPER_CHECK_TRUE( roll == answerRoll );
}

TEMPER_TEST( TestScale_Scalar_double3x3, TEMPER_FLAG_SHOULD_RUN )
{
	double2 scaleVec = { 2.000000, 2.000000 };
	double3x3 mat;
	identity( mat );

	double3x3 scaled = scale( mat, scaleVec );

	TEMPER_CHECK_TRUE( doubleeq( scaled.rows[0].x, 2.000000 ) );
	TEMPER_CHECK_TRUE( doubleeq( scaled.rows[1].y, 2.000000 ) );
}

