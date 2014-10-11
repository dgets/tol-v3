#include "colors.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "glass.inc"
#include "metals.inc"
#include "finish.inc"

//merkaba
#declare TetrahedronScaleFactor = (1 / 6);
#declare Tetrahedron_Hollow = difference {
  object { Tetrahedron }
  object {
	Tetrahedron
	scale <0.99, 0.99, 0.99>
  }
  //original Tetrahedrons are bounded by a sphere of radius 3
  scale <TetrahedronScaleFactor, 
	 TetrahedronScaleFactor, 
	 TetrahedronScaleFactor>
}

#declare MerkabaUnlit = union {
  object {
    Tetrahedron_Hollow
    texture { T_Yellow_Glass }
    interior { I_Glass }
  }
  object {
    Tetrahedron_Hollow
    rotate <180, 0, 0>
    texture { T_Green_Glass }
    interior { I_Glass }
  }
}

#declare MerkabaLit = union {
  light_source {
    <0, 0, 0> color Yellow
    looks_like {
      object {	//pointed up
	Tetrahedron_Hollow
	texture { T_Yellow_Glass }
	interior { I_Glass }
      }
    }
  }
  light_source {
    <0, 0, 0> color Green
    looks_like {
      object {	//pointed down
	Tetrahedron_Hollow
	rotate <180, 0, 0>
	texture { T_Green_Glass }
	interior { I_Glass }
      }
    }
  }
}



#declare MerkabaGlobe = difference {
  sphere {
    <0, 0, 0>, 0.5
  }
  sphere {
    <0, 0, 0>, 0.49
  }
  texture { T_Glass1 }
  interior { I_Glass }
}

//merkaba w/internal light
#declare Merkaba = union {
  /* going to make an attempt to light the actual object of the internal
 * star
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

  /*
  //let's add a thin, hollow sphere around this merkaba
  difference {
    sphere {
        <0, 0, 0>, (15.5 / 5)   //ugly adjust for previous hardcode &
scale
    }
    sphere {
        <0, 0, 0>, (15.49 / 5)  //ugly adjust for previous hardcode &
scale
    }
    texture { T_Glass1 }
    interior { I_Glass }
  }
  */
}


