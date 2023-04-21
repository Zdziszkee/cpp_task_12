//
// Created by Kacper Kuchta on 4/20/23.
//

#include "BigInt.h"

BigInt BigInt::add(const BigInt& other)
{
    std::string a = *this->str;
    std::string c = *other.str;
    int alen = a.length(), clen = c.length();
    int n = fmax(alen, clen);
    if (alen > clen)
        c.insert(0, alen - clen, '0');
    else if (alen < clen)
        a.insert(0, clen - alen, '0');
    std::string res(n + 1, '0');
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] - '0') + (c[i] - '0') + carry;
        carry = digit / 10;
        res[i + 1] = digit % 10 + '0';
    }
    if (carry == 1) {
        res[0] = '1';
        return BigInt(res);
    }
    else {
        return BigInt(res.substr(1));
    }
}

BigInt BigInt::subtract(const BigInt& bigInt)
{
    std::string result;
    int borrow = 0;

    std::string num1 = *str;
    std::string num2 = *bigInt.str;

    int maxLength = fmax(num1.length(), num2.length());
    num1 = std::string(maxLength - num1.length(), '0') + num1;
    num2 = std::string(maxLength - num2.length(), '0') + num2;

    for (int i = maxLength - 1; i >= 0; i--) {
        int diff = (num1[i] - '0') - (num2[i] - '0') - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        result.insert(0, std::to_string(diff));
    }

    result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));
    return BigInt(result);
}

BigInt::BigInt(const char *s)
        : str(nullptr)
{
    if (s != nullptr)
        str = new std::string(s);
    else
        str = new std::string("0");

}
BigInt::BigInt(const std::string &s): str(nullptr)
{

    if (!s.empty())
        str = new std::string(s);
    else
        str = new std::string("0");

}
BigInt& BigInt::operator=(const BigInt& s)
{
    if (this != &s)
    {
        delete str;
        str = nullptr;
        str = new std::string{ " ", s.str->size() };
        *str = *s.str;
    }

    return *this;
}

BigInt& BigInt::operator=(BigInt&& s)
{
    if (this != &s)
    {
        delete str;
        str = s.str;
        s.str = nullptr;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const BigInt& b)
{
    os << *b.str;
    return os;
}

BigInt::~BigInt()
{
    delete str;
}