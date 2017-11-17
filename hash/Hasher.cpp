#include "Hasher.h"

template<typename T, typename Functor>
Hasher<T, Functor>::Hasher(ULL s, Functor f) :
size(s),
table(std::vector<std::vector<T> >(s)),
functor(f)
{;}

template<typename T, typename Functor>
void Hasher<T, Functor>::add(T value)
{table[hash(value)].push_back(value);}

template<typename T, typename Functor>
bool Hasher<T, Functor>::search(T value)
{
  std::vector<T> slot = table[hash(value)];
  int i;
  for (i=0; i<slot.size(); i++)
    {
      if (slot[i] == value)
	{return true;}
    }
  return false;
}

template<typename T, typename Functor>
ULL Hasher<T, Functor>::hash(T value)
{
  ULL x = functor(value);
  x %= size;
  return ((x>=0)?x:x+size);
}

template<typename T, typename Functor>
void Hasher<T, Functor>::stats()
{
  ULL used=0, min, max, entries=0, s;
  double avg;
  ULL i;
  bool init = false;
  for(i=0; i<size; i++)
    {
      if(! table[i].empty())
	{used++;
	  entries += (s = table[i].size());
	  if      (! init)  {max=min=s; init=true;}
	  else if (s < min) {min=s;}
	  else if (s > max) {max=s;}
	}
    }
  avg = (double)entries/used;
  std::cout << "Out of " << size << " bins, ";
  std::cout << used  << " were used and " << size-used << " were not.\n";
  std::cout << "Used bin stats:\n";
  std::cout << "Minimum length: " << min << std::endl;
  std::cout << "Maximum length: " << max << std::endl;
  std::cout << "Average length: " << avg << std::endl << std::endl;
}
