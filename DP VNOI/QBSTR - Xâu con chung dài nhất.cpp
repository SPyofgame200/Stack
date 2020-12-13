#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

char __;
template<typename T>
void getUnsign(T &x)
{
    while (__ = getchar(), __ < '0' || __ > '9');
 
    x = (__ - '0');
    while (__ = getchar(), __ >= '0' && __ <= '9')
        x = (x << 3) + (x << 1) + (__ - '0');
}

template<typename T> void maximize(T &res, const T &val) { if (res < val) res = val; }
template<typename T> void minimize(T &res, const T &val) { if (res > val) res = val; }

const int INF = 0x3f3f3f3f;
/// ====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====

int main()
{
    string s, t;
    cin >> s >> t;

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
    
    cout << f[n][m];
    return 0;
}
