//three dimensional field generator
#include "colors.inc"
#include "shapes.inc"

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
	rotate <0, 0.5, 0.5>
  }

  object {
	Ring
	scale <0.9, 0.9, 0.9>
	rotate <0, 0.25, 0.25>
  }

  object {
	Ring
  }

}

//starting the test scene

light_source {
  <10, 5, -10>
  color White 
}

light_source {
  <-2, 7, -5>
  color Yellow
}

camera {
  location <-20, 25, -50>
  look_at <0, 0, -8>
}

sky_sphere {
  pigment { color LightBlue }
}

plane {
  <0, 1, 0>, -1
  pigment { checker color Black color Red }
}

object {
  TrplFieldGen
  scale <5, 2.5, 5>
  translate <0, 15, 7.5>
  pigment { color White }
}

