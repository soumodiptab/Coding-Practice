#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll min_difference(vector<pair<ll,ll>>arr)
{
    if(arr.size()<2)
        return 0;
    sort(arr.begin(),arr.end());
    ll diff=abs(arr[0].second-arr[1].second);
    for(int i=1;i<arr.size()-1;i++)
    {
        if(abs(arr[i].second-arr[i+1].second)<diff)
            diff=abs(arr[i].second-arr[i+1].second);
    }
    return diff;
}
int main()
{
    ll t,n;
    ll temp;
        vector<pair<ll,ll>>arr;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            arr.push_back(make_pair(temp,i));
        }
        cout<<min_difference(arr);
    return 0;
}