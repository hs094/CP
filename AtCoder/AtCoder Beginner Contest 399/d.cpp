#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Fenw {
    int n;
    vector<ordered_set<int>> tree;
    Fenw(int n) : n(n), tree(n+1) {}

    void update(int i, int val) {
        for (++i; i <= n; i += i & -i)
            tree[i].insert(val);
    }
    
    int query(int i, int key) {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += tree[i].order_of_key(key);
        return res;
    }
    
    int range_query(int l, int r, int key) {
        if(l > r) return 0;
        return query(r, key) - query(l-1, key);
    }
};
struct Interval {
    int L, R, label;
};


void solve() {
    int N;
    cin >> N;
    int len = 2 * N;
    vector<int> A(len);
    for (int i = 0; i < len; i++){
        cin >> A[i];
    }
    vector<int> L(N+1, -1), R(N+1, -1);
    for (int i = 0; i < len; i++){
        int x = A[i];
        if (L[x] == -1)
            L[x] = i;
        else
            R[x] = i;
    }
    vector<Interval> valid;
    for (int x = 1; x <= N; x++){
        if(R[x] > L[x] + 1) {
            valid.push_back({L[x], R[x], x});
        }
    }
    sort(valid.begin(), valid.end(), [](const Interval &a, const Interval &b){
        return a.L < b.L;
    });
    Fenw fenw(len);
    long long ans = 0;
    for (auto &b : valid) {
        int count = fenw.range_query(b.L + 1, b.R - 1, b.label);
        ans += count;
        fenw.update(b.R, b.label);
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}
