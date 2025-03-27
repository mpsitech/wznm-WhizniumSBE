/**
	* \file WznmQVisRowctx.java
	* Java API code for record of table TblWznmQVisRowctx
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQVisRowctx {
	
	public WznmQVisRowctx(
				int jnum
				, int jnumBox
				, String Content1
				, String Content2
				, String Content3
			) {
		this.jnum = jnum;
		this.jnumBox = jnumBox;
		this.Content1 = Content1;
		this.Content2 = Content2;
		this.Content3 = Content3;
	};

	public int jnum;
	public int jnumBox;
	public String Content1;
	public String Content2;
	public String Content3;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQVisRowctx");

		if (Xmlio.checkXPath(doc, basexpath)) {
			jnumBox = Xmlio.extractIntegerUclc(doc, basexpath, "jnumBox", "", null, 0);
			Content1 = Xmlio.extractStringUclc(doc, basexpath, "Content1", "cnt1", null, 0);
			Content2 = Xmlio.extractStringUclc(doc, basexpath, "Content2", "cnt2", null, 0);
			Content3 = Xmlio.extractStringUclc(doc, basexpath, "Content3", "cnt3", null, 0);
			
			return true;
		};

		return false;
	};
};
