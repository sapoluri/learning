all: foo user
clean:
	-rm foo.so foo.o user.o user

foo:
	g++ -c foo.cpp -o foo.o
	g++ -shared -fPIC -o foo.so foo.o

user:
	g++ -c user.cpp -o user.o
	g++ user.o foo.so -o user


