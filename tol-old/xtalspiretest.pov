#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"

#include "merk-n-misc.inc"

camera {
	location <0, 2, -20>
	look_at <0, 1.5, 0>
}

light_source {
	<-5, 10, -5>
	color White
}

plane {
	<0, 1, 0>, -1
	pigment { checker color Blue color White }
}

sky_sphere {
	pigment { MyApocalypse }
}


/*
  this is the object that we need to make work
  prism {
        conic_sweep
        linear_spline
        -0.5,
        0.5,
        7,
        <3,5>, <-3,5>, <-5,0>, <-3,-5>, <3, -5>, <5,0>, <3,5>
        //rotate <0, 0, 180>    what the fuck is wrong with this?
        translate <0, 3, 0>
  }
*/

/*
object {
	XtalSpire
	translate <0, 2.5, 0>
	texture { Brushed_Aluminum }
}
*/

//reference object
sphere { <0, 0, 0>, 1 pigment { color Orange } }

prism {
	conic_sweep
	linear_spline
	-0.5,
	0.5,
	7,
	<3,5>, <-3,5>, <-5,0>, <-3,-5>, <3, -5>, <5,0>, <3,5>
	translate <-10, 1, 0>
	scale <1, 3, 1>
	pigment { color Red }
}

prism {
	conic_sweep
	linear_spline
	0,
	-1,
	7,
	<3,5>, <-3,5>, <-5,0>, <-3,-5>, <3, -5>, <5,0>, <3,5>
	translate <0, 1.5, 0>
	scale <1, 3, 1>
	pigment { color Yellow }
}

prism {
	conic_sweep
	linear_spline
	1,
	0,
	7,
	<3,5>, <-3,5>, <-5,0>, <-3,-5>, <3, -5>, <5,0>, <3,5>
	translate <10, 1, 0>
	scale <1, 3, 1>
	pigment { color Blue }
}
