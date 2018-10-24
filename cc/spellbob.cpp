#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

typedef pair<char, char> pc;

int main() {
    int t;

    scanf("%d", &t);

    while(t--) {
        string s1, s2;
        cin >> s1;
        cin >> s2;

        // Create a frequency array
        int arr[4] = {0};

        vector<pc> v;
        v.push_back(make_pair(s1[0], s2[0]));
        v.push_back(make_pair(s1[1], s2[1]));
        v.push_back(make_pair(s1[2], s2[2]));

        for(int i = 0; i < v.size(); ++i) {
            if((v[i].first == 'b' && v[i].second == 'b'))
                arr[0] += 1;

            else if((v[i].first == 'o' && v[i].second == 'b') || (v[i].first == 'b' && v[i].second == 'o'))
                arr[2] += 1;
            
            else if(v[i].first == 'o' && v[i].second == 'o')
                arr[1] += 1;
            
            else if(v[i].first == 'b' || v[i].second == 'b')
                arr[0] += 1;
            
            else if(v[i].first == 'o' || v[i].second == 'o')
                arr[1] += 1;

            else
                arr[3] += 1;
        }

        if (arr[0] == 3 || arr[1] >=2 || arr[3])
            printf("%s", "no");
        else
            printf("%s", "yes");
        cout<<endl;
    }

    return 0;
}