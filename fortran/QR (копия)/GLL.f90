
MODULE NML
implicit none 

 contains    
subroutine LA61(H, WR, WI, Cnt, Error)
!Вычисление собственных значений верхней почти треугольной матрицы Гессенберга.
!Перевод на Фортран 90 программы 'hqr' из книги
!Уилкинсон Дж. Х., Райнш К. Справочник алгоритмов на языке Алгол.
real, intent(inout):: H(:,:)
real:: WR(:), WI(:)
integer:: Cnt(:), Error
real p, q, r, s, t, w, x, y, z
integer i, j, k, l, m, n, n1, n2, its
logical NotLast
!begin
  n=size(H,1); Error=0
  t=0.0
10 continue
  if (n==0) return
  its=0; n1=n-1; n2=n-2
20 continue
  !поиск малого по величине поддиагонального элемента
  l=n
  do while(l>=2)
    if (abs(H(l,l-1))<=epsilon(1.0)*  &
        (abs(H(l-1,l-1))+abs(H(l,l)))) exit
    l=l-1
  end do
  x=H(n,n)
  if (l==n) goto 50
  y=H(n1,n1); w=H(n,n1)*H(n1,n)
  if (l==n1) goto 60
  if (its==30) then
    Error=65; return
  end if
  if (its==10 .OR. its==20) then
    !формирование дополнительного смещения
    t=t+x
    do i=1,n;  H(i,i)=H(i,i)-x; end do
      s=abs(H(n,n1))+abs(H(n1,n2))
    x=0.75*s; y=x; w=-0.4375*s**2
  end if
  its=its+1
  !поиск двух соседних малых по величине поддиагональных элементов
  m=n2
  do while(m>=l)
    z=H(m,m); r=x-z; s=y-z
    p=(r*s-w)/H(m+1,m)+H(m,m+1)
    q=H(m+1,m+1)-z-r-s
    r=H(m+2,m+1)
    s=abs(p)+abs(q)+abs(r)
    p=p/s; q=q/s; r=r/s
    if (l==m) exit
    if (abs(H(m,m-1))*(abs(q)+abs(r)) <=  &
        epsilon(1.0)*abs(p)*(abs(H(m-1,m-1)+abs(z)+abs(H(m+1,m+1))))) exit
    m=m-1
  end do
  do i=m+2,n; H(i,i-2)=0.0; end do
  do i=m+3,n; H(i,i-3)=0.0; end do
  !двойной щаг QR-алгоритма, выполняемый над строками
  !с номерами от l до n и столбцами с номерами от m до n
  NotLast=.true.
  do k=m, n1
    if (k==n1) NotLast=.false.
    if (k/=m) then
      p=H(k,k-1); q=H(k+1,k-1)
      if (NotLast) then; r=H(k+2,k-1); else; r=0.0; end if
      x=abs(p)+abs(q)+abs(r)
      if (x==0.0) cycle
      p=p/x; q=q/x; r=r/x
    end if
    s=sign(sqrt(p**2+q**2+r**2),p)
    if (k/=m) then
      H(k,k-1)=-s*x
    else if (l/=m) then
      H(k,k-1)=-H(k,k-1)
    end if
    p=p+s; x=p/s; y=q/s; z=r/s
    q=q/p; r=r/p
    !изменение строк
    do j=k,n
      p=H(k,j)+q*H(k+1,j)
      if (NotLast) then
        p=p+r*H(k+2,j)
        H(k+2,j)=H(k+2,j)-p*z
      end if
      H(k+1,j)=H(k+1,j)-p*y
      H(k,j)=H(k,j)-p*x
    end do
    if (k+3<n) then; j=k+3; else; j=n; end if
    !изменение столбцов
    do i=l, j
      p=x*H(i,k)+y*H(i,k+1)
      if (NotLast) then
        p=p+z*H(i,k+2)
        H(i,k+2)=H(i,k+2)-p*r
      end if
      H(i,k+1)=H(i,k+1)-p*q
      H(i,k)=H(i,k)-p
    end do
  end do
  goto 20
50 continue
  !выделено одно собственное значение
  WR(n)=x+t; WI(n)=0.0; Cnt(n)=its
  n=n1; goto 10
60 continue
  !выделена пара собственных значений
  p=0.5*(y-x); x=x+p+t
  q=p*p+w; r=sqrt(abs(q))
  Cnt(n1)=its; Cnt(n)=-its
  if (q>=0.0) then
    !пара вещественных собственных значений
    WR(n1)=x+r; WR(n)=x-r
    WI(n1)=0.0; WI(n)=0.0
  else
    !пара компл.-сопряж. собственных значений
    WR(n1)=x; WR(n)=x
    WI(n1)=r; WI(n)=-r
  end if
  n=n2; goto 10
end subroutine LA61
END MODULE NML
