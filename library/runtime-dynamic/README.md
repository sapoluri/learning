foo.cpp -> contains the definition of library function
foo.h -> contains the declaration of library function
g++ -c foo.cpp -o foo.o
g++ -shared -fPIC -o foo.so foo.o //fPIC - position independent (relocatable) code,
				  //shared indicates this is library without a starting address
				  //for execution i.e main. This is in contrast to 
				  //an executable object, which has a starting address.

user.cpp -> code that loads the library and calls the function
g++ -c user.cpp -o user.o

g++ user.o -ldl -o user // user links to libdl.so which contains the symbols for dlopen, dlsym, dlclose. executable has no knowledge of dynamic lib at linking step.

ldd user //will not show foo.so because it's a runtime dependence.

nm foo.so -> When declared as C++ function, the symbol was _Z6squarei (C++ compiler's way of uniquely describing the function declaration to help with function overloading). When declared as extern "C", the symbol is square because function names in C must be unique. No function overloading is possible.

What about loading a C++ class?
You create a C factory function for creating a new instance of the class and another for destroying the instance
https://tldp.org/HOWTO/html_single/C++-dlopen/


Use of Function Pointers:
1. For calling functions in a loaded plugin
2. Callback function pointer
