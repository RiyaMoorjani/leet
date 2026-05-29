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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            
            int n=q.size();
            res.push_back(q.front()->val);//right view will be the front of que so first pusjh that 
            while(n--){//go left and  right of the curr level 
                TreeNode* node=q.front();
                q.pop();
                if(node->right){//to get right at front we pushh right first 
                    q.push(node->right);
                }
                if(node->left){
                    q.push(node->left);
                }
            }
        }
        
        return res;
    }
};