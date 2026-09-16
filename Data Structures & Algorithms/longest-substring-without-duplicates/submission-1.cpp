class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        unordered_set<char> set;
        int len=1;
        int i=0;

        for(int j=0;j<s.size();j++){
            while(set.count(s[j])){
                set.erase(s[i++]);
            }
            
            set.insert(s[j]);
            len = max(len,j-i+1);

        }
        return len;
    }
};
