#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
#include <string>

void inverting_bits(char* p, size_t length, uint8_t mask) {
    for (size_t i = 0; i < length; i++) {
        p[i] = p[i] ^ mask;
    }
}

std::string char_to_bin(char c) {
    std::string result = "";
    unsigned char mask = 128;
    int i;
    for (i = 0; i < 8; ++i) {
        result.append(((mask & c) ? "1" : "0"));
        mask >>= 1;
    }
    result.append(" ");
    return result;
}

uint8_t generate_mask(int param) {
    uint8_t mask;
    if (param < 0 or param > 255) {
        srand(time(0));
        mask = rand() % 256;
    }
    else {
        mask = (uint8_t)param;
    }
    return mask;
}

int main() {

    std::cout << "Enter data" << std::endl;
    std::string str;
    std::cin >> str;

    const char* s = str.c_str();
    char* mem = new char[str.length() + 1];
    std::strcpy(mem, s);
    
    size_t length = strlen(mem);

    std::cout << "Original data" << std::endl;
    for (size_t i = 0; i < length; ++i) {
        std::cout << mem[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Binary original data" << std::endl;
    for (size_t i = 0; i < length; ++i) {
        std::cout << char_to_bin(mem[i]);
    }
    std::cout << "\n\n";

    std::cout << "Enter mask like number from 0 to 255 or enter '-1' if you want to generate random mask:\n";
    std::string m;
    std::cin >> m;

    uint8_t mask = generate_mask(stoi(m));

    int len = -1;
    while (len < 0 || len > length) {
        std::cout << "Enter size of memory to invert. Size must be <= than " << length << "\n";
        std::cin >> len;
    }

    inverting_bits(mem, len, mask);

    std::cout << "Data after inverting bytes with mask " <<char_to_bin(mask)<< std::endl;
    for (size_t i = 0; i < length; ++i) {
        std::cout << mem[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Binary data after inverting bytes with mask " <<char_to_bin(mask)<< std::endl;
    for (size_t i = 0; i < length; ++i) {
        std::cout << char_to_bin(mem[i]);
    }
    std::cout << std::endl;
    return 0;
}