#include <bits/stdc++.h>
#include <deque>

using namespace std;

#define DEBUG(var) \
    (std::cout << "[DEBUG]: " << #var << " = " << (var) << '\n')

typedef long long ll;
typedef unsigned long long ull;

ll part1();
ll part2();

int main()
{
    cout << part1() << endl;
    cout << part2() << endl;
}

ll part1()
{
    ifstream input("../data/7.txt");
    string line;
    ll res = 0;

    vector<string> grid;

    while (getline(input, line))
    {
        grid.push_back(line);
    }

    ll start_pos = 0;
    for (ll i = 0; i < grid[0].size(); i++)
    {
        if (grid[0][i] == 'S')
        {
            start_pos = i;
            break;
        }
    }

    stack<pair<ll, ll>> st;
    st.push({start_pos, 1});

    while (!st.empty())
    {
        auto [x, y] = st.top();
        st.pop();

        if (y >= grid.size() || x < 0 || x >= grid[0].size() || grid[y][x] == '|')
        {
            continue;
        }

        if (grid[y][x] == '^')
        {
            res++;
            st.push({x - 1, y});
            st.push({x + 1, y});
            continue;
        }
        else
        {
            st.push({x, y + 1});
        }

        grid[y][x] = '|';
    }

    return res;
}

ll count_path(vector<string> &grid, map<pair<ll, ll>, ll> &dp, ll x, ll y)
{
    if (x < 0 || x >= grid[0].size())
    {
        return 0;
    }

    if (y >= grid.size())
    {
        return 1;
    }

    if (dp.find({x, y}) != dp.end())
    {
        return dp[{x, y}];
    }

    if (grid[y][x] == '^')
    {
        ll left = count_path(grid, dp, x - 1, y);
        ll right = count_path(grid, dp, x + 1, y);
        dp[{x, y}] = left + right;
    }
    else
    {
        dp[{x, y}] = count_path(grid, dp, x, y + 1);
    }

    return dp[{x, y}];
}

ll part2()
{
    ifstream input("../data/7.txt");
    string line;
    ll res = 0;

    vector<string> grid;

    while (getline(input, line))
    {
        grid.push_back(line);
    }

    ll start_pos = 0;
    for (ll i = 0; i < grid[0].size(); i++)
    {
        if (grid[0][i] == 'S')
        {
            start_pos = i;
            break;
        }
    }

    map<pair<ll, ll>, ll> dp;
    res = count_path(grid, dp, start_pos, 1);

    return res;
}