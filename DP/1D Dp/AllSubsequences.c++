#include <iostream>
#include <vector>
using namespace std;

void printSubsequences(vector<int>& nums, vector<int>& subsequence, int index) {
    // Base case: if index is equal to size of nums, print the subsequence
    if (index == nums.size()) {
        for (int num : subsequence) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // Include the current element in the subsequence
    subsequence.push_back(nums[index]);
    printSubsequences(nums, subsequence, index + 1);

    // Exclude the current element from the subsequence
    subsequence.pop_back();
    printSubsequences(nums, subsequence, index + 1);
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> subsequence;

    cout << "Subsequences:" << endl;
    printSubsequences(nums, subsequence, 0);

    return 0;
}
