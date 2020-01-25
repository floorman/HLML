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

static int2x3 g_matrixMulLHS_int2x3    = (int2x3) {
		6, 6, 6,
		6, 6, 6
};

static int3x2 g_matrixMulRHS_int2x3    = (int3x2) {
		1, 1,
		2, 2,
		3, 3
};

static int2x2 g_matrixMulAnswer_int2x3 = (int2x2) {
		36, 36,
		36, 36
};


TEMPER_TEST( TestAssignment_int2x3, void )
{
	int2x3 mat;

	mat.rows[0] = (int3) { 999, 0, 0 };
	mat.rows[1] = (int3) { 0, 999, 0 };

	TEMPER_EXPECT_TRUE( mat.rows[0].x == 999 );
	TEMPER_EXPECT_TRUE( mat.rows[0].y == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].z == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].x == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].y == 999 );
	TEMPER_EXPECT_TRUE( mat.rows[1].z == 0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_int2x3, void )
{
	int2x3 answer = (int2x3) {
		7, 7, 7,
		8, 8, 8
	};

	int2x3 a = (int2x3) {
		6, 6, 6,
		6, 6, 6
	};

	int2x3 b = (int2x3) {
		1, 1, 1,
		2, 2, 2
	};

	int2x3 c = int2x3_comp_addm( &a, &b );

	TEMPER_EXPECT_TRUE( int2x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_int2x3, void )
{
	int2x3 answer = (int2x3) {
		5, 5, 5,
		4, 4, 4
	};

	int2x3 a = (int2x3) {
		6, 6, 6,
		6, 6, 6
	};

	int2x3 b = (int2x3) {
		1, 1, 1,
		2, 2, 2
	};

	int2x3 c = int2x3_comp_subm( &a, &b );

	TEMPER_EXPECT_TRUE( int2x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_int2x3, void )
{
	int2x3 answer = (int2x3) {
		6, 6, 6,
		12, 12, 12
	};

	int2x3 a = (int2x3) {
		6, 6, 6,
		6, 6, 6
	};

	int2x3 b = (int2x3) {
		1, 1, 1,
		2, 2, 2
	};

	int2x3 c = int2x3_comp_mulm( &a, &b );

	TEMPER_EXPECT_TRUE( int2x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_int2x3, void )
{
	int2x3 answer = (int2x3) {
		6, 6, 6,
		3, 3, 3
	};

	int2x3 a = (int2x3) {
		6, 6, 6,
		6, 6, 6
	};

	int2x3 b = (int2x3) {
		1, 1, 1,
		2, 2, 2
	};

	int2x3 c = int2x3_comp_divm( &a, &b );

	TEMPER_EXPECT_TRUE( int2x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_int2x3, void )
{
	int2x2 answer = g_matrixMulAnswer_int2x3;

	int2x3 a = g_matrixMulLHS_int2x3;
	int3x2 b = g_matrixMulRHS_int2x3;
	int2x2 c = int2x3_mulm( &a, &b );

	TEMPER_EXPECT_TRUE( int2x2_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int2x3, void )
{
	bool2x3 allTrue = { 		true, true, true,
		true, true, true
 };

	int2x3 mat0 = (int2x3) { 		1, 1, 1,
		1, 1, 1
 };
	int2x3 mat1 = (int2x3) { 		2, 2, 2,
		2, 2, 2
 };
	int2x3 mat2 = (int2x3) { 		3, 3, 3,
		3, 3, 3
 };
	int2x3 mat3 = (int2x3) { 		4, 4, 4,
		4, 4, 4
 };

	bool2x3 test0  = int2x3_cmple( &mat0, &mat0 );
	bool2x3 test1  = int2x3_cmpge( &mat0, &mat0 );
	bool2x3 test2  = int2x3_cmpl( &mat0, &mat1 );
	bool2x3 test3  = int2x3_cmpl( &mat0, &mat2 );
	bool2x3 test4  = int2x3_cmpl( &mat0, &mat3 );

	bool2x3 test5  = int2x3_cmpg( &mat1, &mat0 );
	bool2x3 test6  = int2x3_cmple( &mat1, &mat1 );
	bool2x3 test7  = int2x3_cmpge( &mat1, &mat1 );
	bool2x3 test8  = int2x3_cmpl( &mat1, &mat2 );
	bool2x3 test9  = int2x3_cmpl( &mat1, &mat3 );

	bool2x3 test10 = int2x3_cmpg( &mat2, &mat0 );
	bool2x3 test11 = int2x3_cmpg( &mat2, &mat1 );
	bool2x3 test12 = int2x3_cmple( &mat2, &mat2 );
	bool2x3 test13 = int2x3_cmpge( &mat2, &mat2 );
	bool2x3 test14 = int2x3_cmpl( &mat2, &mat3 );

	bool2x3 test15 = int2x3_cmpg( &mat3, &mat0 );
	bool2x3 test16 = int2x3_cmpg( &mat3, &mat1 );
	bool2x3 test17 = int2x3_cmpg( &mat3, &mat2 );
	bool2x3 test18 = int2x3_cmple( &mat3, &mat3 );
	bool2x3 test19 = int2x3_cmpge( &mat3, &mat3 );

	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test0,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test1,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test2,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test3,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test4,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test5,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test6,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test7,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test8,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test9,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test10, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test11, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test12, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test13, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test14, &allTrue ) );

	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test15, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test16, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test17, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test18, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test19, &allTrue ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_And_int2x3, void )
{
	int2x3 answer  = (int2x3) {
		5, 5, 5,
		5, 5, 5
	};
	int2x3 a = (int2x3) {
		21, 21, 21,
		21, 21, 21
	};
	int2x3 b = (int2x3) {
		7, 7, 7,
		7, 7, 7
	};
	int2x3 c = int2x3_comp_and( &a, &b );

	TEMPER_EXPECT_TRUE( int2x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Or_int2x3, void )
{
	int2x3 answer  = (int2x3) {
		23, 23, 23,
		23, 23, 23
	};
	int2x3 a = (int2x3) {
		21, 21, 21,
		21, 21, 21
	};
	int2x3 b = (int2x3) {
		7, 7, 7,
		7, 7, 7
	};
	int2x3 c = int2x3_comp_or( &a, &b );

	TEMPER_EXPECT_TRUE( int2x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Xor_int2x3, void )
{
	int2x3 answer  = (int2x3) {
		18, 18, 18,
		18, 18, 18
	};
	int2x3 a = (int2x3) {
		21, 21, 21,
		21, 21, 21
	};
	int2x3 b = (int2x3) {
		7, 7, 7,
		7, 7, 7
	};
	int2x3 c = int2x3_comp_xor( &a, &b );

	TEMPER_EXPECT_TRUE( int2x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftLeft_int2x3, void )
{
	int2x3 answer  = (int2x3) {
		4, 4, 4,
		4, 4, 4
	};
	int2x3 a = (int2x3) {
		1, 1, 1,
		1, 1, 1
	};
	int2x3 b = (int2x3) {
		2, 2, 2,
		2, 2, 2
	};
	int2x3 c = int2x3_comp_shift_left( &a, &b );

	TEMPER_EXPECT_TRUE( int2x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftRight_int2x3, void )
{
	int2x3 answer  = (int2x3) {
		1, 1, 1,
		1, 1, 1
	};
	int2x3 a = (int2x3) {
		16, 16, 16,
		16, 16, 16
	};
	int2x3 b = (int2x3) {
		4, 4, 4,
		4, 4, 4
	};
	int2x3 c = int2x3_comp_shift_right( &a, &b );

	TEMPER_EXPECT_TRUE( int2x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Unary_int2x3, void )
{
	int2x3 answer = (int2x3) {
		(int32_t) -1, (int32_t) -1, (int32_t) -1,
		(int32_t) -1, (int32_t) -1, (int32_t) -1
	};
	int2x3 a = (int2x3) {
		0, 0, 0,
		0, 0, 0
	};

	int2x3 b = int2x3_comp_unary( &a );

	TEMPER_EXPECT_TRUE( int2x3_cmpe( &b, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_Scalar_int2x3, void )
{
	int2x3 id;
	id.rows[0] = (int3) { 1, 0, 0 };
	id.rows[1] = (int3) { 0, 1, 0 };

	int2x3 mat;
	int2x3_identity( &mat );
	TEMPER_EXPECT_TRUE( int2x3_cmpe( &mat, &id ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_Scalar_int2x3, void )
{
	int3x2 answerTransposed = (int3x2) {
		0, 4,
		1, 5,
		2, 6
	};

	int2x3 mat = (int2x3) {
		0, 1, 2,
		4, 5, 6
	};
	int3x2 trans = int2x3_transpose( &mat );

	TEMPER_EXPECT_TRUE( int3x2_cmpe( &trans, &answerTransposed ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_Scalar_int2x3, void )
{
	int2 scaleVec = { 2, 2 };
	int2x3 mat;
	int2x3_identity( &mat );

	int2x3 scaled = int2x3_scale( &mat, &scaleVec );

	TEMPER_EXPECT_TRUE( scaled.rows[0].x == 2 );
	TEMPER_EXPECT_TRUE( scaled.rows[1].y == 2 );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_int2x3 )
{
	TEMPER_RUN_TEST( TestAssignment_int2x3 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Addition_int2x3 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_int2x3 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_int2x3 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Division_int2x3 );
	TEMPER_RUN_TEST( TestMultiplyMatrix_Scalar_int2x3 );
	TEMPER_RUN_TEST( TestRelational_int2x3 );
	TEMPER_RUN_TEST( TestBitwise_And_int2x3 );
	TEMPER_RUN_TEST( TestBitwise_Or_int2x3 );
	TEMPER_RUN_TEST( TestBitwise_Xor_int2x3 );
	TEMPER_RUN_TEST( TestBitwise_ShiftLeft_int2x3 );
	TEMPER_RUN_TEST( TestBitwise_ShiftRight_int2x3 );
	TEMPER_RUN_TEST( TestBitwise_Unary_int2x3 );
	TEMPER_RUN_TEST( TestIdentity_Scalar_int2x3 );
	TEMPER_RUN_TEST( TestTranspose_Scalar_int2x3 );
	TEMPER_RUN_TEST( TestScale_Scalar_int2x3 );
}
