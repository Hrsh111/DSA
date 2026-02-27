# Blind 75 - Revision Tracker

> Revise problems weekly. Focus on 🔴 first, then 🟡, then 🟢.

---

## 📅 Revision Log

| Date | Problems Revised | Notes |
|------|-----------------|-------|
| - | - | - |

---

## 📋 All Solved Problems

| # | Problem | Topic | LC Difficulty | Personal Difficulty | Date Solved | Last Revised | Revisions | Key Pattern | Notes |
|---|---------|-------|---------------|---------------------|-------------|--------------|-----------|-------------|-------|
| 1 | [Two Sum](01_Array/TwoSum.c++) | Array | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | Hash Map | Store complement in map |
| 2 | [Best Time to Buy and Sell Stock](01_Array/BestTimeToBuyAndSellStock.c++) | Array | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | Sliding Window / Kadane | Track min price, max profit |
| 3 | [Contains Duplicate](01_Array/ContainsDuplicate.c++) | Array | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | Hash Set | Insert and check set |
| 4 | [Product of Array Except Self](01_Array/ProductOfArrayExceptSelf.c++) | Array | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | Prefix/Suffix Product | Left pass then right pass |
| 5 | [Maximum Subarray](01_Array/MaximumSubarray.c++) | Array | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | Kadane's Algorithm | Reset running sum if negative |
| 6 | [Maximum Product Subarray](01_Array/MaximumProductSubarray.c++) | Array | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | DP / Kadane variant | Track both max and min (negatives flip) |
| 7 | [Find Minimum in Rotated Sorted Array](01_Array/FindMinimumInRotatedSortedArray.c++) | Array | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Binary Search | Compare mid with right boundary |
| 8 | [Search in Rotated Sorted Array](01_Array/SearchInRotatedSortedArray.c++) | Array | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Binary Search | Find sorted half, then decide direction |
| 9 | [Three Sum](01_Array/ThreeSum.c++) | Array | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Two Pointers | Sort + fix one, two-pointer rest |
| 10 | [Container With Most Water](01_Array/ContainerWithMostWater.c++) | Array | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | Two Pointers | Move the shorter pointer inward |
| 11 | [Sum of Two Integers](02_Binary/SumOfTwoIntegers.c++) | Binary | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Bit Manipulation | XOR for sum, AND+shift for carry |
| 12 | [Number of 1 Bits](02_Binary/NumberOf1Bits.c++) | Binary | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | Bit Manipulation | n & (n-1) clears lowest set bit |
| 13 | [Counting Bits](02_Binary/CountingBits.c++) | Binary | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | DP + Bit | dp[i] = dp[i >> 1] + (i & 1) |
| 14 | [Missing Number](02_Binary/MissingNumber.c++) | Binary | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | XOR / Math | XOR all indices and values |
| 15 | [Reverse Bits](02_Binary/ReverseBits.c++) | Binary | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | Bit Manipulation | Shift result left, shift n right |
| 16 | [Climbing Stairs](03_DynamicProgramming/ClimbingStairs.c++) | DP | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | Fibonacci DP | dp[i] = dp[i-1] + dp[i-2] |
| 17 | [Coin Change](03_DynamicProgramming/CoinChange.c++) | DP | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Unbounded Knapsack | dp[amount] = min over all coins |
| 18 | [Longest Increasing Subsequence](03_DynamicProgramming/LongestIncreasingSubsequence.c++) | DP | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | DP / Patience Sort | O(n log n) with binary search |
| 19 | [Longest Common Subsequence](03_DynamicProgramming/LongestCommonSubsequence.c++) | DP | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | 2D DP | Match chars diagonally or take max |
| 20 | [Word Break](03_DynamicProgramming/WordBreak.c++) | DP | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | DP + Trie/Set | dp[i] = any dp[j] && word[j..i] in dict |
| 21 | [Combination Sum IV](03_DynamicProgramming/CombinationSum.c++) | DP | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | DP / Backtracking | Count permutations summing to target |
| 22 | [House Robber](03_DynamicProgramming/HouseRobber.c++) | DP | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | Linear DP | dp[i] = max(dp[i-1], dp[i-2]+nums[i]) |
| 23 | [House Robber II](03_DynamicProgramming/HouseRobberII.c++) | DP | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Circular DP | Two passes: skip first or skip last |
| 24 | [Decode Ways](03_DynamicProgramming/DecodeWays.c++) | DP | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Linear DP | Check single and two-digit decodings |
| 25 | [Unique Paths](03_DynamicProgramming/UniquePaths.c++) | DP | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | 2D DP / Math | dp[i][j] = dp[i-1][j] + dp[i][j-1] |
| 26 | [Jump Game](03_DynamicProgramming/JumpGame.c++) | DP | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | Greedy | Track farthest reachable index |
| 27 | [Clone Graph](04_Graph/CloneGraph.c++) | Graph | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | BFS/DFS + HashMap | Map old nodes to cloned nodes |
| 28 | [Course Schedule](04_Graph/CourseSchedule.c++) | Graph | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Topological Sort | BFS Kahn's or DFS cycle detection |
| 29 | [Pacific Atlantic Water Flow](04_Graph/PacificAtlanticWaterFlow.c++) | Graph | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Multi-source BFS/DFS | Start from ocean borders, go uphill |
| 30 | [Number of Islands](04_Graph/NumberOfIslands.c++) | Graph | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | BFS/DFS grid traversal | Mark visited cells, explore 4 directions |
| 31 | [Longest Consecutive Sequence](04_Graph/LongestConsecutiveSequence.c++) | Graph | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Hash Set | Only start counting from sequence start |
| 32 | [Number of Connected Components](04_Graph/NumberOfConnectedComponents.c++) | Graph | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | Union Find / DFS | Count connected components |
| 33 | [Graph Valid Tree](04_Graph/GraphValidTree.c++) | Graph | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Union Find / DFS | n-1 edges + no cycle = tree |
| 34 | [Alien Dictionary](04_Graph/AlienDictionary.c++) | Graph | Hard | 🔴 Struggled | 2026-02-22 | - | 0 | Topological Sort | Build graph from adjacent word pairs |
| 35 | [Insert Interval](05_Interval/InsertInterval.c++) | Interval | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Interval Merge | Add before, merge overlapping, add after |
| 36 | [Merge Intervals](05_Interval/MergeIntervals.c++) | Interval | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | Sort + Merge | Sort by start, merge if overlap |
| 37 | [Non-Overlapping Intervals](05_Interval/NonOverlappingIntervals.c++) | Interval | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Greedy | Sort by end, count overlaps to remove |
| 38 | [Meeting Rooms](05_Interval/MeetingRooms.c++) | Interval | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | Sort + Check | Sort by start, check overlaps |
| 39 | [Meeting Rooms II](05_Interval/MeetingRoomsII.c++) | Interval | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Min Heap / Sweep Line | Track end times with priority queue |
| 40 | [Reverse Linked List](06_LinkedList/ReverseLinkedList.c++) | Linked List | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | Iterative / Recursive | prev, curr, next pointer swap |
| 41 | [Linked List Cycle](06_LinkedList/LinkedListCycle.c++) | Linked List | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | Fast & Slow Pointers | Floyd's cycle detection |
| 42 | [Merge Two Sorted Lists](06_LinkedList/MergeTwoSortedLists.c++) | Linked List | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | Two Pointers | Compare heads, attach smaller |
| 43 | [Merge K Sorted Lists](06_LinkedList/MergeKSortedLists.c++) | Linked List | Hard | 🟡 Moderate | 2026-02-22 | - | 0 | Min Heap / Divide & Conquer | Push all heads into min heap |
| 44 | [Remove Nth Node From End](06_LinkedList/RemoveNthNodeFromEnd.c++) | Linked List | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | Two Pointers | Advance fast n steps, then move both |
| 45 | [Reorder List](06_LinkedList/ReorderList.c++) | Linked List | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Find Mid + Reverse + Merge | Split, reverse second half, interleave |
| 46 | [Set Matrix Zeroes](07_Matrix/SetMatrixZeroes.c++) | Matrix | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | In-place Marking | Use first row/col as markers |
| 47 | [Spiral Matrix](07_Matrix/SpiralMatrix.c++) | Matrix | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Simulation | Track 4 boundaries, shrink inward |
| 48 | [Rotate Image](07_Matrix/RotateImage.c++) | Matrix | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | Transpose + Reverse | Transpose matrix then reverse each row |
| 49 | [Word Search](07_Matrix/WordSearch.c++) | Matrix | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Backtracking / DFS | DFS with visited tracking |
| 50 | [Longest Substring Without Repeating Characters](08_String/LongestSubstringWithoutRepeatingCharacters.c++) | String | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | Sliding Window | Expand right, shrink left on duplicate |
| 51 | [Longest Repeating Character Replacement](08_String/LongestRepeatingCharacterReplacement.c++) | String | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Sliding Window | Window - maxFreq <= k |
| 52 | [Minimum Window Substring](08_String/MinimumWindowSubstring.c++) | String | Hard | 🔴 Struggled | 2026-02-22 | - | 0 | Sliding Window + HashMap | Expand to satisfy, shrink to minimize |
| 53 | [Valid Anagram](08_String/ValidAnagram.c++) | String | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | Hash Map / Sort | Count char frequencies |
| 54 | [Group Anagrams](08_String/GroupAnagrams.c++) | String | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | Hash Map | Sorted string as key |
| 55 | [Valid Parentheses](08_String/ValidParentheses.c++) | String | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | Stack | Push open, pop and match close |
| 56 | [Valid Palindrome](08_String/ValidPalindrome.c++) | String | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | Two Pointers | Skip non-alphanumeric, compare |
| 57 | [Longest Palindromic Substring](08_String/LongestPalindromicSubstring.c++) | String | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Expand Around Center | Expand from each char (odd + even) |
| 58 | [Palindromic Substrings](08_String/PalindromicSubstrings.c++) | String | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Expand Around Center | Count expansions from each center |
| 59 | [Encode and Decode Strings](08_String/EncodeAndDecodeStrings.c++) | String | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Length Prefix | len# delimiter for each string |
| 60 | [Strobogrammatic Number III](08_String/StrobogrammaticNumberIII.c++) | String | Hard | 🔴 Struggled | 2026-02-25 | - | 0 | Recursion + String | Build from center out, filter by range |
| 61 | [Maximum Depth of Binary Tree](09_Tree/MaximumDepthOfBinaryTree.c++) | Tree | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | DFS / BFS | 1 + max(left, right) |
| 62 | [Same Tree](09_Tree/SameTree.c++) | Tree | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | DFS | Compare nodes recursively |
| 63 | [Invert Binary Tree](09_Tree/InvertBinaryTree.c++) | Tree | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | DFS | Swap left and right children |
| 64 | [Binary Tree Maximum Path Sum](09_Tree/BinaryTreeMaximumPathSum.c++) | Tree | Hard | 🔴 Struggled | 2026-02-22 | - | 0 | DFS + Global Max | Return max single path, update global with both |
| 65 | [Binary Tree Level Order Traversal](09_Tree/BinaryTreeLevelOrderTraversal.c++) | Tree | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | BFS | Process queue level by level |
| 66 | [Serialize and Deserialize Binary Tree](09_Tree/SerializeAndDeserializeBinaryTree.c++) | Tree | Hard | 🔴 Struggled | 2026-02-22 | - | 0 | BFS / Preorder | Use null markers, rebuild with queue |
| 67 | [Subtree of Another Tree](09_Tree/SubtreeOfAnotherTree.c++) | Tree | Easy | 🟢 Smooth | 2026-02-22 | - | 0 | DFS | Check isSameTree at each node |
| 68 | [Construct Binary Tree from Preorder and Inorder](09_Tree/ConstructBinaryTreeFromPreorderAndInorder.c++) | Tree | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Recursion + HashMap | Preorder root, inorder splits left/right |
| 69 | [Validate Binary Search Tree](09_Tree/ValidateBinarySearchTree.c++) | Tree | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | DFS with Range | Pass min/max bounds recursively |
| 70 | [Kth Smallest Element in BST](09_Tree/KthSmallestElementInBST.c++) | Tree | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | Inorder Traversal | Inorder gives sorted, return kth |
| 71 | [Lowest Common Ancestor of BST](09_Tree/LowestCommonAncestorOfBST.c++) | Tree | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | BST Property | Split point where p and q diverge |
| 72 | [Implement Trie](09_Tree/ImplementTrie.c++) | Tree | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Trie | TrieNode with children[26] + isEnd |
| 73 | [Design Add and Search Words](09_Tree/DesignAddAndSearchWordsDataStructure.c++) | Tree | Medium | 🟡 Moderate | 2026-02-22 | - | 0 | Trie + DFS | Trie with '.' wildcard via DFS |
| 74 | [Top K Frequent Elements](10_Heap/TopKFrequentElements.c++) | Heap | Medium | 🟢 Smooth | 2026-02-22 | - | 0 | Heap / Bucket Sort | Count freq, use heap or bucket |
| 75 | [Find Median from Data Stream](10_Heap/FindMedianFromDataStream.c++) | Heap | Hard | 🔴 Struggled | 2026-02-22 | - | 0 | Two Heaps | Max-heap for lower, min-heap for upper |

---

## 🔴 Priority Revision (Struggled)

| # | Problem | Topic | Date Solved | Last Revised | Revisions |
|---|---------|-------|-------------|--------------|-----------|
| 1 | [Alien Dictionary](04_Graph/AlienDictionary.c++) | Graph | 2026-02-22 | - | 0 |
| 2 | [Minimum Window Substring](08_String/MinimumWindowSubstring.c++) | String | 2026-02-22 | - | 0 |
| 3 | [Strobogrammatic Number III](08_String/StrobogrammaticNumberIII.c++) | String | 2026-02-25 | - | 0 |
| 4 | [Binary Tree Maximum Path Sum](09_Tree/BinaryTreeMaximumPathSum.c++) | Tree | 2026-02-22 | - | 0 |
| 5 | [Serialize and Deserialize Binary Tree](09_Tree/SerializeAndDeserializeBinaryTree.c++) | Tree | 2026-02-22 | - | 0 |
| 6 | [Find Median from Data Stream](10_Heap/FindMedianFromDataStream.c++) | Heap | 2026-02-22 | - | 0 |

---

## 🟡 Regular Revision (Moderate)

| # | Problem | Topic | Date Solved | Last Revised | Revisions |
|---|---------|-------|-------------|--------------|-----------|
| 1 | [Maximum Product Subarray](01_Array/MaximumProductSubarray.c++) | Array | 2026-02-22 | - | 0 |
| 2 | [Find Minimum in Rotated Sorted Array](01_Array/FindMinimumInRotatedSortedArray.c++) | Array | 2026-02-22 | - | 0 |
| 3 | [Search in Rotated Sorted Array](01_Array/SearchInRotatedSortedArray.c++) | Array | 2026-02-22 | - | 0 |
| 4 | [Three Sum](01_Array/ThreeSum.c++) | Array | 2026-02-22 | - | 0 |
| 5 | [Sum of Two Integers](02_Binary/SumOfTwoIntegers.c++) | Binary | 2026-02-22 | - | 0 |
| 6 | [Coin Change](03_DynamicProgramming/CoinChange.c++) | DP | 2026-02-22 | - | 0 |
| 7 | [Longest Increasing Subsequence](03_DynamicProgramming/LongestIncreasingSubsequence.c++) | DP | 2026-02-22 | - | 0 |
| 8 | [Longest Common Subsequence](03_DynamicProgramming/LongestCommonSubsequence.c++) | DP | 2026-02-22 | - | 0 |
| 9 | [Word Break](03_DynamicProgramming/WordBreak.c++) | DP | 2026-02-22 | - | 0 |
| 10 | [Combination Sum IV](03_DynamicProgramming/CombinationSum.c++) | DP | 2026-02-22 | - | 0 |
| 11 | [House Robber II](03_DynamicProgramming/HouseRobberII.c++) | DP | 2026-02-22 | - | 0 |
| 12 | [Decode Ways](03_DynamicProgramming/DecodeWays.c++) | DP | 2026-02-22 | - | 0 |
| 13 | [Clone Graph](04_Graph/CloneGraph.c++) | Graph | 2026-02-22 | - | 0 |
| 14 | [Course Schedule](04_Graph/CourseSchedule.c++) | Graph | 2026-02-22 | - | 0 |
| 15 | [Pacific Atlantic Water Flow](04_Graph/PacificAtlanticWaterFlow.c++) | Graph | 2026-02-22 | - | 0 |
| 16 | [Longest Consecutive Sequence](04_Graph/LongestConsecutiveSequence.c++) | Graph | 2026-02-22 | - | 0 |
| 17 | [Graph Valid Tree](04_Graph/GraphValidTree.c++) | Graph | 2026-02-22 | - | 0 |
| 18 | [Insert Interval](05_Interval/InsertInterval.c++) | Interval | 2026-02-22 | - | 0 |
| 19 | [Non-Overlapping Intervals](05_Interval/NonOverlappingIntervals.c++) | Interval | 2026-02-22 | - | 0 |
| 20 | [Meeting Rooms II](05_Interval/MeetingRoomsII.c++) | Interval | 2026-02-22 | - | 0 |
| 21 | [Merge K Sorted Lists](06_LinkedList/MergeKSortedLists.c++) | Linked List | 2026-02-22 | - | 0 |
| 22 | [Reorder List](06_LinkedList/ReorderList.c++) | Linked List | 2026-02-22 | - | 0 |
| 23 | [Spiral Matrix](07_Matrix/SpiralMatrix.c++) | Matrix | 2026-02-22 | - | 0 |
| 24 | [Word Search](07_Matrix/WordSearch.c++) | Matrix | 2026-02-22 | - | 0 |
| 25 | [Longest Repeating Character Replacement](08_String/LongestRepeatingCharacterReplacement.c++) | String | 2026-02-22 | - | 0 |
| 26 | [Longest Palindromic Substring](08_String/LongestPalindromicSubstring.c++) | String | 2026-02-22 | - | 0 |
| 27 | [Palindromic Substrings](08_String/PalindromicSubstrings.c++) | String | 2026-02-22 | - | 0 |
| 28 | [Encode and Decode Strings](08_String/EncodeAndDecodeStrings.c++) | String | 2026-02-22 | - | 0 |
| 29 | [Construct Binary Tree from Preorder and Inorder](09_Tree/ConstructBinaryTreeFromPreorderAndInorder.c++) | Tree | 2026-02-22 | - | 0 |
| 30 | [Implement Trie](09_Tree/ImplementTrie.c++) | Tree | 2026-02-22 | - | 0 |
| 31 | [Design Add and Search Words](09_Tree/DesignAddAndSearchWordsDataStructure.c++) | Tree | 2026-02-22 | - | 0 |

---

## 🟢 Monthly Revision (Smooth)

| # | Problem | Topic | Date Solved | Last Revised | Revisions |
|---|---------|-------|-------------|--------------|-----------|
| 1 | [Two Sum](01_Array/TwoSum.c++) | Array | 2026-02-22 | - | 0 |
| 2 | [Best Time to Buy and Sell Stock](01_Array/BestTimeToBuyAndSellStock.c++) | Array | 2026-02-22 | - | 0 |
| 3 | [Contains Duplicate](01_Array/ContainsDuplicate.c++) | Array | 2026-02-22 | - | 0 |
| 4 | [Product of Array Except Self](01_Array/ProductOfArrayExceptSelf.c++) | Array | 2026-02-22 | - | 0 |
| 5 | [Maximum Subarray](01_Array/MaximumSubarray.c++) | Array | 2026-02-22 | - | 0 |
| 6 | [Container With Most Water](01_Array/ContainerWithMostWater.c++) | Array | 2026-02-22 | - | 0 |
| 7 | [Number of 1 Bits](02_Binary/NumberOf1Bits.c++) | Binary | 2026-02-22 | - | 0 |
| 8 | [Counting Bits](02_Binary/CountingBits.c++) | Binary | 2026-02-22 | - | 0 |
| 9 | [Missing Number](02_Binary/MissingNumber.c++) | Binary | 2026-02-22 | - | 0 |
| 10 | [Reverse Bits](02_Binary/ReverseBits.c++) | Binary | 2026-02-22 | - | 0 |
| 11 | [Climbing Stairs](03_DynamicProgramming/ClimbingStairs.c++) | DP | 2026-02-22 | - | 0 |
| 12 | [House Robber](03_DynamicProgramming/HouseRobber.c++) | DP | 2026-02-22 | - | 0 |
| 13 | [Unique Paths](03_DynamicProgramming/UniquePaths.c++) | DP | 2026-02-22 | - | 0 |
| 14 | [Jump Game](03_DynamicProgramming/JumpGame.c++) | DP | 2026-02-22 | - | 0 |
| 15 | [Number of Islands](04_Graph/NumberOfIslands.c++) | Graph | 2026-02-22 | - | 0 |
| 16 | [Number of Connected Components](04_Graph/NumberOfConnectedComponents.c++) | Graph | 2026-02-22 | - | 0 |
| 17 | [Merge Intervals](05_Interval/MergeIntervals.c++) | Interval | 2026-02-22 | - | 0 |
| 18 | [Meeting Rooms](05_Interval/MeetingRooms.c++) | Interval | 2026-02-22 | - | 0 |
| 19 | [Reverse Linked List](06_LinkedList/ReverseLinkedList.c++) | Linked List | 2026-02-22 | - | 0 |
| 20 | [Linked List Cycle](06_LinkedList/LinkedListCycle.c++) | Linked List | 2026-02-22 | - | 0 |
| 21 | [Merge Two Sorted Lists](06_LinkedList/MergeTwoSortedLists.c++) | Linked List | 2026-02-22 | - | 0 |
| 22 | [Remove Nth Node From End](06_LinkedList/RemoveNthNodeFromEnd.c++) | Linked List | 2026-02-22 | - | 0 |
| 23 | [Set Matrix Zeroes](07_Matrix/SetMatrixZeroes.c++) | Matrix | 2026-02-22 | - | 0 |
| 24 | [Rotate Image](07_Matrix/RotateImage.c++) | Matrix | 2026-02-22 | - | 0 |
| 25 | [Longest Substring Without Repeating Characters](08_String/LongestSubstringWithoutRepeatingCharacters.c++) | String | 2026-02-22 | - | 0 |
| 26 | [Valid Anagram](08_String/ValidAnagram.c++) | String | 2026-02-22 | - | 0 |
| 27 | [Group Anagrams](08_String/GroupAnagrams.c++) | String | 2026-02-22 | - | 0 |
| 28 | [Valid Parentheses](08_String/ValidParentheses.c++) | String | 2026-02-22 | - | 0 |
| 29 | [Valid Palindrome](08_String/ValidPalindrome.c++) | String | 2026-02-22 | - | 0 |
| 30 | [Maximum Depth of Binary Tree](09_Tree/MaximumDepthOfBinaryTree.c++) | Tree | 2026-02-22 | - | 0 |
| 31 | [Same Tree](09_Tree/SameTree.c++) | Tree | 2026-02-22 | - | 0 |
| 32 | [Invert Binary Tree](09_Tree/InvertBinaryTree.c++) | Tree | 2026-02-22 | - | 0 |
| 33 | [Binary Tree Level Order Traversal](09_Tree/BinaryTreeLevelOrderTraversal.c++) | Tree | 2026-02-22 | - | 0 |
| 34 | [Subtree of Another Tree](09_Tree/SubtreeOfAnotherTree.c++) | Tree | 2026-02-22 | - | 0 |
| 35 | [Validate Binary Search Tree](09_Tree/ValidateBinarySearchTree.c++) | Tree | 2026-02-22 | - | 0 |
| 36 | [Kth Smallest Element in BST](09_Tree/KthSmallestElementInBST.c++) | Tree | 2026-02-22 | - | 0 |
| 37 | [Lowest Common Ancestor of BST](09_Tree/LowestCommonAncestorOfBST.c++) | Tree | 2026-02-22 | - | 0 |
| 38 | [Top K Frequent Elements](10_Heap/TopKFrequentElements.c++) | Heap | 2026-02-22 | - | 0 |

---

## 📊 Stats

| Metric | Count |
|--------|-------|
| Total Solved | 75 |
| 🔴 Struggled | 6 |
| 🟡 Moderate | 31 |
| 🟢 Smooth | 38 |
| Total Revisions | 0 |

---

## 📌 How to Use

1. **After solving a problem** — Add it to the "All Solved Problems" table and the matching difficulty section
2. **During weekly revision** — Go through 🔴 and 🟡 problems, re-solve them without looking at your solution
3. **After revising** — Update "Last Revised" date, increment "Revisions" count, log it in the Revision Log
4. **Promotion rule** — After 3 clean revisions, promote: 🔴 → 🟡 → 🟢
5. **Revision frequency** — 🔴 weekly, 🟡 biweekly, 🟢 monthly
