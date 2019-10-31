

void MatrMyltiply(double(*A)[4], double* x, double* Ax , int n)  // Функция умножения квадратной матрицы A на вектор x. 
{
  int i,j;
  for (j=0;j<n;j++)
  {
      Ax[j]=0.0;   
      for (i=0;i<n;i++)
      {
          Ax[j]=Ax[j]+A[j][i]*x[i];  
      }
  }
  
}
