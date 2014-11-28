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

/*
 * Top level triad & 'horizontal' pathways
 */

//sephira
#declare Keter = sphere {
	/*
	 * Keter or Kether
	 * The Crown - the Big Bang - Aces in the Minor Arcana
	 */
	<PX2 * Dist_Eqlt, 0, PZ2 * Dist_Eqlt>, Seph_Diam
	pigment { Med_Purple }
}

#declare Chokhmah = sphere {
	/*
	 * Chokhmah or Chockmah
	 * Wisdom - the full Zodiac - Twos in Minor Arcana, Kings in the
	 * full court cards of the Tarot; the male, gray; the raw energy
	 * or 'fuel' of the All
	 */
	<PX3 * Dist_Eqlt, 0, PZ3 * Dist_Eqlt>, Seph_Diam
	texture { T_Grnt9 }
}

#declare Binah = sphere {
	/*
	 * Binah
	 * Understanding - Saturn - Threes in Minor Arcana, Queens in
	 * the full court Tarot; the feminine, black; the 'engine' of
	 * substance in which the energy/fuel of Chokhmah is burned
	 */
	<PX1 * Dist_Eqlt, 0, PZ1 * Dist_Eqlt>, Seph_Diam
	texture { T_Grnt15 }
}

#declare Top_Triad = union {
	object { Keter }
	object { Chokhmah }
	object { Binah }
}

//pathways

