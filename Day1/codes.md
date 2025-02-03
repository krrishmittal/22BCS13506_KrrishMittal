# Arrays Problems

## 1. Remove duplicates from a sorted array  
**Question:** Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums..  
**Link:** [Remove duplicates from a sorted array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)  
**Solution:**  
```cpp
int removeDuplicates(vector<int>& nums){
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
```
**Screenshot:**  
![alt text](./images/image.png)

---

## 2. Implementing insertion sort  
**Question:** The task is to complete the insertsort() function which is used to implement Insertion Sort..  
**Link:** [Insertion Sort](https://www.geeksforgeeks.org/problems/insertion-sort/1)  
**Solution:**  
```cpp
void insertionSort(vector<int>& arr) {
        // code here
    for(int i=1;i<arr.size();i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
```
**Screenshot:**  
![alt text](./images/image-1.png) 

---

## 3. Contains duplicate  
**Question:** Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

**Link:** [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/)  
**Solution:**  
```cpp
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]){
            return true;
        }
    }
    return false;
}
```
**Screenshot:**  
![alt text](./images/image-2.png)

---

## 4. Two Sum
**Question:** Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. 

**Link:** [Two Sum](https://leetcode.com/problems/two-sum/description/)  
**Solution:**  
```cpp
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
```
**Screenshot:**  
![alt text](./images/image-3.png)  

---

## 5. Jump Game
**Question:** You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.  
**Link:** [Jump Game](https://leetcode.com/problems/jump-game/description/)  
**Solution:**  
```cpp
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
```
**Screenshot:**  
![alt text](./images/image-4.png)

---

## 6. Majority Element  
**Question:** Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

**Link:** [ Majority Element](https://leetcode.com/problems/majority-element/description/)  
**Solution:**  
```cpp
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
```
**Screenshot:**  
![alt text](./images/image-5.png)

---

## 7. Valid Palindrome
**Question:** A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.  
**Link:** [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/description/)  
**Solution:**  
```cpp
bool isPalindrome(string s) {
    string res;
    for(int i = 0;i<s.length();i++){
        if(((int)s[i] > 64 && (int)s[i] < 91) || ((int)s[i] > 96 && (int)s[i] < 123) || ((int)s[i] > 47 && (int)s[i] < 58)){
            res+=tolower(s[i]);
        }
    }
    string check=res;
    reverse(res.begin(),res.end());
    cout<<res;
    if(res==check)
        return true;
    return false; 
}
```
**Screenshot:**  
![alt text](./images/image-6.png)

---

## 8. Jump Game 2 
**Question:** You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:  
**Link:** [Jump Game II](https://leetcode.com/problems/jump-game-ii/description/)  
**Solution:**  
```cpp
int jump(vector<int>& nums) {
    int near = 0, far = 0,jumps = 0;
    while (far < nums.size() - 1) {
        int farthest = 0;
        for (int i = near; i <= far; i++) {
            farthest = max(farthest, i + nums[i]);
        }
        near = far + 1;
        far = farthest;
        jumps++;
    }
    return jumps;        
}
```
**Screenshot:**  
![alt text](./images/image-7.png)

---

## 9. 3Sum 
**Question:** Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.  
**Link:** [3Sum](https://leetcode.com/problems/3sum/description/)  
**Solution:**  
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            int total = nums[i] + nums[j] + nums[k];
            if (total > 0) {
                k--;
            } else if (total < 0) {
                j++;
            } else {
                res.push_back({nums[i], nums[j], nums[k]});
                j++;
                while (nums[j] == nums[j-1] && j < k) {
                    j++;
                }
            }
        }
    }
    return res;       
}
```
**Screenshot:**  
![alt text](./images/image-8.png)

---

## 10. Set Matrix Zeroes  
**Question:** Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.  
**Link:** [ Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/description/)  
**Solution:**  
```cpp
void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==1 || col[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }
```
**Screenshot:**  
![alt text](./images/image-9.png) 

---

## 11. Longest substring without repeating characters 
**Question:** Given a string s, find the length of the longest 
substring
 without repeating characters.  
**Link:** [Longest substring without repeating characters ](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)  
**Solution:**  
```cpp
int lengthOfLongestSubstring(string s) {
    int left = 0;
    int maxLength = 0;
    unordered_set<char> charSet;
    for (int right = 0; right < s.length(); right++) {
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            left++;
        }
        charSet.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength; 
}
```
**Screenshot:**  
![alt text](./images/image-10.png)

---

## 12. Find the Duplicate Number 
**Question:** Sort a linked list in ascending order.  
**Link:** [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/description/)  
**Solution:**  
```cpp
int findDuplicate(vector<int>& nums) {
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        if(mp[nums[i]]==1){
            return nums[i];
        }
        else{
            mp[nums[i]]++;
        }
    }
    return -1;
}
```
**Screenshot:**  
![alt text](./images/image-11.png) 

```
```
