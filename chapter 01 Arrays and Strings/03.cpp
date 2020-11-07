/*
   Question: Write a method to replace all spaces in a string with '%20'.
   You may assume that the string has sufficient space at the end to hold
   the additional characters, and that you are given the "true" length of
   the string. (Note: If implementing in Java, please use a character array
   so that you can perform this operation in place.)
*/

#include <iostream>

std::string urlify(std::string &A, const int length){
   std::string response = "";
   int space=0;
   for(int i = 0; i < length; i++){
      char letter = A[i];
      if(letter==' '){
         response.push_back('%');
         response.push_back('2');
         response.push_back('0');
      }else{
         response.push_back(letter);
      }
   }
   A = response;
   /*
      Assume S is the size of the input string
      and C is the size of the final string.

      Space complexity: O(C)
      Time complexity: O(C)

      std::string push_back() is O(1)
   */
}

int main(){
   std::string response = "Mr John Smith ";
   urlify(response, 13);

   std::cout << response << std::endl;

}
