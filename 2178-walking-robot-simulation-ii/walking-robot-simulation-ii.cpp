class Robot {
private:
    int w, h, perimeter;
    int pos = 0;
    bool moved = false;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        // Total steps to complete one full lap
        perimeter = 2 * (w - 1) + 2 * (h - 1);
    }
    
    void step(int num) {
        moved = true;
        pos = (pos + num) % perimeter;
        // If the robot completes a full lap and ends at 0, 
        // it technically faces "South" at the origin.
        if (pos == 0) pos = perimeter; 
    }
    
    vector<int> getPos() {
        // Map the linear 'pos' back to X, Y coordinates
        // Using a temporary variable to handle the "pos = perimeter" logic
        int curr = pos % perimeter; 
        
        if (curr < w) return {curr, 0};                   // Bottom edge
        if (curr < w + h - 1) return {w - 1, curr - (w - 1)}; // Right edge
        if (curr < 2 * w + h - 2) return {w - 1 - (curr - (w + h - 2)), h - 1}; // Top edge
        return {0, h - 1 - (curr - (2 * w + h - 3))};    // Left edge
    }
    
    string getDir() {
        if (!moved || (pos > 0 && pos < w)) return "East";
        if (pos >= w && pos < w + h - 1) return "North";
        if (pos >= w + h - 1 && pos < 2 * w + h - 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */