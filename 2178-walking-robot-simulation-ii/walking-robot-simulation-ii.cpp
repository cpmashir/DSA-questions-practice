class Robot {
private:
    int w, h, p;
    int pos = 0;
    bool is_origin = true;

public:
    Robot(int width, int height) : w(width), h(height) {
        p = (w + h - 2) << 1;
    }
    
    void step(int num) {
        is_origin = false;
        pos = (pos + num) % p;
    }
    
    vector<int> getPos() {
        if (pos < w) return {pos, 0};
        if (pos < w + h - 1) return {w - 1, pos - w + 1};
        if (pos < 2 * w + h - 2) return {w - 1 - (pos - (w + h - 2)), h - 1};
        return {0, h - 1 - (pos - (2 * w + h - 3))};
    }
    
    string getDir() {
        if (is_origin || (pos > 0 && pos < w)) return "East";
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