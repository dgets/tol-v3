#include "colors.inc"
#include "shapes.inc"
#include "finish.inc"
#include "stones.inc"

#include "merkaba.inc"
#include "sephiroth.inc"	//change this to .inc?
#include "misc-architecture.inc"

//slightly above, looking down just a bit, not all the way to the origin
/*camera {
  location <0, 6, -13>
  look_at <0, 5.75, -0.5>
}*/

//higher up, looking downward steeper from that & a focal point closer to the
//origin
camera {
    location <0, 10, -13>
    look_at <0, 3, -0.5>
}

sky_sphere {
  pigment { color Gray }
}

//probably need some more options for lighting, especially as we start putting
//all of the different object samples together in here
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
  rotate y*45   //I do like the diagonal angles better
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
/*object {
	Tower
	translate <0, 6, 0>
	texture { T_Stone11 }
}*/

/*object {
    ArchToppedCyl
    scale <3, 3, 3>
    pigment { color Orange }
}*/

/*object {
    SteppedMount
    scale <5, 5, 5>
    //pigment { color Orange }
    texture { T_Stone1 }
}*/

object {
    SteppedPyramid
    texture { T_Stone2 }
}
