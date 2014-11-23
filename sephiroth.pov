/*
 * Let's try to see what we can do with the structure I had before;
 * after this has gone for awhile, I'll look back and see if it might be
 * possible to change it up as I've seen that it might fit better into
 * the sacred geometrical patterns with some modifications.
 */

#include "stones.inc"
#include "metals.inc"
#include "textures.inc"
#include "glass.inc"

#declare Seph_Diam = 1;
#declare Dist_Eqlt = 3; //just using this for now; we'll want to divide
        //the equilateral triad triangle properly for accurate distances
        //later
#declare Cyl_Diam = Seph_Diam / 5;

#declare D1 = 270;
#declare D2 = 30;
#declare D3 = 150;
#declare PX1 = cosd(D1);
#declare PZ1 = sind(D1);
#declare PX2 = cosd(D2);
#declare PZ2 = sind(D2);
#declare PX3 = cosd(D3);
#declare PZ3 = sind(D3);

#declare Binah = sphere {

