#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string randomkeygenerator(string text){
    string randomkey;
    srand(time(nullptr));
    for (int i = 0 ; i < text.length() ; i++){
        if(text[i] == ' '){
            randomkey = randomkey + ' ';
        }
        else{
            char randomchar = 'A' + (rand() % 26);
            randomkey += randomchar;
        }
    }
    return randomkey;
}

string upper_case(string text){
    for (int i = 0 ; i < text.length() ; i++){
        if(text[i] >= 'a' && text[i] <= 'z'){
            text[i] = text[i] - 'a' + 'A';
        }
        else{
            text[i] = text[i];
        }
    }
    return text;
}

string vigenere(string text, string key, bool EncDec) {
    string newtext;
    if (EncDec == 0) {
        for (int i = 0; i < text.length(); i++) {
            if(text[i] == ' '){
                newtext = newtext + ' ';
            }
            else{
                newtext += (text[i] + key[i]) % 26 + 65;
            }
        }
        return newtext;
    } 
    else {
        for (int i = 0; i < text.length(); i++) {
            if(text[i] == ' '){
                newtext = newtext + ' ';
            }
            else{
                int decrypted_char = (text[i] - key[i] + 26) % 26 + 65; 
                newtext += decrypted_char;
            }
    }
    return newtext;
}
}

int main() {
    int option;
    char x;
    do {
        cout << "Welcome to the Encryption-Decryption Station.\n";
        cout << "Enter the task number you would like to perform:\n";
        cout << "1. Encryption     2. Decryption     3. Exit\n";
        cin >> option;
        cin.ignore();

        if (option == 1) {
            string plaintext;

            cout << "Enter the text you would like to encrypt: ";
            getline(cin, plaintext);
            plaintext = upper_case(plaintext);
            string key = randomkeygenerator(plaintext);
            // cout<<"Generated key is: "<<key<<endl;

            string newtext_cipher = vigenere(plaintext, key, 0);
            cout << "Your encrypted text is:\n";
            cout << newtext_cipher << endl;
            cout << "Would you like to start the Decryption process (Y/N) or press any other key to exit: ";
            cin >> x;
            cin.ignore();

            if(x == 'Y' || x == 'y'){
            string ciphertext;
            cout << "Enter the text you would like to decrypt: ";
            getline(cin, ciphertext);
            string newtext_plaintext= vigenere(ciphertext, key, 1);
            cout << "Your decrypted ciphertext:\n";
            cout << newtext_plaintext << endl;
            cout << "Press (Y/y) to continue or any other key to exit: ";
            cin >> x;
            }
        }
        else if (option == 2) {
            string ciphertext;
            string key;
            cout << "Enter the text you would like to decrypt: ";
            getline(cin, ciphertext);
            ciphertext = upper_case(ciphertext);
            cout << "Enter the key used for encryption: ";
            getline(cin, key); 
            string returntext = vigenere(ciphertext, key, 1);
            cout << "Your plaintext is: " << returntext << endl;
            cout << "Press (Y/y) to continue or any other key to exit: ";
            cin >> x;
        }
        else if (option == 3) {
            cout << "Thank you for using the Encryption-Decryption Platform.\n";
            break;
        }
        else if (x != 'y' && x != 'Y') {
            cout << "Thank you for visiting the Platform.\n";
            break;
        }
    } while (x == 'y' || x == 'Y');
    cout << "You have exited the platform. Please rerun the code to use it again. Thank you.\n";
    return 0;
}
