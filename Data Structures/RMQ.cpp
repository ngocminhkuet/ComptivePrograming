const int MAXN = 2e5 + 5;

int n, a[MAXN];

struct RMQ{
	int n;
	int f[MAXN][20];
	void init(int _n){
		n = _n;
		ford(i,1,n){
			f[i][0] = a[i];
		}
		for(int j = 1; (1 << j) <= n; ++j){
			for(int i = 1; i + (1 << j) - 1 <= n; ++i){
				f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	int getMax(int l, int r){
		int k = __lg(r - l + 1);
		return max(f[l][k], f[r - (1 << k) + 1][k]);
	}
 
} rmq;