#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int check(int middle,vector<ll>ar, int n, int m)
{
    ll sum;
    int d=0;
    sum=0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] > middle)
            return false;
        sum=sum+ar[i];
        if (sum>middle)
        {
            d++;
            sum = ar[i];
        }
    }
    d++;
    if (d <= m)
        return 1;
    return 0;
}
ll candies(vector<ll>arr, int n, int m)
{
    ll min_val = *max_element(arr.begin(), arr.end());
    ll max_val = 0;
 
    for (int i = 0; i < n; i++) {
        max_val=max_val+arr[i];
    }
    ll res=0;
    while(min_val<=max_val)
    {
        ll mid=(min_val+max_val)/2;
        if (check(mid,arr,n,m))
        {
            res=mid;
            max_val=mid-1;
        }
        else {
            min_val=mid+1;
        }
    }
    return res;
}
int main() {
    int n,m;
    cin>>n;
    vector<ll>arr;
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cin>>m;
    cout<<candies(arr,n,m)<<endl;
}