#include<iostream>

using namespace std;

typedef unsigned long ul;
typedef unsigned short us;

us reverseBitsLookup[65536];

us swapBits(us x, int i, int j) {
    if(((x>>i) & 1) != ((x>>j)&1)) {
        us bitMask = (1L << i) | (1L << j);
        x ^= bitMask;
    }

    return x;
}

us reverseBitsUsingSwap(us x) {
    for(int i=0, j=15; i<j; ++i, --j) {
        x = swapBits(x, i, j);
    }

    return x;
}

void initializeLookup(int n) {
    for(ul i=0; i<n; ++i) {
        reverseBitsLookup[i] = reverseBitsUsingSwap(i);
    }
}

ul reverseBitsUsingLookup(ul x) {
    const int wordSize = 16;
    const int bitMask = 0xFFFF;

    return reverseBitsLookup[x & bitMask] << (3 * wordSize) |
           reverseBitsLookup[(x >> wordSize) & bitMask] << (2 * wordSize) |
           reverseBitsLookup[(x >> (2*wordSize)) & bitMask] << wordSize |
           reverseBitsLookup[(x >> (3*wordSize)) & bitMask];
}

int main() {
    int lookupSize = 65536;
    initializeLookup(lookupSize);
    ul x;
    while(cin >> x) {
        cout << reverseBitsUsingLookup(x) << endl;
    }
    return 0;
}

