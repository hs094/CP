#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    vector<bool> appear(26, false);
    vector<int> f(26, -1);
    for (int i = 0; i < N; i++){
        int c = S[i] - 'a';
        int t = T[i] - 'a';
        appear[c] = true;
        if(f[c] == -1) {
            f[c] = t;
        } else {
            if(f[c] != t){
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    for (int c = 0; c < 26; c++){
        if(!appear[c])
            f[c] = c;
        if(f[c] == -1)
            f[c] = c;
    }
    int m = 0;
    for (int c = 0; c < 26; c++)
        if(f[c] != c) m++;
    int cycles = 0;
    vector<int> state(26, 0); 
    function<void(int)> dfs = [&](int v) {
        state[v] = 1;
        int nxt = f[v];
        if(nxt != v){ 
            if(state[nxt] == 0){
                dfs(nxt);
            } else if(state[nxt] == 1){
                cycles++;
            }
        }
        state[v] = 2;
    };
    for (int c = 0; c < 26; c++){
        if(state[c] == 0){
            dfs(c);
        }
    }
    cout << m + cycles << "\n";
    return 0;
}
