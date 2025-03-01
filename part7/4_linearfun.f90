module funlin
  implicit none
  contains

  function linear(x, m, y0) result(y)
    Real (Kind = 8) :: x, y, m, y0
    y = x * m + y0
  
  end function linear

end module funlin
