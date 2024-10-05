const int MAXN = 2e5 + 5;
 
int a[MAXN];
deque<int> dq;

// Tìm min - max trên đoạn tịnh tiến

int minRange[MAXN];

while (dq.size()) dq.pop_front();
ford(i,1,n){
    while (dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
    dq.push_back(i);
    if (dq.front() + k <= i) dq.pop_front();
    /* minRange[i] là giá trị nhỏ nhất trong đoạn [i – k + 1 … i] */
    if (i >= k) minRange[i] = a[dq.front()];
}

// tính mảng L, R

/* L1[i]: Xa nhất về bên trái nhận a[i] là max */

dq.clear();
ford(i,1,n){
    while (dq.size() && a[dq.front()] <= a[i]) dq.pop_front();
    if (dq.size()) L1[i] = dq.front() + 1;
    else L1[i] = i;
    dq.push_front(i);
}

/* R1[i]: Xa nhất về bên phải nhận a[i] là max */

dq.clear();
foru(i,n,1){
    while (dq.size() && a[dq.front()] <= a[i]) dq.pop_front();
    if (dq.size()) R1[i] = dq.front() - 1;
    else R1[i] = i;
    dq.push_front(i);
}

/* L2[i]: Xa nhất về bên trái nhận a[i] là min */

dq.clear();
ford(i,1,n){
    while (dq.size() && a[dq.front()] >= a[i]) dq.pop_front();
    if (dq.size()) L2[i] = dq.front() + 1;
    else L2[i] = i;
    dq.push_front(i);
}

/* R2[i]: Xa nhất về bên phải nhận a[i] là min */

dq.clear();
foru(i,n,1){
    while (dq.size() && a[dq.front()] >= a[i]) dq.pop_front();
    if (dq.size()) R2[i] = dq.front() - 1;
    else R2[i] = i;
    dq.push_front(i);
}
