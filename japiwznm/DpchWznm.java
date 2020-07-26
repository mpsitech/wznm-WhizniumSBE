/**
  * \file DpchWznm.java
  * Wznm Java API package dispatch block
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
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

