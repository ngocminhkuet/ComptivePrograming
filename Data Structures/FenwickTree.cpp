struct FenwickTree{
    int n;
    vector<ll> t;
    FenwickTree(int _n = 0){
        n = _n;
        t.resize(n + 1);
    }
    void update(int id){
        int v = id;
        while(id <= n){
            t[id] += v;
            id += id & (-id);
        }
    }
    ll get(int id){
        ll total = 0;
        while(id > 0){
            total += t[id];
            id -= id & (-id);
        }
        return total;
    }
} BIT;