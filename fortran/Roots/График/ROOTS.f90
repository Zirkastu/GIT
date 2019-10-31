
MODULE MyModule
implicit none 
 contains 
subroutine DN(i,j,n,a,l)   
     integer, intent(in):: i,j,n
     integer :: k,mini,maxi     
     real,allocatable,intent(in):: a(:)
     real,intent(inout):: l
     
     IF (i/=j) then
         maxi=MAX0(i,j)
         mini=MIN0(i,j)
         l=1/(a(i) - a(j))
         DO k=0,mini-1
             l=l*((a(j)-a(k))/(a(i)-a(k)))   
         END DO 
         DO k=mini+1,maxi-1
             l=l*((a(j)-a(k))/(a(i)-a(k)))   
         END DO 
         DO k=maxi+1,n-1
             l=l*((a(j)-a(k))/(a(i)-a(k)))   
         END DO
     ELSE
         l=0
         DO k=0,i-1
             l=l+1/(a(i)-a(k))
         END DO
         DO k=i+1,n-1
             l=l+1/(a(i)-a(k)) 
         END DO
      END IF 
      
      
end subroutine DN  

 subroutine  ROOTS(n,d) !pd -Поддиагональные элементы
    integer, intent(in):: n
    real,allocatable,intent(inout):: d(:)
    integer:: i,k,j
    real,allocatable:: pd(:)
    real::p,p1,p2,a,b,l
    logical::FLAG=.FALSE. 
    IF (n==1) then
        d(0)=-1.0
        d(1)=0.0
        d(2)=1.0
        return
    END IF   
    allocate (pd(1:n-1))
    DO i=1,n-1
        pd(i)=SQRT(1.*(i*i+2*i)/((2*i+3)*(2*i+1)))
    END DO 
    a=-1.0
    j=0             
    l=0.0
    k=1          
    DO WHILE (j<int(n/2))                    
        DO WHILE ( k /= n-j)            
            k=1           
            IF (FLAG) then
                a=b
                b=0.0
                FLAG=.FALSE.
            else
                b=l
            endif
            l=(a+b)/2
            p2=1.0
            p1=-l               
            DO i=2,n                
                p=(-l)*p1-pd(i-1)*pd(i-1)*p2
                IF (p/p1 > 0 ) then
                    k=k+1                    
                END IF                                               
                p2=p1
                p1=p   
            END DO              
        END DO
        a=l
        l=b
        k=1             
        if (abs(b-a)<0.0000001) then
            d(n-j)=-(a+b)/2
            j=j+1
            d(j)=-d(n-j+1)            
            FLAG=.TRUE.
        endif           
    END DO          
    deallocate(pd)
    d(0)=-1.0
    d(n+1)=1.0
    IF  ( (mod(n,2)) /= 0 ) then
        d(int((n+1)/2))=0.0
    endif
       
end subroutine ROOTS 

real function lezh(x, n) result(p)
    integer, intent(in):: n
    real, intent(in):: x
    real::p1,p0
    integer::i
    p=x
    p1=1.0   !P_(n-1)
    p0=x   !P_n
    DO i=1,n-1
        p=((2.*i+1)/(i+1.))*x*p0 - p1*(i/(i+1.))        
        p1=p0
        p0=p
    END DO
    return
end function lezh

subroutine  weight(n,x,w) !
   
    integer, intent(in):: n
    real,allocatable,intent(inout):: w(:)
    real,allocatable,intent(in):: x(:)
    integer:: i
    real:: w1=0.0
     
    DO i=0,int(n/2)
        w1=lezh(x(i),n)         
        w(i)=2/((n*(n+1))*(w1*w1))
        w(n-i)=w(i)
    END DO    
end subroutine weight

subroutine MASS(n,xi,m,DX,NX)   
     integer, intent(in):: n,NX                           
     real, intent(in):: DX       
     real,allocatable,intent(in):: xi(:)
     real,allocatable,intent(inout)::M(:) 
     integer :: i,j,NL 
     real,allocatable::w(:)
     real::l
     NL=(N-1+NX)/NX 
     allocate (w(0:NL-1))
     CALL weight(NL-1,xi,w)                  
     DO j=0,NL-1 
         M(j)=0.0                     
         DO i=0,NL-1
             CALL DN(i,j,NL,xi,l) 
             M(j)=M(j)+l*(xi(i)*DX/2 + DX/2) !+v*DX)?
         END DO
         M(j)=M(j)*w(j)             
     END DO   
     M=M*7800
end subroutine MASS

subroutine RIGIDITY(N,xi,K,DX,NX,E)   
     integer, intent(in):: n,NX                           
     real, intent(in):: DX,E       
     real,allocatable,intent(in):: xi(:)
     real,allocatable,intent(inout)::K(:,:) 
     integer :: i,j,NL,i1,j1=0,m,m1  
     real,allocatable::w(:)
     real::l1,l2,l3,&
     x=0.0
     NL=(N-1+NX)/NX !Число узлов в элементе
     allocate (w(0:NL-1))
     CALL weight(NL-1,xi,w)
     
     DO i=0,NL-1
         DO j=j1,NL-1
             K(i,j)=0.0
             DO m=0,NL-1
                 CALL DN(i,m,NL,xi,l1)!
                 CALL DN(j,m,NL,xi,l2)!
                 DO m1=0,NL-1
                     CALL DN(m1,m,NL,xi,l3)!
                     x=x+l3*(xi(m1)*DX/2 + DX/2)
                 END DO                
                 K(i,j)=K(i,j) + l1*l2*w(m)/x
                 x=0.0 
             END DO
             K(j,i)=K(i,j)
         END DO
         j1=j1+1         
     END DO
     K=K*E!*1E-4
end subroutine RIGIDITY

subroutine DEVIDEMASS(M,U,N,NX,MU)   
     integer, intent(in):: n,NX           
     real,allocatable,intent(in):: M(:),MU(:)
     real,allocatable,intent(inout)::U(:) 
     integer :: i,j,NL 
     NL=(N-1+NX)/NX !Число узлов в элементе
     DO i=0,NX-1
         DO j=0,NL-1             
             U(j+i*(NL-1))=MU(j+i*(NL-1))/M(j)  
         END DO
     END DO
     U(N-1)=MU(N-1)/M(NL-1)
     DO i=1,NX-1
         U(i*(NL-1))=MU(i*(NL-1))/(M(0)+M(NL-1))
     END DO
end subroutine DEVIDEMASS


subroutine MultiplyRigidity(K,U,N,NX,KU)   
     integer, intent(in):: n,NX     
     real,allocatable,intent(in):: K(:,:),U(:)
     real,allocatable,intent(inout)::KU(:) 
     integer :: i,j,NL,j1 
     NL=(N-1+NX)/NX !Число узлов в элементе
     DO i=0,N-1
         KU(i)=0.0
     END DO
     DO i=0,NX-1
         DO j1=0,NL-1
             DO j=0,NL-1             
                 KU(j1+i*(NL-1))=KU(j1+i*(NL-1))+U(j+i*(NL-1))*K(j1,j) !j1->j?
             END DO
         END DO
     END DO    
end subroutine MultiplyRigidity 



Subroutine Newmark(M,K,U1,deltaT,N,NX,xi,DX,E,KNL,SIGMA)
    real,allocatable,intent(in):: M(:),K(:,:),xi(:)
    real,intent(in):: deltaT,DX,E
    integer,intent(in):: N,NX,KNL
    real,allocatable,intent(inout):: U1(:),SIGMA(:)
    real,allocatable:: MU0(:),MU1(:),MU2(:)
    real::l,SIGM=0.0,x=0.0,SIGMA1=0.0,c
    integer:: i,i1,NL,j1,j,j2,m1,p,iter
    NL=(N-1+NX)/NX
    c=SQRT(E/7800)
    allocate(MU0(0:N-1))
    allocate(MU1(0:N-1))
    allocate(MU2(0:N-1))
    DO i=0,N-1
        MU0(i)=0.0
        MU1(i)=0.0
    END DO    
             

     !open(12,FILE='result2')
    iter=int((1/c)*10.5/deltaT)+10
    print*,iter
    DO i=0,iter
        CALL MultiplyRigidity(K,U1,N,NX,MU2) !Результат умножения KU1 ->MU2       
        MU2=MU2*(-1.*deltaT*deltaT) + MU1*2 - MU0
        MU2(N-1)=MU2(N-1) - 1.0E6*deltaT*deltaT
        MU2(0)=0.0
        MU0=MU1              
        MU1=MU2         
        CALL DEVIDEMASS(M,U1,N,NX,MU2) !MU2/M ->U1 
        IF (MOD(i,10)==0) then 
            DO p=0,NL-1
                SIGMA(p)=0.0
                DO m1=0,NL-1
                    CALL DN(m1,p,NL,xi,l)    
                    SIGMA(p)=SIGMA(p)+((DX/2)*xi(m1)+DX/2)*l 
                END DO
                SIGMA(p)=1/SIGMA(p)
            END DO
            DO p=NL,N-1           
                j1=i-int((i-1)/(NL-1))*(NL-1)          
                SIGMA(p)=SIGMA(j1)
            END DO     
            DO j=0,N-1            
                j1=j-int((j-1)/(NL-1))*(NL-1)
                j2=int((j-1)/(NL-1))*(NL-1)
                DO i1=0,NL-1                     
                    CALL DN(i1,j1,NL,xi,l)                    
                    SIGM=SIGM+l*U1(j2+i1)
                END DO
                SIGMA(j)=SIGMA(j)*SIGM*E
                SIGM=0.0
            END DO                      
            write(KNL,'(2E15.6)') i*deltaT,SIGMA(0)                             
        ENDIF                        
    END DO
 
    
    deallocate (MU0)
    deallocate (MU1)
    deallocate (MU2)
END SUBROUTINE Newmark





END MODULE MyModule
