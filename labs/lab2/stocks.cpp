// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int main()
 {
     int n,target;
     vector<int>arr;
     cin>>n;
     for(int i=0;i<n;i++)
     {
         int t;
         cin>>t;
         arr.push_back(t);
     }
     cin>>target;
     int sum,days,min_days=INT_MAX;
     if(n==1 && arr[0]>=target)
        min_days=1;
     for(int i=0;i<n-1;i++)
     {
         days=1;
         sum=arr[i];
         if(sum>=target)
         {
             min_days=min(min_days,days);
         }
         for(int j=i+1;j<n;j++)
         {
             ++days;
             sum+=arr[j];
             if(sum>=target)
             {
                 min_days=min(min_days,days);
                 break;
             }
         }
     }
     if(min_days==INT_MAX)
         cout<<-1;
     else
        cout<<min_days;
     return 0;
}