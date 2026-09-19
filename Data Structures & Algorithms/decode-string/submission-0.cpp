class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> text;
        int curr = 0;
        string temp="";
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(isdigit(c)){
                curr=curr*10+s[i]-'0';
            }else if(c=='['){
                text.push(temp);
                num.push(curr);
                temp.clear();
                curr=0;
            }else if(c==']'){
                string f="";
                int occ=num.top();num.pop();
                while(occ--){
                    f+=temp;
                }
                temp =text.top()+f;
                text.pop();
            }else{
                temp.push_back(c);
            }
        }
        return temp;
    }
};