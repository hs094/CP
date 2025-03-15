class Solution {
public:
    long long coloredCells(int n) {
        long long t1 = n, t2 = n-1;
        return t1*t1+t2*t2;
    }
};