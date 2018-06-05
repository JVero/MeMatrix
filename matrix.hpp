#pragma once

#include <assert.h>
#include <vector>

template <typename T>
class matrix {
public:
    matrix(); // Default constructor
    matrix(const matrix& mat); // Default Copy
    matrix(unsigned rows, unsigned columns); // Initializes zero matrix

    // Defined operator overflows
    matrix<T> operator+(matrix<T> right) const;
    matrix<T> operator+(int val) const;

    matrix operator-(matrix& right) const;
    matrix operator-(int& val) const;

    matrix operator*(const matrix& right);

    T& operator()(unsigned r, unsigned c);

private:
    const unsigned r, c;
    //TODO make this std::vecotr<int> valules
    std::vector<int> values;
};
