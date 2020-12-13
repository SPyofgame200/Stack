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

int n, m;
vector<vector<int> > f;
vector<vector<int> > a;

int magic(int i = 1, int j = 1)
{
    if (i < 1 || i > n) return -INF;
    if (j > m) return 0;

    int &res = f[i][j];
    if (res != -INF) return res;
    maximize(res, magic(i + 1, j + 1) + a[i][j]);
    maximize(res, magic(i + 0, j + 1) + a[i][j]);
    maximize(res, magic(i - 1, j + 1) + a[i][j]);

    return res;
}

int main()
{
    cin >> n >> m;
    a.assign(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    
    f.assign(n + 2, vector<int>(m + 2, -INF));

    int res = -INF;
    for (int row = 1; row <= n; ++row)
        maximize(res, magic(row, 1));

    cout << res;
    return 0;
}
