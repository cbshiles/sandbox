#include <iostream>
#include <fstream>
#include <vector>
#include "Graph.cpp"

using namespace std;

/*
In my not so humble opinion, if C++ was
even vaguely readable, it would be an amazing language.
 */

/*
template <typename T>
struct Edge
{
  T to, from;

  Edge(T a, T b): to(a), from(b){}

  void print()
  {
    cout << to << "--" << from << endl;
  }
};
*/
 /*
template <typename T>
Vertex<T>* find (vector<Vertex<T> >& vect, T val)
{
  int i;
  for (i=0; i<vect.size(); i++)
    {
      if (vect[i].id == val)
	return &vect[i];
    }
  vect.push_back(Vertex<T>(val));
  return &(vect.back());
}


template <typename T>
void clear(vector<Vertex<T> >& vect)
{
  int i;
  for (i=0; i<vect.size(); i++)
    {
      vect.visited = false;
    }
}
*/

template <typename T>
void processGraph(const char* fname)
{
  ifstream file (fname);
  int x;
  file >> x;

  T a, b;

  Graph<T> graph;

  while ((file >> a) && (file >> b))
    {
      cout << "len before: " << graph.verticies.size() << endl;
      Vertex<T> *from = graph.find(a);
      Vertex<T> *to = graph.find(b);
      cout << "from address: "  << from << endl;
      cout << to->id << " added to " << from->id << endl;
      from->addEdge(to); //boom shaka laka
      cout << "len after: " << graph.verticies.size() << endl;
    }

  cout << graph.hasCycle() << endl;

  file.close();
}

int main()
{
   processGraph<int>("test.g");
   /*
  Vertex<int> vert (7);
  vector<Vertex<int> > verticies;
  verticies.push_back(vert);
   */
  return 0;
}
