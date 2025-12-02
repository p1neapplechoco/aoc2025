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

bool is_valid_p1(ll number)
{
    string s = to_string(number);

    if (s.length() % 2 != 0)
        return false;

    int l = 0;
    int r = s.length() - 1;

    string s_l = "";
    string s_r = "";

    while (l < r)
    {
        s_l += s[l++];
        s_r += s[r--];
    }

    reverse(s_r.begin(), s_r.end());

    return s_l == s_r;
}

ll part1()
{
    ifstream input("../data/2.txt");
    string line;
    ll res = 0;

    while (getline(input, line, ','))
    {
        stringstream ss(line);

        string s_start;
        string s_end;

        getline(ss, s_start, '-');
        getline(ss, s_end, '-');

        ll start = stoll(s_start);
        ll end = stoll(s_end);

        for (ll i = start; i <= end; i++)
        {
            if (is_valid_p1(i))
                res += i;
        }
    }

    return res;
}

bool is_valid_p2(ll number)
{
    string s = to_string(number);

    string pattern = "";
    int i = 0;

    while (pattern.length() < (s.length() / 2))
    {
        pattern += s[i++];
        string tmp = "";
        int repeat = s.length() / pattern.length();

        for (int j = 0; j < repeat; j++)
            tmp += pattern;

        if (tmp == s)
            return true;
    }

    return false;
}

ll part2()
{
    ifstream input("../data/2.txt");
    string line;
    ll res = 0;
    int cur_pos = 50;

    while (getline(input, line, ','))
    {
        stringstream ss(line);

        string s_start;
        string s_end;

        getline(ss, s_start, '-');
        getline(ss, s_end, '-');

        ll start = stoll(s_start);
        ll end = stoll(s_end);

        for (ll i = start; i <= end; i++)
        {
            if (is_valid_p2(i))
                res += i;
        }
    }

    return res;
}