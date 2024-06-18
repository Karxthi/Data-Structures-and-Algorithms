#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

void selectActivities(Activity arr[], int n, priority_queue<int, vector<int>, greater<int>>& pq, int lastFinishTime) {
    if (n == 0) {
        return;
    }

    if (arr[0].start >= lastFinishTime) {
        cout << "(" << arr[0].start << ", " << arr[0].finish << ")" << endl;
        pq.push(arr[0].finish);
        selectActivities(arr + 1, n - 1, pq, arr[0].finish);
    } else {
        selectActivities(arr + 1, n - 1, pq, lastFinishTime);
    }
}

int main() {
    Activity arr[] = { {1, 3}, {2, 5}, {3, 4}, {4, 8}, {5, 9}, {8, 10} };
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n, [](Activity a, Activity b) {
        return a.finish < b.finish;
    });

    priority_queue<int, vector<int>, greater<int>> pq;

    selectActivities(arr, n, pq, 0);

    return 0;
}
