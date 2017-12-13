#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LUsolve(double *A, double *b, double *x, double *c, int n) {
     int i, j, k;
     double dtemp;

     /* LU decomposition ---------------------- */  
     for (k=0; k<n; k++) {
       dtemp = 1.0 / A[k * n + k];
       for (i=k+1; i<n; i++) {
         A[i * n + k] = A[i * n + k]*dtemp;   
       }
       for (j=k+1; j<n; j++) {
         dtemp = A[j * n + k];
         for (i=k+1; i<n; i++) {
           A[j * n + i] = A[j * n + i] - A[k* n + i]*dtemp; 
         }
       }
     }
     /* --------------------------------------- */


     /* Forward substitution ------------------ */  
     for (k=0; k<n; k++) {
       c[k] = b[k];
       for (j=0; j<k; j++) {
         c[k] -= A[k * n + j]*c[j];
       }
     }
     /* --------------------------------------- */


     /* Backward substitution ------------------ */  
     x[n-1] = c[n-1]/A[(n-1) * n + (n-1)];
     for (k=n-2; k>=0; k--) {
       x[k] = c[k];
       for (j=k+1; j<n; j++) {
         x[k] -= A[k * n + j]*x[j];
       }
       x[k] = x[k] / A[k * n + k];
     }
     /* --------------------------------------- */
}

int main(int argc, char* argv[]) {
     const int N = 192;
     int i, j, ii;

     double *A = malloc(sizeof(double) * N * N);
     double *b = malloc(sizeof(double) * N);
     double *x = malloc(sizeof(double) * N);
     double *c = malloc(sizeof(double) * N);

     /*
     memset(A, 0, sizeof(double) * N * N);
     memset(b, 0, sizeof(double) * N);
     memset(x, 0, sizeof(double) * N);
     memset(c, 0, sizeof(double) * N);
     */

     // matrix generation
     for(j=0; j<N; j++) {
       ii = 0;
       for(i=j; i<N; i++) {
	 A[j * N + i] = (N-j) - ii;
	 A[i * N + j] = A[j * N + i];
	 ii++;
       }
     }

     // set b
     for (i=0; i<N; i++) {
       b[i] = 0.0;
       for (j=0; j<N; j++) {
         b[i] += A[i * N + j];
       }
     }

     // solve Ax = b using LU decomposition
     LUsolve(A, b, x, c, N);

     // print the answer: x should be (1, 1, 1, ..., 1)
     printf("x: \n");
     for(i=0; i<N; i++) {
       printf("%.5f ", x[i]);
     }
     printf("\n");
}
