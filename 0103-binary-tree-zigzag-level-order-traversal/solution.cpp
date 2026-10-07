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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        
        while(q.size()!=NULL){
            vector<int> level;
            int size=q.size();
            for(int i=0;i<size;i++){
            TreeNode* current =q.front();
            q.pop();
            if(current->left != NULL){
                q.push(current-> left);
                
            }
            if(current-> right!=NULL){
                q.push(current-> right);
            }
            level.push_back(current->val);
            
            }
            if(i%2==0) reverse(level.begin(),level.end());
            ans.push_back(level);
            i++;
        }
        return ans;
        
    }
};
