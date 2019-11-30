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

#include <temper/temper.h>

TEMPER_TEST( TestArithmeticMultiplyScalar_float4 )
{
	const float4 a = HLML_CONSTRUCT( float4 ) { ( 2.0f ), ( 3.0f ), ( 4.0f ), ( 5.0f ) };
	const float b = 6.0f;

	float4 c = float4_quaternion_mul( &a, b );

	TEMPER_EXPECT_TRUE( floateq( c.x, ( 12.0f ) ) );
	TEMPER_EXPECT_TRUE( floateq( c.y, ( 18.0f ) ) );
	TEMPER_EXPECT_TRUE( floateq( c.z, ( 24.0f ) ) );
	TEMPER_EXPECT_TRUE( floateq( c.w, ( 30.0f ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiply_float4 )
{
	const float4 a = HLML_CONSTRUCT( float4 ) { ( 2.0f ), ( 3.0f ), ( 4.0f ), ( 5.0f ) };
	const float4 b = HLML_CONSTRUCT( float4 ) { ( 1.0f ), ( 3.0f ), ( 5.0f ), ( 7.0f ) };

	float4 c = float4_quaternion_mulq( &a, &b );

	TEMPER_EXPECT_TRUE( c.x == ( 22.0f ) );
	TEMPER_EXPECT_TRUE( c.y == ( 30.0f ) );
	TEMPER_EXPECT_TRUE( c.z == ( 56.0f ) );
	TEMPER_EXPECT_TRUE( c.w == ( 4.0f ) );
	TEMPER_EXPECT_TRUE( floateq( c.x, ( 22.0f ) ) );
	TEMPER_EXPECT_TRUE( floateq( c.y, ( 30.0f ) ) );
	TEMPER_EXPECT_TRUE( floateq( c.z, ( 56.0f ) ) );
	TEMPER_EXPECT_TRUE( floateq( c.w, ( 4.0f ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticLength_float4 )
{
	const float4 a = HLML_CONSTRUCT( float4 ) { ( 2.0f ), ( 3.0f ), ( 4.0f ), ( 5.0f ) };

	float b = float4_quaternion_length( &a );

	TEMPER_EXPECT_TRUE( floateq( b, ( 7.34846925735f ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticNormalize_float4 )
{
	const float4 a = HLML_CONSTRUCT( float4 ) { ( 2.0f ), ( 3.0f ), ( 4.0f ), ( 5.0f ) };

	float4 b = float4_quaternion_normalize( &a );

	TEMPER_EXPECT_TRUE( floateq( b.x, ( 0.272166f ) ) );
	TEMPER_EXPECT_TRUE( floateq( b.y, ( 0.408248f ) ) );
	TEMPER_EXPECT_TRUE( floateq( b.z, ( 0.544331f ) ) );
	TEMPER_EXPECT_TRUE( floateq( b.w, ( 0.680414f ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticConjugate_float4 )
{
	const float4 a = HLML_CONSTRUCT( float4 ) { ( 2.0f ), ( 3.0f ), ( 4.0f ), ( 5.0f ) };

	float4 b = float4_quaternion_conjugate( &a );

	TEMPER_EXPECT_TRUE( floateq( b.x, ( -2.000000f ) ) );
	TEMPER_EXPECT_TRUE( floateq( b.y, ( -3.000000f ) ) );
	TEMPER_EXPECT_TRUE( floateq( b.z, ( -4.000000f ) ) );
	TEMPER_EXPECT_TRUE( floateq( b.w, ( 5.000000f ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticInverse_float4 )
{
	const float4 a = HLML_CONSTRUCT( float4 ) { ( 2.0f ), ( 3.0f ), ( 4.0f ), ( 5.0f ) };

	float4 b = float4_quaternion_inverse( &a );

	TEMPER_EXPECT_TRUE( floateq( b.x, ( -0.037037f ) ) );
	TEMPER_EXPECT_TRUE( floateq( b.y, ( -0.0555556f ) ) );
	TEMPER_EXPECT_TRUE( floateq( b.z, ( -0.0740741f ) ) );
	TEMPER_EXPECT_TRUE( floateq( b.w, ( 0.092593f ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticVectorRotationByAngleAxis_float4 )
{
	const float3 vector = HLML_CONSTRUCT( float3 ) { 0.0f, 1.0f, 0.0f };
	const float3 axis = HLML_CONSTRUCT( float3 ) { 1.0f, 0.0f, 0.0f };
	const float angle = 1.570800f;

	float3 rotated_vector = float4_quaternion_rotate_vector_about_angle_axis( &vector, angle, &axis );

	TEMPER_EXPECT_TRUE( floateq( rotated_vector.x, ( 0.0f ) ) );
	TEMPER_EXPECT_TRUE( floateq( rotated_vector.y, ( 0.0f ) ) );
	TEMPER_EXPECT_TRUE( floateq( rotated_vector.z, ( 1.0f ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticLerp_float4 )
{
	const float4 a = HLML_CONSTRUCT( float4 ) { ( 0.0f ), ( 0.0f ), ( 0.0f ), ( 0.0f ) };
	const float4 b = HLML_CONSTRUCT( float4 ) { ( 1.0f ), ( 1.0f ), ( 1.0f ), ( 1.0f ) };

	float4 c = float4_quaternion_lerp( &a, &b, 0.5f );

	TEMPER_EXPECT_TRUE( floateq( c.x, ( 0.5f ) ) );
	TEMPER_EXPECT_TRUE( floateq( c.y, ( 0.5f ) ) );
	TEMPER_EXPECT_TRUE( floateq( c.z, ( 0.5f ) ) );
	TEMPER_EXPECT_TRUE( floateq( c.w, ( 0.5f ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSlerp_float4 )
{
	const float4 a = HLML_CONSTRUCT( float4 ) { ( 0.0f ), ( 0.0f ), ( 0.0f ), ( 0.0f ) };
	const float4 b = HLML_CONSTRUCT( float4 ) { ( 1.0f ), ( 1.0f ), ( 1.0f ), ( 1.0f ) };

	float4 c = float4_quaternion_slerp( &a, &b, 0.5f );

	TEMPER_EXPECT_TRUE( floateq( c.x, ( 0.707106769f ) ) );
	TEMPER_EXPECT_TRUE( floateq( c.y, ( 0.707106769f ) ) );
	TEMPER_EXPECT_TRUE( floateq( c.z, ( 0.707106769f ) ) );
	TEMPER_EXPECT_TRUE( floateq( c.w, ( 0.707106769f ) ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_quaternion_float4 )
{
	TEMPER_RUN_TEST( TestArithmeticMultiplyScalar_float4 );
	TEMPER_RUN_TEST( TestArithmeticMultiply_float4 );
	TEMPER_RUN_TEST( TestArithmeticLength_float4 );
	TEMPER_RUN_TEST( TestArithmeticNormalize_float4 );
	TEMPER_RUN_TEST( TestArithmeticConjugate_float4 );
	TEMPER_RUN_TEST( TestArithmeticInverse_float4 );
	TEMPER_RUN_TEST( TestArithmeticVectorRotationByAngleAxis_float4 );
	TEMPER_RUN_TEST( TestArithmeticLerp_float4 );
	TEMPER_RUN_TEST( TestArithmeticSlerp_float4 );
}
