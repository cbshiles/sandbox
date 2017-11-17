//C++ is hard man!


template <typename T> 
struct EdgeNode
{
EdgeNode(EdgeNode<T> *n) : next(n) {} 
EdgeNode(T x, EdgeNode<T> *n) : dest_id(x), next(n) {} 
  T dest_id; //destination ID
  EdgeNode<T>* next;
};

template <typename T>  
struct Vertex
{
Vertex() : exists(false), in(0), out(0),
    edgeList(new EdgeNode<T>(0)) {}

  bool exists, visited;

  T id;
  int in, out;

  //For sorting purposes
  int tmp_in; 
  bool sorted;

  EdgeNode<T> *edgeList;

  bool set(T val) 
  {
    if (exists) 
      return id==val;
    //Returns true if this vertex is already set here, false if its another value
    else { //If empty, set 'er up
    exists=true; 
    visited = false; 
    id=val;
    return true;
    }
  }

  void sortPrep()
  {
    tmp_in = in;
    sorted = false;
  }
};

template <typename T> 
class Graph
{
 public:
  Graph(int edges);
  Vertex<T>* find (T val);
  std::vector<Vertex<T> > verticies;
  void addEdge(T a, T b);
  void topSort();
 private:
  std::hash<T> hasher;
};


