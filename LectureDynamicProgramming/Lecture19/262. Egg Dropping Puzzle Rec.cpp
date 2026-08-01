int findTotalFloor(int eggs, int moves){
    if(eggs==0 || moves==0)
    return 0;

    if(eggs==1)
    return moves;


    return 1+findTotalFloor(eggs-1,moves-1)+findTotalFloor(eggs,moves-1);
}


int eggDrop(int n, int k) {

    // moves = 0,1,2,3,4,5   : k = 36
    // 8
     int moves = 0;
    while(findTotalFloor(n,moves)<k)
    {
        moves++;
    }

    return moves;
}