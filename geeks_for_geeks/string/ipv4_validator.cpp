#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<string> tokenizer(string &s){
            vector<string> tokens;
            stringstream ss(s);
            string i;
            while(getline(ss,i,'.'))
            {
                tokens.push_back(i);
            }
            return tokens;
        }
        int isValid(string s) {
            vector<string> t=tokenizer(s);
            if(t.size()!=4)
                return 0;
            for(auto i:t)
            {
                int val;
                stringstream ss(i);
                ss>>val;
                if(!(val>=0&&val<=255))
                    return 0;
            }
            return 1;
        }
};

int main(){
    Solution s=Solution();
    vector<string> testcases={
        "127.0.0.1",
        "0.0.0.1",
        "3..23",
        "...",
        "0.0.0.1"
    };
    for(auto i:testcases)
        cout<<s.isValid(i)<<'\n';
}