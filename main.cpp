#include "Graph.hpp"

using namespace std;

int main() {
  Graph G(10);
  G.addEdge(0,9);
  G.addEdge(4, 2);
  G.addEdge(2,9);

  G.print();

  cout << "Edge Count Is: "<< G.numEdges() << endl;

  cout << "In-Degree Count of 9 Is: "<< G.inDegree(9) << endl;

  cout << "Is 9 influencer?: " << G.isInfluencer(9) << endl;

  G.addEdge(5, 2);
  G.addEdge(6, 2);
  G.addEdge(7, 2);

  cout << "Is 9 influencer?: " << G.isInfluencer(9) << endl;

  cout << "Is 2 influencer?: " << G.isInfluencer(2) << endl;

  cout << "Edge Count Is: "<< G.numEdges() << endl;

  cout << "In-Degree Count of 2 Is: "<< G.inDegree(2) << endl;

}
