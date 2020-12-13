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

string s;
int n;

vector<vector<int> > g;
int prev(int p, int c)
{
    if (p < 0) return p;
    if (s[p] == c) return p;
    if (g[p][c] != -1) return g[p][c];
    return g[p][c] = prev(p - 1, c);
}

vector<vector<int> > f;
int magic(int i = 0, int j = n - 1)
{
    if (i > j) return 0;
    
    int &res = f[i][j];
    if (res != -1) return res;

    res = magic(i + 1, j);
    j = prev(j, s[i]);
    if (i <= j && s[i] == s[j])
        maximize(res, magic(i + 1, j - 1) + 2 - (i == j));
        
    return res;
}
 
string L, R;
void trace(int i = 0, int j = n - 1)
{
    if (i > j) return ;
 
    int val = magic(i, j);
    if (val == magic(i + 1, j))
        return trace(i + 1, j);
    else 
    {
        j = prev(j, s[i]);
        
        L += s[i];
        if (i != j) R += s[j];
        return trace(i + 1, j - 1);
    }
}
 
int main()
{
    getString(s);
    n = s.size();
    f.assign(n + 1, vector<int>(n + 1, -1));
    g.assign(n + 1, vector<int>(256, -1));
    trace();
    
    reverse(all(R));
    cout << L << R;
    return 0;
}
