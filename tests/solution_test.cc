#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(TestQ3, HandlesTestQ3) {
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
  std::vector<int> actual = g.dfsNonrecursive(root,visited);
  std::vector<int> expected = {0, 5, 2, 3, 6, 4, 1};
  EXPECT_EQ(expected, actual);
}

TEST(TestQ4, HandlesTestQ4) {
  std::map<int, std::set<int>> vertices{
  {0, {1}},
  {1, {2, 3}},
  {2, {0}},
  {3, {2, 4, 6}},
  {4, {}},
  {5, {6}},
  {6, {}},
  };
  Graph g(vertices);
  std::vector<int> actual = g.DFS_ALL();
  std::vector<int> expected = {0, 1, 3, 6, 4, 2, 5};
  EXPECT_EQ(expected, actual);
}

TEST(TestQ5, HandlesTestQ5) {
  Solution solution;
  std::vector<std::vector<int>> input = {{1, 1, 0, 0, 0},
                                         {1, 1, 1, 1, 1},
                                         {0, 1, 0, 0, 1},
                                         {1, 0, 0, 0, 0},
                                         {1, 1, 1, 1, 1}};
  std::pair<int,int> s(1,2);
  std::pair<int,int> e(4,4);
  std::vector<std::vector<int>> input1 = {{1, 1, 0, 0, 0},
                                          {1, 0, 1, 1, 1},
                                          {1, 1, 0, 0, 1},
                                          {1, 1, 0, 0, 1},
                                          {1, 1, 1, 1, 1}};
  std::pair<int,int> s1(0,0);
  std::pair<int,int> e1(4,4);
  EXPECT_EQ(solution.maze(input, s, e), false);
  EXPECT_EQ(solution.maze(input1, s1, e1), true);
}

TEST(TestQ6, HandlesTestQ6) {
  Solution solution;
  std::vector<int> v = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
  solution.quicksort(v,9);
  std::vector<int> expected = {5, 2, 3, 6, 12, 7, 14, 9, 10, 11};
  EXPECT_EQ(v, expected);
}