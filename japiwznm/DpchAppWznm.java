/**
	* \file DpchAppWznm.java
	* Wznm Java API package app dispatch block
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DpchAppWznm extends DpchWznm {

	public static final int SCRJREF = 1;
	
	public DpchAppWznm(
				int ixWznmVDpch
				, String scrJref
			) {
		super(ixWznmVDpch);
		
		this.scrJref = scrJref;
		
		mask = new HashSet<Integer>(Arrays.asList(SCRJREF));
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
	
	public void writeXML(
				Document doc
				, Element sup
			) {
		Element el = doc.createElement(VecWznmVDpch.getSref(ixWznmVDpch));

		if (sup == null) doc.appendChild(el);
		else sup.appendChild(el);

		el.setAttribute("xmlns", "http://www.mpsitech.com/wznm");
		
		if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
	};
};
