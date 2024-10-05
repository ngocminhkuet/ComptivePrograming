#define bit(x,k) ((x>>k)&1ll) // kiểm tra bit thứ k của số x là 0 hay 1
#define offbit(x,k) (~(1ll<<k)&x) // tắt bit thứ k của số x (1 -> 0) 
#define onbit(x,k) ((1ll<<k)|x) // bật bit thứ k của số x (0 -> 1)

// S là một dãy bit nhị phân gồm các số 0 và 1

/* Cét tất cả các tập con khác rỗng của S */

for (int mask = S; mask > 0; mask = (mask - 1) & S){

}