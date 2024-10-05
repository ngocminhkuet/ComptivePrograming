const int MAXN = 2e5 + 5;
const int INF = 1e9;

int n, dist[MAXN];
bool visited[MAXN];
vector<pair<int, int>> g[MAXN];  
deque<int> dq;

void BFS_01(int s){
    ford(i,1,n){
        dist[i] = INF;              
        visited[i] = false;
    }
    dist[s] = 0;
    dq.push_front(s);
    while(!dq.empty()){
        int u = dq.front();
        dq.pop_front();
        if(visited[u] == true)continue;
        visited[u] = true;            
        for(auto v: g[u]){
            if(dist[v.f] > dist[u] + v.s){             
                dist[v.f] = dist[u] + v.s;             
                if(v.s == 1) dq.push_back(v.f);    
                else dq.push_front(v.f);
            }
        }
    }
}