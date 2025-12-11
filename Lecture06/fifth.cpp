#include<iostream>
using namespace std;

// void increment(int &n){
//     n++;
// }

void swap(int &a, int &b){
    int c = a;
    a=b;
    b=c;
}
// default parameter
void printing(int num = 5){
    cout<<num<<endl;
}

int main(){

    // int a = 10;

    // increment(a);



//     cout<<a<<endl;

    int a = 10, b = 20;
    
    swap(a,b);

    // int c;
    // c = a;
    // a = b;
    // b = c;
    
    cout<<a<<" "<<b<<endl;



    printing(10);
    printing();
  
    return 0;
}



// Function ki help se Prime number
// Function ki help se armstrong number
// Function , swap ka, a b c , a= 10, b = 20, c = 30 --> a= 20, b = 30, c = 10
// 0.1 + 0.2 sum kitna hota hai???