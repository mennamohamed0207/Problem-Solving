// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n=height.size();
//         int waterTrapped=0;
//         for(int i=0;i<height.size();i++)
//         {
//             if(i>0&&i<n-1&&!(height[i]>height[i-1]&&height[i]>height[i+1]))
//             {
//                 int increasedWater=abs(height[i]-min(height[i-1],height[i+1]));
//                 waterTrapped+=increasedWater;
//                 height[i]+=increasedWater;

//             }

//         }
//         return waterTrapped;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;  // Can't trap water with less than 3 bars

        int waterTrapped = 0;
        vector<int> leftMax(n), rightMax(n);

        // Compute left max heights
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Compute right max heights
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Compute water trapped
        for (int i = 1; i < n - 1; i++) { // Ignore first and last as they can't trap water
            waterTrapped += max(0, min(leftMax[i], rightMax[i]) - height[i]);
        }

        return waterTrapped;
    }
};
