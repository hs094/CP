https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size(), cnt = 0;
        sort(arr.begin(), arr.end());
        for(int i=n-1;i>=2;i--) 
        {
            for(int j=i-1;j>=1;j--) {
                int t = arr[i]+arr[j], p = max(arr[i]-arr[j], arr[j]-arr[i]), ans1 = -1, ans2 = -1;
                int start = 0;
                int end = j-1;
                while(start <= end) {
                    int mid = (start+end)/2;
                    if(arr[mid] < t) {
                        ans1 = mid;
                        start = mid+1;
                    }
                    else 
                        end = mid-1;
                }
                if(ans1 == -1) continue;
                start = 0;
                end = ans1;
                while(start <= end) {
                    int mid = (start+end)/2;
                    if(arr[mid] > p) {
                        ans2 = mid;
                        end = mid-1;
                    }
                    else 
                        start = mid+1;
                }
                if(ans1 != -1 && ans2 != -1) cnt += (ans1-ans2+1);
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends