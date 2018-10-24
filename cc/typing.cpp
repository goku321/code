#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

bool hand[26];

int main() {
    int t;
    cin >> t;
    hand['d'-97] = 0;
    hand['f'-97] = 0;
    hand['j'-97] = 1;
    hand['k'-97] = 1;
    
    while(t--) {
        int n;
        cin >> n;
        vector<string> words;
        string word;
        map<string, float> freq;

        for(int i=0; i<n; ++i){
            cin >> word;
            words.push_back(word);
        }

        float totalTime = 0;

        for(int i=0; i<n; ++i) {
            word = words[i];
            if(freq.find(word)!=freq.end()) {
                totalTime += freq[word]/2;
                continue;
            }

            float localTime = 0;
            localTime += 0.2;

            for(int j=1; j<word.length(); ++j) {
                if(hand[word[j]-97] == hand[word[j-1]-97])
                    localTime += 0.4;
                else    
                    localTime += 0.2;
            }
            freq.insert(pair<string, float>(word, localTime));
            totalTime += localTime;
        }

        cout << int(totalTime*10)<< endl;
    }
    return 0;
}