class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = num1;
        int n1 = __builtin_popcount(x), n2 = __builtin_popcount(num2);
        if(n1 == n2) 
            return x;
        else {
            int r = x, p = (n1 < n2) ? 0 : 1;
            int cnt = 0, bits = 31;
            while(bits-- >= 0 && n1 != n2) {
                int e = (r % 2);
                if(p==e) {
                    x ^= (1 << cnt);
                    n1+=(p == 0) ? 1 : -1;
                }
                cnt++;
                r /= 2;
            }
            return x;
        }
    }
};