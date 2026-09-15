class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int water=0;
        for(int i=0;i<height.size();i++){
            while(!st.empty() && height[st.top()]<height[i]){
                int bottom = height[st.top()];st.pop();
                if(st.empty()) break;
                int left  = st.top();
                int right = i;
                int h = min(height[left],height[right])-bottom;
                int width=right-left-1;
                water+=h*width;
            }
            st.push(i);
        }
        
        return water;
    }
};
