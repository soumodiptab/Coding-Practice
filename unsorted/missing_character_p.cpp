//Missing characters to make a string Pangram
#include<bits/stdc++.h>
using namespace std;
    class Panagram{
        private:
        bool storeFlag=false;
        map<char,int>charStore;
        void flush(){
            Panagram();
        }
        void store(string &str){
            if(storeFlag==true)
                flush();
            storeFlag=true;
            for(auto i:str){
                charStore[toupper(i)]++;
            }
        }
        public:
        Panagram(){
            for(char i='A';i<='Z';i++)
            {
                charStore[i]=0;
            }
        }
        bool isPanagram(string &str){
            bool flag=true;
            store(str);
            for(auto c:charStore){
                if(c.second==0){
                    flag=false;
                    break;
                }
            }
            return flag;
        }
        string missingPanagram(string &str){
            store(str);
            string missing;
            for(auto c:charStore){
                if(c.second==0)
                    missing.push_back(c.first);
            }
            return missing;
        }
    };
    bool isAnagram(char a[], char b[]){
    bool flag=true;
    // Your code here
    map<char,int> as,bs;
    for(int i=0;i<strlen(a);i++)
        as[a[i]]++;
    for(int i=0;i<strlen(b);i++)
        bs[b[i]]++;
    map<char,int>::iterator i=as.begin();
    map<char,int>::iterator j=bs.begin();
    for(;(i!=as.end())&&(j!=bs.end());i++,j++)
        if(*i!=*j){
            flag=false;
            break;
        }
        if(i!=as.end()||j!=bs.end())
            flag=false;
        return flag;
}

int main()
{
    string x;
    char s1[]="geeksforgeeks";
    char s2[]="geeksgeeksfor";
    //getline(cin,x);
    //cout<<getMaxOccuringChar(x)<<'\n';
    //Panagram p=Panagram();
    //cout<<p.isPanagram(x)<<'\n';
    //cout<<p.missingPanagram(x)<<'\n';
    cout<<isAnagram(s1,s2)<<'\n';
    return 0;
}