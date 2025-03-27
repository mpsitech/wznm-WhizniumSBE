/**
	* \file WznmQVisBoxctx.java
	* Java API code for record of table TblWznmQVisBoxctx
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQVisBoxctx {
	
	public WznmQVisBoxctx(
				int jnum
				, String stubUnvUref
				, int x
				, int y
				, String jnumsSub
				, String jnumsLink
				, int w
				, int h
				, String Content1
				, String Content2
			) {
		this.jnum = jnum;
		this.stubUnvUref = stubUnvUref;
		this.x = x;
		this.y = y;
		this.jnumsSub = jnumsSub;
		this.jnumsLink = jnumsLink;
		this.w = w;
		this.h = h;
		this.Content1 = Content1;
		this.Content2 = Content2;
	};

	public int jnum;
	public String stubUnvUref;
	public int x;
	public int y;
	public String jnumsSub;
	public String jnumsLink;
	public int w;
	public int h;
	public String Content1;
	public String Content2;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQVisBoxctx");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubUnvUref = Xmlio.extractStringUclc(doc, basexpath, "stubUnvUref", "stubUnv", null, 0);
			x = Xmlio.extractIntegerUclc(doc, basexpath, "x", "x", null, 0);
			y = Xmlio.extractIntegerUclc(doc, basexpath, "y", "y", null, 0);
			jnumsSub = Xmlio.extractStringUclc(doc, basexpath, "jnumsSub", "sub", null, 0);
			jnumsLink = Xmlio.extractStringUclc(doc, basexpath, "jnumsLink", "lnk", null, 0);
			w = Xmlio.extractIntegerUclc(doc, basexpath, "w", "w", null, 0);
			h = Xmlio.extractIntegerUclc(doc, basexpath, "h", "h", null, 0);
			Content1 = Xmlio.extractStringUclc(doc, basexpath, "Content1", "cnt1", null, 0);
			Content2 = Xmlio.extractStringUclc(doc, basexpath, "Content2", "cnt2", null, 0);
			
			return true;
		};

		return false;
	};
};
