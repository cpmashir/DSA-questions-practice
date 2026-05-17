#include <vector>

using namespace std;

// Fast I/O optimization
auto speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // Base Case 1: Out of bounds or already visited
        if (start < 0 || start >= arr.size() || arr[start] < 0) {
            return false;
        }
        
        // Base Case 2: Target found
        if (arr[start] == 0) {
            return true;
        }
        
        // Grab the jump value and flip the sign to mark as visited
        int jump = arr[start];
        arr[start] = -jump; 
        
        // Short-circuit evaluation: if the forward path works, backward path won't even execute
        return canReach(arr, start + jump) || canReach(arr, start - jump);
    }
};