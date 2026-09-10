class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        int j=0;
        while(j<s.size()){
            bool flag = true;
            for(int i=1;i<strs.size();i++){
                if(s[j]!=strs[i][j]){
                    flag=false;
                }
            }
            if(flag)
                j++;
            else 
                break;
        }
        return s.substr(0,j);
    }
};