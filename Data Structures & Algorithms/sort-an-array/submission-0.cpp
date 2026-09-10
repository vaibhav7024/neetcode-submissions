class Solution {
public:
    void merge(vector<int>& v,int i, int mid, int j){
        vector<int> temp;
        int k=i;
        int p=mid+1;
        while(i<=mid && p<=j){
            if(v[i]<=v[p]){
                temp.push_back(v[i++]);
            }else{
                temp.push_back(v[p++]);
            }
        }
        while(i<=mid){
            temp.push_back(v[i++]);
        }
        while(p<=j){
            temp.push_back(v[p++]);
        }
        for(int a=0;a<temp.size();a++){
            v[k++]=temp[a];
        }
    }
    void mergesort(vector<int>& v , int i, int j){
        if(i>=j) return ;
        int mid = (j+i)/2;
        mergesort(v,i,mid);
        mergesort(v,mid+1,j);
        return merge(v,i,mid,j);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};