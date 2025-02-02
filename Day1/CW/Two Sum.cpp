class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int sum=target-arr[i];
            if(mp.find(sum)!=mp.end()){
                ans.push_back(mp[sum]);
                ans.push_back(i);
            }
            mp[arr[i]]=i;
        }
        return ans;
    }
};