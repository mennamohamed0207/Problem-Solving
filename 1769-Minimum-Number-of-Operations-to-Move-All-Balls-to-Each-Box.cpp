class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answers(boxes.length());
        for (int i = 0; i < boxes.length(); i++) {
            int sum = 0;
            if (boxes[i] == '1') {
                for (int j = 0; j < boxes.length(); j++) {
                     answers[j] += abs(j - i);
                }
            // answers[i] = sum;
            }
        }
        return answers;
    }
};