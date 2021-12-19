#include <iostream>
#include "foo.h"

int main() {
	int input;
	std::cin >> input;
	int result = square(input);

	std::cout << "Square: " << result << std::endl;
}

