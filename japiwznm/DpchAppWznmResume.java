/**
  * \file DpchAppWznmResume.java
  * Wznm Java API package resume app dispatch block
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

public class DpchAppWznmResume extends DpchAppWznm {

	public DpchAppWznmResume(
				String scrJref
			) {
		super(VecWznmVDpch.DPCHAPPWZNMRESUME, scrJref);
	};
};

