class Solution {
public:
    long long rotationCount(long long R, long long D) {
        // code here
        long long count = 0;

        while(R){
            int firstLastValue = R%10;
            int secondLastValue = D%10;
            R/=10;
            D/=10;

            count+= min(abs(firstLastValue-secondLastValue), 10-abs(firstLastValue-secondLastValue));
        }

        while(D){
            int lastValue = D%10;
            D/=10;
            count+= min(lastValue,10-lastValue);
        }

        return count;
    }
};