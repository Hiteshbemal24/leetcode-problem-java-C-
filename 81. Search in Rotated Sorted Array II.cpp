class Solution {
public:
    int pivot(vector<int>& nums){
        int s=0,e=nums.size()-1;
        while(s<e){
            if(e-1>=0&& nums[e-1]>nums[e])
                return e-1;
            e--;
        }
        return 0;
    }
    bool binary(vector<int>& nums,int& target,int s,int e){
        int mid=0;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==target)
            return true;
            else if(nums[mid]<target)
            s=mid+1;
            else
            e=mid-1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        if(nums[0]==target)
            return true;
        int pvt=pivot(nums);
        bool ans1=false, ans2=false;
        if(target>=nums[0]&& target<=nums[pvt])
        ans1=binary(nums,target,0,pvt);
        else
        ans2=binary(nums,target,pvt+1,nums.size()-1);
    return ans1||ans2;
    }
};
