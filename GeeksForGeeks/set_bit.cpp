class Solution
{
  public:
    int replaceBit (int n, int k)
    {
        int bitnum = int(log2(n)) + 1;
        return n & ~( (1<<(bitnum)) >> k);
    }
};