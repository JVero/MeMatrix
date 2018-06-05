#include "matrix.hpp"
#include <iostream>
#include <vector>

// empty matrix
template<typename T>
matrix<T>::matrix(int rows, int columns)
    : r(rows), c(columns),
      values(std::vector<T>(rows*columns, 0)){
      std::cout << "Vector initialized with " << rows << " rows and " << columns
       << " columns." << std::endl;
};

template<typename T>
matrix<T>::matrix(const matrix &mat) : r(mat.r), c(mat.c), values(mat.values) {}

template<typename T>
T matrix<T>::get(int row, int col) { return this->values[row*c+col]; }


template<typename T>
row<T> matrix<T>::operator[](int rw)  { return row<T>{rw, this->c,  &this->values};};

template<typename T>
matrix<T> matrix<T>::operator+(const int &val) const {
  matrix ret(*this);
  // Not using iterators because I need the indices, in addition to the values
  for (auto i = 0; i < this->r; ++i) {
    for (auto j = 0; j < this->c; ++j) {
      ret[i] [j] = this->values[i][j] + val;
    }
  }
  return ret;
}

template<typename T>
matrix<T> matrix<T>::operator+(const matrix &right) const {
  assert(this->r == right.r && this->c == right.c);
  //matrix ret(*this);
  matrix ret(this->r, this->c);
  // Not using iterators because I need the indices, 
  // in addition to the values
  for (auto i = 0; i < this->r; ++i) {
    for (auto j = 0; j < this->c; ++j) {
      ret[i][j] = this[i][j] + right[i][j];
    }
  }
  return ret;
}

template<typename T>
matrix<T> matrix<T>::operator-(const matrix &right) const {
  assert(this->r == right.r && this->c == right.c);
  matrix ret(*this);
  // Not using iterators because I need the indices,
  // in addition to the values
  for (auto i = 0; i < this->r; ++i) {
    for (auto j = 0; j < this->c; ++j) {
      ret[i][j] = this->values[i][j] - right[i][j];
    }
  }

  return ret;
}
