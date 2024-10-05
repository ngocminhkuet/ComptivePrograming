struct SegmentTree{
    int n;
    vector<ll> t, lazy;
    SegmentTree(int _n = 0){
        n = _n;
        t.resize(n * 4 + 1);
        lazy.resize(n * 4 + 1);
    }
    void init(int id, int l, int r){
        if(l == r){
            t[id] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        init(id << 1, l, m);
        init(id << 1 | 1, m + 1, r);
        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
    void down(int id){
        if(lazy[id] != 0){
            ford(i,id*2,id*2+1){
                t[i] += lazy[id];
                lazy[i] += lazy[id];
            }
            lazy[id] = 0;
        }
    }
    void update(int id, int l, int r, int u, int v, ll val){
        if(r < u || v < l){
            return;
        }
        if(u <= l && r <= v){
            t[id] += val;
            lazy[id] += val;
            return;
        }
        down(id);
        int m = (l + r) >> 1;
        update(id << 1, l, m, u, v, val);
        update(id << 1 | 1, m + 1, r, u, v, val);
        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
} IT;