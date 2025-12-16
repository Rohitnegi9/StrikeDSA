#include<iostream>
using namespace std;

// array ko name ke basis pe paas kar , uska size bhi pass karna
void printvalue(int a[],int n){
   
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }

    a[0] = 90;
    
}


int main(){
    
    int arr[5] = {10,20,11,18,30};
    int arr2[5];
    
    for(int i=0;i<5;i++){
        arr2[i]=arr[i];
    }

    printvalue(arr,5);

    cout<<arr[0];

    // cout<<arr;

    // int marks[10] = {11,19,8,1,2,18,9,10,17,20};
    // printvalue(marks,10);

    return 0;
}