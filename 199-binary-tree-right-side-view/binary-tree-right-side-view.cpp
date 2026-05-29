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
        
        // code here
        if(root==NULL){
            return {};
        }  
        
        queue<TreeNode*> que;
        que.push(root);
        vector<int> res;
        while(!que.empty()){
            int n=que.size();//size of the curr generation 
            res.push_back(que.front()->val);//pehle wala part of the queue in inorder is left view 
            while(n--){//check left and  right of current level 
                TreeNode* node=que.front();
                que.pop();
                if(node->right){
                    que.push(node->right);
                }
                
                if(node->left){
                    que.push(node->left);
                }
                
            }
            
        }
        return res;
    
    }
};