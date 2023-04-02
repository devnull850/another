#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  std::vector<int>::iterator it;

  it = v.insert(it, 23);

  for (it = v.begin(); it < v.end(); ++it) {
    std::cout << *it << std::endl;
  }

  return 0;
}
