/**
	* \file WznmopdOpprc.h
	* operation processor for Wznm operation daemon wznmopd2 (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMOPDOPPRC_H
#define WZNMOPDOPPRC_H

#include "WznmCtpGenjtrAcv.h"
#include "WznmCtpGenjtrDlgimp.h"
#include "WznmCtpGenjtrDlgloaini.h"
#include "WznmCtpGenuiAcv.h"
#include "WznmCtpGenuiDlgimp.h"
#include "WznmCtpGenuiDlgloaini.h"
#include "WznmCtpWrstkitAcv.h"
#include "WznmCtpWrstkitArm.h"
#include "WznmCtpWrsrvAcv.h"
#include "WznmCtpWrsrvDlgimp.h"
#include "WznmCtpWrsrvDlgloaini.h"

/**
	* WznmopdOpprc
	*/
namespace WznmopdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif

