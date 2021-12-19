foo.cpp -> contains the definition of library function
foo.h -> contains the declaration of library function
g++ -c foo.cpp -o foo.o
ar cr foo.a foo.o //use linux archive tool to convert compiled object file to static library

user.cpp -> code that uses the library function.
g++ -c user.cpp -o user.o

g++ -o user user.o -L. foo.a //This is the linker step. -L. indicates the search path to find foo.a

file foo.a -> current ar archive
file foo.o -> ELF 64-bit LSB (i.e Little Endian for Intel) relocatable

If linking is the same whether it's static library or object file, then why bother?
When you have a large number of object files, you do not want to individually mention which files
to link against. You want to dump them all in a static library (compressed collection of object files)
and link against a single file.

The main thing to remember is the linking is static not at runtime and hence the following applies for a static library:
1. The linking needs to be redone everytime you have new version of static library.
2. Each executable we link into, has it's own copy of the object code.
3. No runtime overhead of symbol lookup since everything is resolved at the time of linking.
4. It is easy to distribute the linked code, since it is self contained. None of the libraries that it linked with need to be provided with it.

Given that each executable will have it's own copy, a static library is not a shared library.


nm foo.a -> lists all the object files included in it. T indicates text section (containing it's code).
		U indicates symbols that are referenced but not defined i.e stuff in a dynamic library
		that it uses.
