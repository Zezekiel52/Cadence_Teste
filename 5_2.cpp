#include <algorithm>
#include <cstdint>
#include <iostream>

class BigInt {
public:
    BigInt(unsigned len);
    BigInt(const BigInt& bi);
    BigInt& operator=(const BigInt& bi);
    BigInt(BigInt&& bi) noexcept;  // Move constructor
    BigInt& operator=(BigInt&& bi) noexcept;  // Move assignment operator
    ~BigInt();

private:
    unsigned len_;
    uint8_t* mag_;
};

BigInt::BigInt(unsigned len)
    : len_(len), mag_(len ? new uint8_t[len] : nullptr) {}

BigInt::BigInt(const BigInt& bi)
    : len_(bi.len_), mag_(len_ ? new uint8_t[bi.len_] : nullptr) {
    std::copy(bi.mag_, bi.mag_ + len_, mag_);
}

BigInt& BigInt::operator=(const BigInt& bi) {
    if (&bi == this) return *this;
    len_ = bi.len_;
    delete[] mag_;
    mag_ = len_ ? new uint8_t[bi.len_] : nullptr;
    std::copy(bi.mag_, bi.mag_ + len_, mag_);
    return *this;
}

BigInt::BigInt(BigInt&& bi) noexcept
    : len_(bi.len_), mag_(bi.mag_) {
    bi.len_ = 0;
    bi.mag_ = nullptr;
}

BigInt& BigInt::operator=(BigInt&& bi) noexcept {
    if (&bi == this) return *this;
    delete[] mag_;
    len_ = bi.len_;
    mag_ = bi.mag_;
    bi.len_ = 0;
    bi.mag_ = nullptr;
    return *this;
}

BigInt::~BigInt() {
    delete[] mag_;
}

int main() {
    BigInt a(5);  // Create a BigInt object with length 5
    BigInt b = std::move(a);  // Move constructor

    BigInt c(3);
    BigInt d(2);
    d = std::move(c);  // Move assignment operator

    return 0;
}
