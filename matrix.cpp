
#include "matrix.hpp"
#include<vector>
#include<memory>

template<typename T>
matrix<T>::matrix(): r(3), c(3), std::vector<T>(9, 0) {};

template<typename T>
matrix<T>::matrix(int r, int c): r(r), c(c), values(std::vector<T>(r*c, 0)){};

template<typename T>
matrix<T>::matrix(matrix<T> const&old): r(old.r), c(old.c), values(old.values) {};

template<typename T>
row<T>& matrix<T>::operator[](int r) {
	row<T> rw(r, this->c, this->values);
	return rw;
}

template<typename T>
matrix<T> matrix<T>::operator+(matrix<T> right){
	matrix<T> ret(right);
	for (auto i = 0; i < this->r; ++i) {
	  for (auto j = 0; j < this->c; ++j) {
	    ret[i][j] += right[i][j];
	  }
	}
	return ret;
}
