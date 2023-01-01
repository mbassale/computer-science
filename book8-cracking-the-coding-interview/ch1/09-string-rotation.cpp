#include <chrono>
#include <iostream>
#include <string>

using namespace std;
using namespace std::chrono;

// Time: O(M+N) with M=len(s1), N=len(s2) Space: O(1)
bool isSubstring(const string& s1, const string& s2) {
  return s1.find(s2) != string::npos;
}

/*
Problem: find if s2 is a rotation of s1, using only one call to the method
         isSubstring().

Example #1: accusantium santiumaccu
1) santiumaccu + santiumaccu
2) santiumaccusantiumaccu
3) isSubstring(santiumaccusantiumaccu, accusantium) = true

Example #2: atrocious satrociou
1) satrociou + satrociou
2) satrociousatrociou
3) isSubstring(satrociousatrociou, atrocious) = true

Example #3: example exemplar
1) exemplar + exemplar
2) exemplarexamplar
3) isSubstring(exemplarexemplar, example) = false
*/

// Time: O(M+N) Space: O(N) with M=len(s1), N=len(s2)
bool isRotation(const string& s1, const string& s2) {
  const auto doubleS2 = s2 + s2;
  return isSubstring(doubleS2, s1);
}

void invokeIsRotation(const string& s1, const string& s2) {
  const auto start = high_resolution_clock::now();
  const auto result = isRotation(s1, s2);
  const auto stop = high_resolution_clock::now();
  cout << "isRotation(" << s1 << "," << s2 << ") = " << result
       << " Runtime: " << duration_cast<nanoseconds>(stop - start).count()
       << "ns" << endl;
}

int main(int argc, char* argv[]) {
  invokeIsRotation("accusantium", "santiumaccu");
  invokeIsRotation("atrocious", "satrociou");
  invokeIsRotation("example", "exemplar");
  return EXIT_SUCCESS;
}