#include "Primer.h"

Primer::Primer()
{
  primes.push_back(2LL);
  primes.push_back(3LL);

}

inline
ULL Primer::last()
//Note: due to constructor, will always return odd
{return primes[primes.size()-1];}

ULL Primer::next()
{//Finds the smallest prime larger than last()
  ULL x = last()+2;
  while (! isPrime(x))
    {x += 2;}
  primes.push_back(x);
  return x;
}

ULL Primer::next(ULL x)
{//Finds a prime larger than x
  //current (bad) implementation makes object a one-shotter
  ULL ans;
  if (x > last())
    {while (x > (ans = next())) {;}}
  else
    {ans = last();}
  return ans;
}

bool Primer::isPrime(ULL x)
{//x can be assumed to be odd
  ULL i, n, div;
  for (i=1; i<primes.size(); i++)
    {div = primes[i];
      if (div*div > x) {break;}
      else if (x%div == 0) {return false;}
    }
  return true;
}
