#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int main() {
  int tc;
  cin >> tc;
  while(tc--) {
  int n;
  cin >> n;
  long long total_weight = 0, total_strength = 0;
  vector<pair<int,int>> reindeers(n);
  for(int i = 0; i < n; i++) {
    cin >> reindeers[i].first >> reindeers[i].second;
    total_strength += reindeers[i].second;
  }
  sort(reindeers.begin(), reindeers.end(), [](pair<int,int> a, pair<int,int> b) {
      return a.first + a.second < b.first + b.second;
  });
  int max_reindeer = 0;
  for(int i=0;i<n;i++) {
    total_weight += reindeers[i].first;
    total_strength -= reindeers[i].second;
    if(total_weight <= total_strength) {
      max_reindeer = i + 1;
    }
  }
  cout << max_reindeer << endl;
  }
}
