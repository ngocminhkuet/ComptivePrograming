const int MANX = 2e5 + 5;

int a[MAXN], f[MAXN];
stack<int> st;

/* f[i] là chỉ số bên trái gần nhất mà a[f[i]] > a[i]*/

ford(i,1,n){
    while (!st.empty() && a[st.top()] <= a[i])
        st.pop();
    if (!st.empty())
        f[i] = st.top();
    st.push(i);
}