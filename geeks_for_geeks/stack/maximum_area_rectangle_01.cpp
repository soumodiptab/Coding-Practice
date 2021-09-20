// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //--------------------------------------------------------------------------------
    //utility function that returns the index of the next smallest element to the left
    vector<int>NSL(vector<int>arr, int n){
        // Your code here
        stack<int>s;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
                s.pop();
            v.push_back((s.empty())?-1:s.top());
            s.push(i);
        }
        return v;
    }
    //Utility function that returns the index of the next smallest element to the right
    vector<int>NSR(vector<int>arr, int n){
        // Your code here
        stack<int>s;
        vector<int>v;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
                s.pop();
            v.push_back((s.empty())?n:s.top()); // here n is the pseudo index to represent extreme right
            s.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }

    //------------------------------------------------------------------------------------
    //Function to find largest rectangular area possible in a given histogram.
    int MAH(vector<int>arr, int n)
    {
        if(n==0)
            return 0;
        vector<int>nsl_index=NSL(arr,n);
        vector<int>nsr_index=NSR(arr,n);
        int area=(nsr_index[0]-nsl_index[0]-1)*arr[0];
        for(int i=1;i<n;i++)
        {
            area=max(area,(nsr_index[i]-nsl_index[i]-1)*arr[i]);
        }
        return area;
    }
    int maxAreaRectangle(vector<vector<int>>arr,int row,int col)
{
    //Here each row is treated like a histogram
    int area=0;
    if(row>0)
        area=MAH(arr[0],col);
    for(int i=1;i< row; i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr[i][j])
                arr[i][j]+=arr[i-1][j];
        }
        area=max(area,MAH(arr[i],col));
    }
    return area;
}
};
// { Driver Code Starts.
vector<vector<int>>test_case={
    {1,1,0,0,0,0},
    {1,1,1,1,1,1},
    {1,1,1,1,1,0},
    {1,1,0,0,0,0}
};

int main()
 {/*
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        */
        Solution ob;
        cout<<ob.maxAreaRectangle(test_case,4,6)<<endl;
    
    //}
	return 0;
}
  // } Driver Code Ends