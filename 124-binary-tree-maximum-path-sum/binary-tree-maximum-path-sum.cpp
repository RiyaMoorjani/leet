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
    int findmaxpathsum(TreeNode* root,int &maxi){
        if(root==NULL){
            return 0;
        }
        int l=findmaxpathsum(root->left,maxi);
        int r=findmaxpathsum(root->right,maxi);
        //options
        int ek_side_acha=max(l,r)+root->val;
        int root_acha_hai=root->val;
        int neech_ek_cycle =l+r+root->val;//iss case me upar ke nodes explore nahi kar sakte 
        maxi=max(maxi,max({ek_side_acha,root_acha_hai,neech_ek_cycle}));
        return max(ek_side_acha,root_acha_hai);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        findmaxpathsum(root,maxi);
        return maxi;
    }
};