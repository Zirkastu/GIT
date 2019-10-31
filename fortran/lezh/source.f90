program PAM
  USE MyModule
  integer :: n = 3
  integer :: k = 0
  real:: x = 0.
  x=dlezh(0.5, n)
  print*, "----------------------------------------"
  print*, x

  Do i=1,n-1
      x=solve(n, i)
      print*, x
  end do
  
end program PAM


