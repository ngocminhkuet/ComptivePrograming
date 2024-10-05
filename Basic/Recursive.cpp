int calc(int n){
    if(n == 0) return 0;
    if(n == 1) return 1; // Điều kiện dừng đệ quy
    return calc(n - 1) + calc(n - 2);
}