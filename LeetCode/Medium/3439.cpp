#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int sum = 0, start = 0, end = -1, n = startTime.size();
        for(int i=0;i<k;i++) {
            sum += endTime[i]-startTime[i];
        }
        end = (k >= n ? eventTime : startTime[k]);
        int mx = max(startTime[0], end-start-sum);
        mx = max(mx, eventTime-endTime[n-1]);
        for(int i=k;i<n;i++) {
            sum -= (endTime[i-k]-startTime[i-k]);
            sum += (endTime[i]-startTime[i]);
            start = endTime[i-k];
            end = (i+1 >= n ? eventTime : startTime[i+1]);
            mx = max(mx, end-start-sum);
        }
        return mx;
    }
};