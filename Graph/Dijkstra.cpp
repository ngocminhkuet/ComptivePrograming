const int MAXN = 2e5 + 5;
const ll INF = 1e15;

struct Edge{
    int v, w;
    Edge(int _v = 0, int _w = 0){
        v = _v;
        w = _w;
    }
    bool operator > (const &Edge other) const{
        return w > other.w;
    }
}

int n;
ll dist[MAXN];
vector<Edge> g[MAXN];

void addEdge(int u, int v, int w){
    g[u].pb(Edge(v, w));
    g[v].pb(Edge(u, w));
}

void dijkstra(int s){
	ford(i,1,n){
        dist[i] = INF;
    }
    dist[s] = 0;
	priority_queue<Edge, vector<Edge>, greater<Edge> > q;
    q.push(Edge(s, 0));
	while(!q.empty()){
		int u = q.top().v;
		ll du = q.top().w;
		q.pop();
		if(dist[u] != du) continue;
		for(auto &it: g[u]){
			int v = it.v;
			int uv = it.w;
			if(dist[v] > dist[u] + uv){
				dist[v] = dist[u] + uv;
				q.push(Edge(v, dist[v]));
			}
		}
	}
}