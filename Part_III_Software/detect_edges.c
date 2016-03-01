#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <jpeglib.h>

int main(int argc, char * argv[]){
    FILE * input = fopen("binary_lenna.txt","r");
   FILE * output = fopen("c_output.txt","w");
   unsigned char * row1;
   unsigned char * row2;
   unsigned char * row3;
   unsigned char * temp;
   int i,j;
   int row, col; 
   int sumx, sumy;
   int Gx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
   int Gy[3][3] = {{1,2,1},{0,0,0},{-1,-2,-1}};
   char zero = 0;

   unsigned char picture[512][512];
   unsigned char result[512][512];
   unsigned char tmp;

   if(argc != 5){
      printf("usage:\n\t %s input.txt output.txt width height\n\n",argv[0]);
   }
   int width, height;
   width = atoi(argv[3]);
   height = atoi(argv[4]);
   for(i = 0; i < 512; i++){
     // read in picture 1 row at a time
     fread(picture[i],1,512,input);
     // fill top row with 0's
     fwrite(&zero,1,1,output);
   }

   for(row = 1; row < 511; row++){ 
     fwrite(&zero,1,1,output); // first col al 0's
     for(col = 1; col < 511; col++){
       sumx = sumy = 0;
       for(i = -1; i <= 1; i++)
           for(j = -1 ; j <= 1; j++){
             sumx += picture[row+i][col+j] * Gx[i+1][j+1];
             sumy += picture[row+i][col+j] * Gy[i+1][j+1];
           }
       tmp = (abs(sumx)+abs(sumy) ) >> 1 ;
       fwrite(&tmp,1,1,output);
     }
     fwrite(&zero,1,1,output); // last col all 0's
   }
   // last row is all 0's
   for(i=0;i<512;i++)
     fwrite(&zero,1,1,output);
/*
   row1 = malloc(512*sizeof(char));
   row2 = malloc(512*sizeof(char));
   row3 = malloc(512*sizeof(char));

   if(!input || !output){
       printf("error opening a file\n");
       return 1;
   }

   int linesread = 3;
   fread(row1,1,512,input);
   fread(row2,1,512,input);
   fread(row3,1,512,input);
*/
   
   
   


//    printf("Size of image: %d\n",size);


   fclose(input);
   fclose(output);
    return 0;


}


