/*You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.*/
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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int cur= image[sr][sc];
        if(cur== color)return image;
        int r=image.size();
        int c=image[0].size();
      queue<pair<int, int>> q;
      // push the node which needs to be colored first 
      q.push({sr,sc});
      image[sr][sc]=color;

      // now start iterating the graph and color the nodes which can be colored by pushing each one of them on the queue and coloring the adjacent ones each by each and then conitnuing it until the graph ends
      // making one directions list to store the directions 
      vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
      // using BFS traversal
      while(!q.empty()){
        auto[x,y]= q.front();// storing the coordinates of the front elements of the queue
        q.pop();
        // add up the direction coordinates which needs to be colored and store them in some other variable to color rest of them 
        for(auto dir : directions){
            int nx = x + dir.first;// changing directions using the direction vector and the earlier stored coordinates of the non-colored element
            int ny = y + dir.second;
            if(nx>=0 && nx<r && ny>=0 && ny<c && image[nx][ny]== cur ){
                q.push({nx,ny});
                image[nx][ny]= color;
            }
        }
       
      }
      return image;


    }
};



int main() {
ios::sync_with_stdio(0);
return 0;
}