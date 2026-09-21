class Solution {
public:
    int mySqrt(int x) {
        int i=0,j=x;
        int ans=0;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(1LL*mid*mid<=x){
                ans = mid;
                i=mid+1;
            }else
                j=mid-1;
        }
        return ans;
    }
};