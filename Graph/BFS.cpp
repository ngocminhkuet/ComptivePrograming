const int MAXN = 2e5 + 5;
const int INF = 1e9;

int n;
vector<int> g[MAXN]; 
int dist[MAXN];
queue<int> q;

void BFS(int s){
    ford(i,1,n){
        dist[i] = INF;
    }
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: g[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
