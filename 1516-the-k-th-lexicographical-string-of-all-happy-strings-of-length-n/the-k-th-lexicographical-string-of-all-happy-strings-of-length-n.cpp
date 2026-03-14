class Solution {
public:
    string getHappyString(int n, int k) {
        // Total number of happy strings is 3 * 2^(n-1)
        int total = 3 * pow(2, n - 1);
        if (k > total) return "";

        string result = "";
        vector<char> letters = {'a', 'b', 'c'};
        
        // Determine the first character
        // Each starting letter covers 2^(n-1) possibilities
        int partitionSize = pow(2, n - 1);
        for (char c : letters) {
            if (k <= partitionSize) {
                result += c;
                break;
            }
            k -= partitionSize;
        }

        // Determine the remaining n-1 characters
        for (int i = 1; i < n; i++) {
            partitionSize /= 2; // Each subsequent choice splits remaining space in 2
            for (char c : letters) {
                if (c == result.back()) continue; // Must be "happy"
                
                if (k <= partitionSize) {
                    result += c;
                    break;
                }
                k -= partitionSize;
            }
        }

        return result;
    }
};