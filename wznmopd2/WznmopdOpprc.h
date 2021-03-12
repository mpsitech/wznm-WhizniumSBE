/**
	* \file WznmopdOpprc.h
	* operation processor for Wznm operation daemon wznmopd2 (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMOPDOPPRC_H
#define WZNMOPDOPPRC_H

#include "WznmCtpWrwebDbeterm.h"
#include "WznmCtpWrstkitAcv.h"
#include "WznmCtpWrstkitArm.h"
#include "WznmCtpWrstkitClustmgr.h"
#include "WznmCtpWrstkitPrefs.h"
#include "WznmCtpWrsrvAcv.h"
#include "WznmCtpWrsrvClustmgr.h"
#include "WznmCtpWrsrvDbeterm.h"
#include "WznmCtpWrsrvDlgimp.h"
#include "WznmCtpWrsrvDlgloaini.h"
#include "WznmCtpWrsrvPrefs.h"
#include "WznmCtpGenuiAcv.h"
#include "WznmCtpGenuiClustmgr.h"
#include "WznmCtpGenuiDbeterm.h"
#include "WznmCtpGenuiDlgimp.h"
#include "WznmCtpGenuiDlgloaini.h"
#include "WznmCtpGenuiPrefs.h"
#include "WznmCtpGenjtrAcv.h"
#include "WznmCtpGenjtrClustmgr.h"
#include "WznmCtpGenjtrDlgimp.h"
#include "WznmCtpGenjtrDlgloaini.h"
#include "WznmCtpGenjtrPrefs.h"

/**
	* WznmopdOpprc
	*/
namespace WznmopdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif
