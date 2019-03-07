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

#include "../out/gen/hlml_functions_matrix.h"

#include <temper.h>

TEMPER_TEST( TestAssignment_double3x3 ) {
	double3x3 mat;

	// fill single value
	mat = double3x3( 999.000000 );
	TEMPER_EXPECT_TRUE( mat[0] == double3( 999.000000, 0.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 0.000000, 999.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 0.000000, 0.000000, 999.000000 ) );

	// row filling
	mat = double3x3(
		double3( 0, 1, 2 ),
		double3( 3, 4, 5 ),
		double3( 6, 7, 8 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == double3( 0, 1, 2 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 3, 4, 5 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 6, 7, 8 ) );

	// all values filled
	mat = double3x3(
		9, 8, 7, 
		6, 5, 4, 
		3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == double3( 9, 8, 7 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 6, 5, 4 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_double3x3 ) {
	double3x3 mat;

	TEMPER_EXPECT_TRUE( mat[0] == double3( 1.000000, 0.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 0.000000, 1.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 0.000000, 0.000000, 1.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double3x3 ) {
	double3x3 mat0 = double3x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
	);
	double3x3 mat1 = double3x3(
		2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000
	);
	double3x3 mat2 = double3x3(
		3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000
	);
	double3x3 mat3 = double3x3(
		4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000
	);

	bool3x3 test0 = mat0 <= mat0;
	bool3x3 test1 = mat0 >= mat0;
	bool3x3 test2 = mat0 < mat1;

	bool3x3 test3 = mat1 <= mat1;
	bool3x3 test4 = mat1 >= mat1;
	bool3x3 test5 = mat1 < mat2;
	bool3x3 test6 = mat1 > mat0;

	bool3x3 test7 = mat2 <= mat2;
	bool3x3 test8 = mat2 >= mat2;
	bool3x3 test9 = mat2 < mat3;
	bool3x3 test10 = mat2 > mat1;

	bool3x3 test11 = mat3 <= mat3;
	bool3x3 test12 = mat3 >= mat3;
	bool3x3 test13 = mat3 > mat2;

	TEMPER_EXPECT_TRUE( test0 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test1 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test2 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test3 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test4 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test5 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test6 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test7 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test8 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test9 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test10 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test11 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test12 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test13 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_double3x3 ) {
	double3x3 id = double3x3(
		1.000000, 0.000000, 0.000000,
		0.000000, 1.000000, 0.000000,
		0.000000, 0.000000, 1.000000
	);

	double3x3 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_double3x3 ) {
	double3x3 mat = double3x3(
		0.000000, 1.000000, 2.000000,
		3.000000, 4.000000, 5.000000,
		6.000000, 7.000000, 8.000000
	);
	double3x3 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == double3x3(
		0.000000, 3.000000, 6.000000,
		1.000000, 4.000000, 7.000000,
		2.000000, 5.000000, 8.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_double3x3 ) {
	double3x3 identityMatrix;

	double3x3 mat = double3x3(
		6.000000, 2.000000, 3.000000,
		2.000000, 7.000000, 2.000000,
		3.000000, 2.000000, 6.000000
	);
	double3x3 matInverse = inverse( mat );

	TEMPER_EXPECT_TRUE( mat * matInverse == identityMatrix );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_double3x3 ) {
	double3x3 mat = double3x3(
		6.000000, 2.000000, 3.000000,
		2.000000, 7.000000, 2.000000,
		3.000000, 2.000000, 6.000000
	);
	double det = determinant( mat );

	TEMPER_EXPECT_TRUE( floateq( det, 165.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_double3x3 ) {
	double3x3 mat;
	double3x3 translated = double3x3(
		1.000000, 0.000000, 2.000000,
		0.000000, 1.000000, 3.000000,
		0.000000, 0.000000, 1.000000
	);

	double2 translation = double2( 2.000000, 3.000000 );
	mat = translate( mat, translation );

	TEMPER_EXPECT_TRUE( mat == translated );

	TEMPER_PASS();
}

TEMPER_TEST( TestRotate_double3x3 ) {
	double3x3 mat;
	double3x3 roll = rotate( mat, radians( 45.000000 ) );

	double3x3 answerRoll = double3x3(
		0.707107, -0.707107, 0.000000,
		0.707107, 0.707107, 0.000000,
		0.000000, 0.000000, 1.000000
	);

	TEMPER_EXPECT_TRUE( roll == answerRoll );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_double3x3 ) {
	double3x3 mat;
	double3x3 scaled = scale( mat, double3( 2.000000, 2.000000, 2.000000 ) );

	TEMPER_EXPECT_TRUE( scaled == double3x3(
		2.000000, 0.000000, 0.000000,
		0.000000, 2.000000, 0.000000,
		0.000000, 0.000000, 2.000000
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_double3x3 ) {
	TEMPER_RUN_TEST( TestAssignment_double3x3 );


	TEMPER_RUN_TEST( TestArray_double3x3 );
	TEMPER_RUN_TEST( TestRelational_double3x3 );

	TEMPER_RUN_TEST( TestIdentity_double3x3 );
	TEMPER_RUN_TEST( TestTranspose_double3x3 );
	TEMPER_RUN_TEST( TestDeterminant_double3x3 );
	TEMPER_RUN_TEST( TestInverse_double3x3 );

	TEMPER_RUN_TEST( TestTranslate_double3x3 );
	TEMPER_RUN_TEST( TestRotate_double3x3 );
	TEMPER_RUN_TEST( TestScale_double3x3 );

};
