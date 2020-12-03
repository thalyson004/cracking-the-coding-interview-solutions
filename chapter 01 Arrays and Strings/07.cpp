/*
   Question: Rotate Matrix: Given an image represented by an NxN matrix,
   where each pixel in the image is 4 bytes, write a method to rotate the
   image by 90 degrees. Can you do this in place?

   For this question, my first approach is just make a new image.
   You can build each row with the reverse order of each column.
   This approach takes O(N^2) time and space.

   I improve the space complexity using  inplace swapping on the second
   approach. For each cell in the first quadrant, find the others three cell
   on the others three quadrants that match with rotate.
   Using this inplace approach, the time complexity remains the same O(N^2),
   but the space complexity reduce to O(1).

*/

#include <iostream>
#include <vector>
#include <algorithm>

void rotate_image(std::vector<std::vector<int>> &image){
   std::vector<std::vector<int>> new_image(image[0].size());

   for(int row = image.size()-1; row>=0; row--){
      for(int col = 0; col < image[0].size(); col++){
         new_image[col].push_back( image[row][col] );
      }
   }

   image = new_image;
}

void rotate_square_image(std::vector<std::vector<int>> &image){
   int row = image.size();

   for(int r = 0; r < (row+1)/2; r++ ){
      for(int c = 0; c < (row)/2; c++ ){
         int &q1 = image[r][c];
         int &q2 = image[c][row-1-r];
         int &q3 = image[row-1-r][row-1-c];
         int &q4 = image[row-1-c][r];

         std::swap(q1,q4);
         std::swap(q4,q3);
         std::swap(q3,q2);
      }
   }
}

int main(){
   std::vector<std::vector<int>> image;
   image.push_back( {0,0,0,1,1} );
   image.push_back( {0,0,0,1,0} );
   image.push_back( {0,0,1,1,0} );
   image.push_back( {0,1,1,1,0} );
   image.push_back( {1,1,1,1,1} );
   rotate_image(image);
   for(std::vector<int> &row : image){
      for(int pixel : row) printf("%d,", pixel);
      printf("\n");
   }
   printf("%s\n", std::string(10, '-').c_str());
   rotate_square_image(image);
   for(std::vector<int> &row : image){
      for(int pixel : row) printf("%d,", pixel);
      printf("\n");
   }
}
