#pragma once
#pragma warning( disable : 4127 )
#pragma warning( disable : 4146 )

#include "GlobalVariable.h"
#include <vector>
#include <algorithm>
#include <random>
#include <gmpxx.h>
#include <cmath>
#include <locale>
#include <tuple>
#include <chrono>

using namespace std;

class PrimeNumberGenerator
{
public:
    static std::vector<mpz_class> generatePrimes(int numsCount, int depthCount);

    static mpz_class generateBigPrimeWithTest(std::vector<mpz_class>& primeNumbers, int sampleCount,
        std::random_device& rand, std::vector<mpz_class>& primeFactor);

    static mpz_class generateBigPrime(std::vector<mpz_class>& primeNumbers, int sampleCount,
        std::vector<mpz_class>& primeFactor);
       
    static bool NumbersEqualCheck(vector<mpz_class>& v1, vector<mpz_class>& v2);

    static vector<mpz_class> PrimeNumberGenerator::primeFactors(mpz_class n);

    static void removeCommonElements(std::vector<mpz_class>& vector1, std::vector<mpz_class>& vector2);

    static mpz_class generateRandom(std::random_device& rand, int lowerBound, int upperBound);

private:
    PrimeNumberGenerator() = delete;
    ~PrimeNumberGenerator() = delete;
};

