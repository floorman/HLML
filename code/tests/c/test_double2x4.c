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

static double2x4 g_matrixMulLHS_double2x4    = {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000
};

static double4x2 g_matrixMulRHS_double2x4    = {
		1.000000, 1.000000,
		2.000000, 2.000000,
		3.000000, 3.000000,
		6.000000, 6.000000
};

static double2x2 g_matrixMulAnswer_double2x4 = {
		72.000000, 72.000000,
		72.000000, 72.000000
};


TEMPER_TEST( TestAssignment_double2x4, TEMPER_FLAG_SHOULD_RUN )
{
	double2x4 mat;

	mat.rows[0] = (double4) { 999.000000, 0.000000, 0.000000, 0.000000 };
	mat.rows[1] = (double4) { 0.000000, 999.000000, 0.000000, 0.000000 };

	TEMPER_CHECK_TRUE( mat.rows[0].x == 999.0 );
	TEMPER_CHECK_TRUE( mat.rows[0].y == 0.0 );
	TEMPER_CHECK_TRUE( mat.rows[0].z == 0.0 );
	TEMPER_CHECK_TRUE( mat.rows[0].w == 0.0 );
	TEMPER_CHECK_TRUE( mat.rows[1].x == 0.0 );
	TEMPER_CHECK_TRUE( mat.rows[1].y == 999.0 );
	TEMPER_CHECK_TRUE( mat.rows[1].z == 0.0 );
	TEMPER_CHECK_TRUE( mat.rows[1].w == 0.0 );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_double2x4, TEMPER_FLAG_SHOULD_RUN )
{
	double2x4 answer = (double2x4) {
		7.000000, 7.000000, 7.000000, 7.000000,
		8.000000, 8.000000, 8.000000, 8.000000
	};

	double2x4 a = (double2x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	};

	double2x4 b = (double2x4) {
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000
	};

	double2x4 c = double2x4_caddm( &a, &b );

	TEMPER_CHECK_TRUE( double2x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_double2x4, TEMPER_FLAG_SHOULD_RUN )
{
	double2x4 answer = (double2x4) {
		5.000000, 5.000000, 5.000000, 5.000000,
		4.000000, 4.000000, 4.000000, 4.000000
	};

	double2x4 a = (double2x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	};

	double2x4 b = (double2x4) {
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000
	};

	double2x4 c = double2x4_csubm( &a, &b );

	TEMPER_CHECK_TRUE( double2x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_double2x4, TEMPER_FLAG_SHOULD_RUN )
{
	double2x4 answer = (double2x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000
	};

	double2x4 a = (double2x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	};

	double2x4 b = (double2x4) {
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000
	};

	double2x4 c = double2x4_cmulm( &a, &b );

	TEMPER_CHECK_TRUE( double2x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_double2x4, TEMPER_FLAG_SHOULD_RUN )
{
	double2x4 answer = (double2x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		3.000000, 3.000000, 3.000000, 3.000000
	};

	double2x4 a = (double2x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	};

	double2x4 b = (double2x4) {
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000
	};

	double2x4 c = double2x4_cdivm( &a, &b );

	TEMPER_CHECK_TRUE( double2x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_double2x4, TEMPER_FLAG_SHOULD_RUN )
{
	double2x2 answer = g_matrixMulAnswer_double2x4;

	double2x4 a = g_matrixMulLHS_double2x4;
	double4x2 b = g_matrixMulRHS_double2x4;
	double2x2 c = double2x4_mulm( &a, &b );

	TEMPER_CHECK_TRUE( double2x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestRelational_double2x4, TEMPER_FLAG_SHOULD_RUN )
{
	bool2x4 allTrue = { 		true, true, true, true,
		true, true, true, true
 };

	double2x4 mat0 = (double2x4) { 		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000
 };
	double2x4 mat1 = (double2x4) { 		2.000000, 2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000, 2.000000
 };
	double2x4 mat2 = (double2x4) { 		3.000000, 3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000, 3.000000
 };
	double2x4 mat3 = (double2x4) { 		4.000000, 4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000, 4.000000
 };

	bool2x4 test0  = double2x4_cmple( &mat0, &mat0 );
	bool2x4 test1  = double2x4_cmpge( &mat0, &mat0 );
	bool2x4 test2  = double2x4_cmpl( &mat0, &mat1 );
	bool2x4 test3  = double2x4_cmpl( &mat0, &mat2 );
	bool2x4 test4  = double2x4_cmpl( &mat0, &mat3 );

	bool2x4 test5  = double2x4_cmpg( &mat1, &mat0 );
	bool2x4 test6  = double2x4_cmple( &mat1, &mat1 );
	bool2x4 test7  = double2x4_cmpge( &mat1, &mat1 );
	bool2x4 test8  = double2x4_cmpl( &mat1, &mat2 );
	bool2x4 test9  = double2x4_cmpl( &mat1, &mat3 );

	bool2x4 test10 = double2x4_cmpg( &mat2, &mat0 );
	bool2x4 test11 = double2x4_cmpg( &mat2, &mat1 );
	bool2x4 test12 = double2x4_cmple( &mat2, &mat2 );
	bool2x4 test13 = double2x4_cmpge( &mat2, &mat2 );
	bool2x4 test14 = double2x4_cmpl( &mat2, &mat3 );

	bool2x4 test15 = double2x4_cmpg( &mat3, &mat0 );
	bool2x4 test16 = double2x4_cmpg( &mat3, &mat1 );
	bool2x4 test17 = double2x4_cmpg( &mat3, &mat2 );
	bool2x4 test18 = double2x4_cmple( &mat3, &mat3 );
	bool2x4 test19 = double2x4_cmpge( &mat3, &mat3 );

	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test0,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test1,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test2,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test3,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test4,  &allTrue ) );

	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test5,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test6,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test7,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test8,  &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test9,  &allTrue ) );

	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test10, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test11, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test12, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test13, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test14, &allTrue ) );

	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test15, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test16, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test17, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test18, &allTrue ) );
	TEMPER_CHECK_TRUE( bool2x4_cmpe( &test19, &allTrue ) );
}

TEMPER_TEST( TestIdentity_Scalar_double2x4, TEMPER_FLAG_SHOULD_RUN )
{
	double2x4 id;
	id.rows[0] = (double4) { 1.000000, 0.000000, 0.000000, 0.000000 };
	id.rows[1] = (double4) { 0.000000, 1.000000, 0.000000, 0.000000 };

	double2x4 mat;
	double2x4_identity( &mat );
	TEMPER_CHECK_TRUE( double2x4_cmpe( &mat, &id ) );
}

TEMPER_TEST( TestTranspose_Scalar_double2x4, TEMPER_FLAG_SHOULD_RUN )
{
	double4x2 answerTransposed = (double4x2) {
		0.000000, 4.000000,
		1.000000, 5.000000,
		2.000000, 6.000000,
		3.000000, 7.000000
	};

	double2x4 mat = (double2x4) {
		0.000000, 1.000000, 2.000000, 3.000000,
		4.000000, 5.000000, 6.000000, 7.000000
	};
	double4x2 trans = double2x4_transpose( &mat );

	TEMPER_CHECK_TRUE( double4x2_cmpe( &trans, &answerTransposed ) );
}

TEMPER_TEST( TestScale_Scalar_double2x4, TEMPER_FLAG_SHOULD_RUN )
{
	double2 scaleVec = { 2.000000, 2.000000 };
	double2x4 mat;
	double2x4_identity( &mat );

	double2x4 scaled = double2x4_scale( &mat, &scaleVec );

	TEMPER_CHECK_TRUE( doubleeq( scaled.rows[0].x, 2.000000 ) );
	TEMPER_CHECK_TRUE( doubleeq( scaled.rows[1].y, 2.000000 ) );
}

