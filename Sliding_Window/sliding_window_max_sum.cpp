#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int maxSum(const vector<int>&arr, int k){
    
if (k > arr.size()){   
    return -1;
}
int curr_sum=0;   

for (int i = 0; i <k; i++){
 curr_sum += arr[i];
}

int max_sum = curr_sum;

// For updating the sum after sliding 
for (int i = k; i <arr.size(); i++)
{
    curr_sum += arr[i]- arr[i-k];// Subtracting k from i will give us the index  where our window start was 
    max_sum = max(max_sum, curr_sum);
}
return max_sum;
}

int main(){
 
   std::vector<int> arr ={1,2,3,4,5,878,867};
    int k = 3;
    int result =maxSum(arr, k);
   cout<<result<<endl;
    
    
    
    return 0;
}