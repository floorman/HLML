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

static int4x2 g_matrixMulLHS_int4x2    = int4x2( 		6, 6,
		6, 6,
		12, 12,
		18, 18
 );

static int2x4 g_matrixMulRHS_int4x2    = int2x4( 		1, 1, 1, 1,
		2, 2, 2, 2
 );

static int4x4 g_matrixMulAnswer_int4x2 = int4x4( 		18, 18, 18, 18,
		18, 18, 18, 18,
		36, 36, 36, 36,
		54, 54, 54, 54
 );


TEMPER_TEST( TestAssignment_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 mat;

	mat.rows[0] = int2( 999, 0 );
	mat.rows[1] = int2( 0, 999 );
	mat.rows[2] = int2( 0, 0 );
	mat.rows[3] = int2( 0, 0 );

	TEMPER_CHECK_TRUE( mat.rows[0].x == 999 );
	TEMPER_CHECK_TRUE( mat.rows[0].y == 0 );
	TEMPER_CHECK_TRUE( mat.rows[1].x == 0 );
	TEMPER_CHECK_TRUE( mat.rows[1].y == 999 );
	TEMPER_CHECK_TRUE( mat.rows[2].x == 0 );
	TEMPER_CHECK_TRUE( mat.rows[2].y == 0 );
	TEMPER_CHECK_TRUE( mat.rows[3].x == 0 );
	TEMPER_CHECK_TRUE( mat.rows[3].y == 0 );
}

TEMPER_TEST( TestCtor_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 mat;

	// fill single value
	mat = int4x2( 999 );
	TEMPER_CHECK_TRUE( mat[0] == int2( 999, 0 ) );
	TEMPER_CHECK_TRUE( mat[1] == int2( 0, 999 ) );
	TEMPER_CHECK_TRUE( mat[2] == int2( 0, 0 ) );
	TEMPER_CHECK_TRUE( mat[3] == int2( 0, 0 ) );

	// row filling
	mat = int4x2(
		int2( 0, 1 ),
		int2( 4, 5 ),
		int2( 8, 9 ),
		int2( 12, 13 )
	);
	TEMPER_CHECK_TRUE( mat[0] == int2( 0, 1 ) );
	TEMPER_CHECK_TRUE( mat[1] == int2( 4, 5 ) );
	TEMPER_CHECK_TRUE( mat[2] == int2( 8, 9 ) );
	TEMPER_CHECK_TRUE( mat[3] == int2( 12, 13 ) );

	// all values filled
	mat = int4x2(
		16, 15,
		12, 11,
		8, 7,
		4, 3
	);
	TEMPER_CHECK_TRUE( mat[0] == int2( 16, 15 ) );
	TEMPER_CHECK_TRUE( mat[1] == int2( 12, 11 ) );
	TEMPER_CHECK_TRUE( mat[2] == int2( 8, 7 ) );
	TEMPER_CHECK_TRUE( mat[3] == int2( 4, 3 ) );
}

TEMPER_TEST( TestArray_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 mat;
	identity( mat );

	TEMPER_CHECK_TRUE( mat[0] == int2( 1, 0 ) );
	TEMPER_CHECK_TRUE( mat[1] == int2( 0, 1 ) );
	TEMPER_CHECK_TRUE( mat[2] == int2( 0, 0 ) );
	TEMPER_CHECK_TRUE( mat[3] == int2( 0, 0 ) );
}

TEMPER_TEST( TestIncrement_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 answer;
	int4x2 mat;

	// prefix
	answer = int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	);

	mat = int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0

	);
	++mat;
	TEMPER_CHECK_TRUE( mat == answer );

	// postfix
	answer = int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	);

	mat = int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0

	);
	mat++;
	TEMPER_CHECK_TRUE( mat == answer );
}

TEMPER_TEST( TestDecrement_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 answer;
	int4x2 mat;

	// prefix
	answer = int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	);

	mat = int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1

	);
	--mat;
	TEMPER_CHECK_TRUE( mat == answer );

	// postfix
	answer = int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	);

	mat = int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1

	);
	mat--;
	TEMPER_CHECK_TRUE( mat == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 answer = int4x2(
		7, 7,
		8, 8,
		15, 15,
		24, 24
	);

	int4x2 a = int4x2(
		6, 6,
		6, 6,
		12, 12,
		18, 18
	);

	int4x2 b = int4x2(
		1, 1,
		2, 2,
		3, 3,
		6, 6
	);

	int4x2 c = caddm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 answer = int4x2(
		5, 5,
		4, 4,
		9, 9,
		12, 12
	);

	int4x2 a = int4x2(
		6, 6,
		6, 6,
		12, 12,
		18, 18
	);

	int4x2 b = int4x2(
		1, 1,
		2, 2,
		3, 3,
		6, 6
	);

	int4x2 c = csubm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 answer = int4x2(
		6, 6,
		12, 12,
		36, 36,
		108, 108
	);

	int4x2 a = int4x2(
		6, 6,
		6, 6,
		12, 12,
		18, 18
	);

	int4x2 b = int4x2(
		1, 1,
		2, 2,
		3, 3,
		6, 6
	);

	int4x2 c = cmulm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 answer = int4x2(
		6, 6,
		3, 3,
		4, 4,
		3, 3
	);

	int4x2 a = int4x2(
		6, 6,
		6, 6,
		12, 12,
		18, 18
	);

	int4x2 b = int4x2(
		1, 1,
		2, 2,
		3, 3,
		6, 6
	);

	int4x2 c = cdivm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x4 answer = g_matrixMulAnswer_int4x2;

	int4x2 a = g_matrixMulLHS_int4x2;
	int2x4 b = g_matrixMulRHS_int4x2;
	int4x4 c = a * b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestRelational_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	bool4x2 allTrue = { 		true, true,
		true, true,
		true, true,
		true, true
 };

	int4x2 mat0 = int4x2( 		1, 1,
		1, 1,
		1, 1,
		1, 1
 );
	int4x2 mat1 = int4x2( 		2, 2,
		2, 2,
		2, 2,
		2, 2
 );
	int4x2 mat2 = int4x2( 		3, 3,
		3, 3,
		3, 3,
		3, 3
 );
	int4x2 mat3 = int4x2( 		4, 4,
		4, 4,
		4, 4,
		4, 4
 );

	bool4x2 test0  = mat0 <= mat0;
	bool4x2 test1  = mat0 >= mat0;
	bool4x2 test2  = mat0 <  mat1;
	bool4x2 test3  = mat0 <  mat2;
	bool4x2 test4  = mat0 <  mat3;

	bool4x2 test5  = mat1 >  mat0;
	bool4x2 test6  = mat1 <= mat1;
	bool4x2 test7  = mat1 >= mat1;
	bool4x2 test8  = mat1 <  mat2;
	bool4x2 test9  = mat1 <  mat3;

	bool4x2 test10 = mat2 >  mat0;
	bool4x2 test11 = mat2 >  mat1;
	bool4x2 test12 = mat2 <= mat2;
	bool4x2 test13 = mat2 >= mat2;
	bool4x2 test14 = mat2 <  mat3;

	bool4x2 test15 = mat3 >  mat0;
	bool4x2 test16 = mat3 >  mat1;
	bool4x2 test17 = mat3 >  mat2;
	bool4x2 test18 = mat3 <= mat3;
	bool4x2 test19 = mat3 >= mat3;

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

TEMPER_TEST( TestBitwise_And_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 answer = int4x2(
		5, 5,
		5, 5,
		5, 5,
		5, 5
	);
	int4x2 a = int4x2(
		21, 21,
		21, 21,
		21, 21,
		21, 21
	);
	int4x2 b = int4x2(
		7, 7,
		7, 7,
		7, 7,
		7, 7
	);

	int4x2 c = a & b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_Or_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 answer = int4x2(
		23, 23,
		23, 23,
		23, 23,
		23, 23
	);
	int4x2 a = int4x2(
		21, 21,
		21, 21,
		21, 21,
		21, 21
	);
	int4x2 b = int4x2(
		7, 7,
		7, 7,
		7, 7,
		7, 7
	);

	int4x2 c = a | b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_Xor_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 answer = int4x2(
		18, 18,
		18, 18,
		18, 18,
		18, 18
	);
	int4x2 a = int4x2(
		21, 21,
		21, 21,
		21, 21,
		21, 21
	);
	int4x2 b = int4x2(
		7, 7,
		7, 7,
		7, 7,
		7, 7
	);

	int4x2 c = a ^ b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_ShiftLeft_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 answer = int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	);
	int4x2 a = int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	);
	int4x2 b = int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	);

	int4x2 c = a << b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_ShiftRight_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 answer = int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	);
	int4x2 a = int4x2(
		16, 16,
		16, 16,
		16, 16,
		16, 16
	);
	int4x2 b = int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	);

	int4x2 c = a >> b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_Unary_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 answer = int4x2(
		(int32_t) -1, (int32_t) -1,
		(int32_t) -1, (int32_t) -1,
		(int32_t) -1, (int32_t) -1,
		(int32_t) -1, (int32_t) -1
	);
	int4x2 a = int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	);

	int4x2 b = ~a;

	TEMPER_CHECK_TRUE( b == answer );
}

TEMPER_TEST( TestIdentity_Scalar_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int4x2 id;
	id[0] = int2( 1, 0 );
	id[1] = int2( 0, 1 );
	id[2] = int2( 0, 0 );
	id[3] = int2( 0, 0 );

	int4x2 mat;

	identity( mat );
	TEMPER_CHECK_TRUE( mat == id );
}

TEMPER_TEST( TestTranspose_Scalar_int4x2, TEMPER_FLAG_SHOULD_RUN )
{
	int2x4 answerTransposed = int2x4(
		0, 4, 8, 12,
		1, 5, 9, 13
	);

	int4x2 mat = int4x2(
		0, 1,
		4, 5,
		8, 9,
		12, 13
	);
	int2x4 trans = transpose( mat );

	TEMPER_CHECK_TRUE( trans == answerTransposed );
}

