const int MAXN = 505;
const int INF = 1e9;

int a[MAXN][MAXN], dist[MAXN][MAXN];

void initGraph(){
    ford(i,1,n){
        ford(j,1,n){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = a[i][j];
        }
    }
}

void Floyd(){
    ford(i,1,n){
        ford(j,1,n){
            dist[i][j] = INF;
        }
    }
    ford(k,1,n){
        ford(i,1,n){
            ford(j,1,n){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}