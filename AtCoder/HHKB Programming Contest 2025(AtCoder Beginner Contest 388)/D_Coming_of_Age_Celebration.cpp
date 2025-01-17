#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    int size;
    vector<int> tree;

public:
    FenwickTree(int n) : size(n), tree(n + 2, 0) {}

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += index & -index; // Move to the next index
        }
    }

    int query(int index) {
        int result = 0;
        while (index > 0) {
            result += tree[index];
            index -= index & -index; // Move to the parent index
        }
        return result;
    }

    void range_update(int l, int r, int value) {
        update(l, value);
        update(r + 1, -value);
    }

    int point_query(int index) {
        return query(index);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0); // 1-based indexing
    FenwickTree tree1(n);      // Tracks non-zero elements
    FenwickTree tree2(n);      // Tracks updates (reductions)
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] != 0) {
            tree1.update(i, 1); // Mark non-zero elements
        }
    }

    for(int idx = 1; idx <= n; idx++) {
        int non_zero_count = tree1.query(n);
        if (non_zero_count > 0) {
            tree2.range_update(1, idx - 1, -1); // Reduce elements before `idx`
            tree2.range_update(idx + 1, n, -1); // Reduce elements after `idx`
        }
        arr[idx] += non_zero_count;
        if (arr[idx] != 0) {
            tree1.update(idx, 1); // Mark `idx` as non-zero
        }
    }
    for (int i = 1; i <= n; i++) {
        int updated_value = arr[i] + tree2.point_query(i);
        cout << updated_value << " ";
    }
    cout << endl;
    return 0;
}
