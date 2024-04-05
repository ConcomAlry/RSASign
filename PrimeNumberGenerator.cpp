#include "PrimeNumberGenerator.h"
#include "GlobalVariable.h"
#pragma warning (disable : 2020)

std::random_device rd;

std::vector<mpz_class> PrimeNumberGenerator::generatePrimes(int numsCount, int depthCount) {
    std::vector<mpz_class> pseudoPrimes;

    // Используем текущее время в качестве начального значения для генератора случайных чисел
    unsigned long seed = static_cast<unsigned long>(std::time(nullptr));
    gmp_randstate_t state;
    gmp_randinit_default(state);
    gmp_randseed_ui(state, seed);

    int foundCount = 0;

    while (foundCount < numsCount) {
        mpz_class pseudoPrime;
        mpz_urandomb(pseudoPrime.get_mpz_t(), state, depthCount * 3.3219);

        if (mpz_probab_prime_p(pseudoPrime.get_mpz_t(), 1000)) {
            pseudoPrimes.push_back(pseudoPrime);
            ++foundCount;
        }
    }
    return pseudoPrimes;
}

mpz_class PrimeNumberGenerator::generateBigPrimeWithTest(std::vector<mpz_class>& primeNumbers, int sampleCount,
    std::random_device& rand, std::vector<mpz_class>& primeFactor)
{    
    std::reverse(primeNumbers.begin(), primeNumbers.end());
    mpz_class bigPrime;
    int i = 0;
    bool shouldExit = false;
    while (true)
    {
        primeNumbers = generatePrimes(PRIME_COUNT, DEPTH_COUNT);
        while (true) {
            bigPrime = generateBigPrime(primeNumbers, sampleCount, primeFactor);
            i++;

            if (i == 20) {
                i = 0;
                break;
            }

            if (mpz_probab_prime_p(bigPrime.get_mpz_t(), 1000)) {
                shouldExit = true;
                break;
            }
        }
        if (shouldExit)
            break;
    }
    return bigPrime;
}

mpz_class PrimeNumberGenerator::generateBigPrime(std::vector<mpz_class>& primeNumbers, int sampleCount,
    std::vector<mpz_class>& primeFactor)
{
    std::mt19937 g(rd());
    //Перемешиваем вектор случайным образом
    std::shuffle(primeNumbers.begin(), primeNumbers.end(), g);
    primeFactor.clear();

    mpz_class bigPrime = 1;

    for (int i = 0; i < sampleCount; i++) {
        bigPrime *= primeNumbers[i];
        primeFactor.push_back(primeNumbers[i]);
    }

    bigPrime = 1 + 2 * bigPrime;
    return bigPrime;
}

bool PrimeNumberGenerator::NumbersEqualCheck(vector<mpz_class>& v1, vector<mpz_class>& v2) {
    bool found = false;
    for (mpz_class i : v1)
    {
        found = find(v2.begin(), v2.end(), i) != v2.end();
        if (found) break;
    }
    return found;
}

vector<mpz_class> PrimeNumberGenerator::primeFactors(mpz_class n) {
    vector<mpz_class> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (mpz_class i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
    return factors;
}

void PrimeNumberGenerator::removeCommonElements(std::vector<mpz_class>& vector1, std::vector<mpz_class>& vector2) {
    std::sort(vector1.begin(), vector1.end());
    std::sort(vector2.begin(), vector2.end());
    std::vector<mpz_class> common_elements;
    std::set_intersection(
        vector1.begin(), vector1.end(),
        vector2.begin(), vector2.end(),
        std::back_inserter(common_elements)
    );

    auto remove_common = [&common_elements](std::vector<mpz_class>& vec) {
        vec.erase(std::remove_if(vec.begin(), vec.end(),
            [&common_elements](const mpz_class& num) {
                return std::binary_search(common_elements.begin(), common_elements.end(), num);
            }),
            vec.end());
        };
    remove_common(vector1);
    remove_common(vector2);
}

mpz_class PrimeNumberGenerator::generateRandom(std::random_device& rand, int lowerBound, int upperBound)
{
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(lowerBound, upperBound);
    int num = distribution(generator);
    mpz_class mpz_num(num);
    return num;
}