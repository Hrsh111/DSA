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
// TC= O(nlogn)
int majorityElement(vector<int>& nums) {
     int n=nums.size();
     sort(nums.begin(), nums.end());
       return nums[n/2];
    }
// Using map to mark the no of occurrences of the elements 
int majorityElement(vector<int>&nums){
    int n = nums.size();
    unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }

        n=n/2;

        // now return the element with occurrence more than n/2
        for(auto& [num, count]: map){
            if(count>n){
                return num;
            }
        }
        return 0;
}




int main() {
ios::sync_with_stdio(0);
return 0;
}