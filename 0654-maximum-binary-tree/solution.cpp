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
    int search(vector<int>&nums,int begin,int end){
        int maxele=nums[begin];
        int maxind=begin;
        for(int i=begin;i<=end;i++){
            if(nums[i]>maxele){
                maxele=nums[i];
                maxind=i;
            }
        }
        return maxind;
        }

    TreeNode* helper(vector<int>&nums,int begin,int end){
        if(begin>end)return nullptr;
        
        int index=search(nums,begin,end);
        TreeNode*root=new TreeNode(nums[index]);
        root->left=helper(nums,begin,index-1);
        root->right=helper(nums,index+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
        
    }
};
