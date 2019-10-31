
MODULE MyModule
implicit none 
real, allocatable :: Koef(:)
real, allocatable :: DKoef(:)
real, allocatable :: DDKoef(:)
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
    integer::m,i,k,j=0
    real::b,c,d 
    real,allocatable :: a(:)
    m=int((n+1)/2)
   IF( .NOT. ALLOCATED( DKoef ) ) then
        
        
        allocate(DKoef(0:m-1))
        allocate(a(0:m-1))
        
        a(0)=0
        DKoef(0)=1 
        DO k = 1,m-1      
            DKoef(k)=0
            a(k)=0            
        END DO  
              
        DO i = 1, n-1
            c=DKoef(0)            
            DKoef(0)=DKoef(0)*(1.*(2.*i+1)/i) 
            d=a(0)
            j=int((i+2)/2)                      
            DO k = 1,j-1
                b=DKoef(k)              
                DKoef(k)=DKoef(k)*(1.*(2.*i+1)/i) - d*(1.*(i+1)/i)                                               
                d=a(k)
                a(k)=b
            END DO
            a(0)=c
        END DO      
    END IF
    l=0.    
    i=1  
   
    DO k=0,m-1       
       l = l + x**(n-i)*DKoef(k)               
       i=i+2
    end do
    
    !Deallocate (Koef)
   ! Deallocate (a)
    return
end function dlezh 

real function ddlezh(x, n) result(l)
    integer, intent(in):: n
    real, intent(in):: x
    integer::m,i,k
    m=int(n/2)
    IF( .NOT. ALLOCATED( DDKoef ) ) then        
        allocate(DDKoef(0:m-1))
        k=0
        DO i = 0, m-1
            DDKoef(i)=DKoef(i)*(n-k-1) 
            k=k+2           
        END DO
    END IF
  
    DO k=0,m      
        l = l + x**(n-i-1)*DDkoef(k)               
        i=i+2
    end do
    !Deallocate (Koef)
    return
end function ddlezh     



real function solve(n,i) result(x1)

  integer, intent(in):: n,i   
  real:: x0,x
  real:: pi
  pi=acos(-1.)
  x1  = (Cos(pi*(4*i-1)/(4*n+2)) -Cos(pi*(4*i-5)/(4*n+2)))/2
  DO while (abs(x1-x0)>0.000001)
    x0 = x1    
    x1 = x1 - ((dlezh(x1,n))/ddlezh(x1,n))
  end do  
  return
end function solve
 subroutine MASS(n,xi,m,DX,NX)   
     integer, intent(in):: n,NX                           
     real, intent(in):: DX       
     real,allocatable,intent(in):: xi(:)
     real,allocatable,intent(inout)::M(:) 
     integer :: i,j,k=0,v=0,NL,p  
     real,allocatable::w(:)
     real::l
     NL=(n+NX)/NX 
     allocate (w(0:NL-1))
     CALL weight(NL-1,xi,w)
     DO i=0,n
         M(i)=0
     END DO     
     DO WHILE (k<n)
         p=0
         DO j=k,k+NL-1                      
             DO i=0,NL-1
                 CALL DN(i,p,NL-1,xi,l) 
                 M(j)=M(j)+l*(xi(i)*DX/2 + DX/2) !+v*DX)?
             END DO
             M(j)=M(j)*w(p)
             p=p+1
         END DO
         k=k+NL-1 !
         v=v+1
    END DO
end subroutine MASS   
    


END MODULE MyModule
