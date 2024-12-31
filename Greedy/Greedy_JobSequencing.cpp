/*
You are given three arrays: id[], deadline[], and profit[], 
where each job is associated with an ID, a deadline, and a profit. 
Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. 
You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:
1. The maximum number of jobs that can be completed within their deadlines.
2. The total maximum profit earned by completing those jobs.
*/

#include <bits/stdc++.h>
using namespace std;

// Structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;

    Job(int i, int d, int p) : id(i), deadline(d), profit(p) {}
};

// Comparator to sort jobs by profit in descending order
bool comparator(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

// Function to find the maximum number of jobs and the maximum profit
pair<int, int> jobScheduling(vector<Job>& jobs) {
    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), comparator);

    // Find the maximum deadline to initialize the schedule
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Array to keep track of free time slots
    vector<bool> schedule(maxDeadline + 1, false);

    int maxJobs = 0, maxProfit = 0;

    for (const auto& job : jobs) {
        // Find a free slot for this job (starting from its deadline)
        for (int t = job.deadline; t > 0; t--) {
            if (!schedule[t]) {
                // Assign this job to the time slot
                schedule[t] = true;
                maxJobs++;
                maxProfit += job.profit;
                break;
            }
        }
    }

    return {maxJobs, maxProfit};
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs;
    cout << "Enter job ID, deadline, and profit for each job:\n";
    for (int i = 0; i < n; i++) {
        int id, deadline, profit;
        cin >> id >> deadline >> profit;
        jobs.emplace_back(id, deadline, profit);
    }

    pair<int, int> result = jobScheduling(jobs);

    cout << "Max Jobs: " << result.first << endl;
    cout << "Max Profit: " << result.second << endl;

    return 0;
}