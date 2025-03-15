// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1?page=1&category=Dynamic%20Programming&status=unsolved,attempted&sortBy=submissions
//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        vector<int> ans;
        sort(deadline.begin(), deadline.end());
        int start = 0;
        for(int i=0;i<deadline.size();) {
            while(start+1 > deadline[i]) {
                i++;
            }
            start++;
        }
        ans.push_back(start);
    }
};



//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends