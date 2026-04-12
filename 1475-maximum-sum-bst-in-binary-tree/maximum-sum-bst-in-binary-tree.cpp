/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class info {
public:
    int maxi;
    int mini;
    bool bst;
    int sum;
};

info solve(TreeNode* root, int &ans) {
    // Base case
    if (root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currnode;

    // Check BST condition
    if (left.bst && right.bst &&
        root->val > left.maxi && root->val < right.mini) {

        currnode.bst = true;
        currnode.sum = left.sum + right.sum + root->val;
        currnode.maxi = max(root->val, right.maxi);
        currnode.mini = min(root->val, left.mini);

        // Update answer
        ans = max(ans, currnode.sum);
    }
    else {
        currnode.bst = false;
        currnode.sum = 0;
        currnode.maxi = INT_MAX;
        currnode.mini = INT_MIN;
    }

    return currnode;
}

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};