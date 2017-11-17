class Horners
{
public:
 Horners(int d) : degree(d){;};
  ULL operator()(std::string str)
  {
    ULL i, ans;
    for(i=ans=0; i<str.size(); i++)
      {ans = ans*degree + str[i];}
    return ans;
  }
 private:
  int degree;
};


class Ascii
{
 public:
  Ascii(){;};
  ULL operator()(std::string str)
  {
    ULL i, ans;
    for(i=ans=0; i<str.size(); i++)
      {ans += str[i];}
    return ans;
  }
};

class MyTry //Really just a specialized Horner
{
 public:
  MyTry(){;};
  ULL operator()(std::string str)
  {
    int letters = 26; //in the alphabet
    ULL i, ans;
    for(i=ans=0; i<str.size(); i++)
      {ans = ans*(letters+1) + str[i] - 'a' + 1;}
    return ans;
  }
};

