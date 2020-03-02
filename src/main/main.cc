#include "src/lib/solution.h"
#include <iostream>


int main() {
  std::map<int, std::set<int>> vertices{
  {0, {1, 2, 5}},
  {1, {0, 2, 3}},
  {2, {0, 1, 3}},
  {3, {1, 2, 4, 6}},
  {4, {3}},
  {5, {0}},
  {6, {3}}
  };
  Graph g(vertices);
  int root = 0;
  int n = vertices.size();
  std::vector<bool> visited(n,false);
  std::vector<int> result = g.dfsNonrecursive(root,visited);
  g.print(result);


  std::map<int, std::set<int>> vertices1{
  {0, {1}},
  {1, {2, 3}},
  {2, {0}},
  {3, {2, 4, 6}},
  {4, {}},
  {5, {6}},
  {6, {}},
  };
  Graph g1(vertices1);
  std::vector<int> result1 =g1.DFS_ALL();
  g.print(result1);

  Solution solution;
  std::vector<std::vector<int>> input = {{1, 1, 0, 0, 0},
                                         {1, 1, 1, 1, 1},
                                         {0, 1, 0, 0, 1},
                                         {1, 0, 0, 0, 0},
                                         {1, 1, 1, 1, 1}};
  std::pair<int,int> s(1,2);
  std::pair<int,int> e(4,4);
  std::cout << solution.maze(input, s, e) << std::endl;
  for(auto it = input.begin(); it != input.end(); ++it){
    std::vector<int> n = *it;
    for(auto it1 = n.begin(); it1 != n.end(); ++it1){
      int n1 = *it1;
      std::cout<< n1<< " ";
    }
    std::cout <<  std::endl;
  }

  std::vector<std::vector<int>> input1 = {{1, 1, 0, 0, 0},
                                          {1, 0, 1, 1, 1},
                                          {1, 1, 0, 0, 1},
                                          {1, 1, 0, 0, 1},
                                          {1, 1, 1, 1, 1}};
  std::pair<int,int> s1(0,0);
  std::pair<int,int> e1(4,4);
  std::cout << solution.maze(input1, s1, e1) << std::endl;
  for(auto it = input1.begin(); it != input1.end(); ++it){
    std::vector<int> n = *it;
    for(auto it1 = n.begin(); it1 != n.end(); ++it1){
      int n1 = *it1;
      std::cout<< n1<< " ";
    }
    std::cout <<  std::endl;
  }

  std::vector<int> v = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
  solution.quicksort(v,9);

  for(int i=0;i< v.size();i++){
    std::cout<< v[i]<<" ";
  }
  std::cout << std::endl;
}
