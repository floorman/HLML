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

#include "bool2x2.h"
#include "bool2x3.h"
#include "bool2x4.h"
#include "bool3x2.h"
#include "bool3x3.h"
#include "bool3x4.h"
#include "bool4x2.h"
#include "bool4x3.h"
#include "bool4x4.h"

#include "int2x2.h"
#include "int2x3.h"
#include "int2x4.h"
#include "int3x2.h"
#include "int3x3.h"
#include "int3x4.h"
#include "int4x2.h"
#include "int4x3.h"
#include "int4x4.h"

#include "uint2x2.h"
#include "uint2x3.h"
#include "uint2x4.h"
#include "uint3x2.h"
#include "uint3x3.h"
#include "uint3x4.h"
#include "uint4x2.h"
#include "uint4x3.h"
#include "uint4x4.h"

#include "float2x2.h"
#include "float2x3.h"
#include "float2x4.h"
#include "float3x2.h"
#include "float3x3.h"
#include "float3x4.h"
#include "float4x2.h"
#include "float4x3.h"
#include "float4x4.h"

#include "double2x2.h"
#include "double2x3.h"
#include "double2x4.h"
#include "double3x2.h"
#include "double3x3.h"
#include "double3x4.h"
#include "double4x2.h"
#include "double4x3.h"
#include "double4x4.h"

#include "hlml_functions_vector.h"

// float4
inline float4 float4_quaternion_mulq( const float4* lhs, const float4* rhs );

inline float4 float4_quaternion_mul( const float4* lhs, const float rhs );

inline float float4_quaternion_length( const float4* quat );

inline float4 float4_quaternion_normalize( const float4* quat );

inline float4 float4_quaternion_conjugate( const float4* quat );

inline float4 float4_quaternion_inverse( const float4* quat );

inline float3 float4_quaternion_rotate( const float3* vect, const float angle, const float3* axis );

inline float4 float4_quaternion_lerp( const float4* lhs, const float4* rhs, const float percent );

inline float4 float4_quaternion_slerp( const float4* lhs, const float4* rhs, const float percent );


// double4
inline double4 double4_quaternion_mulq( const double4* lhs, const double4* rhs );

inline double4 double4_quaternion_mul( const double4* lhs, const double rhs );

inline double double4_quaternion_length( const double4* quat );

inline double4 double4_quaternion_normalize( const double4* quat );

inline double4 double4_quaternion_conjugate( const double4* quat );

inline double4 double4_quaternion_inverse( const double4* quat );

inline double3 double4_quaternion_rotate( const double3* vect, const double angle, const double3* axis );

inline double4 double4_quaternion_lerp( const double4* lhs, const double4* rhs, const double percent );

inline double4 double4_quaternion_slerp( const double4* lhs, const double4* rhs, const double percent );



#pragma once

// ignore missing brace initializers
#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-braces"
#endif

inline float4 float4_quaternion_mulq( const float4* lhs, const float4* rhs )
{
	float4 quat;
	quat.x = lhs->x * rhs->w + lhs->y * rhs->z - lhs->z * rhs->y + lhs->w * rhs->x;
	quat.y = -lhs->x * rhs->z + lhs->y * rhs->w + lhs->z * rhs->x + lhs->w * rhs->y;
	quat.z = lhs->x * rhs->y - lhs->y * rhs->x + lhs->z * rhs->w + lhs->w * rhs->z;
	quat.w = -lhs->x * rhs->x - lhs->y * rhs->y - lhs->z * rhs->z + lhs->w * rhs->w;
	return quat;
}

inline float4 float4_quaternion_mul( const float4* lhs, const float rhs )
{
	float scalar = lhs->w * rhs;
	float3 imaginary = (float3) { lhs->x, lhs->y, lhs->z };
	imaginary = float3_comp_muls( &imaginary, rhs );
	return HLML_CONSTRUCT( float4 ) { imaginary.x, imaginary.y, imaginary.z, scalar };
}

inline float float4_quaternion_length( const float4* quat )
{
	return sqrtf( ( quat->x * quat->x ) + ( quat->y * quat->y ) + ( quat->z * quat->z ) + ( quat->w * quat->w ) );
}

inline float4 float4_quaternion_normalize( const float4* quat )
{
	float3 normV = HLML_CONSTRUCT( float3 ) { quat->x, quat->y, quat->z };
	float normS = quat->w;
	float mag = float4_quaternion_length( quat );
	if ( mag >= 0 )
	{
		float magInverse = 1.0f / mag;
		normV = float3_comp_muls( &normV, magInverse );
		normS *= magInverse;
	}
	return HLML_CONSTRUCT( float4 ) { normV.x, normV.y, normV.z, normS };
}

inline float4 float4_quaternion_conjugate( const float4* quat )
{
	return HLML_CONSTRUCT (float4) { ( quat->x * ( -1 ) ), ( quat->y * ( -1 ) ), ( quat->z * ( -1 ) ), quat->w };
}

inline float4 float4_quaternion_inverse( const float4* quat )
{
	float magnitude = float4_quaternion_length( quat );
	magnitude *= magnitude;
	magnitude = 1 / magnitude;
	float4 conjugate = float4_quaternion_conjugate( quat );
	float scalar = conjugate.w * magnitude;
	float3 imaginary = HLML_CONSTRUCT( float3 ) { conjugate.x * magnitude, conjugate.y * magnitude, conjugate.z * magnitude };
	return HLML_CONSTRUCT (float4) { imaginary.x, imaginary.y, imaginary.z, scalar };
}

inline float3 float4_quaternion_rotate( const float3* vect, const float angle, const float3* axis )
{
	float4 pureQuat = HLML_CONSTRUCT( float4 ) { vect->x, vect->y, vect->z, 0 };
	float3 normalizedAxis = *axis;
	float3_normalize( &normalizedAxis );
	float4 realQuat = HLML_CONSTRUCT( float4 ) { normalizedAxis.x, normalizedAxis.y, normalizedAxis.z, angle };

	float3 imaginary = HLML_CONSTRUCT( float3 ) { realQuat.x, realQuat.y, realQuat.z };
	float3 normalizedImaginary = imaginary;
	float3_normalize( &normalizedImaginary );
	float unitNormScalar = cosf( realQuat.w * 0.5f );
	float sinResult = sinf( realQuat.w * 0.5f );
	float3 unitNormImaginary = float3_comp_muls( &normalizedImaginary, sinResult );
	float4 unitNormQuat = HLML_CONSTRUCT( float4 ) { unitNormImaginary.x, unitNormImaginary.y, unitNormImaginary.z, unitNormScalar };

	float4 inverseQuat = float4_quaternion_inverse( &unitNormQuat );
	float4 rotatedVector = float4_quaternion_mulq( &unitNormQuat, &pureQuat );
	rotatedVector = float4_quaternion_mulq( &rotatedVector, &inverseQuat );
	return HLML_CONSTRUCT( float3 ) { rotatedVector.x, rotatedVector.y, rotatedVector.z };
}

inline float4 float4_quaternion_lerp( const float4* lhs, const float4* rhs, const float percent )
{
	float4 quat;
	float t = 1 - percent;
	quat.x = t * lhs->x + percent * rhs->x;
	quat.y = t * lhs->y + percent * rhs->y;
	quat.z = t * lhs->z + percent * rhs->z;
	quat.w = t * lhs->w + percent * rhs->w;
	return quat;
}

inline float4 float4_quaternion_slerp( const float4* lhs, const float4* rhs, const float percent )
{
	float4 quat;
	float t = 1 - percent;
	float cosTheta = ( lhs->x * rhs->x ) + ( lhs->y * rhs->y ) + ( lhs->z * rhs->z ) + ( lhs->w * rhs->w );
	float theta = acosf( cosTheta );
	float sn = sqrtf( 1 - cosTheta * cosTheta );
	float Wa = sinf( t * theta ) / sn;
	float Wb = sinf( percent * theta ) / sn;
	quat.x = Wa * rhs->x + Wb * lhs->x;
	quat.y = Wa * rhs->y + Wb * lhs->y;
	quat.z = Wa * rhs->z + Wb * lhs->z;
	quat.w = Wa * rhs->w + Wb * lhs->w;
	return quat;
}

inline double4 double4_quaternion_mulq( const double4* lhs, const double4* rhs )
{
	double4 quat;
	quat.x = lhs->x * rhs->w + lhs->y * rhs->z - lhs->z * rhs->y + lhs->w * rhs->x;
	quat.y = -lhs->x * rhs->z + lhs->y * rhs->w + lhs->z * rhs->x + lhs->w * rhs->y;
	quat.z = lhs->x * rhs->y - lhs->y * rhs->x + lhs->z * rhs->w + lhs->w * rhs->z;
	quat.w = -lhs->x * rhs->x - lhs->y * rhs->y - lhs->z * rhs->z + lhs->w * rhs->w;
	return quat;
}

inline double4 double4_quaternion_mul( const double4* lhs, const double rhs )
{
	double scalar = lhs->w * rhs;
	double3 imaginary = (double3) { lhs->x, lhs->y, lhs->z };
	imaginary = double3_comp_muls( &imaginary, rhs );
	return HLML_CONSTRUCT( double4 ) { imaginary.x, imaginary.y, imaginary.z, scalar };
}

inline double double4_quaternion_length( const double4* quat )
{
	return sqrt( ( quat->x * quat->x ) + ( quat->y * quat->y ) + ( quat->z * quat->z ) + ( quat->w * quat->w ) );
}

inline double4 double4_quaternion_normalize( const double4* quat )
{
	double3 normV = HLML_CONSTRUCT( double3 ) { quat->x, quat->y, quat->z };
	double normS = quat->w;
	double mag = double4_quaternion_length( quat );
	if ( mag >= 0 )
	{
		double magInverse = 1.0 / mag;
		normV = double3_comp_muls( &normV, magInverse );
		normS *= magInverse;
	}
	return HLML_CONSTRUCT( double4 ) { normV.x, normV.y, normV.z, normS };
}

inline double4 double4_quaternion_conjugate( const double4* quat )
{
	return HLML_CONSTRUCT (double4) { ( quat->x * ( -1 ) ), ( quat->y * ( -1 ) ), ( quat->z * ( -1 ) ), quat->w };
}

inline double4 double4_quaternion_inverse( const double4* quat )
{
	double magnitude = double4_quaternion_length( quat );
	magnitude *= magnitude;
	magnitude = 1 / magnitude;
	double4 conjugate = double4_quaternion_conjugate( quat );
	double scalar = conjugate.w * magnitude;
	double3 imaginary = HLML_CONSTRUCT( double3 ) { conjugate.x * magnitude, conjugate.y * magnitude, conjugate.z * magnitude };
	return HLML_CONSTRUCT (double4) { imaginary.x, imaginary.y, imaginary.z, scalar };
}

inline double3 double4_quaternion_rotate( const double3* vect, const double angle, const double3* axis )
{
	double4 pureQuat = HLML_CONSTRUCT( double4 ) { vect->x, vect->y, vect->z, 0 };
	double3 normalizedAxis = *axis;
	double3_normalize( &normalizedAxis );
	double4 realQuat = HLML_CONSTRUCT( double4 ) { normalizedAxis.x, normalizedAxis.y, normalizedAxis.z, angle };

	double3 imaginary = HLML_CONSTRUCT( double3 ) { realQuat.x, realQuat.y, realQuat.z };
	double3 normalizedImaginary = imaginary;
	double3_normalize( &normalizedImaginary );
	double unitNormScalar = cos( realQuat.w * 0.5 );
	double sinResult = sin( realQuat.w * 0.5 );
	double3 unitNormImaginary = double3_comp_muls( &normalizedImaginary, sinResult );
	double4 unitNormQuat = HLML_CONSTRUCT( double4 ) { unitNormImaginary.x, unitNormImaginary.y, unitNormImaginary.z, unitNormScalar };

	double4 inverseQuat = double4_quaternion_inverse( &unitNormQuat );
	double4 rotatedVector = double4_quaternion_mulq( &unitNormQuat, &pureQuat );
	rotatedVector = double4_quaternion_mulq( &rotatedVector, &inverseQuat );
	return HLML_CONSTRUCT( double3 ) { rotatedVector.x, rotatedVector.y, rotatedVector.z };
}

inline double4 double4_quaternion_lerp( const double4* lhs, const double4* rhs, const double percent )
{
	double4 quat;
	double t = 1 - percent;
	quat.x = t * lhs->x + percent * rhs->x;
	quat.y = t * lhs->y + percent * rhs->y;
	quat.z = t * lhs->z + percent * rhs->z;
	quat.w = t * lhs->w + percent * rhs->w;
	return quat;
}

inline double4 double4_quaternion_slerp( const double4* lhs, const double4* rhs, const double percent )
{
	double4 quat;
	double t = 1 - percent;
	double cosTheta = ( lhs->x * rhs->x ) + ( lhs->y * rhs->y ) + ( lhs->z * rhs->z ) + ( lhs->w * rhs->w );
	double theta = acos( cosTheta );
	double sn = sqrt( 1 - cosTheta * cosTheta );
	double Wa = sin( t * theta ) / sn;
	double Wb = sin( percent * theta ) / sn;
	quat.x = Wa * rhs->x + Wb * lhs->x;
	quat.y = Wa * rhs->y + Wb * lhs->y;
	quat.z = Wa * rhs->z + Wb * lhs->z;
	quat.w = Wa * rhs->w + Wb * lhs->w;
	return quat;
}

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif
