class Solution {
public:
     bool isVowel(char c) {
    c = tolower(static_cast<unsigned char>(c));
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
    string sortVowels(string s) {
         vector<char> vowels;
        for (char c : s) if (isVowel(c)) vowels.push_back(c);

        // sort by ASCII (std::sort on char does that)
        sort(vowels.begin(), vowels.end());

        // place sorted vowels back into string
        int idx = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (isVowel(s[i])) {
                s[i] = vowels[idx++];
            }
        }
        return s;
    }
};