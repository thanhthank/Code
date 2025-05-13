#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[1005];
bool visit[1005];
int parents[1005];
bool check;

void dfs(int u)
{
    visit[u] = true;

    for (int i : v[u])
    {
        if (!visit[i])
        {
            parents[i] = u;
            dfs(i);
        }
        else if (i != parents[u])
        {
            check = true;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            v[i].clear();
        memset(visit, false, sizeof(visit));
        check = false;

        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visit[i])
            {
                parents[i] = -1;
                dfs(i);
            }
        }

        cout << (check ? "YES" : "NO") << endl;
    }
    return 0;
}
