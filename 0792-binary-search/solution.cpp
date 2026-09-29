class Solution {
private:
int Bn(vector<int> &nums,int target,int low,int high){
    int mid=(low+high)/2;
    if(low<=high){
    if (nums[mid]==target) return mid;
    else if(nums[mid]<target){
        return Bn(nums,target,mid+1,high);
    }
    else{
        return Bn(nums,target,low,mid-1);
    }
    }
    else{
        return -1;
    }
}
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return Bn(nums,target,0,n-1);

    }
};
