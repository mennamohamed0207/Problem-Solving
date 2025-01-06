class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answers(boxes.length());
        for (int i = 0; i < boxes.length(); i++) {
            int sum = 0;
            for (int j = 0; j < boxes.length(); j++) {
                if (boxes[j] == '1') {
                    sum += abs(j - i);
                    // boxes[j]='0';
                }
            }
            answers[i] = sum;
        }
        return answers;
    }
};