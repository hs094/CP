// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2025-11-03
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), ans = 0;
        for(int i=0;i<n;i++) {
            int j=i+1, sum = neededTime[i], mx = neededTime[i];
            while(j<n && colors[i] == colors[j]) {
                mx = max(mx, neededTime[j]);
                sum += neededTime[j];
                j++;
            }
            if((j-i)>=1)
                ans += (sum - mx);
            i = j-1;
        }
        return ans;
    }
};
