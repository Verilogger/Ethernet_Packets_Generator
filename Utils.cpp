#include "Utils.h"
#include <bitset>
#include <sstream>
#include <iomanip>
#include <iostream>


std::string padTo4ByteAlignment(const std::string& data) {
    size_t dataLength = data.length();
    size_t remainder = dataLength % 8;  
    if (remainder != 0) {
        size_t paddingNeeded = 8 - remainder;
        std::string padding = std::string(paddingNeeded, '\0');
        
        for (size_t i = 0; i < paddingNeeded; ++i) {
            padding[i] = (i % 2 == 0) ? '0' : '7';  
        }
        return data + padding;
    }
    return data;
}




std::string intToHex(uint32_t value, size_t width) {
    std::stringstream ss;
    ss << std::setw(width) << std::setfill('0') << std::hex << value;
    return ss.str();
}


uint32_t calculateCRC32(const std::string& data) {
    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < data.length(); ++i) {
        uint8_t byte = static_cast<uint8_t>(data[i]);
        crc = crc ^ byte;
        for (int j = 0; j < 8; ++j) {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xEDB88320;
            else
                crc = crc >> 1;
        }
    }
    return crc ^ 0xFFFFFFFF;
}
