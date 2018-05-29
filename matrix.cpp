#include "matrix.hpp"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// empty matrix
matrix::matrix(int rows, int columns)
    : r(rows), c(columns),
      values(vector<vector<int>>(rows, vector<int>(columns, 0))) {
  cout << "Vector initialized with " << rows << " rows and " << columns
       << " columns." << endl;
}

int matrix::get(int r, int c) { return this->values[r][c]; }

std::vector<int> matrix::operator[](int row) const { return this->values[row]; }

matrix matrix::operator+(matrix &right) const {
  matrix ret(4, 5);
  if (this->r == right.r && this->c == right.c) {
    for (auto i = 0; i < this->r; ++i) {
      for (auto j = 0; j < this->c; ++j) {
        ret[i][j] = this->values[i][j] + right[i][j];
      }
    }
  }
  return ret;
}
