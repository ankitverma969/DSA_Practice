#include <iostream>
#include<climits>
using namespace std;

int main() {
    int arr[8] = {55,7,2,6,66,78,46,44};
    
    int maxi = INT_MIN;
    int mini = INT_MAX;
    
    for(int i=0;i<8;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
        
        if(arr[i]<mini){
            mini=arr[i];
        }
    }
    
    cout<<"Minimum Value is: "<<mini<<endl;
    cout<<"Maximum Value is: "<<maxi<<endl;
    return 0;
}