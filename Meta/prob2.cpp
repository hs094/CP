#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rankv;
    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;
        vector<long long> A(N + 1);
        for (int i = 1; i <= N; ++i) cin >> A[i];
        vector<tuple<long long, int, int>> edges;
        edges.reserve(2 * N);
        for (int i = 1; i <= N; ++i)
            edges.push_back({A[i], 0, i});
        for (int i = 1; i < N; ++i)
            edges.push_back({abs(A[i] - A[i + 1]), i, i + 1});
        sort(edges.begin(), edges.end());
        DSU dsu(N + 1);
        long long ans = 0;
        int count = 0;
        for (auto &[w, u, v] : edges) {
            if (dsu.unite(u, v)) {
                ans = max(ans, w);
                count++;
                if (count == N) break;
            }
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    return 0;
}