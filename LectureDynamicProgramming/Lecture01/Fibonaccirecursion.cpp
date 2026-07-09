int fibonacci(int n){
     
    if(n<=1){
        return n;
    }


    return fibonacci(n-1)+fibonacci(n-2);

}

int fib(int n) {
    // Your code here
    
    // vector<int>dp(n+1,-1);
    return fibonacci(n);
}