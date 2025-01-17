/*
INTUION: SIMPLE BRUTE FORCE WORKS VERY WELL

### Intuition Summary in Points:
1. **Count Frequencies**:
   - For each word in the input array, iterate through a list of word-frequency pairs.
   - If the word exists, increment its frequency; otherwise, add it to the list.
   - This results in a nested loop, leading to **O(n²)** complexity.

2. **Sort Words**:
   - Sort the word-frequency pairs by:
     - **Descending frequency** (higher frequency first).
     - **Lexicographical order** (alphabetically) for words with the same frequency.
   - Sorting adds an **O(m log m)** overhead, where `m` is the number of unique words.

3. **Extract Top K**:
   - Take the first `k` words from the sorted list as the most frequent ones.

4. **Summary**:
   - The approach is simple but inefficient for large inputs due to its **O(n²)** frequency counting. It prioritizes clarity and direct implementation over performance. */
code:
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<string, int>> freq; // Vector to store word-frequency pairs

        // Step 1: Count frequencies in a brute force manner
        for (int i = 0; i < words.size(); i++) {
            bool found = false;
            for (int j = 0; j < freq.size(); j++) {
                if (freq[j].first == words[i]) { // Word already exists
                    freq[j].second++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                freq.push_back({words[i], 1}); // Add new word with frequency 1
            }
        }

        // Step 2: Sort by frequency and lexicographical order
        sort(freq.begin(), freq.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first; // Lexicographical order if frequencies are equal
            }
            return a.second > b.second; // Descending order of frequency
        });

        // Step 3: Extract the top k words
        vector<string> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freq[i].first);
        }

        return result;
    }
};
