// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to remove consecutive duplicates from given string using Stack.
    /*string removeConsecutiveDuplicates(string s)
    {
        //without using stack
        string y;
        for(int i=0;i<s.size();)
        {
            y.push_back(s[i]);
            int j=i+1;
            while(j<s.size() && s[j]==s[i])
                j++;
            i=j;
        }
        return y;
    }*/
    //remove pairs 
    string removeConsecutiveDuplicates(string x)
    {
        //using stack
        stack<char>s;
        string y;
        for(char c:x)
        {
            if(!s.empty() && c==s.top())
            {
                s.pop();
            }
            else
                s.push(c);
        }
        while(!s.empty())
        {
            y.push_back(s.top());
            s.pop();
        }
        reverse(y.begin(),y.end());
        return y;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends