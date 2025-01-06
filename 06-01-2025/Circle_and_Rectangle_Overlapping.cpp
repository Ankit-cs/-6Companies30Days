
/*
INTUTION:

*Find the closest point on the rectangle to the circle's center.
*Calculate the squared distance between the circle's center and this closest point.
*If the distance is less than or equal to the squared radius, the circle and rectangle overlap.
*If not, they do not overlap.
*/


class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));
        
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;
        
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};
