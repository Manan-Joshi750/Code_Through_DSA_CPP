/*
There is one meeting room in a firm. 
There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is the finish time of meeting i.
The task is to find the maximum number of meetings that can be accommodated in the meeting room. 
You can accommodate a meeting if the start time of the meeting is strictly greater than the finish time of the previous meeting. Print all meeting numbers.

Note: If two meetings can be chosen for the same slot, then choose the meeting that finishes earlier.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxMeetings(int n, vector<int>& start, vector<int>& end) {
        vector<pair<pair<int, int>, int>> meetings;

        for (int i = 0; i < n; ++i) {
            meetings.push_back({{end[i], start[i]}, i + 1});
        }

        sort(meetings.begin(), meetings.end());

        vector<int> result;
        int lastEndTime = -1;

        for (const auto& meeting : meetings) {
            if (meeting.first.second > lastEndTime) {
                result.push_back(meeting.second);
                lastEndTime = meeting.first.first;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    int n = 6;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    vector<int> meetings = sol.maxMeetings(n, start, end);

    cout << "Maximum number of meetings: " << meetings.size() << endl;
    cout << "Meetings numbers: ";
    for (int m : meetings) {
        cout << m << " ";
    }
    cout << endl;

    return 0;
}