struct SegmentTree{
    int n;
    vector<int> t;
    SegmentTree(int _n = 0){
        n = _n;
        t.resize(4 * n + 1);
    }
    void build(int id, int l, int r, int a[]){
        if(l == r){
            t[id] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(id << 1, l, m, a);
        build(id << 1 | 1, m + 1, r, a);
        t[id] = min(t[id << 1], t[id << 1 | 1]);
    }
    void update(int id, int l, int r, int pos, int val){
        if(pos < l || r < pos){
            return;
        }
        if(l == r){
            t[id] = val;
            return;
        }
        int m = (l + r) >> 1;
        if(l <= pos && pos <= m){
            update(id << 1, l, m, pos, val);
        }
        else{
            update(id << 1 | 1, m + 1, r, pos, val);
        }
        t[id] = min(t[id << 1], t[id << 1 | 1]);
    }
    int get(int id, int l, int r, int u, int v){
        if(r < u || v < l){
            return INF;
        }
        if(u <= l && r <= v){
            return t[id];
        }
        int m = (l + r) >> 1;
        int t1 = get(id << 1, l, m, u, v);
        int t2 = get(id << 1 | 1, m + 1, r, u, v);
        return min(t1, t2);
    }
} IT;