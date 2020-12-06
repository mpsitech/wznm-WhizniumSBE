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

#include "WznmCtpWrsrvAcv.h"
#include "WznmCtpWrsrvDlgimp.h"
#include "WznmCtpWrsrvDlgloaini.h"
#include "WznmCtpWrstkitAcv.h"
#include "WznmCtpWrstkitArm.h"
#include "WznmCtpGenuiAcv.h"
#include "WznmCtpGenuiDlgimp.h"
#include "WznmCtpGenuiDlgloaini.h"
#include "WznmCtpGenjtrAcv.h"
#include "WznmCtpGenjtrDlgimp.h"
#include "WznmCtpGenjtrDlgloaini.h"

/**
	* WznmopdOpprc
	*/
namespace WznmopdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif
