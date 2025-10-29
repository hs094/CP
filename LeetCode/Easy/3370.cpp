// https://leetcode.com/problems/smallest-number-with-all-set-bits/description/?envType=daily-question&envId=2025-10-29
#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int smallestNumber(int n) {
//         int ans = 0;
//         while(n) {
//             ans = (ans * 2) + 1;
//             n /= 2;
//         }
//         return ans;
//     }
// };

// Most Optimized or Refactored Code
class Solution {
public:
    int smallestNumber(int n) {
        return ((1 << (int(floor(log2(n)))+1)) - 1);
    }
};

int main() {
    Solution sol;
    int n = 12;
    cout << sol.smallestNumber(n) << endl; // Output: 15
    return 0;
}
