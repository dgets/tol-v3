//three dimensional field generator

#declare Pi = 22 / 7;

#declare Ring = difference {
  cylinder {
	<0, 0.5, 0>,
	<0, -0.5, 0>, Pi
  }
  cylinder {
	<0, 0.51, 0>,
	<0, -0.51, 0>, (Pi - 0.05)
  }
}

#declare TrplFieldGen = union {
  object {
	Ring
	scale <0.95, 0.95, 0.95>
	rotate <0.25, 0, 0>
  }

  object {
	Ring
	scale <0.9, 0.9, 0.9>
	rotate <0, 0.25, 0>
  }

  object {
	Ring
  }
}


