#include "foo.h"

int square(int num) { //declared as extern "C" in header to avoid C++ name mangling
	return num*num;
}
