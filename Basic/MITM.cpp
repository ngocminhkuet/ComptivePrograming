// MITM - Meet In The Middle là một kỹ thuật tìm kiếm được sử dụng khi đầu vào nhỏ nhưng không đủ nhỏ để có thể quay lui (backtracking). 

// Bài toán cơ bản: Cho mảng t có n phần tử (n <= 40). Hỏi có bao nhiêu cách chọn tập con sao cho tổng bằng x cho trước 

// Nhận xét: Nếu ta sử dụng đệ quy quay lui để tính kết quả thì độ phức tạp sẽ là 2 ^ 40 => TELE

// Ta xử lý bằng cách áp dụng MITM: Chia đôi mảng t thành 2 phần từ 1 đến n / 2 và n / 2 + 1 đến n rồi thực hiện đệ quy quay lui trên 2 mảng này tính kết quả

const int N = 45;

int n, x;
int t[N];
vector<int> A, B;

void TryX(int i, int sum) {
    if (sum > x) return;

    if (i > n / 2) A.push_back(sum);
    else {
        TryX(i + 1, sum);
        TryX(i + 1, sum + t[i]);
    }
}
void TryY(int i, int sum) {
    if (sum > x) return;

    if (i > n) B.push_back(sum);
    else {
        TryY(i + 1, sum);
        TryY(i + 1, sum + t[i]);
    }
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> t[i];

    // Chia đôi n thành 2 tập X và Y để quay lui

    // Quay lui 2 tập X và Y
    TryX(1, 0);
    TryY(n / 2 + 1, 0);

    // Sắp xếp mảng B
    sort(B.begin(), B.end());

    // Lặp qua mảng A và tìm kiếm nhị phân:
    // - Đếm số lượng phần tử trong B có giá trị bằng x - A[i]
    long long cnt = 0;
    for (int sum : A) {
        cnt += upper_bound(B.begin(), B.end(), x - sum)
             - lower_bound(B.begin(), B.end(), x - sum);
    }
    cout << cnt << '\n';
}