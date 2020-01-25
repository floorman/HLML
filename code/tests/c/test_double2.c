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

TEMPER_TEST( TestAssignment_double2, void )
{
	double2 vec;

	vec.x = 1.0;
	vec.y = 1.0;
	TEMPER_EXPECT_TRUE( vec.x == 1.0 );
	TEMPER_EXPECT_TRUE( vec.y == 1.0 );

	vec.x = 0.0;
	vec.y = 1.0;
	TEMPER_EXPECT_TRUE( vec.x == 0.0 );
	TEMPER_EXPECT_TRUE( vec.y == 1.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_double2, void )
{
	double2 a = (double2)	{ 6.000000, 6.000000 };
	double2 b = (double2)	{ 2.000000, 3.000000 };
	double2 c = double2_comp_addv( &a, &b );

	TEMPER_EXPECT_TRUE( c.x == 8.0 );
	TEMPER_EXPECT_TRUE( c.y == 9.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_double2, void )
{
	double2 a = (double2)	{ 6.000000, 6.000000 };
	double2 b = (double2)	{ 2.000000, 3.000000 };
	double2 c = double2_comp_subv( &a, &b );

	TEMPER_EXPECT_TRUE( c.x == 4.0 );
	TEMPER_EXPECT_TRUE( c.y == 3.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_double2, void )
{
	double2 a = (double2)	{ 6.000000, 6.000000 };
	double2 b = (double2)	{ 2.000000, 3.000000 };
	double2 c = double2_comp_mulv( &a, &b );

	TEMPER_EXPECT_TRUE( c.x == 12.0 );
	TEMPER_EXPECT_TRUE( c.y == 18.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_double2, void )
{
	double2 a = (double2)	{ 6.000000, 6.000000 };
	double2 b = (double2)	{ 2.000000, 2.000000 };
	double2 c = double2_comp_divv( &a, &b );

	TEMPER_EXPECT_TRUE( c.x == 3.0 );
	TEMPER_EXPECT_TRUE( c.y == 3.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double2, void )
{
	bool2 allTrue = (bool2)	{ true, true };

	double2 vec0 = (double2)	{ 0.000000, 0.000000 };
	double2 vec1 = (double2)	{ 1.000000, 1.000000 };
	double2 vec2 = (double2)	{ 2.000000, 2.000000 };
	double2 vec3 = (double2)	{ 3.000000, 3.000000 };

	bool2 test0  = double2_cmple( &vec0, &vec0 );
	bool2 test1  = double2_cmpge( &vec0, &vec0 );
	bool2 test2  = double2_cmpl( &vec0, &vec1 );
	bool2 test3  = double2_cmpl( &vec0, &vec2 );
	bool2 test4  = double2_cmpl( &vec0, &vec3 );

	bool2 test5  = double2_cmpg( &vec1, &vec0 );
	bool2 test6  = double2_cmple( &vec1, &vec1 );
	bool2 test7  = double2_cmpge( &vec1, &vec1 );
	bool2 test8  = double2_cmpl( &vec1, &vec2 );
	bool2 test9  = double2_cmpl( &vec1, &vec3 );

	bool2 test10 = double2_cmpg( &vec2, &vec0 );
	bool2 test11 = double2_cmpg( &vec2, &vec1 );
	bool2 test12 = double2_cmple( &vec2, &vec2 );
	bool2 test13 = double2_cmpge( &vec2, &vec2 );
	bool2 test14 = double2_cmpl( &vec2, &vec3 );

	bool2 test15 = double2_cmpg( &vec3, &vec0 );
	bool2 test16 = double2_cmpg( &vec3, &vec1 );
	bool2 test17 = double2_cmpg( &vec3, &vec2 );
	bool2 test18 = double2_cmple( &vec3, &vec3 );
	bool2 test19 = double2_cmpge( &vec3, &vec3 );

	TEMPER_EXPECT_TRUE( bool2_cmpe( &test0,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test1,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test2,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test3,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test4,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool2_cmpe( &test5,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test6,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test7,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test8,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test9,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool2_cmpe( &test10, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test11, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test12, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test13, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test14, &allTrue ) );

	TEMPER_EXPECT_TRUE( bool2_cmpe( &test15, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test16, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test17, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test18, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2_cmpe( &test19, &allTrue ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLength_Scalar_double2, void )
{
	double2 vec = (double2) { 2.0, 2.0 };

	TEMPER_EXPECT_TRUE( doubleeq( double2_lengthsqr( &vec ), 8.0 ) );
	TEMPER_EXPECT_TRUE( doubleeq( double2_length( &vec ), 2.82842712475 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestNormalized_Scalar_double2, void )
{
	double2 vec = (double2) { 5.000000, 4.000000 };
	vec = double2_normalized( &vec );

	double veclen = double2_length( &vec );
	TEMPER_EXPECT_TRUE( doubleeq( veclen, 1.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDot_Scalar_double2, void )
{
	double2 a = (double2) { 0.000000, 1.000000 };
	double2 b = (double2) { 0.000000, -1.000000 };

	TEMPER_EXPECT_TRUE( doubleeq( double2_dot( &a, &b ), -1.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestAngle_Scalar_double2, void )
{
	double2 right = (double2) { 1.000000, 0.000000 };
	double2 up    = (double2) { 0.000000, 1.000000 };

double angleDeg = double2_angle( &up, &right );
	TEMPER_EXPECT_TRUE( doubleeq( angleDeg, 90.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDistance_Scalar_double2, void )
{
	double answerDistanceSqr = 104.0;
	double answerDistance    = 10.198039;

	double2 a = (double2) { 7.000000, 4.000000 };
	double2 b = (double2) { 17.000000, 6.000000 };

	double distSqr = double2_distancesqr( &a, &b );
	double dist    = double2_distance( &a, &b );

	TEMPER_EXPECT_TRUE( doubleeq( distSqr, answerDistanceSqr ) );
	TEMPER_EXPECT_TRUE( doubleeq( dist, answerDistance ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestSaturate_double2, void )
{
	double2 answer = (double2) { 0.000000, 1.000000 };

	double2 vec = (double2) { -1.000000, 2.000000 };
	double2 clamped = double2_saturate( &vec );

	TEMPER_EXPECT_TRUE( double2_cmpe( &clamped, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLerp_double2, void )
{
	double2 answer = (double2) { 0.500000, 0.500000 };

	double2 a = (double2) { 0.000000, 1.000000 };
	double2 b = (double2) { 1.000000, 0.000000 };
	double2 lerped = double2_lerp( &a, &b, 0.5 );

	TEMPER_EXPECT_TRUE( double2_cmpe( &lerped, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestStep_double2, void )
{
	double2 answer = (double2) { 1.000000, 1.000000 };

	double2 a = (double2) { 1.000000, 2.000000 };
	double2 b = (double2) { 4.000000, 3.000000 };

	double2 answerStep = double2_step( &a, &b );
	TEMPER_EXPECT_TRUE( double2_cmpe( &answerStep, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestSmoothstep_double2, void )
{
	double2 answerInRangeSmoothstep   = (double2) { 0.104000, 0.104000 };
	double2 answerClampedSmoothstep   = (double2) { 1.000000, 1.000000 };
	double2 answerInRangeSmootherstep = (double2) { 0.057920, 0.057920 };
	double2 answerClampedSmootherstep = (double2) { 1.000000, 1.000000 };
	double2 answer;
	double2 vec;

	double2 low  = (double2) { 0.000000, 0.000000 };
	double2 high = (double2) { 1.000000, 1.000000 };

	vec = (double2) { 0.200000, 0.200000 };
	answer = double2_smoothstep( &low, &high, &vec );
	TEMPER_EXPECT_TRUE( double2_cmpe( &answer, &answerInRangeSmoothstep ) );

	vec = (double2) { 1.200000, 1.200000 };
	answer = double2_smoothstep( &low, &high, &vec );
	TEMPER_EXPECT_TRUE( double2_cmpe( &answer, &answerClampedSmoothstep ) );

	vec = (double2) { 0.200000, 0.200000 };
	answer = double2_smootherstep( &low, &high, &vec );
	TEMPER_EXPECT_TRUE( double2_cmpe( &answer, &answerInRangeSmootherstep ) );

	vec = (double2) { 1.200000, 1.200000 };
	answer = double2_smootherstep( &low, &high, &vec );
	TEMPER_EXPECT_TRUE( double2_cmpe( &answer, &answerClampedSmootherstep ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_double2 )
{
	TEMPER_RUN_TEST( TestAssignment_double2 );
	TEMPER_RUN_TEST( TestArithmeticAddition_double2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_double2 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_double2 );
	TEMPER_RUN_TEST( TestArithmeticDivision_double2 );
	TEMPER_RUN_TEST( TestRelational_double2 );
	TEMPER_RUN_TEST( TestLength_Scalar_double2 );
	TEMPER_RUN_TEST( TestNormalized_Scalar_double2 );
	TEMPER_RUN_TEST( TestDot_Scalar_double2 );
	TEMPER_RUN_TEST( TestAngle_Scalar_double2 );
	TEMPER_RUN_TEST( TestDistance_Scalar_double2 );
	TEMPER_RUN_TEST( TestSaturate_double2 );
	TEMPER_RUN_TEST( TestLerp_double2 );
	TEMPER_RUN_TEST( TestStep_double2 );
	TEMPER_RUN_TEST( TestSmoothstep_double2 );
}
