//https://leetcode.com/problems/merge-sorted-array/
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
// bekar solution 

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        for (int i = 0; i < m; i++) {
            v.push_back(nums1[i]);
        }
        for (int j = 0; j < n; j++) {
            v.push_back(nums2[j]);
        }
        sort(v.begin(), v.end());
        // Copy sorted elements back into nums1
        for (int i = 0; i < v.size(); i++) {
            nums1[i] = v[i];
        }
    };
// Two pointers approach Actually 3 :(
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
                k--;
            } else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
    }
};


int main() {
ios::sync_with_stdio(0);
return 0;
}