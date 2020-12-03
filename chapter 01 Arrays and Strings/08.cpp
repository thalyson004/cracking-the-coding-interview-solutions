/*
   Question: Zero Matrix: Write an algorithm such that if an element in
   an MxN matrix is 0, its entire row and column are set to 0.

   My approach uses two boolean vectors as helpers.
   One vector represents occurrence of zero on each row.
   One vector represents occurrence of zero on each column.
   Iterate though the image and set those vectors.
   Iterate though the image using those vectors the change the image.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void zero_matrix(std::vector<std::vector<int>> &image){

   int N = image.size();
   int M = image[0].size();
   std::vector<bool> rows(N);
   std::vector<bool> cols(M);

   for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
         rows[i] = rows[i] or (image[i][j]==0);
         cols[j] = cols[j] or (image[i][j]==0);
      }
   }
   for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
         if( rows[i] or cols[j] ){
            image[i][j] = 0;
         }
      }
   }

}

int main(){
   std::vector<std::vector<int>> image;
   image.push_back( {1,1,1,0,1} );
   image.push_back( {1,1,1,1,1} );
   image.push_back( {1,0,1,0,1} );
   image.push_back( {1,1,1,1,1} );
   image.push_back( {1,1,1,1,1} );
   zero_matrix(image);
   for(std::vector<int> &row : image){
      for(int pixel : row) printf("%d,", pixel);
      printf("\n");
   }
}
