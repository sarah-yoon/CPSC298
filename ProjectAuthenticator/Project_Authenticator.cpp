/// @file Project_Authenticator
/// @brief checks the validity of the inputted code
/// @author Sarah Yoon
#include <iostream>
#include <string>

using namespace std;
int main()
{
    char firstChar;
    char secondChar;
    char thirdChar;

    const char k_cAuthenticatorCodeCharacter1 = 'E';
    const char k_cAuthenticatorCodeCharacter2 = 'C';
    const char k_cAuthenticatorCodeCharacter3 = 'A';
    const int k_iValidCodeChecksum = 5;

    bool messageValid = false;

    cout << "Enter the first character of the message code:" << endl;
    cin >> firstChar;
    cout << "Enter the second character of the message code:" << endl;
    cin >> secondChar;
    cout << "Enter the third character of the message code:" << endl;
    cin >> thirdChar;

    if (k_cAuthenticatorCodeCharacter1 != firstChar || k_cAuthenticatorCodeCharacter2 != secondChar || k_cAuthenticatorCodeCharacter3 != thirdChar) {
        messageValid = false;
    }
    else {
        messageValid = true;
    }

    cout << endl;
    cout << "Authenticator Code: " << k_cAuthenticatorCodeCharacter1 << k_cAuthenticatorCodeCharacter2 << k_cAuthenticatorCodeCharacter3 << endl;
    cout << "Message Code: " << firstChar << secondChar << thirdChar << endl;
    cout << endl;

    if (messageValid) {
        cout << "Message is authentic." << endl;
    }
    else {
        cout << "Message is invalid" << endl;
    }

    if ((k_cAuthenticatorCodeCharacter1 + k_cAuthenticatorCodeCharacter2 + k_cAuthenticatorCodeCharacter3) == (firstChar + secondChar + thirdChar)) {
        cout << "Concurrence: message is authentic." << endl;
    }
    else {
        cout << "Concurrence: message is invalid." << endl;
    }

    cout << endl;


    cout << "Characterization of Message Code" << endl;
    cout << "--------------------------------" << endl;
    cout << "ASCII Values of Messagae Code Characters: " << int(firstChar) << ", " << int(secondChar) << ", " << int(thirdChar) << endl;
    cout << "Sum of ASCII values for Message Code Characters: " << int(firstChar) + int(secondChar) + int(thirdChar) << endl;

    int checksum = (int(firstChar) + int(secondChar) + int(thirdChar)) % 7;

    if (checksum == k_iValidCodeChecksum) {
        cout << "Message code checksum is valid: " << checksum << endl;
    }
    else {
        cout << "Message code checksum is invalid: " << checksum << "; expected: " << k_iValidCodeChecksum << endl;
    }

    if (k_cAuthenticatorCodeCharacter1 != firstChar) {
        cout << "First characters do not match: Message: " << firstChar << "; Authenticator: " << k_cAuthenticatorCodeCharacter1 << endl;
    }
    if (k_cAuthenticatorCodeCharacter2 != secondChar) {
        cout << "Second characters do not match: Message: " << secondChar << "; Authenticator: " << k_cAuthenticatorCodeCharacter2 << endl;
    }
    if (k_cAuthenticatorCodeCharacter3 != thirdChar) {
        cout << "Third characters do not match: Message: " << thirdChar << "; Authenticator: " << k_cAuthenticatorCodeCharacter3 << endl;
    }

    if ((firstChar + secondChar + thirdChar) < (k_cAuthenticatorCodeCharacter1 + k_cAuthenticatorCodeCharacter2 + k_cAuthenticatorCodeCharacter3)) {
        cout << "Message code (" << firstChar + secondChar + thirdChar << ") is lexicographically less than Authenitactor code (" << k_cAuthenticatorCodeCharacter1 + k_cAuthenticatorCodeCharacter2 + k_cAuthenticatorCodeCharacter3 << ")" << endl;
    }
    else {
        cout << "Message code (" << firstChar << secondChar << thirdChar << ") is lexicographically greater than Authenitactor code (" << k_cAuthenticatorCodeCharacter1 << k_cAuthenticatorCodeCharacter2 << k_cAuthenticatorCodeCharacter3 << ")" << endl;
    }

}