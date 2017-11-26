#include "shapes.inc"
#include "shapes2.inc"
#include "colors.inc"
#include "stones.inc"

#include "temple.inc"

light_source {
	<-3, 15, -30>
	color White
}

light_source {
	<0, 5, -10>
	color Yellow
}

camera {
	location <0, 4, -25>
	look_at <0, 5, -3.15>
}

plane {
        <0, 1, 0>, -1
        pigment { checker color Black color Red }
}

sky_sphere {
        pigment { Blue }
}

//testing
/*
object {
	GreekColumn
	translate <0, 5, 0>
	texture { T_Stone9 }
}
*/
/*
object {
	SteppedMount
	texture { T_Stone9 }
}
*/

object {
	OpenTemple
	texture { T_Stone9 }
}

