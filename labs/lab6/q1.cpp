#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(vector<ll>dates,vector<ll>intervals)
{
    ll y,p;
    vector<ll>diff;
    bool local_flag,flag=false;
    int n=dates.size();
    sort(intervals.begin(),intervals.end());
    int i=1;
    for(i;i<n;i++)
    {
        diff.push_back(dates[i]-dates[i-1]);
    }
    for(i=0;i<intervals.size();i++)
    {
        local_flag=true;
        for(int j=0;j<diff.size();j++)
        {
            if(diff[j]%intervals[i]!=0)
            {
                local_flag=false;
                break;
            }
        }
        if(local_flag)
        {
            p=intervals[i];
            flag=true;
        }
    }
    if(flag)
        cout<<"YES\n"<<dates[0]<<" "<<p<<"\n";
    else
        cout<<"NO\n";
}
int main()
{
    ll n,k,t;
    cin>>t;
    while(t--)
    {
        ll temp;
        vector<ll> dates;
        vector<ll> intervals;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            dates.push_back(temp);
        }
        for(int i=0;i<k;i++)
        {
            cin>>temp;
            intervals.push_back(temp);
        }
        solve(dates,intervals);
    }
    return 0;
}