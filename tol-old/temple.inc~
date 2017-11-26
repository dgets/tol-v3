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
  #declare G_Depth = 0.1;	//this is also the 'etching' cylinder's radius
  #declare CurGouge = 1;
  #while (CurGouge <= Gouges)
   #declare CurAng = (360 / Gouges) * CurGouge;
   cylinder {
	<0, -5, 0>,
	<0, 5, 0>,
	G_Depth
	translate <(cosd(CurAng) * Col_Radius), 0, (sind(CurAng) * Col_Radius)>
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

#declare SteppedMount = merge {
 #declare BaseDim = 10;
 #declare StepHeight = 0.1;
 #declare TopBaseDim = 7.5;
 #declare Steps = 9;	//I like the solar system lol hehe xd xd 8-x
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

//so we're working with a 7.5x7.5 platform with the top edge @ 0.9 units
//currently; let's place some columns
#declare OpenTemple = union {
  object {
	SteppedMount
  }

  //remember the pillars are 10.2 in height and 1.1 in width w/flares, centered
  //exactly at the origin
  #local ColBase = 6;
  object {	//front, far left
	GreekColumn
	translate <-3.15, ColBase, -3.15>
  }

  object {	//front, far right
	GreekColumn
	translate <3.15, ColBase, -3.15>
  }

  object {	//front, 2nd from left
	GreekColumn
	translate <-1.15, ColBase, -3.15>
  }

  object {	//front, 2nd from right
	GreekColumn
	translate <1.15, ColBase, -3.15>
  }

  //do some heading backwards on each side
  object {	//left, 2nd back
	GreekColumn
	translate <-3.15, ColBase, -1.15>
  }

  object {	//right, 2nd back
	GreekColumn
	translate <3.15, ColBase, -1.15>
  }

  object {	//left, 3rd back
	GreekColumn
	translate <-3.15, ColBase, 1.15>
  }

  object {	//right, 3rd back
	GreekColumn
	translate <3.15, ColBase, 1.15>
  }

  //rear row
  object {	//far left
	GreekColumn
	translate <-3.15, ColBase, 3.15>
  }

  object {	//2nd fm. left
	GreekColumn
	translate <-1.15, ColBase, 3.15>
  }

  object {	//2nd fm. right
	GreekColumn
	translate <1.15, ColBase, 3.15>
  }

  object {	//far right
	GreekColumn
	translate <3.15, ColBase, 3.15>
  }

  //let's put a roof on dis suckah; for now just a simple 4side pyramid
  object {
	Pyramid
	scale <5.5, 2, 5.5>
	translate <0, 13.2, 0>
  }

}

