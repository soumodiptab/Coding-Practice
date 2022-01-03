#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Hash map representation
 * 
 */
class Graph
{
    unordered_map<string, list<pair<string, int>>> l;

public:
/**
 * @brief adds an edge
 * 
 * @param x source 
 * @param y destination
 * @param bi bidirectional
 * @param weight distance/cost
 */
    void add_edge(string x, string y, bool bi, int weight)
    {
        l[x].push_back(make_pair(y, weight));
        if (bi)
        {
            l[y].push_back(make_pair(x, weight));
        }
    }
    /**
     * @brief print list repr
     * 
     */
    void print()
    {
        for (auto ele : l)
        {
            string source = ele.first;
            cout << source << " | ";
            list<pair<string, int>> neighbours = ele.second;
            for (auto n : neighbours)
            {
                string dest = n.first;
                int distance = n.second;
                cout << " " << dest << "[" << distance << "]"
                     << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g;
    g.add_edge("A", "B", true, 20);
    g.add_edge("B", "D", true, 40);
    g.add_edge("A", "C", true, 10);
    g.print();
    return 0;
}