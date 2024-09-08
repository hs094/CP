// https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        vector<int> c(3,0);
        int n = arr.size();
        for(int i=0;i<n;i++) {
            c[arr[i]]++;
        }
        int idx=0;
        for(int i=0;i<n;i++) {
            if(c[idx] <= 0)
                idx = idx+1;
            if(c[idx] <= 0)
                idx = idx+1;
            arr[i] = idx;
            c[idx]--;
        }
    }
};