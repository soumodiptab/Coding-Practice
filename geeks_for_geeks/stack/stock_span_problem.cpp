// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//Solution of the problem
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int>sol;
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++)
        {
            if(s.size()==0)
                sol.push_back(-1);
            else if(s.size()>0 && s.top().first>price[i])
                sol.push_back(s.top().second);
            else if(s.size()>0 && s.top().first<=price[i]){
                while(s.size()>0 && s.top().first<=price[i]){
                    s.pop();
                }
                sol.push_back((s.size()==0)?-1:s.top().second);
            }
            s.push(make_pair(price[i],i));
        }
        for(int i=0;i<n;i++)
        {
            sol[i]=i-sol[i];
        }
       // Your code here
       return sol;
    }
    //Optimized version of the code
    vector <int> calculateSpan(int arr[], int n)
    {
        
        vector<int>sol;
        stack<int>s;
        // Here we first find the NGL index of each item in the given vector
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]<=arr[i])
                s.pop();
            sol.push_back((s.empty())?-1:s.top());
            s.push(i);
        }
        //Span of each stock= i-NGL index of[i]
        for(int i=0;i<n;i++)
        {
            sol[i]=i-sol[i];
        }
       // Your code here
       return sol;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends