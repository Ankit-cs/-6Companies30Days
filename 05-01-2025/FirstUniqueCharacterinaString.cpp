/*
Intution:
*Count Frequencies: Use a map to track the frequency of each character in the string.
*First Pass: Iterate through the string to populate the map with character frequencies.
*Second Pass: Go through the string again and return the index of the first character with a frequency of 1.
*Return -1: If no non-repeating character is found, return -1.
*/


class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> freq;
        
        for (char c : s) {
            freq[c]++;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};
