class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        unordered_map<char,int> set;
        int len=1;
        int i=0;

        for(int j=0;j<s.size();j++){
            if(set.count(s[j])){
                i = max(set[s[j]]+1,i);
            }
            
            set[s[j]]=j;
            len = max(len,j-i+1);

        }
        return len;
    }
};
