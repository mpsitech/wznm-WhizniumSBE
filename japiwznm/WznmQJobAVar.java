/**
	* \file WznmQJobAVar.h
	* Java API code for record of table TblWznmQJobAVar
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQJobAVar {
	
	public WznmQJobAVar(
				int jnum
				, String sref
				, String srefIxWznmVVartype
				, String titIxWznmVVartype
				, String stubRefWznmMVector
				, int Length
				, String yesnoShr
				, String Comment
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxWznmVVartype = srefIxWznmVVartype;
		this.titIxWznmVVartype = titIxWznmVVartype;
		this.stubRefWznmMVector = stubRefWznmMVector;
		this.Length = Length;
		this.yesnoShr = yesnoShr;
		this.Comment = Comment;
	};

	public int jnum;
	public String sref;
	public String srefIxWznmVVartype;
	public String titIxWznmVVartype;
	public String stubRefWznmMVector;
	public int Length;
	public String yesnoShr;
	public String Comment;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQJobAVar");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxWznmVVartype = Xmlio.extractStringUclc(doc, basexpath, "srefIxWznmVVartype", "vty", null, 0);
			titIxWznmVVartype = Xmlio.extractStringUclc(doc, basexpath, "titIxWznmVVartype", "vty2", null, 0);
			stubRefWznmMVector = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVector", "vec", null, 0);
			Length = Xmlio.extractIntegerUclc(doc, basexpath, "Length", "len", null, 0);
			yesnoShr = Xmlio.extractStringUclc(doc, basexpath, "yesnoShr", "shr", null, 0);
			Comment = Xmlio.extractStringUclc(doc, basexpath, "Comment", "cmt", null, 0);
			
			return true;
		};

		return false;
	};
};

