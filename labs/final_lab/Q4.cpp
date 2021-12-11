#include <bits/stdc++.h>
using namespace std;
#define long long long int
const long MOD = 1e9 + 7;
#include <bits/stdc++.h>
using namespace std;
class graph
{
    int n;
    int m;

public:
    unordered_map<int, unordered_set<pair<int, long>>> list;
    graph(int n)
    {
        this->n = n;
        this->m = 0;
    }
    graph(int n, int m)
    {
        this->m = m;
        this->n = n;
    }
    void add_edge(int u, int v, int w)
    {
        list[u].insert(make_pair(v, w));
        list[v].insert(make_pair(u, w));
        m++;
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
vector<pair<long, pair<long, long>>> special;

int main()
{
    long n, m;
    cin >> n >> m;
    graph g(n);
    vector<long> city_cost;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        city_cost.push_back(temp);
    }
    vector<vector<long>> grid(n + 1, vector<long>(n, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                grid[i][j] = city_cost[i - 1] + city_cost[j - 1];
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        long temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        if(grid[temp1][temp2]> temp3)
        {
            grid[temp1][temp2]=temp3;
            grid[temp2][temp1]=temp3;
        }
        
    }
    vector<pair<long,pair<long,long>>>new_graph;
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < abc.size)

        return 0;
}