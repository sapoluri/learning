#include <iostream>
#include <cstring>
#include <cstddef>

using namespace std;

class ShapeNoVirt {
        private:
        int a;
};

class Shape {
        private:
        int a;

        public:
        virtual int area() = 0;
};

class Circle : public Shape {
        public:
        int area() {
                return 1221;
        }
};


int main() {
        //size of 4 = sizeof(int)
        cout << "Size ShapeNoVirt "<< sizeof(ShapeNoVirt) << endl;

        //size of 16 = sizeof(vtable_ptr) i.e 8 + sizeof(a) i.e 4 + padding of 4 bytes
        cout << "Size Shape "<< sizeof(Shape) << endl;

        Shape* a = new Circle();
        cout << a->area() << endl;
        //override the first 8 bytes i.e the vtable pointer
        memset(a, 0, 8);
        //try to call the function after the vtable has been zeroed out
        cout << a->area() << endl;
}
