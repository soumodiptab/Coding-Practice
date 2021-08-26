#include<bits/stdc++.h>
using namespace std;

int c0;

int tot(int x, int y, int stm)
{
    // stm is steps to move
    if(stm==0)
    {
        if(x==0 && y==0)c0++;
        return 1;
    }
    int ans=0;
    ans+=tot(x+1,y,stm-1);
    ans+=tot(x,y+1,stm-1);
    if(x>0)ans+=tot(x-1,y,stm-1);
    if(y>0)ans+=tot(x,y-1,stm-1);
    // cout<<x<<" "<<y<<" "<<ans<<endl;;
    return ans;
}


int main()
{
    int i,j,k,l,m;
    c0=0;
    int  ans=tot(0,0,6);
    cout<<c0<<"/"<<ans<<endl;c0=0;
    ans=tot(0,0,8);
    cout<<c0<<"/"<<ans;
    return 0;
}