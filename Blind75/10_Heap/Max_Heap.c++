//  MAX HEAP IMPlEMENTATION
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
 
// MAX HEAP IMPLEMENTATION
class MaxHeap{
    vector<int> heap;// heap is declared here due to keep the heap private and to avoid any external modification of the heap and to maintain the integrity of the heap data structure
    // for the max heap the parent node is always greater than the child node and the left child of the heap is always greater than the right child of the heap and the root node is always
    // for the left child of the heap the (2*i)+1) and for the right child of the heap the (2*i)+2) and for the parent of the heap the (i-1)/2)
    public:
    void insert(int val){
        heap.push_back(val);
        int i =heap.size()-1;
        while(i>0){
            int parent =(i-1)/2;
            if(heap[parent]<heap[i]){
                swap(heap[parent],heap[i]);
                i=parent;
            } else {
                break;
            }

        }
    }
    // print function to print the heap since external modification of the heap is not allowed due to the class
    //  encapsulation and to maintain the integrity of the heap data structure
    void print(){
        for(int i=0;i<heap.size();i++){
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }
    void printTree(){
        int height = log2(heap.size());
    }
};



int main() {
ios::sync_with_stdio(0);
// declaring an object of the MaxHeap class to test the
// implementation of the MaxHeap class and to insert some values into the heap and to
//  print the heap to verify the correctness of the implementation of the MaxHeap class
MaxHeap maxheap;
// vector with values for testing the MaxHeap implementation
vector<int> values ={10,20,5,61,90,69};
for(int val:values){
    maxheap.insert(val);
    maxheap.print();
}

return 0;
}
