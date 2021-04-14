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

TEMPER_TEST( TestAssignment_bool3x4, TEMPER_FLAG_SHOULD_RUN )
{
	bool3x4 mat;

	mat.rows[0] = (bool4) { true, false, false, false };
	mat.rows[1] = (bool4) { false, true, false, false };
	mat.rows[2] = (bool4) { false, false, true, false };

	TEMPER_CHECK_TRUE( mat.rows[0].x == true );
	TEMPER_CHECK_TRUE( mat.rows[0].y == false );
	TEMPER_CHECK_TRUE( mat.rows[0].z == false );
	TEMPER_CHECK_TRUE( mat.rows[0].w == false );
	TEMPER_CHECK_TRUE( mat.rows[1].x == false );
	TEMPER_CHECK_TRUE( mat.rows[1].y == true );
	TEMPER_CHECK_TRUE( mat.rows[1].z == false );
	TEMPER_CHECK_TRUE( mat.rows[1].w == false );
	TEMPER_CHECK_TRUE( mat.rows[2].x == false );
	TEMPER_CHECK_TRUE( mat.rows[2].y == false );
	TEMPER_CHECK_TRUE( mat.rows[2].z == true );
	TEMPER_CHECK_TRUE( mat.rows[2].w == false );
}

TEMPER_TEST( TestIdentity_Scalar_bool3x4, TEMPER_FLAG_SHOULD_RUN )
{
	bool3x4 id;
	id.rows[0] = (bool4) { true, false, false, false };
	id.rows[1] = (bool4) { false, true, false, false };
	id.rows[2] = (bool4) { false, false, true, false };

	bool3x4 mat;
	bool3x4_identity( &mat );
	TEMPER_CHECK_TRUE( bool3x4_cmpe( &mat, &id ) );
}

TEMPER_TEST( TestTranspose_Scalar_bool3x4, TEMPER_FLAG_SHOULD_RUN )
{
	bool4x3 answerTransposed = (bool4x3) {
		false, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	};

	bool3x4 mat = (bool3x4) {
		false, true, true, true,
		true, true, true, true,
		true, true, true, true
	};
	bool4x3 trans = bool3x4_transpose( &mat );

	TEMPER_CHECK_TRUE( bool4x3_cmpe( &trans, &answerTransposed ) );
}

