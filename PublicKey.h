#pragma once
#pragma warning( disable : 4127 )
#pragma warning( disable : 4146 )

#include "GlobalVariable.h"
#include "PrimeNumberGenerator.h"
#include <vector>
#include <algorithm>
#include <random>
#include <gmpxx.h>
#include <cmath>
#include <locale>
#include <tuple>

using namespace std;

class PublicKey
{
public:
    PublicKey() : pPrimeFactor(), qPrimeFactor(), p(), q(), n(), alpha() {}
    PublicKey(const PublicKey& other);
    PublicKey& operator = (const PublicKey& other);
    PublicKey(mpz_class& gamma, mpz_class& gamma1, mpz_class& gamma2);
    PublicKey(mpz_class n, mpz_class alpha);
    ~PublicKey();

    mpz_class& getN();

    void setN(mpz_class value);

    mpz_class& getP();

    void setP(mpz_class value);

    mpz_class& getQ();

    void setQ(mpz_class value);

    mpz_class& getAlpha();

    std::vector<mpz_class>& getPPrimeFactor();

    std::vector<mpz_class>& getQPrimeFactor();

    void generateN();

    void generateAlpha(mpz_class& gamma);

private:
    vector<mpz_class> pPrimeFactor, qPrimeFactor;
    mpz_class p, q;
    mpz_class n;
    mpz_class alpha;
    std::random_device rd;
};



