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
int magic(int i = 0, int len = 0)
{
    if (len > k) return +INF;
    if (i >= n) return k - len;

    int &res = f[i][len];
    if (res != +INF) return res;
    minimize(res, magic(i + 1, len + a[i]));
    minimize(res, max(magic(i + 1, a[i]), (k - len)));
    return res;
}

int main()
{
    cin >> n >> k;
    a.resize(n);
    for (int &x : a) cin >> x;

    f.assign(n + 1, vector<int>(k + 1, +INF));
    cout << magic();
    return 0;
}
