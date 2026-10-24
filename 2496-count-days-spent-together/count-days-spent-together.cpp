#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        const vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        
        auto dateToDays = [&](const string& date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonths[i];
            }
            return totalDays;
        };
        
        int startAlice = dateToDays(arriveAlice);
        int endAlice = dateToDays(leaveAlice);
        int startBob = dateToDays(arriveBob);
        int endBob = dateToDays(leaveBob);
        
        
        int overlapStart = max(startAlice, startBob);
        int overlapEnd = min(endAlice, endBob);
        
        
        return max(0, overlapEnd - overlapStart + 1);
    }
};