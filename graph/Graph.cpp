#include "Graph.h"

template <typename T>
//Max # of Vertices is Edges*2
Graph<T>::Graph(int edges) : verticies(2*edges) {}

template <typename T>
void Graph<T>::addEdge(T a, T b)
{
      Vertex<T> *from = find(a);
      Vertex<T> *to = find(b);

      from->out++;
      to->in++;

      from->edgeList = new EdgeNode<T>(b, from->edgeList);
}

template <typename T>
Vertex<T>* Graph<T>::find (T val)
{
  int size = verticies.size();
  int i = hasher(val)%size;

  while (! verticies[i].set(val))
    {//Will cause infinite loop if not enough bins
      i = (i+1)%size;
    }
  return &verticies[i];
}

template <typename T>
void Graph<T>::topSort()
{
  std::vector<Vertex<T>* > lzt;

  for (Vertex<T>& v : verticies)
    {
      if (v.exists) 
	{
	  v.sortPrep();
	  lzt.push_back(&v);
	}
    }

  //have the unsorted list of existing vertices
  //need to sort them now

  /*
  while (prunes)
    {
      for (Vertex<T>& v : graph.verticies)
	{
	  if (v.exists)
*/

}
