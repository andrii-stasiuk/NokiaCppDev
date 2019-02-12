#include <algorithm>
#include <math.h>
#include <vector>

int solution(int A) {
  vector < int > B;
  vector < int > C;

  for (; A > 0; A /= 10) B.push_back(A % 10);
  std::reverse(B.begin(), B.end());

  for (unsigned int i = 0; i < B.size(); i++)
    if (i % 2 == 0) C.push_back(B[i / 2]);
    else C.push_back(B[B.size() - 1 - i / 2]);

  int res = 0;
  reverse(C.begin(), C.end());
  for (unsigned int i = 0; i < C.size(); i++)
    res += C[i] * pow(10, i);

  return res;
}
