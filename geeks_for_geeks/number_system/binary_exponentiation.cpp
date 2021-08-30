#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int MOD=1e9+7;
// The purpose of mod is to ensure large values can be computed
// Iterative version of fast exponentiation to compute power in O(log n)
ll binary_expo(ll x,ll n)// x^n
{
    ll res=1;
    // Traverse all the bits of the number
    while(n>0)
    {
        if(n&1)//if bit is set
            res=(res*x)%MOD;
        x=(x*x)%MOD;
        n>>=1;
    }
    return res;
}
int main()
{
   int t;
   ll a,b;
   cin>>t;
   while(t--)
   {
       cin>>a>>b;
       cout<<binary_expo(a,b)<<endl;
   }
}