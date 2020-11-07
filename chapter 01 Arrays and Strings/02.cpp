/*
   Question: Check Permutation: Given two strings,
   write a method to decide if one is a permutation of the other.
*/

#include <iostream>

bool is_permutation(const std::string &A, const std::string &B){
   if(A.size()!=B.size())return false;
   //If charset is ASCII 1<<7
   //If charset is Extended ASCII 1<<8
   int occurrence[1<<8] = {};
   for(char letter:A) occurrence[letter]++;
   for(char letter:B){
      occurrence[letter]--;
      if(occurrence[letter]<0){
         return false;
      }
   }
   return true;

   /*
      Assume S is the size of the longest input string
      and C is the size of the charset.

      Space complexity: O(max(S,C))
      Time complexity: O(min(S,C))
   */
}

int main(){
   std::cout << is_permutation("thalyson", "nsothlya") << std::endl;
   std::cout << is_permutation("thayson", "sothlya") << std::endl;
   std::cout << is_permutation("thaloson", "thalyson") << std::endl;
}
