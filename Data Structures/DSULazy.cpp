struct DSU{
	int n, root[MAXN], nxt[MAXN][11], sz[MAXN];
	void init(int _n = 0){
		n = _n;
		ford(i,1,n){
			root[i] = i;
			sz[i] = 1;
			ok[i] = false;
			ford(j,0,10){
				nxt[i][j] = i + j;
			}
		}
	}
	int Find(int u) {
		return (root[u] == u ? u : root[u] = Find(root[u]));
	}
	void Union(int x, int y) {
		int u = Find(x);
		int v = Find(y);
		if(u == v) return;
		if(u < v){
			sz[u] += sz[v];
			root[v] = u;
		}
		else{
			sz[v] += sz[u];
			root[u] = v;
		}
	}
	void Merge(int l, int r, int j) {
		for(int i = l + j; i <= r;) {
			Union(i - j, i);
			int k = nxt[i][j];
			nxt[i][j] = max(nxt[i][j], r);
			i = k;
		}
	}
} dsu;