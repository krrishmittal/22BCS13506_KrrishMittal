class Solution {
public:
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
};