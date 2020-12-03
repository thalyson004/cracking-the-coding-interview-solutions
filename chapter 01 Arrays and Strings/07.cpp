/*
   Question: Rotate Matrix: Given an image represented by an NxN matrix,
   where each pixel in the image is 4 bytes, write a method to rotate the
   image by 90 degrees. Can you do this in place?

   For this question, my approach just reverses each row of the image.

   Each reversation costs O(N). Then, the total complexity is O(N*N) in time.
   PS: I can improve the complexity of space into O(1), using two points approach
   for the reversation of each row.

   The complexity of space is just O(N) (for the function). Because this
   approach stores only one row per the time.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void flip_image(std::vector<std::vector<int>> &image){
   for(std::vector<int> &row:image){
      std::reverse(row.begin(), row.end());
   }
}

int main(){
   std::vector<std::vector<int>> image;
   image.push_back( {0,0,0,1,1} );
   image.push_back( {0,0,0,1,0} );
   image.push_back( {0,0,1,1,0} );
   image.push_back( {0,1,1,1,0} );
   image.push_back( {1,1,1,1,1} );
   flip_image(image);
   for(std::vector<int> &row : image){
      for(int pixel : row) printf("%d,", pixel);
      printf("\n");
   }
}
