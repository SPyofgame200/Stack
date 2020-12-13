#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

void file(const string FILE = "Test")
{
    freopen((FILE + ".INP").c_str(), "r", stdin);
    freopen((FILE + ".OUT").c_str(), "w", stdout);
}

char __;
template<typename T>
void getUnsign(T &x)
{
    while (__ = getchar(), __ < '0' || __ > '9');
 
    x = (__ - '0');
    while (__ = getchar(), __ >= '0' && __ <= '9')
        x = (x << 3) + (x << 1) + (__ - '0');
}

template<typename T>
void getSigned(T &x)
{
    while (__ = getchar(), __ != '-' && (__ < '0' || __ > '9'));
    bool sign(__ == '-');
    if (sign) __ = getchar();
 
    x = (__ - '0');
    while (__ = getchar(), __ >= '0' && __ <= '9')
        x = (x << 3) + (x << 1) + (__ - '0');

    if (sign) x = -x;
}

template<typename T>
void getString(T &s)
{
    while (__ = getchar(), __ < 'a' || __ > 'z');

    s.assign(1, __);
    while (__ = getchar(), __ >= 'a' && __ <= 'z')
        s += __;
}

template<typename T> void maximize(T &res, const T &val) { if (res < val) res = val; }
template<typename T> void minimize(T &res, const T &val) { if (res > val) res = val; }

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
/// ====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====

void lcs(const string &s, const string &t)
{
    int n = s.size();
    int m = t.size();

    int f[n + 1][m + 1];
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s[i - 1] == t[j - 1])
                f[i][j] = f[i - 1][j - 1] + 1;
            else 
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);       
        }
    }

    string res;
    for (int i = n, j = m; i > 0 && j > 0; )
    {
        if (s[i - 1] == t[j - 1])
        {
            res += s[i - 1];
            --i, --j;
            continue;
        }

        (f[i - 1][j] > f[i][j - 1]) ? --i : --j;
    }

    reverse(all(res));
    cout << res;
}

int main()
{
    string s;
    getString(s);
    string t = s;
    reverse(all(t));
    lcs(s, t);
    return 0;
}
