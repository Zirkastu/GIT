
MODULE MyModule
implicit none 

 contains    



  integer function tqli(n) result(o)
  integer, intent(in):: n
  integer:: m,l,iter,i,k
  real:: s,r,p,g,f,dd,c,b
  real, allocatable :: d(:),e(:)
  !/* удобнее будет перенумеровать элементы e */
  o=0.
  allocate(e(1:n))
  allocate(d(1:n)) 
  DO i=1,n-1
      e(i)=1.*i/SQRT(4.*i*i-1)
      d(i)=0.
  END DO
  e(n)=0.
  d(n)=0.
  e(n)=0.
  !/* главный цикл идет по строкам матрицы */
  DO l=1,n 
    !/* обнуляем счетчик итераций для этой строки */
    iter=0;
    !/* цикл проводится, пока минор 2х2 в левом верхнем углу начиная со строки l
       !не станет диагональным */
      DO 
      !/* найти малый поддиагональный элемент, дабы расщепить матрицу */
          DO m=l,n-1 
              dd=abs(d(m))+abs(d(m+1))
              if (abs(e(m)+dd)-dd<0.0000000001) exit
          END DO
          !/* операции проводятся, если верхний левый угол 2х2 минора еще не диагональный */
          if (m /= l) then
              !/* увеличить счетчик итераций и посмотреть, не слишком ли много. Функция
              !nerror завершает программу с диагностикой ошибки. */
              !if(++iter>=MAXITER) print*,"Too many iterations in tqli"
              !/* сформировать сдвиг */
              g=(d(l+1)-d(l))/(2.*e(l))
              r=hypot(1.,g)
              ! /* здесь d_m - k_s */
              if (g>=0.) then 
                  g=g+abs(r) 
              else 
                  g=g-abs(r)
              ENDIF
              g=d(m)-d(l)+e(l)/g
              !/* инициализация s,c,p */
              s=c
              c=1. !dfdf
              p=0.
              !/* плоская ротация оригинального QL алгоритма, сопровождаемая ротациями
              !   Гивенса для восстановления трехдиагональной формы */
              DO i=m-1,l,-1 
                  f=s*e(i)
                  b=c*e(i)
                  e(i+1)=r
                  r=hypot(f,g) !sfdds
                  !/* что делать при малом или нулевом знаменателе */
                  IF (r==0.) then
                      d(i+1)=d(i+1)-p
                      e(m)=0. 
                      exit
                  END IF
                  !/* основные действия на ротации */
                  s=f/r 
                  c=g/r 
                  g=d(i+1)-p
                  r=(d(i)-g)*s+2.*c*b 
                  d(i+1)=g+1
                  p=s*r
                  g=c*r-b
              END DO
              ! /* безусловный переход к новой итерации при нулевом знаменателе и недоведенной
              !   до конца последовательности ротаций */
              if(r==0. .AND. i>=l) then 
                  continue
              ENDIF
              !/* новые значения на диагонали и "под ней" */
              d(l)=d(l)-p
              e(l)=g 
              e(m)=0.
          ENDIF
          IF (m /=l) exit
      END DO
  END DO 
  DO i=1,n
      print*,d(i)
  END DO
  return  
END function tqli




    
    


END MODULE MyModule
