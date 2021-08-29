#include<bits/stdc++.h>
#define ll long long
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //-----------------------------------------------------------------------------------
    //Optimized version
    //Next greater element to the left
    vector<ll>NSL(vector<ll> arr, int n){
        // Your code here
        stack<ll>s;
        vector<ll>v;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && s.top()>=arr[i])
                s.pop();
            v.push_back((s.empty())?-1:s.top());
            s.push(arr[i]);
        }
        return v;
    }
    //Next greater element to the right
    vector<ll>NSR(vector<ll> arr, int n){
        // Your code here
        stack<ll>s;
        vector<ll>v;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top()>=arr[i])
                s.pop();
            v.push_back((s.empty())?-1:s.top());
            s.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        cout<<"NSL:"<<endl;
        vector <long long> res = obj.NSL(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
        cout<<"NSR:"<<endl;
        vector <long long> res = obj.NSR(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends