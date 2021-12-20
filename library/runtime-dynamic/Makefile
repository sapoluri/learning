CXXFLAGS = -O2

all: foo user

debug: CXXFLAGS = -DDEBUG -g -O0
debug: foo user

clean:
	-rm foo.so foo.o user.o user

foo:
	g++ -c $(CXXFLAGS) foo.cpp -o foo.o
	g++ -shared -fPIC -o foo.so foo.o

user:
	g++ -c $(CXXFLAGS) user.cpp -o user.o
	g++ user.o -ldl -o user


