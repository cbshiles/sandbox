#include <functional>
#include <vector>
#include <iostream>
#include <fstream>
#include <deque>

#include "Graph.cpp"

using namespace std;

template <typename T>
void processGraph(const char* fname)
{
  ifstream file (fname);
  int x;
  file >> x;
  Graph<T> graph(x);


  T a, b;
  while ((file >> a) && (file >> b))
      graph.addEdge(a, b);

  graph.topSort();

  /* //print tester
  for (Vertex<T>& v : graph.verticies)
    {
      cout << "ID: " << v.id << " In: " << v.in <<
	" Out: " << v.out << endl;

      int i;
      EdgeNode<T> *yow = v.edgeList;
      for (i=0; i<v.out; i++)
	{
	  cout << "To: " << yow->dest_id << endl;
	  yow = yow->next;
	}
    }
  */

  file.close();
}

int main(int argc, char *argv[])
{
  /*
  Command line files assume that the graphs use integers.
  Would it be desirable to have a command line variable 
specifying type?
  */
 
  char* fileName;

  fileName = (argc > 1)?argv[1]:(char *)"test.g";

  //processGraph<int>(fileName);

  processGraph<string>("airports.g");



  /*
  Graph<int> graph(3);
  graph.verticies[1].set(99);
  cout << graph.verticies[1].visited << endl;
  */
  return 0;
}
