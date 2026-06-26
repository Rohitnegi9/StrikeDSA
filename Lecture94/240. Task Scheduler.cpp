int leastInterval(vector<char>& tasks, int n) {
    vector<int>freq(26,0);
    int count = 0;

    for(int i=0;i<tasks.size();i++){
        int index = tasks[i]-'A';
        freq[index]++;
        count = max(count,freq[index]);
    }
    
    int result = (n+1)*(count-1);

    // now whose freq is equal to count, increase the result by 1

    for(int i=0;i<26;i++){
        if(freq[i]==count)
            result++;
    }


    return tasks.size() > result ? tasks.size(): result;



}