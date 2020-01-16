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

#pragma once

// hlml includes
#include "float3x4.h"

// others
#include <math.h>
#include <memory.h>
#include <assert.h>

// forward declares
float3x4 inverse( const float3x4& mat );

float3x4::float3x4( const float diagonal )
{
	rows[0] = { diagonal, 0, 0, 0 };
	rows[1] = { 0, diagonal, 0, 0 };
	rows[2] = { 0, 0, diagonal, 0 };
}

float3x4::float3x4( const float4& diagonal )
{
	rows[0] = { diagonal.x, 0, 0, 0 };
	rows[1] = { 0, diagonal.y, 0, 0 };
	rows[2] = { 0, 0, diagonal.z, 0 };
}

float3x4::float3x4( const float4& row0, const float4& row1, const float4& row2 )
{
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
}

float3x4::float3x4( const float4 rows[3] )
{
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
	this->rows[2] = rows[2];
}

float3x4::float3x4( const float m00, const float m01, const float m02, const float m03, const float m10, const float m11, const float m12, const float m13, const float m20, const float m21, const float m22, const float m23 )
{
	rows[0] = { m00, m01, m02, m03 };
	rows[1] = { m10, m11, m12, m13 };
	rows[2] = { m20, m21, m22, m23 };
}

float3x4::float3x4( const float3x4& other )
{
	memcpy( rows, other.rows, sizeof( rows ) );
}

float3x4 float3x4::operator=( const float3x4& other )
{
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
}

float4& float3x4::operator[]( const uint32_t index )
{
	assert( index < 3 );
	return rows[index];
}

const float4& float3x4::operator[]( const uint32_t index ) const
{
	assert( index < 3 );
	return rows[index];
}

