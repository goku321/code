#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findSmallestNonConstructible(vector<int> v) {
    int maxConstructible = 0;
    int vectorSize = v.size();
    sort(v.begin(), v.end());

    for(int i=0; i<vectorSize; ++i) {
        if(maxConstructible+1 >= v[i]) {
            maxConstructible += v[i];
        } else {
            break;
        }
    }

    return maxConstructible + 1;
}

int main() {
    vector<int> v = {1, 2, 4};
    int smallestNonConstructible = findSmallestNonConstructible(v);
    cout << smallestNonConstructible << endl;
}