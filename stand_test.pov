#include "colors.inc"
#include "shapes.inc"
#include "finish.inc"

#include "merkaba.inc"
#include "sephiroth.pov"	//change this to .inc?

camera {
  location <0, 2, -10>
  look_at <0, 0, -0.5>
}

sky_sphere {
  pigment { color Gray }
}

light_source {
  <-3, 8, -12>
  color White
}

light_source {
  <3, 1, -5>
  color White
}

plane {
  <0, 1, 0>, -1
  pigment { checker color White color Black }
  finish { Dull }
}

//objects
/* object {
  MerkabaUnlit
} */

/* box {
  <-0.5, 0.5, -0.5>,
  <0.5, -0.5, 0.5>
  pigment { color Orange }
  translate <-1.5, 0, 0>
} */

object {
	Atziluth
	translate <0, Dist_Eqlt, 0>
}

object {
	Beriah
	//translate not needed; this should be right where we want it
}

