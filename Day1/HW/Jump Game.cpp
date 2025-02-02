class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxreach=0;
        for(int i=0;i<n;i++){
            if(i>maxreach){
                return false;
            }
            maxreach=max(maxreach,nums[i]+i);
        }
        return true;
    }
};