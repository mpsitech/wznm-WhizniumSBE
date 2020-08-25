/**
  * \file VecWznmVBasereptype.java
  * vector VecWznmVBasereptype
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

public class VecWznmVBasereptype {
	public static final int VOID = 1;
	public static final int PRJGIT = 2;
	public static final int CUSTGIT = 3;
	public static final int ULD = 4;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("void")) return VOID;
		if (s.equals("prjgit")) return PRJGIT;
		if (s.equals("custgit")) return CUSTGIT;
		if (s.equals("uld")) return ULD;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == VOID) return("void");
		if (ix == PRJGIT) return("prjgit");
		if (ix == CUSTGIT) return("custgit");
		if (ix == ULD) return("uld");

		return "";
	};

};

