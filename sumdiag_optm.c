// optimized versions of matrix diagonal summing
#include "matvec.h"

// You can write several different versions of your optimized function
// in this file and call one of them in the last function.

int sumdiag_VER1(matrix_t *mat, vector_t *vec) {
  
  
  matrix_t mat_copy = *mat;
  vector_t sums = *vec;


  if(sums.len != (mat_copy.rows + mat_copy.cols -1)){
    printf("sumdiag_base: bad sizes\n");
    return 1;
  }
  
  for(int i=0; i<sums.len; i++){                     // initialize vector of diagonal sums
    VSET(sums,i,0);                                  // to all 0s
  }
  
  
  int maxdiag = (mat_copy.rows+mat_copy.cols)-1; 
    

  int col; 
  for(int row=0; row< mat_copy.rows; row++){
 	for(col=0; col<mat_copy.cols-5;col+=5){
  		int d= maxdiag-mat_copy.cols+col-row;
  		int curr_0= MGET(mat_copy,row,col);                    // matrix element
      		int curr_sum0 = VGET(sums,d+0);                         // diagonal sum from vector
      		VSET(sums, d+0, curr_0+curr_sum0); 
      		

  		int curr_1= MGET(mat_copy,row,col+1);                    // matrix element
      		int curr_sum1 = VGET(sums,d+1);                         // diagonal sum from vector
      		VSET(sums, d+1, curr_1+curr_sum1); 
      		
      		int curr_2= MGET(mat_copy,row,col+2);                    // matrix element
      		int curr_sum2 = VGET(sums,d+2);                         // diagonal sum from vector
      		VSET(sums, d+2, curr_2+curr_sum2); 
      		
      		int curr_3= MGET(mat_copy,row,col+3);                    // matrix element
      		int curr_sum3 = VGET(sums,d+3);                         // diagonal sum from vector
      		VSET(sums, d+3, curr_3+curr_sum3); 
      		
      		
      		int curr_4= MGET(mat_copy,row,col+4);                    // matrix element
      		int curr_sum4 = VGET(sums,d+4);                         // diagonal sum from vector
      		VSET(sums, d+4, curr_4+curr_sum4); 
      		
      		
  	}
  	
  	for(;col<mat_copy.cols;col++){
  	
  		int d= maxdiag-mat_copy.cols+col-row;
  		int curr_0= MGET(mat_copy,row,col);                    // matrix element
      		int curr_sum0 = VGET(sums,d+0);                         // diagonal sum from vector
      		VSET(sums, d+0, curr_0+curr_sum0); 
      		
  	}
  
  }
  



   return 0;
}

int sumdiag_VER2(matrix_t *mat, vector_t *vec) {
  matrix_t mat_copy = *mat;
  vector_t sums = *vec;
  
  
  if(sums.len != (mat_copy.rows + mat_copy.cols -1)){
    printf("sumdiag_base: bad sizes\n");
    return 1;
  }
  
  for(int i=0; i<sums.len; i++){                     // initialize vector of diagonal sums
    VSET(sums,i,0);                                  // to all 0s
  }


  for(int d=0; d < mat_copy.rows; d++){                  // iterate over lower diagonals
    int c = 0;                                       // col always starts at 0 in lower diags
    for(int r=mat_copy.rows-d-1; r<mat_copy.rows; r++,c++){  // work down rows, right cols for same diag
      int curr = MGET(mat_copy,r,c);                   // get matrix element on diagonal
      int curr_sum = VGET(sums,d);                      // retrieve current sum for diag
      VSET(sums, d, curr+curr_sum);                     // add on back to the diagonal sum
    }
  }

  int maxdiag = (mat_copy.rows+mat_copy.cols)-1; 
  for(int d=mat_copy.rows; d < maxdiag ; d++){           // iterate starting at first upper diag
    int r = 0;                                       // row always starts at 0 in upper diags
    for(int c=d-mat_copy.cols+1; c<mat_copy.cols; r++,c++){  // work down rows, right cols for same diag
      int curr = MGET(mat_copy,r,c);                    // matrix element
      int curr_sum = VGET(sums,d);                         // diagonal sum from vector
      VSET(sums, d, curr+curr_sum);                     // add on to sum
    }
  }
  return 0;
}

int sumdiag_OPTM(matrix_t *mat, vector_t *vec) {
  // call your preferred version of the function
  return sumdiag_VER1(mat, vec);
}
