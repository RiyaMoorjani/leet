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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        vector<double> ans;
        while(!q.empty()){
            int size=q.size();
            long  long sum=0;int cnt=0;
            while(size>0){
                TreeNode* curr=q.front();
                q.pop();
                sum+=curr->val;
                
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                size--;
                cnt++;
            }
            double avg=(double)sum/cnt;
            ans.push_back(avg);
        }
        return ans;
    }
};