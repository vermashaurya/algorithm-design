#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compareActivities(const Activity& a1, const Activity& a2) {
    return (a1.finish < a2.finish);
}

vector<Activity> selectActivities(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compareActivities);
    
    vector<Activity> selectedActivities;
    selectedActivities.push_back(activities[0]);
    
    int prevFinishTime = activities[0].finish;
    
    for (size_t i = 1; i < activities.size(); i++) {
        if (activities[i].start >= prevFinishTime) {
            selectedActivities.push_back(activities[i]);
            prevFinishTime = activities[i].finish;
        }
    }
    
    return selectedActivities;
}

int main() {
    vector<Activity> activities = {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };
    
    vector<Activity> selectedActivities = selectActivities(activities);
    
    cout << "Selected Activities:\n";
    for (const Activity& activity : selectedActivities) {
        cout << "Start: " << activity.start << ", Finish: " << activity.finish << endl;
    }
    
    return 0;
}
