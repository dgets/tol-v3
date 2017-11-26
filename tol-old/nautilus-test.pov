#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"

#include "nautilus.inc"

camera {
	location <0, 5, -45>
	look_at <0, 0, 0>
}

light_source {
	<0, 10, -20>
	color White
}

light_source {
	<5, 7, -10>
	color White
}

light_source {
	<-5, 7, -10>
	color White
}

plane {
	<0, 1, 0>, -8
	pigment { checker color Black color White }
}

object {
	Nautilus
	translate <-12, 0, 5>
	pigment { color Gray }
}
light_source {
	<-12, 30, 5>
	color Green
}

object {
	Nautilus
	translate <12, 0, 0>
	rotate <0, 90, 0>
	pigment { color Yellow }
}
light_source {
	<12, 30, 5>
	color Green
}

