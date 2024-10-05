vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> pi = prefix_function(s);
int ans = 0; // Số lần s xuất hiện trong t
int j = 0; // Hàm tiền tố ở vị trí đang xét của xâu t

for (int i = 0; i < m; i++) {
    while (j > 0 && t[i] != s[j])
        j = pi[j - 1];
    if (t[i] == s[j])
        j++;
    if (j == n)
        ans++;
}