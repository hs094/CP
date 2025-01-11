class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        int bitmask = 0;
        for(char c: s) 
            bitmask ^= (1 << (c-'a'));
        return __builtin_popcount(bitmask) <= k;
    }
};