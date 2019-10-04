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

#include "../../code/out/gen/hlml_functions_matrix.h"
#include "../../code/out/gen/hlml_operators_matrix.h"
#include "../../code/out/gen/hlml_functions_matrix_sse.h"

#include <temper/temper.h>

static float2x4 g_identityMatrix;

static float2x4 g_matrixMulLHS = float2x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f
	);
static float4x2 g_matrixMulRHS = float4x2(
		1.000000f, 1.000000f,
		2.000000f, 2.000000f,
		3.000000f, 3.000000f,
		6.000000f, 6.000000f
	);
static float2x2 g_matrixMulAnswer = float2x2(
		72.000000f, 72.000000f,
		72.000000f, 72.000000f
	);

TEMPER_TEST( TestAssignment_float2x4 )
{
	float2x4 mat;

	// fill single value
	mat = float2x4( 999.0f );
	TEMPER_EXPECT_TRUE( mat[0] == float4( 999.000000f, 0.000000f, 0.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 0.000000f, 999.000000f, 0.000000f, 0.000000f ) );

	// row filling
	mat = float2x4(
		float4( 0.000000f, 1.000000f, 2.000000f, 3.000000f ),
		float4( 4.000000f, 5.000000f, 6.000000f, 7.000000f )
	);
	TEMPER_EXPECT_TRUE( mat[0] == float4( 0.000000f, 1.000000f, 2.000000f, 3.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 4.000000f, 5.000000f, 6.000000f, 7.000000f ) );

	// all values filled
	mat = float2x4(
		16.000000f, 15.000000f, 14.000000f, 13.000000f,
		12.000000f, 11.000000f, 10.000000f, 9.000000f
	);
	TEMPER_EXPECT_TRUE( mat[0] == float4( 16.000000f, 15.000000f, 14.000000f, 13.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 12.000000f, 11.000000f, 10.000000f, 9.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_float2x4 )
{
	float2x4 answer = float2x4(
		7.000000f, 7.000000f, 7.000000f, 7.000000f,
		8.000000f, 8.000000f, 8.000000f, 8.000000f
	);

	float2x4 a = float2x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f
	);
	float2x4 b = float2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	);
	float2x4 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_float2x4 )
{
	float2x4 answer = float2x4(
		5.000000f, 5.000000f, 5.000000f, 5.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	);

	float2x4 a = float2x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f
	);
	float2x4 b = float2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	);
	float2x4 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_float2x4 )
{
	float2x4 answer = float2x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		12.000000f, 12.000000f, 12.000000f, 12.000000f
	);

	float2x4 a = float2x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f
	);
	float2x4 b = float2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	);
	float2x4 c = comp_mul( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_float2x4 )
{
	float2x4 answer = float2x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	);

	float2x4 a = float2x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f
	);
	float2x4 b = float2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	);
	float2x4 c = comp_div( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_SSE_Addition_float2x4 )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a02[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a03[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a12[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a13[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b02[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b03[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b12[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b13[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };

	float2x4_sse_t results;
	float2x4_sse_t lhs;
	float2x4_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[0][2] = _mm_load_ps( a02 );
	lhs.m[0][3] = _mm_load_ps( a03 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[1][2] = _mm_load_ps( a12 );
	lhs.m[1][3] = _mm_load_ps( a13 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[0][2] = _mm_load_ps( b02 );
	rhs.m[0][3] = _mm_load_ps( b03 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[1][2] = _mm_load_ps( b12 );
	rhs.m[1][3] = _mm_load_ps( b13 );

	comp_add_sse( &lhs, &rhs, &results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results.m[0][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 7.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 7.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][2] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 7.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][3] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 7.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 8.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 8.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 8.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 8.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 8.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 8.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 8.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 8.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][2] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 8.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 8.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 8.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 8.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][3] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 8.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 8.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 8.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 8.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_SSE_Subtraction_float2x4 )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a02[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a03[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a12[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a13[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b02[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b03[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b12[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b13[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };

	float2x4_sse_t results;
	float2x4_sse_t lhs;
	float2x4_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[0][2] = _mm_load_ps( a02 );
	lhs.m[0][3] = _mm_load_ps( a03 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[1][2] = _mm_load_ps( a12 );
	lhs.m[1][3] = _mm_load_ps( a13 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[0][2] = _mm_load_ps( b02 );
	rhs.m[0][3] = _mm_load_ps( b03 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[1][2] = _mm_load_ps( b12 );
	rhs.m[1][3] = _mm_load_ps( b13 );

	comp_sub_sse( &lhs, &rhs, &results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results.m[0][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 5.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 5.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][2] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 5.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][3] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 5.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 4.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 4.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][2] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 4.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][3] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 4.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_SSE_Multiplication_float2x4 )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a02[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a03[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a12[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a13[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b02[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b03[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b12[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b13[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };

	float2x4_sse_t results;
	float2x4_sse_t lhs;
	float2x4_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[0][2] = _mm_load_ps( a02 );
	lhs.m[0][3] = _mm_load_ps( a03 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[1][2] = _mm_load_ps( a12 );
	lhs.m[1][3] = _mm_load_ps( a13 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[0][2] = _mm_load_ps( b02 );
	rhs.m[0][3] = _mm_load_ps( b03 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[1][2] = _mm_load_ps( b12 );
	rhs.m[1][3] = _mm_load_ps( b13 );

	comp_mul_sse( &lhs, &rhs, &results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results.m[0][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][2] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][3] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 12.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 12.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 12.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 12.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 12.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 12.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 12.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 12.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][2] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 12.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 12.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 12.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 12.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][3] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 12.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 12.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 12.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 12.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_SSE_Division_float2x4 )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a02[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a03[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a12[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a13[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b02[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b03[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b12[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b13[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };

	float2x4_sse_t results;
	float2x4_sse_t lhs;
	float2x4_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[0][2] = _mm_load_ps( a02 );
	lhs.m[0][3] = _mm_load_ps( a03 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[1][2] = _mm_load_ps( a12 );
	lhs.m[1][3] = _mm_load_ps( a13 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[0][2] = _mm_load_ps( b02 );
	rhs.m[0][3] = _mm_load_ps( b03 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[1][2] = _mm_load_ps( b12 );
	rhs.m[1][3] = _mm_load_ps( b13 );

	comp_div_sse( &lhs, &rhs, &results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results.m[0][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][2] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][3] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 3.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 3.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][2] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 3.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][3] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], 3.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_float2x4 )
{
	float2x2 answer = g_matrixMulAnswer;

	float2x4 a = g_matrixMulLHS;
	float4x2 b = g_matrixMulRHS;
	float2x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyMatrix_SSE_float2x4 )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a02[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a03[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a12[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a13[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b20[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b21[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b30[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float b31[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float2x2_sse_t results;
	float2x4_sse_t lhs;
	float4x2_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[0][2] = _mm_load_ps( a02 );
	lhs.m[0][3] = _mm_load_ps( a03 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[1][2] = _mm_load_ps( a12 );
	lhs.m[1][3] = _mm_load_ps( a13 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[2][0] = _mm_load_ps( b20 );
	rhs.m[2][1] = _mm_load_ps( b21 );
	rhs.m[3][0] = _mm_load_ps( b30 );
	rhs.m[3][1] = _mm_load_ps( b31 );

	mul_sse( &lhs, &rhs, &results );

	float mulResults[4];

	_mm_store_ps( mulResults, results.m[0][0] );
	TEMPER_EXPECT_TRUE( floateq( mulResults[0], g_matrixMulAnswer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( mulResults[1], g_matrixMulAnswer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( mulResults[2], g_matrixMulAnswer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( mulResults[3], g_matrixMulAnswer[0][0] ) );

	_mm_store_ps( mulResults, results.m[0][1] );
	TEMPER_EXPECT_TRUE( floateq( mulResults[0], g_matrixMulAnswer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( mulResults[1], g_matrixMulAnswer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( mulResults[2], g_matrixMulAnswer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( mulResults[3], g_matrixMulAnswer[0][1] ) );

	_mm_store_ps( mulResults, results.m[1][0] );
	TEMPER_EXPECT_TRUE( floateq( mulResults[0], g_matrixMulAnswer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( mulResults[1], g_matrixMulAnswer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( mulResults[2], g_matrixMulAnswer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( mulResults[3], g_matrixMulAnswer[1][0] ) );

	_mm_store_ps( mulResults, results.m[1][1] );
	TEMPER_EXPECT_TRUE( floateq( mulResults[0], g_matrixMulAnswer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( mulResults[1], g_matrixMulAnswer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( mulResults[2], g_matrixMulAnswer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( mulResults[3], g_matrixMulAnswer[1][1] ) );


	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_float2x4 )
{
	float2x4 mat;

	// prefix
	mat = float2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == float2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	) );

	// postfix
	mat = float2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == float2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_float2x4 )
{
	float2x4 mat;

	// prefix
	mat = float2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == float2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	) );

	// postfix
	mat = float2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == float2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float2x4 )
{
	bool2x4 allTrue = bool2x4(
		true, true, true, true,
		true, true, true, true
	);

	float2x4 mat0 = float2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	);
	float2x4 mat1 = float2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	);
	float2x4 mat2 = float2x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	);
	float2x4 mat3 = float2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
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

TEMPER_TEST( TestArray_float2x4 )
{
	float2x4 mat;

	TEMPER_EXPECT_TRUE( mat[0] == float4( 1.0f, 0.0f, 0.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 0.0f, 1.0f, 0.0f, 0.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_Scalar_float2x4 )
{
	float2x4 id = float2x4(
		1.000000f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.000000f, 0.0f, 0.0f
	);

	float2x4 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_SSE_float2x4 )
{
	float2x4_sse_t matSSE;
	identity_sse( &matSSE );

	float identityResults[4];
	_mm_store_ps( identityResults, matSSE.m[0][0] );
	TEMPER_EXPECT_TRUE( identityResults[0] == 1.0f );
	TEMPER_EXPECT_TRUE( identityResults[1] == 1.0f );
	TEMPER_EXPECT_TRUE( identityResults[2] == 1.0f );
	TEMPER_EXPECT_TRUE( identityResults[3] == 1.0f );

	_mm_store_ps( identityResults, matSSE.m[0][1] );
	TEMPER_EXPECT_TRUE( identityResults[0] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[1] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[2] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[3] == 0.0f );

	_mm_store_ps( identityResults, matSSE.m[0][2] );
	TEMPER_EXPECT_TRUE( identityResults[0] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[1] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[2] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[3] == 0.0f );

	_mm_store_ps( identityResults, matSSE.m[0][3] );
	TEMPER_EXPECT_TRUE( identityResults[0] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[1] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[2] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[3] == 0.0f );

	_mm_store_ps( identityResults, matSSE.m[1][0] );
	TEMPER_EXPECT_TRUE( identityResults[0] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[1] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[2] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[3] == 0.0f );

	_mm_store_ps( identityResults, matSSE.m[1][1] );
	TEMPER_EXPECT_TRUE( identityResults[0] == 1.0f );
	TEMPER_EXPECT_TRUE( identityResults[1] == 1.0f );
	TEMPER_EXPECT_TRUE( identityResults[2] == 1.0f );
	TEMPER_EXPECT_TRUE( identityResults[3] == 1.0f );

	_mm_store_ps( identityResults, matSSE.m[1][2] );
	TEMPER_EXPECT_TRUE( identityResults[0] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[1] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[2] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[3] == 0.0f );

	_mm_store_ps( identityResults, matSSE.m[1][3] );
	TEMPER_EXPECT_TRUE( identityResults[0] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[1] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[2] == 0.0f );
	TEMPER_EXPECT_TRUE( identityResults[3] == 0.0f );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_Scalar_float2x4 )
{
	float2x4 mat = float2x4(
		0.000000f, 1.000000f, 2.000000f, 3.000000f,
		4.000000f, 5.000000f, 6.000000f, 7.000000f
	);
	float4x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == float4x2(
		0.000000f, 4.000000f,
		1.000000f, 5.000000f,
		2.000000f, 6.000000f,
		3.000000f, 7.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_SSE_float2x4 )
{
	float4x2_sse_t results;
	float2x4_sse_t in;

	// row 0
	in.m[0][0] = _mm_set1_ps( 0.0f );
	in.m[0][1] = _mm_set1_ps( 1.0f );
	in.m[0][2] = _mm_set1_ps( 2.0f );
	in.m[0][3] = _mm_set1_ps( 3.0f );

	// row 1
	in.m[1][0] = _mm_set1_ps( 4.0f );
	in.m[1][1] = _mm_set1_ps( 5.0f );
	in.m[1][2] = _mm_set1_ps( 6.0f );
	in.m[1][3] = _mm_set1_ps( 7.0f );

	transpose_sse( &in, &results );

	float transposeResults[4];
	_mm_store_ps( transposeResults, results.m[0][0] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], 0.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], 0.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], 0.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], 0.000000f ) );

	_mm_store_ps( transposeResults, results.m[0][1] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], 4.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], 4.000000f ) );

	_mm_store_ps( transposeResults, results.m[1][0] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], 1.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], 1.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], 1.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], 1.000000f ) );

	_mm_store_ps( transposeResults, results.m[1][1] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], 5.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], 5.000000f ) );

	_mm_store_ps( transposeResults, results.m[2][0] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], 2.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], 2.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], 2.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], 2.000000f ) );

	_mm_store_ps( transposeResults, results.m[2][1] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], 6.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], 6.000000f ) );

	_mm_store_ps( transposeResults, results.m[3][0] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], 3.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], 3.000000f ) );

	_mm_store_ps( transposeResults, results.m[3][1] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], 7.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], 7.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_Scalar_float2x4 )
{
	float2x4 mat;
	float2x4 scaled = scale( mat, float2( 2.000000f, 2.000000f ) );

	TEMPER_EXPECT_TRUE( floateq( scaled[0][0], 2.000000f ) );
	TEMPER_EXPECT_TRUE( floateq( scaled[1][1], 2.000000f ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_float2x4 )
{
	TEMPER_RUN_TEST( TestAssignment_float2x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Addition_float2x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_float2x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_float2x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Division_float2x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_SSE_Addition_float2x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_SSE_Subtraction_float2x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_SSE_Multiplication_float2x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_SSE_Division_float2x4 );
	TEMPER_RUN_TEST( TestMultiplyMatrix_Scalar_float2x4 );
	TEMPER_RUN_TEST( TestMultiplyMatrix_SSE_float2x4 );
	TEMPER_RUN_TEST( TestIncrement_float2x4 );
	TEMPER_RUN_TEST( TestDecrement_float2x4 );
	TEMPER_RUN_TEST( TestRelational_float2x4 );
	TEMPER_RUN_TEST( TestArray_float2x4 );
	TEMPER_RUN_TEST( TestIdentity_Scalar_float2x4 );
	TEMPER_RUN_TEST( TestIdentity_SSE_float2x4 );
	TEMPER_RUN_TEST( TestTranspose_Scalar_float2x4 );
	TEMPER_RUN_TEST( TestTranspose_SSE_float2x4 );
	TEMPER_RUN_TEST( TestScale_Scalar_float2x4 );
}
