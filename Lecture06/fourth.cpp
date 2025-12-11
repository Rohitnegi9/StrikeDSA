#include<iostream>
using namespace std;

// int square(int n);
// function overloading:
int sum(int a, int b){
    return a+b;
}

int sum(int a,int b,int c){
    return a+b+c;
}

float sum(float a, float b){
    return a+b;
}

int main(){
    
    // int num = 5;
    
    // // function call
    // cout<<square(num)<<endl;
    float a = 3.1, b=3.4;

    // cout<<3.1<<endl;

    cout<<sum(3,4)<<endl;
    cout<<sum(3,4,5)<<endl;
    cout<<sum(a,b)<<endl;

    return 0;
}


// function define
// int square(int n){
//     return n*n;
// }