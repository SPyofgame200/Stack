#include <iostream>
#include <cstring>

using namespace std;

const int LIM = 100001;
int f[LIM], g[LIM];

char __;
template<typename T>
void getUnsign(T &x)
{
    while (__ = getchar(), __ < '0' || __ > '9');

    x = (__ - '0');
    while (__ = getchar(), __ >= '0' && __ <= '9')
        x = (x << 3) + (x << 1) + (__ - '0');
}

int magic(int x)
{
    if (f[x] != -1) return f[x];

    f[x] = magic(x / 2);
    if (x & 1) f[x] += magic(x / 2 + 1);

    return f[x];
}

int solve(int x)
{
    if (g[x] != -1) return g[x];
    return g[x] = max(magic(x), solve(x - 1));
}

int main()
{
    int q;
    cin >> q;

    memset(f, -1, sizeof(f));
    memset(g, -1, sizeof(f));
    f[0] = g[0] = 0;
    f[1] = g[1] = 1;

    while (q-->0)
    {
        int x;
        getUnsign(x);
        cout << solve(x) << '\n';
    }
    return 0;
}
