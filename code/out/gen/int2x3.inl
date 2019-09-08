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

// others
#include <math.h>

// forward declares
int2x3 inverse( const int2x3& mat );

int2x3::int2x3()
{
	rows[0] = { 1, 0, 0 };
	rows[1] = { 0, 1, 0 };
}

int2x3::int2x3( const int32_t diagonal )
{
	rows[0] = { diagonal, 0, 0 };
	rows[1] = { 0, diagonal, 0 };
}

int2x3::int2x3( const int3& diagonal )
{
	rows[0] = { diagonal.x, 0, 0 };
	rows[1] = { 0, diagonal.y, 0 };
}

int2x3::int2x3( const int3& row0, const int3& row1 )
{
	rows[0] = row0;
	rows[1] = row1;
}

int2x3::int2x3( const int3 rows[2] )
{
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
}

int2x3::int2x3( const int32_t m00, const int32_t m01, const int32_t m02, const int32_t m10, const int32_t m11, const int32_t m12 )
{
	rows[0] = { m00, m01, m02 };
	rows[1] = { m10, m11, m12 };
}

int2x3::int2x3( const int2x3& other )
{
	memcpy( rows, other.rows, sizeof( rows ) );
}

int2x3 int2x3::operator=( const int2x3& other )
{
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
}

int3& int2x3::operator[]( const uint32_t index )
{
	assert( index < 2 );
	return rows[index];
}

const int3& int2x3::operator[]( const uint32_t index ) const
{
	assert( index < 2 );
	return rows[index];
}

bool operator==( const int2x3& lhs, const int2x3& rhs )
{
	return lhs[0] == rhs[0]
		&& lhs[1] == rhs[1];
}

bool operator!=( const int2x3& lhs, const int2x3& rhs )
{
	return !( operator==( lhs, rhs ) );
}

