// Find the no. of distinct max heaps possible
#include<bits/stdc++.h>
#define ll long long int
#define MAX 102
using namespace std;
const ll MOD=1e9+7;
ll nc_cache[MAX][MAX];
void setup()
{
    for(int i=1;i<MAX;i++)
	{
		nc_cache[i][0]=1;
		nc_cache[i][i]=1;
	}
}
ll nck(int n,int k)
{
    if(nc_cache[n][k]==0)
	    nc_cache[n][k] = (nck(n-1,k)+nck(n-1,k-1))%MOD;
    return nc_cache[n][k];
}
//find no. of nodes for left subtree
int find(int n)
{
    int height=log2(n);
    int max=pow(2,height);
    int p=n-max+1;
    if(p>=max/2)
        return max-1;
    int x=max-1-max/2+p;
    return x;
}
//f(n)=(n-1)cl x f(l) x f(r) | n-1=l+r
ll f(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 1;
    int l=find(n);
    ll coefficient=nck(n-1,l);
    ll left=f(l);
    ll right=f(n-1-l);
    ll total=(((coefficient*left)%MOD)*right)%MOD;
    return total;
}

int main()
{
    int keys;
    setup();
    cin>>keys;
    cout<<f(keys);
    return 0;
}