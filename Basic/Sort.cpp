// Thuật toán Merge Sort có độ phức tạp O(N * Log(N))

int a[MAXN]; // mảng trung gian cho việc sắp xếp

// Sắp xếp các phần tử có chỉ số từ left đến right của mảng data.
void mergeSort(int data[MAXN], int left, int right) {
    if (data.length == 1) {
        // Dãy chỉ gồm 1 phần tử, ta không cần sắp xếp.
        return ;
    }
    int mid = (left + right) / 2;
    // Sắp xếp 2 phần
    mergeSort(data, left, mid);
    mergeSort(data, mid+1, right);

    // Trộn 2 phần đã sắp xếp lại
    int i = left, j = mid + 1; // phần tử đang xét của mỗi nửa
    int cur = 0; // chỉ số trên mảng a

    while (i <= mid || j <= right) { // chừng nào còn 1 phần chưa hết phần tử.
        if (i > mid) {
            // bên trái không còn phần tử nào
            a[cur++] = data[j++];
        } else if (j > right) {
            // bên phải không còn phần tử nào
            a[cur++] = data[i++];
        } else if (data[i] < data[j]) {
            // phần tử bên trái nhỏ hơn
            a[cur++] = data[i++];
        } else {
            a[cur++] = data[j++];
        }
    }

    // copy mảng a về mảng data
    for (int i = 0; i < cur; i++)
        data[left + i] = a[i];
}