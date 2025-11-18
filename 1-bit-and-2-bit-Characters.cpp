class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool open = false;
        bool two = false;
        for (int i = 0; i < bits.size(); i++) {
            if ((bits[i] == 1 || bits[i] == 0) && open) {
                open = false;
                two = true;
            } else if (!open && bits[i] == 1)
                open = true;
            else if (bits[i] == 0)
                two = false;
        }
        return bits[bits.size() - 1] == 0 && !open && !two;
    }
};