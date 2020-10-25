/**
  * \file WznmQBlkAItem.h
  * Java API code for record of table TblWznmQBlkAItem
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQBlkAItem {
	
	public WznmQBlkAItem(
				int jnum
				, String srefIxVBasetype
				, String titIxVBasetype
				, String sref
				, String srefIxWznmVVartype
				, String titIxWznmVVartype
				, String stubRefWznmMControl
				, String stubRefWznmMVector
				, String stubRefWznmMFeed
				, String stubRefWznmMTable
				, String stubRefWznmMBlock
				, String Defval
				, String stubRefWznmMVectoritem
				, String Comment
			) {
		this.jnum = jnum;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.sref = sref;
		this.srefIxWznmVVartype = srefIxWznmVVartype;
		this.titIxWznmVVartype = titIxWznmVVartype;
		this.stubRefWznmMControl = stubRefWznmMControl;
		this.stubRefWznmMVector = stubRefWznmMVector;
		this.stubRefWznmMFeed = stubRefWznmMFeed;
		this.stubRefWznmMTable = stubRefWznmMTable;
		this.stubRefWznmMBlock = stubRefWznmMBlock;
		this.Defval = Defval;
		this.stubRefWznmMVectoritem = stubRefWznmMVectoritem;
		this.Comment = Comment;
	};

	public int jnum;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String sref;
	public String srefIxWznmVVartype;
	public String titIxWznmVVartype;
	public String stubRefWznmMControl;
	public String stubRefWznmMVector;
	public String stubRefWznmMFeed;
	public String stubRefWznmMTable;
	public String stubRefWznmMBlock;
	public String Defval;
	public String stubRefWznmMVectoritem;
	public String Comment;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQBlkAItem");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxWznmVVartype = Xmlio.extractStringUclc(doc, basexpath, "srefIxWznmVVartype", "vty", null, 0);
			titIxWznmVVartype = Xmlio.extractStringUclc(doc, basexpath, "titIxWznmVVartype", "vty2", null, 0);
			stubRefWznmMControl = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMControl", "con", null, 0);
			stubRefWznmMVector = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVector", "vec", null, 0);
			stubRefWznmMFeed = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMFeed", "fed", null, 0);
			stubRefWznmMTable = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMTable", "tbl", null, 0);
			stubRefWznmMBlock = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMBlock", "bl2", null, 0);
			Defval = Xmlio.extractStringUclc(doc, basexpath, "Defval", "dfv", null, 0);
			stubRefWznmMVectoritem = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVectoritem", "vit", null, 0);
			Comment = Xmlio.extractStringUclc(doc, basexpath, "Comment", "cmt", null, 0);
			
			return true;
		};

		return false;
	};
};

