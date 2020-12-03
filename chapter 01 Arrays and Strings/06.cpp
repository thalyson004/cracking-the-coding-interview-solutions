/*
   Question: String Compression: Implement a method to perform basic
   string compression using the counts of repeated characters.

   For example, the string aabcccccaaa would become a2blc5a3. If the
   "compressed" string would not become smaller than the original
   string, your method should return the original string.
   You can assume the string has only uppercase and lowercase letters (a - z).

   Simple approach, just iterate the original string, counting the number of
   consecutive equal characters, and add into a compressed string.

   Only careful about the difference of the complexity of
      S = S + "b" O(N)
      Vs
      S.push_back('b') O(1)

   PS: The book solution uses one iterate to check if the final compressed string
   will become smaller than the original one.
*/

#include <iostream>

void push_compressed(std::string &S, char letter, int amount){
   if(amount==0)return;
   S.push_back(letter);

   std::string number = std::to_string(amount);
   for(char digit:number) S.push_back(digit);
}

std::string compress(std::string S){
   std::string compressed = "";

   char last = '@';
   int amount = 0;
   for(char letter: S){
      if(letter==last){
         amount++;
      }else{
         push_compressed(compressed, last, amount);
         amount = 1;
         last = letter;
      }
   }
   push_compressed(compressed, last, amount);

   return compressed.size()<S.size()?compressed:S;

}

int main(){
   std::cout << compress("aabcccccaaa") << std::endl;
}
