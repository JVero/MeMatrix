#include<vector>
class matrix {
public:
  matrix(){};
  matrix(int, int);
  matrix operator+(matrix &right)const ;
  matrix operator-(const matrix &right);
  matrix operator*(const matrix &right);
  matrix operator/(const matrix &right);
  std::vector<int>  operator[](int r) const;
  int get(int r, int c);
  int rows() {return r;}
  int cols() {return c;}
private:
  int r, c;
  std::vector< std::vector<int> > values;
};
