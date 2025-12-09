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

bool is_fresh(vector<pair<ll, ll>> &db, ll id)
{
    vector<pair<ll, ll>> to_check;

    for (auto &e : db)
    {
        if (min(id, e.first) == e.first)
            to_check.push_back(e);
    }

    for (auto &e : to_check)
    {
        if (max(id, e.second) == e.second)
            return true;
    }
    return false;
}

ll part1()
{
    ifstream input("../data/5.txt");
    string line;
    ll res = 0;

    vector<pair<ll, ll>> db;

    while (getline(input, line) && line != "")
    {
        stringstream ss(line);

        string s_l;
        string s_r;

        getline(ss, s_l, '-');
        getline(ss, s_r, '-');

        ll l = stoll(s_l);
        ll r = stoll(s_r);

        db.push_back({l, r});
    }

    while (getline(input, line))
    {
        ll id = stoll(line);

        if (is_fresh(db, id))
            res++;
    }

    return res;
}

ll num_fresh(vector<pair<ll, ll>> &db)
{
}

ll part2()
{
    ifstream input("../data/5.txt");
    string line;
    ll res = 0;

    vector<pair<ll, ll>> db;

    while (getline(input, line) && line != "")
    {
        stringstream ss(line);

        string s_l;
        string s_r;

        getline(ss, s_l, '-');
        getline(ss, s_r, '-');

        ll l = stoll(s_l);
        ll r = stoll(s_r);

        db.push_back({l, r});
    }

    return res;
}