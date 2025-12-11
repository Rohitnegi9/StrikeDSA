#include<iostream>
using namespace std;

// declare and define
// return_type functionName(parameter,parameter, parameter)
int factorial(int n){
   
    int fact = 1;

    for(int i=1;i<=n;i++){
        fact*=i;
    }

    return fact;
}

int sum(int a, int b){

   return a+b;
}




int main(){
   
    // factorial
    int num = 5 , num2 = 7, num3 = 8;
    // int fact = 1;
    
    // function call, argument
    int answer1 = factorial(num);
    int answer2 = factorial(num2);
    int answer3 = factorial(num3);
    
    cout<<answer1<<endl<<answer2<<endl<<answer3<<endl;

    int sum1 = sum(3,4);
    cout<<sum1<<endl;
    
    // for(int i=1;i<=num;i++){
    //     fact*=i;
    // }

    // cout<<fact<<endl;
    

    // fact = 1;

    // for(int i=1;i<=num2;i++){
    //     fact*=i;
    // }

    // cout<<fact<<endl;


    // fact = 1;

    // for(int i=1;i<=num3;i++){
    //     fact*=i;
    // }

    // cout<<fact<<endl;
    
    return 0;

}