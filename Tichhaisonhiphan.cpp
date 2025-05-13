#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    string s1, s2;
    cin >> t;
    while (t--)
    {
        cin >> s1 >> s2;
        long long a = 0, b = 0, p = 1;
        for (int i = s1.size() - 1, j = 0; i >= 0, j < s1.size(); i--, j++)
        {
            a += int(s1[i] - '0') * p;
            p *= 2;
        }
        p = 1;
        for (int i = s2.size() - 1, j = 0; i >= 0, j < s2.size(); i--, j++)
        {
            b += int(s2[i] - '0') * p;
            p *= 2;
        }
        cout << a * b << '\n';
    }
    return 0;
}