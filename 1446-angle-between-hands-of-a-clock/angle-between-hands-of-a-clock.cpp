class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = minutes * 6.0;
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        
        double diff = abs(hourAngle - minAngle);
        
        // Ensure we return the smaller of the two possible angles
        return diff > 180.0 ? 360.0 - diff : diff;
    }
};