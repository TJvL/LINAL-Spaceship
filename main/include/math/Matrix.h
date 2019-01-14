#pragma once
#include <type_traits>
#include <algorithm>
#include <array>
#include <numeric>
#include <cassert>
#include <cmath>

template<size_t row, size_t col, class T>
class Matrix;
template<class T>
class Matrix<1, 1, T>;
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator*(T, Matrix<row, col, T>);
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator*(Matrix<row, col, T>, T);

template<size_t row, size_t col, class T>
Matrix<row, col, T> operator/(Matrix<row, col, T>, T);

template<size_t row, size_t col, size_t colr, class T>
Matrix<row, colr, T> operator*(const Matrix<row, col, T> &, const Matrix<col, colr, T> &);

template<size_t row, size_t col, class T>
Matrix<row, col, T> operator+(Matrix<row, col, T>, const Matrix<row, col, T> &);
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator+(Matrix<row, col, T>, const Matrix<1, 1, T> &);
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator+(const Matrix<1, 1, T> &, Matrix<row, col, T>);
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator+(Matrix<row, col, T>, T);
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator+(T, Matrix<row, col, T>);

template<size_t row, size_t col, class T>
Matrix<row, col, T> operator-(Matrix<row, col, T>, const Matrix<row, col, T> &);
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator-(Matrix<row, col, T>, const Matrix<1, 1, T> &);
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator-(const Matrix<1, 1, T> &, Matrix<row, col, T>);
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator-(Matrix<row, col, T>, T);
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator-(T, Matrix<row, col, T>);

template<size_t row, size_t col, class T>
bool operator==(const Matrix<row, col, T> &, const Matrix<row, col, T> &);
template<size_t row, size_t col, class T>
bool operator!=(const Matrix<row, col, T> &, const Matrix<row, col, T> &);

template<class T>
bool operator==(const Matrix<1, 1, T> &, T);
template<class T>
bool operator==(T, const Matrix<1, 1, T> &);
template<class T>
bool operator!=(const Matrix<1, 1, T> &, T);
template<class T>
bool operator!=(T, const Matrix<1, 1, T> &);

template<size_t row, size_t col, class T>
class Matrix {
 public:
  constexpr static const size_t cols = col;
  constexpr static const size_t rows = row;
  constexpr static const size_t size = row*col;
  constexpr static const bool is_vector = (cols==1 || rows==1);
  using value_type = T;
  static_assert(rows > 0, "rows moet groter zijn dan 0");
  static_assert(cols > 0, "cols moet groter zijn dan 0");
  static_assert(std::is_arithmetic_v<T>, "T moet numeriek zijn.");
 private:
 public:

  template<typename ...Args, std::enable_if_t<(sizeof...(Args) <= size)> * = nullptr>
  Matrix(Args ...args) : data{std::forward<Args>(args)...} {
  }

  static Matrix null_matrix() {
    return Matrix{};
  }

  Matrix(const Matrix &) = default;
  Matrix(Matrix &&) = default;
  Matrix &operator=(const Matrix &) = default;
  Matrix &operator=(Matrix &&) = default;

  friend bool operator==<row, col, T>(const Matrix<row, col, T> &, const Matrix<row, col, T> &);
  friend bool operator!=<row, col, T>(const Matrix<row, col, T> &, const Matrix<row, col, T> &);

 public:
  std::array<T, size> data;
  friend Matrix operator*<row, col, T>(Matrix, T);
  friend Matrix operator*<row, col, T>(T, Matrix);

  friend Matrix operator/<row, col, T>(Matrix, T);

  friend Matrix operator+<row, col, T>(Matrix, const Matrix &);
  friend Matrix operator+<row, col, T>(Matrix, const Matrix<1, 1, T> &);
  friend Matrix operator+<row, col, T>(const Matrix<1, 1, T> &, Matrix);
  friend Matrix operator+<row, col, T>(Matrix, T);
  friend Matrix operator+<row, col, T>(T, Matrix);

  friend Matrix operator-<row, col, T>(Matrix, const Matrix &);
  friend Matrix operator-<row, col, T>(Matrix, const Matrix<1, 1, T> &);
  friend Matrix operator-<row, col, T>(const Matrix<1, 1, T> &, Matrix);
  friend Matrix operator-<row, col, T>(Matrix, T);
  friend Matrix operator-<row, col, T>(T, Matrix);

  Matrix &operator+=(T value) {
    std::for_each(data.begin(), data.end(), [&value](auto &data) { data += value; });
    return *this;
  }
  Matrix &operator+=(const Matrix &value) {
    for (size_t idx = 0; idx < size; ++idx) {
      data[idx] += value.data[idx];
    }

    return *this;
  }

  Matrix &operator-=(T value) {
    std::for_each(data.begin(), data.end(), [&value](auto &data) { data -= value; });
    return *this;
  }
  Matrix &operator-=(const Matrix &value) {
    for (size_t idx = 0; idx < size; ++idx) {
      data[idx] -= value.data[idx];
    }

    return *this;
  }

  Matrix &operator*=(T value) {
    std::for_each(data.begin(), data.end(), [&value](auto &data) { data *= value; });
    return *this;
  }
  Matrix &operator/=(T value) {
    std::for_each(data.begin(), data.end(), [&value](auto &data) { data /= value; });
    return *this;
  }

  template<size_t rown, size_t coln, size_t colr, typename Tn>
  friend Matrix<rown, colr, Tn> operator*(const Matrix<rown, coln, Tn> &, const Matrix<coln, colr, Tn> &);

  void set(size_t n, T val) {
    data.at(n) = val;
  }

  Matrix<cols, rows, T> transpose() const {
    Matrix<cols, rows, T> matrix{};

    for (size_t c = 0; c < cols; ++c) {
      for (size_t r = 0; r < rows; ++r) {
        matrix.data[r*cols + c] = data[c*rows + r];
      }
    }

    return matrix;
  }

  T length() const {
    return std::sqrt(std::accumulate(data.begin(), data.end(), T{}, [](T lhs, T rhs) { return lhs + (rhs*rhs); }));
  }

  Matrix<rows, cols, T> normalize() const {
    Matrix<rows, cols, T> matrix = *this;
    T len = length();
    std::for_each(matrix.data.begin(), matrix.data.end(), [&len](T &scal) mutable { scal /= len; });
    return matrix;
  }

  T dot(Matrix<rows, cols, T> const &rhs) {
    static_assert(((rows==1 && cols > 1) || (rows > 1 && cols==1)), "Dot product only works on vectors.");
    T value{};
    for (size_t idx = 0; idx < size; ++idx) {
      value += data[idx]*rhs.data[idx];
    }
    return value;
  }
};

template<typename T>
void constexpr inplace_dot_product(T *target,
                                   const T *const lhs,
                                   size_t row,
                                   size_t mid,
                                   size_t colr,
                                   const T *const rhs) {
  assert(row > 0);
  assert(mid > 0);
  assert(colr > 0);
  assert(lhs!=nullptr);
  assert(rhs!=nullptr);

  for (size_t r = 0; r < row; ++r) {
    for (size_t c = 0; c < colr; ++c) {
      T val{};
      for (size_t d = 0; d < mid; ++d) {
        val += *(lhs + ((r*mid) + d))**(rhs + (c + (colr*d)));
      }
      *(target++) = val;
    }
  }
}

template<size_t row, size_t col, class T>
bool operator==(const Matrix<row, col, T> &lhs, const Matrix<row, col, T> &rhs) {
  return lhs.data==rhs.data;
};
template<size_t row, size_t col, class T>
bool operator!=(const Matrix<row, col, T> &lhs, const Matrix<row, col, T> &rhs) {
  return !(lhs==rhs);
};

template<size_t row, size_t col, size_t colr, class T>
Matrix<row, colr, T> operator*(const Matrix<row, col, T> &lhs, const Matrix<col, colr, T> &rhs) {
  Matrix<row, colr, T> data{};

  if constexpr ((row==1 && row==colr)) {
    T val{};
    for (size_t i = 0; i < col; ++i) {
      val += lhs.data.at(i)*rhs.data.at(i);
    }
    data.data[0] = val;
  } else if (col==1) {
    T val{};
    for (size_t i = 0; i < row; ++i) {
      val += lhs.data.at(i)*rhs.data.at(i);
    }
    data.data[0] = val;
  } else {
    inplace_dot_product(data.data.data(), lhs.data.data(), row, col, colr, rhs.data.data());

  }
  return data;
}
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator*(Matrix<row, col, T> matrix, T value) {
  std::for_each(matrix.data.begin(), matrix.data.end(), [&value](auto &data) { data *= value.data; });
  return matrix;
}
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator*(T value, Matrix<row, col, T> matrix) {
  std::for_each(matrix.data.begin(), matrix.data.end(), [&value](auto &data) { data *= value.data; });
  return matrix;
}

template<size_t row, size_t col, class T>
Matrix<row, col, T> operator/(Matrix<row, col, T> matrix, T value) {
  std::for_each(matrix.data.begin(), matrix.data.end(), [&value](auto &data) { data /= value.data; });
  return matrix;
}

template<size_t row, size_t col, class T>
Matrix<row, col, T> operator+(Matrix<row, col, T> data, const Matrix<row, col, T> &rhs) {
  for (auto i = 0; i < data.size; ++i) {
    data.data.at(i) += rhs.data.at(i);
  }
  return data;
};
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator+(Matrix<row, col, T> matrix, const Matrix<1, 1, T> &value) {
  std::for_each(matrix.data.begin(), matrix.data.end(), [&value](auto &data) { data -= value.data; });
  return matrix;
};
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator+(const Matrix<1, 1, T> &value, Matrix<row, col, T> matrix) {
  std::for_each(matrix.data.begin(), matrix.data.end(), [&value](auto &data) { data -= value.data; });
  return matrix;
};
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator+(Matrix<row, col, T> matrix, T value) {
  std::for_each(matrix.data.begin(), matrix.data.end(), [&value](auto &data) { data += value; });
  return matrix;
};
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator+(T value, Matrix<row, col, T> matrix) {
  std::for_each(matrix.data.begin(), matrix.data.end(), [&value](auto &data) { data += value; });
  return matrix;
};

template<size_t row, size_t col, class T>
Matrix<row, col, T> operator-(Matrix<row, col, T> data, const Matrix<row, col, T> &rhs) {
  for (auto i = 0; i < data.size; ++i) {
    data.data.at(i) -= rhs.data.at(i);
  }
  return data;
};
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator-(Matrix<row, col, T> matrix, const Matrix<1, 1, T> &value) {
  std::for_each(matrix.data.begin(), matrix.data.end(), [&value](auto &data) { data -= value.data; });
  return matrix;
};
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator-(const Matrix<1, 1, T> &value, Matrix<row, col, T> matrix) {
  std::for_each(matrix.data.begin(), matrix.data.end(), [&value](auto &data) { data -= value.data; });
  return matrix;
};
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator-(Matrix<row, col, T> matrix, T value) {
  std::for_each(matrix.data.begin(), matrix.data.end(), [&value](auto &data) { data -= value; });
  return matrix;
};
template<size_t row, size_t col, class T>
Matrix<row, col, T> operator-(T value, Matrix<row, col, T> matrix) {
  std::for_each(matrix.data.begin(), matrix.data.end(), [&value](auto &data) { data -= value; });
  return matrix;
};

template<typename T>
T dot_product(const T *const lhs, size_t row, size_t mid, size_t colr, const T *const rhs) {
  T val{};
  for (size_t d = 0; d < mid; ++d) {
    val += *(lhs + ((row*mid) + d))**(rhs + (mid + (colr*d)));
  }
  return val;
}

template<class T>
class Matrix<1, 1, T> {
 public:
  constexpr static const size_t cols = 1;
  constexpr static const size_t rows = 1;
  constexpr static const size_t size = 1;
  using value_type = T;
  static_assert(std::is_arithmetic_v<T>, "T moet numeriek zijn.");
 private:
 public:
  explicit Matrix(T arg) : data{std::forward<T>(arg)} {
  }

  operator T() const { return data; }

  //inline bool operator==(const Matrix& m) const {
  //	return data == m.data;
  //}
  //
  //inline bool operator!=(const Matrix& m) const {
  //	return !(*this == m);
  //}
  T data;

  friend bool operator==<T>(const Matrix &, T);
  friend bool operator==<T>(T, const Matrix &);
  friend bool operator!=<T>(const Matrix &, T);
  friend bool operator!=<T>(T, const Matrix &);

  friend Matrix operator*<T>(Matrix, T);
  friend Matrix operator*<T>(T, Matrix);

  friend Matrix operator+<T>(Matrix, const Matrix &);
  friend Matrix operator+<T>(Matrix, T);
  friend Matrix operator+<T>(T, Matrix);

  friend Matrix operator-<T>(Matrix, const Matrix &);
  friend Matrix operator-<T>(Matrix, T);
  friend Matrix operator-<T>(T, Matrix);

  Matrix &operator+=(T value) {
    for (auto &scal : data) {
      data += value;
    }
    return *this;
  }

  Matrix &operator+=(const Matrix &value) {
    data += value.data;
    return *this;
  }

  Matrix &operator-=(T value) {
    data -= value;
    return *this;
  }

  Matrix &operator-=(const Matrix &value) {
    data += value.data;
    return *this;
  }

  template<size_t rown, size_t coln, size_t colr, typename Tn>
  friend Matrix<rown, colr, Tn> operator*(const Matrix<rown, coln, Tn> &, const Matrix<coln, colr, Tn> &);

  void set(size_t n, T val) {
    data.at(n) = val;
  }

  T length() {
    return data;
  }
};

template<class T>
Matrix<1, 1, T> operator*(Matrix<1, 1, T> matrix, T value) {
  matrix.data += value;
  return matrix;
}
template<class T>
Matrix<1, 1, T> operator*(T value, Matrix<1, 1, T> matrix) {
  matrix.data *= value;
  return matrix;
}
template<class T>
Matrix<1, 1, T> operator*(const Matrix<1, 1, T> &lhs, const Matrix<1, 1, T> &rhs) {
  return Matrix<1, 1, T>{lhs.data*rhs.data};
}

template<class T>
Matrix<1, 1, T> operator+(Matrix<1, 1, T> matrix, const Matrix<1, 1, T> &value) {
  matrix.data += value.data;
  return matrix;
};
template<class T>
Matrix<1, 1, T> operator+(Matrix<1, 1, T> matrix, T value) {
  matrix.data += value;
  return matrix;
};
template<class T>
Matrix<1, 1, T> operator+(T value, Matrix<1, 1, T> matrix) {
  matrix.data += value;
  return matrix;
};

template<class T>
Matrix<1, 1, T> operator-(Matrix<1, 1, T> matrix, const Matrix<1, 1, T> &value) {
  matrix.data -= value.data;
  return matrix;
};
template<class T>
Matrix<1, 1, T> operator-(Matrix<1, 1, T> matrix, T value) {
  matrix.data -= value;
  return matrix;
};
template<class T>
Matrix<1, 1, T> operator-(T value, Matrix<1, 1, T> matrix) {
  matrix.data -= value;
  return matrix;
};

template<class T>
bool operator==(const Matrix<1, 1, T> &matrix, T value) {
  return matrix.data==value;
};
template<class T>
bool operator==(T value, const Matrix<1, 1, T> &matrix) {
  return matrix==value;
};
template<class T>
bool operator!=(const Matrix<1, 1, T> &matrix, T value) {
  return !(matrix==value);
};
template<class T>
bool operator!=(T value, const Matrix<1, 1, T> &matrix) {
  return !(matrix==value);
};

template<size_t row, size_t col, class T, typename = std::enable_if_t<((row==3 && col==1) || (row==1 && col==3)),
                                                                      Matrix<row, col, T>>>
Matrix<row, col, T> cross(Matrix<row, col, T> const &lhs, Matrix<row, col, T> const &rhs) {
  return {
      lhs.data[1]*rhs.data[2] - lhs.data[2]*rhs.data[1],
      lhs.data[0]*rhs.data[2] - lhs.data[2]*rhs.data[0],
      lhs.data[0]*rhs.data[1] - lhs.data[1]*rhs.data[0]};
}

template<size_t row, size_t col, class T, typename = std::enable_if_t<((row==1 && col==3) || (row==3 && col==1)),
                                                                      Matrix<row, col, T>>>
Matrix<row, col, T> cross(Matrix<row, col, T> const &lhs, Matrix<col, row, T> const &rhs) {
  return {
      lhs.data[1]*rhs.data[2] - lhs.data[2]*rhs.data[1],
      lhs.data[0]*rhs.data[2] - lhs.data[2]*rhs.data[0],
      lhs.data[0]*rhs.data[1] - lhs.data[1]*rhs.data[0]};
}

template<size_t col, class T> using row_vector = Matrix<1, col, T>;
template<size_t row, class T> using col_vector = Matrix<row, 1, T>;
template<size_t row, class T> using vector = Matrix<row, 1, T>;

using Vector3 = Matrix<3, 1, double>;
using Vector4 = Matrix<4, 1, double>;
using Matrix3 = Matrix<3, 3, double>;
using Matrix4 = Matrix<4, 4, double>;

Vector4 toVector4(Vector3 const &vector3);

Vector3 fromVector4(Vector4 const &vector4);