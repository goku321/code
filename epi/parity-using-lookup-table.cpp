#include<iostream>

using namespace std;

typedef unsigned long ul;

unsigned short LOOKUP_SIZE = 16;
short parityLookup[65536];

short parityUsingXor(ul x) {
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    return x & 0x1;
}

void initializeParityLookup() {
    for(ul i=0; i<65536; ++i) {
        parityLookup[i] = parityUsingXor(i);
        //cout << sizeof(i) << endl;
    }
}

short parityUsingLookup(ul x) {
    const int wordSize = 16;
    const int bitMask = 0xFFFF;

    return parityLookup[x >> (3 * wordSize)] ^
           parityLookup[(x >> (2 * wordSize)) & bitMask] ^
           parityLookup[(x >> wordSize) & bitMask] ^
           parityLookup[x & bitMask];
}

int main() {
 initializeParityLookup();
 ul inputWord;
 while(cin>>inputWord) {
     cout << parityUsingLookup(inputWord) << endl;
 }
 return 0;
}