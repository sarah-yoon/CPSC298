// AutomotiveElectronicControlUnit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class ElectronicControlUnit 
{
public: 
    ElectronicControlUnit();
    ~ElectronicControlUnit();
    void handleCommand(char cCommand);
    void toggleHydraulicJacks();
    void toggleBeltTires();
    void toggleIRIllumination();

private:
    bool m_bActivatedHydrualicJacks = false; //button A
    bool m_bActivatedBeltTires = false; //button B
    bool m_bActivatedIRIllumination = false; //button E
};

ElectronicControlUnit::ElectronicControlUnit() {

}

ElectronicControlUnit::~ElectronicControlUnit() {

}

void ElectronicControlUnit::handleCommand(char cCommand) {
    switch (cCommand)
    {
    case 'A':
    case 'a':
        toggleHydraulicJacks();
        break;
    case 'B':
        toggleBeltTires();
        break;
    case 'b':
        toggleBeltTires();
        break;
    case 'E':
        toggleIRIllumination();
        break;
    case'e':
        toggleIRIllumination();
        break;
    case 'X':
        cout << "Turning off" << endl;
        break;
    case 'x':
        cout << "Turning off" << endl;
        break;
    default:
        cout << "Not a valid option" << endl;
        break;
    }
}

void ElectronicControlUnit::toggleHydraulicJacks() {
    m_bActivatedHydrualicJacks = !m_bActivatedHydrualicJacks;
    if (m_bActivatedHydrualicJacks) {
        cout << "Hydraulic Jacks activated" << endl;
    }
    else {
        cout << "Hydraulic Jacks deactivated" << endl;
    }
}

void ElectronicControlUnit::toggleBeltTires() {
    m_bActivatedBeltTires = !m_bActivatedBeltTires;
    if (m_bActivatedBeltTires) {
        cout << "Belt Tires Jacks activated" << endl;
    }
    else {
        cout << "Belt Tires deactivated" << endl;
    }
}

void ElectronicControlUnit::toggleIRIllumination() {
    m_bActivatedIRIllumination = !m_bActivatedIRIllumination;
    if (m_bActivatedIRIllumination) {
        cout << "Infrared Illumination activated" << endl;
    }
    else {
        cout << "Infrared Illumination deactivated" << endl;
    }
}

int main()
{
    ElectronicControlUnit* e_electronicControlunit = new ElectronicControlUnit();

    cout << "Press X to turn off ignition or enter a steering wheel button (A, B, E)" << endl;
    char userInput = ' ';
    while (userInput != 'X') {
        cin >> userInput;
        cout << "    (A) " << endl;
        cout << "(F) (G) (B)" << endl;
        cout << "(E)     (C)" << endl;
        cout << "    (D) " << endl;
        e_electronicControlunit->handleCommand(userInput);
    }
}

