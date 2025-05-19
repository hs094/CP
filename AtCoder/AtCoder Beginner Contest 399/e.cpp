#include <bits/stdc++.h>
using namespace std;

#define MAX 200001

int parent[MAX];
int Rank[MAX];

// Find with path compression
int find(int x) {
    return parent[x] = (parent[x] == x ? x : find(parent[x]));
}

// Merge two sets by rank
void merge(int r1, int r2) {
    if(r1 != r2) {
        if(Rank[r1] > Rank[r2]) {
            parent[r2] = r1;
            Rank[r1] += Rank[r2];
        } else {
            parent[r1] = r2;
            Rank[r2] += Rank[r1];
        }
    }
}

// Function to find the minimum number of operations required
// to transform s1 into s2 using the allowed operation.
void minimumOperations(string s1, string s2) {
    int n = s1.size();
    
    // First, check that every letter in s1 consistently maps to the same letter in s2.
    // mapping[x] stores the target letter for letter (x+'a')
    vector<int> mapping(26, -1);
    for (int i = 0; i < n; i++) {
        int idx = s1[i] - 'a';
        int target = s2[i] - 'a';
        if(mapping[idx] == -1)
            mapping[idx] = target;
        else if(mapping[idx] != target) {
            // Inconsistent mapping: transformation impossible.
            cout << -1 << "\n";
            return;
        }
    }
    
    // Initialize union-find for letters 1 to 26.
    // (We use 1-indexing: letter 'a' is 1, 'b' is 2, ..., 'z' is 26)
    for (int i = 1; i <= 26; i++) {
        parent[i] = i;
        Rank[i] = 1;
    }
    
    vector<pair<char, char>> ans;
    
    // Process each position: if s1[i] != s2[i], we want to merge the two groups.
    // We also record the operation if the two letters are not already connected.
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            int a = s1[i] - 'a' + 1;  // convert to 1-indexed
            int b = s2[i] - 'a' + 1;
            if(find(a) != find(b)) {
                merge(find(a), find(b));
                ans.push_back({ s1[i], s2[i] });
            }
        }
    }
    
    // Output the number of operations and each operation.
    cout << ans.size() << "\n";
    for (auto &p : ans)
        cout << p.first << "->" << p.second << "\n";
}
  
// Driver code
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s1, s2;
    // Example test case; you can change these to test further.
    cin >> s1 >> s2;
    minimumOperations(s1, s2);
    return 0;
}
