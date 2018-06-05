/*
 * This file is a proxy for a test-file.  I have not used any testing library yet
 */

#include <iostream>
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
	m(1, 0) += 4;
	
	auto n = m + m;
	auto k = m - n;
	std::cout << "\n";
	std:: cout << m(1, 0) << std::endl;
	return 0;
}
