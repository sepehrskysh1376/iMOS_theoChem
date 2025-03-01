program mktable
  use fun

  implicit none

  Integer :: io, n, m, i
  Real (Kind = 8) :: x, y, step 
  print *, "From (ex: 0) ?"
  read (*, *) m
  print *, "To (ex: 100) ?"
  read (*, *) n
  print *, "And with what step (ex: 1) ?"
  read (*, *) step

  open(newunit=io, file="iso.xvg", action="write")
  
  x = m
  do i = 0, ceiling((n - m)/step)
    x = x + step  
    y = para(x) 
    write(io, *) x, y, step
  end do

  close(io)

end program mktable
