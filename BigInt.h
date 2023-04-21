//
// Created by Kacper Kuchta on 4/20/23.
//

#ifndef CPP_TASK_12_BIGINT_H
#define CPP_TASK_12_BIGINT_H


#include <string>
#include <iostream>
class BigInt
{
private:
    std::string *str = nullptr;

public:
    BigInt add(const BigInt& a);
    BigInt subtract(const BigInt& a);
    BigInt(const char *s = nullptr);
    BigInt(const std::string &s);
    BigInt& operator=(const BigInt& s);
    BigInt& operator=(BigInt&& s);
    friend std::ostream& operator<<(std::ostream& out, const BigInt& b);
    ~BigInt();
};

#endif //CPP_TASK_12_BIGINT_H
