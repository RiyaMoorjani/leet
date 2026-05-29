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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }  
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            int n=que.size();
            vector<int> res;
            while(n--){//check left and  right of current level 
                TreeNode* node=que.front();
                que.pop();
                
                res.push_back(node->val);
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }
            ans.push_back(res);
        }
        return  ans;
    }
};