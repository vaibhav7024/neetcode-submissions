class Solution {
public:
    int characterReplacement(string s, int k) {
        int len=0;
        unordered_map<int,int> m;
        int freq=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            freq = max(freq,m[s[i]]);
            while(i-j+1-freq>k){
                m[s[j]]--;
                j++;
            }
            len = max(i-j+1,len);
        }
        return len;
    }
};
