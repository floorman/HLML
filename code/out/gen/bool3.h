/*
===========================================================================

hlml.
Copyright (c) Dan Moody 2019 - Present.

This file is part of hlml.

hlml is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

hlml is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with hlml.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

// GENERATED FILE.  DO NOT EDIT.

#pragma once

#include <stdint.h>

struct bool2;
struct bool4;
struct float3;

/// \brief A vector of 3 bools with components xyz.
/// Components are also stored as elements in an array via a union.
struct bool3
{
	union
	{
		struct
		{
			bool x;
			bool y;
			bool z;
		};

		bool data[3] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline bool3();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit bool3( const bool x );

	/// Sets the xyz members of the vector to the corresponding parameters.
	inline bool3( const bool x, const bool y, const bool z );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline bool3( const bool2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline bool3( const bool3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline bool3( const bool4& other );

	~bool3() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline bool3 operator=( const bool2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline bool3 operator=( const bool3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline bool3 operator=( const bool4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline const bool& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline bool& operator[]( const uint32_t index );

	// swizzle funcs
	inline bool2 xx() const { return bool2( x, x ); }
	inline bool2 yx() const { return bool2( y, x ); }
	inline bool2 xy() const { return bool2( x, y ); }
	inline bool2 yy() const { return bool2( y, y ); }

	inline bool3 xxx() const { return bool3( x, x, x ); }
	inline bool3 yxx() const { return bool3( y, x, x ); }
	inline bool3 zxx() const { return bool3( z, x, x ); }
	inline bool3 xyx() const { return bool3( x, y, x ); }
	inline bool3 yyx() const { return bool3( y, y, x ); }
	inline bool3 zyx() const { return bool3( z, y, x ); }
	inline bool3 xzx() const { return bool3( x, z, x ); }
	inline bool3 yzx() const { return bool3( y, z, x ); }
	inline bool3 zzx() const { return bool3( z, z, x ); }
	inline bool3 xxy() const { return bool3( x, x, y ); }
	inline bool3 yxy() const { return bool3( y, x, y ); }
	inline bool3 zxy() const { return bool3( z, x, y ); }
	inline bool3 xyy() const { return bool3( x, y, y ); }
	inline bool3 yyy() const { return bool3( y, y, y ); }
	inline bool3 zyy() const { return bool3( z, y, y ); }
	inline bool3 xzy() const { return bool3( x, z, y ); }
	inline bool3 yzy() const { return bool3( y, z, y ); }
	inline bool3 zzy() const { return bool3( z, z, y ); }
	inline bool3 xxz() const { return bool3( x, x, z ); }
	inline bool3 yxz() const { return bool3( y, x, z ); }
	inline bool3 zxz() const { return bool3( z, x, z ); }
	inline bool3 xyz() const { return bool3( x, y, z ); }
	inline bool3 yyz() const { return bool3( y, y, z ); }
	inline bool3 zyz() const { return bool3( z, y, z ); }
	inline bool3 xzz() const { return bool3( x, z, z ); }
	inline bool3 yzz() const { return bool3( y, z, z ); }
	inline bool3 zzz() const { return bool3( z, z, z ); }

};

/// \relates bool3
/// \brief Returns true if the all the components of the left-hand-side bool3 match the other one, otherwise returns false.
inline bool operator==( const bool3& lhs, const bool3& rhs );

/// \relates bool3
/// \brief Returns true if not all of the components of the left-hand-side bool3 match the other one, otherwise returns false.
inline bool operator!=( const bool3& lhs, const bool3& rhs );

#include "bool3.inl"