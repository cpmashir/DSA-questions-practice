class Solution {
public:
    double angleClock(int hour, int minutes) {
        double diff = abs(((hour % 12) * 30.0 + minutes * 0.5) - (minutes * 6.0));
        return diff > 180.0 ? 360.0 - diff : diff;
    }
};