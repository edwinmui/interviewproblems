class Solution {
public:
    int maxArea(vector<int>& height) {
        // O(n) solution
        int l = 0;
        int r = int(height.size() - 1);
        int max_area = -1;
        while (l < r){
            int h = min(height[l], height[r]);
            int w = r - l;
            int area = h * w;
            max_area = max(area, max_area);
            
            // decides whether to move left or right pointer
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return max_area;
        
        /*
        // brute force solution
        int max_area = -1;
        // calculates max area
        for (int i = 0; i < height.size() - 1; ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                // calculate current area
                int h = min(height[i], height[j]);
                int w = j - i;
                int area = h * w;
                if (area > max_area) max_area = area;
            }
        }
        return max_area;
        */
    }
};
