/*
 * LeetCode #271 - Encode and Decode Strings (Premium)
 * https://leetcode.com/problems/encode-and-decode-strings/
 *
 * Design an algorithm to encode a list of strings to a string. The encoded
 * string is then sent over the network and is decoded back to the original list
 * of strings.
 *
 * Implement the encode and decode methods.
 *
 * You are not allowed to solve the problem using any serialize methods (such as
 * eval).
 *
 * Example 1:
 * Input: dummy_input = ["Hello","World"]
 * Output: ["Hello","World"]
 *
 * Example 2:
 * Input: dummy_input = [""]
 * Output: [""]
 *
 * Constraints:
 * - 1 <= strs.length <= 200
 * - 0 <= strs[i].length <= 200
 * - strs[i] contains any possible characters out of 256 valid ASCII characters.
 *
 * Follow up: Could you write a generalized algorithm to work on any possible set
 * of characters? Could you solve the problem without using any serialize methods?
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        // TODO: Implement your solution here

    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        // TODO: Implement your solution here

    }
};

// Helper function to print vector of strings
void printStrings(const vector<string>& strs) {
    cout << "[";
    for (int i = 0; i < strs.size(); i++) {
        cout << "\"" << strs[i] << "\"";
        if (i < strs.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Test cases
int main() {
    Codec codec;

    // Test case 1
    vector<string> strs1 = {"Hello", "World"};
    string encoded1 = codec.encode(strs1);
    vector<string> decoded1 = codec.decode(encoded1);
    cout << "Test 1: ";
    printStrings(decoded1);
    // Expected: ["Hello","World"]

    // Test case 2
    vector<string> strs2 = {""};
    string encoded2 = codec.encode(strs2);
    vector<string> decoded2 = codec.decode(encoded2);
    cout << "Test 2: ";
    printStrings(decoded2);
    // Expected: [""]

    // Test case 3
    vector<string> strs3 = {"we", "say", ":", "yes"};
    string encoded3 = codec.encode(strs3);
    vector<string> decoded3 = codec.decode(encoded3);
    cout << "Test 3: ";
    printStrings(decoded3);
    // Expected: ["we","say",":","yes"]

    return 0;
}
