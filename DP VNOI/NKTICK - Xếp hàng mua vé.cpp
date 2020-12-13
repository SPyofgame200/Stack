#include <algorithm>
#include <iostream>
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

template<typename T> void maximize(T &res, const T &val) { if (res < val) res = val; }
template<typename T> void minimize(T &res, const T &val) { if (res > val) res = val; }

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
/// ====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====

int n;
vector<int> t;
vector<int> r;
vector<ll> f;
ll magic(int i = 0)
{
    if (i >= n) return 0;

    ll &res = f[i];
    if (res != +LINF) return res;

    minimize(res, magic(i + 1) + t[i]);
    if (i + 1 < n)
        minimize(res, magic(i + 2) + r[i + 1]);

    return res;
}

int main()
{
    cin >> n;

    t.resize(n);
    r.resize(n);
    for (int i = 0; i < n; ++i) cin >> t[i];
    for (int i = 1; i < n; ++i) cin >> r[i];

    f.assign(n + 1, +LINF);
    cout << magic();
    return 0;
}
