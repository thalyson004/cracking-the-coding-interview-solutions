/*
   Question: Is Unique: Implement an algorithm to determine
      if a string has all unique characters. What if you cannot
      use additional data structures?
*/

#include <iostream>

bool has_repetition(const std::string &s){
   //If charset is ASCII 1<<7
   //If charset is Extended ASCII 1<<8
   bool occurrence[1<<8] = {};
   for(char letter:s){
      if( occurrence[letter] ) return true;
      occurrence[letter] = true;
   }
   return false;

   /*
      Assume S is the size of the input string and C is the size of the charset.
      Space complexity: O(max(S,C))
      Time complexity: O(min(S,C))
   */
}

int main(){
   std::cout << has_repetition("thalyson") << std::endl;
   std::cout << has_repetition("thaloson") << std::endl;
}
