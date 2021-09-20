#include<bits/stdc++.h>
using namespace std;
int solve(vector<pair<int,int>>&arr,int sub,int problems)
{
    
}
int main()
{
    vector<pair<int,int>> arr;
    // n - no. of submissions m - no. of problems
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int temp1,temp2;
        cin>>temp1>>temp2;
        arr.push_back(make_pair(temp1,temp2));
    }
    cout<<solve(arr,n,m)<<endl;
    return 0;
}