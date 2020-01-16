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

TEMPER_TEST( TestAssignment_uint4 )
{
	uint4 vec;

	vec.x = 1U;
	vec.y = 1U;
	vec.z = 1U;
	vec.w = 1U;
	TEMPER_EXPECT_TRUE( vec.x == 1U );
	TEMPER_EXPECT_TRUE( vec.y == 1U );
	TEMPER_EXPECT_TRUE( vec.z == 1U );
	TEMPER_EXPECT_TRUE( vec.w == 1U );

	vec.x = 0U;
	vec.y = 1U;
	vec.z = 2U;
	vec.w = 3U;
	TEMPER_EXPECT_TRUE( vec.x == 0U );
	TEMPER_EXPECT_TRUE( vec.y == 1U );
	TEMPER_EXPECT_TRUE( vec.z == 2U );
	TEMPER_EXPECT_TRUE( vec.w == 3U );

	TEMPER_PASS();
}

// also tests equality operators
TEMPER_TEST( TestCtor_uint4 )
{
	uint4 vec;

	// single value
	vec = uint4( 1U );
	TEMPER_EXPECT_TRUE( vec == uint4( 1U ) );
	TEMPER_EXPECT_TRUE( vec != uint4( 0U, 1U, 2U, 3U ) );

	// all values set
	vec = uint4( 0U, 1U, 2U, 3U );
	TEMPER_EXPECT_TRUE( vec == uint4( 0U, 1U, 2U, 3U ) );
	TEMPER_EXPECT_TRUE( vec != uint4( 1U ) );

	// copy ctors of other vector types
	uint2 other2 = { 10U, 11U };
	vec = uint4( other2 );
	TEMPER_EXPECT_TRUE( vec.x == 10U );
	TEMPER_EXPECT_TRUE( vec.y == 11U );

	uint3 other3 = { 10U, 11U, 14U };
	vec = uint4( other3 );
	TEMPER_EXPECT_TRUE( vec.x == 10U );
	TEMPER_EXPECT_TRUE( vec.y == 11U );
	TEMPER_EXPECT_TRUE( vec.z == 14U );

	uint4 other4 = { 10U, 11U, 14U, 15U };
	vec = uint4( other4 );
	TEMPER_EXPECT_TRUE( vec.x == 10U );
	TEMPER_EXPECT_TRUE( vec.y == 11U );
	TEMPER_EXPECT_TRUE( vec.z == 14U );
	TEMPER_EXPECT_TRUE( vec.w == 15U );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_uint4 )
{
	uint4 a = uint4( 0U, 1U, 2U, 3U );

	TEMPER_EXPECT_TRUE( a.x == 0U );
	TEMPER_EXPECT_TRUE( a.y == 1U );
	TEMPER_EXPECT_TRUE( a.z == 2U );
	TEMPER_EXPECT_TRUE( a.w == 3U );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_uint4 )
{
	uint4 vec;

	// prefix
	vec = uint4( 0U, 0U, 0U, 0U );
	++vec;
	TEMPER_EXPECT_TRUE( vec == uint4( 1U, 1U, 1U, 1U ) );

	// postfix
	vec = uint4( 0U, 0U, 0U, 0U );
	vec++;
	TEMPER_EXPECT_TRUE( vec == uint4( 1U, 1U, 1U, 1U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_uint4 )
{
	uint4 vec;

	// prefix
	vec = uint4( 1U, 1U, 1U, 1U );
	--vec;
	TEMPER_EXPECT_TRUE( vec == uint4( 0U, 0U, 0U, 0U ) );

	// postfix
	vec = uint4( 1U, 1U, 1U, 1U );
	vec--;
	TEMPER_EXPECT_TRUE( vec == uint4( 0U, 0U, 0U, 0U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_uint4 )
{
	uint4 a = uint4( 6U );
	uint4 b = uint4( 2U, 3U, 4U, 5U );

	uint4 c = a + b;

	TEMPER_EXPECT_TRUE( c == uint4( 8U, 9U, 10U, 11U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_uint4 )
{
	uint4 a = uint4( 6U );
	uint4 b = uint4( 2U, 3U, 4U, 5U );

	uint4 c = a - b;

	TEMPER_EXPECT_TRUE( c == uint4( 4U, 3U, 2U, 1U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_uint4 )
{
	uint4 a = uint4( 6U );
	uint4 b = uint4( 2U, 3U, 4U, 5U );

	uint4 c = a * b;

	TEMPER_EXPECT_TRUE( c == uint4( 12U, 18U, 24U, 30U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_uint4 )
{
	uint4 a = uint4( 6U );
	uint4 b = uint4( 2U, 2U, 3U, 6U );

	uint4 c = a / b;

	TEMPER_EXPECT_TRUE( c == uint4( 3U, 3U, 2U, 1U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_uint4 )
{
	bool4 allTrue = bool4( true );

	uint4 vec0 = uint4( 0U );
	uint4 vec1 = uint4( 1U );
	uint4 vec2 = uint4( 2U );
	uint4 vec3 = uint4( 3U );

	bool4 test0  = vec0 <= vec0;
	bool4 test1  = vec0 >= vec0;
	bool4 test2  = vec0 <  vec1;
	bool4 test3  = vec0 <  vec2;
	bool4 test4  = vec0 <  vec3;

	bool4 test5  = vec1 >  vec0;
	bool4 test6  = vec1 <= vec1;
	bool4 test7  = vec1 >= vec1;
	bool4 test8  = vec1 <  vec2;
	bool4 test9  = vec1 <  vec3;

	bool4 test10 = vec2 >  vec0;
	bool4 test11 = vec2 >  vec1;
	bool4 test12 = vec2 <= vec2;
	bool4 test13 = vec2 >= vec2;
	bool4 test14 = vec2 <  vec3;

	bool4 test15 = vec3 >  vec0;
	bool4 test16 = vec3 >  vec1;
	bool4 test17 = vec3 >  vec2;
	bool4 test18 = vec3 <= vec3;
	bool4 test19 = vec3 >= vec3;

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

TEMPER_TEST( TestBitwise_And_uint4 )
{
	uint4 a  = uint4( 21U, 21U, 21U, 21U );
	uint4 b  = uint4( 7U, 7U, 7U, 7U );

	uint4 answer = a & b;

	TEMPER_EXPECT_TRUE( answer == uint4( 5U, 5U, 5U, 5U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Or_uint4 )
{
	uint4 a  = uint4( 21U, 21U, 21U, 21U );
	uint4 b  = uint4( 7U, 7U, 7U, 7U );

	uint4 answer = a | b;

	TEMPER_EXPECT_TRUE( answer == uint4( 23U, 23U, 23U, 23U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Xor_uint4 )
{
	uint4 a  = uint4( 21U, 21U, 21U, 21U );
	uint4 b  = uint4( 7U, 7U, 7U, 7U );

	uint4 answer = a ^ b;

	TEMPER_EXPECT_TRUE( answer == uint4( 18U, 18U, 18U, 18U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftLeft_uint4 )
{
	uint4 a  = uint4( 1U, 1U, 1U, 1U );
	uint4 b  = uint4( 2U, 2U, 2U, 2U );

	uint4 answer = a << b;

	TEMPER_EXPECT_TRUE( answer == uint4( 4U, 4U, 4U, 4U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftRight_uint4 )
{
	uint4 a  = uint4( 16U, 16U, 16U, 16U );
	uint4 b  = uint4( 4U, 4U, 4U, 4U );

	uint4 answer = a >> b;

	TEMPER_EXPECT_TRUE( answer == uint4( 1U, 1U, 1U, 1U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Unary_uint4 )
{
	uint4 a = uint4( 0U, 0U, 0U, 0U );

	uint4 answer = ~a;

	TEMPER_EXPECT_TRUE( answer == uint4( (uint32_t) -1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLength_Scalar_uint4 )
{
	uint4 vec = uint4( 2U );

	TEMPER_EXPECT_TRUE( floateq( lengthsqr( vec ), 16.0f ) );
	TEMPER_EXPECT_TRUE( floateq( length( vec ), 4.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestPacking_uint4 )
{
	uint32_t answerPacked = 0xFFFF00FF;
	uint4 vec = uint4( 255U, 255U, 0U, 255U );
	uint32_t packed = pack( vec );
	TEMPER_EXPECT_TRUE( packed == answerPacked );

	uint4 answerUnpacked = uint4( 255U, 255U, 0U, 255U );
	uint4 unpacked = unpack( packed );
	TEMPER_EXPECT_TRUE( unpacked == answerUnpacked );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_uint4 )
{
	TEMPER_RUN_TEST( TestAssignment_uint4 );
	TEMPER_RUN_TEST( TestCtor_uint4 );
	TEMPER_RUN_TEST( TestArray_uint4 );
	TEMPER_RUN_TEST( TestIncrement_uint4 );
	TEMPER_RUN_TEST( TestDecrement_uint4 );
	TEMPER_RUN_TEST( TestArithmeticAddition_uint4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_uint4 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_uint4 );
	TEMPER_RUN_TEST( TestArithmeticDivision_uint4 );
	TEMPER_RUN_TEST( TestRelational_uint4 );
	TEMPER_RUN_TEST( TestBitwise_And_uint4 );
	TEMPER_RUN_TEST( TestBitwise_Or_uint4 );
	TEMPER_RUN_TEST( TestBitwise_Xor_uint4 );
	TEMPER_RUN_TEST( TestBitwise_ShiftLeft_uint4 );
	TEMPER_RUN_TEST( TestBitwise_ShiftRight_uint4 );
	TEMPER_RUN_TEST( TestBitwise_Unary_uint4 );
	TEMPER_RUN_TEST( TestLength_Scalar_uint4 );
	TEMPER_RUN_TEST( TestPacking_uint4 );
}
