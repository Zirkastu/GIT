MODULE spectralmethod
implicit none 
 contains 
subroutine Spectral(KNL)
  USE MyModule
  integer,intent(in)::KNL
  
  integer :: Nx = 70,& ! Число элементов
             Nv = 1,& ! Число внутренних узлов
             N,& ! Число узлов
             i
  real :: XL=1,& ! Длина стержня
         Dx,& ! длина КЭ
          y=0,&
          deltaT=0.000001,&         ! Шаг по времени
          E=2.1E11
  real,allocatable:: xi(:) ! Координаты узлов в локальной системе координат  
  real,allocatable:: M(:)  ! Матрица масс
  real,allocatable:: K(:,:)  ! Матрица жесткости
  real,allocatable:: U(:) !вектор перемещений 
  real,allocatable:: MU(:) !вектор K*перемещений
  real,allocatable:: SIGMA(:) !вектор K*перемещений
  
  N=Nx+1+Nx*Nv
  Dx=XL/NX
  !-------------------------
  allocate (xi(0:Nv+1))  
  CALL ROOTS(Nv,xi)  
  !-------------------------
  allocate (M(0:Nv+1))
  CALL MASS(N,xi,M,Dx,Nx)
  !-------------------------  
  !-------------------------
  allocate (U(0:N-1))
  allocate (SIGMA(0:N-1))  
 
  !--------------------------
  !------------------------
  allocate (K(0:Nv+1,0:Nv+1))
  CALL RIGIDITY(N,xi,K,DX,NX,E)
    
  !--------------------------  
  CALL Newmark(M,K,U,deltaT,N,NX,xi,DX,E,KNL,SIGMA) 
  !Deallocate(M)
  !Deallocate(K)     
  

end subroutine Spectral

END MODULE spectralmethod

