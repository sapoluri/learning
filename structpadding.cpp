#include <iostream>
#include <cstring>
#include <cstddef>

using namespace std;

class Single {
        private:
        char a;
};

class Multi {
        private:
        int a;
        char b;
};

class packed {
        private:
        char* a;
        int i;
        short b;
        char c;
};

class unpacked {
        public:
        char c;
        char* b;
        short a;
        int i;
};

int main() {
        //size of 1. For single members, no padding added.
        cout << "Size Single "<< sizeof(Single) << endl;

        //size of 8 = Sizeof(int) i.e 4 + sizeof(char) i.e 1 + padding of 3 bytes
        cout << "Size Multi "<< sizeof(Multi) << endl;

        //size of 24 = sizeof(char) i.e 1 + padding of 7 bytes + sizeof(char*) i.e 8 + sizeof(short) i.e 2 + padding of 2 bytes + sizeof(int) i.e 4
        cout << "Size unpacked "<< sizeof(unpacked) << endl;
        cout << "Offsetof char* " << offsetof(unpacked, unpacked::b) << endl;

        //size of 16 = sizeof(char*) i.e 8 + sizeof(int) i.e 4 + sizeof(short) i.e 2 + sizeof(char) i.e 1 + 1 byte padding
        cout << "Size packed "<< sizeof(packed) << endl;
}
