program ex2
  Integer :: n, i
  Real (KIND = 8), Dimension(:), Allocatable :: a, b
  Real (KIND = 8) :: lena, lenb, dotmul

  print *, "Give me a dimension right now: "
  read (*,*) n
  allocate(a(n), b(n))

  do i = 1, n
          print *, "A Vector (",i,") component: "
          read (*,*) a(i)
          print *, "B Vector (",i,") component: "
          read (*,*) b(i)
  end do
  
  lena = 0.0
  lenb = 0.0
  do i = 1, n
          lena = lena + a(i)*a(i)
          lenb = lenb + b(i)*b(i)
  end do
  
  lena = sqrt(lena)
  print *, "The length of A Vector: ", lena
  lenb = sqrt(lenb)
  print *, "The length of B Vector: ", lenb      
  
  dotmul = 0.0
  do i = 1, n
          dotmul = dotmul + a(i)*b(i)
  end do
  print *, "The dot product of A and B: ", dotmul

  print *, "Angle between A and B: ", dacos(dotmul/(lena*lenb)) 
  
  deallocate(a,b)

end program ex2
                

        
        
    

