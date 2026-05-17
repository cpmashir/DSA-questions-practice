#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // Out of bounds or already visited check
        if (start < 0 || start >= arr.size() || arr[start] < 0) {
            return false;
        }
        
        // Base case: destination reached
        if (arr[start] == 0) {
            return true;
        }
        
        // Mark the current index as visited by making it negative
        int jump = arr[start];
        arr[start] = -arr[start];
        
        // Explore both directions
        return canReach(arr, start + jump) || canReach(arr, start - jump);
    }
};