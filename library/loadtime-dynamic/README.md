foo.cpp -> contains the definition of library function
foo.h -> contains the declaration of library function
g++ -c foo.cpp -o foo.o
g++ -shared -fPIC -o foo.so foo.o //fPIC - position independent (relocatable) code,
				  //shared indicates this is library without a starting address
				  //for execution i.e main. This is in contrast to 
				  //an executable object, which has a starting address.

user.cpp -> code that uses the library function.
g++ -c user.cpp -o user.o

g++ user.o foo.so -o user // user now contains symbol table info to access code and data in foo.so at run time

ldd user //will show all shared libs it depends on.
	//linux-vdso.so (virtual dynamic shared object) is the dynamic runtime linker
	// of other dynamic libs.

When you execute user the following happens:
The loader loads the executable code, and transfers control to the dynamic linker (linux-vdso.so - virtual dynamic shared object), which maps the shared libs into program's address space and then starts execution at main. As such, this is called Load Time Dynamic Linking, as opposed to runtime dynamic linking (dlopen, dlsym, dlclose).

Very important info about debug info in an object file:
when you compile with -g option the output object file will have debug info
g++ -g -c foo.cpp -o foo.o
you can easily remove that symbol table without recompile using:
strip foo.o



