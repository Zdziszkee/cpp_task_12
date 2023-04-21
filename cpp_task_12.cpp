#include <iostream>
#include "BigInt.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    BigInt bigInt = "123";
    BigInt result = bigInt.add(BigInt("123"));
    std::cout<<result<<std::endl;

    BigInt result2 = bigInt.subtract(BigInt("3"));
    std::cout<<result2<<std::endl;

    return 0;
}
