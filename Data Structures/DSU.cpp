struct DSU{
	int n, root[MAXN], sz[MAXN];
	void init(int _n = 0){
		n = _n;
		ford(i,1,n){
			root[i] = i;
			sz[i] = 1;
		}
	}
	int Find(int u) {
		return (root[u] == u ? u : root[u] = Find(root[u]));
	}
	void Union(int x, int y) {
		int u = Find(x);
		int v = Find(y);
		if(u == v) return;
		if(sz[u] < sz[v]){
            swap(u, v);
        }
        sz[u] += sz[v];
        root[v] = u;
	}
} dsu;