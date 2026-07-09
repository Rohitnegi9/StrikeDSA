int climb(int n){
    // base case
    if(n<=2){
        return n;
    }


    return climb(n-1)+climb(n-2);
}


int climbStairs(int n) {
    // Your code here
    return climb(n);
}