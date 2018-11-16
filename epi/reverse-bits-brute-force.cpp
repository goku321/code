#include<iostream>

using namespace std;

typedef unsigned long ul;

ul reverseBits(ul x) {
    ul ans = 0;
    for(int i=0; i<63; ++i) {
        unsigned y = (x >> i) & 1L;
        ans |= (y << (63-i));
    }

    return ans;
}

int main() {
    ul x;
    while(cin >> x) {
        cout << reverseBits(x) << endl;
    }
    return 0;
}