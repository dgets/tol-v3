/*
 * Let's try to see what we can do with the structure I had before;
 * after this has gone for awhile, I'll look back and see if it might be
 * possible to change it up as I've seen that it might fit better into
 * the sacred geometrical patterns with some modifications.
 */

//#include "stones.inc"
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
	<PX1 * Dist_Eqlt, 0, PZ1 * Dist_Eqlt>, Seph_Diam
	pigment { Col_Amethyst_03  }
}

#declare Chokhmah = sphere {
	/*
	 * Chokhmah or Chockmah
	 * Wisdom - the full Zodiac - Twos in Minor Arcana, Kings in the
	 * full court cards of the Tarot; the male, gray; the raw energy
	 * or 'fuel' of the All
	 */
	<PX2 * Dist_Eqlt, 0, PZ2 * Dist_Eqlt>, Seph_Diam
	texture { T_Stone8 }
}

#declare Binah = sphere {
	/*
	 * Binah
	 * Understanding - Saturn - Threes in Minor Arcana, Queens in
	 * the full court Tarot; the feminine, black; the 'engine' of
	 * substance in which the energy/fuel of Chokhmah is burned
	 */
	<PX3 * Dist_Eqlt, 0, PZ3 * Dist_Eqlt>, Seph_Diam
	texture { T_Stone15 }
}

#declare Atziluth = union {
	/*
	 * Atziluth
	 * The world of the Supernals - the Crown & Brow Chakra
	 */
	object { Keter }
	object { Chokhmah }
	object { Binah }
}

//pathways

/*
 * Second level triad & horizontal pathways
 */

//sephira
#declare Chesed = sphere {
	/*
	 * Chesed
	 * Loving kindness (Ahavah, 'love' of god and divine in all
	 * things
	 */
	<PX3 * Dist_Eqlt, 0, PZ3 * Dist_Eqlt>, Seph_Diam
	texture { T_Stone21  }
}

#declare Gevurah = sphere {
	/*
	 * Gevurah
	 * Might/severity (Yirah - 'fear' of god)
	 */
	<PX2 * Dist_Eqlt, 0, PZ2 * Dist_Eqlt>, Seph_Diam
	texture { T_Stone21 }
}

#declare Daat_struct = difference {
    sphere {
	/*
	 * Da'at
	 * Knowledge  (Yichud - Union; union with idea awakens emotions)
	 */
	<PX1 * Dist_Eqlt, 0, PZ1 * Dist_Eqlt>, Seph_Diam
    }
    sphere { <PX2 * Dist_Eqlt, 0, PZ2 * Dist_Eqlt>, 0.99 * Seph_Diam }
    interior { I_Glass }
    pigment { Col_Glass_Old }
}
/*  interior { I_Glass }
  pigment { Col_Glass_Old }
  /*light_source {
	<PX2 * Dist_Eqlt, 0, PZ2 * Dist_Eqlt>
	pigment { color White }
  }*/
} */

#declare Daat_light = light_source {
	<PX2 * Dist_Eqlt, 0, PZ2 * Dist_Eqlt>
	color White
}

#declare Daat = union {
	object { Daat_struct }
	object { Daat_light }
}

#declare Beriah = union {
	/*
	 * Beri'ah
	 * The intellectual understanding; the world of creation; need
	 * to look up the rest of the references heah after I plot the
	 * spheres & shit
	 */
	object { Chesed }
	object { Gevurah }
	object { Daat }
}

//so it looks like we still haven't dealt with one level (and the base) of
//the TOL

