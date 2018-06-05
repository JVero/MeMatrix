#pragma once

#include <vector>
#include <assert.h> 


template<typename T>
class matrix {
public:
  matrix(); // Default constructor
  matrix(const matrix &mat); // Default Copy
  matrix(int rows, int columns); // Initializes zero matrix

  // Defined operator overflows
  matrix<T> operator+( matrix<T> right) const ;
  matrix<T> operator+( int val) const ;

  matrix operator-( matrix &right) const;
  matrix operator-( int &val) const;

  matrix operator*(const matrix &right);
  
  T& operator()(unsigned r, unsigned c);
  
  T get(int r, int c);
  int rows() { return r; }
  int cols() { return c; }

private:
  const int r, c;
  //TODO make this std::vecotr<int> valules
  std::vector<int> values;
};
