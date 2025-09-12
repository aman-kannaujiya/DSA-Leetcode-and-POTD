class Solution {
public:
    bool doesAliceWin(string s) {
        // Set of vowels for quick lookup
        string vowels = "aeiou";
        int count = 0;

        // Count total vowels in the string
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                count++;
            }
        }

        // If no vowels, Alice cannot make a move -> she loses
        if (count == 0) return false;

        // Otherwise, Alice always wins
        return true;
    }
};
