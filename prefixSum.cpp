#include <iostream>
using namespace std;

void sum(int prefixSum[], int a, int b){
    int ans = prefixSum[b] - prefixSum[a-1];
    cout<<ans<<endl;
}

int main() {
    int arr[5] = {3, 1, 4, 2, 5};
    int prefixSum[5];
    
    prefixSum[0] = arr[0];
    
    for(int i=1;i<5;i++){
        prefixSum[i] = prefixSum[i-1]+arr[i];
    }
    
    for(int i=0;i<5;i++){
        cout<<prefixSum[i]<<" ";
    }
    
    cout<<endl;
    
    sum(prefixSum,1,4);
    sum(prefixSum,2,3);
    
    return 0;
}
