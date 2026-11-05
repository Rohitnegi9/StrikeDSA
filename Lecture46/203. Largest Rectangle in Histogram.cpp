int largestRectangleArea(vector<int>& heights) {
    

    stack<int>st;
    int n = heights.size();

    // Next smallest Right and Left

    vector<int>NSR(n);
    vector<int>NSL(n,-1);


    for(int i=0;i<n;i++){
        while(!st.empty()&&heights[i]<heights[st.top()]){
            NSR[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    while(!st.empty()){
        NSR[st.top()] = n;
        st.pop();
    }


    // Next smallest element on Left side

    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&heights[i]<heights[st.top()]){
            NSL[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }


    int maxArea = 0;

    for(int i=0;i<n;i++){
        maxArea = max(maxArea,(NSR[i]-NSL[i]-1)*heights[i]);
    }


    return maxArea;



}

// Optimize Solution in Single pass
class Solution {
public:
int largestRectangleArea(vector<int>& h) {
h.push_back(0); // prevent the rewrite code for element which remains in stack 
int n=h.size();
    stack<int>s;
    int ans=0;
    for(int i=0;i<n;i++){
        while(!s.empty()&&h[s.top()]>h[i]){
            int NSR=i;
            int poped=s.top();
            s.pop();
            if(!s.empty()){
            int NSL=s.top();
            int curr=(NSR-NSL-1)*h[poped];
            ans=max(ans,curr);
            }
            else{
            int curr=(NSR)*h[poped];
            ans=max(ans,curr);
            }
        }
        s.push(i);
    }
    // stack contains min elements like 2,3,4 handeled by pushing 0 at end in h vector
    return ans;
