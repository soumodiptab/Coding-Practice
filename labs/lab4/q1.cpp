#include<bits/stdc++.h>
using namespace std;
int triplet_sum(vector<int> arr,int target)
{
    int count=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++)
    {
        if(i!=0 && arr[i]==arr[i-1])
        {
            continue;
        }
        if(arr[i]>target)
            break;
        for(int j=i+1;j<arr.size();j++)
        {

            if(j!=i+1 && arr[j]==arr[j-1])
            {
                continue;
            }
            if(arr[i]+arr[j]>target)
                break;
            for(int k=j+1;k<arr.size();k++)
            {
                if(k!=j+1 && arr[k]==arr[k-1])
                continue;
                int sum=arr[i]+arr[j]+arr[k];
                if(sum>target)
                    break;
                else if(sum==target)
                {
                    count++;
                }
            }
        }
    }
    return count;
}
int main()
{
    int t,n,temp,k;
    cin>>t;
    while(t--)
    {
        vector<int>arr;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            arr.push_back(temp);
        }
        cin>>k;
        cout<<triplet_sum(arr,k)<<endl;
    }
    return 0;
}