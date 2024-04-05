#pragma once
#pragma warning( disable : 4127 )
#pragma warning( disable : 4146 )

#include "GlobalVariable.h"
#include <vector>
#include <gmpxx.h>

class PrivateKey
{
public:
    PrivateKey() : gamma(), gamma1(), gamma2() {}
    PrivateKey(mpz_class gamma);
    ~PrivateKey();

    mpz_class& getGamma();

    mpz_class& getGamma1();

    mpz_class& getGamma2();

    void setGamma(mpz_class value);

    void setGamma1(mpz_class value) {
        this->gamma1 = value;
    }

    void setGamma2(mpz_class value) {
        this->gamma2 = value;
    }

    void generateGamma(std::vector<mpz_class>& pPrimeFactor, std::vector<mpz_class> qPrimeFactor);

private:
    mpz_class gamma;
    mpz_class gamma1;
    mpz_class gamma2;
};



