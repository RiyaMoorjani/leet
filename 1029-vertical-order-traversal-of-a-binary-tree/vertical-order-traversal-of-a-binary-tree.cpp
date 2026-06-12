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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int ,map<int,vector<int>>> node;
        queue<pair<TreeNode* , pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            TreeNode* frontnode=temp.first;
            int hd=temp.second.first;
            int level=temp.second.second;
            node[hd][level].push_back(frontnode->val);
            if(frontnode->left){
                q.push({frontnode->left,{hd-1,level+1}});
            }
            if(frontnode->right){
                q.push({frontnode->right,{hd+1,level+1}});
            }
        }
        for( auto i:node){
            vector<int> col;
            for(auto j: i.second){
                sort(j.second.begin(), j.second.end());
                for(auto k : j.second){
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};