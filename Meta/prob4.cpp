#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

// modular exponentiation
long long modpow(long long a, long long b) {
    long long res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// inverse mod
long long modinv(long long a) { return modpow(a, MOD - 2); }

// compute C(N+e-1, e) with large N small e
long long binom_largeN(long long N, int e) {
    long long num = 1;
    for (int i = 0; i < e; i++)
        num = num * ((N + i) % MOD) % MOD;
    long long den = 1;
    for (int i = 1; i <= e; i++)
        den = den * i % MOD;
    return num * modinv(den) % MOD;
}

// factorize number
vector<pair<long long,int>> factorize(long long n) {
    vector<pair<long long,int>> f;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            int e = 0;
            while (n % p == 0) n /= p, ++e;
            f.push_back({p, e});
        }
    }
    if (n > 1) f.push_back({n, 1});
    return f;
}

// compute f(M, N)
long long f_of(long long M, long long N) {
    auto f = factorize(M);
    long long res = 1;
    for (auto [p, e] : f)
        res = res * binom_largeN(N, e) % MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        long long N, A, B;
        cin >> N >> A >> B;
        auto fB = factorize(B);
        vector<long long> divisors = {1};
        // generate divisors
        for (auto [p, e] : fB) {
            vector<long long> next;
            long long mul = 1;
            for (int i = 0; i <= e; i++) {
                for (auto d : divisors)
                    next.push_back(d * mul);
                mul *= p;
            }
            divisors.swap(next);
        }

        long long ans = 0;
        for (auto d : divisors) {
            if (d <= A) {
                long long term = f_of(d, N) * f_of(B / d, N) % MOD;
                ans = (ans + term) % MOD;
            }
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    return 0;
}