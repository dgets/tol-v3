#include "shapes.inc"
#include "colors.inc"

#declare Iterations = 12;	//spheres to use in the 'nautilus'
#declare StartSize = 6;		//beginning sphere radius
#declare FinishSize = 2;	//ending sphere radius
#declare SizeStep = (StartSize - FinishSize) / Iterations;
#declare DegStep = 270 / Iterations;
#declare CurDeg = 0;
#declare CurSize = StartSize;
#declare CurIt = 1;

#declare Nautilus = union {
  #while (CurIt <= Iterations)
    sphere {
	<0, 0, 0>, CurSize
	translate <0, (sind(CurDeg) * CurSize), (cosd(CurDeg) * CurSize)>
    }
    #declare CurSize = CurSize - SizeStep;
    #declare CurDeg = CurDeg + DegStep;
    #declare CurIt = CurIt + 1;
  #end
}

