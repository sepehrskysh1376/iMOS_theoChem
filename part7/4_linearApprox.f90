program linapp

  use maketable
  
  implicit none
  ! --------------------------------------------------------
  Integer :: io1, io2, iostat, rowCount, i, minindex, minCount, sign
  Real (Kind = 8) :: inpX, mindiff, anear1, anear2, bnear1, bnear2, m, b0
  !Real (Kind = 8), Dimension(:), Allocatable :: a, b, c
  Real (Kind = 8), Dimension(:), Allocatable :: a, b, c, diff, alin, blin, clin
  Character (len = 256) :: line
  ! --------------------------------------------------------

  print *, "Making linear approximation of arbitrary x"
  
  ! ------------------Getting the data----------------------
  ! two file openning for counting the lines and saving them
  open(newunit = io1, file = "iso.xvg", action = "read")  
  open(newunit = io2, file = "iso.xvg", action = "read")
  
  rowCount = 0
  do ! The number of lines in the table file
    read(io1, *, iostat=iostat) line

    if (iostat /= 0) exit

    rowCount = rowCount + 1
  end do

  close(io1)

  print *, "rowCount = ", rowCount

  allocate(a(rowCount), b(rowCount), c(rowCount))
  
  ! Saving the data in three variables
  do i = 1, rowCount
    read(io2, *) a(i), b(i), c(i)
  end do
  
  close(io2)


  ! ----------------------Getting input---------------------
  print *, "Give me an arbitrary point between "
  print *, minval(a), " - ", maxval(a), " :" 
  read (*, *) inpX

  ! ---------------Getting two nearest points---------------
  Allocate(diff(rowCount)) 
  
  ! Difference Search
  do i = 1, rowCount
    diff(i) = abs(inpX - a(i))
  end do

  mindiff = minval(diff)
  
  minCount = 0
  do i = 1, rowCount
    if (diff(i) == mindiff) minindex = i
  end do
  
  ! The nearest values of a, anear1 and anear2
  anear1 = a(minindex)
  bnear1 = b(minindex)

  if ( (a(minindex) - inpX) < 0 ) then
    anear2 = a(minindex + 1) 
    bnear2 = b(minindex + 1)
    sign = 1
  else
    anear2 = a(minindex - 1)
    bnear2 = b(minindex - 1)
    sign = -1
  end if
  

  print *, "anear1 = ", anear1
  print *, "anear2 = ", anear2


  ! -----------------Linear interpolation-------------------
  allocate(alin(rowCount), blin(rowCount), clin(rowCount)) 

  ! The linear function
  alin = a
  clin = c
  m = (bnear2 - bnear1) / (anear2 - anear1) ! Slope
  b0 = bnear1 - m * anear1 ! Intercept

  do i = 1, rowCount
    blin(i) = m * alin(i) + b0 
  end do
  
  call tableing("isolin.xvg", alin, blin, clin, rowCount)  

  Deallocate(a, b, c, diff)
  
end program linapp
