/*
   Question: One Away: There are three types of edits that can be performed
   on strings: insert a character, remove a character, or replace a character.
   Given two strings, write a function to check if they are one edit
   (or zero edits) away.

   EXAMPLE
   pale, ple -> true
   pales, pale -> true
   pale, bale -> true
   pale, bake -> false
*/

#include <iostream>

bool one_insert(std::string A, std::string B){
   if(A.size()>B.size()) swap(A,B);
   if(A.size()+1!=B.size()) return false;

   bool inserted = false;
   int i = 0, j = 0;
   while(j<B.size()){
      if(B[j]==A[i]){
         i++;
         j++;
      }else{
         if(inserted)return false;
         inserted = true;
         j++;
      }
   }
   return true;
}

bool one_replace(std::string A, std::string B){
   if(A.size()>B.size()) swap(A,B);
   if(B.size()!=A.size()) return false;

   bool replaced = false;
   int i = 0, j = 0;
   while(j<B.size()){
      if(B[j]==A[i]){
         i++;
         j++;
      }else{
         if(replaced)return false;
         replaced = true;
         i++;
         j++;
      }
   }
   return true;
}


bool one_away(std::string A, std::string B){
   if(A==B) return true;
   if( one_insert(A,B) ) return true;
   if( one_replace(A,B) ) return true;
   return false;
   /*
      If those strings are equal, need no operations.
      For insert operation, i will try insert into smallest string.
      For remove operation, i will try remove from the biggest string.

      Space complexity: O(|A|+|B|)
      Time complexity: O(|A|+|B|)

      PS: The book used a reference to pass the strings. Then the final
      complexity is min(|A|, |B|). But my approach use copy, then it
      will use O(|A|+|B|) for just pass the strings.
   */
}

int main(){
   std::cout << one_away("pale","ple") << std::endl;
   std::cout << one_away("pales","pale") << std::endl;
   std::cout << one_away("pale","bale") << std::endl;
   std::cout << one_away("pale","bake") << std::endl;

}
