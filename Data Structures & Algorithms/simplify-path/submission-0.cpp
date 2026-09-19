class Solution {
public:
    string simplifyPath(string path) {
        vector<string> temp;
        string token;
        stringstream ss(path);
        while(getline(ss,token,'/')){
            if(token=="" || token=="."){
                continue;
            }else if(token==".."){
                if(!temp.empty())
                    temp.pop_back();
            }else{
                temp.push_back(token);
            }
        }
        string res="";
        int i=0;
        while(i<temp.size()){
            res+="/"+temp[i++];
        }
        return res.empty()?"/":res;
    }
};