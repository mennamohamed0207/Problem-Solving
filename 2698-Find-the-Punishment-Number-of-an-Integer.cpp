// class Solution {
// public:
//     int punishmentNumber(int n) {
//         int result=0;
//         for(int i=1;i<=n;i++)
//         {
//            int potentialSum=0;
//            int num=i*i;

//            while(num>0)
//            {
//             int digit=num%10;
//             potentialSum+=digit;
//             num /=10;
//            }
//            if(potentialSum==i)
//            {
//             result+=i*i;
//            }
//         }
//         return result;
//     }
// };
class Solution {
public:
    // Helper function to check if we can partition square(i) to sum up to i
    bool canPartition(string &numStr, int target, int index, int currentSum) {
        if (index == numStr.size()) {
            return currentSum == target;
        }
        
        int value = 0;
        for (int j = index; j < numStr.size(); ++j) {
            value = value * 10 + (numStr[j] - '0'); // Build the partition
            if (value + currentSum > target) break; // Prune unnecessary cases
            if (canPartition(numStr, target, j + 1, currentSum + value)) {
                return true;
            }
        }
        
        return false;
    }

    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            string squareStr = to_string(square);
            if (canPartition(squareStr, i, 0, 0)) {
                result += square;
            }
        }
        return result;
    }
};
