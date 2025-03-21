/// @file FreqMusicalnotesLoopsArrays
/// @brief prints out each note's frqeuency and wavelength 
/// @author Sarah Yoon

#include <iostream>
#include <string>
#include<cmath>
using namespace std;

int main()
{
    string a_strNotes[] = {
     "C0", "C#0", "D0","D#0", "E0", "F0", "F#0", "G0", "G#0", "A0", "A#0", "B0",
     "C1", "C#1", "D1","D#1", "E1", "F1", "F#1", "G1", "G#1", "A1", "A#1", "B1",
     "C2", "C#2", "D2","D#2", "E2", "F2", "F#2", "G2", "G#2", "A2", "A#2", "B2",
     "C3", "C#3", "D3","D#3", "E3", "F3", "F#3", "G3", "G#3", "A3", "A#3", "B3",
     "C4", "C#4", "D4","D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4",
     "C5", "C#5", "D5","D#5", "E5", "F5", "F#5", "G5", "G#5", "A5", "A#5", "B5",
     "C6", "C#6", "D6","D#6", "E6", "F6", "F#6", "G6", "G#6", "A6", "A#6", "B6",
     "C7", "C#7", "D7","D#7", "E7", "F7", "F#7", "G7", "G#7", "A7", "A#7", "B7",
     "C8", "C#8", "D8","D#8", "E8", "F8", "F#8", "G8", "G#8", "A8", "A#8", "B8",
    };
    const int k_nOctaves = 9;    // Number of octaves to consider 
    const int k_nHalfTones = 12; // Number of Half-tones in an octave 
    int pos = 0;

    for (int nu = 0; nu < k_nOctaves; nu++)
    {
        for (int k = 0; k < k_nHalfTones; k++)
        {
            float f = 16.35 * pow(2.0, nu) * pow(1.059463094359, k);
            float dWavelengthCentimeters = (345.0 / f) * 100.0;
            // ?? 
            // Select name for note (e.g. "C#0") from array (assign to strNote) 
            // ?? (Need to compute offset into array based on nu and k) 
            cout << "Note: " << a_strNotes[pos] << "; nu: " << nu << "; k: " << k << "; frequency: " << f << " Hz; wavelength: " << dWavelengthCentimeters << " cm" << std::endl;
            pos++;
        }
    }
}
