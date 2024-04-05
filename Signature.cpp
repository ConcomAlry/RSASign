#include "Signature.h"
#include "PrimeNumberGenerator.h"

using namespace std;

PublicKey& Signature::getPublicKey() {
    return this->pubKey;
}

PrivateKey& Signature::getPrivateKey() {
    return this->prKey;
}

bool Signature::getEquationIsValid() {
    return this->equationIsValid;
}

mpz_class& Signature::getR() {
    return this->r;
}

mpz_class& Signature::getS() {
    return this->s;
}

void Signature::generateSignature() {
    const mpz_class& alpha = pubKey.getAlpha();
    const mpz_class& n = pubKey.getN();
    const mpz_class& gamma = prKey.getGamma();
    mpz_class U = PrimeNumberGenerator::generateRandom(rd, LOWER_BOUND, UPPER_BOUND);
    generateSignature(U);
}

void Signature::generateSignature(const mpz_class& U) {
    const mpz_class& alpha = pubKey.getAlpha();
    const mpz_class& n = pubKey.getN();
    const mpz_class& gamma = prKey.getGamma();

    this->u = U;
    mpz_class Z;
    mpz_powm(Z.get_mpz_t(), alpha.get_mpz_t(), U.get_mpz_t(), n.get_mpz_t());
    this->z = Z;

    mpz_class numerator = 1 - Z * U;
    mpz_class denominator = 2 * Z;
    mpz_class inverse;

    mpz_invert(inverse.get_mpz_t(), denominator.get_mpz_t(), gamma.get_mpz_t());        

    mpz_class k = (numerator * inverse) % gamma;
    this->k = k;

    numerator = Z * U + 1;
    denominator = 2 * Z;

    mpz_invert(inverse.get_mpz_t(), denominator.get_mpz_t(), prKey.getGamma().get_mpz_t());        

    mpz_class g = (numerator * inverse) % gamma;
    this->g = g;

    mpz_powm(r.get_mpz_t(), alpha.get_mpz_t(), k.get_mpz_t(), n.get_mpz_t());
    mpz_powm(s.get_mpz_t(), alpha.get_mpz_t(), g.get_mpz_t(), n.get_mpz_t());
}

void Signature::checkEquationIsValid() {
    const mpz_class& alpha = pubKey.getAlpha();
    const mpz_class& n = pubKey.getN();
    const mpz_class& gamma = prKey.getGamma();
    mpz_class base = r * s;
    mpz_class ind;
    mpz_class inverse;
    mpz_invert(inverse.get_mpz_t(), r.get_mpz_t(), n.get_mpz_t());
    ind = (s * inverse) % n;
    mpz_class pow;
    mpz_powm(pow.get_mpz_t(), base.get_mpz_t(), ind.get_mpz_t(), n.get_mpz_t());
    mpz_class alphaModN = alpha % n;
    mpz_class powModN = pow % n;
    this->leftMod = alphaModN;
    this->rightMod = powModN;
    this->equationIsValid = alphaModN == powModN;
}

void Signature::checkAlphaPowGammaModNEqualOne() {
    mpz_class myAlphPowGamMod;
    mpz_powm(myAlphPowGamMod.get_mpz_t(), pubKey.getAlpha().get_mpz_t(), prKey.getGamma().get_mpz_t(), pubKey.getN().get_mpz_t());
    this->alphPowGamMod = myAlphPowGamMod;
    this->alphPowGamModNEqualOne = (myAlphPowGamMod == 1) ? true : false;
}

bool Signature::getAlphaPowGammaModNEqualOne() {
    return this->alphPowGamModNEqualOne;
}

mpz_class& Signature::getAlphPowGamMod() {
    return alphPowGamMod;
}

Signature::Signature()
{
    this->getPublicKey().generateN();
    this->getPrivateKey().generateGamma(this->getPublicKey().getPPrimeFactor(),
        this->getPublicKey().getQPrimeFactor());    
    this->getPublicKey().generateAlpha(this->getPrivateKey().getGamma());
    checkAlphaPowGammaModNEqualOne();
    int attempts = 0;
    while (true) {
        this->generateSignature();
        this->checkEquationIsValid();
        if (this->equationIsValid)
            break;
        attempts++;

        if (attempts >= 1000) {
            break;
        }
    }
}

Signature::Signature(const Signature& other)
    : pubKey(other.pubKey), prKey(other.prKey),
    r(other.r), s(other.s), equationIsValid(other.equationIsValid) {
}

Signature::Signature(mpz_class p, mpz_class q)
{
    this->pubKey.setP(p);
    this->pubKey.setQ(q);
    std::vector<mpz_class> pMinusOnePrimeFactor = PrimeNumberGenerator::primeFactors(pubKey.getP() - 1);
    std::vector<mpz_class> qMinusOnePrimeFactor = PrimeNumberGenerator::primeFactors(pubKey.getQ() - 1);
    PrimeNumberGenerator::removeCommonElements(pMinusOnePrimeFactor, qMinusOnePrimeFactor);
    if (pMinusOnePrimeFactor.empty() || qMinusOnePrimeFactor.empty()) 
        throw std::runtime_error("Не удалось подобрать gamma");
    this->prKey.setGamma1(pMinusOnePrimeFactor.back());
    this->prKey.setGamma2(qMinusOnePrimeFactor.back());
    this->pubKey.setN(p * q);
    this->prKey.setGamma(this->prKey.getGamma1() * this->prKey.getGamma2());
    this->pubKey.generateAlpha(this->prKey.getGamma());
    checkAlphaPowGammaModNEqualOne();
    int attempts = 0;
    while (true) {
        this->generateSignature();
        this->checkEquationIsValid();
        if (this->equationIsValid)
            break;
        attempts++;
        if (attempts >= 1000) {
            break;
        }
    }
}

Signature::~Signature()
{
}
