#declare ZodiacCross = merge {
  difference {
    sphere {
        <0, 0, 0>, 3
    }
    sphere {
        <0, 0, 0>, 2
    }
  }

  //crossmembers (remember this is in 3 dimensions, not 2)
  box {
    <-5, 0.5, -0.5>,
    <5, -0.5, 0.5>
  }
  box {
    <-0.5, 5, -0.5>,
    <0.5, -5, 0.5>
  }
  box {
    <-0.5, 0.5, -5>,
    <0.5, -0.5, 5>
  }

  //end poles
  box { //left
    <-5.5, 1, -1>,
    <-5, -1, 1>
  }
  box { //right
    <5, 1, -1>,
    <5.5, -1, 1>
  }
  box { //top
    <-1, 5.5, -1>,
    <1, 5, 1>
  }
  box { //bottom
    <-1, -5, -1>,
    <1, -5.5, 1>
  }
  box { //close
    <-1, 1, -5.5>,
    <1, -1, -5>
  }
  box { //far
    <-1, 1, 5>,
    <1, -1, 5.5>
  }
}

