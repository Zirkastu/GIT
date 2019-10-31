!Вычисление собственных значений вещественной матрицы.
program TestLA61
use NML
implicit none
integer, parameter:: n=3
real:: H(n,n), WR(n), WI(n)
integer:: Cnt(n), Er
integer i, j
DO i=1,n
    WR(i)=0
    WI(i)=0
    DO j=1,n
        H(i,j)=0
    END DO
END DO
DO i=1,n-1
 H(i,i+1)=1.*i/SQRT(4.*i*i-1)
 H(i+1,i)=1.*i/SQRT(4.*i*i-1)
END DO  
  call LA61(H, WR, WI, Cnt, Er)
  DO i=1,n
      print*,WR(i)
  END DO

end program TestLA61
