#math #mayChallenge
/*
Link:

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/

// Solution

/*
TC = O(n)
SC = O(1)
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& v) {
        int len = v.size(), i;
        int slopeX = v[0][0] - v[1][0];
        int slopeY = (v[0][1] - v[1][1]);
        for (i = 2; i < len; i++) {
            int tempX = (v[i][0] - v[i - 1][0]);
            int tempY = (v[i][1] - v[i - 1][1]);
            if (tempX * slopeY != tempY * slopeX)       // using the property (y = mx) of slope
                return false;
        }
        return true;
    }
};