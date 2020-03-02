#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <vector>
#include <algorithm>
#include <map>
#include <set>

class Graph {
public:
Graph(std::map<int, std::set<int>> &vertices) :
v_(vertices) {}
std::map<int, std::set<int>> v_;
std::vector<int> dfsNonrecursive(int root, std::vector<bool>& visited);
std::vector<int> DFS_ALL();
void print(std::vector<int> &result);
};


class Solution {
public:
    bool maze(std::vector<std::vector<int>>& input, std::pair<int,int> s, std::pair<int,int> e);
    void quicksort(std::vector<int> &v,int i);
private:
    int partition(std::vector<int> &arr, int low, int high,int i);
};


#endif