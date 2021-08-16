#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isOp(string c)
    {
        if(c=="+" || c=="-"|| c=="*"|| c=="/")
            return true;
        return false;
    }
    int cn(string c)
    {
        return stoi(c);
    }
    int op(string s,int a,int b)
    {
        char c=s[0];
        switch(c)
        {
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            case '/':
                return a/b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a,b;
        for(auto i:tokens)
        {
            if(!isOp(i))
            {
                st.push(cn(i));
            }
            else{
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                st.push(op(i,a,b));
            } 
        }
        int res=st.top();
        st.pop();
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<string>> test_cases={
        {"4","13","5","/","+"},
        {"10","6","9","3","+","-11","*","/","*","17","+","5","+"}
    };
    for(int i=0;i<test_cases.size();i++)
    {
        cout<<i+1<<": "<<s.evalRPN(test_cases[i])<<"\n";
    }
    return 0;
}