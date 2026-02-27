#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <numeric>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

/*Level 6: Stack & Queue
These come up constantly in DSA — BFS uses queue, DFS/parentheses problems use stack.

Stack — LIFO (Last In, First Out):
stack<int> st;
st.push(10);      // add to top
st.top();          // peek at top element
st.pop();          // remove top (returns void!)
st.empty();        // true if empty
st.size();
Queue — FIFO (First In, First Out):
queue<int> q;
q.push(10);        // add to back
q.front();         // peek at front
q.back();          // peek at back
q.pop();           // remove front (returns void!)
q.empty();
q.size();
Important: .pop() on both does NOT return the value. You must read .top() or .front() before popping.

Q1->Your exercise: Write a program that:
Push {1, 2, 3, 4, 5} into a stack
Pop and print all elements (should print 5 4 3 2 1)
Push {1, 2, 3, 4, 5} into a queue
Pop and print all elements (should print 1 2 3 4 5)

Q2->Write a function void printStack(stack<int> st) — takes a stack, pops and prints all elements
Write a function void printQueue(queue<int> q) — takes a queue, pops and prints all elements
In main(), push {1,2,3,4,5} into each and call the functions
Notice: the functions take the stack/queue by value (copy), not by reference. Think about why that matters — if you passed by reference, the original would be empty after printing.

Bonus: Try wrapping it in a class if you want:
class MyStack {
    stack<int> st;
public:
    void push(int val);
    void printAll();
};
*/
 
class MyStack{
    private: 
    int arr[100];
    int top_index;
    public:
    MyStack (){top_index=0;}
    void push(int val);
    void pop();
    int top();
    bool emptyy();
    void printall();
};
void MyStack::push(int val){
    arr[top_index]=val;
    top_index++;
}

int MyStack::top(){
    return arr[top_index-1];
}
bool MyStack::emptyy(){
    return top_index==0;
}
void MyStack::pop(){
    if(!emptyy()){
        arr[top_index-1]=0;
        top_index--;
    }
}
void MyStack:: printall(){
    for(int i=0;i<top_index;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


class MyQueue{
    private: int arr[100];
    int front_index;
    int last_index;
    public:
    MyQueue () { front_index=0; last_index=0;}
    
    void push(int val){
        arr[last_index]=val;
        last_index++;
    }
    void pop(){
        front_index++;
    }
    int front(){
        return arr[front_index];
    };
    int last(){
        return arr[last_index-1];
    };
    bool empty(){
        return front_index==last_index;
    }
    void PrintAll(){
        for(int i=front_index;i<last_index;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
};
int main() {
    // making an object of the class MyStack
    //objectName.functionName(parameters)

// MyStack s;
// s.push(1);
// s.push(2);
// s.push(3);
// s.push(4);
// s.push(5);
// cout<<"Top "<<s.top()<<endl;
// s.pop();
// cout<<"After Pop, Top->"<<s.top()<<endl;
// if(!s.emptyy()){
//     cout<<"Stack is not empty"<<endl;
// }
// s.printall();
MyQueue q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);
cout<<"FRONT-> "<<q.front()<<endl;
q.pop();
cout<<"AFTER POP, FRONT-> "<<q.front()<<endl;
if (!q.empty())
{
    cout<<"QUEUE Is not empty"<<endl;
}
q.PrintAll();

    return 0;
}