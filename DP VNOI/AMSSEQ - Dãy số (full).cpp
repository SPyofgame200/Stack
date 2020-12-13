#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

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

int main()
{   
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int res = 0;
    vector<int> f(n, -INF);
    f[0] = max(a[0], 0);
    for (int i = 1; i < n; ++i)
    {
        for (int j = max(0, i - k); j < i; ++j)
            maximize(f[i], f[j] + a[i]);

        maximize(res, f[i]);
    }

    cout << res;
    return 0;
}
