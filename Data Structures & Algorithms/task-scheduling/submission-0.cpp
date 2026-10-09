class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        for(char c:tasks){
            count[c-'A']++;
        }
        sort(count.begin(),count.end());
        int maxf = count[25];
        int idle = (maxf-1)*n;
        for(int i=24;i>=0;i--){
            idle-= min(count[i],maxf-1);
        }
        return max(0,idle)+size(tasks);
    }
};
