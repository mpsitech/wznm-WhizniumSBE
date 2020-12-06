/**
	* \file DpchEngWznmAlert.java
	* Wznm Java API package alert engine dispatch block
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DpchEngWznmAlert extends DpchEngWznm {

	public static final int SCRJREF = 1;
	public static final int CONTINF = 2;
	public static final int FEEDFMCB = 3;

	public DpchEngWznmAlert() {
		super(VecWznmVDpch.DPCHENGWZNMALERT);
		
		continf = new ContInfWznmAlert("", "", "", "", "", "", "", "", "", "", "", "", "");
		feedFMcb = new Feed("FeedFMcb");
	};

	public ContInfWznmAlert continf;
	public Feed feedFMcb;

	public static boolean all(
				HashSet<Integer> items
			) {
		if (!items.contains(SCRJREF)) return false;
		if (!items.contains(CONTINF)) return false;
		if (!items.contains(FEEDFMCB)) return false;
	
		return true;
	};

	public String getSrefsMask() {
		ArrayList<String> ss = new ArrayList<String>();

		if (has(SCRJREF)) ss.add("scrJref");
		if (has(CONTINF)) ss.add("continf");
		if (has(FEEDFMCB)) ss.add("feedFMcb");

		return StrMod.vectorToString(ss, ';');
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
			if (continf.readXML(doc, basexpath, true)) add(CONTINF);
			if (feedFMcb.readXML(doc, basexpath, true)) add(FEEDFMCB);
		} else {
			continf = new ContInfWznmAlert("", "", "", "", "", "", "", "", "", "", "", "", "");
			feedFMcb.clear();
		};
	};
};
