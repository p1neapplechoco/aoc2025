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
    cout << "Part 1: " << part1() << endl;
    cout << "Part 2: " << part2() << endl;
}

ll dial_p1(int &cur_pos, string &action)
{
    char dir = action[0];
    string tmp;

    for (int i = 1; i < action.size(); i++)
    {
        if (isdigit(action[i]))
        {
            tmp += action[i];
        }
    }

    int steps = stoi(tmp);
    if (toupper(dir) == 'R')
        steps = steps;
    else if (toupper(dir) == 'L')
        steps = -steps;
    else
        throw runtime_error("Invalid direction");

    int new_pos = cur_pos + steps;
    cur_pos = ((new_pos % 100) + 100) % 100;

    return cur_pos == 0;
}

ll part1()
{
    ifstream input("../data/1.txt");
    string line;
    ll res = 0;
    int cur_pos = 50;

    while (getline(input, line))
    {
        res += dial_p1(cur_pos, line);
    }

    return res;
}

ll dial_p2(int &cur_pos, string &action)
{
    char dir = action[0];
    string tmp;

    for (int i = 1; i < action.size(); i++)
    {
        if (isdigit(action[i]))
        {
            tmp += action[i];
        }
    }

    int steps = stoi(tmp);
    int step = 1;

    if (toupper(dir) == 'R')
        step = 1;
    else if (toupper(dir) == 'L')
        step = -1;

    // DEBUG(step);

    ll cnt = 0;

    for (int i = 0; i < steps; i++)
    {
        cur_pos = ((cur_pos + step % 100) + 100) % 100;
        if (cur_pos == 0)
            cnt++;
    }

    return cnt;
}

ll part2()
{
    ifstream input("../data/1.txt");
    string line;
    ll res = 0;
    int cur_pos = 50;

    while (getline(input, line))
    {
        res += dial_p2(cur_pos, line);
    }
    return res;
}