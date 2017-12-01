#include "shapes2.inc"
#include "glass_old.inc"

//tower sans cap
//cylinder placed at origin; 
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

//adding the previous one for now (this will still need to be
//translated)
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

#declare SteppedMount = merge {
 #declare BaseDim = 10;
 #declare StepHeight = 0.1;
 #declare TopBaseDim = 7.5;
 #declare Steps = 9;    //I like the solar system lol hehe xd xd 8-x
 #declare StepWidth = (BaseDim - TopBaseDim) / Steps;
 #declare CurStep = 1;
 
 #while (CurStep <= Steps)
  box { 
        <((BaseDim - (CurStep * StepWidth)) / -2),
         ((CurStep - 1) * StepHeight),
         ((BaseDim - (CurStep * StepWidth)) / -2)>,
        <((BaseDim - (CurStep * StepWidth)) / 2),
         (CurStep * StepHeight),
         ((BaseDim - (CurStep * StepWidth)) / 2)>
  }
  #declare CurStep = CurStep + 1;
 #end
}

//might as well have both types :D (extrapolate from above)
/* not finished yet */
#declare SteppedPyramid = merge {
  #local Steps = 10;
  #local BaseWidth = 15;
  #local TopBaseWidth = 1;
  #local StepLen = 1;
  #local StepHeight = 1;
  #local CurStep = 1;
  #local StepWidth = (BaseWidth - TopBaseWidth) / Steps;
  
  #while (CurStep < Steps)
    box {
	    <((BaseWidth - (CurStep * StepWidth)) / -2),    
	     ((CurStep - 1) * StepHeight),
	     ((BaseWidth - (CurStep * StepWidth)) / -2)>
	    <((BaseWidth - (CurStep * StepWidth)) / 2),
	     (CurStep * StepHeight),
	     ((BaseDim - (CurStep * StepWidth)) / 2)>
	}
	#declare CurStep = CurStep + 1;
  #end
}
        

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

//greek columns are always good
#declare GreekColumn = union {
 difference {
  #declare Col_Radius = 0.5;
  //primary column mass
  cylinder {
        <0, -5, 0>,
        <0, 5, 0>,
        Col_Radius
  }

  #declare Gouges = 20;
  #declare G_Depth = 0.1;       //this is also the 'etching' cylinder's
				//radius
  #declare CurGouge = 1;
  #while (CurGouge <= Gouges)
   #declare CurAng = (360 / Gouges) * CurGouge;
   cylinder {
        <0, -5, 0>,
        <0, 5, 0>,
        G_Depth
        translate <(cosd(CurAng) * Col_Radius), 0, (sind(CurAng) *
Col_Radius)>
   }
   #declare CurGouge = CurGouge + 1;
  #end
 }

 //end flare, now beveled nicely with torii
 difference {
  cylinder {
        <0, -5, 0>,
        <0, -5.1, 0>,
        (Col_Radius * 1.1)
  }

  torus {
        (Col_Radius * 1.1), 0.1
        translate <0, -4.95, 0>
  }
 }

 difference {
  cylinder {
        <0, 5.1, 0>,
        <0, 5, 0>,
        (Col_Radius * 1.1)
  }

  torus {
        (Col_Radius * 1.1), 0.1
        translate <0, 4.95, 0>
  }
 }
}

