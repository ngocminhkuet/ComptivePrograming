const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n;
int fact[MAXN], inv[MAXN];

ll binpow(ll a, ll n){
    ll ans = 1;
    while(n > 0){
        if(n & 1) ans = ans * a % MOD;
        n >>= 1;
        a = a * a % MOD;
    }
    return ans;
}
 
ll C(int k, int n){
     if(n < k || k < 0) return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}
 
void Init(){
    fact[0] = 1;
    ford(i,1,200000){
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv[200000] = binpow(fact[200000], MOD - 2);
    foru(i,200000-1,0){
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}