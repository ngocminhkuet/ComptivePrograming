// nén các số trong phạm vi giá trị của số đó về phạm vi số lượng của các phần tử

// 1 <= ai <= 10^9 và có n phần tử => nén lại thành 1 <= ai <= n mà vẫn giữ quan hệ lớn bé của các phần tử

const int MAXN = 2e5 + 5;

int n, a[MAXN];
vector<int> v;

int pos(int x){
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int main(){
    cin >> n;
    ford(i,1,n){
        cin >> a[i];
        v.pb(a[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    ford(i,1,n){
        a[i] = pos(a[i]);
    }
    // Mảng a là mảng sau khi đã rời rạc hoá và nén lại giá trị của các số
    return 0;
}