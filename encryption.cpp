#include<iostream>
#include "keygen.hpp"

using namespace std;

int main(int argc, char **argv){
    if(argc != 2){
        cout << "Usage ./encryption [string]" << endl;
        exit(1);
    }
    //Generate 256 bit key
    vector<uint8_t> key = keygen(32);
    string plaintext(argv[1]);
    //Encryption
    string cipher = encrypt(plaintext, key);
    cout << "Generated Cipher : ";
    cout << cipher << endl;
    //Decryption
    string decipher = decrypt(cipher, key);
    cout << "Decrypting the cipher : ";
    cout << decipher << endl;
    return 0;
}