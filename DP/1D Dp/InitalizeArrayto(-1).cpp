#include <iostream>
#include <algorithm> // For std::fill
#include <cstring>   // For memset
#include <vector>    // For std::vector

using namespace std;

int main() {
    // Method 1: Using a Loop
    cout << "Method 1: Using a Loop\n";
    int arr1[10];
    for (int i = 0; i < 10; i++) {
        arr1[i] = -1;
    }
    for (int i = 0; i < 10; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\n\n";

    // Method 2: Using std::fill
    cout << "Method 2: Using std::fill\n";
    int arr2[10];
    fill(arr2, arr2 + 10, -1);
    for (int i = 0; i < 10; i++) {
        cout << arr2[i] << " ";
    }
    cout << "\n\n";

    // Method 3: Using Initializer List
    cout << "Method 3: Using Initializer List\n";
    int arr3[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    for (int i = 0; i < 10; i++) {
        cout << arr3[i] << " ";
    }
    cout << "\n\n";

    // Method 4: Using memset
    cout << "Method 4: Using memset\n";
    int arr4[10];
    memset(arr4, -1, sizeof(arr4));
    for (int i = 0; i < 10; i++) {
        cout << arr4[i] << " ";
    }
    cout << "\n\n";

    // Method 5: Using std::vector
    cout << "Method 5: Using std::vector\n";
    vector<int> vec(10, -1);
    for (int val : vec) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
