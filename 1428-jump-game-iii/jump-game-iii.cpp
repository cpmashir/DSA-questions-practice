class Solution {
public:
    bool canReach(vector<int>& arr, int n, int start) {
        int q[50001]; 
        int head = 0, tail = 0;
        
        q[tail++] = start;
        
        while (head < tail) {
            int curr = q[head++];
            int jump = arr[curr];
            
            if (jump == 0) return true;
            if (jump < 0) continue;
            
            arr[curr] = -jump;
            
            int forward = curr + jump;
            if (forward < n && arr[forward] >= 0) {
                q[tail++] = forward;
            }
            
            int backward = curr - jump;
            if (backward >= 0 && arr[backward] >= 0) {
                q[tail++] = backward;
            }
        }
        
        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        return canReach(arr, arr.size(), start);
    }
};