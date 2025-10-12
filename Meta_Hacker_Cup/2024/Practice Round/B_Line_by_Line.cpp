#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

long long modular_exponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long double calculate_expression_modular(int N, int P) {
    long double root_result = exp((ld)(2 * log(10) + (N - 1) * log((ld)P)) / (ld)N);
    return root_result - P;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
    freopen("line_by_line_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++) {
        int N, P;
        cin >> N >> P;
        cout << "Case #" << it << ": " << calculate_expression_modular(N, P) << endl;
    }
    return 0;
}
