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

string max_joltage_helper(map<pair<int, int>, string> &dp, const string &bank, int start, int depth)
{
    if (depth == 0 || start >= bank.length() || depth > bank.length() - start)
        return "";

    if (dp.find({start, depth}) != dp.end())
        return dp[{start, depth}];

    dp[{start, depth}] = max(
        bank[start] + max_joltage_helper(dp, bank, start + 1, depth - 1),
        max_joltage_helper(dp, bank, start + 1, depth));

    return dp[{start, depth}];
}

string max_joltage(const string &bank, int depth)
{
    map<pair<int, int>, string> dp;
    return max_joltage_helper(dp, bank, 0, depth);
}

ll part1()
{
    ifstream input("../data/3.txt");
    string line;
    ll res = 0;

    while (getline(input, line))
    {
        string a = max_joltage(line, 2);
        // DEBUG(a);
        res += stoll(a);
    }

    return res;
}

ll part2()
{
    ifstream input("../data/3.txt");
    string line;
    ll res = 0;

    while (getline(input, line))
    {
        string a = max_joltage(line, 12);
        // DEBUG(a);
        res += stoll(a);
    }

    return res;
}