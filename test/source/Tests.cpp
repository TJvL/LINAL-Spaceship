//
// Created by thomas on 14-1-19.
//

#include "../include/Catch.hpp"
#include "../../main/include/math/Matrix.h"

TEST_CASE("Adding 4*4 matrices together.", "[Matrix]") {
  SECTION("Using the + operator.") {

    // Arrange

    Matrix4 m{
        0, 1, 2, 3,
        4, 5, 6, 7,
        8, 9, 10, 11,
        12, 13, 14, 15
    };

    Matrix4 n{
        15, 14, 13, 12,
        11, 10, 9, 8,
        7, 6, 5, 4,
        3, 2, 1, 0
    };

    // Act

    Matrix4 r = m + n;

    // Assert

    // All coefficients of matrix r should be 15.
    REQUIRE((r.data[0]==15 && r.data[1]==15 && r.data[2]==15 && r.data[3]==15 &&
        r.data[4]==15 && r.data[5]==15 && r.data[6]==15 && r.data[7]==15 &&
        r.data[8]==15 && r.data[9]==15 && r.data[10]==15 && r.data[11]==15 &&
        r.data[12]==15 && r.data[13]==15 && r.data[14]==15 && r.data[15]==15));

    // All coefficients of matrix m should have stayed the same.
    REQUIRE((m.data[0]==0 && m.data[1]==1 && m.data[2]==2 && m.data[3]==3 &&
        m.data[4]==4 && m.data[5]==5 && m.data[6]==6 && m.data[7]==7 &&
        m.data[8]==8 && m.data[9]==9 && m.data[10]==10 && m.data[11]==11 &&
        m.data[12]==12 && m.data[13]==13 && m.data[14]==14 && m.data[15]==15));

    // All coefficients of matrix n should have stayed the same.
    REQUIRE((n.data[0]==15 && n.data[1]==14 && n.data[2]==13 && n.data[3]==12 &&
        n.data[4]==11 && n.data[5]==10 && n.data[6]==9 && n.data[7]==8 &&
        n.data[8]==7 && n.data[9]==6 && n.data[10]==5 && n.data[11]==4 &&
        n.data[12]==3 && n.data[13]==2 && n.data[14]==1 && n.data[15]==0));
  }

  SECTION("Using the += operator.") {

    // Setup

    Matrix4 m{
        0, 1, 2, 3,
        4, 5, 6, 7,
        8, 9, 10, 11,
        12, 13, 14, 15
    };

    Matrix4 n{
        15, 14, 13, 12,
        11, 10, 9, 8,
        7, 6, 5, 4,
        3, 2, 1, 0
    };

    // Act

    m += n;

    // Assert

    // All coefficients of matrix m should be 15.
    REQUIRE((m.data[0]==15 && m.data[1]==15 && m.data[2]==15 && m.data[3]==15 &&
        m.data[4]==15 && m.data[5]==15 && m.data[6]==15 && m.data[7]==15 &&
        m.data[8]==15 && m.data[9]==15 && m.data[10]==15 && m.data[11]==15 &&
        m.data[12]==15 && m.data[13]==15 && m.data[14]==15 && m.data[15]==15));

    // All coefficients of matrix n should have stayed the same.
    REQUIRE((n.data[0]==15 && n.data[1]==14 && n.data[2]==13 && n.data[3]==12 &&
        n.data[4]==11 && n.data[5]==10 && n.data[6]==9 && n.data[7]==8 &&
        n.data[8]==7 && n.data[9]==6 && n.data[10]==5 && n.data[11]==4 &&
        n.data[12]==3 && n.data[13]==2 && n.data[14]==1 && n.data[15]==0));
  }

}

TEST_CASE("Subtracting 4*4 matrices from each other.", "[Matrix4]") {
  SECTION("Using the - operator.") {

    // Arrange

    Matrix4 m{
        15, 14, 13, 12,
        11, 10, 9, 8,
        7, 6, 5, 4,
        3, 2, 1, 0
    };

    Matrix4 n{
        15, 14, 13, 12,
        11, 10, 9, 8,
        7, 6, 5, 4,
        3, 2, 1, 0
    };

    // Act

    Matrix4 r = m - n;

    // Assert

    // All coefficients of matrix r should be 0.
    REQUIRE((r.data[0]==0 && r.data[1]==0 && r.data[2]==0 && r.data[3]==0 &&
        r.data[4]==0 && r.data[5]==0 && r.data[6]==0 && r.data[7]==0 &&
        r.data[8]==0 && r.data[9]==0 && r.data[10]==0 && r.data[11]==0 &&
        r.data[12]==0 && r.data[13]==0 && r.data[14]==0 && r.data[15]==0));

    // All coefficients of matrix m should have stayed the same.
    REQUIRE((m.data[0]==15 && m.data[1]==14 && m.data[2]==13 && m.data[3]==12 &&
        m.data[4]==11 && m.data[5]==10 && m.data[6]==9 && m.data[7]==8 &&
        m.data[8]==7 && m.data[9]==6 && m.data[10]==5 && m.data[11]==4 &&
        m.data[12]==3 && m.data[13]==2 && m.data[14]==1 && m.data[15]==0));

    // All coefficients of matrix n should have stayed the same.
    REQUIRE((n.data[0]==15 && n.data[1]==14 && n.data[2]==13 && n.data[3]==12 &&
        n.data[4]==11 && n.data[5]==10 && n.data[6]==9 && n.data[7]==8 &&
        n.data[8]==7 && n.data[9]==6 && n.data[10]==5 && n.data[11]==4 &&
        n.data[12]==3 && n.data[13]==2 && n.data[14]==1 && n.data[15]==0));
  }

  SECTION("Using the -= operator.") {

    // Arrange

    Matrix4 m{
        15, 14, 13, 12,
        11, 10, 9, 8,
        7, 6, 5, 4,
        3, 2, 1, 0
    };

    Matrix4 n{
        15, 14, 13, 12,
        11, 10, 9, 8,
        7, 6, 5, 4,
        3, 2, 1, 0
    };

    // Act

    m -= n;

    // Assert

    // All coefficients of matrix m should be 0.
    REQUIRE((m.data[0]==0 && m.data[1]==0 && m.data[2]==0 && m.data[3]==0 &&
        m.data[4]==0 && m.data[5]==0 && m.data[6]==0 && m.data[7]==0 &&
        m.data[8]==0 && m.data[9]==0 && m.data[10]==0 && m.data[11]==0 &&
        m.data[12]==0 && m.data[13]==0 && m.data[14]==0 && m.data[15]==0));

    // All coefficients of matrix n should have stayed the same.
    REQUIRE((n.data[0]==15 && n.data[1]==14 && n.data[2]==13 && n.data[3]==12 &&
        n.data[4]==11 && n.data[5]==10 && n.data[6]==9 && n.data[7]==8 &&
        n.data[8]==7 && n.data[9]==6 && n.data[10]==5 && n.data[11]==4 &&
        n.data[12]==3 && n.data[13]==2 && n.data[14]==1 && n.data[15]==0));
  }
}

// Matrix4 multiplication.
TEST_CASE("Multiplying a 4*4 matrix by another 4*4 matrix.", "[Matrix4]") {
  SECTION("Using the * operator.") {

    // Arrange

    Matrix4 m{
        0, 1, 2, 3,
        4, 5, 6, 7,
        8, 9, 10, 11,
        12, 13, 14, 15
    };

    Matrix4 n{
        15, 14, 13, 12,
        11, 10, 9, 8,
        7, 6, 5, 4,
        3, 2, 1, 0
    };

    // Act

    Matrix4 r = m * n;

    // Assert

    // Coefficients of matrix r should be:
    // 34	28	22	16
    // 178	156	134	112
    // 322	284	246	208
    // 466	412	358	304
    REQUIRE((r.data[0]==34 && r.data[1]==28 && r.data[2]==22 && r.data[3]==16 &&
        r.data[4]==178 && r.data[5]==156 && r.data[6]==134 && r.data[7]==112 &&
        r.data[8]==322 && r.data[9]==284 && r.data[10]==246 && r.data[11]==208 &&
        r.data[12]==466 && r.data[13]==412 && r.data[14]==358 && r.data[15]==304));

    // All coefficients of matrix m should have stayed the same.
    REQUIRE((m.data[0]==0 && m.data[1]==1 && m.data[2]==2 && m.data[3]==3 &&
        m.data[4]==4 && m.data[5]==5 && m.data[6]==6 && m.data[7]==7 &&
        m.data[8]==8 && m.data[9]==9 && m.data[10]==10 && m.data[11]==11 &&
        m.data[12]==12 && m.data[13]==13 && m.data[14]==14 && m.data[15]==15));

    // All coefficients of matrix n should have stayed the same.
    REQUIRE((n.data[0]==15 && n.data[1]==14 && n.data[2]==13 && n.data[3]==12 &&
        n.data[4]==11 && n.data[5]==10 && n.data[6]==9 && n.data[7]==8 &&
        n.data[8]==7 && n.data[9]==6 && n.data[10]==5 && n.data[11]==4 &&
        n.data[12]==3 && n.data[13]==2 && n.data[14]==1 && n.data[15]==0));
  }
}

// Vector3 magnitude.
TEST_CASE("Calculating the magnitude of a 3d vector.", "[Vector3]") {

  // Arrange

  Vector3 v{3, 4, 5};

  // Act

  double magnitude = v.length();

  // Assert

  // Vector magnitude should be 7.0710678118654755
  REQUIRE(magnitude == 7.0710678118654755);

  // Vector v should have stayed (3,4,5).
  REQUIRE((v.data[0]==3 && v.data[1]==4 && v.data[2]==5));
}

// Vector3 normalizing.
TEST_CASE("Normalizing a 3d vector.", "[Vector3]") {

  // Arrange

  Vector3 v{3, 4, 5};
  Vector3 w{};

  SECTION("Normalizing a non-zero magnitude 3d vector.") {

    // Act

    Vector3 u = v.normalize();

    // Assert

    // Vector u should be (0.42426406871192851,0.56568542494923801,0.70710678118654746).
    REQUIRE((u.data[0] == 0.42426406871192851 && u.data[1] == 0.56568542494923801 && u.data[2] == 0.70710678118654746));

    // Vector v should have stayed (3,4,5).
    REQUIRE((v.data[0]==3 && v.data[1]==4 && v.data[2]==5));
  }
}

// Vector3 dot product.
TEST_CASE("Calculating the dot product from two 3d vectors.", "[Vector3]") {

  // Arrange

  Vector3 v{2, 2, 2};
  Vector3 w{-2,-2,-2};

  // Act

  double dot = v.dot(w);

  // Assert

  // The dot product should be -12.
  REQUIRE(dot == -12);

  // Vector v should have stayed (2,2,2).
  REQUIRE((v.data[0]==2 && v.data[1]==2 && v.data[2]==2));

  // Vector w should have stayed (-2,-2,-2).
  REQUIRE((w.data[0]==-2 && w.data[1]==-2 && w.data[2]==-2));
}

// Vector3 cross product.
TEST_CASE("Calculating the cross product from two 3d vectors.", "[Vector3]") {

  // Arrange

  Vector3 v{2, 2, 2};
  Vector3 w{-2,-2,-2};

  // Act

  Vector3 u = cross(v, w);

  // Assert

  // Vector u should be (0,0,0).
  REQUIRE((u.data[0]==0 && u.data[1]==0 && u.data[2]==0));

  // Vector v should have stayed (2,2,2).
  REQUIRE((v.data[0]==2 && v.data[1]==2 && v.data[2]==2));

  // Vector w should have stayed (-2,-2,-2).
  REQUIRE((w.data[0]==-2 && w.data[1]==-2 && w.data[2]==-2));
}