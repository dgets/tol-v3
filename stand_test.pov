#include "colors.inc"
#include "shapes.inc"
#include "finish.inc"

#include "merkaba.inc"

camera {
  location <0, 1, -5>
  look_at <0, 0, -0.5>
}

sky_sphere {
  pigment { color Gray }
}

plane {
  <0, 1, 0>, -1
  pigment { checker color White color Black }
  finish { Dull }
}

//objects
object {
  MerkabaUnlit
}

box {
  <-0.5, 0.5, -0.5>,
  <0.5, -0.5, 0.5>
  pigment { color Orange }
  translate <-1.5, 0, 0>
}

