// MESSAGE ENCRYPTER V1.0
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

string pwd, pswd, msg, key, encrypted_msg;
int salt, pwd_i, key_i;
ifstream saltin, msgin;

int main() {
    // ------ input ------
    // input salt
    cout << "Input the file path of the salt: "
    cin >> pwd_salt;
    cout << endl;
    saltin.open(pwd_salt);
    saltin >> salt;
    // input password
    cout << "Input the password: ";
    cin >> pswd;
    cout << endl;
    // input message
    cout << "Input the file path of the message: "
    cin >> pwd_msg;
    cout << endl;
    msgin.open(pwd_msg);
    msgin >> msg;
}