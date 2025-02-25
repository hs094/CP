class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        string ans = "";
        for(int i=0;i<min(a.size(), b.size());i++) {
            int x = a[i]-'0'+b[i]-'0'+carry ;
            if(x == 3) {
                ans.push_back('1');
                carry = 1;
            }
            else if(x == 2) {
                ans.push_back('0');
                carry = 1;
            }
            else if(x == 1) {
                ans.push_back('1');
                carry = 0;
            }
            else {
                ans.push_back('0');
                carry = 0;
            }
        }
        for(int i=min(a.size(), b.size());i<a.size();i++) {
            int y = a[i]-'0'+carry;
            if(y == 2) {
                ans.push_back('0');
                carry = 1;
            }
            else if(y == 1) {
                ans.push_back('1');
                carry = 0;
            }
            else {
                ans.push_back('0');
                carry = 0;
            }
        }
        for(int i=min(a.size(), b.size());i<b.size();i++) {
            int y = b[i]-'0'+carry;
            if(y == 2) {
                ans.push_back('0');
                carry = 1;
            }
            else if(y == 1) {
                ans.push_back('1');
                carry = 0;
            }
            else {
                ans.push_back('0');
                carry = 0;
            }
        }
        if(carry > 0) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};