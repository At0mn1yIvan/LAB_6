#include <iostream>
#include "ChildVector.h"


int main() {
	
	TVector<int> v2{ 1,4,6 };
	TVector<int> v8{ 4,7,8 };
	//std::cout << v2.Angle(v8);
	ChildVector<int> m1(2,2);
	ChildVector<int> m2(2, 2);
	std::cin >> m1;
	std::cin >> m2;
	std::cout << m1 * m2;
	return 0;
} 
