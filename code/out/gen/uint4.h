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

#include "bool4.h"

#include "../hlml_types.h"

#include "uint2.h"
#include "uint3.h"

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#elif defined( _MSC_VER )
#pragma warning( push )
#pragma warning( disable : 4201 ) // C4201 - nonstandard extension used : nameless struct/union
#endif

/// \brief A vector of 4 uint32_ts with components xyzw.
/// Components are also stored as elements in an array via a union.
struct uint4
{
	union
	{
		struct
		{
			uint32_t x;
			uint32_t y;
			uint32_t z;
			uint32_t w;
		};

		struct
		{
			uint32_t r;
			uint32_t g;
			uint32_t b;
			uint32_t a;
		};

		uint32_t data[4] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline uint4();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit uint4( const uint32_t x );

	/// Sets the xyzw members of the vector to the corresponding parameters.
	inline uint4( const uint32_t x, const uint32_t y, const uint32_t z, const uint32_t w );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint4( const uint2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint4( const uint3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint4( const uint4& other );

	~uint4() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline uint4 operator=( const uint2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline uint4 operator=( const uint3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline uint4 operator=( const uint4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline const uint32_t& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline uint32_t& operator[]( const uint32_t index );

	// swizzle funcs
	inline uint2 xx() const;
	inline uint2 yx() const;
	inline uint2 xy() const;
	inline uint2 yy() const;
	inline uint3 xxx() const;
	inline uint3 yxx() const;
	inline uint3 zxx() const;
	inline uint3 xyx() const;
	inline uint3 yyx() const;
	inline uint3 zyx() const;
	inline uint3 xzx() const;
	inline uint3 yzx() const;
	inline uint3 zzx() const;
	inline uint3 xxy() const;
	inline uint3 yxy() const;
	inline uint3 zxy() const;
	inline uint3 xyy() const;
	inline uint3 yyy() const;
	inline uint3 zyy() const;
	inline uint3 xzy() const;
	inline uint3 yzy() const;
	inline uint3 zzy() const;
	inline uint3 xxz() const;
	inline uint3 yxz() const;
	inline uint3 zxz() const;
	inline uint3 xyz() const;
	inline uint3 yyz() const;
	inline uint3 zyz() const;
	inline uint3 xzz() const;
	inline uint3 yzz() const;
	inline uint3 zzz() const;
	inline uint4 xxxx() const;
	inline uint4 yxxx() const;
	inline uint4 zxxx() const;
	inline uint4 wxxx() const;
	inline uint4 xyxx() const;
	inline uint4 yyxx() const;
	inline uint4 zyxx() const;
	inline uint4 wyxx() const;
	inline uint4 xzxx() const;
	inline uint4 yzxx() const;
	inline uint4 zzxx() const;
	inline uint4 wzxx() const;
	inline uint4 xwxx() const;
	inline uint4 ywxx() const;
	inline uint4 zwxx() const;
	inline uint4 wwxx() const;
	inline uint4 xxyx() const;
	inline uint4 yxyx() const;
	inline uint4 zxyx() const;
	inline uint4 wxyx() const;
	inline uint4 xyyx() const;
	inline uint4 yyyx() const;
	inline uint4 zyyx() const;
	inline uint4 wyyx() const;
	inline uint4 xzyx() const;
	inline uint4 yzyx() const;
	inline uint4 zzyx() const;
	inline uint4 wzyx() const;
	inline uint4 xwyx() const;
	inline uint4 ywyx() const;
	inline uint4 zwyx() const;
	inline uint4 wwyx() const;
	inline uint4 xxzx() const;
	inline uint4 yxzx() const;
	inline uint4 zxzx() const;
	inline uint4 wxzx() const;
	inline uint4 xyzx() const;
	inline uint4 yyzx() const;
	inline uint4 zyzx() const;
	inline uint4 wyzx() const;
	inline uint4 xzzx() const;
	inline uint4 yzzx() const;
	inline uint4 zzzx() const;
	inline uint4 wzzx() const;
	inline uint4 xwzx() const;
	inline uint4 ywzx() const;
	inline uint4 zwzx() const;
	inline uint4 wwzx() const;
	inline uint4 xxwx() const;
	inline uint4 yxwx() const;
	inline uint4 zxwx() const;
	inline uint4 wxwx() const;
	inline uint4 xywx() const;
	inline uint4 yywx() const;
	inline uint4 zywx() const;
	inline uint4 wywx() const;
	inline uint4 xzwx() const;
	inline uint4 yzwx() const;
	inline uint4 zzwx() const;
	inline uint4 wzwx() const;
	inline uint4 xwwx() const;
	inline uint4 ywwx() const;
	inline uint4 zwwx() const;
	inline uint4 wwwx() const;
	inline uint4 xxxy() const;
	inline uint4 yxxy() const;
	inline uint4 zxxy() const;
	inline uint4 wxxy() const;
	inline uint4 xyxy() const;
	inline uint4 yyxy() const;
	inline uint4 zyxy() const;
	inline uint4 wyxy() const;
	inline uint4 xzxy() const;
	inline uint4 yzxy() const;
	inline uint4 zzxy() const;
	inline uint4 wzxy() const;
	inline uint4 xwxy() const;
	inline uint4 ywxy() const;
	inline uint4 zwxy() const;
	inline uint4 wwxy() const;
	inline uint4 xxyy() const;
	inline uint4 yxyy() const;
	inline uint4 zxyy() const;
	inline uint4 wxyy() const;
	inline uint4 xyyy() const;
	inline uint4 yyyy() const;
	inline uint4 zyyy() const;
	inline uint4 wyyy() const;
	inline uint4 xzyy() const;
	inline uint4 yzyy() const;
	inline uint4 zzyy() const;
	inline uint4 wzyy() const;
	inline uint4 xwyy() const;
	inline uint4 ywyy() const;
	inline uint4 zwyy() const;
	inline uint4 wwyy() const;
	inline uint4 xxzy() const;
	inline uint4 yxzy() const;
	inline uint4 zxzy() const;
	inline uint4 wxzy() const;
	inline uint4 xyzy() const;
	inline uint4 yyzy() const;
	inline uint4 zyzy() const;
	inline uint4 wyzy() const;
	inline uint4 xzzy() const;
	inline uint4 yzzy() const;
	inline uint4 zzzy() const;
	inline uint4 wzzy() const;
	inline uint4 xwzy() const;
	inline uint4 ywzy() const;
	inline uint4 zwzy() const;
	inline uint4 wwzy() const;
	inline uint4 xxwy() const;
	inline uint4 yxwy() const;
	inline uint4 zxwy() const;
	inline uint4 wxwy() const;
	inline uint4 xywy() const;
	inline uint4 yywy() const;
	inline uint4 zywy() const;
	inline uint4 wywy() const;
	inline uint4 xzwy() const;
	inline uint4 yzwy() const;
	inline uint4 zzwy() const;
	inline uint4 wzwy() const;
	inline uint4 xwwy() const;
	inline uint4 ywwy() const;
	inline uint4 zwwy() const;
	inline uint4 wwwy() const;
	inline uint4 xxxz() const;
	inline uint4 yxxz() const;
	inline uint4 zxxz() const;
	inline uint4 wxxz() const;
	inline uint4 xyxz() const;
	inline uint4 yyxz() const;
	inline uint4 zyxz() const;
	inline uint4 wyxz() const;
	inline uint4 xzxz() const;
	inline uint4 yzxz() const;
	inline uint4 zzxz() const;
	inline uint4 wzxz() const;
	inline uint4 xwxz() const;
	inline uint4 ywxz() const;
	inline uint4 zwxz() const;
	inline uint4 wwxz() const;
	inline uint4 xxyz() const;
	inline uint4 yxyz() const;
	inline uint4 zxyz() const;
	inline uint4 wxyz() const;
	inline uint4 xyyz() const;
	inline uint4 yyyz() const;
	inline uint4 zyyz() const;
	inline uint4 wyyz() const;
	inline uint4 xzyz() const;
	inline uint4 yzyz() const;
	inline uint4 zzyz() const;
	inline uint4 wzyz() const;
	inline uint4 xwyz() const;
	inline uint4 ywyz() const;
	inline uint4 zwyz() const;
	inline uint4 wwyz() const;
	inline uint4 xxzz() const;
	inline uint4 yxzz() const;
	inline uint4 zxzz() const;
	inline uint4 wxzz() const;
	inline uint4 xyzz() const;
	inline uint4 yyzz() const;
	inline uint4 zyzz() const;
	inline uint4 wyzz() const;
	inline uint4 xzzz() const;
	inline uint4 yzzz() const;
	inline uint4 zzzz() const;
	inline uint4 wzzz() const;
	inline uint4 xwzz() const;
	inline uint4 ywzz() const;
	inline uint4 zwzz() const;
	inline uint4 wwzz() const;
	inline uint4 xxwz() const;
	inline uint4 yxwz() const;
	inline uint4 zxwz() const;
	inline uint4 wxwz() const;
	inline uint4 xywz() const;
	inline uint4 yywz() const;
	inline uint4 zywz() const;
	inline uint4 wywz() const;
	inline uint4 xzwz() const;
	inline uint4 yzwz() const;
	inline uint4 zzwz() const;
	inline uint4 wzwz() const;
	inline uint4 xwwz() const;
	inline uint4 ywwz() const;
	inline uint4 zwwz() const;
	inline uint4 wwwz() const;
	inline uint4 xxxw() const;
	inline uint4 yxxw() const;
	inline uint4 zxxw() const;
	inline uint4 wxxw() const;
	inline uint4 xyxw() const;
	inline uint4 yyxw() const;
	inline uint4 zyxw() const;
	inline uint4 wyxw() const;
	inline uint4 xzxw() const;
	inline uint4 yzxw() const;
	inline uint4 zzxw() const;
	inline uint4 wzxw() const;
	inline uint4 xwxw() const;
	inline uint4 ywxw() const;
	inline uint4 zwxw() const;
	inline uint4 wwxw() const;
	inline uint4 xxyw() const;
	inline uint4 yxyw() const;
	inline uint4 zxyw() const;
	inline uint4 wxyw() const;
	inline uint4 xyyw() const;
	inline uint4 yyyw() const;
	inline uint4 zyyw() const;
	inline uint4 wyyw() const;
	inline uint4 xzyw() const;
	inline uint4 yzyw() const;
	inline uint4 zzyw() const;
	inline uint4 wzyw() const;
	inline uint4 xwyw() const;
	inline uint4 ywyw() const;
	inline uint4 zwyw() const;
	inline uint4 wwyw() const;
	inline uint4 xxzw() const;
	inline uint4 yxzw() const;
	inline uint4 zxzw() const;
	inline uint4 wxzw() const;
	inline uint4 xyzw() const;
	inline uint4 yyzw() const;
	inline uint4 zyzw() const;
	inline uint4 wyzw() const;
	inline uint4 xzzw() const;
	inline uint4 yzzw() const;
	inline uint4 zzzw() const;
	inline uint4 wzzw() const;
	inline uint4 xwzw() const;
	inline uint4 ywzw() const;
	inline uint4 zwzw() const;
	inline uint4 wwzw() const;
	inline uint4 xxww() const;
	inline uint4 yxww() const;
	inline uint4 zxww() const;
	inline uint4 wxww() const;
	inline uint4 xyww() const;
	inline uint4 yyww() const;
	inline uint4 zyww() const;
	inline uint4 wyww() const;
	inline uint4 xzww() const;
	inline uint4 yzww() const;
	inline uint4 zzww() const;
	inline uint4 wzww() const;
	inline uint4 xwww() const;
	inline uint4 ywww() const;
	inline uint4 zwww() const;
	inline uint4 wwww() const;
};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#elif defined( _MSC_VER )
#pragma warning( pop )
#endif

/// \relates uint4
/// \brief Returns true if the all the components of the left-hand-side uint4 match the other one, otherwise returns false.
inline bool operator==( const uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns true if not all of the components of the left-hand-side uint4 match the other one, otherwise returns false.
inline bool operator!=( const uint4& lhs, const uint4& rhs );

