// #include <iostream>
// #include <sstream>
// #include <string>

// using namespace std;

// int main() {
//   string str = "0";
//   stringstream ss;
//   ss << str;
//   char c;
//   ss >> c;
//   cout << c << endl;
//   // float f = nanf("");
//   // // if (f == 0) return 0;
//   // if (f == static_cast<char>(f)) cout << "is tru!!!\n";
//   // cout << f << "f";
//   // if (f > INT_MAX || f < INT_MIN) cout << "hi\n";
//   // int i = static_cast<int>(f);
//   // cout << f << "\n" << i << endl;
// }

#include <iostream>
#include <limits>

int main() {
  std::cout << "Maximum int: " << std::numeric_limits<int>::max() << std::endl;
  std::cout << "Minimum int: " << std::numeric_limits<int>::min() << std::endl;
  std::cout << "Maximum double: " << std::numeric_limits<double>::max() * 2
            << std::endl;
  std::cout << "Minimum double: "
            << static_cast<int>(std::numeric_limits<double>::min())
            << std::endl;

  return 0;
}
