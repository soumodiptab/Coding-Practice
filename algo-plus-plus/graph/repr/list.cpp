#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Adjacency List Representation
 * 
 */
class Graph
{
    int V;
    list<int> *l; // pointer to a array of lists
public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    /**
     * @brief adds an edge to graph from node x to y and y to x
     * 
     * @param x - node 1
     * @param y - node 2
     */
    void add_edge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
};
int main()
{
    Graph g(4);
    g.add_edge(2, 3);
    g.add_edge(0, 2);
    //cout << "test";
    char ch = 'a';
    string s = "hello" + to_string('a');
    cout << s << endl;
    return 0;
}