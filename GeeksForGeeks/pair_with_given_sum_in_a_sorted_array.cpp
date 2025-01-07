// https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int findFirst(vector<int> &arr, int l, int r, int &t) {
        int ans = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(arr[mid] == t) {
                ans = mid;
                r = mid-1;
            }
            else if(arr[mid] < t) l = mid+1;
            else r = mid-1;
        }
        return ans;
    }
    int findLast(vector<int> &arr, int l, int r, int &t) {
        int ans = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(arr[mid] == t) {
                ans = mid;
                l = mid+1;
            }
            else if(arr[mid] < t) l = mid+1;
            else r = mid-1;
        }
        return ans;
    }
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int cnt = 0, n = arr.size();
        for(int i=0;i<n;i++) {
            int t = target-arr[i];
            int start = findFirst(arr, i+1, n-1, t);
            if(start == -1) continue;
            cnt += findLast(arr, start, n-1, t)-start+1;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends