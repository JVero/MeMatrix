#include <vector>
#include <assert.h> 

template<typename T>
struct row {
  int r;
  int c;
  row<T>(int r, int c, std::vector<T> &data) : r(r), c(c), data(data){};
  *T operator[](int val){ return *data[r*c + val]; }
  private:
     std::vector<T> *data;
  public:
};

template<typename T>
class matrix {
public:
  matrix();
  matrix(const matrix &mat);
  matrix(int rows, int columns);
  matrix operator+(const matrix &right) const;
  matrix operator+(const int &val) const;

  matrix operator-(const matrix &right) const;
  matrix operator-(const int &val) const;

  matrix operator*(const matrix &right);
  matrix operator/(const matrix &right);
  
  row<T> operator[](int rw) const ;

  T get(int r, int c);
  int rows() { return r; }
  int cols() { return c; }

private:
  const int r, c;
  //TODO make this std::vecotr<int> valules
  std::vector<int> values;
};
