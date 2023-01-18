/// @file Project_FrequenciesOfMusicalNotes
/// @brief 
/// @author Sarah Yoon
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int main()
{
    //C#0, D0, D3, C4, D#7, and C8
    cout << "Reference of Frequency: 16.35 Hz" << endl;
    cout << "Speed of Sound: 345 m/s" << endl;

    double c0fq = 16.35 * pow(2.0, 0) * pow(1.059463094359, 0);
    double csharp0fq = 16.35 * pow(2.0, 0) * pow(1.059463094359, 1);
    double d0fq = 16.35 * pow(2.0, 0) * pow(1.059463094359, 2);
    double d3fq = 16.35 * pow(2.0, 3) * pow(1.059463094359, 2);
    double c4fq = 16.35 * pow(2.0, 4) * pow(1.059463094359, 0);
    double dsharp7fq = 16.35 * pow(2.0, 7) * pow(1.059463094359, 3);
    double c8fq = 16.35 * pow(2.0, 8) * pow(1.059463094359, 0);

    cout << "Note: C0; nu: 0; k: 0; frequency: " << c0fq << "; wavelength: " << (345.0 / c0fq) * 100.0 << " cm" << endl;
    cout << "Note: C#0; nu: 0; k: 1; frequency: " << csharp0fq << "; wavelength: " << (345.0 / csharp0fq) * 100.0 << " cm" << endl;
    cout << "Note: D0; nu: 0; k: 2; frequency: " << d0fq << "; wavelength: " << (345.0 / d0fq) * 100.0 << " cm" << endl;
    cout << "Note: D3; nu: 3; k: 2; frequency: " << d3fq << "; wavelength: " << (345.0 / d3fq) * 100.0 << " cm" << endl;
    cout << "Note: C4; nu: 4; k: 0; frequency: " << c4fq << "; wavelength: " << (345.0 / c4fq) * 100.0 << " cm" << endl;
    cout << "Note: D#7; nu: 7; k: 3; frequency: " << dsharp7fq << "; wavelength: " << (345.0 / dsharp7fq) * 100.0 << " cm" << endl;
    cout << "Note: C8; nu: 8; k: 0; frequency: " << c8fq << "; wavelength: " << (345.0 / c8fq) * 100.0 << " cm" << endl;
}