/**
  * \file DpchAppWznmInit.java
  * Wznm Java API package init app dispatch block
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

public class DpchAppWznmInit extends DpchAppWznm {

	public DpchAppWznmInit(
				String scrJref
			) {
		super(VecWznmVDpch.DPCHAPPWZNMINIT, scrJref);
	};
};

