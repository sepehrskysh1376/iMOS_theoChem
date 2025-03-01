module fun
  implicit none
  contains
  
  function para(x) result(f)
    Real (Kind = 8) :: x, f
    f = sin(x)
  end function para

end module fun
