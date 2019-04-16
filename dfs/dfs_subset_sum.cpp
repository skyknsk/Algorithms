/*
    Subset Sum Problem
*/

#include <iostream>
#include <utility>
#include <vector>

class DFS {
  private:
    int n_;
    int ssum_;
    std::vector<int> data_;

  public:
    DFS(int n, int ssum, std::vector<int> input)
      : n_{n},
        ssum_{ssum},
        data_{std::move(input)}
      {}
    ~DFS() {}
    
    void SubsetSum();

  private:
    bool DfsSubsetSum(int i, int sum);
};

void DFS::SubsetSum() {
  if(DfsSubsetSum(0, 0))
    std::cout << "Yes\n";
  else
    std::cout << "No\n";
}

bool DFS::DfsSubsetSum(int i, int sum) {
  if(i == n_)
    return sum == ssum_;
  if(DfsSubsetSum(i + 1, sum))
    return true;
  if(DfsSubsetSum(i + 1, sum + data_[i]))
    return true;

  return false;
}

int main() {
  int n;     // input size
  std::cout << "n (input size) = ";
  std:: cin >> n;

  std::vector<int> input(n);    // input data
  std::cout << "input(n) = ";
  for(int i=0; i<n; ++i) {
    std::cin >> input[i];
  }

  int ssum;     //  subset sum
  std::cout << "ssum (subset sum) = ";
  std::cin  >> ssum;

  DFS dfs(n, ssum, std::move(input));
  dfs.SubsetSum();

  return 0;
}
