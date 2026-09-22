class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int tlen = n+m;
        bool odd = tlen%2;
        int half = odd ? ceil(tlen/2.0): tlen/2 +1;
        vector<int> sorted ;
        int i=0,j=0;
        while(sorted.size()<half && i<m && j<n){
            if(nums1[i]<nums2[j]){
                sorted.push_back(nums1[i++]);
            }else{
                sorted.push_back(nums2[j++]);
            }
        }
        while(sorted.size()<half && i<m)
            sorted.push_back(nums1[i++]);
        while(sorted.size()<half && j<n)
            sorted.push_back(nums2[j++]);
        double median =0;
        if(odd){
            median = sorted[sorted.size()-1];
        }else{
            median = (sorted[sorted.size()-1]+sorted[sorted.size()-2])/2.0;
        }
        for(int num:sorted){
            cout<<" "<<num;
        }
        return median;
    }
};
