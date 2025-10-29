#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int sumDivisibleByK(vector<int> &nums, int k) {
      cout << nums.size() << " " << k << endl; 
      map<int,int> m;
      for(int i=0;i<nums.size();i++) m[nums[i]]++;
      int sum = 0;
      for(auto it: m)  {
        if(it.second % k == 0) { 
          sum += (it.first * it.second);
        }
      }
      return sum;
    }
};

int main() {
  Solution* obj = new Solution();
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];
  cout << obj->sumDivisibleByK(v, k) << endl;
  return 0;
}
