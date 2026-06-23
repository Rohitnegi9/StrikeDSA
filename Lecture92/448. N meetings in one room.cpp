class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // code here
        vector<pair<int,int>>meeting;
        int n = start.size();

        for(int i=0;i<n;i++){
            meeting.push_back({end[i],start[i]});
        }

        sort(meeting.begin(),meeting.end());


        int lastMeetingTime = -1;
        int totalMeeting = 0;

        for(int i=0;i<n;i++){
            if(meeting[i].second>lastMeetingTime){
                totalMeeting++;
                lastMeetingTime = meeting[i].first;
            }
        }

        return totalMeeting;


    }
};