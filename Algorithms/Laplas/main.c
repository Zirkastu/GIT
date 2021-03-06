#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f1 (double x);
double f2 (double x);
double f3 (double x);
double f4 (double x);

int main(void)
{
    double A[17][17], d[17][17], b[17][17], db[17][17];
    double xz[17], r[17], xzp[17];
    double h=0.2;
    int i=0, j=0;

    for(i=0; i<17; i++)
    {
        for(j=0; j<17; j++)
        {
            if(i==j)
            {
               A[i][j]= -1;
            }
            else
            {
                A[i][j]= 0;
            }
        }
    }

    A[1][2] = 1./4; A[4][8] = 1./4; A[7][8] = 1./4; A[9][13] = 1./4; A[11][12] = 1./4; A[14][10] = 1./4;
    A[1][5] = 1./4; A[5][1] = 1./4; A[7][6] = 1./4; A[9][10] = 1./4; A[11][10] = 1./4; A[14][15] = 1./4;
    A[2][1] = 1./4; A[5][6] = 1./4; A[7][3] = 1./4; A[9][5] = 1./4; A[11][15] = 1./4; A[14][13] = 1./4;
    A[2][3] = 1./4; A[5][9] = 1./4; A[7][11] = 1./4; A[10][9] = 1./4; A[12][16] = 1./4; A[15][14] = 1./4;
    A[2][6] = 1./4; A[6][2] = 1./4; A[7][6] = 1./4; A[10][11] = 1./4; A[12][11] = 1./4; A[15][16] = 1./4;
    A[3][2] = 1./4; A[6][5] = 1./4; A[8][4] = 1./4; A[10][14] = 1./4; A[12][8] = 1./4; A[15][11] = 1./4;
    A[3][4] = 1./4; A[6][10] = 1./4; A[8][12] = 1./4; A[10][6] = 1./4; A[13][9] = 1./4; A[16][15] = 1./4;
    A[3][7] = 1./4; A[6][7] = 1./4; A[8][7] = 1./4; A[11][7] = 1./4; A[13][14] = 1./4; A[16][12] = 1./4;

    for(i=0; i<17; i++)
    {
        r[i]=0;
    }

    r[1] = 1./4*(f4(h) + f1(h));
    r[2] = 1./4*(f4(2*h));
    r[3] = 1./4*(f4(3*h));
    r[4] = 1./4*(f4(4*h) + f3(h));
    r[5] = 1./4*(f1(2*h));
    r[8] = 1./4*(f3(2*h));
    r[9] = 1./4*(f1(3*h));
    r[12] = 1./4*(f3(3*h));
    r[13] = 1./4*(f1(4*h) + f2(h));
    r[14] = 1./4*(f2(2*h));
    r[15] = 1./4*(f2(3*h));
    r[16] = 1./4*(f3(4*h) + f2(4*h));

    for(i=1; i<17; i++)
    {
        for(j=1; j<17; j++)
        {
            if (i==j)
            {
                d[i][j] = 1./A[i][j];
                b[i][j] = 0;
                db[i][j] = 0;
            }

            else
            {
                d[i][j] = 0;
                b[i][j] = A[i][j];
                db[i][j] = 0;
            }
        }
    }

    int k=0;
    double s=0;
    double eps=0.0001;
    double s1=100;
    for(i=1; i<17;i++)
    {
        for(j=1; j<17; j++)
        {
            for(k=1; k<17; k++)
            {
                db[i][j]= db[i][j]+d[i][k]*b[k][j];
            }
        }
    }

    while(s1 > eps)
    {

     for( i=1; i<17; i++)
     {
        for(j=1; j<17; j++)
        {
          xz[i]=xz[i]-db[i][j]*xzp[j]+d[i][j]*r[j];
        }
        s=s+(xz[i]-xzp[i])*(xz[i]-xzp[i]);
        xzp[i]=xz[i];
        xz[i]=0;
     }
     s1=s;
     s=0;

    }

    for (i=1; i<17; i++)
    {
       printf("%e\n",xzp[i]);
    }



    return 0;
}

double f1 (double x)
{
    return 30*(1-x);
}

double f2 (double x)
{
    return 20*pow(x,1./2);
}

double f3 (double x)
{
    return 20*x;
}

double f4 (double x)
{
    return 30*(1-x);
}