#define size 4
#include "eigenvalues.h"
int main(void)
{
    int i,j,k,n=size;
    double temp;
    double A[size][size];
    double B[size][5]; 
    double y0[size];
    double y1[size];
    double y2[size];
    double y3[size];
    double y4[size];
    double p[5]; //Массив коэффицентов характеристического многочлена
    double x[size];
    double l[size]; //Собственный вектор
    p[0]=1.0;
    //double x0=5.0;
    //
    A[0][0]=1.6;A[0][1]=1.0;A[0][2]=1.4;A[0][3]=1.0;
    A[1][0]=1.0;A[1][1]=1.0;A[1][2]=0.5;A[1][3]=2.0;//Задание массива
    A[2][0]=1.4;A[2][1]=0.5;A[2][2]=2.0;A[2][3]=1.2;
    A[3][0]=1.0;A[3][1]=2.0;A[3][2]=1.2;A[3][3]=0.5;
    // 
    y0[0]=1.0;y0[1]=0.0;y0[2]=2.0;y0[3]=1.0;  //Задание произвольного вектора  
    //
    MatrMyltiply(A, y0, y1 , n); // Вычисление вектора y1
    MatrMyltiply(A, y1, y2 , n); // Вычисление вектора y2 
    MatrMyltiply(A, y2, y3 , n); // Вычисление вектора y3 
    MatrMyltiply(A, y3, y4 , n); //

    for (i=0;i<n;i++)
    {
        B[i][0]=y3[i];
        B[i][1]=y2[i];
        B[i][2]=y1[i];
        B[i][3]=y0[i];
        B[i][4]=y4[i];   
    }
    Gauss(B,n,p); // Вычисление коэффицентов характеристического многочлена
    ROOTS(p , l , n);// Вычисление корней многочлена
    /*
    for (i=0;i<n;i++)
    {
        printf("%f \n",l[i]);
    } 
    */
    y4[0]=1;
    for (i=0;i<n;i++)
    {
        temp=dfunc (l[i],p ,n);
        for (j=1;j<n;j++)
        {
            y4[j]=l[i]*y4[j-1]+p[j];
        }
        printf("----------------\n");
        printf("Собственное число :%f\n",l[i]);
        printf("Собственный вектор :\n");
        for (k=0;k<n;k++)
        {
            x[k]=(y3[k]+y4[1]*y2[k]+y4[2]*y1[k]+y4[3]*y0[k]);
            x[k]=x[k] / temp;
            printf("%f\n",x[k]);            
        }
        CHECK (A,x,l[i],size);
        printf("----------------\n");
   }   
    
   return 0;

}

void CHECK(double(*A)[size],double*x,double l,int n)
{
    double y[size];
    int i; 
    MatrMyltiply(A, x, y , n);
    for (i=0;i<n;i++)
    {
        printf("%f\n",y[i]-l*x[i]);

    } 
}


