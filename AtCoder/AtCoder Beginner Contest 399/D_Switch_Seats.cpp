#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(pair<int,int> a, pair<int,int> b) {
    return (a.first+1 == b.first && a.second+1 == b.second) ||
           (a.first == b.first+1 && a.second == b.second+1) || 
           (a.first+1 == b.first && a.second+1 == b.second) ||
           (a.first == b.first+1 && a.second+1 == b.second);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int len = 2 * N;
        vector<int> A(len);
        for (int i = 0; i < len; i++)
            cin >> A[i];
        vector<int> L(N+1, -1), R(N+1, -1);
        for (int i = 0; i < len; i++){
            if (L[A[i]] == -1)
                L[A[i]] = i;
            else
                R[A[i]] = i;
        }
        vector<pair<int,int>> valid;
        for (int x = 1; x <= N; x++)
            if (R[x] > L[x] + 1)
                valid.push_back({L[x], R[x]});
        sort(valid.begin(), valid.end());
        int ans = 0;
        for (size_t i = 0; i + 1 < valid.size(); i++){
            if(check(valid[i], valid[i+1]))
                ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
