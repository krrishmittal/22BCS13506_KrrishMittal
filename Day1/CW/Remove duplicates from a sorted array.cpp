class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int sz=1;
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[sz-1]){
                sz++;
                nums[sz-1]=nums[i];
            }
        }
        return sz;
    }
};