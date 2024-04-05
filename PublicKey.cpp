#include "PublicKey.h"
#include "GlobalVariable.h"

mpz_class& PublicKey::getN() {
    return this->n;
}

void PublicKey::setN(mpz_class value) {
    this->n = value;
}

mpz_class& PublicKey::getP() {
    return this->p;
}

void PublicKey::setP(mpz_class value) {
    this->p = value;
}

mpz_class& PublicKey::getQ() {
    return this->q;
}

void PublicKey::setQ(mpz_class value) {
    this->q = value;
}

mpz_class& PublicKey::getAlpha() {
    return this->alpha;
}

std::vector<mpz_class>& PublicKey::getPPrimeFactor() {
    return this->pPrimeFactor;
}

std::vector<mpz_class>& PublicKey::getQPrimeFactor() {
    return this->qPrimeFactor;
}


void PublicKey::generateN()
{
    bool shouldExit = false;

    while (!shouldExit) {
        std::vector<mpz_class> primeNumbers = PrimeNumberGenerator::generatePrimes(PRIME_COUNT, DEPTH_COUNT);

        for (int i = 0; i < 10; i++) {
            this->p = PrimeNumberGenerator::generateBigPrimeWithTest(primeNumbers, SAMPLE_COUNT, rd, this->pPrimeFactor);
            this->q = PrimeNumberGenerator::generateBigPrimeWithTest(primeNumbers, SAMPLE_COUNT, rd, this->qPrimeFactor);

            if (!PrimeNumberGenerator::NumbersEqualCheck(this->pPrimeFactor, this->qPrimeFactor)) {
                shouldExit = true;
                break; 
            }
        }
        if (shouldExit) {
            break;
        }
    }
    
    this->n = this->p * this->q;
}

void PublicKey::generateAlpha(mpz_class& gamma)
{
    mpz_class beta(2);
    mpz_class ind = (this->p - 1) * (this->q - 1) / gamma;
    mpz_class myAlplha;
    mpz_powm(myAlplha.get_mpz_t(), beta.get_mpz_t(), ind.get_mpz_t(), this->n.get_mpz_t());
    this->alpha = myAlplha;
}

PublicKey::PublicKey(const PublicKey& other)
    : pPrimeFactor(other.pPrimeFactor), qPrimeFactor(other.qPrimeFactor),
    p(other.p), q(other.q), n(other.n), alpha(other.alpha) {
}

PublicKey& PublicKey::operator = (const PublicKey& other) {
    if (this != &other) {
        pPrimeFactor = other.pPrimeFactor;
        qPrimeFactor = other.qPrimeFactor;
        p = other.p;
        q = other.q;
        n = other.n;
        alpha = other.alpha;
    }
    return *this;
}

PublicKey::PublicKey(mpz_class& gamma, mpz_class& gamma1, mpz_class& gamma2)
{
    generateN();
    generateAlpha(gamma);
}

PublicKey::PublicKey(mpz_class n, mpz_class alpha)
{
    this->n = n;
    this->alpha = alpha;
}

PublicKey::~PublicKey()
{
}