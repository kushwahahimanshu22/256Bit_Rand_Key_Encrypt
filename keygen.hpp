#ifndef KEYGEN
#define KEYGEN

#include <random>
#include <vector>
#include <bitset>

std::vector<uint8_t> keygen(int len){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint8_t> dist(0,255);

    std::vector<uint8_t> key;
    for(int i=0;i<len;i++){
        key.push_back(dist(gen));
    }
    return key;
}

std::string encrypt(std::string &plaintext, std::vector<uint8_t> &key){
    std::string cipher;
    for(int i=0;i<plaintext.size();i++){
        cipher += plaintext[i] ^ key[i%key.size()];
    }
    return cipher;
}

std::string decrypt(std::string &cipher, std::vector<uint8_t> &key){
    return encrypt(cipher, key);
}

#endif