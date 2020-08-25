/**
  * \file DpchAppWznmResume.java
  * Wznm Java API package resume app dispatch block
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

public class DpchAppWznmResume extends DpchAppWznm {

	public DpchAppWznmResume(
				String scrJref
			) {
		super(VecWznmVDpch.DPCHAPPWZNMRESUME, scrJref);
	};
};

