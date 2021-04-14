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

static float4x2 g_matrixMulLHS_float4x2    = {
		6.000000f, 6.000000f,
		6.000000f, 6.000000f,
		12.000000f, 12.000000f,
		18.000000f, 18.000000f
};

static float2x4 g_matrixMulRHS_float4x2    = {
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
};

static float4x4 g_matrixMulAnswer_float4x2 = {
		18.000000f, 18.000000f, 18.000000f, 18.000000f,
		18.000000f, 18.000000f, 18.000000f, 18.000000f,
		36.000000f, 36.000000f, 36.000000f, 36.000000f,
		54.000000f, 54.000000f, 54.000000f, 54.000000f
};


TEMPER_TEST( TestAssignment_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float4x2 mat;

	mat.rows[0] = (float2) { 999.000000f, 0.000000f };
	mat.rows[1] = (float2) { 0.000000f, 999.000000f };
	mat.rows[2] = (float2) { 0.000000f, 0.000000f };
	mat.rows[3] = (float2) { 0.000000f, 0.000000f };

	TEMPER_CHECK_TRUE( mat.rows[0].x == 999.0f );
	TEMPER_CHECK_TRUE( mat.rows[0].y == 0.0f );
	TEMPER_CHECK_TRUE( mat.rows[1].x == 0.0f );
	TEMPER_CHECK_TRUE( mat.rows[1].y == 999.0f );
	TEMPER_CHECK_TRUE( mat.rows[2].x == 0.0f );
	TEMPER_CHECK_TRUE( mat.rows[2].y == 0.0f );
	TEMPER_CHECK_TRUE( mat.rows[3].x == 0.0f );
	TEMPER_CHECK_TRUE( mat.rows[3].y == 0.0f );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float4x2 answer = (float4x2) {
		7.000000f, 7.000000f,
		8.000000f, 8.000000f,
		15.000000f, 15.000000f,
		24.000000f, 24.000000f
	};

	float4x2 a = (float4x2) {
		6.000000f, 6.000000f,
		6.000000f, 6.000000f,
		12.000000f, 12.000000f,
		18.000000f, 18.000000f
	};

	float4x2 b = (float4x2) {
		1.000000f, 1.000000f,
		2.000000f, 2.000000f,
		3.000000f, 3.000000f,
		6.000000f, 6.000000f
	};

	float4x2 c = float4x2_caddm( &a, &b );

	TEMPER_CHECK_TRUE( float4x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float4x2 answer = (float4x2) {
		5.000000f, 5.000000f,
		4.000000f, 4.000000f,
		9.000000f, 9.000000f,
		12.000000f, 12.000000f
	};

	float4x2 a = (float4x2) {
		6.000000f, 6.000000f,
		6.000000f, 6.000000f,
		12.000000f, 12.000000f,
		18.000000f, 18.000000f
	};

	float4x2 b = (float4x2) {
		1.000000f, 1.000000f,
		2.000000f, 2.000000f,
		3.000000f, 3.000000f,
		6.000000f, 6.000000f
	};

	float4x2 c = float4x2_csubm( &a, &b );

	TEMPER_CHECK_TRUE( float4x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float4x2 answer = (float4x2) {
		6.000000f, 6.000000f,
		12.000000f, 12.000000f,
		36.000000f, 36.000000f,
		108.000000f, 108.000000f
	};

	float4x2 a = (float4x2) {
		6.000000f, 6.000000f,
		6.000000f, 6.000000f,
		12.000000f, 12.000000f,
		18.000000f, 18.000000f
	};

	float4x2 b = (float4x2) {
		1.000000f, 1.000000f,
		2.000000f, 2.000000f,
		3.000000f, 3.000000f,
		6.000000f, 6.000000f
	};

	float4x2 c = float4x2_cmulm( &a, &b );

	TEMPER_CHECK_TRUE( float4x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float4x2 answer = (float4x2) {
		6.000000f, 6.000000f,
		3.000000f, 3.000000f,
		4.000000f, 4.000000f,
		3.000000f, 3.000000f
	};

	float4x2 a = (float4x2) {
		6.000000f, 6.000000f,
		6.000000f, 6.000000f,
		12.000000f, 12.000000f,
		18.000000f, 18.000000f
	};

	float4x2 b = (float4x2) {
		1.000000f, 1.000000f,
		2.000000f, 2.000000f,
		3.000000f, 3.000000f,
		6.000000f, 6.000000f
	};

	float4x2 c = float4x2_cdivm( &a, &b );

	TEMPER_CHECK_TRUE( float4x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_SSE_Addition_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a20[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a21[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a30[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };
	float a31[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b20[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b21[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b30[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float b31[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float4x2_sse_t results;
	float4x2_sse_t lhs;
	float4x2_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[2][0] = _mm_load_ps( a20 );
	lhs.m[2][1] = _mm_load_ps( a21 );
	lhs.m[3][0] = _mm_load_ps( a30 );
	lhs.m[3][1] = _mm_load_ps( a31 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[2][0] = _mm_load_ps( b20 );
	rhs.m[2][1] = _mm_load_ps( b21 );
	rhs.m[3][0] = _mm_load_ps( b30 );
	rhs.m[3][1] = _mm_load_ps( b31 );

	float4x2_caddm_sse( &lhs, &rhs, &results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results.m[0][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 7.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 7.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 8.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 8.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[2][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 15.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 15.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 15.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 15.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[2][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 15.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 15.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 15.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 15.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[3][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 24.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 24.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 24.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 24.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[3][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 24.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 24.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 24.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 24.000000f ) );

}

TEMPER_TEST( TestComponentWiseArithmetic_SSE_Subtraction_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a20[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a21[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a30[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };
	float a31[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b20[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b21[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b30[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float b31[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float4x2_sse_t results;
	float4x2_sse_t lhs;
	float4x2_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[2][0] = _mm_load_ps( a20 );
	lhs.m[2][1] = _mm_load_ps( a21 );
	lhs.m[3][0] = _mm_load_ps( a30 );
	lhs.m[3][1] = _mm_load_ps( a31 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[2][0] = _mm_load_ps( b20 );
	rhs.m[2][1] = _mm_load_ps( b21 );
	rhs.m[3][0] = _mm_load_ps( b30 );
	rhs.m[3][1] = _mm_load_ps( b31 );

	float4x2_csubm_sse( &lhs, &rhs, &results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results.m[0][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 5.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 5.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 4.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 4.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[2][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 9.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 9.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 9.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 9.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[2][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 9.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 9.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 9.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 9.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[3][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 12.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[3][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 12.000000f ) );

}

TEMPER_TEST( TestComponentWiseArithmetic_SSE_Multiplication_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a20[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a21[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a30[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };
	float a31[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b20[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b21[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b30[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float b31[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float4x2_sse_t results;
	float4x2_sse_t lhs;
	float4x2_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[2][0] = _mm_load_ps( a20 );
	lhs.m[2][1] = _mm_load_ps( a21 );
	lhs.m[3][0] = _mm_load_ps( a30 );
	lhs.m[3][1] = _mm_load_ps( a31 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[2][0] = _mm_load_ps( b20 );
	rhs.m[2][1] = _mm_load_ps( b21 );
	rhs.m[3][0] = _mm_load_ps( b30 );
	rhs.m[3][1] = _mm_load_ps( b31 );

	float4x2_cmulm_sse( &lhs, &rhs, &results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results.m[0][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 12.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 12.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[2][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 36.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 36.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 36.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 36.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[2][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 36.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 36.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 36.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 36.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[3][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 108.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 108.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 108.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 108.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[3][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 108.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 108.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 108.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 108.000000f ) );

}

TEMPER_TEST( TestComponentWiseArithmetic_SSE_Division_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a20[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a21[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a30[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };
	float a31[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b20[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b21[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b30[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float b31[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float4x2_sse_t results;
	float4x2_sse_t lhs;
	float4x2_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[2][0] = _mm_load_ps( a20 );
	lhs.m[2][1] = _mm_load_ps( a21 );
	lhs.m[3][0] = _mm_load_ps( a30 );
	lhs.m[3][1] = _mm_load_ps( a31 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[2][0] = _mm_load_ps( b20 );
	rhs.m[2][1] = _mm_load_ps( b21 );
	rhs.m[3][0] = _mm_load_ps( b30 );
	rhs.m[3][1] = _mm_load_ps( b31 );

	float4x2_cdivm_sse( &lhs, &rhs, &results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results.m[0][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 3.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 3.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[2][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 4.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[2][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 4.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[3][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 3.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[3][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 3.000000f ) );

}

TEMPER_TEST( TestMultiplyMatrix_Scalar_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float4x4 answer = g_matrixMulAnswer_float4x2;

	float4x2 a = g_matrixMulLHS_float4x2;
	float2x4 b = g_matrixMulRHS_float4x2;
	float4x4 c = float4x2_mulm( &a, &b );

	TEMPER_CHECK_TRUE( float4x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestMultiplyMatrix_SSE_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a20[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a21[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a30[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };
	float a31[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b02[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b03[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b12[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b13[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };

	float4x4_sse_t results;
	float4x2_sse_t lhs;
	float2x4_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[2][0] = _mm_load_ps( a20 );
	lhs.m[2][1] = _mm_load_ps( a21 );
	lhs.m[3][0] = _mm_load_ps( a30 );
	lhs.m[3][1] = _mm_load_ps( a31 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[0][2] = _mm_load_ps( b02 );
	rhs.m[0][3] = _mm_load_ps( b03 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[1][2] = _mm_load_ps( b12 );
	rhs.m[1][3] = _mm_load_ps( b13 );

	float4x2_mulm_sse( &lhs, &rhs, &results );

	float mulResults[4];

	_mm_store_ps( mulResults, results.m[0][0] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[0].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[0].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[0].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[0].x ) );

	_mm_store_ps( mulResults, results.m[0][1] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[0].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[0].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[0].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[0].y ) );

	_mm_store_ps( mulResults, results.m[0][2] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[0].z ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[0].z ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[0].z ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[0].z ) );

	_mm_store_ps( mulResults, results.m[0][3] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[0].w ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[0].w ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[0].w ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[0].w ) );

	_mm_store_ps( mulResults, results.m[1][0] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[1].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[1].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[1].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[1].x ) );

	_mm_store_ps( mulResults, results.m[1][1] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[1].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[1].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[1].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[1].y ) );

	_mm_store_ps( mulResults, results.m[1][2] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[1].z ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[1].z ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[1].z ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[1].z ) );

	_mm_store_ps( mulResults, results.m[1][3] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[1].w ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[1].w ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[1].w ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[1].w ) );

	_mm_store_ps( mulResults, results.m[2][0] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[2].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[2].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[2].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[2].x ) );

	_mm_store_ps( mulResults, results.m[2][1] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[2].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[2].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[2].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[2].y ) );

	_mm_store_ps( mulResults, results.m[2][2] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[2].z ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[2].z ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[2].z ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[2].z ) );

	_mm_store_ps( mulResults, results.m[2][3] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[2].w ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[2].w ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[2].w ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[2].w ) );

	_mm_store_ps( mulResults, results.m[3][0] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[3].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[3].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[3].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[3].x ) );

	_mm_store_ps( mulResults, results.m[3][1] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[3].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[3].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[3].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[3].y ) );

	_mm_store_ps( mulResults, results.m[3][2] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[3].z ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[3].z ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[3].z ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[3].z ) );

	_mm_store_ps( mulResults, results.m[3][3] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float4x2.rows[3].w ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float4x2.rows[3].w ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float4x2.rows[3].w ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float4x2.rows[3].w ) );

}

TEMPER_TEST( TestRelational_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	bool4x2 allTrue = { 		true, true,
		true, true,
		true, true,
		true, true
 };

	float4x2 mat0 = (float4x2) { 		1.000000f, 1.000000f,
		1.000000f, 1.000000f,
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
 };
	float4x2 mat1 = (float4x2) { 		2.000000f, 2.000000f,
		2.000000f, 2.000000f,
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
 };
	float4x2 mat2 = (float4x2) { 		3.000000f, 3.000000f,
		3.000000f, 3.000000f,
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
 };
	float4x2 mat3 = (float4x2) { 		4.000000f, 4.000000f,
		4.000000f, 4.000000f,
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
 };

	bool4x2 test0  = float4x2_cmple( &mat0, &mat0 );
	bool4x2 test1  = float4x2_cmpge( &mat0, &mat0 );
	bool4x2 test2  = float4x2_cmpl( &mat0, &mat1 );
	bool4x2 test3  = float4x2_cmpl( &mat0, &mat2 );
	bool4x2 test4  = float4x2_cmpl( &mat0, &mat3 );

	bool4x2 test5  = float4x2_cmpg( &mat1, &mat0 );
	bool4x2 test6  = float4x2_cmple( &mat1, &mat1 );
	bool4x2 test7  = float4x2_cmpge( &mat1, &mat1 );
	bool4x2 test8  = float4x2_cmpl( &mat1, &mat2 );
	bool4x2 test9  = float4x2_cmpl( &mat1, &mat3 );

	bool4x2 test10 = float4x2_cmpg( &mat2, &mat0 );
	bool4x2 test11 = float4x2_cmpg( &mat2, &mat1 );
	bool4x2 test12 = float4x2_cmple( &mat2, &mat2 );
	bool4x2 test13 = float4x2_cmpge( &mat2, &mat2 );
	bool4x2 test14 = float4x2_cmpl( &mat2, &mat3 );

	bool4x2 test15 = float4x2_cmpg( &mat3, &mat0 );
	bool4x2 test16 = float4x2_cmpg( &mat3, &mat1 );
	bool4x2 test17 = float4x2_cmpg( &mat3, &mat2 );
	bool4x2 test18 = float4x2_cmple( &mat3, &mat3 );
	bool4x2 test19 = float4x2_cmpge( &mat3, &mat3 );

	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test0,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test1,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test2,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test3,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test4,  &allTrue ) );

	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test5,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test6,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test7,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test8,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test9,  &allTrue ) );

	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test10, &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test11, &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test12, &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test13, &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test14, &allTrue ) );

	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test15, &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test16, &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test17, &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test18, &allTrue ) );
	TEMPER_CHECK_TRUE( bool4x2_cmpe( &test19, &allTrue ) );
}

TEMPER_TEST( TestIdentity_Scalar_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float4x2 id;
	id.rows[0] = (float2) { 1.000000f, 0.000000f };
	id.rows[1] = (float2) { 0.000000f, 1.000000f };
	id.rows[2] = (float2) { 0.000000f, 0.000000f };
	id.rows[3] = (float2) { 0.000000f, 0.000000f };

	float4x2 mat;
	float4x2_identity( &mat );
	TEMPER_CHECK_TRUE( float4x2_cmpe( &mat, &id ) );
}

TEMPER_TEST( TestIdentity_SSE_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float4x2_sse_t matSSE;
	float4x2_identity_sse( &matSSE );

	float identityResults[4];
	_mm_store_ps( identityResults, matSSE.m[0][0] );
	TEMPER_CHECK_TRUE( identityResults[0] == 1.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 1.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 1.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 1.0f );

	_mm_store_ps( identityResults, matSSE.m[0][1] );
	TEMPER_CHECK_TRUE( identityResults[0] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 0.0f );

	_mm_store_ps( identityResults, matSSE.m[1][0] );
	TEMPER_CHECK_TRUE( identityResults[0] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 0.0f );

	_mm_store_ps( identityResults, matSSE.m[1][1] );
	TEMPER_CHECK_TRUE( identityResults[0] == 1.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 1.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 1.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 1.0f );

	_mm_store_ps( identityResults, matSSE.m[2][0] );
	TEMPER_CHECK_TRUE( identityResults[0] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 0.0f );

	_mm_store_ps( identityResults, matSSE.m[2][1] );
	TEMPER_CHECK_TRUE( identityResults[0] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 0.0f );

	_mm_store_ps( identityResults, matSSE.m[3][0] );
	TEMPER_CHECK_TRUE( identityResults[0] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 0.0f );

	_mm_store_ps( identityResults, matSSE.m[3][1] );
	TEMPER_CHECK_TRUE( identityResults[0] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 0.0f );

}

TEMPER_TEST( TestTranspose_Scalar_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float2x4 answerTransposed = (float2x4) {
		0.000000f, 4.000000f, 8.000000f, 12.000000f,
		1.000000f, 5.000000f, 9.000000f, 13.000000f
	};

	float4x2 mat = (float4x2) {
		0.000000f, 1.000000f,
		4.000000f, 5.000000f,
		8.000000f, 9.000000f,
		12.000000f, 13.000000f
	};
	float2x4 trans = float4x2_transpose( &mat );

	TEMPER_CHECK_TRUE( float2x4_cmpe( &trans, &answerTransposed ) );
}

TEMPER_TEST( TestTranspose_SSE_float4x2, TEMPER_FLAG_SHOULD_RUN )
{
	float2x4_sse_t results;
	float4x2_sse_t in;

	// row 0
	in.m[0][0] = _mm_set1_ps( 0.0f );
	in.m[0][1] = _mm_set1_ps( 1.0f );

	// row 1
	in.m[1][0] = _mm_set1_ps( 4.0f );
	in.m[1][1] = _mm_set1_ps( 5.0f );

	// row 2
	in.m[2][0] = _mm_set1_ps( 8.0f );
	in.m[2][1] = _mm_set1_ps( 9.0f );

	// row 3
	in.m[3][0] = _mm_set1_ps( 12.0f );
	in.m[3][1] = _mm_set1_ps( 13.0f );

	float4x2_transpose_sse( &in, &results );

	float transposeResults[4];
	_mm_store_ps( transposeResults, results.m[0][0] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 0.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 0.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 0.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 0.000000f ) );

	_mm_store_ps( transposeResults, results.m[0][1] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 4.000000f ) );

	_mm_store_ps( transposeResults, results.m[0][2] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 8.000000f ) );

	_mm_store_ps( transposeResults, results.m[0][3] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 12.000000f ) );

	_mm_store_ps( transposeResults, results.m[1][0] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 1.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 1.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 1.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 1.000000f ) );

	_mm_store_ps( transposeResults, results.m[1][1] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 5.000000f ) );

	_mm_store_ps( transposeResults, results.m[1][2] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 9.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 9.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 9.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 9.000000f ) );

	_mm_store_ps( transposeResults, results.m[1][3] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 13.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 13.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 13.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 13.000000f ) );

}

