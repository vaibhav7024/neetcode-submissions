class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m;
        for(char c:s1){
            m[c]++;
        }
        unordered_map<char,int> seen;
        int k=s1.size();
        for(int i=0;i<s2.size();i++){
            seen[s2[i]]++;
            if(i-k>=0){
                seen[s2[i-k]]--;
                if(seen[s2[i-k]]==0){
                    seen.erase(s2[i-k]);
                }
            }
            if(seen==m) return true;
        }
        return false;
    }
};
