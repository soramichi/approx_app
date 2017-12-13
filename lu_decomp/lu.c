#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 192

double  A[N][N];
double  b[N];
double  x[N];
double  c[N];

void LUsolve(double A[N][N], double b[N], double x[N], int n) 
{
     int i, j, k;
     double dtemp;

     /* LU decomposition ---------------------- */  
     for (k=0; k<n; k++) {
       dtemp = 1.0 / A[k][k];
       for (i=k+1; i<n; i++) {
         A[i][k] = A[i][k]*dtemp;   
       }
       for (j=k+1; j<n; j++) {
         dtemp = A[j][k];
         for (i=k+1; i<n; i++) {
           A[j][i] = A[j][i] - A[k][i]*dtemp; 
         }
       }
     }
     /* --------------------------------------- */


     /* Forward substitution ------------------ */  
     for (k=0; k<n; k++) {
       c[k] = b[k];
       for (j=0; j<k; j++) {
         c[k] -= A[k][j]*c[j];
       }
     }
     /* --------------------------------------- */


     /* Backward substitution ------------------ */  
     x[n-1] = c[n-1]/A[n-1][n-1];
     for (k=n-2; k>=0; k--) {
       x[k] = c[k];
       for (j=k+1; j<n; j++) {
         x[k] -= A[k][j]*x[j];
       }
       x[k] = x[k] / A[k][k];
     }
     /* --------------------------------------- */
}

int main(int argc, char* argv[]) {
     int i, j, ii;

     // matrix generation
     for(j=0; j<N; j++) {
       ii = 0;
       for(i=j; i<N; i++) {
	 A[j][i] = (N-j) - ii;
	 A[i][j] = A[j][i];
	 ii++;
       }
     }

     // set b
     for (i=0; i<N; i++) {
       b[i] = 0.0;
       for (j=0; j<N; j++) {
         b[i] += A[i][j];
       }
     }

     // solve Ax = b using LU decomposition
     LUsolve(A, b, x, N);

     // print the answer: x should be (1, 1, 1, ..., 1)
     printf("x: \n");
     for(i=0; i<N; i++) {
       printf("%.5f ", x[i]);
     }
     printf("\n");
}
