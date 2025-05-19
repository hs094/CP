class Solution {
    long long MOD = 1e9+7;
public:
    long long power(long long x, long long y) 
    { 
        long long res = 1;
        x = x % MOD; 
        if (x == 0) return 0;
        while (y > 0) 
        { 
            if (y & 1ll) 
                res = (res*x) % MOD; 
            y = y>>1;
            x = (x*x) % MOD; 
        } 
        return res; 
    } 
    int countGoodNumbers(long long n) {
        long long prod = (power(4, (n)/2) * power(5, (n+1)/2)) % MOD;
        return prod;
    }
};