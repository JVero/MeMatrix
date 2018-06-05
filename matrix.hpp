#pragma once

#include <vector>
#include <assert.h> 

template<typename T>
struct row {
  int r;
  int c;
  row<T>(int r, int c, std::vector<T> data) : r(r), c(c), data(data){};
  T& operator[](int val){ return data[r*c + val]; }
  private:
     std::vector<T> data;
};

template<typename T>
class matrix {
public:
  matrix(); // Default constructor
  matrix(const matrix &mat); // Default Copy
  matrix(int rows, int columns); // Initializes zero matrix

  // Defined operator overflows
  matrix<T> operator+( matrix<T> right) ;
  matrix<T> operator+( int val) ;

  matrix operator-( matrix &right) const;
  matrix operator-( int &val) const;

  matrix operator*(const matrix &right);
  matrix operator/(const matrix &right);
  
  row<T>& operator[](int rw)  ;

  T get(int r, int c);
  int rows() { return r; }
  int cols() { return c; }

private:
  const int r, c;
  //TODO make this std::vecotr<int> valules
  std::vector<int> values;
};
