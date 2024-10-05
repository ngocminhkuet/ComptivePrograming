const int MAXN = 2e5 + 5;

int n;
int h[MAXN], sz[MAXN];

void DFS(int u, int par){
    sz[u] = 1;
    for(int v: g[u]){
        if(par == v) continue;
        h[v] = h[u] + 1;
        DFS(v, u);
        sz[u] += sz[v];
    }
}
