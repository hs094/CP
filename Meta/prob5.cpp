#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;

// Computes sum_{k=1}^{N} k * (N-k+1)
ll total_subarray_lengths(int N) {
    // = N * (N+1) * (N+2) / 6
    return (ll)N * (N + 1) * (N + 2) / 6;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        int N; cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        ll total = 0;
        for (int k = 1; k <= N; ++k)
            total += (ll)k * (N - k + 1);

        // Prefix XOR map
        unordered_map<int, vector<int>> xor_indices;
        int px = 0;
        xor_indices[0].push_back(-1);
        vector<int> prefix_xor(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            px ^= A[i];
            prefix_xor[i + 1] = px;
            xor_indices[px].push_back(i);
        }
        // All XOR==0 subarrays (including all-zero)
        ll xor0_subarrays = 0;
        for (auto& [val, idxs] : xor_indices) {
            ll c = idxs.size();
            xor0_subarrays += c * (c - 1) / 2;
        }

        // All-zero subarrays and their lengths
        ll allzero_subarrays = 0;
        ll allzero_len_sum = 0;
        vector<vector<int>> allzero_ranges;
        for (int i = 0; i < N;) {
            if (A[i] == 0) {
                int j = i;
                while (j < N && A[j] == 0) ++j;
                ll L = j - i;
                allzero_subarrays += L * (L + 1) / 2;
                allzero_len_sum += L * (L + 1) * (L + 2) / 6;
                i = j;
            } else {
                ++i;
            }
        }

        // So, total cost:
        // total - allzero_len_sum - (xor0_subarrays - allzero_subarrays)
        ll answer = total - allzero_len_sum - (xor0_subarrays - allzero_subarrays);

        cout << "Case #" << case_num << ": " << answer << "\n";
    }
    return 0;
}