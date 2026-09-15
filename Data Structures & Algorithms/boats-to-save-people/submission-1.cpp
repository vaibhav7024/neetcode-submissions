class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count=0;
        int i=0;
        int j=people.size()-1;
        while(j>=0 && people[j]==limit){
            j--;
            count++;
        }
        while(i<=j){
            if(people[i]+people[j]<=limit){
                count++;
                i++;
                j--;
            }
            else if(people[i]+people[j]>limit){
                j--;
                count++;
            }
        }
        return count;
    }
};