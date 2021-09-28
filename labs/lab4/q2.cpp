#include<bits/stdc++.h>
using namespace std;
void string_game(string s,int k)
{
    int counter=0;
    stack<char>res;
    for(char c:s)
    {
        counter=1;
        while(!res.empty() && res.top()==c)
        {
            res.pop();
            counter++;
        }
        if(counter<k)
        {
            while(counter--)
                res.push(c);
        }
    }
    string fin;
    while(!res.empty()){
        fin.insert(0,1,res.top());
        res.pop();
    }
    cout<<fin;
}
int main()
{
    int k;
    string s;
    cin>>s;
    cin>>k;
    string_game(s,k);
    return 0;
}