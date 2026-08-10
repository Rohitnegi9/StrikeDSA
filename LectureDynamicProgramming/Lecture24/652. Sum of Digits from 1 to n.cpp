class Solution {
public:
    // n = 43892
    // power = 10000, digit = 4 (0-9999)
    long long sumOfDigits(long long n) {
        // Your code here

        if(n<10)
        return n*(n+1)/2;


        int power = 1;
        int digit = 0;

        while(power*10<=n){
            power*=10;
            digit++;
        }


        long long sumElement = 45*digit*(power/10);

        long long firstElement = n/power;
        long long remainingElement = n%power;


        return firstElement*(sumElement)+ ((firstElement*(firstElement-1))/2)*power+ firstElement*(remainingElement+1)+ sumOfDigits(remainingElement);

        
    }
};