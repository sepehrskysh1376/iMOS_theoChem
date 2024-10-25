PROGRAM angle

IMPLICIT NONE

INTEGER :: i,n
DOUBLE PRECISION, DIMENSION(:), ALLOCATABLE :: v1, v2
DOUBLE PRECISION :: len1, len2, prod

PRINT *,"Dimension of the vectors:"
READ '(I)',n
PRINT *,"Input was: ",n

ALLOCATE(v1(n),v2(n),STAT=i)
! IF (i.NE.0) THEN
IF (i/=0) THEN
   PRINT *,"Allocation failed!"
   STOP
END IF

PRINT *,"Values of vector 1:"
DO i = 1, n
   READ *,v1(i)
END DO

PRINT *,"Values of vector 2:"
DO i = 1, n
   READ *,v2(i)
END DO

len1 = 0.0
len2 = 0.0
prod = 0.0
DO i = 1, n
   len1 = len1 + v1(i)**2
   len2 = len2 + v2(i)**2
   prod = prod + v1(i)*v2(i)
END DO
len1 = SQRT(len1)
len2 = SQRT(len2)
PRINT *,ACOS(prod/(len1*len2))

END PROGRAM
