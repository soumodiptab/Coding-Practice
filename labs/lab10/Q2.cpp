#include <bits/stdc++.h>
using namespace std;
class graph
{
    int n;
    int m;

public:
    unordered_map<int, unordered_set<int>> list;
    graph(int m, int n)
    {
        this->m = m;
        this->n = n;
    }
    void add_edge(int u, int v)
    {
        list[u].insert(v);
        list[v].insert(u);
    }
    int nodes()
    {
        return n;
    }
    int edges()
    {
        return m;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    graph g = graph(m, n);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }
    /**
     * @brief 
     * a -> b -> c ->a
     * 
     */
    int cycle = 0;
    for (int i = 0; i < g.nodes(); i++)
    {
        int a = i;
        for (auto j : g.list[a])
        {
            int b = j;
            for (auto k : g.list[b])
            {
                int c = k;
                if (g.list[a].count(b) && g.list[b].count(c) && g.list[c].count(a))
                {
                    cycle++;
                }
            }
        }
    }
    cycle /= 6;
    cout << cycle;
    return 0;
}
