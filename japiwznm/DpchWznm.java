/**
  * \file DpchWznm.java
  * Wznm Java API package dispatch block
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import sbecore.*;

public class DpchWznm extends Block {

	public DpchWznm(
				int ixWznmVDpch
			) {
		this.ixWznmVDpch = ixWznmVDpch;
	};

	public int ixWznmVDpch;
};

