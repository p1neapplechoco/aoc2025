#include <bits/stdc++.h>

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

bool is_accessible(vector<string> &grid, int r, int c)
{
    // // 4 corners
    // if (r == 0 && c == 0)
    //     return true;

    // if (r == 0 && (c == grid[0].length() - 1))
    //     return true;

    // if ((r == grid.size() - 1) && c == 0)
    //     return true;

    // if ((r == grid.size() - 1) && (c == grid[0].length() - 1))
    //     return true;

    int count = 0;

    for (int i = ((r > 0) ? -1 : 0); i <= ((r < grid.size() - 1) ? 1 : 0); i++)
        for (int j = ((c > 0) ? -1 : 0); j <= ((c < grid[0].length() - 1) ? 1 : 0); j++)
        {
            if (i == 0 && j == 0)
                continue;

            if (grid[r + i][c + j] == '@')
                count++;
        }

    return count < 4;
}

ll part1()
{
    ifstream input("../data/4.txt");
    string line;
    ll res = 0;

    vector<string> grid;
    while (getline(input, line))
    {
        grid.push_back(line);
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].length(); j++)
        {
            if (!(grid[i][j] == '@'))
                continue;
            if (is_accessible(grid, i, j))
            {
                // grid[i][j] = 'X';
                res++;
            }
        }
    }

    // for (int i = 0; i < grid.size(); i++)
    // {
    //     cout << grid[i] << endl;
    // }

    return res;
}

ll part2()
{
    ifstream input("../data/4.txt");
    string line;
    ll res = 0;

    vector<string> grid;
    while (getline(input, line))
    {
        grid.push_back(line);
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].length(); j++)
        {
            if (!(grid[i][j] == '@'))
                continue;
            if (is_accessible(grid, i, j))
            {
                grid[i][j] = '.';
                i = 0;
                j = 0;
                res++;
                continue;
            }
        }
    }

    // for (int i = 0; i < grid.size(); i++)
    // {
    //     cout << grid[i] << endl;
    // }

    return res;
}