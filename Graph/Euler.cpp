#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;

struct Edge {
    int target, id;
    Edge(int _target = 0, int _id = 0){
        target = _target;
        id = _id;
    }
};

vector<Edge> adj[N]; // Danh sách kề lưu cạnh và chỉ số
bool used_edge[M]; // Mảng đánh dấu cạnh đã thăm

list<int> euler_walk(int u) {
    // Sử dụng cấu trúc danh sách liên kết để lưu kết quả
    list<int> ans;

    // Xuất phát từ đỉnh u
    ans.push_back(u);

    while (!adj[u].empty()) {
        // Chọn một cạnh bất kì chưa thăm
        int v = adj[u].back().target;
        int eid = adj[u].back().id;

        // Xoá cạnh vừa đi qua khỏi đồ thị
        // Lưu ý việc xoá cạnh có thể **ảnh hưởng** tới các
        // thao tác trên đồ thị về sau do việc xoá cạnh sẽ
        // **phá huỷ** hoàn toàn danh sách cạnh
        // Nên sao lưu danh sách cạnh ra biến khác nếu cần dùng lại
        adj[u].pop_back();

        // Bỏ qua nếu cạnh đã thăm
        if (used_edge[eid]) continue;

        // Đánh dấu cạnh đã đi qua
        used_edge[eid] = true;

        // Di chuyển sang đỉnh mới
        u = v;

        // Thêm cạnh vào đường đi hiện tại
        // Có nhiều cách lưu chu trình như lưu đỉnh, cạnh,
        // chỉ số cạnh, ...
        ans.push_back(u);
    }

    // Tìm cạnh chưa thăm từ một đỉnh trên chu trình hiện tại
    // Bắt đầu từ đỉnh thứ hai trong chu trình do ta biết
    // rằng đỉnh đầu tiên trong chu trình (u) đã không còn
    // cạnh ra
    for (auto it = ++ans.begin(); it != ans.end(); ++it) {
        // Gọi đệ quy tiếp tục tìm chu trình mới
        auto t = euler_walk(*it);

        // Nối chu trình tìm được vào chu trình hiện tại
        t.pop_back();
        ans.splice(it, t);
    }

    return ans;
}