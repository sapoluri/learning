all: foo user
clean:
	-rm foo.a foo.o user.o user

foo:
	g++ -c foo.cpp -o foo.o
	ar cr foo.a foo.o

user:
	g++ -c user.cpp -o user.o
	g++ -o user user.o -L. foo.a


