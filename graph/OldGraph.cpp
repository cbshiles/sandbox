#include "Graph.h"

template <typename T>
Vertex<T>::Vertex(T x) : id(x), visited(false) {}

template <typename T>
void Vertex<T>::addEdge(Vertex *v)
{
  moves.push_back(Edge(v));
}

template <typename T>
bool Vertex<T>::findCycle()
{  std::cout << "fcyc"  << id << ":"  << moves.size()  << std::endl;
  if (visited) return true;
  visited = true;
  std::cout << "c" << std::endl;
  int i;
  for (i=0; i<moves.size(); i++)
    {
      if (moves[i].dest->findCycle())
	return true;
    }
  return false;
}

template <typename T>
struct Vertex<T>::Edge {
  //This struct is to make it easy to change this to a a weighted graph

  Edge(Vertex<T> *v) : dest(v){}
  Vertex<T> *dest; //destination
};

template <typename T>
Vertex<T>* Graph<T>::find (T val)
{std::cout << "find " << val << std::endl;
  int i;
  for (i=0; i<verticies.size(); i++)
    {
      if (verticies[i].id == val)
	return &(verticies[i]);
    }
  Vertex<T> *newV = new Vertex<T>(val);
  verticies.push_back(*new Vertex<T>(val));
std::cout << "not found: " << verticies.back().id  << std::endl;
 Vertex<T>* zz = &(verticies.back());
 std::cout << "zz: " << &(verticies.back())  << std::endl;
  return &(verticies.back());
}

template <typename T>
void Graph<T>::reset()
{
  int i;
  for (i=0; i<verticies.size(); i++)
    {
      verticies[i].visited = false;
    }
}

template <typename T>
bool Graph<T>::hasCycle()
{
  std::cout << "a" << std::endl;
  int i;
  for (i=0; i<verticies.size(); i++)
    {
      std::cout << "outer darkness" << verticies[i].id << std::endl;
      if(verticies[i].findCycle()) return true;
      reset();
    }
  std::cout << "z" << std::endl;
  return false;
}
