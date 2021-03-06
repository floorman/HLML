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
#include "bool2x4.h"

// others
#include <math.h>
#include <memory.h>
#include <assert.h>

bool2x4::bool2x4( const bool32_t diagonal )
{
	rows[0] = { diagonal, 0, 0, 0 };
	rows[1] = { 0, diagonal, 0, 0 };
}

bool2x4::bool2x4( const bool4& diagonal )
{
	rows[0] = { diagonal.x, 0, 0, 0 };
	rows[1] = { 0, diagonal.y, 0, 0 };
}

bool2x4::bool2x4( const bool4& row0, const bool4& row1 )
{
	rows[0] = row0;
	rows[1] = row1;
}

bool2x4::bool2x4( const bool4 rows[2] )
{
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
}

bool2x4::bool2x4( const bool32_t m00, const bool32_t m01, const bool32_t m02, const bool32_t m03, const bool32_t m10, const bool32_t m11, const bool32_t m12, const bool32_t m13 )
{
	rows[0] = { m00, m01, m02, m03 };
	rows[1] = { m10, m11, m12, m13 };
}

bool2x4::bool2x4( const bool2x4& other )
{
	memcpy( rows, other.rows, sizeof( rows ) );
}

bool2x4 bool2x4::operator=( const bool2x4& other )
{
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
}

bool4& bool2x4::operator[]( const uint32_t index )
{
	assert( index < 2 );
	return rows[index];
}

const bool4& bool2x4::operator[]( const uint32_t index ) const
{
	assert( index < 2 );
	return rows[index];
}

