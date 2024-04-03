
#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159265358979323846;
void radiansToDegrees(const double* radians, double* degrees) {
    *degrees = (*radians * 180.0) / PI;
}
int main() {
    double angleRadians;
    cout << "Enter the angle in radians: ";
    cin >> angleRadians;
    double angleDegrees;
    radiansToDegrees(&angleRadians, &angleDegrees);
    cout << "Angle in radians: " << angleRadians << endl;
    cout << "Angle in degrees: " << angleDegrees << endl;
    return 0;
}
