class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        while(j<n){
            int num = nums2[j++];
            int i=m-1;
            while(i>=0 && num<nums1[i]){
                nums1[i+1]=nums1[i];
                i--;
            }
            nums1[i+1]=num;
            m++;
        }
    }
};