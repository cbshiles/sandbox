#define ULL unsigned long long //Not working with typedef for some reason

template<typename T, typename Functor>
class Hasher
{
 public:
  Hasher(ULL s, Functor f);
  void add(T value);
  bool search(T value);
  void stats();
 private:
  Functor functor;
  ULL size;
  std::vector<std::vector<T> > table;
  ULL hash(T value);
};
