/*
Intution:*/

code:class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256, 0);
        
        for (char c : s) {
            freq[c]++;
        }
        
        string result = "";
        while (true) {
            int maxFreq = -1;
            char maxChar = '\0';
            
            for (int i = 0; i < 256; i++) {
                if (freq[i] > maxFreq) {
                    maxFreq = freq[i];
                    maxChar = i;
                }
            }
            
            if (maxFreq == 0) {
                break;
            }
            
            result += string(maxFreq, maxChar);
            freq[maxChar] = 0;
        }
        
        return result;
    }
};

