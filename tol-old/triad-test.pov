#include "colors.inc"
#include "shapes.inc"
#include "stones.inc"
#include "metals.inc"
#include "glass.inc"
#include "textures.inc"
#include "shapes2.inc"

#include "triad-building.inc"

//aboveish
//camera {
//	location <0, 10, -15>
//	look_at <0, 2, 0>
//}

camera {
	location <0, 3, -20>
	look_at <0, 2, 0>
}

//pseudo-sun
light_source {
	<-150, 500, -20>
	color Yellow
}

//straight up and behind
light_source {
	<0, 15, -15>
	color White
}

//inside at 'abyss' level
light_source {
	<0, 3.0, 0>
	color Blue
}

//below the crown
light_source {
	<0, -5, -3>
	color Violet
}

//below and in front of merkaba
light_source {
	<25, 12, 0>
	color White
}
plane {
	<0, 1, 0>, -15
	pigment { checker color White color Black }
}

/*
object {
	Triad
	translate y*4.5
}

object {
	Level_Triad_Join
	translate y*4.5
}

object {
	Triad
	translate y*1.5
}

object {
	Level_Triad_Join
	translate y*1.5
}

object {
	Triad
	translate y*-1.5
}

object {
	Level_Triad_Join
	translate y*-1.5
}
*/

//straight up
object {
	Nine_Seph
	translate <0, 4.5, 0>
}

object {
	Ten_Web
	translate <0, 4.5, 0>
}

//crown sephiroth
sphere {
	<0, -4.5, 0>
	1
	texture { T_Stone21 }
	translate <0, 4.5, 0>
}

//now let's add the other 5 and try to see what 'Crossing the Event Horizon'
//was showing
/*
#declare RotAng = 60;
#while (RotAng < 360)
  object {
	Nine_Seph
	rotate <0, 0, RotAng>
	translate <cosd(RotAng) * 4.5, sind(RotAng) * 4.5, 0>
  }

  object {
	Ten_Web
	rotate <0, 0, RotAng>
	translate <cosd(RotAng) * 4.5, sind(RotAng) * 4.5, 0>
  }

  #declare RotAng = RotAng + 60;
#end	//of while
*/

/* testing of transformation for use in above algorithm
   alright let's just do it manually first :| */ 
object {
	Nine_Seph
	rotate <0, 0, 60>
	//translate <cosd(90) * 4.5, sind(90) * 4.5, 0>
	translate <-4.5, 2, 0>
}

object {
	Ten_Web
	rotate <0, 0, 60>
	//translate <cosd(90) * 4.5, sind(90) * 4.5, 0>
	translate <-4.5, 2, 0>
} 

/*
//merkaba
object {	//pointed up
	Tetrahedron
	scale <5, 5, 5>
	translate <20, 20, 60>
	texture { T_Yellow_Glass }
	interior { I_Glass }
	//finish { F_Glass8 }
}
object {	//pointed down
	Tetrahedron
	scale <5, 5, 5>
	rotate <180, 120, 0>
	translate <20, 20, 60>
	texture { T_Green_Glass }
	interior { I_Glass }
	//finish { F_Glass7 }
}
*/
object {
	Pyramid2
	scale <500, 500, 500>
	rotate <0, 60, 0>
	translate <-55, 0, 850>
	texture { T_Stone22 }
}
