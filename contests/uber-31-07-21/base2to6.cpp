#include<bits/stdc++.h>
using namespace std;
vector<int> base2To6Hire2020(vector<bool> base2) {
    __int128 num=0;
    for(int i=base2.size()-1;i>=0;i--)
    {
        num=num*2;
        if(base2[i]==true)
           num=num+1; 
    }
    vector<int> base6;
    if(num==0)
        base6.push_back(0);
    while(num!=0)
    {
        int i=num%6;
        base6.push_back(i);
        num=num/6;
    }
    return base6;
}

int main(){
    base2To6Hire2020({false,true,false,false});
    return 0;
}