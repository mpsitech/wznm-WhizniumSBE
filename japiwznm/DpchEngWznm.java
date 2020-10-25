/**
  * \file DpchEngWznm.java
  * Wznm Java API package engine dispatch block
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DpchEngWznm extends DpchWznm {

	public static final int SCRJREF = 1;
	
	public DpchEngWznm(
				int ixWznmVDpch
			) {
		super(ixWznmVDpch);
		
		scrJref = new String();
	};

	public String scrJref;
	
	public static boolean all(
				HashSet<Integer> items
			) {
		if (!items.contains(SCRJREF)) return false;

		return true;
	};
	
	public String getSrefsMask() {
		if (has(SCRJREF)) return("scrJref");
		
		return "";
	};
	
	public void readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		clear();
		
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, VecWznmVDpch.getSref(ixWznmVDpch));

		if (Xmlio.checkXPath(doc, basexpath)) {
			scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
		};
	};
};

