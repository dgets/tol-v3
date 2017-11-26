#include "shapes2.inc"
#include "glass_old.inc"

//hollow out the tetrahedron from shapes2.inc
#declare Tetrahedron_Hollow = difference {
  object {
        Tetrahedron
  }
  object {
        Tetrahedron
        scale <0.99, 0.99, 0.99>
  }
}

//merkaba and other misc. objects
//merkaba w/internal light
#declare Merkaba = union {
  /* going to make an attempt to light the actual object of the internal star
     star tetrahedron to achieve a better effect
   light_source {
        <0, 0, 0>
        color White
   }
  */

  light_source {
    <0, 0, 0> color Yellow
    looks_like {
	object {        //pointed up
          Tetrahedron_Hollow
          //scale <5, 5, 5>
          //translate <45, 20, 60>
          texture { T_Yellow_Glass }
          interior { I_Glass }
          //finish { F_Glass8 }
  	}
    }
  }
  light_source {
    <0, 0, 0> color Green
    looks_like { 
	object {        //pointed down
          Tetrahedron_Hollow
          //scale <5, 5, 5>
          rotate <180, 0, 0>
          //translate <45, 20, 60>
          texture { T_Green_Glass }
          interior { I_Glass }
          //finish { F_Glass7 }
	}
    }
  }

  //let's add a thin, hollow sphere around this merkaba
 /*
  difference {
    sphere {
        <0, 0, 0>, (15.5 / 5)	//ugly adjust for previous hardcode & scale
    }
    sphere {
        <0, 0, 0>, (15.49 / 5)	//ugly adjust for previous hardcode & scale
    }
    texture { T_Glass1 }
    interior { I_Glass }
  }
 */
}

//tower sans cap
#declare TowerBody = difference {
  #local TStep = 0.2;
  #local ApetureBottom = -5;
  #local ApRot = 0;
  cylinder {
	<0, 5, 0>,
	<0, -5, 0>, 0.75
  }
  cylinder {
	<0, 5.1, 0>,
	<0, -5.1, 0>, 0.745
  }
  #while (ApetureBottom <= 4.5)
    box {
	<-0.05, ApetureBottom, -0.8>,
	<0.05, (ApetureBottom + 0.5), 0.8>
	rotate <0, ApRot, 0>
    }
    #declare ApetureBottom = ApetureBottom + TStep;
    #declare ApRot = ApRot + 32;
  #end
}

//tower cap
#declare TCap = difference {
  cylinder {
	<0, 5.25, 0>,
	<0, 5, 0>, 0.825
  }
  cylinder {
	<0, 5.26, 0>,
	<0, 4.99, 0>, 0.735
  }
  #local ApRot = 0;
  #while (ApRot < 360)
    box {
	<-0.08, 5.1, -1>,
	<0.08, 5.26, 1>
	rotate <0, ApRot, 0>
    }
    #declare ApRot = ApRot + 30;
  #end
} 

#declare Tower = union {
  object { TowerBody }
  object { TCap }
}

//modified Apocalypse for sky_sphere
#declare MyApocalypse = 
pigment {
    bozo
    turbulence 1.5
    color_map {
        [0.0 rgb <0.8, 0.0, 0.0>]
        [0.4 rgb <0.4, 0.0, 0.4>]
        [0.6 rgb <0.0, 0.0, 0.2>]
        [1.0 rgb 0.0]
    }
}

//double helix approximation using shapesq.inc's helix
//note this is not including any 'steps' for use in a pseudo-DNA molecule form
/*  putting this on hold until I understand it a little better 
#declare D_Helix = difference {
  union {

*/

//for use primarily in carving out windows in 'difference' structures with
//rounded tops instead of just rectangular prism forms
#declare ArchToppedCyl = union {
  cylinder {
	<0, -1, 0>,
	<0, 1, 0>,
	(2 / 3)
  }
  sphere {
	<0, 1, 0>, (2 / 3)
  }
}

//might as well have both types :D
/* not finished yet
#declare SteppedPyramid = union {
  #local Steps = 10;
  #local BaseWidth = 15;
  #local StepLen = 1;
  #local StepHeight = 1;
  #local CurStep = 0;
  #while (CurStep < Steps)
    box {
	<-((BaseWidth - CurStep) / 2), 

*/

//crystal spire
#declare XtalSpire = union {
  //note when translating/scaling this is -1.5 through 1.5 in y (3 tall total)
  //note width (X/Z coordinates) or height need to be fixed as this is FAT
  prism {
	linear_sweep
	linear_spline
	-1.5,
	0.5,
	7,	//total # of points, this is hexagonal prism (7 pts to close)
	<3,5>, <-3,5>, <-5,0>, <-3,-5>, <3, -5>, <5,0>, <3,5>
  }
  //now we need one with a conic sweep to cap with a pointed prism
  //must start at the origin, though
  prism {
	conic_sweep
	linear_spline
	0,
	-1,
	7,
	<3,5>, <-3,5>, <-5,0>, <-3,-5>, <3, -5>, <5,0>, <3,5>
	//rotate <0, 0, 180>	what the fuck is wrong with this?
	translate <0, 1.5, 0>
  }
  scale <0.125, 1, 0.125>
}

#declare ZodiacCross = merge {
  difference {
    sphere {
	<0, 0, 0>, 3
    }
    sphere {
	<0, 0, 0>, 2
    }
  }

  //crossmembers (remember this is in 3 dimensions, not 2)
  box {
    <-5, 0.5, -0.5>,
    <5, -0.5, 0.5>
  }
  box {
    <-0.5, 5, -0.5>,
    <0.5, -5, 0.5>
  }
  box {
    <-0.5, 0.5, -5>,
    <0.5, -0.5, 5>
  }

  //end poles
  box {	//left
    <-5.5, 1, -1>,
    <-5, -1, 1>
  }
  box { //right
    <5, 1, -1>,
    <5.5, -1, 1>
  }
  box { //top
    <-1, 5.5, -1>,
    <1, 5, 1>
  }
  box { //bottom
    <-1, -5, -1>,
    <1, -5.5, 1>
  }
  box { //close
    <-1, 1, -5.5>,
    <1, -1, -5>
  }
  box { //far
    <-1, 1, 5>,
    <1, -1, 5.5>
  }
}

