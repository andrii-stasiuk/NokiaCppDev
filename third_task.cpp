// Tricoloring an array of integers
// Not my solution. I translated one guy's solution from PHP to C++
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

bool recurse(vector < int > & arr, string & result, int division, char color, int sum, int i) {
  if (sum == division) {
    // We got the right sum for one color. 
    // If this was the second color, we have a solution
    if (color == 'B') return true;
    // If this was the first color (G), then now assign the second (B).
    // Don't assign Blue before the first Green, as that would be just
    // an inversion of colors. Our solution will have R before the first
    // G, and G before the first B.
    int first = result.find("G");
    return recurse(arr, result, division, 'B', 0, first + 1);
  }
  if (i >= arr.size()) return false; // failed to match the division
  // First, try without coloring this value:
  bool success = recurse(arr, result, division, color, sum, i + 1);
  if (success) return true;
  // Secondly, try coloring this value, if it was not yet colored (Red is default):
  if (result[i] == 'R') {
    result[i] = color;
    success = recurse(arr, result, division, color, sum + arr[i], i + 1);
    if (success) return true;
    result[i] = 'R'; // Set back to default color
  }
  // No luck. Racktrack
  return false;
}

int main() {
  vector<int> arr = { 3, 7, 2, 5, 4 }; 
  //vector<int> arr = { 4, 6, 9 }; 		
  int sum = accumulate(arr.begin(), arr.end(), 0);;
  if ((sum % 3) != 0) {
    cout << "impossible"; // no need to look further
    return 0;
  }
  int division = sum / 3;
  // Initialise the solution array with only Red values
  string result(arr.size(), 'R'); // Fill with default color (i.e. "R");
  // Recurse to assign Green to some values, and after that: Blue to some other values, but let the first value stay assigned to Red (as it could be any).
  bool success = recurse(arr, result, division, 'G', 0, 1);
  if (success) {
    cout << result; // no need to look further
    return 1;
  } else {
    cout << "impossible";
    return 0;
  }
}
