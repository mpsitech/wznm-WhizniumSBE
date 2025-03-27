/**
	* \file WznmQVisLinkctx.java
	* Java API code for record of table TblWznmQVisLinkctx
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQVisLinkctx {
	
	public WznmQVisLinkctx(
				int jnum
				, int orgClk
				, int dstClk
				, int Weight
				, int jnumBoxOrg
				, int jnumBoxDst
				, String Title
				, String Content1
				, String Content2
			) {
		this.jnum = jnum;
		this.orgClk = orgClk;
		this.dstClk = dstClk;
		this.Weight = Weight;
		this.jnumBoxOrg = jnumBoxOrg;
		this.jnumBoxDst = jnumBoxDst;
		this.Title = Title;
		this.Content1 = Content1;
		this.Content2 = Content2;
	};

	public int jnum;
	public int orgClk;
	public int dstClk;
	public int Weight;
	public int jnumBoxOrg;
	public int jnumBoxDst;
	public String Title;
	public String Content1;
	public String Content2;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQVisLinkctx");

		if (Xmlio.checkXPath(doc, basexpath)) {
			orgClk = Xmlio.extractIntegerUclc(doc, basexpath, "orgClk", "ocl", null, 0);
			dstClk = Xmlio.extractIntegerUclc(doc, basexpath, "dstClk", "dcl", null, 0);
			Weight = Xmlio.extractIntegerUclc(doc, basexpath, "Weight", "wgt", null, 0);
			jnumBoxOrg = Xmlio.extractIntegerUclc(doc, basexpath, "jnumBoxOrg", "", null, 0);
			jnumBoxDst = Xmlio.extractIntegerUclc(doc, basexpath, "jnumBoxDst", "", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			Content1 = Xmlio.extractStringUclc(doc, basexpath, "Content1", "cnt1", null, 0);
			Content2 = Xmlio.extractStringUclc(doc, basexpath, "Content2", "cnt2", null, 0);
			
			return true;
		};

		return false;
	};
};
