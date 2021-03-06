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

static uint2x4 g_matrixMulLHS_uint2x4    = {
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U
};

static uint4x2 g_matrixMulRHS_uint2x4    = {
		1U, 1U,
		2U, 2U,
		3U, 3U,
		6U, 6U
};

static uint2x2 g_matrixMulAnswer_uint2x4 = {
		72U, 72U,
		72U, 72U
};


TEMPER_TEST( TestAssignment_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 mat;

	mat.rows[0] = (uint4) { 999U, 0U, 0U, 0U };
	mat.rows[1] = (uint4) { 0U, 999U, 0U, 0U };

	TEMPER_CHECK_TRUE( mat.rows[0].x == 999U );
	TEMPER_CHECK_TRUE( mat.rows[0].y == 0U );
	TEMPER_CHECK_TRUE( mat.rows[0].z == 0U );
	TEMPER_CHECK_TRUE( mat.rows[0].w == 0U );
	TEMPER_CHECK_TRUE( mat.rows[1].x == 0U );
	TEMPER_CHECK_TRUE( mat.rows[1].y == 999U );
	TEMPER_CHECK_TRUE( mat.rows[1].z == 0U );
	TEMPER_CHECK_TRUE( mat.rows[1].w == 0U );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = (uint2x4) {
		7U, 7U, 7U, 7U,
		8U, 8U, 8U, 8U
	};

	uint2x4 a = (uint2x4) {
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U
	};

	uint2x4 b = (uint2x4) {
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U
	};

	uint2x4 c = uint2x4_caddm( &a, &b );

	TEMPER_CHECK_TRUE( uint2x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = (uint2x4) {
		5U, 5U, 5U, 5U,
		4U, 4U, 4U, 4U
	};

	uint2x4 a = (uint2x4) {
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U
	};

	uint2x4 b = (uint2x4) {
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U
	};

	uint2x4 c = uint2x4_csubm( &a, &b );

	TEMPER_CHECK_TRUE( uint2x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = (uint2x4) {
		6U, 6U, 6U, 6U,
		12U, 12U, 12U, 12U
	};

	uint2x4 a = (uint2x4) {
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U
	};

	uint2x4 b = (uint2x4) {
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U
	};

	uint2x4 c = uint2x4_cmulm( &a, &b );

	TEMPER_CHECK_TRUE( uint2x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = (uint2x4) {
		6U, 6U, 6U, 6U,
		3U, 3U, 3U, 3U
	};

	uint2x4 a = (uint2x4) {
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U
	};

	uint2x4 b = (uint2x4) {
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U
	};

	uint2x4 c = uint2x4_cdivm( &a, &b );

	TEMPER_CHECK_TRUE( uint2x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x2 answer = g_matrixMulAnswer_uint2x4;

	uint2x4 a = g_matrixMulLHS_uint2x4;
	uint4x2 b = g_matrixMulRHS_uint2x4;
	uint2x2 c = uint2x4_mulm( &a, &b );

	TEMPER_CHECK_TRUE( uint2x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestRelational_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	bool2x4 allTrue = { 		true, true, true, true,
		true, true, true, true
 };

	uint2x4 mat0 = (uint2x4) { 		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
 };
	uint2x4 mat1 = (uint2x4) { 		2U, 2U, 2U, 2U,
		2U, 2U, 2U, 2U
 };
	uint2x4 mat2 = (uint2x4) { 		3U, 3U, 3U, 3U,
		3U, 3U, 3U, 3U
 };
	uint2x4 mat3 = (uint2x4) { 		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U
 };

	bool2x4 test0  = uint2x4_cmple( &mat0, &mat0 );
	bool2x4 test1  = uint2x4_cmpge( &mat0, &mat0 );
	bool2x4 test2  = uint2x4_cmpl( &mat0, &mat1 );
	bool2x4 test3  = uint2x4_cmpl( &mat0, &mat2 );
	bool2x4 test4  = uint2x4_cmpl( &mat0, &mat3 );

	bool2x4 test5  = uint2x4_cmpg( &mat1, &mat0 );
	bool2x4 test6  = uint2x4_cmple( &mat1, &mat1 );
	bool2x4 test7  = uint2x4_cmpge( &mat1, &mat1 );
	bool2x4 test8  = uint2x4_cmpl( &mat1, &mat2 );
	bool2x4 test9  = uint2x4_cmpl( &mat1, &mat3 );

	bool2x4 test10 = uint2x4_cmpg( &mat2, &mat0 );
	bool2x4 test11 = uint2x4_cmpg( &mat2, &mat1 );
	bool2x4 test12 = uint2x4_cmple( &mat2, &mat2 );
	bool2x4 test13 = uint2x4_cmpge( &mat2, &mat2 );
	bool2x4 test14 = uint2x4_cmpl( &mat2, &mat3 );

	bool2x4 test15 = uint2x4_cmpg( &mat3, &mat0 );
	bool2x4 test16 = uint2x4_cmpg( &mat3, &mat1 );
	bool2x4 test17 = uint2x4_cmpg( &mat3, &mat2 );
	bool2x4 test18 = uint2x4_cmple( &mat3, &mat3 );
	bool2x4 test19 = uint2x4_cmpge( &mat3, &mat3 );

	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test0,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test1,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test2,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test3,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test4,  &allTrue ) );

	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test5,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test6,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test7,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test8,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test9,  &allTrue ) );

	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test10, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test11, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test12, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test13, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test14, &allTrue ) );

	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test15, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test16, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test17, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test18, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test19, &allTrue ) );
}

TEMPER_TEST( TestBitwise_And_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer  = (uint2x4) {
		5U, 5U, 5U, 5U,
		5U, 5U, 5U, 5U
	};
	uint2x4 a = (uint2x4) {
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U
	};
	uint2x4 b = (uint2x4) {
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U
	};
	uint2x4 c = uint2x4_cand( &a, &b );

	TEMPER_CHECK_TRUE( uint2x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_Or_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer  = (uint2x4) {
		23U, 23U, 23U, 23U,
		23U, 23U, 23U, 23U
	};
	uint2x4 a = (uint2x4) {
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U
	};
	uint2x4 b = (uint2x4) {
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U
	};
	uint2x4 c = uint2x4_cor( &a, &b );

	TEMPER_CHECK_TRUE( uint2x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_Xor_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer  = (uint2x4) {
		18U, 18U, 18U, 18U,
		18U, 18U, 18U, 18U
	};
	uint2x4 a = (uint2x4) {
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U
	};
	uint2x4 b = (uint2x4) {
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U
	};
	uint2x4 c = uint2x4_cxor( &a, &b );

	TEMPER_CHECK_TRUE( uint2x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_ShiftLeft_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer  = (uint2x4) {
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U
	};
	uint2x4 a = (uint2x4) {
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
	};
	uint2x4 b = (uint2x4) {
		2U, 2U, 2U, 2U,
		2U, 2U, 2U, 2U
	};
	uint2x4 c = uint2x4_cshift_left( &a, &b );

	TEMPER_CHECK_TRUE( uint2x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_ShiftRight_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer  = (uint2x4) {
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
	};
	uint2x4 a = (uint2x4) {
		16U, 16U, 16U, 16U,
		16U, 16U, 16U, 16U
	};
	uint2x4 b = (uint2x4) {
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U
	};
	uint2x4 c = uint2x4_cshift_right( &a, &b );

	TEMPER_CHECK_TRUE( uint2x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_Unary_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answer = (uint2x4) {
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1, (uint32_t) -1
	};
	uint2x4 a = (uint2x4) {
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U
	};

	uint2x4 b = uint2x4_cunary( &a );

	TEMPER_CHECK_TRUE( uint2x4_cmpe( &b, &answer ) );
}

TEMPER_TEST( TestIdentity_Scalar_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 id;
	id.rows[0] = (uint4) { 1U, 0U, 0U, 0U };
	id.rows[1] = (uint4) { 0U, 1U, 0U, 0U };

	uint2x4 mat;
	uint2x4_identity( &mat );
	TEMPER_CHECK_TRUE( uint2x4_cmpe( &mat, &id ) );
}

TEMPER_TEST( TestTranspose_Scalar_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 answerTransposed = (uint4x2) {
		0U, 4U,
		1U, 5U,
		2U, 6U,
		3U, 7U
	};

	uint2x4 mat = (uint2x4) {
		0U, 1U, 2U, 3U,
		4U, 5U, 6U, 7U
	};
	uint4x2 trans = uint2x4_transpose( &mat );

	TEMPER_CHECK_TRUE( uint4x2_cmpe( &trans, &answerTransposed ) );
}

TEMPER_TEST( TestScale_Scalar_uint2x4, TEMPER_FLAG_SHOULD_RUN )
{
	uint2 scaleVec = { 2U, 2U };
	uint2x4 mat;
	uint2x4_identity( &mat );

	uint2x4 scaled = uint2x4_scale( &mat, &scaleVec );

	TEMPER_CHECK_TRUE( scaled.rows[0].x == 2U );
	TEMPER_CHECK_TRUE( scaled.rows[1].y == 2U );
}

