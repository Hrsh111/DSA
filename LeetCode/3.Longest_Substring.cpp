#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Vector to keep track of the last seen index of each character
        // Initialized to -1 to indicate that no character has been seen initially
        vector<int> hash(256, -1);
        
        // Initialize the left and right pointers for the sliding window
        int l = 0, r = 0;
        
        // Get the size of the input string
        int n = s.size();
        
        // Variable to keep track of the length of the longest substring without repeating characters
        int maxlen = 0;
        
        // Iterate through the string with the right pointer
        while (r < n) {
            // Check if the current character has been seen before
            if (hash[s[r]] != -1) {
                // Move the left pointer to the right of the last occurrence of the current character
                // Ensures that the current window contains unique characters only
                l = max(hash[s[r]] + 1, l);
            }
            
            // Update the last seen index of the current character
            hash[s[r]] = r;
            
            // Calculate the length of the current window and update maxlen if it's the longest seen so far
            maxlen = max(maxlen, r - l + 1);
            
            // Move the right pointer to the next character
            r++;
        }
        
        // Return the length of the longest substring without repeating characters
        return maxlen;
    }
};
