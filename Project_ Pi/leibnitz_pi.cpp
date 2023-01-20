/// @file leibnitz_pi
/// @brief prints out value of pi using the leibnitz formula with n = 2^20
/// @author Sarah Yoon
#include <iostream>
#include <string>
#include <cmath>
#include <cfloat>
#include <iomanip>
using namespace std;

int main()
{
    float pi = 0;
    float n = 0;

    cout << "Please enter a non-negative integer upper limit of sumnation for the Leibnitz formula for computing pi:" << endl;
    cin >> n;

    for (int k = 0; k <= n ; k++) {
        pi += (pow(-1.0, (double)k) / (2.0 * k + 1.0));
    }
    pi *= 4.0;

    cout << setprecision(15) << "PI (approx): " << pi << "; n: " << n << endl;
    cout << "PI (actual): " << "3.141592653589793" << endl;

    cout << "Decimal digits of precision: " << DBL_DIG << std::endl;
    cout << "Number of base 2 mantissa digits of double precision floating point value: " << DBL_MANT_DIG << endl;
    cout << "Next representable number from 3.141592653589793: " << nextafter(3.141592653589793, 3.14) << endl;



}
