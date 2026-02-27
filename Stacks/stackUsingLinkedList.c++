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

int main()
{
    ios::sync_with_stdio(0);
    return 0;
}
// classic c style implementation in c++ without memory management
class MinStack
{
public:
    // using a linked list here
    typedef struct node
    {
        int v;
        int minUntilNow;
        node *next;
    } node;
    MinStack() : topN(nullptr)
    {
    }

    void push(int val)
    {
        node *n = new node;
        n->v = n->minUntilNow = val;
        n->next = nullptr;

        if (topN == nullptr)
        {
            topN = n;
        }
        else
        {
            n->minUntilNow = min(n->v, topN->minUntilNow);
            n->next = topN;
            topN = n;
        }
    }

    void pop()
    {
        topN = topN->next;
    }

    int top()
    {
        return topN->v;
    }

    int getMin()
    {
        return topN->minUntilNow;
    }

private:
    node *topN;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// ### more refined version
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// classic c++ style implementation

#include <iostream>
#include <limits>

using namespace std;

class MinStack
{
private:
    struct Node
    {
        int value;
        int minUntilNow;
        Node *next;

        Node(int val, int minVal, Node *nextNode)// constructor for initialzing the members when called 
            : value(val), minUntilNow(minVal), next(nextNode) {}
    };

    Node *topN; // Pointer to the top node

public:
    MinStack() : topN(nullptr) {}

    void push(int val)
    {
        if (topN == NULL)
        {
            topN = new Node(val, val, nullptr);
        }
        else
        {
            int newMin = min(val, topN->minUntilNow);
            topN = new Node(val, newMin, topN);
        }
    }

    void pop()
    {
        if (topN != nullptr)
        {
            Node *temp = topN;
            topN = topN->next; // Move top to next node
            delete temp;       // Free memory of the removed node
        }
    }

    int top()
    {
        if (topN == nullptr)
        {
            throw runtime_error("Stack is empty!");
        }
        return topN->value;
    }

    int getMin()
    {
        if (topN == nullptr)
        {
            throw runtime_error("Stack is empty!");
        }
        return topN->minUntilNow;
    }

    ~MinStack()
    {
        while (topN != nullptr)
        {
            pop(); // Free all nodes
        }
    }
};

int main()
{
    MinStack s;
    s.push(5);
    s.push(2);
    s.push(3);
    cout << "Minimum: " << s.getMin() << endl; // Output: 2
    s.pop();
    cout << "Minimum: " << s.getMin() << endl; // Output: 2
    s.pop();
    cout << "Minimum: " << s.getMin() << endl; // Output: 5
}
