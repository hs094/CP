#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    vector<int> x(N+1);
    vector<long long> y(N+1);
    for (int i = 1; i <= N; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<unordered_map<long long,int>> children;
    children.reserve(N+1);
    children.emplace_back(); 
    vector<int> trieOf(N+1);     
    trieOf[0] = 0;
    vector<vector<int>> indices;    
    indices.reserve(N+1);
    indices.emplace_back(); 
    int nodes = 1; 
    for (int i = 1; i <= N; ++i) {
        int parentTrie = trieOf[x[i]];
        long long label = y[i];
        auto it = children[parentTrie].find(label);
        if (it != children[parentTrie].end()) {
            trieOf[i] = it->second;
        } else {
            trieOf[i] = nodes++;
            children.emplace_back();
            indices.emplace_back();
            children[parentTrie].emplace(label, trieOf[i]);
        }
        indices[trieOf[i]].push_back(i);     
    }
    vector<vector<pair<long long,int>>> edges(nodes);
    for (int v = 0; v < nodes; ++v) {
        edges[v].reserve(children[v].size());
        for (auto &p : children[v]) edges[v].push_back(p);
        sort(edges[v].begin(), edges[v].end(), [](auto &a, auto &b){
            return a.first < b.first;
        });
    }
    vector<int> result;
    result.reserve(N);
    function<void(int)> dfs = [&](int v) {
        for (int idx : indices[v]) result.push_back(idx);
        for (auto &e : edges[v]) dfs(e.second);
    };
    dfs(0);
    for (int i = 0; i < (int)result.size(); ++i) {
        if (i) cout << ' ';
        cout << result[i];
    }
    cout << '\n';
    return 0;
}

