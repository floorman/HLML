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

static uint3x3 g_matrixMulLHS_uint3x3    = {
		6U, 6U, 6U,
		6U, 6U, 6U,
		12U, 12U, 12U
};

static uint3x3 g_matrixMulRHS_uint3x3    = {
		1U, 1U, 1U,
		2U, 2U, 2U,
		3U, 3U, 3U
};

static uint3x3 g_matrixMulAnswer_uint3x3 = {
		36U, 36U, 36U,
		36U, 36U, 36U,
		72U, 72U, 72U
};


TEMPER_TEST( TestAssignment_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 mat;

	mat.rows[0] = (uint3) { 999U, 0U, 0U };
	mat.rows[1] = (uint3) { 0U, 999U, 0U };
	mat.rows[2] = (uint3) { 0U, 0U, 999U };

	TEMPER_CHECK_TRUE( mat.rows[0].x == 999U );
	TEMPER_CHECK_TRUE( mat.rows[0].y == 0U );
	TEMPER_CHECK_TRUE( mat.rows[0].z == 0U );
	TEMPER_CHECK_TRUE( mat.rows[1].x == 0U );
	TEMPER_CHECK_TRUE( mat.rows[1].y == 999U );
	TEMPER_CHECK_TRUE( mat.rows[1].z == 0U );
	TEMPER_CHECK_TRUE( mat.rows[2].x == 0U );
	TEMPER_CHECK_TRUE( mat.rows[2].y == 0U );
	TEMPER_CHECK_TRUE( mat.rows[2].z == 999U );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 answer = (uint3x3) {
		7U, 7U, 7U,
		8U, 8U, 8U,
		15U, 15U, 15U
	};

	uint3x3 a = (uint3x3) {
		6U, 6U, 6U,
		6U, 6U, 6U,
		12U, 12U, 12U
	};

	uint3x3 b = (uint3x3) {
		1U, 1U, 1U,
		2U, 2U, 2U,
		3U, 3U, 3U
	};

	uint3x3 c = uint3x3_caddm( &a, &b );

	TEMPER_CHECK_TRUE( uint3x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 answer = (uint3x3) {
		5U, 5U, 5U,
		4U, 4U, 4U,
		9U, 9U, 9U
	};

	uint3x3 a = (uint3x3) {
		6U, 6U, 6U,
		6U, 6U, 6U,
		12U, 12U, 12U
	};

	uint3x3 b = (uint3x3) {
		1U, 1U, 1U,
		2U, 2U, 2U,
		3U, 3U, 3U
	};

	uint3x3 c = uint3x3_csubm( &a, &b );

	TEMPER_CHECK_TRUE( uint3x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 answer = (uint3x3) {
		6U, 6U, 6U,
		12U, 12U, 12U,
		36U, 36U, 36U
	};

	uint3x3 a = (uint3x3) {
		6U, 6U, 6U,
		6U, 6U, 6U,
		12U, 12U, 12U
	};

	uint3x3 b = (uint3x3) {
		1U, 1U, 1U,
		2U, 2U, 2U,
		3U, 3U, 3U
	};

	uint3x3 c = uint3x3_cmulm( &a, &b );

	TEMPER_CHECK_TRUE( uint3x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 answer = (uint3x3) {
		6U, 6U, 6U,
		3U, 3U, 3U,
		4U, 4U, 4U
	};

	uint3x3 a = (uint3x3) {
		6U, 6U, 6U,
		6U, 6U, 6U,
		12U, 12U, 12U
	};

	uint3x3 b = (uint3x3) {
		1U, 1U, 1U,
		2U, 2U, 2U,
		3U, 3U, 3U
	};

	uint3x3 c = uint3x3_cdivm( &a, &b );

	TEMPER_CHECK_TRUE( uint3x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 answer = g_matrixMulAnswer_uint3x3;

	uint3x3 a = g_matrixMulLHS_uint3x3;
	uint3x3 b = g_matrixMulRHS_uint3x3;
	uint3x3 c = uint3x3_mulm( &a, &b );

	TEMPER_CHECK_TRUE( uint3x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestMultiplyVector_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3 answerVec = { 16U, 44U, 72U };

	uint3x3 a = (uint3x3) {
		1U, 2U, 3U,
		5U, 6U, 7U,
		9U, 10U, 11U
	};
	uint3 b = { 2U, 1U, 4U };
	uint3 c = uint3x3_mulv( &a, &b );

	TEMPER_CHECK_TRUE( uint3_cmpe( &c, &answerVec ) );
}

TEMPER_TEST( TestRelational_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	bool3x3 allTrue = { 		true, true, true,
		true, true, true,
		true, true, true
 };

	uint3x3 mat0 = (uint3x3) { 		1U, 1U, 1U,
		1U, 1U, 1U,
		1U, 1U, 1U
 };
	uint3x3 mat1 = (uint3x3) { 		2U, 2U, 2U,
		2U, 2U, 2U,
		2U, 2U, 2U
 };
	uint3x3 mat2 = (uint3x3) { 		3U, 3U, 3U,
		3U, 3U, 3U,
		3U, 3U, 3U
 };
	uint3x3 mat3 = (uint3x3) { 		4U, 4U, 4U,
		4U, 4U, 4U,
		4U, 4U, 4U
 };

	bool3x3 test0  = uint3x3_cmple( &mat0, &mat0 );
	bool3x3 test1  = uint3x3_cmpge( &mat0, &mat0 );
	bool3x3 test2  = uint3x3_cmpl( &mat0, &mat1 );
	bool3x3 test3  = uint3x3_cmpl( &mat0, &mat2 );
	bool3x3 test4  = uint3x3_cmpl( &mat0, &mat3 );

	bool3x3 test5  = uint3x3_cmpg( &mat1, &mat0 );
	bool3x3 test6  = uint3x3_cmple( &mat1, &mat1 );
	bool3x3 test7  = uint3x3_cmpge( &mat1, &mat1 );
	bool3x3 test8  = uint3x3_cmpl( &mat1, &mat2 );
	bool3x3 test9  = uint3x3_cmpl( &mat1, &mat3 );

	bool3x3 test10 = uint3x3_cmpg( &mat2, &mat0 );
	bool3x3 test11 = uint3x3_cmpg( &mat2, &mat1 );
	bool3x3 test12 = uint3x3_cmple( &mat2, &mat2 );
	bool3x3 test13 = uint3x3_cmpge( &mat2, &mat2 );
	bool3x3 test14 = uint3x3_cmpl( &mat2, &mat3 );

	bool3x3 test15 = uint3x3_cmpg( &mat3, &mat0 );
	bool3x3 test16 = uint3x3_cmpg( &mat3, &mat1 );
	bool3x3 test17 = uint3x3_cmpg( &mat3, &mat2 );
	bool3x3 test18 = uint3x3_cmple( &mat3, &mat3 );
	bool3x3 test19 = uint3x3_cmpge( &mat3, &mat3 );

	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test0,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test1,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test2,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test3,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test4,  &allTrue ) );

	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test5,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test6,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test7,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test8,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test9,  &allTrue ) );

	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test10, &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test11, &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test12, &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test13, &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test14, &allTrue ) );

	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test15, &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test16, &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test17, &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test18, &allTrue ) );
	TEMPER_CHECK_TRUE( bool3x3_cmpe( &test19, &allTrue ) );
}

TEMPER_TEST( TestBitwise_And_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 answer  = (uint3x3) {
		5U, 5U, 5U,
		5U, 5U, 5U,
		5U, 5U, 5U
	};
	uint3x3 a = (uint3x3) {
		21U, 21U, 21U,
		21U, 21U, 21U,
		21U, 21U, 21U
	};
	uint3x3 b = (uint3x3) {
		7U, 7U, 7U,
		7U, 7U, 7U,
		7U, 7U, 7U
	};
	uint3x3 c = uint3x3_cand( &a, &b );

	TEMPER_CHECK_TRUE( uint3x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_Or_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 answer  = (uint3x3) {
		23U, 23U, 23U,
		23U, 23U, 23U,
		23U, 23U, 23U
	};
	uint3x3 a = (uint3x3) {
		21U, 21U, 21U,
		21U, 21U, 21U,
		21U, 21U, 21U
	};
	uint3x3 b = (uint3x3) {
		7U, 7U, 7U,
		7U, 7U, 7U,
		7U, 7U, 7U
	};
	uint3x3 c = uint3x3_cor( &a, &b );

	TEMPER_CHECK_TRUE( uint3x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_Xor_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 answer  = (uint3x3) {
		18U, 18U, 18U,
		18U, 18U, 18U,
		18U, 18U, 18U
	};
	uint3x3 a = (uint3x3) {
		21U, 21U, 21U,
		21U, 21U, 21U,
		21U, 21U, 21U
	};
	uint3x3 b = (uint3x3) {
		7U, 7U, 7U,
		7U, 7U, 7U,
		7U, 7U, 7U
	};
	uint3x3 c = uint3x3_cxor( &a, &b );

	TEMPER_CHECK_TRUE( uint3x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_ShiftLeft_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 answer  = (uint3x3) {
		4U, 4U, 4U,
		4U, 4U, 4U,
		4U, 4U, 4U
	};
	uint3x3 a = (uint3x3) {
		1U, 1U, 1U,
		1U, 1U, 1U,
		1U, 1U, 1U
	};
	uint3x3 b = (uint3x3) {
		2U, 2U, 2U,
		2U, 2U, 2U,
		2U, 2U, 2U
	};
	uint3x3 c = uint3x3_cshift_left( &a, &b );

	TEMPER_CHECK_TRUE( uint3x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_ShiftRight_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 answer  = (uint3x3) {
		1U, 1U, 1U,
		1U, 1U, 1U,
		1U, 1U, 1U
	};
	uint3x3 a = (uint3x3) {
		16U, 16U, 16U,
		16U, 16U, 16U,
		16U, 16U, 16U
	};
	uint3x3 b = (uint3x3) {
		4U, 4U, 4U,
		4U, 4U, 4U,
		4U, 4U, 4U
	};
	uint3x3 c = uint3x3_cshift_right( &a, &b );

	TEMPER_CHECK_TRUE( uint3x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_Unary_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 answer = (uint3x3) {
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1
	};
	uint3x3 a = (uint3x3) {
		0U, 0U, 0U,
		0U, 0U, 0U,
		0U, 0U, 0U
	};

	uint3x3 b = uint3x3_cunary( &a );

	TEMPER_CHECK_TRUE( uint3x3_cmpe( &b, &answer ) );
}

TEMPER_TEST( TestIdentity_Scalar_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 id;
	id.rows[0] = (uint3) { 1U, 0U, 0U };
	id.rows[1] = (uint3) { 0U, 1U, 0U };
	id.rows[2] = (uint3) { 0U, 0U, 1U };

	uint3x3 mat;
	uint3x3_identity( &mat );
	TEMPER_CHECK_TRUE( uint3x3_cmpe( &mat, &id ) );
}

TEMPER_TEST( TestTranspose_Scalar_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 answerTransposed = (uint3x3) {
		0U, 4U, 8U,
		1U, 5U, 9U,
		2U, 6U, 10U
	};

	uint3x3 mat = (uint3x3) {
		0U, 1U, 2U,
		4U, 5U, 6U,
		8U, 9U, 10U
	};
	uint3x3 trans = uint3x3_transpose( &mat );

	TEMPER_CHECK_TRUE( uint3x3_cmpe( &trans, &answerTransposed ) );
}

TEMPER_TEST( TestTranslate_Scalar_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint3x3 mat;
	uint3x3_identity( &mat );

	uint2 translation = { 2U, 3U };

	mat = uint3x3_translate( &mat, &translation );

	TEMPER_CHECK_TRUE( mat.rows[0].z == 2U );
	TEMPER_CHECK_TRUE( mat.rows[1].z == 3U );
}

TEMPER_TEST( TestScale_Scalar_uint3x3, TEMPER_FLAG_SHOULD_RUN )
{
	uint2 scaleVec = { 2U, 2U };
	uint3x3 mat;
	uint3x3_identity( &mat );

	uint3x3 scaled = uint3x3_scale( &mat, &scaleVec );

	TEMPER_CHECK_TRUE( scaled.rows[0].x == 2U );
	TEMPER_CHECK_TRUE( scaled.rows[1].y == 2U );
}

