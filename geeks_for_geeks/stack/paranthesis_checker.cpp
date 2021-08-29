// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    //char ar2[]={,,};
    bool ispar(string x)
    {
        char ar1[]={'{','[','('};
        char ar2[]={'}',']',')'};
        // Your code here
        stack<char>s;
        for(char c:x)
        {
            for(int i=0;i<3;i++)
                if(ar2[i]==c)
                {
                    if(s.empty() || s.top()!=ar1[i])
                        return false;
                    else
                    {
                        s.pop();
                        continue;
                    }
                }
            for(int i=0;i<3;i++)
                if(ar1[i]==c)
                {
                    s.push(c);
                    continue;
                }
        }
        if(s.empty())
            return true;
        return false;
    }
};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends