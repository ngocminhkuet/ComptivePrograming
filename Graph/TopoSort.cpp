const int MAXN = 2e5 + 5;

int n, m;
int indegree[MAXN], res[MAXN];
vector <int> g[MAXN], topo;
queue <int> listSource;

int main() {

    cin >> n >> m;
    
    while (m--) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      indegree[v]++;
    }

    ford(u,1,n){
      if (!indegree[u]) listSource.push(u);
    }

    while (!listSource.empty()) {
      int u = listSource.front();
      listSource.pop();
      topo.push_back(u);
      for (auto v : g[u]) {
        indegree[v]--;
        if (!indegree[v]) listSource.push(v);
      }
    }

    if (topo.size() < n) {
      cout << "Error: Graph contains a cycle";
      return 0;
    }

    /* Sau khi xác định được thứ tự Tô-pô của đồ thị, ta sử dụng
       mảng res để đánh số lại các đỉnh */
    int cnt = 0;
    for (auto x : topo) res[x] = ++cnt;

    ford(i,1,n) cout << res[i] << ' ';

}