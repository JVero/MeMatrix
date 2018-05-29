#include "matrix.cpp"

void test_mat_init() {
	auto mat = matrix(4, 5);
}

void test_mat_add() {
	auto m1 = matrix(4, 5);
	auto m2 = matrix(4, 5);
	m1 + m2;
}

int main() {
	test_mat_add();
	
	auto m = matrix(4,4);
	cout << "\n";
	cout << m[1][0] << endl;
	return 0;
}
