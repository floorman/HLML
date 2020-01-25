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

TEMPER_TEST( TestAssignment_double3, void )
{
	double3 vec;

	vec.x = 1.0;
	vec.y = 1.0;
	vec.z = 1.0;
	TEMPER_EXPECT_TRUE( vec.x == 1.0 );
	TEMPER_EXPECT_TRUE( vec.y == 1.0 );
	TEMPER_EXPECT_TRUE( vec.z == 1.0 );

	vec.x = 0.0;
	vec.y = 1.0;
	vec.z = 2.0;
	TEMPER_EXPECT_TRUE( vec.x == 0.0 );
	TEMPER_EXPECT_TRUE( vec.y == 1.0 );
	TEMPER_EXPECT_TRUE( vec.z == 2.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_double3, void )
{
	double3 a = (double3)	{ 6.000000, 6.000000, 6.000000 };
	double3 b = (double3)	{ 2.000000, 3.000000, 4.000000 };
	double3 c = double3_comp_addv( &a, &b );

	TEMPER_EXPECT_TRUE( c.x == 8.0 );
	TEMPER_EXPECT_TRUE( c.y == 9.0 );
	TEMPER_EXPECT_TRUE( c.z == 10.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_double3, void )
{
	double3 a = (double3)	{ 6.000000, 6.000000, 6.000000 };
	double3 b = (double3)	{ 2.000000, 3.000000, 4.000000 };
	double3 c = double3_comp_subv( &a, &b );

	TEMPER_EXPECT_TRUE( c.x == 4.0 );
	TEMPER_EXPECT_TRUE( c.y == 3.0 );
	TEMPER_EXPECT_TRUE( c.z == 2.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_double3, void )
{
	double3 a = (double3)	{ 6.000000, 6.000000, 6.000000 };
	double3 b = (double3)	{ 2.000000, 3.000000, 4.000000 };
	double3 c = double3_comp_mulv( &a, &b );

	TEMPER_EXPECT_TRUE( c.x == 12.0 );
	TEMPER_EXPECT_TRUE( c.y == 18.0 );
	TEMPER_EXPECT_TRUE( c.z == 24.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_double3, void )
{
	double3 a = (double3)	{ 6.000000, 6.000000, 6.000000 };
	double3 b = (double3)	{ 2.000000, 2.000000, 3.000000 };
	double3 c = double3_comp_divv( &a, &b );

	TEMPER_EXPECT_TRUE( c.x == 3.0 );
	TEMPER_EXPECT_TRUE( c.y == 3.0 );
	TEMPER_EXPECT_TRUE( c.z == 2.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double3, void )
{
	bool3 allTrue = (bool3)	{ true, true, true };

	double3 vec0 = (double3)	{ 0.000000, 0.000000, 0.000000 };
	double3 vec1 = (double3)	{ 1.000000, 1.000000, 1.000000 };
	double3 vec2 = (double3)	{ 2.000000, 2.000000, 2.000000 };
	double3 vec3 = (double3)	{ 3.000000, 3.000000, 3.000000 };

	bool3 test0  = double3_cmple( &vec0, &vec0 );
	bool3 test1  = double3_cmpge( &vec0, &vec0 );
	bool3 test2  = double3_cmpl( &vec0, &vec1 );
	bool3 test3  = double3_cmpl( &vec0, &vec2 );
	bool3 test4  = double3_cmpl( &vec0, &vec3 );

	bool3 test5  = double3_cmpg( &vec1, &vec0 );
	bool3 test6  = double3_cmple( &vec1, &vec1 );
	bool3 test7  = double3_cmpge( &vec1, &vec1 );
	bool3 test8  = double3_cmpl( &vec1, &vec2 );
	bool3 test9  = double3_cmpl( &vec1, &vec3 );

	bool3 test10 = double3_cmpg( &vec2, &vec0 );
	bool3 test11 = double3_cmpg( &vec2, &vec1 );
	bool3 test12 = double3_cmple( &vec2, &vec2 );
	bool3 test13 = double3_cmpge( &vec2, &vec2 );
	bool3 test14 = double3_cmpl( &vec2, &vec3 );

	bool3 test15 = double3_cmpg( &vec3, &vec0 );
	bool3 test16 = double3_cmpg( &vec3, &vec1 );
	bool3 test17 = double3_cmpg( &vec3, &vec2 );
	bool3 test18 = double3_cmple( &vec3, &vec3 );
	bool3 test19 = double3_cmpge( &vec3, &vec3 );

	TEMPER_EXPECT_TRUE( bool3_cmpe( &test0,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test1,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test2,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test3,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test4,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool3_cmpe( &test5,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test6,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test7,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test8,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test9,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool3_cmpe( &test10, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test11, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test12, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test13, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test14, &allTrue ) );

	TEMPER_EXPECT_TRUE( bool3_cmpe( &test15, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test16, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test17, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test18, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3_cmpe( &test19, &allTrue ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLength_Scalar_double3, void )
{
	double3 vec = (double3) { 2.0, 2.0, 2.0 };

	TEMPER_EXPECT_TRUE( doubleeq( double3_lengthsqr( &vec ), 12.0 ) );
	TEMPER_EXPECT_TRUE( doubleeq( double3_length( &vec ), 3.46410161514 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestNormalized_Scalar_double3, void )
{
	double3 vec = (double3) { 5.000000, 4.000000, 3.000000 };
	vec = double3_normalized( &vec );

	double veclen = double3_length( &vec );
	TEMPER_EXPECT_TRUE( doubleeq( veclen, 1.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDot_Scalar_double3, void )
{
	double3 a = (double3) { 0.000000, 1.000000, 0.000000 };
	double3 b = (double3) { 0.000000, -1.000000, 0.000000 };

	TEMPER_EXPECT_TRUE( doubleeq( double3_dot( &a, &b ), -1.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestCross_Scalar_double3, void )
{
	double3 left    = (double3) { -1.000000, 0.000000, 0.000000 };
	double3 forward = (double3) { 0.000000, 0.000000, 1.000000 };
	double3 up      = (double3) { 0.000000, 1.000000, 0.000000 };

	double3 vecCross = double3_cross( &left, &forward );
	TEMPER_EXPECT_TRUE( double3_cmpe( &vecCross, &up ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestAngle_Scalar_double3, void )
{
	double3 right = (double3) { 1.000000, 0.000000, 0.000000 };
	double3 up    = (double3) { 0.000000, 1.000000, 0.000000 };

double angleDeg = double3_angle( &up, &right );
	TEMPER_EXPECT_TRUE( doubleeq( angleDeg, 90.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDistance_Scalar_double3, void )
{
	double answerDistanceSqr = 105.0;
	double answerDistance    = 10.246951;

	double3 a = (double3) { 7.000000, 4.000000, 3.000000 };
	double3 b = (double3) { 17.000000, 6.000000, 2.000000 };

	double distSqr = double3_distancesqr( &a, &b );
	double dist    = double3_distance( &a, &b );

	TEMPER_EXPECT_TRUE( doubleeq( distSqr, answerDistanceSqr ) );
	TEMPER_EXPECT_TRUE( doubleeq( dist, answerDistance ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestSaturate_double3, void )
{
	double3 answer = (double3) { 0.000000, 1.000000, 1.000000 };

	double3 vec = (double3) { -1.000000, 2.000000, 4.000000 };
	double3 clamped = double3_saturate( &vec );

	TEMPER_EXPECT_TRUE( double3_cmpe( &clamped, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLerp_double3, void )
{
	double3 answer = (double3) { 0.500000, 0.500000, 0.000000 };

	double3 a = (double3) { 0.000000, 1.000000, 0.000000 };
	double3 b = (double3) { 1.000000, 0.000000, 0.000000 };
	double3 lerped = double3_lerp( &a, &b, 0.5 );

	TEMPER_EXPECT_TRUE( double3_cmpe( &lerped, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestStep_double3, void )
{
	double3 answer = (double3) { 1.000000, 1.000000, 0.000000 };

	double3 a = (double3) { 1.000000, 2.000000, 3.000000 };
	double3 b = (double3) { 4.000000, 3.000000, 2.000000 };

	double3 answerStep = double3_step( &a, &b );
	TEMPER_EXPECT_TRUE( double3_cmpe( &answerStep, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestSmoothstep_double3, void )
{
	double3 answerInRangeSmoothstep   = (double3) { 0.104000, 0.104000, 0.104000 };
	double3 answerClampedSmoothstep   = (double3) { 1.000000, 1.000000, 1.000000 };
	double3 answerInRangeSmootherstep = (double3) { 0.057920, 0.057920, 0.057920 };
	double3 answerClampedSmootherstep = (double3) { 1.000000, 1.000000, 1.000000 };
	double3 answer;
	double3 vec;

	double3 low  = (double3) { 0.000000, 0.000000, 0.000000 };
	double3 high = (double3) { 1.000000, 1.000000, 1.000000 };

	vec = (double3) { 0.200000, 0.200000, 0.200000 };
	answer = double3_smoothstep( &low, &high, &vec );
	TEMPER_EXPECT_TRUE( double3_cmpe( &answer, &answerInRangeSmoothstep ) );

	vec = (double3) { 1.200000, 1.200000, 1.200000 };
	answer = double3_smoothstep( &low, &high, &vec );
	TEMPER_EXPECT_TRUE( double3_cmpe( &answer, &answerClampedSmoothstep ) );

	vec = (double3) { 0.200000, 0.200000, 0.200000 };
	answer = double3_smootherstep( &low, &high, &vec );
	TEMPER_EXPECT_TRUE( double3_cmpe( &answer, &answerInRangeSmootherstep ) );

	vec = (double3) { 1.200000, 1.200000, 1.200000 };
	answer = double3_smootherstep( &low, &high, &vec );
	TEMPER_EXPECT_TRUE( double3_cmpe( &answer, &answerClampedSmootherstep ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_double3 )
{
	TEMPER_RUN_TEST( TestAssignment_double3 );
	TEMPER_RUN_TEST( TestArithmeticAddition_double3 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_double3 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_double3 );
	TEMPER_RUN_TEST( TestArithmeticDivision_double3 );
	TEMPER_RUN_TEST( TestRelational_double3 );
	TEMPER_RUN_TEST( TestLength_Scalar_double3 );
	TEMPER_RUN_TEST( TestNormalized_Scalar_double3 );
	TEMPER_RUN_TEST( TestDot_Scalar_double3 );
	TEMPER_RUN_TEST( TestCross_Scalar_double3 );
	TEMPER_RUN_TEST( TestAngle_Scalar_double3 );
	TEMPER_RUN_TEST( TestDistance_Scalar_double3 );
	TEMPER_RUN_TEST( TestSaturate_double3 );
	TEMPER_RUN_TEST( TestLerp_double3 );
	TEMPER_RUN_TEST( TestStep_double3 );
	TEMPER_RUN_TEST( TestSmoothstep_double3 );
}
