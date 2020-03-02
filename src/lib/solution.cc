#include "solution.h"
#include <iostream>
#include <stack>



std::vector<int> Graph::dfsNonrecursive(int root, std::vector<bool>& visited){
  std::stack<int> stack;
  stack.push(root);
  visited[root]= true;
  std::vector<int> result ;
  while(!stack.empty()){
    int i = stack.top(); 
    stack.pop();
    result.push_back(i);
    for(int j: v_[i]){
      if(!visited[j]){
        visited[j] = true;
        stack.push(j) ;
      }
    }
  }
  return result;
}

std::vector<int> Graph::DFS_ALL(){
  int root = v_.begin()->first;
  int n = v_.size();
  std::vector<bool> visited(n,false);
  std::vector<int> result = dfsNonrecursive(root,visited);
  
  for(auto it = v_.begin(); it != v_.end(); ++it){
    std::vector<int>::iterator it1 = find(result.begin(), result.end(), it->first);
    if(it1 == result.end()){
      std::vector<int> temp = dfsNonrecursive(it->first,visited);
      result.insert(result.end(), temp.begin(), temp.end());
    }
  }
  
  return result;
}

void Graph::print(std::vector<int> &result){
  for (auto it = result.begin(); it != result.end(); ++it) {
    int n = *it;
    std::cout << n << " ";
  }
  std::cout<<std::endl;
}

bool Solution::maze(std::vector<std::vector<int>>& input, std::pair<int,int> s, std::pair<int,int> e){
  input[e.first][e.second] = 2;
  if(e.second<input.size()){
    if(e.first>=0 && e.second>=0 && e.first<input[0].size()){
      if(input[e.first][e.second-1] == 1 && e.second-1 >= 0){
        if (e.first == s.first && e.second-1 == s.second){
          input[e.first][e.second-1] = 3;
        }else{
          e.second -= 1;
          input[e.first][e.second] = 2;
          maze(input, s, e);
        }
      }
  }
    if(e.first+1 < input[0].size()){
      if(input[e.first+1][e.second] == 1 ) {
        if (e.first+1 == s.first && e.second == s.second){
          input[e.first+1][e.second] = 3;
        }else{
          e.first += 1;
          input[e.first][e.second] = 2;
          maze(input, s, e);
        }
      }
    }
    if(e.first-1 >= 0){
      if(input[e.first-1][e.second] == 1 ){
        if (e.first-1 == s.first && s.second == e.second){
          input[e.first-1][e.second] = 3;
        }else{
          e.first -= 1;
          input[e.first][e.second] = 2;
          maze(input, s, e);
        }
      }
    }
    if(e.second+1 < input.size()){
      if (input[e.first][e.second+1] == 1 ){
        if(e.first == s.first && e.second+1 == s.second){
          input[e.first][e.second+1] = 3;
        }else{
          e.second += 1;
          input[e.first][e.second] = 2;
          maze(input, s, e);
        }
      }
    }
    if (input[e.first][e.second+1] == 1 ){
       if(e.first == s.first && e.second+1 == s.second){
        input[e.first][e.second+1] = 3;
      }else{
        e.second += 1;
        input[e.first][e.second] = 2;
        maze(input, s, e);
      }
    }
    
    
  }
  if(input[s.first][s.second] == 3){
    return true;
  }else{
    return false;
  }
}

int Solution::partition(std::vector<int> &arr, int low, int high,int i){
  // std::swap(arr[i], arr[high]);
  int pivot = arr[i];
  int n = low - 1;
  for(int j=low;j<high;j++){
    if(pivot>arr[j]){
      n++;
      std::swap(arr[n], arr[j]);
    }
  }
  std::swap(arr[n+1], arr[i]);
  return n+1;
}

void Solution::quicksort(std::vector<int> &v,int i){
  partition(v, 0, v.size()-1, i);
}