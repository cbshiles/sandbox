#define ULL unsigned long long

#include <vector>

class Primer {
 public:
  Primer();
  ULL last();
  ULL next();
  ULL next(ULL x);
 private:
  std::vector<ULL> primes;
  bool isPrime(ULL x);
};
