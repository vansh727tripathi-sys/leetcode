class Solution {
public:
    int firstoccur(vector<int> &nums,int target,int n){
            int low=0;
            int high=n-1;
            int first=-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(nums[mid]==target){
                    first=mid;
                    high=mid-1;
                    }
                else if(nums[mid]<target){
                    low=mid+1;
                    }
                else{
                    high=mid-1;
                }
                }
            return first;
            }
    int lastoccur(vector<int> &nums,int target,int n){
            int low=0;
            int high=n-1;
            int last=-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(nums[mid]==target){
                    last=mid;
                    low=mid+1;
                    }
                else if(nums[mid]<target){
                    low=mid+1;
                    }
                else{
                    high=mid-1;
                }
                }
            return last;
            }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        int firocc=firstoccur(nums,target,n);
        if(firocc==-1){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
            }
        ans.push_back(firocc);
        ans.push_back(lastoccur(nums,target,n));
        return ans;
    }
};
