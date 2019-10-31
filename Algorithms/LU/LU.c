void LU(double** a, double** L, double** U, int size)
{
    int i,j,k;
    double s1=0.,s2=0.;
    
    for (j=0;j<size;j++) 
    {
        U[0][j]=a[0][j];
        L[j][0]=a[j][0]/U[0][0];
    }

    for (i=1;i<size;i++)
    {
        
        for (j=i;j<size;j++)
        {
            for (k=0;k<i;k++)
            {
                s1=s1+L[i][k]*U[k][j];
                s2=s2+L[j][k]*U[k][i];
            }
            U[i][j]=a[i][j] - s1;
            L[j][i]=(a[j][i]- s2)/U[i][i];
            s1=0.;
            s2=0.;     
        }
    
    }
 } 
