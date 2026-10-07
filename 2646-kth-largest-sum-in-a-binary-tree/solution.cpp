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
     vector<long long> levelOrdersum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
         vector<long long> levelsum;
        
        while(q.size()!=0){
            long long sum=0;
           
            long long size=q.size();
            for(long long i=0;i<size;i++){
            TreeNode* current =q.front();
            q.pop();
            if(current->left != NULL){
                q.push(current-> left);
                
            }
            if(current-> right!=NULL){
                q.push(current-> right);
            }
            sum=sum+ current->val;
            }
            
            levelsum.push_back(sum);
        }
        return levelsum;
    }
     long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>ans=levelOrdersum(root);
        sort(ans.begin(),ans.end());
        int n=ans.size();
        if(n<k)return -1;
        else{
            return ans[n-k];
        }
        
        
        
    }
};
