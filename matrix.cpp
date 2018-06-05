
#include "matrix.hpp"
#include <vector>

// Default constructor
template <typename T>
matrix<T>::matrix()
    : r(3)
    , c(3)
    , std::vector<T>(9, 0){};

// Blank initializer
template <typename T>
matrix<T>::matrix(unsigned r, unsigned c)
    : r(r)
    , c(c)
    , values(std::vector<T>(r * c, 0)){};

// Copy constructor
template <typename T>
matrix<T>::matrix(matrix<T> const& old)
    : r(old.r)
    , c(old.c)
    , values(old.values){};

// Overload [] operator to return a "row object"
template <typename T>
T& matrix<T>::operator()(unsigned r, unsigned c)
{
    assert(r <= this->r && c <= this->c);
    return this->values[r * c + c];
}

template <typename T>
matrix<T> matrix<T>::operator+(matrix<T> right) const
{
    matrix<T> ret(right);
    for (auto i = 0; i < this->r; ++i) {
        for (auto j = 0; j < this->c; ++j) {
            ret(i, j) += right(i, j);
        }
    }
    return ret;
}

template <typename T>
matrix<T> matrix<T>::operator-(matrix<T>& right) const
{
    matrix<T> ret(right);
    for (auto i = 0; i < this->r; ++i) {
        for (auto j = 0; j < this->c; ++j) {
            ret(i, j) -= right(i, j);
        }
    }
    return ret;
}
