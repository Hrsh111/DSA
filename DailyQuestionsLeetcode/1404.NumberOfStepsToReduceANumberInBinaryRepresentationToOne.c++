/*1404. Number of Steps to Reduce a Number in Binary Representation to One [Medium]

Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
- If the current number is even, you have to divide it by 2.
- If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.

Example 1:
Input: s = "1101"
Output: 6
Explanation: "1101" corresponds to number 13 in decimal.
Step 1) 13 is odd, add 1 and obtain 14.
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.
Step 5) 4 is even, divide by 2 and obtain 2.
Step 6) 2 is even, divide by 2 and obtain 1.

Example 2:
Input: s = "10"
Output: 1
Explanation: "10" corresponds to number 2. Step 1) 2 is even, divide by 2 and obtain 1.

Example 3:
Input: s = "1"
Output: 0

Constraints:
- 1 <= s.length <= 500
- s consists of characters '0' or '1'
- s[0] == '1'
*/
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>
#include <utility>
#include <limits>
#include <string>
#include <type_traits>
#include <chrono>
using namespace std;
#include <iostream>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)
class Solution {
public:
    int numSteps(string s) {
       int steps=0;
        
        while(s!="1"){
            if(s.back()=='0'){
                s.pop_back();
            }
            else{
                int i= s.size()-1;
                while(i>=0&&s[i]=='1'){
            s[i]='0';
            i--;
        }
        if(i>=0)s[i]='1';
        else s="1"+s;
            }
            steps++;
            
        }
        return steps;
    }
    
};



int main() {
ios::sync_with_stdio(0);
return 0;
}
