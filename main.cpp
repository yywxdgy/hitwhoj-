#include <stdio.h>
#define N 1010
int n, m, opt;
int pr[N], tr[N];
int G[N][N];
void Inc(int x, int y, int z) { G[x][y] = z; }
int read() {
    int s = 0; char c = getchar(); 
    for (; c < '0' || c > '9'; c = getchar());
    for (s = 0; c >= '0' && c <= '9'; c = getchar())
        s = (s << 3) + (s << 1) + c - 48;
    return s;
} 
char readc() {
    char c = getchar();
    for (; (c < 'A' || c > 'Z'); c = getchar());
    return c;
} 
int vis[N], vs = 0;
void Dfs(int u) {
    int i, v;
    vis[u] = 1, ++vs;
    putchar(pr[u]);
    for (i = 1; i <= n; ++i) {
        v = i;
        if (!G[u][v]) continue;
        if (vis[v]) continue;
        Dfs(v);
    } 
}
int main() {
    int i, x, y, z = 1;
    opt = read(), n = read(), m = read();
    for (i = 1; i <= n; ++i) pr[i] = readc(), tr[pr[i]] = i;
    for (i = 1; i <= m; ++i) 
        x = readc(), y = readc(), 
        ((opt == 1 || opt == 3) ? z = read() : 0), 
        Inc(tr[x], tr[y], z), 
        (opt == 2 || opt == 3) ? Inc(tr[y], tr[x], z),0 : 0;
    int st = tr[(int)readc()];
    Dfs(st);
    if (vs == n) return 0; 
    for (i = 1; i <= n; ++i) if (!vis[i]) Dfs(i);
    return 0;
} 