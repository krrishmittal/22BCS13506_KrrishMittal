class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int count=nums.size()/2;
        for (int num:nums) {
            mp[num]++;
            if (mp[num]>count) {
                return num;
            }
        }
        return -1;
    }
};