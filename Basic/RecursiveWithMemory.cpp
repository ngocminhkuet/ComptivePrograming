int memo[MAXN];

memset(memo, -1, sizeof memo);

// memo là mảng sẽ lưu lại kết quả của những lần tính trước đó bằng đệ quy để khi ta gọi lại trạng thái đó thì sẽ trả về được kết quả luôn

int calc(int n){
    if(n == 0){
        return memo[n] = 0;
    }
    if(n == 1){
        return memo[n] = 1;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    int ans = 0;
    ans = calc(n - 1) + calc(n - 2);
    return memo[n] = ans;
}