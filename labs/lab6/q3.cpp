#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,k;
    cin>>n>>k;
    unordered_map<ll,int>set;
    unordered_set<ll>s;
    vector<bool>seen;
    vector<ll> arr;
    ll temp;
    for(int i=0;i<n;i++)
        {
            cin>>temp;
            arr.push_back(temp);
        }
    sort(arr.begin(),arr.end());
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        set[arr[i]]+=1;
        s.insert(arr[i]);
        see
    }
    unordered_set<ll>::iterator it=s.begin();
    for(auto i:s)
    {
        if(set[i-k]!=0)
        {
            count+=set[i-k]*set[i];
        }
    }
    cout<<count;
    return 0;
}