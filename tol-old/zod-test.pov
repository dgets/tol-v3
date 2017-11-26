#include "shapes.inc"
#include "colors.inc"

#include "merk-n-misc.inc"

light_source {
	<-2, 7.5, -10>
	color White
}

camera {
	location <-5, 5, -15>
	look_at <-3, 2, 2>
}

plane {
	<0, 1, 0>, -6.5
	rotate <0, 45, 0>
	pigment { checker color Black color Red }
}

object {
	ZodiacCross
	texture { T_Green_Glass }
	interior { I_Glass }
}
