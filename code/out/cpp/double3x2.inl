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
#include "double3x2.h"

// others
#include <math.h>
#include <memory.h>
#include <assert.h>

// forward declares
double3x2 inverse( const double3x2& mat );

double3x2::double3x2( const double diagonal )
{
	rows[0] = { diagonal, 0 };
	rows[1] = { 0, diagonal };
	rows[2] = { 0, 0 };
}

double3x2::double3x2( const double2& diagonal )
{
	rows[0] = { diagonal.x, 0 };
	rows[1] = { 0, diagonal.y };
	rows[2] = { 0, 0 };
}

double3x2::double3x2( const double2& row0, const double2& row1, const double2& row2 )
{
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
}

double3x2::double3x2( const double2 rows[3] )
{
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
	this->rows[2] = rows[2];
}

double3x2::double3x2( const double m00, const double m01, const double m10, const double m11, const double m20, const double m21 )
{
	rows[0] = { m00, m01 };
	rows[1] = { m10, m11 };
	rows[2] = { m20, m21 };
}

double3x2::double3x2( const double3x2& other )
{
	memcpy( rows, other.rows, sizeof( rows ) );
}

double3x2 double3x2::operator=( const double3x2& other )
{
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
}

double2& double3x2::operator[]( const uint32_t index )
{
	assert( index < 3 );
	return rows[index];
}

const double2& double3x2::operator[]( const uint32_t index ) const
{
	assert( index < 3 );
	return rows[index];
}

