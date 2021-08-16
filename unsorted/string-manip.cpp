#include<bits/stdc++.h>
using namespace std;

    char getMaxOccuringChar(string &str)
    {
        // Your code here
        map<char,int>freq;
        for(auto &c:str)
        {
                freq[c]++;
                c=c+1;
        }
        pair<char,int> max;
        for(auto c:freq)
        {
            if(c.second>max.second)
                max=c;
        }
        return max.first;
    }
    void print_formatter(string &x){
        for(auto &i:x){
            i=toupper(i);
            cout<<i<<'\n';
        }
    }

int main()
{
    string x;
    getline(cin,x);
    //cout<<getMaxOccuringChar(x)<<'\n';
    cout<<x<<'\n';
    print_formatter(x);
    return 0;
}