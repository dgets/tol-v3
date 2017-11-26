#include "colors.inc"
#include "textures.inc"
#include "shapes.inc"
#include "shapesq.inc"

/*
camera {
	location <-3, 5, -15>
	look_at <0, 2, 0>
}
*/

camera {
	location <0, 10, -3>
	look_at <0, 4, 0>
} 

plane {
	<0, 1, 0>, -1
	pigment { checker color Red color White }
}

light_source {
	<0, 20, -20>
	color White
}

light_source {
	<0, -10, -20>
	color Yellow
}

object {
	Helix
	//rotate <0, 0, 90>
	texture { Sapphire_Agate }
}
object {
	Helix
	//rotate <0, 0, 90>
	translate <0, 2, 0>
	pigment { color Blue }
}
object {
	Helix
	//rotate <0, 0, 90>
	translate <0, 4, 0>
	pigment { color Green }
}

