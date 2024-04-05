#include "PrivateKey.h"

mpz_class& PrivateKey::getGamma() {
    return this->gamma;
}

mpz_class& PrivateKey::getGamma1() {
    return this->gamma1;
}

mpz_class& PrivateKey::getGamma2() {
    return this->gamma2;
}

void PrivateKey::setGamma(mpz_class value) {
    this->gamma = value;
}

void PrivateKey::generateGamma(std::vector<mpz_class>& pPrimeFactor, std::vector<mpz_class> qPrimeFactor) {
    this->gamma1 = pPrimeFactor[0];
    this->gamma2 = qPrimeFactor[0];
    this->gamma = this->gamma1 * this->gamma2;
}

PrivateKey::PrivateKey(mpz_class gamma)
{
    this->gamma = gamma;
}

PrivateKey::~PrivateKey()
{
}

