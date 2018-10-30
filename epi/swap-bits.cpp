#include<iostream>

using namespace std;

long swapBits(long x, short i, short j) {
    if(((x>>i)&1) != ((x>>j)&1)) {
        unsigned long bitMask = (1L << i | 1L << j);
        x ^= bitMask;
    }

    return x;
}

int main() {
    cout << swapBits(4, 0, 2) << endl;
    return 0;
}