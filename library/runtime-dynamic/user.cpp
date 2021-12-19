#include <iostream>
#include <dlfcn.h>

int main() {
	void* handle = dlopen("foo.so", RTLD_LAZY); //RTLD_LAZY = load on first reference.

	if (!handle) {
		std::cerr << "Cannot open library: " << dlerror() << std::endl;
		return 1;
	}

	typedef int (*square_t)(int);
	square_t square = (square_t) dlsym(handle, "square");
	const char *dlsym_error = dlerror();
	if (dlsym_error) {
		std::cerr << "Cannot load symbol 'square': " << dlsym_error << std::endl;
		dlclose(handle);
		return 1;
	}

	int input;
	std::cout << "Enter the number you want squared: ";
	std::cin >> input;
	int result = square(input);

	std::cout << "Square: " << result << std::endl;
	dlclose(handle);
}

