#pragma once
#pragma warning( disable : 4127 )
#pragma warning( disable : 4146 )

#include "GlobalVariable.h"
#include <vector>
#include <algorithm>
#include <random>
#include <gmpxx.h>
#include <cmath>
#include "PublicKey.h"
#include "PrivateKey.h"

class Signature
{
public:
    Signature();
    Signature(const Signature& other);
    Signature(mpz_class p, mpz_class q);
    ~Signature();


    mpz_class leftMod;
    mpz_class rightMod;
    mpz_class u, z, k, g;

    PublicKey& getPublicKey();

    PrivateKey& getPrivateKey();

    bool getEquationIsValid();

    mpz_class& getR();

    mpz_class& getS();

    void generateSignature();

    void generateSignature(const mpz_class& U);

    void checkEquationIsValid();

    void checkAlphaPowGammaModNEqualOne();

    bool getAlphaPowGammaModNEqualOne();

    mpz_class& getAlphPowGamMod();

private:
    PublicKey pubKey;
    PrivateKey prKey;

    mpz_class r;
    mpz_class s;

    bool equationIsValid;

    mpz_class alphPowGamMod;

    bool alphPowGamModNEqualOne;
};



