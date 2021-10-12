#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll count_nodes(ll root,ll n)
{
        ll child=root+1;
        ll val=0;
        ll count=0;
        for(;root <= n;)
        {
            val=count+min(child, n+1);
            count=val-root;
            root=root*10;
            child=child*10;
        }
        return count;
}
    ll dfs(ll root, ll n, ll k)
    {
        if (!k)
            return root;
        ll next=root+1;
        ll count=count_nodes(root,n);
        ll root_S=root*10;
        if(count<=k)
        {
            return dfs(next,n,k-count);
        }
        else
        {
            return dfs(root_S,n,k-1);
        }
    }
int main()
{
    ll n,k;
    cin>>n>>k;
    cout<<dfs(1,n,k-1);
    return 0;
}