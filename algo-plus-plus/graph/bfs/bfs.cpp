#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void add_edge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T source)
    {
        //maintain a visited map
        map<T, bool> visited;
        queue<T> q;
        vector<T> traversal;
        q.push(source);
        visited[source] = true;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            traversal.push_back(node);
            for (int adj : l[node])
            {
                if (!visited[adj])
                {
                    q.push(adj);
                    visited[adj] = true;
                }
            }
        }
        for (auto t : traversal)
            cout << t << " ";
        cout << endl;
    }
};
int main()
{
    Graph<int> g;
    g.add_edge(1, 2);
    g.add_edge(0, 1);
    g.add_edge(0, 3);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 5);
    g.bfs(0);
    return 0;
}