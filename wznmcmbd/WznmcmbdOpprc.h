/**
	* \file WznmcmbdOpprc.h
	* operation processor for Wznm combined daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMCMBDOPPRC_H
#define WZNMCMBDOPPRC_H

#include "WznmComplBscui.h"
#include "WznmComplDbs.h"
#include "WznmComplIex.h"
#include "WznmComplJtr.h"
#include "WznmCtpGenjtrAcv.h"
#include "WznmCtpGenjtrDlgimp.h"
#include "WznmCtpGenjtrDlgloaini.h"
#include "WznmCtpGenuiAcv.h"
#include "WznmCtpGenuiDlgimp.h"
#include "WznmCtpGenuiDlgloaini.h"
#include "WznmCtpWrsrvAcv.h"
#include "WznmCtpWrsrvDlgimp.h"
#include "WznmCtpWrsrvDlgloaini.h"
#include "WznmCtpWrstkitAcv.h"
#include "WznmCtpWrstkitArm.h"
#include "WznmGenBase.h"
#include "WznmGenCal.h"
#include "WznmGenChk.h"
#include "WznmGenDetui.h"
#include "WznmGenJob.h"
#include "WznmGenQtb.h"
#include "WznmGenSysvec.h"
#include "WznmPrcfileConcat.h"
#include "WznmPrcfileIexconv.h"
#include "WznmPrcfilePlhrpl.h"
#include "WznmPrctreeExtract.h"
#include "WznmPrctreeMerge.h"
#include "WznmPrctreeValidate.h"
#include "WznmWrapiBase.h"
#include "WznmWrapiDeploy.h"
#include "WznmWrapiJob.h"
#include "WznmWrapiQtb.h"
#include "WznmWrappBase.h"
#include "WznmWrappJbase.h"
#include "WznmWrdbsDbs.h"
#include "WznmWrdbsDeploy.h"
#include "WznmWrdbsDiffsql.h"
#include "WznmWrdbsSql.h"
#include "WznmWrdbsTbl.h"
#include "WznmWrjapiBase.h"
#include "WznmWrjapiJob.h"
#include "WznmWrjapiQtb.h"
#include "WznmWrjapiVec.h"
#include "WznmWrsrvBase.h"
#include "WznmWrsrvCmbengbase.h"
#include "WznmWrsrvCrd.h"
#include "WznmWrsrvDds.h"
#include "WznmWrsrvDeploy.h"
#include "WznmWrsrvDlg.h"
#include "WznmWrsrvEngbase.h"
#include "WznmWrsrvIex.h"
#include "WznmWrsrvInixml.h"
#include "WznmWrsrvJob.h"
#include "WznmWrsrvOp.h"
#include "WznmWrsrvOpengbase.h"
#include "WznmWrsrvOpk.h"
#include "WznmWrsrvPnl.h"
#include "WznmWrsrvPref.h"
#include "WznmWrsrvQry.h"
#include "WznmWrsrvRootsess.h"
#include "WznmWrsrvUa.h"
#include "WznmWrsrvVec.h"
#include "WznmWrwebBase.h"
#include "WznmWrwebCrd.h"
#include "WznmWrwebDeploy.h"
#include "WznmWrwebDlg.h"
#include "WznmWrwebPnl.h"

/**
	* WznmcmbdOpprc
	*/
namespace WznmcmbdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif

