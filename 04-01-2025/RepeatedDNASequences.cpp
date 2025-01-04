/*
Bute Force:
Generate all possible 10-letter substrings from the string.
Compare each substring with every other substring to check for repetitions.
Keep track of repeated substrings and return them.*/
/*
OPTIMAL:

*Use a sliding window of size 10 to efficiently extract all substrings of length 10.
*Hashing: Track the frequency of each 10-letter substring using a hash map (or unordered map).
Steps:
*Initialize an empty unordered map to store substring frequencies.
*Slide through the string, extracting every 10-letter substring.
*Count the occurrences of each substring.
*Add substrings to the result if they appear more than once.
Implementation:

*Loop through the string and extract all possible 10-letter substrings.
*For each substring, update its count in the hash map.
*After counting, check which substrings occur more than once and add them to the result list.
Efficiency:

Time Complexity: O(n), 
where 𝑛 is the length of the string. Each substring is inserted and checked in constant time on average.
Space Complexity:
O(n), for storing the substrings and their frequencies.*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> sequenceCount;
        vector<string> result;
        int n = s.length();

        if (n < 10) return result;

        for (int i = 0; i <= n - 10; i++) {
            string substring = s.substr(i, 10);
            sequenceCount[substring]++;
        }

        for (const auto& pair : sequenceCount) {
            if (pair.second > 1) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};
