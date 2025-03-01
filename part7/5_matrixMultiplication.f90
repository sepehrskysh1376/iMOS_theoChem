program matmul
  ! Installing the DGEMM library and use it:
  ! * Installation:
  !   $ sudo apt update
  !   $ sudo apt install libopenblas-dev
  ! * Use it:
  !   $ gfortran myprogram.f90 -o myprogram -lopenblas -lpthread
  
  implicit none

  ! -----------------------------------------------------------
  Integer :: i, j, n, k
  Real (Kind = 8) :: pi, sum, tb, te
  Real (Kind = 8), Dimension(:, :), Allocatable :: aij, bij, mij, dij
  ! -----------------------------------------------------------
  
  ! Writing a formula for pi
  pi = acos(-1.0)
  print *, "What dimension are your matrices?"
  read (*, *) n

  ! --------------------Making the Matrices--------------------
  allocate(aij(n, n), bij(n, n))
  
  call cpu_time(tb)
  do i = 1, n
    do j = 1, n
      aij(i, j) = sin( (2 * pi * i * j) / n)
      bij(i, j) = cos( (2 * pi * i * j) / n)
    end do
  end do
  call cpu_time(te) 
    
  print *, "Matrix building time: ", te - tb , " s"

  ! -----------------Matrix multiplication (mine)--------------
  allocate(mij(n, n))
  
  call cpu_time(tb)
  do i = 1, n
    do j = 1, n

      sum = 0.0
      do k = 1, n
        sum = sum + ( aij(i, k) * bij(k, j) )
      end do
        
      mij(i, j) = sum
    end do
  end do
  call cpu_time(te)
  print *, "My matrix multiplication time: ", te - tb , " s"

  ! ---------------Matrix multiplication (DGEMM)---------------
  allocate(dij(n, n))
  
  call cpu_time(tb)
  call DGEMM("N", "N", n, n, n, 1.0, aij, n, bij, n, 1.0, dij, n)
  call cpu_time(te)

  print *, "DGEMM matrix multiplication time: ", te - tb , " s"


  deallocate(aij, bij, mij, dij)

end program matmul
