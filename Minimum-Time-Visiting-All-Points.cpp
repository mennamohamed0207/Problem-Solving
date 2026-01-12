1class Solution {
2public:
3    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
4        int duration = 0;
5        for (int i = 0; i < points.size(); i++) {
6            if (i + 1 <= points.size() - 1) {
7                int distX = abs(points[i][0] - points[i + 1][0]);
8                int distY = abs(points[i][1] - points[i + 1][1]);
9                int maxDist = max(distX, distY);
10                duration += maxDist;
11            }
12        }
13        return duration;
14    }
15};