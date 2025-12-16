// Link: https://strikes.in/practice/68ac0c51b68bc4c304e47837

void reverseArray(vector<int>& arr) {
    
	int n = arr.size();

	for(int i=0;i<n/2;i++){
		int temp = arr[i];
		arr[i] = arr[n-1-i];
		arr[n-1-i] = temp;
	}

}