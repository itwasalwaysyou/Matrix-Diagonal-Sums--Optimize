# Matrix-Diagonal-Sums--Optimize
A problem that occasionally arises in numerical computing when working with Matrices (2D Arrays) is to compute the sums of the Diagonals of a matrix.

The purpose of this problem is to write sumdiag_OPTM() which is a faster version of the provided sumdiag_BASE() to calculate the sums of diagonals.several optimizations must be implemented and suggestions are given in a later section

the space below shows how my performance optimizations improved on the baseline codes.
------ Tuned for csel-remote-lnx-NN machines --------

  SIZE       BASE       OPTM  SPDUP POINTS 
   512 2.8973e-02 3.2750e-03   8.85   0.79 
  1024 5.7083e-02 7.2390e-03   7.89   1.49 
  1101 6.0268e-02 8.2290e-03   7.32   1.54 
  2048 3.1723e-01 3.0798e-02  10.30   3.36 
  4099 1.5179e+00 1.2408e-01  12.23   7.23 
  6001 3.4241e+00 2.6686e-01  12.83  10.79 
  8192 6.6004e+00 4.9582e-01  13.31  14.94 
RAW POINTS: 40.14

