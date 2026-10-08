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
    int levelOrder(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()!=NULL){
            int sum=0;
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
            sum+=current->val;
            }
            ans.push_back(sum);

        }
        int n=ans.size();
        int max=ans[0];
        int maxindex=0;
        for(int i=1;i<n;i++){
            if(ans[i]>max){
                max=ans[i];
                maxindex=i;
            }

        }
        return maxindex+1;
    }
    int maxLevelSum(TreeNode* root) {
        return levelOrder(root);

    }
};
