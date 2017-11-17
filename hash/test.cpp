#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Hasher.cpp"
#include "Functors.h"
#include "Primer.cpp"

using namespace std;

template<typename Functor>
bool searchLoop(Hasher<string, Functor>& instHash)
{
  string str;
  cout << "Search for a string:" << endl;
  while (cin >> str)
    {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << instHash.search(str) << endl; 
    }
}

void analyze(ULL sz, bool prompt=false)
{
  fstream ifile ("dictionary-words.txt");

  Hasher<string, Horners> hornersHash(sz, Horners(37));
  Hasher<string, Ascii> asciiHash(sz, Ascii());
  Hasher<string, MyTry> myHash(sz, MyTry());
  Hasher<string, typename std::hash<string> > stdHash(sz, std::hash<string>());
  
  string word;
  while (ifile >> word)
    {
      transform(word.begin(), word.end(), word.begin(), ::tolower);
      hornersHash.add(word);  
      asciiHash.add(word);  
      myHash.add(word);  
      stdHash.add(word);
    }
  cout << endl << "BUCKET SIZE: " << sz << endl << endl;

  cout << "Horners Hash:" << endl;
  hornersHash.stats();

  cout << "Ascii Hash:" << endl;
  asciiHash.stats();

  cout << "My Hash:" << endl;
  myHash.stats();

  cout << "Standard Hash:" << endl;
  stdHash.stats();

  if(prompt)
    {searchLoop(myHash);}//Hubris
}

int main()
{
  int i, n= 100;
  for (i=0; i<3; i++)
    {analyze(n*=10); analyze(Primer().next(n));}
  analyze(234936); analyze(Primer().next(234936), true);

    return 0;
}
