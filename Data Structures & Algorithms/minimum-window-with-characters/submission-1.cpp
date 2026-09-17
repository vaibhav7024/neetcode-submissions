class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        unordered_map<char,int> seen;
        for(char c:t){
            m[c]++;
        }
        int need=m.size();
        int count=0,start=0;;
        int len=INT_MAX;
        int i=0;
        for(int j=0;j<s.size();j++){
            int c=s[j];
            seen[c]++;
            if(m.count(c)&& m[c]==seen[c]){
                count++;
            }
            while(count>=need){
                if(j-i+1<len){
                    len = min(len,j-i+1);
                    start=i;
                }
                seen[s[i]]--;
                if(seen[s[i]]<m[s[i]]){
                    count--;
                }
                i++;
            }
        }
        return len==INT_MAX?"":s.substr(start,len);
    }
};
