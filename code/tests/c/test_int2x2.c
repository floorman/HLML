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

static int2x2 g_matrixMulLHS_int2x2    = {
		6, 6,
		6, 6
};

static int2x2 g_matrixMulRHS_int2x2    = {
		1, 1,
		2, 2
};

static int2x2 g_matrixMulAnswer_int2x2 = {
		18, 18,
		18, 18
};


TEMPER_TEST( TestAssignment_int2x2 )
{
	int2x2 mat;

	mat.rows[0] = (int2) { 999, 0 };
	mat.rows[1] = (int2) { 0, 999 };

	TEMPER_EXPECT_TRUE( mat.rows[0].x == 999 );
	TEMPER_EXPECT_TRUE( mat.rows[0].y == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].x == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].y == 999 );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_int2x2 )
{
	int2x2 answer = (int2x2) {
		7, 7,
		8, 8
	};

	int2x2 a = (int2x2) {
		6, 6,
		6, 6
	};

	int2x2 b = (int2x2) {
		1, 1,
		2, 2
	};

	int2x2 c = int2x2_caddm( &a, &b );

	TEMPER_EXPECT_TRUE( int2x2_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_int2x2 )
{
	int2x2 answer = (int2x2) {
		5, 5,
		4, 4
	};

	int2x2 a = (int2x2) {
		6, 6,
		6, 6
	};

	int2x2 b = (int2x2) {
		1, 1,
		2, 2
	};

	int2x2 c = int2x2_csubm( &a, &b );

	TEMPER_EXPECT_TRUE( int2x2_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_int2x2 )
{
	int2x2 answer = (int2x2) {
		6, 6,
		12, 12
	};

	int2x2 a = (int2x2) {
		6, 6,
		6, 6
	};

	int2x2 b = (int2x2) {
		1, 1,
		2, 2
	};

	int2x2 c = int2x2_cmulm( &a, &b );

	TEMPER_EXPECT_TRUE( int2x2_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_int2x2 )
{
	int2x2 answer = (int2x2) {
		6, 6,
		3, 3
	};

	int2x2 a = (int2x2) {
		6, 6,
		6, 6
	};

	int2x2 b = (int2x2) {
		1, 1,
		2, 2
	};

	int2x2 c = int2x2_cdivm( &a, &b );

	TEMPER_EXPECT_TRUE( int2x2_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_int2x2 )
{
	int2x2 answer = g_matrixMulAnswer_int2x2;

	int2x2 a = g_matrixMulLHS_int2x2;
	int2x2 b = g_matrixMulRHS_int2x2;
	int2x2 c = int2x2_mulm( &a, &b );

	TEMPER_EXPECT_TRUE( int2x2_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyVector_int2x2 )
{
	int2 answerVec = { 4, 16 };

	int2x2 a = (int2x2) {
		1, 2,
		5, 6
	};
	int2 b = { 2, 1 };
	int2 c = int2x2_mulv( &a, &b );

	TEMPER_EXPECT_TRUE( int2_cmpe( &c, &answerVec ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int2x2 )
{
	bool2x2 allTrue = { 		true, true,
		true, true
 };

	int2x2 mat0 = (int2x2) { 		1, 1,
		1, 1
 };
	int2x2 mat1 = (int2x2) { 		2, 2,
		2, 2
 };
	int2x2 mat2 = (int2x2) { 		3, 3,
		3, 3
 };
	int2x2 mat3 = (int2x2) { 		4, 4,
		4, 4
 };

	bool2x2 test0  = int2x2_cmple( &mat0, &mat0 );
	bool2x2 test1  = int2x2_cmpge( &mat0, &mat0 );
	bool2x2 test2  = int2x2_cmpl( &mat0, &mat1 );
	bool2x2 test3  = int2x2_cmpl( &mat0, &mat2 );
	bool2x2 test4  = int2x2_cmpl( &mat0, &mat3 );

	bool2x2 test5  = int2x2_cmpg( &mat1, &mat0 );
	bool2x2 test6  = int2x2_cmple( &mat1, &mat1 );
	bool2x2 test7  = int2x2_cmpge( &mat1, &mat1 );
	bool2x2 test8  = int2x2_cmpl( &mat1, &mat2 );
	bool2x2 test9  = int2x2_cmpl( &mat1, &mat3 );

	bool2x2 test10 = int2x2_cmpg( &mat2, &mat0 );
	bool2x2 test11 = int2x2_cmpg( &mat2, &mat1 );
	bool2x2 test12 = int2x2_cmple( &mat2, &mat2 );
	bool2x2 test13 = int2x2_cmpge( &mat2, &mat2 );
	bool2x2 test14 = int2x2_cmpl( &mat2, &mat3 );

	bool2x2 test15 = int2x2_cmpg( &mat3, &mat0 );
	bool2x2 test16 = int2x2_cmpg( &mat3, &mat1 );
	bool2x2 test17 = int2x2_cmpg( &mat3, &mat2 );
	bool2x2 test18 = int2x2_cmple( &mat3, &mat3 );
	bool2x2 test19 = int2x2_cmpge( &mat3, &mat3 );

	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test0,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test1,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test2,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test3,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test4,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test5,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test6,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test7,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test8,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test9,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test10, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test11, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test12, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test13, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test14, &allTrue ) );

	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test15, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test16, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test17, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test18, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x2_cmpe( &test19, &allTrue ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_And_int2x2 )
{
	int2x2 answer  = (int2x2) {
		5, 5,
		5, 5
	};
	int2x2 a = (int2x2) {
		21, 21,
		21, 21
	};
	int2x2 b = (int2x2) {
		7, 7,
		7, 7
	};
	int2x2 c = int2x2_cand( &a, &b );

	TEMPER_EXPECT_TRUE( int2x2_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Or_int2x2 )
{
	int2x2 answer  = (int2x2) {
		23, 23,
		23, 23
	};
	int2x2 a = (int2x2) {
		21, 21,
		21, 21
	};
	int2x2 b = (int2x2) {
		7, 7,
		7, 7
	};
	int2x2 c = int2x2_cor( &a, &b );

	TEMPER_EXPECT_TRUE( int2x2_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Xor_int2x2 )
{
	int2x2 answer  = (int2x2) {
		18, 18,
		18, 18
	};
	int2x2 a = (int2x2) {
		21, 21,
		21, 21
	};
	int2x2 b = (int2x2) {
		7, 7,
		7, 7
	};
	int2x2 c = int2x2_cxor( &a, &b );

	TEMPER_EXPECT_TRUE( int2x2_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftLeft_int2x2 )
{
	int2x2 answer  = (int2x2) {
		4, 4,
		4, 4
	};
	int2x2 a = (int2x2) {
		1, 1,
		1, 1
	};
	int2x2 b = (int2x2) {
		2, 2,
		2, 2
	};
	int2x2 c = int2x2_cshift_left( &a, &b );

	TEMPER_EXPECT_TRUE( int2x2_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftRight_int2x2 )
{
	int2x2 answer  = (int2x2) {
		1, 1,
		1, 1
	};
	int2x2 a = (int2x2) {
		16, 16,
		16, 16
	};
	int2x2 b = (int2x2) {
		4, 4,
		4, 4
	};
	int2x2 c = int2x2_cshift_right( &a, &b );

	TEMPER_EXPECT_TRUE( int2x2_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Unary_int2x2 )
{
	int2x2 answer = (int2x2) {
		(int32_t) -1, (int32_t) -1,
		(int32_t) -1, (int32_t) -1
	};
	int2x2 a = (int2x2) {
		0, 0,
		0, 0
	};

	int2x2 b = int2x2_cunary( &a );

	TEMPER_EXPECT_TRUE( int2x2_cmpe( &b, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_Scalar_int2x2 )
{
	int2x2 id;
	id.rows[0] = (int2) { 1, 0 };
	id.rows[1] = (int2) { 0, 1 };

	int2x2 mat;
	int2x2_identity( &mat );
	TEMPER_EXPECT_TRUE( int2x2_cmpe( &mat, &id ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_Scalar_int2x2 )
{
	int2x2 answerTransposed = (int2x2) {
		0, 4,
		1, 5
	};

	int2x2 mat = (int2x2) {
		0, 1,
		4, 5
	};
	int2x2 trans = int2x2_transpose( &mat );

	TEMPER_EXPECT_TRUE( int2x2_cmpe( &trans, &answerTransposed ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_Scalar_int2x2 )
{
	int2x2 mat = (int2x2) {
		6, 2,
		2, 6
	};
	int32_t det = int2x2_determinant( &mat );

	TEMPER_EXPECT_TRUE( det == 32 );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_int2x2 )
{
	TEMPER_RUN_TEST( TestAssignment_int2x2 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Addition_int2x2 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_int2x2 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_int2x2 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Division_int2x2 );
	TEMPER_RUN_TEST( TestMultiplyMatrix_Scalar_int2x2 );
	TEMPER_RUN_TEST( TestMultiplyVector_int2x2 );
	TEMPER_RUN_TEST( TestRelational_int2x2 );
	TEMPER_RUN_TEST( TestBitwise_And_int2x2 );
	TEMPER_RUN_TEST( TestBitwise_Or_int2x2 );
	TEMPER_RUN_TEST( TestBitwise_Xor_int2x2 );
	TEMPER_RUN_TEST( TestBitwise_ShiftLeft_int2x2 );
	TEMPER_RUN_TEST( TestBitwise_ShiftRight_int2x2 );
	TEMPER_RUN_TEST( TestBitwise_Unary_int2x2 );
	TEMPER_RUN_TEST( TestIdentity_Scalar_int2x2 );
	TEMPER_RUN_TEST( TestTranspose_Scalar_int2x2 );
	TEMPER_RUN_TEST( TestDeterminant_Scalar_int2x2 );
}
