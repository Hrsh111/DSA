// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
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
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> map;
        // marking each elements occurrence inorder to check any repetitions
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        vector<vector<int>> res;
        while(true){
            vector<int> row;
            for(auto& entry:map){
                if(entry.second>0){
                    row.push_back(entry.first);
                    entry.second--;
                }
            }
            if (row.empty()) {
                break; // Exit if no more elements can be added
            }
            res.push_back(row); // Add the row to the result
        }

        return res;

    } 
        
    }
;



int main() {
ios::sync_with_stdio(0);
return 0;
}