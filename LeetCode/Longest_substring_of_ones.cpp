#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int largestOnes(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        int cnt = 0;
        int maxlen = 0;
        while (r < nums.size())
        {
            if (nums[r] == 0)
            {
                cnt++;
            }
            while (cnt > k)
            {
                if(nums[l]==0){
                    cnt--;
                }
                l++;
            }
            
            // Calculate the maxSum
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};

int main()
{
vector<int> nums={1,1,1,0,0,0,0,1,1,1,};

Solution s;
int largeone = s.largestOnes(nums,2);
cout<<largeone<<endl;

    return 0;
}