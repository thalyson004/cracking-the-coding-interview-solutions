/*
   Question: String Rotation: Assume you have a method isSubString which
   checks if one word is a substring of another. Given two strings, S1 and S2,
   write code to check if S2 is a rotation of S1 using only one call
   to isSubstring (e.g., "waterbottle" is a rotation of" erbottlewat").

   My observations:
      S1 is rotate of S2 if and only if S2 is rotate of S1.
      Two strings with different lengths never will be rotates.

   My approach:
      Check is |S1|==|S2|
      Try find S1 in S2+S2 (or the opposite way).

*/

#include <iostream>
#include <vector>
#include <algorithm>

bool isSubstring(std::string s1, std::string s2){
   return (s1+s1).find(s2)!=std::string::npos;
}

bool rotate(std::string s1, std::string s2){
   return s1.size() == s2.size() and isSubstring(s1,s2);
}


int main(){
   printf("%s", rotate("waterbottle", "erbottlewat")?"Is substring":"Is not a substring" );
}
