// https://www.geeksforgeeks.org/problems/powx-n/1
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
        double ans = 1.0;
        int E = e;
        if(e % 2 && b < 0) ans *= -1;
        b = abs(b), e = abs(e);
        while(e > 0) {
            if(e & 1)
                ans = (ans * b);
            b = b * b;
            e /= 2;
        }
        return E > 0 ? ans : 1.0/(ans);
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends