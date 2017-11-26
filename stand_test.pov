#include "colors.inc"
#include "shapes.inc"
#include "finish.inc"
#include "stones.inc"

#include "merkaba.inc"
#include "sephiroth.pov"	//change this to .inc?
#include "misc-architecture.inc"

camera {
  location <0, 6, -13>
  look_at <0, 5.75, -0.5>
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

//sephiroth.pov
/*object {
	Atziluth
	translate <0, Dist_Eqlt, 0>
}

object {
	Beriah
	//translate not needed; this should be right where we want it
}*/

//misc-architecture.inc
/*union {
    object {
	TowerBody
	translate <0, 6, 0>
	//texture { T_Stone1 }
    }

    object {
	TCap
	translate <0, 6, 0>
	//scale <0, 2, 0> - why no workee?
    }

    texture { T_Stone11 }
}*/

object {
	Tower
	translate <0, 6, 0>
	texture { T_Stone11 }
}


