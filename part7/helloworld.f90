program helloworld

!print something, * means default formatting
print*, 'hello world'

!D = double precision
print*, 1.0/3.0D0

!formatting specified: 10 spaces reserved, 6 after the decimal point
print '(F10.6)', 1.0/3.0D0
!scientific notation
print '(E14.6)', 1.0/3.0D0

!just prints zero as we are dividing integer
print*, 1/3

!print single precision 
print*, 1.0/3
end program helloworld
