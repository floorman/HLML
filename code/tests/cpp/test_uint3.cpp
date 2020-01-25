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

TEMPER_TEST( TestAssignment_uint3, void )
{
	uint3 vec;

	vec.x = 1U;
	vec.y = 1U;
	vec.z = 1U;
	TEMPER_EXPECT_TRUE( vec.x == 1U );
	TEMPER_EXPECT_TRUE( vec.y == 1U );
	TEMPER_EXPECT_TRUE( vec.z == 1U );

	vec.x = 0U;
	vec.y = 1U;
	vec.z = 2U;
	TEMPER_EXPECT_TRUE( vec.x == 0U );
	TEMPER_EXPECT_TRUE( vec.y == 1U );
	TEMPER_EXPECT_TRUE( vec.z == 2U );

	TEMPER_PASS();
}

// also tests equality operators
TEMPER_TEST( TestCtor_uint3, void )
{
	uint3 vec;

	// single value
	vec = uint3( 1U );
	TEMPER_EXPECT_TRUE( vec == uint3( 1U ) );
	TEMPER_EXPECT_TRUE( vec != uint3( 0U, 1U, 2U ) );

	// all values set
	vec = uint3( 0U, 1U, 2U );
	TEMPER_EXPECT_TRUE( vec == uint3( 0U, 1U, 2U ) );
	TEMPER_EXPECT_TRUE( vec != uint3( 1U ) );

	// copy ctors of other vector types
	uint2 other2 = { 10U, 11U };
	vec = uint3( other2 );
	TEMPER_EXPECT_TRUE( vec.x == 10U );
	TEMPER_EXPECT_TRUE( vec.y == 11U );

	uint3 other3 = { 10U, 11U, 14U };
	vec = uint3( other3 );
	TEMPER_EXPECT_TRUE( vec.x == 10U );
	TEMPER_EXPECT_TRUE( vec.y == 11U );
	TEMPER_EXPECT_TRUE( vec.z == 14U );

	uint4 other4 = { 10U, 11U, 14U, 15U };
	vec = uint3( other4 );
	TEMPER_EXPECT_TRUE( vec.x == 10U );
	TEMPER_EXPECT_TRUE( vec.y == 11U );
	TEMPER_EXPECT_TRUE( vec.z == 14U );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_uint3, void )
{
	uint3 a = uint3( 0U, 1U, 2U );

	TEMPER_EXPECT_TRUE( a.x == 0U );
	TEMPER_EXPECT_TRUE( a.y == 1U );
	TEMPER_EXPECT_TRUE( a.z == 2U );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_uint3, void )
{
	uint3 vec;

	// prefix
	vec = uint3( 0U, 0U, 0U );
	++vec;
	TEMPER_EXPECT_TRUE( vec == uint3( 1U, 1U, 1U ) );

	// postfix
	vec = uint3( 0U, 0U, 0U );
	vec++;
	TEMPER_EXPECT_TRUE( vec == uint3( 1U, 1U, 1U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_uint3, void )
{
	uint3 vec;

	// prefix
	vec = uint3( 1U, 1U, 1U );
	--vec;
	TEMPER_EXPECT_TRUE( vec == uint3( 0U, 0U, 0U ) );

	// postfix
	vec = uint3( 1U, 1U, 1U );
	vec--;
	TEMPER_EXPECT_TRUE( vec == uint3( 0U, 0U, 0U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_uint3, void )
{
	uint3 a = uint3( 6U );
	uint3 b = uint3( 2U, 3U, 4U );

	uint3 c = a + b;

	TEMPER_EXPECT_TRUE( c == uint3( 8U, 9U, 10U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_uint3, void )
{
	uint3 a = uint3( 6U );
	uint3 b = uint3( 2U, 3U, 4U );

	uint3 c = a - b;

	TEMPER_EXPECT_TRUE( c == uint3( 4U, 3U, 2U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_uint3, void )
{
	uint3 a = uint3( 6U );
	uint3 b = uint3( 2U, 3U, 4U );

	uint3 c = a * b;

	TEMPER_EXPECT_TRUE( c == uint3( 12U, 18U, 24U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_uint3, void )
{
	uint3 a = uint3( 6U );
	uint3 b = uint3( 2U, 2U, 3U );

	uint3 c = a / b;

	TEMPER_EXPECT_TRUE( c == uint3( 3U, 3U, 2U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_uint3, void )
{
	bool3 allTrue = bool3( true );

	uint3 vec0 = uint3( 0U );
	uint3 vec1 = uint3( 1U );
	uint3 vec2 = uint3( 2U );
	uint3 vec3 = uint3( 3U );

	bool3 test0  = vec0 <= vec0;
	bool3 test1  = vec0 >= vec0;
	bool3 test2  = vec0 <  vec1;
	bool3 test3  = vec0 <  vec2;
	bool3 test4  = vec0 <  vec3;

	bool3 test5  = vec1 >  vec0;
	bool3 test6  = vec1 <= vec1;
	bool3 test7  = vec1 >= vec1;
	bool3 test8  = vec1 <  vec2;
	bool3 test9  = vec1 <  vec3;

	bool3 test10 = vec2 >  vec0;
	bool3 test11 = vec2 >  vec1;
	bool3 test12 = vec2 <= vec2;
	bool3 test13 = vec2 >= vec2;
	bool3 test14 = vec2 <  vec3;

	bool3 test15 = vec3 >  vec0;
	bool3 test16 = vec3 >  vec1;
	bool3 test17 = vec3 >  vec2;
	bool3 test18 = vec3 <= vec3;
	bool3 test19 = vec3 >= vec3;

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

TEMPER_TEST( TestBitwise_And_uint3, void )
{
	uint3 a  = uint3( 21U, 21U, 21U );
	uint3 b  = uint3( 7U, 7U, 7U );

	uint3 answer = a & b;

	TEMPER_EXPECT_TRUE( answer == uint3( 5U, 5U, 5U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Or_uint3, void )
{
	uint3 a  = uint3( 21U, 21U, 21U );
	uint3 b  = uint3( 7U, 7U, 7U );

	uint3 answer = a | b;

	TEMPER_EXPECT_TRUE( answer == uint3( 23U, 23U, 23U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Xor_uint3, void )
{
	uint3 a  = uint3( 21U, 21U, 21U );
	uint3 b  = uint3( 7U, 7U, 7U );

	uint3 answer = a ^ b;

	TEMPER_EXPECT_TRUE( answer == uint3( 18U, 18U, 18U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftLeft_uint3, void )
{
	uint3 a  = uint3( 1U, 1U, 1U );
	uint3 b  = uint3( 2U, 2U, 2U );

	uint3 answer = a << b;

	TEMPER_EXPECT_TRUE( answer == uint3( 4U, 4U, 4U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftRight_uint3, void )
{
	uint3 a  = uint3( 16U, 16U, 16U );
	uint3 b  = uint3( 4U, 4U, 4U );

	uint3 answer = a >> b;

	TEMPER_EXPECT_TRUE( answer == uint3( 1U, 1U, 1U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Unary_uint3, void )
{
	uint3 a = uint3( 0U, 0U, 0U );

	uint3 answer = ~a;

	TEMPER_EXPECT_TRUE( answer == uint3( (uint32_t) -1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLength_Scalar_uint3, void )
{
	uint3 vec = uint3( 2U );

	TEMPER_EXPECT_TRUE( floateq( lengthsqr( vec ), 12.0f ) );
	TEMPER_EXPECT_TRUE( floateq( length( vec ), 3.46410161514f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDistance_Scalar_uint3, void )
{
	float answerDistanceSqr = 105.0f;
	float answerDistance    = 10.246951f;

	uint3 a = uint3( 7U, 4U, 3U );
	uint3 b = uint3( 17U, 6U, 2U );

	float distSqr = distancesqr( a, b );
	float dist    = distance( a, b );

	TEMPER_EXPECT_TRUE( floateq( distSqr, answerDistanceSqr ) );
	TEMPER_EXPECT_TRUE( floateq( dist, answerDistance ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_uint3 )
{
	TEMPER_RUN_TEST( TestAssignment_uint3 );
	TEMPER_RUN_TEST( TestCtor_uint3 );
	TEMPER_RUN_TEST( TestArray_uint3 );
	TEMPER_RUN_TEST( TestIncrement_uint3 );
	TEMPER_RUN_TEST( TestDecrement_uint3 );
	TEMPER_RUN_TEST( TestArithmeticAddition_uint3 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_uint3 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_uint3 );
	TEMPER_RUN_TEST( TestArithmeticDivision_uint3 );
	TEMPER_RUN_TEST( TestRelational_uint3 );
	TEMPER_RUN_TEST( TestBitwise_And_uint3 );
	TEMPER_RUN_TEST( TestBitwise_Or_uint3 );
	TEMPER_RUN_TEST( TestBitwise_Xor_uint3 );
	TEMPER_RUN_TEST( TestBitwise_ShiftLeft_uint3 );
	TEMPER_RUN_TEST( TestBitwise_ShiftRight_uint3 );
	TEMPER_RUN_TEST( TestBitwise_Unary_uint3 );
	TEMPER_RUN_TEST( TestLength_Scalar_uint3 );
	TEMPER_RUN_TEST( TestDistance_Scalar_uint3 );
}
