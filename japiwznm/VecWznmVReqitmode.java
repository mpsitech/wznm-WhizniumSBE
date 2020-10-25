/**
  * \file VecWznmVReqitmode.java
  * vector VecWznmVReqitmode
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

public class VecWznmVReqitmode {
	public static final int IDLE = 1;
	public static final int NOTIFY = 2;
	public static final int POLL = 3;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("idle")) return IDLE;
		if (s.equals("notify")) return NOTIFY;
		if (s.equals("poll")) return POLL;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == IDLE) return("idle");
		if (ix == NOTIFY) return("notify");
		if (ix == POLL) return("poll");

		return "";
	};

};

