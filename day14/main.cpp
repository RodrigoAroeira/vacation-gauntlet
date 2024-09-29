// failed compiles:
// failed runs:
// time taken:

#include <array>
#include <cstddef>
#include <type_traits>

template <typename T, size_t Rows, size_t Cols>
using matrix_t = std::array<std::array<T, Cols>, Rows>;

template <typename T, size_t Rows, size_t Cols> class Matrix {
public:
  Matrix(matrix_t<T, Rows, Cols> matrix) : m_matrix(matrix) {}

  Matrix(){};

  std::array<T, Rows> &operator[](size_t idx) { return m_matrix[idx]; }

  const std::array<T, Rows> &operator[](size_t idx) const {
    return m_matrix[idx];
  }

  auto add(const Matrix &other) const {
    Matrix<T, Rows, Cols> newMatrix;

    for (size_t i = 0; i < Rows; i++) {
      for (size_t j; j < Cols; j++) {
        newMatrix[i][j] = m_matrix[i][j] + other.m_matrix[i][j];
      }
    }
    return newMatrix;
  }

  auto mult(const int num) const {
    Matrix<T, Rows, Cols> newMatrix;

    for (size_t i = 0; i < Rows; i++) {
      for (size_t j; j < Cols; j++) {
        newMatrix[i][j] = m_matrix[i][j] * num;
      }
    }
    return newMatrix;
  }

  template <size_t OtherCols>
  Matrix<T, Rows, OtherCols> mult(const Matrix<T, Cols, OtherCols> &other) {
    Matrix<T, Rows, OtherCols> newMatrix;

    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < OtherCols; ++j) {
        for (size_t k = 0; k < Cols; ++k) {
          newMatrix[i][j] += m_matrix[i][k] * other[k][j];
        }
      }
    }
    return newMatrix;
  }

private:
  static_assert(std::is_same<T, int>::value || std::is_same<T, float>::value,
                "Matrix can only be instantiated with int or float.");

  matrix_t<T, Rows, Cols> m_matrix{{0}};
};
