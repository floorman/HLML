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

static uint3x2 g_matrixMulLHS_uint3x2    = uint3x2( 		6U, 6U,
		6U, 6U,
		12U, 12U
 );

static uint2x3 g_matrixMulRHS_uint3x2    = uint2x3( 		1U, 1U, 1U,
		2U, 2U, 2U
 );

static uint3x3 g_matrixMulAnswer_uint3x2 = uint3x3( 		18U, 18U, 18U,
		18U, 18U, 18U,
		36U, 36U, 36U
 );


TEMPER_TEST( TestAssignment_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 mat;

	mat.rows[0] = uint2( 999U, 0U );
	mat.rows[1] = uint2( 0U, 999U );
	mat.rows[2] = uint2( 0U, 0U );

	TEMPER_CHECK_TRUE( mat.rows[0].x == 999U );
	TEMPER_CHECK_TRUE( mat.rows[0].y == 0U );
	TEMPER_CHECK_TRUE( mat.rows[1].x == 0U );
	TEMPER_CHECK_TRUE( mat.rows[1].y == 999U );
	TEMPER_CHECK_TRUE( mat.rows[2].x == 0U );
	TEMPER_CHECK_TRUE( mat.rows[2].y == 0U );
}

TEMPER_TEST( TestCtor_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 mat;

	// fill single value
	mat = uint3x2( 999U );
	TEMPER_CHECK_TRUE( mat[0] == uint2( 999U, 0U ) );
	TEMPER_CHECK_TRUE( mat[1] == uint2( 0U, 999U ) );
	TEMPER_CHECK_TRUE( mat[2] == uint2( 0U, 0U ) );

	// row filling
	mat = uint3x2(
		uint2( 0U, 1U ),
		uint2( 4U, 5U ),
		uint2( 8U, 9U )
	);
	TEMPER_CHECK_TRUE( mat[0] == uint2( 0U, 1U ) );
	TEMPER_CHECK_TRUE( mat[1] == uint2( 4U, 5U ) );
	TEMPER_CHECK_TRUE( mat[2] == uint2( 8U, 9U ) );

	// all values filled
	mat = uint3x2(
		16U, 15U,
		12U, 11U,
		8U, 7U
	);
	TEMPER_CHECK_TRUE( mat[0] == uint2( 16U, 15U ) );
	TEMPER_CHECK_TRUE( mat[1] == uint2( 12U, 11U ) );
	TEMPER_CHECK_TRUE( mat[2] == uint2( 8U, 7U ) );
}

TEMPER_TEST( TestArray_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 mat;
	identity( mat );

	TEMPER_CHECK_TRUE( mat[0] == uint2( 1U, 0U ) );
	TEMPER_CHECK_TRUE( mat[1] == uint2( 0U, 1U ) );
	TEMPER_CHECK_TRUE( mat[2] == uint2( 0U, 0U ) );
}

TEMPER_TEST( TestIncrement_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 answer;
	uint3x2 mat;

	// prefix
	answer = uint3x2(
		1U, 1U,
		1U, 1U,
		1U, 1U
	);

	mat = uint3x2(
		0U, 0U,
		0U, 0U,
		0U, 0U

	);
	++mat;
	TEMPER_CHECK_TRUE( mat == answer );

	// postfix
	answer = uint3x2(
		1U, 1U,
		1U, 1U,
		1U, 1U
	);

	mat = uint3x2(
		0U, 0U,
		0U, 0U,
		0U, 0U

	);
	mat++;
	TEMPER_CHECK_TRUE( mat == answer );
}

TEMPER_TEST( TestDecrement_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 answer;
	uint3x2 mat;

	// prefix
	answer = uint3x2(
		0U, 0U,
		0U, 0U,
		0U, 0U
	);

	mat = uint3x2(
		1U, 1U,
		1U, 1U,
		1U, 1U

	);
	--mat;
	TEMPER_CHECK_TRUE( mat == answer );

	// postfix
	answer = uint3x2(
		0U, 0U,
		0U, 0U,
		0U, 0U
	);

	mat = uint3x2(
		1U, 1U,
		1U, 1U,
		1U, 1U

	);
	mat--;
	TEMPER_CHECK_TRUE( mat == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 answer = uint3x2(
		7U, 7U,
		8U, 8U,
		15U, 15U
	);

	uint3x2 a = uint3x2(
		6U, 6U,
		6U, 6U,
		12U, 12U
	);

	uint3x2 b = uint3x2(
		1U, 1U,
		2U, 2U,
		3U, 3U
	);

	uint3x2 c = caddm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 answer = uint3x2(
		5U, 5U,
		4U, 4U,
		9U, 9U
	);

	uint3x2 a = uint3x2(
		6U, 6U,
		6U, 6U,
		12U, 12U
	);

	uint3x2 b = uint3x2(
		1U, 1U,
		2U, 2U,
		3U, 3U
	);

	uint3x2 c = csubm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 answer = uint3x2(
		6U, 6U,
		12U, 12U,
		36U, 36U
	);

	uint3x2 a = uint3x2(
		6U, 6U,
		6U, 6U,
		12U, 12U
	);

	uint3x2 b = uint3x2(
		1U, 1U,
		2U, 2U,
		3U, 3U
	);

	uint3x2 c = cmulm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 answer = uint3x2(
		6U, 6U,
		3U, 3U,
		4U, 4U
	);

	uint3x2 a = uint3x2(
		6U, 6U,
		6U, 6U,
		12U, 12U
	);

	uint3x2 b = uint3x2(
		1U, 1U,
		2U, 2U,
		3U, 3U
	);

	uint3x2 c = cdivm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 answer = g_matrixMulAnswer_uint3x2;

	uint3x2 a = g_matrixMulLHS_uint3x2;
	uint2x3 b = g_matrixMulRHS_uint3x2;
	uint3x3 c = a * b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestRelational_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	bool3x2 allTrue = { 		true, true,
		true, true,
		true, true
 };

	uint3x2 mat0 = uint3x2( 		1U, 1U,
		1U, 1U,
		1U, 1U
 );
	uint3x2 mat1 = uint3x2( 		2U, 2U,
		2U, 2U,
		2U, 2U
 );
	uint3x2 mat2 = uint3x2( 		3U, 3U,
		3U, 3U,
		3U, 3U
 );
	uint3x2 mat3 = uint3x2( 		4U, 4U,
		4U, 4U,
		4U, 4U
 );

	bool3x2 test0  = mat0 <= mat0;
	bool3x2 test1  = mat0 >= mat0;
	bool3x2 test2  = mat0 <  mat1;
	bool3x2 test3  = mat0 <  mat2;
	bool3x2 test4  = mat0 <  mat3;

	bool3x2 test5  = mat1 >  mat0;
	bool3x2 test6  = mat1 <= mat1;
	bool3x2 test7  = mat1 >= mat1;
	bool3x2 test8  = mat1 <  mat2;
	bool3x2 test9  = mat1 <  mat3;

	bool3x2 test10 = mat2 >  mat0;
	bool3x2 test11 = mat2 >  mat1;
	bool3x2 test12 = mat2 <= mat2;
	bool3x2 test13 = mat2 >= mat2;
	bool3x2 test14 = mat2 <  mat3;

	bool3x2 test15 = mat3 >  mat0;
	bool3x2 test16 = mat3 >  mat1;
	bool3x2 test17 = mat3 >  mat2;
	bool3x2 test18 = mat3 <= mat3;
	bool3x2 test19 = mat3 >= mat3;

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

TEMPER_TEST( TestBitwise_And_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 answer = uint3x2(
		5U, 5U,
		5U, 5U,
		5U, 5U
	);
	uint3x2 a = uint3x2(
		21U, 21U,
		21U, 21U,
		21U, 21U
	);
	uint3x2 b = uint3x2(
		7U, 7U,
		7U, 7U,
		7U, 7U
	);

	uint3x2 c = a & b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_Or_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 answer = uint3x2(
		23U, 23U,
		23U, 23U,
		23U, 23U
	);
	uint3x2 a = uint3x2(
		21U, 21U,
		21U, 21U,
		21U, 21U
	);
	uint3x2 b = uint3x2(
		7U, 7U,
		7U, 7U,
		7U, 7U
	);

	uint3x2 c = a | b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_Xor_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 answer = uint3x2(
		18U, 18U,
		18U, 18U,
		18U, 18U
	);
	uint3x2 a = uint3x2(
		21U, 21U,
		21U, 21U,
		21U, 21U
	);
	uint3x2 b = uint3x2(
		7U, 7U,
		7U, 7U,
		7U, 7U
	);

	uint3x2 c = a ^ b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_ShiftLeft_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 answer = uint3x2(
		4U, 4U,
		4U, 4U,
		4U, 4U
	);
	uint3x2 a = uint3x2(
		1U, 1U,
		1U, 1U,
		1U, 1U
	);
	uint3x2 b = uint3x2(
		2U, 2U,
		2U, 2U,
		2U, 2U
	);

	uint3x2 c = a << b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_ShiftRight_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 answer = uint3x2(
		1U, 1U,
		1U, 1U,
		1U, 1U
	);
	uint3x2 a = uint3x2(
		16U, 16U,
		16U, 16U,
		16U, 16U
	);
	uint3x2 b = uint3x2(
		4U, 4U,
		4U, 4U,
		4U, 4U
	);

	uint3x2 c = a >> b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_Unary_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 answer = uint3x2(
		(uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1
	);
	uint3x2 a = uint3x2(
		0U, 0U,
		0U, 0U,
		0U, 0U
	);

	uint3x2 b = ~a;

	TEMPER_CHECK_TRUE( b == answer );
}

TEMPER_TEST( TestIdentity_Scalar_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x2 id;
	id[0] = uint2( 1U, 0U );
	id[1] = uint2( 0U, 1U );
	id[2] = uint2( 0U, 0U );

	uint3x2 mat;

	identity( mat );
	TEMPER_CHECK_TRUE( mat == id );
}

TEMPER_TEST( TestTranspose_Scalar_uint3x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x3 answerTransposed = uint2x3(
		0U, 4U, 8U,
		1U, 5U, 9U
	);

	uint3x2 mat = uint3x2(
		0U, 1U,
		4U, 5U,
		8U, 9U
	);
	uint2x3 trans = transpose( mat );

	TEMPER_CHECK_TRUE( trans == answerTransposed );
}

