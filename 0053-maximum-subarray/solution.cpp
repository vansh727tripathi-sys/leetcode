class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msum=INT_MIN;
        int csum=0;
        for(int val: nums){
            csum+=val;
            msum=max(csum,msum);
            if(csum<0){
                csum=0;
            }
        }
        return msum;
        
    }
};
