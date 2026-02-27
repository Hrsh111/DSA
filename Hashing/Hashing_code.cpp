#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++){
    cin>>arr[i];
}

// precompute 

int hash[13]={0};
// Set all the elements inital value to 0
for(int i=0; i<n;i++){
 hash[arr[i]]+=1;
}
int q ;
while(q--){
    int number ;
    cin>>number;
    cout<< hash[number]<<endl;// pass the value whose 
    // occurence has to be found so that it
    // the hash function marks +1 every time it finds the 
    // givem number in the array
}
        
        
return 0;
}



