#include<iostream>

using namespace std;

typedef unsigned long ul;

ul findNearestIntegerWithSameWeight(ul x) {
    int numOfBits = 64;

    for(int i=0; i<numOfBits-1; ++i) {
        if((x>>i & 1) != (x>>(i+1) & 1)) {
            ul bitMask = (1UL << i) | (1UL << (i+1));
            x ^= bitMask;
            return x;
        }
    }
}

int main() {
    ul x;
    while(cin>>x) {
        cout<<findNearestIntegerWithSameWeight(x) << endl;
    }
    return 0;
}