#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

static inline double circle_area(double radius)
{
    return M_PI * pow(radius, 2);
}

int main() {
    size_t t;
    cin >> t;
    
    for (size_t tc = 1; tc <= t; tc++) {
        printf("Case #%zu: ", tc);
        
        size_t R, A, B;
        cin >> R >> A >> B;
        
        double area = circle_area(R);

        for (size_t i = 1, radius = R; radius > 0; i++) {
            if (i % 2 == 0) {
                // draw right
                radius = fabs(radius / B);
            } else {
                // draw left
                radius *= A;
            }
            area += circle_area(radius);
        }
        
        printf("%.6lf\n", area);
    }
}
