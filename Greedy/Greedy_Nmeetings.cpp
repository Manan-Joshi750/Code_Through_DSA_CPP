/*
You are given timings of n meetings in the form of (start[i], end[i]) 
where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. 
Return the maximum number of meetings that can be accommodated in a single meeting room, 
when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> meetings;

        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }

        sort(meetings.begin(), meetings.end());

        int count = 0;
        int lastEndTime = -1;

        for (auto& meeting : meetings) {
            if (meeting.second > lastEndTime) {
                count++;
                lastEndTime = meeting.first;
            }
        }

        return count;
    }
};

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    Solution sol;
    cout << "Maximum number of meetings: " << sol.maxMeetings(start, end) << endl;

    return 0;
}