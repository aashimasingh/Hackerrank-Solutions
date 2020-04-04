#include <iostream>
#include <string>

bool checkReplacement( std::string s1, std::string s2) {
  int count = 0;
  for (int i = 0; i < s1.length(); i++) {
    if (s1.at(i) != s2.at(i)) {
      count++;
      if (count > 1)
        return false;
    }
  }
  return true;
}

bool checkInsert( std::string s1, std::string s2 ) {
  int i1 = 0, i2 = 0;
  while ( i1 < s1.length() && i2 < s2.length() ) {
    if (s1.at(i1) != s2.at(i2)) {
      if (i1 != i2) 
        return false;
      i2++;
    }
    else {
      i1++;
      i2++;
    }
  }
  return true;
}

bool oneEditAway(std::string s1, std::string s2) {
  if (s1.length() == s2.length())
    return checkReplacement(s1, s2);
  else if (s1.length() == s2.length() - 1)
    return checkInsert(s1, s2);
  else if (s1.length() == s2.length() + 1)
    return checkInsert(s2, s1);
  return false;
}

int main() {

std::string s1 = "aple";
std::string s2 = "abble";

bool result = oneEditAway(s1, s2);
std::cout << result;

}



