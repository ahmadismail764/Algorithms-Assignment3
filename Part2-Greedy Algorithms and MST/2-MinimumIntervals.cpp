#include <bits/stdc++.h>
using namespace std;

int minIntervals(vector<string> processes, int mini_gap)
{
    map<string, int> process_count;
    for_each(processes.cbegin(), processes.cend(), [&process_count](const string &p)
             { process_count[p]++; });

    priority_queue<int> pq;
    for (const auto &p : process_count)
        pq.push(p.second);

    int max_count = pq.top();
    pq.pop();
    int idle_slots = (max_count - 1) * mini_gap;

    while (!pq.empty())
    {
        idle_slots -= min(max_count - 1, pq.top());
        pq.pop();
    }

    idle_slots = max(0, idle_slots);
    return processes.size() + idle_slots;
}

int main()
{
    int n, mini_gap;
    cout << "Input the number of processes: \n";
    cin >> n;
    vector<string> processes(n);
    cout << "Input process names: \n";
    for (int i = 0; i < n; i++)
        cin >> processes[i];
    cout << "Input minimum gap: \n";
    cin >> mini_gap;
    cout << minIntervals(processes, mini_gap) << '\n';
}
