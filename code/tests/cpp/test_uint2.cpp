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

TEMPER_TEST( TestAssignment_uint2 )
{
	uint2 vec;

	vec.x = 1U;
	vec.y = 1U;
	TEMPER_EXPECT_TRUE( vec.x == 1U );
	TEMPER_EXPECT_TRUE( vec.y == 1U );

	vec.x = 0U;
	vec.y = 1U;
	TEMPER_EXPECT_TRUE( vec.x == 0U );
	TEMPER_EXPECT_TRUE( vec.y == 1U );

	TEMPER_PASS();
}

// also tests equality operators
TEMPER_TEST( TestCtor_uint2 )
{
	uint2 vec;

	vec = uint2( 1U );
	TEMPER_EXPECT_TRUE( vec == uint2( 1U ) );
	TEMPER_EXPECT_TRUE( vec != uint2( 0U, 1U ) );

	vec = uint2( 0U, 1U );
	TEMPER_EXPECT_TRUE( vec == uint2( 0U, 1U ) );
	TEMPER_EXPECT_TRUE( vec != uint2( 1U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_uint2 )
{
	uint2 a = uint2( 0U, 1U );

	TEMPER_EXPECT_TRUE( a.x == 0U );
	TEMPER_EXPECT_TRUE( a.y == 1U );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_uint2 )
{
	uint2 vec;

	// prefix
	vec = uint2( 0U, 0U );
	++vec;
	TEMPER_EXPECT_TRUE( vec == uint2( 1U, 1U ) );

	// postfix
	vec = uint2( 0U, 0U );
	vec++;
	TEMPER_EXPECT_TRUE( vec == uint2( 1U, 1U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_uint2 )
{
	uint2 vec;

	// prefix
	vec = uint2( 1U, 1U );
	--vec;
	TEMPER_EXPECT_TRUE( vec == uint2( 0U, 0U ) );

	// postfix
	vec = uint2( 1U, 1U );
	vec--;
	TEMPER_EXPECT_TRUE( vec == uint2( 0U, 0U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_uint2 )
{
	uint2 a = uint2( 6U );
	uint2 b = uint2( 2U, 3U );

	uint2 c = a + b;

	TEMPER_EXPECT_TRUE( c == uint2( 8U, 9U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_uint2 )
{
	uint2 a = uint2( 6U );
	uint2 b = uint2( 2U, 3U );

	uint2 c = a - b;

	TEMPER_EXPECT_TRUE( c == uint2( 4U, 3U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_uint2 )
{
	uint2 a = uint2( 6U );
	uint2 b = uint2( 2U, 3U );

	uint2 c = a * b;

	TEMPER_EXPECT_TRUE( c == uint2( 12U, 18U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_uint2 )
{
	uint2 a = uint2( 6U );
	uint2 b = uint2( 2U, 2U );

	uint2 c = a / b;

	TEMPER_EXPECT_TRUE( c == uint2( 3U, 3U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_uint2 )
{
	bool2 allTrue = bool2( true );

	uint2 vec0 = uint2( 0U );
	uint2 vec1 = uint2( 1U );
	uint2 vec2 = uint2( 2U );
	uint2 vec3 = uint2( 3U );

	bool2 test0  = vec0 <= vec0;
	bool2 test1  = vec0 >= vec0;
	bool2 test2  = vec0 <  vec1;
	bool2 test3  = vec0 <  vec2;
	bool2 test4  = vec0 <  vec3;

	bool2 test5  = vec1 >  vec0;
	bool2 test6  = vec1 <= vec1;
	bool2 test7  = vec1 >= vec1;
	bool2 test8  = vec1 <  vec2;
	bool2 test9  = vec1 <  vec3;

	bool2 test10 = vec2 >  vec0;
	bool2 test11 = vec2 >  vec1;
	bool2 test12 = vec2 <= vec2;
	bool2 test13 = vec2 >= vec2;
	bool2 test14 = vec2 <  vec3;

	bool2 test15 = vec3 >  vec0;
	bool2 test16 = vec3 >  vec1;
	bool2 test17 = vec3 >  vec2;
	bool2 test18 = vec3 <= vec3;
	bool2 test19 = vec3 >= vec3;

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

TEMPER_TEST( TestBitwise_And_uint2 )
{
	uint2 a  = uint2( 21U, 21U );
	uint2 b  = uint2( 7U, 7U );

	uint2 answer = a & b;

	TEMPER_EXPECT_TRUE( answer == uint2( 5U, 5U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Or_uint2 )
{
	uint2 a  = uint2( 21U, 21U );
	uint2 b  = uint2( 7U, 7U );

	uint2 answer = a | b;

	TEMPER_EXPECT_TRUE( answer == uint2( 23U, 23U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Xor_uint2 )
{
	uint2 a  = uint2( 21U, 21U );
	uint2 b  = uint2( 7U, 7U );

	uint2 answer = a ^ b;

	TEMPER_EXPECT_TRUE( answer == uint2( 18U, 18U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftLeft_uint2 )
{
	uint2 a  = uint2( 1U, 1U );
	uint2 b  = uint2( 2U, 2U );

	uint2 answer = a << b;

	TEMPER_EXPECT_TRUE( answer == uint2( 4U, 4U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftRight_uint2 )
{
	uint2 a  = uint2( 16U, 16U );
	uint2 b  = uint2( 4U, 4U );

	uint2 answer = a >> b;

	TEMPER_EXPECT_TRUE( answer == uint2( 1U, 1U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Unary_uint2 )
{
	uint2 a = uint2( 0U, 0U );

	uint2 answer = ~a;

	TEMPER_EXPECT_TRUE( answer == uint2( (uint32_t) -1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLength_Scalar_uint2 )
{
	uint2 vec = uint2( 2U );

	TEMPER_EXPECT_TRUE( floateq( lengthsqr( vec ), 8.0f ) );
	TEMPER_EXPECT_TRUE( floateq( length( vec ), 2.82842712475f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDistance_Scalar_uint2 )
{
	float answerDistanceSqr = 104.0f;
	float answerDistance    = 10.198039f;

	uint2 a = uint2( 7U, 4U );
	uint2 b = uint2( 17U, 6U );

	float distSqr = distancesqr( a, b );
	float dist    = distance( a, b );

	TEMPER_EXPECT_TRUE( floateq( distSqr, answerDistanceSqr ) );
	TEMPER_EXPECT_TRUE( floateq( dist, answerDistance ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_uint2 )
{
	TEMPER_RUN_TEST( TestAssignment_uint2 );
	TEMPER_RUN_TEST( TestCtor_uint2 );
	TEMPER_RUN_TEST( TestArray_uint2 );
	TEMPER_RUN_TEST( TestIncrement_uint2 );
	TEMPER_RUN_TEST( TestDecrement_uint2 );
	TEMPER_RUN_TEST( TestArithmeticAddition_uint2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_uint2 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_uint2 );
	TEMPER_RUN_TEST( TestArithmeticDivision_uint2 );
	TEMPER_RUN_TEST( TestRelational_uint2 );
	TEMPER_RUN_TEST( TestBitwise_And_uint2 );
	TEMPER_RUN_TEST( TestBitwise_Or_uint2 );
	TEMPER_RUN_TEST( TestBitwise_Xor_uint2 );
	TEMPER_RUN_TEST( TestBitwise_ShiftLeft_uint2 );
	TEMPER_RUN_TEST( TestBitwise_ShiftRight_uint2 );
	TEMPER_RUN_TEST( TestBitwise_Unary_uint2 );
	TEMPER_RUN_TEST( TestLength_Scalar_uint2 );
	TEMPER_RUN_TEST( TestDistance_Scalar_uint2 );
}