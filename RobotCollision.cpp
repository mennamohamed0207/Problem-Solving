/*
There are n 1-indexed robots, each having a position on a line, health, and movement direction.

You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.

All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.

If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.

Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.

Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.

Note: The positions may be unsorted.

 
 

Example 1:



Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
Output: [2,17,9,15,10]
Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].
Example 2:



Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
Output: [14]
Explanation: There are 2 collisions in this example. Firstly, robot 1 and robot 2 will collide, and since both have the same health, they will be removed from the line. Next, robot 3 and robot 4 will collide and since robot 4's health is smaller, it gets removed, and robot 3's health becomes 15 - 1 = 14. Only robot 3 remains, so we return [14].
Example 3:



Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
Output: []
Explanation: Robot 1 and robot 2 will collide and since both have the same health, they are both removed. Robot 3 and 4 will collide and since both have the same health, they are both removed. So, we return an empty array, [].
 

Constraints:

1 <= positions.length == healths.length == directions.length == n <= 105
1 <= positions[i], healths[i] <= 109
directions[i] == 'L' or directions[i] == 'R'
All values in positions are distinct
*/
//First Solution:128/2433 test cases passed
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        vector<int> index(positions.size());
        vector<int> result;
        for (int i = 0; i < positions.size(); i++) {
            index[i] = i + 1;
        }
        for (int k = 0; k < positions.size(); k++) {
            if (directions[k] == 'R'&&positions[k]!=0) {
                positions[k]++;
            } else if (directions[k] == 'L'&& positions[k]!=0) {
                positions[k]--;
            }
        }
        for (int i = 0; i < positions.size(); i++) {
            for (int j = 0; j < positions.size(); j++) {
                if (positions[i] == positions[j]&&i!=j) {
                    if (healths[i] > healths[j]) {
                        healths[i]--;
                        healths[j] = 0;
                        positions[j]=0;
                       
                    } else {
                        healths[i] = 0;
                        positions[i]=0;
                    }
                    break;
                }
            }
            cout<<healths[i];
            if (healths[i] != 0)
                result.push_back(healths[i]);
        }
        
        return result;
    }
};
//Second one with chatgpt solution
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    vector<tuple<int, int, char, int>> robots;

    // Combine positions, healths, directions, and original index
    for (int i = 0; i < n; ++i) {
        robots.push_back({positions[i], healths[i], directions[i], i});
    }

    // Sort robots by position
    sort(robots.begin(), robots.end());

    stack<tuple<int, int, char, int>> stk; // Stack to store robots moving right
    vector<int> result(n, -1); // Initialize the result with -1 (indicating removed robots)

    for (auto& robot : robots) {
        int pos = get<0>(robot);
        int health = get<1>(robot);
        char dir = get<2>(robot);
        int idx = get<3>(robot);

        if (dir == 'R') {
            stk.push(robot); // Push robots moving right to the stack
        } else { // dir == 'L'
            while (!stk.empty() && health > 0) {
                auto right_robot = stk.top();
                int right_health = get<1>(right_robot);
                int right_idx = get<3>(right_robot);

                if (right_health < health) {
                    // Robot moving left survives but loses health
                    health -= 1;
                    stk.pop();
                } else if (right_health == health) {
                    // Both robots have same health, both are removed
                    stk.pop();
                    health = 0;
                } else {
                    // Robot moving right survives but loses health
                    get<1>(right_robot) -= 1;
                    stk.pop();
                    if (get<1>(right_robot) > 0) {
                        stk.push(right_robot);
                    }
                    health = 0;
                }
            }
            if (health > 0) {
                result[idx] = health; // Surviving left-moving robot
            }
        }
    }

    // Process remaining robots moving right
    while (!stk.empty()) {
        auto right_robot = stk.top();
        stk.pop();
        int right_idx = get<3>(right_robot);
        result[right_idx] = get<1>(right_robot);
    }

    // Collect the results in the order of original indices
    vector<int> survivors;
    for (int i = 0; i < n; ++i) {
        if (result[i] != -1) {
            survivors.push_back(result[i]);
        }
    }

    return survivors;
}};
