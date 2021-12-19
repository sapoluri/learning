#ifndef __FOO_H__
#define __FOO_H__
extern "C" int square(int num); //extern is used to avoid C++ name mangling the function,
				//so we can extract the function in user.cpp using the name square
#endif //__FOO_H__
