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

int n, k;
vector<int> a;
vector<map<int, int> > f;
int magic(int i = 0, int sum = 0)
{
    if (i >= n) return 0;

    if (f[i].count(sum)) return f[i][sum];
    int &res = f[i][sum];

    res = -INF;
    int lim = min(i + k, n);
    for (int j = i; j < lim; ++j)
        maximize(res, magic(j + 1, sum + a[j]) + a[j]);

    return res;
}

int main()
{   
    cin >> n >> k;
    a.resize(n);
    for (int &x : a) cin >> x;

    f.resize(n + 1);
    cout << magic();
    return 0;
}
