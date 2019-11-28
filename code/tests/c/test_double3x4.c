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

static double3x4 g_matrixMulLHS_double3x4    = (double3x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000
};

static double4x3 g_matrixMulRHS_double3x4    = (double4x3) {
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000
};

static double3x3 g_matrixMulAnswer_double3x4 = (double3x3) {
		72.000000, 72.000000, 72.000000,
		72.000000, 72.000000, 72.000000,
		144.000000, 144.000000, 144.000000
};


TEMPER_TEST( TestAssignment_double3x4 )
{
	double3x4 mat;

	mat.rows[0] = (double4) { 999.000000, 0.000000, 0.000000, 0.000000 };
	mat.rows[1] = (double4) { 0.000000, 999.000000, 0.000000, 0.000000 };
	mat.rows[2] = (double4) { 0.000000, 0.000000, 999.000000, 0.000000 };

	TEMPER_EXPECT_TRUE( mat.rows[0].x == 999.0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].y == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].z == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].w == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].x == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].y == 999.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].z == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].w == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].x == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].y == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].z == 999.0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].w == 0.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_double3x4 )
{
	double3x4 answer = (double3x4) {
		7.000000, 7.000000, 7.000000, 7.000000,
		8.000000, 8.000000, 8.000000, 8.000000,
		15.000000, 15.000000, 15.000000, 15.000000
	};

	double3x4 a = (double3x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000
	};

	double3x4 b = (double3x4) {
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000
	};

	double3x4 c = double3x4_comp_addm( &a, &b );

	TEMPER_EXPECT_TRUE( double3x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_double3x4 )
{
	double3x4 answer = (double3x4) {
		5.000000, 5.000000, 5.000000, 5.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		9.000000, 9.000000, 9.000000, 9.000000
	};

	double3x4 a = (double3x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000
	};

	double3x4 b = (double3x4) {
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000
	};

	double3x4 c = double3x4_comp_subm( &a, &b );

	TEMPER_EXPECT_TRUE( double3x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_double3x4 )
{
	double3x4 answer = (double3x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		36.000000, 36.000000, 36.000000, 36.000000
	};

	double3x4 a = (double3x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000
	};

	double3x4 b = (double3x4) {
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000
	};

	double3x4 c = double3x4_comp_mulm( &a, &b );

	TEMPER_EXPECT_TRUE( double3x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_double3x4 )
{
	double3x4 answer = (double3x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		4.000000, 4.000000, 4.000000, 4.000000
	};

	double3x4 a = (double3x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000
	};

	double3x4 b = (double3x4) {
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000
	};

	double3x4 c = double3x4_comp_divm( &a, &b );

	TEMPER_EXPECT_TRUE( double3x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_double3x4 )
{
	double3x3 answer = g_matrixMulAnswer_double3x4;

	double3x4 a = g_matrixMulLHS_double3x4;
	double4x3 b = g_matrixMulRHS_double3x4;
	double3x3 c = double3x4_mulm( &a, &b );

	TEMPER_EXPECT_TRUE( double3x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double3x4 )
{
	bool3x4 allTrue = { 		true, true, true, true,
		true, true, true, true,
		true, true, true, true
 };

	double3x4 mat0 = (double3x4) { 		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000
 };
	double3x4 mat1 = (double3x4) { 		2.000000, 2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000, 2.000000
 };
	double3x4 mat2 = (double3x4) { 		3.000000, 3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000, 3.000000
 };
	double3x4 mat3 = (double3x4) { 		4.000000, 4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000, 4.000000
 };

	bool3x4 test0  = double3x4_cmple( &mat0, &mat0 );
	bool3x4 test1  = double3x4_cmpge( &mat0, &mat0 );
	bool3x4 test2  = double3x4_cmpl( &mat0, &mat1 );
	bool3x4 test3  = double3x4_cmpl( &mat0, &mat2 );
	bool3x4 test4  = double3x4_cmpl( &mat0, &mat3 );

	bool3x4 test5  = double3x4_cmpg( &mat1, &mat0 );
	bool3x4 test6  = double3x4_cmple( &mat1, &mat1 );
	bool3x4 test7  = double3x4_cmpge( &mat1, &mat1 );
	bool3x4 test8  = double3x4_cmpl( &mat1, &mat2 );
	bool3x4 test9  = double3x4_cmpl( &mat1, &mat3 );

	bool3x4 test10 = double3x4_cmpg( &mat2, &mat0 );
	bool3x4 test11 = double3x4_cmpg( &mat2, &mat1 );
	bool3x4 test12 = double3x4_cmple( &mat2, &mat2 );
	bool3x4 test13 = double3x4_cmpge( &mat2, &mat2 );
	bool3x4 test14 = double3x4_cmpl( &mat2, &mat3 );

	bool3x4 test15 = double3x4_cmpg( &mat3, &mat0 );
	bool3x4 test16 = double3x4_cmpg( &mat3, &mat1 );
	bool3x4 test17 = double3x4_cmpg( &mat3, &mat2 );
	bool3x4 test18 = double3x4_cmple( &mat3, &mat3 );
	bool3x4 test19 = double3x4_cmpge( &mat3, &mat3 );

	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test0,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test1,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test2,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test3,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test4,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test5,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test6,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test7,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test8,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test9,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test10, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test11, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test12, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test13, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test14, &allTrue ) );

	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test15, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test16, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test17, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test18, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool3x4_cmpe( &test19, &allTrue ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_Scalar_double3x4 )
{
	double3x4 id;
	id.rows[0] = (double4) { 1.000000, 0.000000, 0.000000, 0.000000 };
	id.rows[1] = (double4) { 0.000000, 1.000000, 0.000000, 0.000000 };
	id.rows[2] = (double4) { 0.000000, 0.000000, 1.000000, 0.000000 };

	double3x4 mat;
	double3x4_identity( &mat );
	TEMPER_EXPECT_TRUE( double3x4_cmpe( &mat, &id ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_Scalar_double3x4 )
{
	double4x3 answerTransposed = (double4x3) {
		0.000000, 4.000000, 8.000000,
		1.000000, 5.000000, 9.000000,
		2.000000, 6.000000, 10.000000,
		3.000000, 7.000000, 11.000000
	};

	double3x4 mat = (double3x4) {
		0.000000, 1.000000, 2.000000, 3.000000,
		4.000000, 5.000000, 6.000000, 7.000000,
		8.000000, 9.000000, 10.000000, 11.000000
	};
	double4x3 trans = double3x4_transpose( &mat );

	TEMPER_EXPECT_TRUE( double4x3_cmpe( &trans, &answerTransposed ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_Scalar_double3x4 )
{
	double3x4 mat;
	double3x4_identity( &mat );

	double3 translation = { 2.000000, 3.000000, 4.000000 };
	mat = double3x4_translate( &mat, &translation );

	TEMPER_EXPECT_TRUE( doubleeq( mat.rows[0].w, 2.0 ) );
	TEMPER_EXPECT_TRUE( doubleeq( mat.rows[1].w, 3.0 ) );
	TEMPER_EXPECT_TRUE( doubleeq( mat.rows[2].w, 4.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_Scalar_double3x4 )
{
	double2 scaleVec = { 2.000000, 2.000000 };
	double3x4 mat;
	double3x4_identity( &mat );

	double3x4 scaled = double3x4_scale( &mat, &scaleVec );

	TEMPER_EXPECT_TRUE( doubleeq( scaled.rows[0].x, 2.000000 ) );
	TEMPER_EXPECT_TRUE( doubleeq( scaled.rows[1].y, 2.000000 ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_double3x4 )
{
	TEMPER_RUN_TEST( TestAssignment_double3x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Addition_double3x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_double3x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_double3x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Division_double3x4 );
	TEMPER_RUN_TEST( TestMultiplyMatrix_Scalar_double3x4 );
	TEMPER_RUN_TEST( TestRelational_double3x4 );
	TEMPER_RUN_TEST( TestIdentity_Scalar_double3x4 );
	TEMPER_RUN_TEST( TestTranspose_Scalar_double3x4 );
	TEMPER_RUN_TEST( TestTranslate_Scalar_double3x4 );
	TEMPER_RUN_TEST( TestScale_Scalar_double3x4 );
}