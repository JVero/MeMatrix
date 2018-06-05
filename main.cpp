/*
 * This file is a proxy for a test-file.  I have not used any testing library yet
 */


#include "matrix.cpp"

void test_mat_init() {
	auto mat = matrix<int>(4, 5);
}

matrix<int> test_mat_add() {
	auto m1 = matrix<int>(4, 5);
	auto m2 = matrix<int>(4, 5);
	return m1 + m2;
}

int main() {
	test_mat_add();
	auto m = matrix<int>(4,4);
	cout << "\n";
	cout << m[1][0] << endl;
	return 0;
}
