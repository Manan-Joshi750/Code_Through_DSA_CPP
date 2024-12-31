#include <iostream>
#include <cmath> // For sqrt function
using namespace std;

int main() {
    // Declare variables for the coefficients and the roots
    double a, b, c;
    double discriminant, root1, root2;

    // Prompt the user to enter the coefficients of the quadratic equation
    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;

    // Calculate the discriminant
    discriminant = b * b - 4 * a * c;

    // Check the nature of the discriminant
    if (discriminant > 0) {
        // Two distinct and real roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and different." << endl;
        cout << "Root 1 = " << root1 << endl;
        cout << "Root 2 = " << root2 << endl;
    } else if (discriminant == 0) {
        // One real root (repeated)
        root1 = root2 = -b / (2 * a);
        cout << "Roots are real and the same." << endl;
        cout << "Root 1 = Root 2 = " << root1 << endl;
    } else {
        // Complex roots
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Roots are complex and different." << endl;
        cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i" << endl;
    }

    return 0;
}