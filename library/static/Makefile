CXXFLAGS = -O2

all: foo usera

debug: CXXFLAGS = -DDEBUG -g -O0
debug: foo user

clean:
	-rm foo.a foo.o user.o user

foo:
	g++ -c $(CXXFLAGS) foo.cpp -o foo.o
	ar cr foo.a foo.o

user:
	g++ -c $(CXXFLAGS) user.cpp -o user.o
	g++ -o user user.o -L. foo.a


