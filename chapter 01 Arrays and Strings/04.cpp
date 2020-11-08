/*
   Question: Palindrome Permutation: Given a string, write a function to
   check if it is a permutation of a palindrome. A palindrome is a word
   or phrase that is the same forwards and backwards. A permutation is a
   rearrangement of letters. The palindrome does not need to be limited
   to just dictionary words.

   EXAMPLE
   Input: Tact Coa
   Output: True (permutations: "taco cat", "atco eta", etc.)
*/

#include <iostream>

bool is_palindrome(std::string A){
   int odd = 0;
   bool quantity[26] = {};

   for(char letter:A){
      if( letter>='A' and letter<='Z') letter += ('a'-'A');

      if( letter>='a' and letter<='z' ){
         int position = letter-'a';
         quantity[position]^=true;
         if( quantity[position] ) odd++;
         else odd--;
      }
   }
   return odd<=1;
   /*
      Assume S is the size of the input string

      This approach counts the number of each letter.
      For check character is letter O(1).
      For transform the character into lower case O(1).
      If the number of odd is less than or equal to 1,
         this string is a palindrome.

      Space complexity: O(S)
      Time complexity: O(S)

   */
}

int main(){

   std::cout << is_palindrome("Tact Coa") << std::endl;

}
