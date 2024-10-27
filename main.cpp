#include <bits/stdc++.h>
#define N 5010
#define int long long
using namespace std;
int n, m;
int c[N][N] = {}, cc[N][N] = {};
int c1[N][N] = {}, c2[N][N] = {};
int read() {
    int s = 0, w = 1;
    char c = getchar();

    while ((c > '9' || c < '0') && c != '-')
        c = getchar();

    if (c == '-')
        w = -1, c = getchar();

    while (c <= '9' && c >= '0')
        s = (s << 3) + (s << 1) + c - '0', c = getchar();

    return s * w;
}
void inc(int x, int y, int v) {
    int _ = y;

    for (; x <= N; x += x & (-x))
        for (y = _; y <= N; y += y & (-y))
            c[x][y] += v;
}
int ask(int x, int y) {
    int sum = 0, _ = y;

    for (; x; x -= x & (-x))
        for (y = _; y; y -= y & (-y))
            sum += c[x][y];

    return sum;
}
void incc(int x, int y, int v) {
    int _ = y, __ = x - 1, ___ = y - 1;

    for (; x <= N; x += x & (-x))
        for (y = _; y <= N; y += y & (-y))
            cc[x][y] += __ * ___ * v;
}
int askk(int x, int y) {
    int sum = 0, _ = y;

    for (; x; x -= x & (-x))
        for (y = _; y; y -= y & (-y))
            sum += cc[x][y];

    return sum;
}
void innc(int x, int y, int v) {
    int _ = y, __ = x - 1;

    for (; x <= N; x += x & (-x))
        for (y = _; y <= N; y += y & (-y))
            c1[x][y] += __ * v;
}
int assk(int x, int y) {
    int _ = y, sum = 0;

    for (; x; x -= x & (-x))
        for (y = _; y; y -= y & (-y))
            sum += c1[x][y];

    return sum;
}
void iinc(int x, int y, int v) {
    int _ = y, ___ = y - 1;

    for (; x <= N; x += x & (-x))
        for (y = _; y <= N; y += y & (-y))
            c2[x][y] += ___ * v;
}
int aask(int x, int y) {
    int _ = y, sum = 0;

    for (; x; x -= x & (-x))
        for (y = _; y; y -= y & (-y))
            sum += c2[x][y];

    return sum;
}
int Ask(int x, int y) {
    return (x) * (y) * ask(x, y) - (y) * assk(x, y) - (x) * aask(x, y) + askk(x, y);
}
void pr() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            printf("%lld ", askk(i, j));

        puts("");
    }
}
signed main() {
    n = read();
    m = read();
    int op = 0;

    while (scanf("%lld", &op) != EOF) {
        if (op == 1) {
            int l1 = read(), r1 = read(), l2 = read(), r2 = read(), v = read();
            inc(l1 + 1, r1 + 1, v);
            inc(l1 + 1, r2 + 2, -v);
            inc(l2 + 2, r1 + 1, -v);
            inc(l2 + 2, r2 + 2, v);
            incc(l1 + 1, r1 + 1, v);
            incc(l1 + 1, r2 + 2, -v);
            incc(l2 + 2, r1 + 1, -v);
            incc(l2 + 2, r2 + 2, v);
            innc(l1 + 1, r1 + 1, v);
            innc(l1 + 1, r2 + 2, -v);
            innc(l2 + 2, r1 + 1, -v);
            innc(l2 + 2, r2 + 2, v);
            iinc(l1 + 1, r1 + 1, v);
            iinc(l1 + 1, r2 + 2, -v);
            iinc(l2 + 2, r1 + 1, -v);
            iinc(l2 + 2, r2 + 2, v);
            //          pr();
        }

        if (op == 2) {
            int l1 = read(), r1 = read(), l2 = read(), r2 = read();
            printf("%lld\n", Ask(l2 + 1, r2 + 1) - Ask(l2 + 1, r1) - Ask(l1, r2 + 1) + Ask(l1, r1));
        }
    }

    return 0;
}