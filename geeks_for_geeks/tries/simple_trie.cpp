#include<bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * 
 */
class trie_node
{
    public:
    trie_node* child[26]={};
    bool is_end;
    trie_node()
    {
        is_end=false;
    }
};
trie_node *root=new trie_node();
bool search_key(string key)
{
    trie_node *current=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(current->child[index]==NULL)
            return false;
        current=current->child[index];
    }
    return current->is_end;
}
void insert_key(string key)
{
    trie_node *current=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(current->child[index]==NULL)
            current->child[index]=new trie_node();
        current=current->child[index];
    }
    current->is_end=true;
}
bool is_node_empty(trie_node *temp)
{
    for(int i=0;i<26;i++)
    {
        if(temp->child[i]!=NULL)
            return false;
    }
    return true;
}

/**
 * @brief There are mainly 3 cases:
 * @param current 
 * @param key 
 * @param i 
 * @return trie_node* 
 */
trie_node* delete_key(trie_node *current,string key,int i)
{
    if(current==NULL)
    {
        return NULL;
    }
    if(i==key.length())//reached end of string
    {
        current->is_end=false;
        if(is_node_empty(current))//if node is empty then delete it
        {
            delete(current);
            return NULL;
        }
        return current;//if not then just set is_end false and return same node
    }
    int index=key[i]-'a';
    current->child[index]=delete_key(current->child[index],key,i+1);//recursively traverse the string
    if(is_node_empty(current) && current->is_end==false)
    {
        delete(current);
        return NULL;
    }
    return current;
}
void delete_wrapper(string key)
{
    delete_key(root,key,0);
}
int main()
{
    int choice=0;
    string key;
    while(true)
    {
        cin>>choice;
        switch(choice)
        {
            case 1:
            cin>>key;
            insert_key(key);
            break;
            case 2:
            cin>>key;
            delete_wrapper(key);
            break;
            case 3:
            cin>>key;
            cout<<search_key(key)<<endl;
            case 4:
            exit(0);
            break;
            default:
            break;
        }
    }
    return 0;
}