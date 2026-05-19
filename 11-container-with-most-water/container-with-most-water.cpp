class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxarea=0;
        while(l<r){
            int w=r-l;
            int deciding_height=min(height[l],height[r]);
            int area=w*deciding_height;
            maxarea=max(area,maxarea);
            //move smaller height
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxarea;
    }
};