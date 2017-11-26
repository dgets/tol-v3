#include "shapes.inc"
#include "colors.inc"
#include "textures.inc"

#include "triad-building.inc"

camera {
	location <0, 2, -5>
	look_at <0, 0, 0>
}

light_source {
	<-2, 25, -25>
	color White
}

light_source {
	<-5, 10, 0>
	color White
}

light_source {
	<5, 10, 0>
	color White
}

plane {
	<0, 1, 0>, -7
	pigment { checker color Red color Black }
}

object {
	DNAStrand
}

