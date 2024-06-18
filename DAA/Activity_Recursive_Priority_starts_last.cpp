#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Activity {
    int start, end;
};

struct CompareActivities {
    bool operator()(const Activity& a1, const Activity& a2) {
        return a1.start < a2.start;
    }
};

void selectActivities(vector<Activity>& activities, priority_queue<Activity, vector<Activity>, CompareActivities>& selected, int current) {
    if (current >= activities.size()) {
        return;
    }

    Activity currentActivity = activities[current];
    bool conflict = false;
    if (!selected.empty() && selected.top().start < currentActivity.end) {
        conflict = true;
    }
    if (!conflict) {
        selected.push(currentActivity);
    }
    selectActivities(activities, selected, current + 1);
}

int main() {
  
    vector<Activity> activities = {{1, 4},{3, 5},{0, 6},{5, 7},{3, 8},{5, 9}
    };

    priority_queue<Activity, vector<Activity>, CompareActivities> selected;

    selectActivities(activities, selected, 0);
    while (!selected.empty()) {
        cout << "[" << selected.top().start << ", " << selected.top().end << "]" << endl;
        selected.pop();
    }

    return 0;
}
