class Solution {
    vector<int> prime;
    void seive(int n) {
        prime.resize(n+1, 1);
        prime[0] = 0, prime[1] = 0;
        for(int p=2;p*p<=n;p++) 
        {
            if(prime[p]) {
                for(int j=p*p;j<=n;j+=p) {
                    prime[j] = 0;
                }
            }
        }
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans = {-1, -1};
        seive(right);
        int slast = -1, last = -1;
        int min_diff = INT_MAX;
        for(int j=left;j<=right;j++) {
            if(prime[j]) {
                if(slast == -1 && last == -1) {
                    last = j;
                }
                else {
                    slast = last;
                    last = j;
                    if(last-slast < min_diff) {
                        min_diff = last-slast;
                        ans = {slast, last};
                    }
                }
            }
        }
        return ans;
    }
};