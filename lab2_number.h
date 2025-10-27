#pragma once
#include <cinttypes>
#include <iostream>


struct int2025_t {
    static const int SIZE = 253; 
    static const int BYTES = 253;
    static const int BITS = 2024; 
    
    uint8_t data[SIZE]; 
    bool is_positive; 
};

static_assert(sizeof(int2025_t) <= 254,  "Size of int2025_t must be no higher than 254 bytes");

int2025_t from_int(int32_t i);

int2025_t from_string(const char* buff);

int2025_t operator+(const int2025_t& lhs, const int2025_t& rhs);

int2025_t operator-(const int2025_t& lhs, const int2025_t& rhs);

int2025_t operator*(const int2025_t& lhs, const int2025_t& rhs);

int2025_t operator/(const int2025_t& lhs, const int2025_t& rhs);

bool operator==(const int2025_t& lhs, const int2025_t& rhs);

bool operator!=(const int2025_t& lhs, const int2025_t& rhs);

std::ostream& operator<<(std::ostream& stream, const int2025_t& value);