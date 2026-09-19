class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Find closest x-coordinate in rectangle
        int closestX = max(x1, min(xCenter, x2));

        // Find closest y-coordinate in rectangle
        int closestY = max(y1, min(yCenter, y2));

        // Distance between circle center and closest point
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        // Check if closest point is inside/on the circle
        return dx * dx + dy * dy <= radius * radius;
    }
};