#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x)
    {
        // code here
        for (int i = 0; i < mat.size(); i++)
        {
            if (mat[i][0] <= x)
            {
                int start = 0;
                int end = mat[0].size() - 1;
                while (start <= end)
                {
                    int mid = start + (end - start) / 2;
                    if (mat[i][mid] == x)
                        return true;
                    else if (mat[i][mid] < x)
                        start = mid + 1;
                    else
                        end = mid - 1;
                }
            }
        }
        return false;
    }
};

// Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++)
        {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }
        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << "\n";
        return 0;
    }