/// @file leibnitz_pi_converge
/// @brief prints out value of pi using the leibnitz formula with n ranging from 2^1 - 2^20
/// @author Sarah Yoon
/// 
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
    for (int i = 1; i < 21; i++) {
        n = pow(2.0, i);
        for (int k = 0; k <= n; k++) {
            pi += (pow(-1.0, (double)k) / (2.0 * k + 1.0));
        }
        pi *= 4.0;
        cout << setprecision(15) << "PI: " << pi << "; n: " << n << endl;
        pi = 0;
    }
}
