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
    ifstream input("../data/6.txt");
    string line;
    ll res = 0;

    vector<vector<string>> vec;

    while (getline(input, line))
    {
        stringstream ss(line);
        string s_digit;

        vector<string> temp_vec;

        while (ss >> s_digit)
        {
            temp_vec.push_back(s_digit);
        }
        vec.push_back(temp_vec);
    }

    int n_rows = vec.size();
    int n_cols = vec[0].size();

    for (int i = 0; i < n_cols; i++)
    {
        ll tmp_res = 0;
        if (vec[n_rows - 1][i] == "+")
        {
            for (int j = 0; j < n_rows - 1; j++)
            {
                tmp_res += stoll(vec[j][i]);
            }
        }
        else if (vec[n_rows - 1][i] == "*")
        {
            tmp_res = 1;
            for (int j = 0; j < n_rows - 1; j++)
            {
                tmp_res *= stoll(vec[j][i]);
            }
        }

        res += tmp_res;
    }

    return res;
}

ll part2()
{
    ifstream input("../data/6.txt");
    string line;
    ll res = 0;

    vector<string> vec;
    int max_len = 0;

    while (getline(input, line))
    {
        max_len = max(max_len, (int)line.length());
        vec.push_back(line);
    }

    vector<string> col_chars;
    int n_rows = vec.size();

    for (int i = max_len - 1; i >= 0; i--)
    {
        string s_col = "";
        string s_op = "";

        for (int j = 0; j < n_rows; j++)
        {
            if (i < vec[j].length() && isdigit(vec[j][i]))
            {
                s_col += vec[j][i];
            }
            if (i < vec[j].length() && vec[j][i] != ' ' && !isdigit(vec[j][i]))
            {
                s_op += vec[j][i];
            }
        }
        if (s_col != "")
            col_chars.push_back(s_col);

        if (s_op != "")
        {
            cout << "Operation: " << s_op << endl;
            if (s_op == "+")
            {
                ll tmp_res = 0;
                for (string &num : col_chars)
                {
                    tmp_res += stoll(num);
                }
                res += tmp_res;
            }
            else if (s_op == "*")
            {
                ll tmp_res = 1;
                for (string &num : col_chars)
                {
                    tmp_res *= stoll(num);
                }
                res += tmp_res;
            }
            col_chars.clear();
        }
    }

    return res;
}