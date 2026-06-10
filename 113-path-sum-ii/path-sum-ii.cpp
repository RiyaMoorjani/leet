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
class Solution {
public:
    void dfs(TreeNode* root, int targetSum,vector<vector<int>>& ans,vector<int>& res){
        if(root==NULL){
            return;
        }
        res.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(targetSum==root->val){
                ans.push_back(res);
            }
        }
        dfs(root->left,targetSum-root->val,ans,res);
        dfs(root->right,targetSum-root->val,ans,res);
        res.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> res;
        dfs(root,targetSum,ans,res);
        return ans;
    }
};