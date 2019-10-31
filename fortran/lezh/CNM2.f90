
MODULE MyModule
implicit none 
real, allocatable :: Koef(:)
real, allocatable :: DKoef(:)
 contains    
integer function CNM(n, m) result(l)
    integer, intent(in):: n, m
    integer:: i, n1, m1
    m1=m
    if(m1>n-m) m1=n-m
    l=1; 
    n1=n+1
    do i=1,m1
        l=l*(n1-i)/i
    end do
    return
end function CNM

integer function EVEN(n) result(l)
    integer, intent(in):: n   
    if ((MOD(n, 2))==0) then
        l=1
    else
        l=-1
    END IF
    return
end function EVEN 

real function lezh(x, n) result(l)
    integer, intent(in):: n
    real, intent(in):: x
    integer::m,i,k,j=0
    real::b,c,d 
    real,allocatable :: a(:)
     
   IF( .NOT. ALLOCATED( Koef ) ) then
        m=int((n+2)/2)
        
        allocate(Koef(0:m-1))
        allocate(a(0:m-1))
        
        a(0)=1
        Koef(0)=1 
        DO k = 1,m-1      
            Koef(k)=0
            a(k)=0            
        END DO  
              
        DO i = 1, n-1
            c=Koef(0)            
            Koef(0)=Koef(0)*(1.*(2*i+1))/(i+1) 
            d=a(0)
            j=int((i+3)/2)                      
            DO k = 1,j-1
                b=Koef(k)              
                Koef(k)=Koef(k)*(1.*(2*i+1)/(i+1)) - d*(1.*i/(i+1))                               
                d=a(k)
                a(k)=b
            END DO
            a(0)=c
        END DO      
    END IF
    i=0
    l=0.     
    DO k=0,n-1       
       l = l + x**(n-i)*Koef(k)               
       i=i+2
    end do
    !Deallocate (Koef)
    !Deallocate (a)
    return
end function lezh 

real function dlezh(x, n) result(l)
    integer, intent(in):: n
    real, intent(in):: x
    integer::m,i,k
    IF( .NOT. ALLOCATED( DKoef ) ) then
        m=int((n+1)/2)
        allocate(DKoef(0:m-1))
        k=0
        DO i = 0, m-1
            DKoef(i)=Koef(i)*(n-k) 
            k=k+2           
        END DO
    END IF
    i=0
    l=0.
    k=0  
    DO k=0,n-2      
        l = l + x**(n-i-1)*Dkoef(k)               
        i=i+2
    end do
    !Deallocate (Koef)
    return
end function dlezh     

real function solve(n,i) result(x1)

  integer, intent(in):: n,i   
  real x0
  real:: pi
  pi=acos(-1.)
  x1  = Cos(pi*(4*i-1)/(4*n+2))
  DO while (abs(x1-x0)>0.001)
    x0 = x1
    x1 = x1 - (lezh(x1,n)/dlezh(x1,n))
  end do  
  return
end function solve
    
    


END MODULE MyModule
