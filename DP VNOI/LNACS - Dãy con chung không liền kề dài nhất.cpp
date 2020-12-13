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
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    int f[n + 2][m + 2];

    memset(f, 0, sizeof(f));

    for (int i = 2; i <= n + 1; ++i)
    {
        for (int j = 2; j <= m + 1; ++j)
        {
            if (a[i - 2] == b[j - 2])
                f[i][j] = f[i - 2][j - 2] + 1;
            else 
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }
    
    cout << f[n + 1][m + 1];
    return 0;
}
