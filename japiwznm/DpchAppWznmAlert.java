/**
  * \file DpchAppWznmAlert.java
  * Wznm Java API package alert app dispatch block
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DpchAppWznmAlert extends DpchAppWznm {

	public static final int SCRJREF = 1;
	public static final int NUMFMCB = 2;
	public static final int ALL = 3;

	public DpchAppWznmAlert(
				String scrJref
				, int numFMcb
				, Integer[] mask
			) {
		super(VecWznmVDpch.DPCHAPPWZNMALERT, scrJref);

		this.numFMcb = numFMcb;

		for (Integer i: mask)
			if (i == ALL) {
				this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, NUMFMCB));
				return;
			};

		this.mask = new HashSet<Integer>(Arrays.asList(mask));
	};
	
	public int numFMcb;

	public static boolean all(
				HashSet<Integer> items
			) {
		if (!items.contains(SCRJREF)) return false;
		if (!items.contains(NUMFMCB)) return false;
	
		return true;
	};
	
	public String getSrefsMask() {
		ArrayList<String> ss = new ArrayList<String>();
		
		if (has(SCRJREF)) ss.add("scrJref");
		if (has(NUMFMCB)) ss.add("numFMcb");
	
		return StrMod.vectorToString(ss, ';');
	};

	public void writeXML(
				Document doc
				, Element sup
			) {
		Element el = doc.createElement("DpchAppWznmAlert");
	
		if (sup == null) doc.appendChild(el);
		else sup.appendChild(el);
	
		el.setAttribute("xmlns", "http://www.mpsitech.com/wznm");
		
		if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
		if (has(NUMFMCB)) Xmlio.writeInteger(doc, el, "numFMcb", numFMcb);
	};
};

