#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <numeric>

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

const int INIT = -INF;
vector<vector<int> > f;
inline void fix(vector<int> &S, int len)
{
    if (S.size() <= len) 
        S.resize(len + 1, INIT);
}

int magic(int i = 0, int sum = 0)
{
    if (sum > k) return INIT;
    if (i >= n) return sum;

    fix(f[i], sum);
    int &res = f[i][sum];
    if (res != INIT) return res;
    maximize(res, magic(i + 1, sum + a[i]));
    maximize(res, magic(i + 1, sum));
    return res;
}

int main()
{
    cin >> k >> n;
    a.resize(n);
    for (int &x : a)
    {
        cin >> x;
        if (x > k)
        {
            swap(x, a.back());
            a.pop_back();
            --n;
        }
    }

    ll sum = accumulate(all(a), 0LL);
    if (sum <= k)
    {
        cout << sum;
        return 0;
    }

    f.resize(n + 1);
    int res = magic();
    if (res == INIT)
        res = 0;

    cout << res;
    return 0;
}
