#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool flag;
    int findH(TreeNode* root) {
        if(root == NULL)
            return 0;
        else
            return 1+max(findH(root->left), findH(root->right));
    }
    void inorder(TreeNode* root) {
        if(root == NULL) 
            return 0;
        
    }
public:
    bool isBalanced(TreeNode* root) {
        flag = true;
        inorder(root);

    }
};

int giveNumber(string s, int& i) {
    int num = 0;
    while(i < s.size() && (s[i] != ',' || s[i] != ']')) {
        num = num*10 + (s[i]-'0');
        i++;
    }
    i++;
    return num;
}
TreeNode* formTree(string s) {
    if(s.size() == 0)
        return NULL;
    int i = 0;
    string temp = "";
    TreeNode* root = new TreeNode();
    i += 
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < s.size()) {
        TreeNode* temp = q.front();
        q.pop();
        if(s[i] != 'n') {
            temp->left = new TreeNode(s[i]-'0');
            q.push(temp->left);
        }
        i++;
        if(i < s.size() && s[i] != 'n') {
            temp->right = new TreeNode(s[i]-'0');
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

int main() {
    string s;
    cin >> s;
    TreeNode* root = formTree(s);
    Solution sol;
    cout << sol.isBalanced(root) << endl;
    return 0;
}