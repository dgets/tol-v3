#include "shapes.inc"
#include "colors.inc"

#include "triad-building.inc"

camera {
	location <0, 3, -15>
	look_at <0, 0, -1>
}

light_source {
	<-0.5, 20, -30>
	color White
}

plane {
	<0, 1, 0>, -1
	rotate <0, 45, 0>
	pigment { checker color Black color White }
}

object {
	VesicaPisces
	translate <0, 1, 0>
	pigment { checker color Blue color White }
}

object {
	VPEye
	translate <0, 1, -3>
}

//light source behind this to see better
light_source {
	<0, 1, 1.5>
	color White
}

object {
	FlowerOfLife
	translate <0, 3, 0>
	pigment { Jade }
}

