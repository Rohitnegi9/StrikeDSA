#include <iostream>
#include<vector>
using namespace std;

int main() {
    // int arr[5] = {10,20,30,40,50}

    // vector<int>arr(5);
    
    // arr[0] = 10;
    // arr[1]=20,
    // arr[2] = 5;
    // arr[3]=9;
    // arr[4] = 7;

    vector<int>arr;

    arr.push_back(90);
    arr.push_back(10);

    arr.pop_back();

    int n = arr.size();

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<n<<" ";
    return 0;
}