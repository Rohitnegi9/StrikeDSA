int trapWater(vector<int>& arr) {

	int n = arr.size();

	vector<int>LeftMax(n,0);
	vector<int>RightMax(n,0);

	LeftMax[0] = arr[0], RightMax[n-1] = arr[n-1];
    
	// Prefix Max
	for(int i=1;i<n;i++){
       LeftMax[i] += max(LeftMax[i-1],arr[i]);
	}   

	// Suffix Max

	for(int i=n-2;i>0;i--){
       RightMax[i] += max(RightMax[i+1],arr[i]);
	}  


	int totalWater = 0;

	for(int i=1;i<n-1;i++){
		int minLeftRight = min(LeftMax[i-1],RightMax[i+1]);
		if(minLeftRight>arr[i]){
			totalWater+=minLeftRight-arr[i];
		}
	}

	return totalWater;



}



// Second solution

int trapWater(vector<int>& arr) {

	int n = arr.size();

	vector<int>RightMax(n,0);

	RightMax[n-1] = arr[n-1];

	int LeftMax = arr[0];
    

	// Suffix Max

	for(int i=n-2;i>0;i--){
       RightMax[i] += max(RightMax[i+1],arr[i]);
	}  


	int totalWater = 0;

	for(int i=1;i<n-1;i++){
		int minLeftRight = min(LeftMax,RightMax[i+1]);
		if(minLeftRight>arr[i]){
			totalWater+=minLeftRight-arr[i];
		}

		LeftMax = max(LeftMax,arr[i]);
	}

	return totalWater;


}
// Third Solution 
int trapWater(vector<int>& arr) {
	int n=arr.size();
	// find the maximum element using 2 pointer
	int start=0,end=n-1;
	while(start<end){
		if(arr[start]>arr[end]){
			end--;
		}
		else{
			start++;
		}
	}
	int leftmax=arr[0],rightmax=arr[n-1],water=0;
	for(int i=0;i<start;i++){
		if(arr[i]<leftmax){
			water+=leftmax-arr[i];
		}
		leftmax=max(leftmax,arr[i]);
	}
	for(int i=n-2;i>start;i--){
		if(arr[i]<rightmax){
			water+=rightmax-arr[i];
		}
		rightmax=max(rightmax,arr[i]);
	}
	return water;
}

// Fouth Method
int trapWater(vector<int>& arr) {
	int n=arr.size();
	int start=0,end=n-1,leftmax=arr[0],rightmax=arr[n-1],water=0;
	while(start<end){
		if(arr[start]<arr[end]){
			if(arr[start]<leftmax){
				water+=leftmax-arr[start];
			}
			leftmax=max(leftmax,arr[start]);
			start++;
		}
		else{
			if(arr[end]<rightmax){
				water+=rightmax-arr[end];
			}
			rightmax=max(rightmax,arr[end]);
			end--;
		}
	}
	return water;
}

