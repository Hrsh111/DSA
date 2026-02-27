/*
 * ============================================================================
 *                    DSA TEMPLATES & PATTERNS REFERENCE
 * ============================================================================
 * Quick reference for common patterns, data structures, and algorithms
 * used in coding interviews and competitive programming.
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <climits>
#include <cmath>
#include <numeric>
using namespace std;

/*
 * ============================================================================
 *                         TABLE OF CONTENTS
 * ============================================================================
 * 1.  COMMON DATA STRUCTURES
 *     - ListNode (Linked List)
 *     - TreeNode (Binary Tree)
 *     - Graph Node
 *     - Trie Node
 *
 * 2.  TWO POINTERS PATTERNS
 *     - Same direction (slow/fast)
 *     - Opposite directions
 *     - Sliding window
 *
 * 3.  BINARY SEARCH PATTERNS
 *     - Standard binary search
 *     - Lower/Upper bound
 *     - Search in rotated array
 *
 * 4.  LINKED LIST PATTERNS
 *     - Reverse linked list
 *     - Detect cycle (Floyd's algorithm)
 *     - Find middle
 *     - Merge two sorted lists
 *
 * 5.  TREE PATTERNS
 *     - DFS (Preorder, Inorder, Postorder)
 *     - BFS (Level order)
 *     - Tree height/depth
 *     - LCA (Lowest Common Ancestor)
 *
 * 6.  GRAPH PATTERNS
 *     - DFS (recursive & iterative)
 *     - BFS
 *     - Topological Sort (Kahn's algorithm)
 *     - Union-Find (Disjoint Set)
 *
 * 7.  DYNAMIC PROGRAMMING PATTERNS
 *     - 1D DP
 *     - 2D DP
 *     - Knapsack variants
 *     - LCS/LIS patterns
 *
 * 8.  BACKTRACKING PATTERNS
 *     - Subsets
 *     - Permutations
 *     - Combinations
 *
 * 9.  HEAP/PRIORITY QUEUE PATTERNS
 *     - Min heap / Max heap
 *     - Top K elements
 *     - Merge K sorted lists
 *
 * 10. BIT MANIPULATION
 *     - Common operations
 *     - Counting bits
 *
 * 11. INTERVAL PATTERNS
 *     - Merge intervals
 *     - Insert interval
 *
 * 12. MONOTONIC STACK/QUEUE
 *
 * 13. USEFUL HELPER FUNCTIONS
 * ============================================================================
 */


/* ============================================================================
 * 1. COMMON DATA STRUCTURES
 * ============================================================================
 */

// ----------------------------- Linked List Node -----------------------------
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Helper: Create linked list from vector
ListNode* createLinkedList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper: Print linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// ----------------------------- Binary Tree Node -----------------------------
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// ----------------------------- Graph Node (for Clone Graph) -----------------
class GraphNode {
public:
    int val;
    vector<GraphNode*> neighbors;
    GraphNode() : val(0), neighbors(vector<GraphNode*>()) {}
    GraphNode(int _val) : val(_val), neighbors(vector<GraphNode*>()) {}
    GraphNode(int _val, vector<GraphNode*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

// ----------------------------- Trie Node ------------------------------------
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie - O(n)
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Search for exact word - O(n)
    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    // Check if any word starts with prefix - O(n)
    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return true;
    }
};


/* ============================================================================
 * 2. TWO POINTERS PATTERNS
 * ============================================================================
 */

// ----------------------------- Two Pointers: Opposite Direction -------------
// Use case: Sorted array, find pair with target sum, palindrome check
// Time: O(n), Space: O(1)

bool twoSumSorted(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}

bool isPalindrome(const string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// ----------------------------- Two Pointers: Same Direction (Fast/Slow) -----
// Use case: Remove duplicates, linked list cycle detection
// Time: O(n), Space: O(1)

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int slow = 0;
    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1;
}

// ----------------------------- Sliding Window (Fixed Size) ------------------
// Use case: Max sum of k consecutive elements
// Time: O(n), Space: O(1)

int maxSumFixedWindow(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) return -1;

    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    int maxSum = windowSum;
    for (int i = k; i < n; i++) {
        windowSum += nums[i] - nums[i - k];  // Slide the window
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}

// ----------------------------- Sliding Window (Variable Size) ---------------
// Use case: Longest substring with at most K distinct characters
// Time: O(n), Space: O(k)

int longestSubstringKDistinct(const string& s, int k) {
    unordered_map<char, int> charCount;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        charCount[s[right]]++;

        // Shrink window while we have more than k distinct chars
        while (charCount.size() > k) {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0) {
                charCount.erase(s[left]);
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// ----------------------------- Sliding Window: Minimum Window Substring -----
// Template for "find minimum window containing all target characters"
// Time: O(n), Space: O(k)

string minWindowTemplate(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;  // Number of characters satisfied
    int start = 0, minLen = INT_MAX;

    while (right < s.size()) {
        char c = s[right];
        right++;

        // Expand window
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) valid++;
        }

        // Shrink window when valid
        while (valid == need.size()) {
            if (right - left < minLen) {
                start = left;
                minLen = right - left;
            }
            char d = s[left];
            left++;
            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}


/* ============================================================================
 * 3. BINARY SEARCH PATTERNS
 * ============================================================================
 */

// ----------------------------- Standard Binary Search -----------------------
// Time: O(log n), Space: O(1)

int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Prevents overflow
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;  // Not found
}

// ----------------------------- Lower Bound (First >= target) ----------------
// Returns index of first element >= target
// Time: O(log n), Space: O(1)

int lowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

// ----------------------------- Upper Bound (First > target) -----------------
// Returns index of first element > target
// Time: O(log n), Space: O(1)

int upperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left;
}

// ----------------------------- Search in Rotated Sorted Array ---------------
// Time: O(log n), Space: O(1)

int searchRotated(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;

        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

// ----------------------------- Find Minimum in Rotated Array ----------------
// Time: O(log n), Space: O(1)

int findMinRotated(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}


/* ============================================================================
 * 4. LINKED LIST PATTERNS
 * ============================================================================
 */

// ----------------------------- Reverse Linked List --------------------------
// Time: O(n), Space: O(1)

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// Reverse Linked List (Recursive)
ListNode* reverseListRecursive(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

// ----------------------------- Detect Cycle (Floyd's Algorithm) -------------
// Time: O(n), Space: O(1)

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// Find cycle start node
ListNode* detectCycleStart(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Cycle detected, find start
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;  // No cycle
}

// ----------------------------- Find Middle of Linked List -------------------
// Time: O(n), Space: O(1)

ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// ----------------------------- Merge Two Sorted Lists -----------------------
// Time: O(n + m), Space: O(1)

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}


/* ============================================================================
 * 5. TREE PATTERNS
 * ============================================================================
 */

// ----------------------------- DFS Traversals -------------------------------
// Time: O(n), Space: O(h) where h is height

// Preorder: Root -> Left -> Right
void preorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

// Inorder: Left -> Root -> Right (gives sorted order for BST)
void inorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

// Postorder: Left -> Right -> Root
void postorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->val);
}

// Iterative Inorder using stack
vector<int> inorderIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
    return result;
}

// ----------------------------- BFS / Level Order Traversal ------------------
// Time: O(n), Space: O(n)

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(currentLevel);
    }
    return result;
}

// ----------------------------- Tree Height / Max Depth ----------------------
// Time: O(n), Space: O(h)

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// ----------------------------- Validate BST ---------------------------------
// Time: O(n), Space: O(h)

bool isValidBSTHelper(TreeNode* root, long minVal, long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBSTHelper(root->left, minVal, root->val) &&
           isValidBSTHelper(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}

// ----------------------------- Lowest Common Ancestor (BST) -----------------
// Time: O(h), Space: O(1)

TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        } else {
            return root;
        }
    }
    return nullptr;
}

// ----------------------------- Lowest Common Ancestor (Binary Tree) ---------
// Time: O(n), Space: O(h)

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}


/* ============================================================================
 * 6. GRAPH PATTERNS
 * ============================================================================
 */

// ----------------------------- DFS (Recursive) ------------------------------
// Time: O(V + E), Space: O(V)

void dfsRecursive(vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";  // Process node

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsRecursive(graph, neighbor, visited);
        }
    }
}

// ----------------------------- DFS (Iterative using Stack) ------------------
// Time: O(V + E), Space: O(V)

void dfsIterative(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> st;

    st.push(start);
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (visited[node]) continue;
        visited[node] = true;
        cout << node << " ";  // Process node

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
            }
        }
    }
}

// ----------------------------- BFS -------------------------------------------
// Time: O(V + E), Space: O(V)

void bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";  // Process node

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// ----------------------------- BFS Shortest Path (Unweighted) ---------------
// Time: O(V + E), Space: O(V)

int bfsShortestPath(vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;  // {node, distance}

    visited[start] = true;
    q.push({start, 0});

    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();

        if (node == end) return dist;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }
    return -1;  // No path found
}

// ----------------------------- Number of Islands (Grid DFS) -----------------
// Time: O(m * n), Space: O(m * n)

void dfsIsland(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;

    grid[i][j] = '0';  // Mark as visited
    dfsIsland(grid, i + 1, j);
    dfsIsland(grid, i - 1, j);
    dfsIsland(grid, i, j + 1);
    dfsIsland(grid, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                dfsIsland(grid, i, j);
                count++;
            }
        }
    }
    return count;
}

// ----------------------------- Topological Sort (Kahn's Algorithm - BFS) ----
// Time: O(V + E), Space: O(V)

vector<int> topologicalSort(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);

    // Build graph
    for (auto& pre : prerequisites) {
        graph[pre[1]].push_back(pre[0]);
        inDegree[pre[0]]++;
    }

    // Start with nodes having 0 in-degree
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If not all nodes are processed, there's a cycle
    return result.size() == numCourses ? result : vector<int>();
}

// ----------------------------- Union-Find (Disjoint Set Union) --------------
// Time: O(α(n)) ≈ O(1) amortized, Space: O(n)

class UnionFind {
private:
    vector<int> parent, rank_;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank_.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by rank
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;  // Already in same set

        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};


/* ============================================================================
 * 7. DYNAMIC PROGRAMMING PATTERNS
 * ============================================================================
 */

// ----------------------------- 1D DP: Fibonacci / Climbing Stairs -----------
// Time: O(n), Space: O(1)

int climbStairs(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// ----------------------------- 1D DP: House Robber --------------------------
// Time: O(n), Space: O(1)

int houseRobber(vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int num : nums) {
        int curr = max(prev1, prev2 + num);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// ----------------------------- 1D DP: Coin Change ---------------------------
// Time: O(amount * n), Space: O(amount)

int coinChange(vector<int>& coins, int amount) {
    /**
     * @brief Dynamic programming array to store the minimum number of coins needed for each amount.
     * 
     * Initializes a vector of size (amount + 1) where each element is set to (amount + 1).
     * - Index i represents the target amount i
     * - Value at index i will store the minimum number of coins needed to make amount i
     * - Initial value (amount + 1) acts as infinity/impossible marker, since the minimum
     *   number of coins can never exceed the target amount itself
     * - dp[0] is typically set to 0 later, as 0 coins are needed to make amount 0
     */
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

// ----------------------------- 2D DP: Longest Common Subsequence ------------
// Time: O(m * n), Space: O(m * n)

int longestCommonSubsequence(string& text1, string& text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

// ----------------------------- 1D DP: Longest Increasing Subsequence --------
// Time: O(n^2), Space: O(n)

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLen = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

// LIS with Binary Search - O(n log n)
int lengthOfLISOptimized(vector<int>& nums) {
    vector<int> tails;
    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }
    return tails.size();
}

// ----------------------------- 2D DP: Unique Paths --------------------------
// Time: O(m * n), Space: O(n)

int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

// ----------------------------- 0/1 Knapsack ---------------------------------
// Time: O(n * W), Space: O(W)

int knapsack01(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {  // Reverse to avoid using same item twice
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[W];
}


/* ============================================================================
 * 8. BACKTRACKING PATTERNS
 * ============================================================================
 */

// ----------------------------- Subsets --------------------------------------
// Time: O(2^n), Space: O(n)

void subsetsHelper(vector<int>& nums, int start, vector<int>& current,
                   vector<vector<int>>& result) {
    result.push_back(current);
    for (int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);
        subsetsHelper(nums, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    subsetsHelper(nums, 0, current, result);
    return result;
}

// ----------------------------- Permutations ---------------------------------
// Time: O(n!), Space: O(n)

void permuteHelper(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permuteHelper(nums, start + 1, result);
        swap(nums[start], nums[i]);  // Backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permuteHelper(nums, 0, result);
    return result;
}

// ----------------------------- Combinations ---------------------------------
// Time: O(C(n,k)), Space: O(k)

void combineHelper(int n, int k, int start, vector<int>& current,
                   vector<vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    for (int i = start; i <= n; i++) {
        current.push_back(i);
        combineHelper(n, k, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    combineHelper(n, k, 1, current, result);
    return result;
}

// ----------------------------- Combination Sum ------------------------------
// Time: O(2^target), Space: O(target)

void combinationSumHelper(vector<int>& candidates, int target, int start,
                          vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        if (candidates[i] <= target) {
            current.push_back(candidates[i]);
            combinationSumHelper(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    combinationSumHelper(candidates, target, 0, current, result);
    return result;
}


/* ============================================================================
 * 9. HEAP / PRIORITY QUEUE PATTERNS
 * ============================================================================
 */

// ----------------------------- Min Heap / Max Heap --------------------------
// Note: C++ priority_queue is MAX heap by default

void heapExamples() {
    // Max heap (default)
    priority_queue<int> maxHeap;
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(4);
    // maxHeap.top() = 4

    // Min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    // minHeap.top() = 1

    // Custom comparator for pairs (sort by second element)
    auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;  // Min heap by second element
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
}

// ----------------------------- Top K Frequent Elements ----------------------
// Time: O(n log k), Space: O(n)

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;

    // Min heap of (frequency, number)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto& [num, count] : freq) {
        pq.push({count, num});
        if (pq.size() > k) pq.pop();
    }

    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}

// ----------------------------- Merge K Sorted Lists -------------------------
// Time: O(n log k), Space: O(k)

ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

    for (auto list : lists) {
        if (list) pq.push(list);
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        tail->next = node;
        tail = tail->next;
        if (node->next) pq.push(node->next);
    }
    return dummy.next;
}

// ----------------------------- Find Median from Data Stream -----------------
// Time: O(log n) for addNum, O(1) for findMedian

class MedianFinder {
    priority_queue<int> maxHeap;  // Lower half
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Upper half

public:
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};


/* ============================================================================
 * 10. BIT MANIPULATION
 * ============================================================================
 */

void bitManipulationBasics() {
    int n = 10;  // Binary: 1010

    // Check if i-th bit is set (0-indexed from right)
    bool isSet = (n >> 2) & 1;  // true (bit 2 is 1)

    // Set i-th bit
    n = n | (1 << 1);  // 1010 | 0010 = 1010 (already set)

    // Clear i-th bit
    n = n & ~(1 << 1);  // 1010 & 1101 = 1000

    // Toggle i-th bit
    n = n ^ (1 << 1);  // 1000 ^ 0010 = 1010

    // Check if power of 2
    bool isPowerOf2 = n && !(n & (n - 1));

    // Count set bits (Brian Kernighan's algorithm)
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }

    // Get lowest set bit
    int lowestBit = n & (-n);

    // XOR properties:
    // a ^ a = 0
    // a ^ 0 = a
    // a ^ b ^ a = b (useful for finding single number)
}

// ----------------------------- Single Number --------------------------------
// Time: O(n), Space: O(1)

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

// ----------------------------- Counting Bits --------------------------------
// Time: O(n), Space: O(n)

vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp;
}


/* ============================================================================
 * 11. INTERVAL PATTERNS
 * ============================================================================
 */

// ----------------------------- Merge Intervals ------------------------------
// Time: O(n log n), Space: O(n)

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}

// ----------------------------- Insert Interval ------------------------------
// Time: O(n), Space: O(n)

vector<vector<int>> insertInterval(vector<vector<int>>& intervals,
                                    vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0, n = intervals.size();

    // Add all intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i++]);
    }

    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);

    // Add remaining intervals
    while (i < n) {
        result.push_back(intervals[i++]);
    }
    return result;
}


/* ============================================================================
 * 12. MONOTONIC STACK / QUEUE
 * ============================================================================
 */

// ----------------------------- Next Greater Element -------------------------
// Time: O(n), Space: O(n)

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;  // Store indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

// ----------------------------- Daily Temperatures ---------------------------
// Time: O(n), Space: O(n)

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> st;  // Store indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
            result[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return result;
}

// ----------------------------- Sliding Window Maximum -----------------------
// Time: O(n), Space: O(k)

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  // Store indices, front has max
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices outside window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        // Remove smaller elements (they'll never be max)
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}


/* ============================================================================
 * 13. USEFUL HELPER FUNCTIONS
 * ============================================================================
 */

// ----------------------------- Print Helpers --------------------------------

void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void print2DVector(const vector<vector<int>>& v) {
    cout << "[" << endl;
    for (const auto& row : v) {
        cout << "  [";
        for (int i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i < row.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

// ----------------------------- String Helpers -------------------------------

bool isAlphanumeric(char c) {
    return isalnum(c);
}

string toLowerCase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

vector<string> splitString(const string& s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// ----------------------------- Math Helpers ---------------------------------

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// ----------------------------- Direction Arrays (for Grid Problems) ---------

// 4 directions: up, right, down, left
int dx4[] = {-1, 0, 1, 0};
int dy4[] = {0, 1, 0, -1};

// 8 directions: including diagonals
int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Alternative: vector of pairs
vector<pair<int, int>> directions4 = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int>> directions8 = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                       {0, 1}, {1, -1}, {1, 0}, {1, 1}};


/* ============================================================================
 * QUICK REFERENCE: TIME COMPLEXITIES
 * ============================================================================
 *
 * Data Structure Operations:
 * - Array access: O(1)
 * - Array insert/delete: O(n)
 * - Linked List insert/delete: O(1) if pointer known
 * - Hash Table: O(1) average, O(n) worst
 * - BST operations: O(log n) average, O(n) worst
 * - Heap push/pop: O(log n)
 * - Heap peek: O(1)
 *
 * Sorting:
 * - Quick Sort: O(n log n) average, O(n²) worst
 * - Merge Sort: O(n log n)
 * - Heap Sort: O(n log n)
 * - Counting/Radix Sort: O(n + k)
 *
 * Searching:
 * - Binary Search: O(log n)
 * - Linear Search: O(n)
 *
 * Graph:
 * - DFS/BFS: O(V + E)
 * - Dijkstra: O((V + E) log V) with priority queue
 * - Bellman-Ford: O(V * E)
 * - Floyd-Warshall: O(V³)
 *
 * ============================================================================
 */


// Main function for testing
int main() {
    cout << "=== DSA Templates Reference File ===" << endl;
    cout << "This file contains common patterns and algorithms." << endl;
    cout << "Refer to specific sections as needed!" << endl;

    // Example usage
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "\nExample - Print vector: ";
    printVector(nums);

    cout << "\nExample - Binary Search for 3: " << binarySearch(nums, 3) << endl;

    return 0;
}
