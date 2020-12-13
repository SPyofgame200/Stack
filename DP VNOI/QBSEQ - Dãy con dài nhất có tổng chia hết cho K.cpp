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

int n, k;
vector<int> a;
vector<vector<int> > f;
int magic(int i = 0, int sum = 0)
{
    while (sum >= k) sum -= k;
    if (i >= n) return (sum == 0) ? 0 : -INF;

    int &res = f[i][sum];
    if (res != -INF) return res;
    maximize(res, magic(i + 1, sum));
    maximize(res, magic(i + 1, sum + a[i]) + 1);
    return res;
}

int main()
{
    cin >> n >> k;
    a.resize(n);
    for (int &x : a)
    {
        cin >> x;
        x %= k;
    }

    f.assign(n + 1, vector<int>(k + 1, -INF));
    int res = magic();
    if (res == -INF) res = 0;
    cout << res;
    return 0;
}
