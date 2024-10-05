const int MAXN = 2e5 + 5;
const int INF = 1e9;

int n, stt = 0, id[MAXN], num[MAXN], low[MAXN];
int timeDfs = 0,
vector<int> g[MAXN];
stack<int> st;
 
void tarjan(int u){
	num[u] = low[u] = ++timeDfs;
	st.push(u);
	for(int v: g[u]){
		if(!num[v]){
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else{
			low[u] = min(low[u], num[v]);
		}
	}
	if(num[u] == low[u]){
		stt++;
		int v;
		do{
			v = st.top();
			id[v] = stt;
			st.pop();
			low[v] = num[v] = INF;
		}
		while(v != u);
	}
}