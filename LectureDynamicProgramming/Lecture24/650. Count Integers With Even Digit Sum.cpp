class Solution {
public:
    int countEven(int num) {
        // Your code here

        int sumOfDigit = 0, n = num;

        while(n){
            sumOfDigit+=(n%10);
            n/=10;
        }

        return sumOfDigit%2? (num-1)/2: num/2;
    }
};