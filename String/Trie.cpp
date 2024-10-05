// Trie xâu

struct Trie{
    struct Node{
        Node* child[26];
        int exist, cnt;

        Node() {
            for (int i = 0; i < 26; i++) child[i] = NULL;
            exist = cnt = 0;
        }
    };

    int cur;
    Node* root;
    Trie() : cur(0) {
        root = new Node();
    };

    void add_string(string s) {
        Node* p = root;
        for (auto f : s) {
            int c = f - 'a';
            if (p->child[c] == NULL) p->child[c] = new Node();

            p = p->child[c];
            p->cnt++;
        }
        p->exist++;
    }

    bool delete_string_recursive(Node* p, string& s, int i) {
        if (i != (int)s.size()) {
            int c = s[i] - 'a';
            bool isChildDeleted = delete_string_recursive(p->child[c], s, i + 1);
            if (isChildDeleted) p->child[c] = NULL;
        }
        else p->exist--;

        if (p != root) {
            p->cnt--;
            if (p->cnt == 0) {
                delete(p); // Khác với cài đặt bằng mảng,
                           // ta có thể thực sự xóa đỉnh này đi
                return true;
            }
        }
        return false;
    }

    void delete_string(string s) {
        if (find_string(s) == false) return;

        delete_string_recursive(root, s, 0);
    }

    bool find_string(string s) {
        Node* p = root;
        for (auto f : s) {
            int c = f - 'a';
            if (p->child[c] == NULL) return false;
            p = p->child[c];
        }
        return (p->exist != 0);
    }
};

// Trie nhị phân

const int NUMBEROFNODES = ...;
const int LG = ...;
struct Trie{
    struct Node{
        int child[2];
        int exist, cnt;
    } nodes[NUMBEROFNODES];

    int cur;
    Trie() : cur(0) {
        memset(nodes[0].child, -1, sizeof(nodes[cur].child));
        nodes[0].exist = nodes[0].cnt = 0;
    };

    int new_node() {
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }

    void add_number(int x) {
        int pos = 0;
        for (int i = LG; i >= 0; i--) {
            int c = (x >> i) & 1;
            if (nodes[pos].child[c] == -1) nodes[pos].child[c] = new_node();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }

    void delete_number(int x) {
        if (find_number(x) == false) return;
        int pos = 0;
        for (int i = LG; i >= 0; i--) {
            int c = (x >> i) & 1;

            int tmp = nodes[pos].child[c];
            nodes[tmp].cnt--;
            if (nodes[tmp].cnt == 0) {
                nodes[pos].child[c] = -1;
                return;
            }

            pos = tmp;
        }
        nodes[pos].exist--;
    }

    bool find_number(int x) {
        int pos = 0;
        for (int i = LG; i >= 0; i--) {
            int c = (x & (1 << i) ? 1 : 0);
            if (nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c];
        }
        return (nodes[pos].exist != 0);
    }
};

// Tìm xâu có thứ tự từ điển thứ k trong danh sách

string find_kth_string(int k) {
    int pos = 0;
    string res = "";

    while (true) {
        if (nodes[pos].exist >= k) break;
        k -= nodes[pos].exist;

        for (int i = 0; i < 26; i++) if (nodes[pos].child[i] != -1) {
            int nxt = nodes[pos].child[i];
            if (nodes[nxt].cnt >= k) {
                res += char(i + 'a');
                pos = nxt;
                break;
            }
            k -= nodes[nxt].cnt;
        }
    }

    return res;
}

// Xử lí truy vấn tìm XOR lớn nhất với giá trị được cho

int query(int x) {
    int pos = 0, res = 0;
    for (int i = LG; i >= 0; i--) {
        int c = (x >> i) & 1;

        if (nodes[pos].child[c ^ 1] != -1) {
            res += (1ll << i);
            pos = nodes[pos].child[c ^ 1];
        }
        else {
            pos = nodes[pos].child[c];
        }
    }
    return res;
}