#include<bits/stdc++.h>
using namespace std;
pair<int,int> compute(map<int,int> &scanner)
{
    map<int,int>::iterator i=scanner.begin();
    pair<int,int> max=*i;
    ++i;
    for(;i!=scanner.end();i++)
    {
        if((*i).second>max.second)
        max=*i;
    }
    return max;
}
int main(){
    int k,n,x,temp;
    vector<int> array;
    map<int,int> scanner;
    cin>>n;
    pair<int,int> y;
    while(n--)
    {
        cin>>temp;
        array.push_back(temp);
        scanner[temp]=0;
    }
    cin>>k;
    do{
        if(array[0]>array[1])
        {
            x=array[1];
            scanner[array[0]]++;
            array.erase(array.begin()+1);
        }
        else
        {
            x=array[0];
            scanner[array[1]]++;
            array.erase(array.begin());
        }
        array.push_back(x);
        y=compute(scanner);
    }
    while(y.second!=k);
    cout<<y.first;
    return 0;
}