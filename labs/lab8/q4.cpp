#include <bits/stdc++.h>
using namespace std;
class graph
{
    int nodes;
    int edges;
    vector<bool> visited;
    stack<int> st;
    /**
     * Adjaceny list representation:
     * 
     */
    vector<vector<pair<int, int>>> weights;

public:
    graph(int nodes)
    {
        this->nodes = nodes;
        this->edges = 0;
        weights = vector<vector<pair<int, int>>>(nodes + 1);
        visited = vector<bool>(nodes + 1, false);
    }
    void dfs(int source)
    {
        visited[source] = true;
        for (pair<int, int> e : weights[source])
        {
            if (visited[e.second] == false)
                dfs(e.second);
        }
    }
    void add_edge(int u, int v)
    {
        weights[u].push_back(make_pair(1, v));
        edges++;
    }
    void dfs_pre(int source)
    {
        visited[source] = true;
        for (pair<int, int> e : weights[source])
        {
            if (visited[e.second] == false)
                dfs_pre(e.second);
        }
        st.push(source);
    }
    int solver(int n)
    {
        int counter = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false)
                dfs_pre(i);
        }
        visited = vector<bool>(n + 1, false);
        while (st.size() != 0)
        {
            int source = st.top();
            st.pop();
            if (visited[source]==false)
            {
                dfs(source);
                counter = counter + 1;
            }
        }
        return counter;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        cin >> m;
        graph g(n);
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a;
            cin >> b;
            g.add_edge(a, b);
        }
        cout << g.solver(n);
    }
    return 0;
}