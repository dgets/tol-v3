/* vesica pisces
 * we're going to try to create the 'flower of life' (and quite possibly
 * extend it into the 'seed of life' later) by creating the first form
 * out of
 * circles and CSGs.  The 2-d form is created by 7 circles; one at the
 * center
 * and 6 radiating out from its center, with radii tangental to the
 * center of
 * the first, skewed by 60 degrees apiece.  Three dimensional will take
 * this
 * into account with two more forms of the first 2-d form, each rotated
 * in the
 * y-axis by 60 degrees to complete the sphere
 */

//properly centered
#declare VesicaPisces = intersection {
        sphere {
          <-2, 0, 0>, 3
        }
        sphere {
          <2, 0, 0>, 3
        }
}

//centered
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
        looks_like {
	  object {
            VesicaPisces
            scale <0.25, 0.25, 0.25>
            //pigment { color Black }
          }
        }
  }
}

/*
 * Flower of Life 
 * DEBUG: This is buggy as HELL
 */

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

