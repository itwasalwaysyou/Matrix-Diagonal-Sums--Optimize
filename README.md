# Matrix-Diagonal-Sums--Optimize
A problem that occasionally arises in numerical computing when working with Matrices (2D Arrays) is to compute the sums of the Diagonals of a matrix.

The purpose of this problem is to write sumdiag_OPTM() which is a faster version of the provided sumdiag_BASE() to calculate the sums of diagonals.several optimizations must be implemented and suggestions are given in a later section


My optimizations: 

        Optimization 1: 
        
        there is a an outer loop along with a first and second nested loop both doing a 
        similar activity
        
        The first nested loop is unrolled by 5 times; if the number of rows in the matrix 
        is not divisible by 5, the second loop will 'clean up' by processing the last few 
        remaining elements
        
        This should make run faster because which adjusted memory access pattern and
         each loop iteration has more independent arithmetic operations that can be 
         executed; this favors efficient execution in pipelined / superscalar processors

        Optimization 2: 
        
        Using Macros instead of function
        
        This should make run faster because Macro versions
   	perform better as they force inlining of the function body enabling
    	further optimizations by the compiler.

        Optimization 3: 
        
        matrix_t mat_copy = *mat;
 	      vector_t sums = *vec;

        Using local copies of the struct
        This should make run faster because some data being cached in registers 
        rather than main memory


