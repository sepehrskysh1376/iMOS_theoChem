module maketable
  
  implicit none
  contains

  subroutine tableing(name, x, y, z, n) 
    ! name: name of the file
    ! x, y, z: inputs and outputs and timesteps of the function
    ! n: the amount of inputs or outputs
    ! ------------------------------------------------------
    character(len = *) :: name
    Real (Kind = 8), Dimension(:), Allocatable :: x, y, z
    Integer :: i, n, io
    ! ------------------------------------------------------ 
    
    ! -----------------Writing file------------------------- 
    open(newunit = io, file = trim(name), action = "write")
    
    ! allocate(x(n), y(n), z(n))

    do i = 1, n
      write(io, *) x(i), y(i), z(i)
    end do
      
    close(io) 
    deallocate(x, y, z)
  end subroutine tableing


end module maketable
