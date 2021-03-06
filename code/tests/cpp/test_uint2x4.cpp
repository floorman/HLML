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

static uint2x4 g_matrixMulLHS_uint2x4    = uint2x4( 		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U
 );

static uint4x2 g_matrixMulRHS_uint2x4    = uint4x2( 		1U, 1U,
		2U, 2U,
		3U, 3U,
		6U, 6U
 );

static uint2x2 g_matrixMulAnswer_uint2x4 = uint2x2( 		72U, 72U,
		72U, 72U
 );


TEMPER_TEST( TestAssignment_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 mat;

	mat.rows[0] = uint4( 999U, 0U, 0U, 0U );
	mat.rows[1] = uint4( 0U, 999U, 0U, 0U );

	TEMPER_CHECK_TRUE( mat.rows[0].x == 999U );
	TEMPER_CHECK_TRUE( mat.rows[0].y == 0U );
	TEMPER_CHECK_TRUE( mat.rows[0].z == 0U );
	TEMPER_CHECK_TRUE( mat.rows[0].w == 0U );
	TEMPER_CHECK_TRUE( mat.rows[1].x == 0U );
	TEMPER_CHECK_TRUE( mat.rows[1].y == 999U );
	TEMPER_CHECK_TRUE( mat.rows[1].z == 0U );
	TEMPER_CHECK_TRUE( mat.rows[1].w == 0U );
}

TEMPER_TEST( TestCtor_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 mat;

	// fill single value
	mat = uint2x4( 999U );
	TEMPER_CHECK_TRUE( mat[0] == uint4( 999U, 0U, 0U, 0U ) );
	TEMPER_CHECK_TRUE( mat[1] == uint4( 0U, 999U, 0U, 0U ) );

	// row filling
	mat = uint2x4(
		uint4( 0U, 1U, 2U, 3U ),
		uint4( 4U, 5U, 6U, 7U )
	);
	TEMPER_CHECK_TRUE( mat[0] == uint4( 0U, 1U, 2U, 3U ) );
	TEMPER_CHECK_TRUE( mat[1] == uint4( 4U, 5U, 6U, 7U ) );

	// all values filled
	mat = uint2x4(
		16U, 15U, 14U, 13U,
		12U, 11U, 10U, 9U
	);
	TEMPER_CHECK_TRUE( mat[0] == uint4( 16U, 15U, 14U, 13U ) );
	TEMPER_CHECK_TRUE( mat[1] == uint4( 12U, 11U, 10U, 9U ) );
}

TEMPER_TEST( TestArray_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 mat;
	identity( mat );

	TEMPER_CHECK_TRUE( mat[0] == uint4( 1U, 0U, 0U, 0U ) );
	TEMPER_CHECK_TRUE( mat[1] == uint4( 0U, 1U, 0U, 0U ) );
}

TEMPER_TEST( TestIncrement_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer;
	uint2x4 mat;

	// prefix
	answer = uint2x4(
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
	);

	mat = uint2x4(
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U

	);
	++mat;
	TEMPER_CHECK_TRUE( mat == answer );

	// postfix
	answer = uint2x4(
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
	);

	mat = uint2x4(
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U

	);
	mat++;
	TEMPER_CHECK_TRUE( mat == answer );
}

TEMPER_TEST( TestDecrement_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer;
	uint2x4 mat;

	// prefix
	answer = uint2x4(
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U
	);

	mat = uint2x4(
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U

	);
	--mat;
	TEMPER_CHECK_TRUE( mat == answer );

	// postfix
	answer = uint2x4(
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U
	);

	mat = uint2x4(
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U

	);
	mat--;
	TEMPER_CHECK_TRUE( mat == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = uint2x4(
		7U, 7U, 7U, 7U,
		8U, 8U, 8U, 8U
	);

	uint2x4 a = uint2x4(
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U
	);

	uint2x4 b = uint2x4(
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U
	);

	uint2x4 c = caddm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = uint2x4(
		5U, 5U, 5U, 5U,
		4U, 4U, 4U, 4U
	);

	uint2x4 a = uint2x4(
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U
	);

	uint2x4 b = uint2x4(
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U
	);

	uint2x4 c = csubm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = uint2x4(
		6U, 6U, 6U, 6U,
		12U, 12U, 12U, 12U
	);

	uint2x4 a = uint2x4(
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U
	);

	uint2x4 b = uint2x4(
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U
	);

	uint2x4 c = cmulm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = uint2x4(
		6U, 6U, 6U, 6U,
		3U, 3U, 3U, 3U
	);

	uint2x4 a = uint2x4(
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U
	);

	uint2x4 b = uint2x4(
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U
	);

	uint2x4 c = cdivm( a, b );

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x2 answer = g_matrixMulAnswer_uint2x4;

	uint2x4 a = g_matrixMulLHS_uint2x4;
	uint4x2 b = g_matrixMulRHS_uint2x4;
	uint2x2 c = a * b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestRelational_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	bool2x4 allTrue = { 		true, true, true, true,
		true, true, true, true
 };

	uint2x4 mat0 = uint2x4( 		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
 );
	uint2x4 mat1 = uint2x4( 		2U, 2U, 2U, 2U,
		2U, 2U, 2U, 2U
 );
	uint2x4 mat2 = uint2x4( 		3U, 3U, 3U, 3U,
		3U, 3U, 3U, 3U
 );
	uint2x4 mat3 = uint2x4( 		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U
 );

	bool2x4 test0  = mat0 <= mat0;
	bool2x4 test1  = mat0 >= mat0;
	bool2x4 test2  = mat0 <  mat1;
	bool2x4 test3  = mat0 <  mat2;
	bool2x4 test4  = mat0 <  mat3;

	bool2x4 test5  = mat1 >  mat0;
	bool2x4 test6  = mat1 <= mat1;
	bool2x4 test7  = mat1 >= mat1;
	bool2x4 test8  = mat1 <  mat2;
	bool2x4 test9  = mat1 <  mat3;

	bool2x4 test10 = mat2 >  mat0;
	bool2x4 test11 = mat2 >  mat1;
	bool2x4 test12 = mat2 <= mat2;
	bool2x4 test13 = mat2 >= mat2;
	bool2x4 test14 = mat2 <  mat3;

	bool2x4 test15 = mat3 >  mat0;
	bool2x4 test16 = mat3 >  mat1;
	bool2x4 test17 = mat3 >  mat2;
	bool2x4 test18 = mat3 <= mat3;
	bool2x4 test19 = mat3 >= mat3;

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

TEMPER_TEST( TestBitwise_And_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = uint2x4(
		5U, 5U, 5U, 5U,
		5U, 5U, 5U, 5U
	);
	uint2x4 a = uint2x4(
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U
	);
	uint2x4 b = uint2x4(
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U
	);

	uint2x4 c = a & b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_Or_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = uint2x4(
		23U, 23U, 23U, 23U,
		23U, 23U, 23U, 23U
	);
	uint2x4 a = uint2x4(
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U
	);
	uint2x4 b = uint2x4(
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U
	);

	uint2x4 c = a | b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_Xor_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = uint2x4(
		18U, 18U, 18U, 18U,
		18U, 18U, 18U, 18U
	);
	uint2x4 a = uint2x4(
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U
	);
	uint2x4 b = uint2x4(
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U
	);

	uint2x4 c = a ^ b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_ShiftLeft_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = uint2x4(
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U
	);
	uint2x4 a = uint2x4(
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
	);
	uint2x4 b = uint2x4(
		2U, 2U, 2U, 2U,
		2U, 2U, 2U, 2U
	);

	uint2x4 c = a << b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_ShiftRight_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = uint2x4(
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
	);
	uint2x4 a = uint2x4(
		16U, 16U, 16U, 16U,
		16U, 16U, 16U, 16U
	);
	uint2x4 b = uint2x4(
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U
	);

	uint2x4 c = a >> b;

	TEMPER_CHECK_TRUE( c == answer );
}

TEMPER_TEST( TestBitwise_Unary_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = uint2x4(
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1, (uint32_t) -1
	);
	uint2x4 a = uint2x4(
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U
	);

	uint2x4 b = ~a;

	TEMPER_CHECK_TRUE( b == answer );
}

TEMPER_TEST( TestIdentity_Scalar_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 id;
	id[0] = uint4( 1U, 0U, 0U, 0U );
	id[1] = uint4( 0U, 1U, 0U, 0U );

	uint2x4 mat;

	identity( mat );
	TEMPER_CHECK_TRUE( mat == id );
}

TEMPER_TEST( TestTranspose_Scalar_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 answerTransposed = uint4x2(
		0U, 4U,
		1U, 5U,
		2U, 6U,
		3U, 7U
	);

	uint2x4 mat = uint2x4(
		0U, 1U, 2U, 3U,
		4U, 5U, 6U, 7U
	);
	uint4x2 trans = transpose( mat );

	TEMPER_CHECK_TRUE( trans == answerTransposed );
}

TEMPER_TEST( TestScale_Scalar_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2 scaleVec = { 2U, 2U };
	uint2x4 mat;
	identity( mat );

	uint2x4 scaled = scale( mat, scaleVec );

	TEMPER_CHECK_TRUE( scaled.rows[0].x == 2U );
	TEMPER_CHECK_TRUE( scaled.rows[1].y == 2U );
}

