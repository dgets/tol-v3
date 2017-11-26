#include "stones.inc"
#include "metals.inc"
#include "textures.inc"
#include "glass.inc"

//all origin centered objects for proper xformation and translation
//
//it may be helpful to note here that trigonometric functions start with 0 deg
//being found at the "3 o'clock" position, not "12 o'clock"
//
//also, rotation is "backwards" from the way I would expect it

#declare D1 = 270;
#declare D2 = 30;
#declare D3 = 150;
#declare PX1 = cosd(D1);
#declare PZ1 = sind(D1);
#declare PX2 = cosd(D2);
#declare PZ2 = sind(D2);
#declare PX3 = cosd(D3);
#declare PZ3 = sind(D3);

#declare Seph_Diam = 1;
#declare Dist_Eqlt = 3;	//just using this for now; we'll want to divide the
	//equilateral triad triangle properly for accurate distances later
#declare Cyl_Diam = Seph_Diam / 5;

#declare Triad = union {
	sphere {
		<PX1 * Dist_Eqlt, 0, PZ1 * Dist_Eqlt>
		Seph_Diam
		pigment { Brown_Agate }
	}

	sphere {
		<PX2 * Dist_Eqlt, 0, PZ2 * Dist_Eqlt>
		Seph_Diam
		texture { Blood_Marble }
	}

	sphere {
		<PX3 * Dist_Eqlt, 0, PZ3 * Dist_Eqlt>
		Seph_Diam
		texture { Sapphire_Agate }
	}
}

#declare Level_Triad_Join = union {
	cylinder {
		<PX1 * Dist_Eqlt, 0, PZ1 * Dist_Eqlt>,
		<PX2 * Dist_Eqlt, 0, PZ2 * Dist_Eqlt>,
		Cyl_Diam
		pigment { P_Chrome3 }
		finish { F_MetalB }
	}

	cylinder {
		<PX2 * Dist_Eqlt, 0, PZ2 * Dist_Eqlt>,
		<PX3 * Dist_Eqlt, 0, PZ3 * Dist_Eqlt>,
		Cyl_Diam
		pigment { P_Chrome3 }
		finish { F_MetalB }
	}

	cylinder {
		<PX3 * Dist_Eqlt, 0, PZ3 * Dist_Eqlt>,
		<PX1 * Dist_Eqlt, 0, PZ1 * Dist_Eqlt>,
		Cyl_Diam
		pigment { P_Chrome3 }
		finish { F_MetalB }
	}
}

#declare Tri_Lev = union {
  object {
	Triad
  }
  object {
	Level_Triad_Join
  }
}

#declare Nine_Seph = union {
  //note this is lacking all pathways except for the 'horizontal'

  //'top'
  object {
	Tri_Lev
	translate y*4.5
  }

  //'down', 1st above origin
  object {
	Tri_Lev
	translate y*1.5
  }

  //1st below origin
  object {
	Tri_Lev
	translate y*-1.5
  }
}

#declare Ten_Web = union {
  //this is the web framework that consists of non-horizontal pathways to all
  //sephiroth except for the crown

  //verticals
  cylinder {
	<PX1 * 3, 4.5, PZ1 * 3>,
	<PX1 * 3, -1.5, PZ1 * 3>,
	Cyl_Diam
	pigment { P_Brass2 }
	finish { F_MetalC }
  }

  cylinder {
	<PX2 * 3, 4.5, PZ2 * 3>,
	<PX2 * 3, -1.5, PZ2 * 3>,
	Cyl_Diam
	pigment { P_Brass2 }
	finish { F_MetalC }
  }

  cylinder {
	<PX3 * 3, 4.5, PZ3 * 3>,
	<PX3 * 3, -1.5, PZ3 * 3>,
	Cyl_Diam
	pigment { P_Silver2 }
	finish { F_MetalC }
  }

  //corners to front
  cylinder {
	<PX1 * 3, 1.5, PZ1 * 3>,
	<PX2 * 3, 4.5, PZ2 * 3>,
	Cyl_Diam
	pigment { P_Copper2 }
	finish { F_MetalB }
  }

  cylinder {
	<PX1 * 3, 1.5, PZ1 * 3>,
	<PX3 * 3, 4.5, PZ3 * 3>,
	Cyl_Diam
	pigment { P_Copper2 }
	finish { F_MetalB }
  }

  cylinder {
	<PX1 * 3, 1.5, PZ1 * 3>,
	<PX2 * 3, -1.5, PZ2 * 3>,
	Cyl_Diam
	pigment { P_Copper2 }
	finish { F_MetalB }
  }

  cylinder {
	<PX1 * 3, 1.5, PZ1 * 3>,
	<PX3 * 3, -1.5, PZ3 * 3>,
	Cyl_Diam
	pigment { P_Copper2 }
	finish { F_MetalB }
  }

  //bottom tier to 'crown'
  cylinder {
	<PX1 * 3, -1.5, PZ1 * 3>,
	<0, -4.5, 0>,
	Cyl_Diam
	pigment { P_Chrome1 }
	finish { F_MetalD }
  }

  cylinder {
	<PX2 * 3, -1.5, PZ2 * 3>,
	<0, -4.5, 0>,
	Cyl_Diam
	pigment { P_Chrome1 }
	finish { F_MetalD }
  }

  cylinder {
	<PX3 * 3, -1.5, PZ3 * 3>,
	<0, -4.5, 0>,
	Cyl_Diam
	pigment { P_Chrome1 }
	finish { F_MetalD }
  }
}

#declare TOL = union {
  //NOTE: this is missing the 'crown' sephiroth
  object {
	Nine_Seph
  }

  object {
	Ten_Web
  }
}

//Testing shit
//#declare Test_Triad1 = union {
  //just testing to see if I've got my (steak)(li) wrapped around trig. still
  //sphere { <cosd(270) * 3, sind(270) * 3, 0> 1 texture { T_Stone1 } }
  //sphere { <cosd(30) * 3, sind(30) * 3, 0> 1 texture { T_Stone2 } }
  //sphere { <cosd(150) * 3, sind(150) * 3, 0> 1 texture { T_Stone3 } }

  //orientation sphere (thirty degree trigonometric function base)
  //sphere { <cosd(-30) * 3, sind(-30) * 3, 0> 1 pigment { color Blue } }
//}

/* vesica pisces
 * we're going to try to create the 'flower of life' (and quite possibly
 * extend it into the 'seed of life' later) by creating the first form out of
 * circles and CSGs.  The 2-d form is created by 7 circles; one at the center
 * and 6 radiating out from its center, with radii tangental to the center of
 * the first, skewed by 60 degrees apiece.  Three dimensional will take this
 * into account with two more forms of the first 2-d form, each rotated in the
 * y-axis by 60 degrees to complete the sphere
 */

#declare VesicaPisces = intersection {
	sphere {
	  <-2, 0, 0>, 3
	}
	sphere {
	  <2, 0, 0>, 3
	}
}

#declare VPEye = union {
  difference { //create the hollow 'eye'
    object {
	VesicaPisces
	rotate <0, 0, 90>
    }
    object {
	VesicaPisces
	scale <0.99, 0.99, 0.99>
	rotate <0, 0, 90>
    }
    pigment { Col_Glass_Clear }
    interior { I_Glass }
    finish { F_Glass7 }
  }

  difference { //iris
    sphere {
	<0, 0, 0>, 0.99
    }
    sphere {
	<0, 0, 0>, 0.98
    }
    pigment { Col_Glass_General }
    interior { I_Glass }
    finish { F_Glass7 }
  }

  light_source {
	<0, 0, 0>
	color Red
	looks_like {  object {
			    VesicaPisces
			    scale <0.25, 0.25, 0.25>
			    //pigment { color Black }
	  }
	}
  }
}

/* DEBUG: This is buggy as HELL */

#declare FlowerOfLife = union {
 #local RotAng = 0;
 #while (RotAng <= 359)
  object {
	VesicaPisces
	rotate <0, 0, RotAng + 270>
	translate <cosd(RotAng) * 2, sind(RotAng) * 2, 0>
  }
  #declare RotAng = RotAng + 60;
 #end
}

//DNA Molecule
#declare DNAStrand = union {
 #local MolRad = 0.025;
 #local JoinRad = 0.05 / 6;
 #local JoinLen = 0.5;

 #local Length = 10;
 #local TwistPerUnit = 0.5;
 #local IncPerTwist = 6;
 #local Step = 0;
 #local StepInc = 1 / (IncPerTwist / TwistPerUnit);
 #local StepDeg = (360 / TwistPerUnit) / IncPerTwist;
 #while ((Step * StepInc) <= 10)
  sphere {
	<(cosd(StepDeg * Step) * JoinLen),
	 (sind(StepDeg * Step) * JoinLen),
	 (0 + StepInc)>,
	MolRad
	pigment { color Blue }
  }
  sphere {
	<(-cosd(StepDeg * Step) * JoinLen),
	 (-sind(StepDeg * Step) * JoinLen),
	 (0 + StepInc)>,
	MolRad
	pigment { color Yellow }
  }
  #if (Step != 0)
   //do one for the above 0[y] coord, one for below
   sphere {
        <(cosd(StepDeg * Step) * JoinLen),
         (sind(StepDeg * Step) * JoinLen),
         (0 - StepInc)>,
        MolRad
        pigment { color Blue }
   }
   sphere {
        <(-cosd(StepDeg * Step) * JoinLen),
         (-sind(StepDeg * Step) * JoinLen),
         (0 - StepInc)>,
        MolRad
        pigment { color Yellow }
   }
  #end
  #if ((Step / 2) = 0)
   //this one will have a joining bridge
   cylinder {
	<(cosd(StepDeg * Step) * JoinLen),
	 (sind(StepDeg * Step) * JoinLen),
	 (0 + StepInc)>,
	<(-cosd(StepDeg * Step) * JoinLen),
	 (-sind(StepDeg * Step) * JoinLen),
	 (0 + StepInc)>,
	JoinRad
	texture { Gold_Nugget }
   }
   #if (Step != 0)
    cylinder {
	<(cosd(StepDeg * Step) * JoinLen),
         (sind(StepDeg * Step) * JoinLen),
         (0 - StepInc)>,
        <(-cosd(StepDeg * Step) * JoinLen),
         (-sind(StepDeg * Step) * JoinLen),
         (0 - StepInc)>,
        JoinRad
        texture { Gold_Nugget }
    }
   #end
  #end
  #declare Step = Step + 1;
 #end
}


