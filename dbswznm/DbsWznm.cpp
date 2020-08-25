/**
	* \file DbsWznm.cpp
	* C++ wrapper for database DbsWznm (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "DbsWznm.h"

#include "DbsWznm_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class DbsWznm
 ******************************************************************************/

DbsWznm::DbsWznm() {
	initdone = false;

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	dbsMy = NULL;
#endif
#if defined(SBECORE_PG)
	dbsPg = NULL;
#endif
};

DbsWznm::~DbsWznm() {
	if (initdone) term();
};

void DbsWznm::init(
			const uint _ixDbsVDbstype
			, const string& _dbspath
			, const string& _dbsname
			, const string& _ip
			, const uint _port
			, const string& _username
			, const string& _password
		) {
	ixDbsVDbstype = _ixDbsVDbstype;
	dbspath = _dbspath;
	dbsname = _dbsname;
	username = _username;
	password = _password;
	ip = _ip;
	port = _port;

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) {
		initMy();
		initdone = true;
	};
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) {
		initPg();
		initdone = true;
	};
#endif
};

void DbsWznm::term() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) {
		termMy();
		initdone = false;
	};
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) {
		termPg();
		initdone = false;
	};
#endif
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
void DbsWznm::initMy() {
	// connect to MySQL database
	dbsMy = mysql_init(NULL);

	mysql_options(dbsMy, MYSQL_READ_DEFAULT_GROUP, "MyccDatabase");
	if (!mysql_real_connect(dbsMy, ip.c_str(), username.c_str(), password.c_str(), dbsname.c_str(), port, NULL, 0)) {
		string dbms = "DbsWznm::initMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_CONN, {{"dbms",dbms}});
	};

	executeQuery("SET SESSION wait_timeout = 31536000");

	tblwznmaccrmuseruniversal = new MyTblWznmAccRMUserUniversal();
	((MyTblWznmAccRMUserUniversal*) tblwznmaccrmuseruniversal)->init(dbsMy);
	tblwznmamblockitem = new MyTblWznmAMBlockItem();
	((MyTblWznmAMBlockItem*) tblwznmamblockitem)->init(dbsMy);
	tblwznmamcapabilitypar = new MyTblWznmAMCapabilityPar();
	((MyTblWznmAMCapabilityPar*) tblwznmamcapabilitypar)->init(dbsMy);
	tblwznmamcontrolpar = new MyTblWznmAMControlPar();
	((MyTblWznmAMControlPar*) tblwznmamcontrolpar)->init(dbsMy);
	tblwznmamjobcmd = new MyTblWznmAMJobCmd();
	((MyTblWznmAMJobCmd*) tblwznmamjobcmd)->init(dbsMy);
	tblwznmamjobvar = new MyTblWznmAMJobVar();
	((MyTblWznmAMJobVar*) tblwznmamjobvar)->init(dbsMy);
	tblwznmamlibrarymakefile = new MyTblWznmAMLibraryMakefile();
	((MyTblWznmAMLibraryMakefile*) tblwznmamlibrarymakefile)->init(dbsMy);
	tblwznmamlibrarypkglist = new MyTblWznmAMLibraryPkglist();
	((MyTblWznmAMLibraryPkglist*) tblwznmamlibrarypkglist)->init(dbsMy);
	tblwznmammachinepar = new MyTblWznmAMMachinePar();
	((MyTblWznmAMMachinePar*) tblwznmammachinepar)->init(dbsMy);
	tblwznmammachtypemakefile = new MyTblWznmAMMachtypeMakefile();
	((MyTblWznmAMMachtypeMakefile*) tblwznmammachtypemakefile)->init(dbsMy);
	tblwznmammethodinvpar = new MyTblWznmAMMethodInvpar();
	((MyTblWznmAMMethodInvpar*) tblwznmammethodinvpar)->init(dbsMy);
	tblwznmammethodretpar = new MyTblWznmAMMethodRetpar();
	((MyTblWznmAMMethodRetpar*) tblwznmammethodretpar)->init(dbsMy);
	tblwznmamopinvarg = new MyTblWznmAMOpInvarg();
	((MyTblWznmAMOpInvarg*) tblwznmamopinvarg)->init(dbsMy);
	tblwznmamoppackinvarg = new MyTblWznmAMOppackInvarg();
	((MyTblWznmAMOppackInvarg*) tblwznmamoppackinvarg)->init(dbsMy);
	tblwznmamoppackretval = new MyTblWznmAMOppackRetval();
	((MyTblWznmAMOppackRetval*) tblwznmamoppackretval)->init(dbsMy);
	tblwznmamopretval = new MyTblWznmAMOpRetval();
	((MyTblWznmAMOpRetval*) tblwznmamopretval)->init(dbsMy);
	tblwznmampersondetail = new MyTblWznmAMPersonDetail();
	((MyTblWznmAMPersonDetail*) tblwznmampersondetail)->init(dbsMy);
	tblwznmamqueryclause = new MyTblWznmAMQueryClause();
	((MyTblWznmAMQueryClause*) tblwznmamqueryclause)->init(dbsMy);
	tblwznmamqueryorder = new MyTblWznmAMQueryOrder();
	((MyTblWznmAMQueryOrder*) tblwznmamqueryorder)->init(dbsMy);
	tblwznmamrelationtitle = new MyTblWznmAMRelationTitle();
	((MyTblWznmAMRelationTitle*) tblwznmamrelationtitle)->init(dbsMy);
	tblwznmamstateaction = new MyTblWznmAMStateAction();
	((MyTblWznmAMStateAction*) tblwznmamstateaction)->init(dbsMy);
	tblwznmamstatetrig = new MyTblWznmAMStateTrig();
	((MyTblWznmAMStateTrig*) tblwznmamstatetrig)->init(dbsMy);
	tblwznmamsubsettitle = new MyTblWznmAMSubsetTitle();
	((MyTblWznmAMSubsetTitle*) tblwznmamsubsettitle)->init(dbsMy);
	tblwznmamtablecoltitle = new MyTblWznmAMTablecolTitle();
	((MyTblWznmAMTablecolTitle*) tblwznmamtablecoltitle)->init(dbsMy);
	tblwznmamtableloadfct = new MyTblWznmAMTableLoadfct();
	((MyTblWznmAMTableLoadfct*) tblwznmamtableloadfct)->init(dbsMy);
	tblwznmamtabletitle = new MyTblWznmAMTableTitle();
	((MyTblWznmAMTableTitle*) tblwznmamtabletitle)->init(dbsMy);
	tblwznmamuseraccess = new MyTblWznmAMUserAccess();
	((MyTblWznmAMUserAccess*) tblwznmamuseraccess)->init(dbsMy);
	tblwznmamusergroupaccess = new MyTblWznmAMUsergroupAccess();
	((MyTblWznmAMUsergroupAccess*) tblwznmamusergroupaccess)->init(dbsMy);
	tblwznmamvectortitle = new MyTblWznmAMVectorTitle();
	((MyTblWznmAMVectorTitle*) tblwznmamvectortitle)->init(dbsMy);
	tblwznmavcontrolpar = new MyTblWznmAVControlPar();
	((MyTblWznmAVControlPar*) tblwznmavcontrolpar)->init(dbsMy);
	tblwznmavkeylistkey = new MyTblWznmAVKeylistKey();
	((MyTblWznmAVKeylistKey*) tblwznmavkeylistkey)->init(dbsMy);
	tblwznmavvaluelistval = new MyTblWznmAVValuelistVal();
	((MyTblWznmAVValuelistVal*) tblwznmavvaluelistval)->init(dbsMy);
	tblwznmcamblockitem = new MyTblWznmCAMBlockItem();
	((MyTblWznmCAMBlockItem*) tblwznmcamblockitem)->init(dbsMy);
	tblwznmcamjobvar = new MyTblWznmCAMJobVar();
	((MyTblWznmCAMJobVar*) tblwznmcamjobvar)->init(dbsMy);
	tblwznmcamopinvarg = new MyTblWznmCAMOpInvarg();
	((MyTblWznmCAMOpInvarg*) tblwznmcamopinvarg)->init(dbsMy);
	tblwznmcamoppackinvarg = new MyTblWznmCAMOppackInvarg();
	((MyTblWznmCAMOppackInvarg*) tblwznmcamoppackinvarg)->init(dbsMy);
	tblwznmcamoppackretval = new MyTblWznmCAMOppackRetval();
	((MyTblWznmCAMOppackRetval*) tblwznmcamoppackretval)->init(dbsMy);
	tblwznmcamopretval = new MyTblWznmCAMOpRetval();
	((MyTblWznmCAMOpRetval*) tblwznmcamopretval)->init(dbsMy);
	tblwznmccontrol = new MyTblWznmCControl();
	((MyTblWznmCControl*) tblwznmccontrol)->init(dbsMy);
	tblwznmcfile = new MyTblWznmCFile();
	((MyTblWznmCFile*) tblwznmcfile)->init(dbsMy);
	tblwznmcrelation = new MyTblWznmCRelation();
	((MyTblWznmCRelation*) tblwznmcrelation)->init(dbsMy);
	tblwznmhistrmuseruniversal = new MyTblWznmHistRMUserUniversal();
	((MyTblWznmHistRMUserUniversal*) tblwznmhistrmuseruniversal)->init(dbsMy);
	tblwznmjamblockitem = new MyTblWznmJAMBlockItem();
	((MyTblWznmJAMBlockItem*) tblwznmjamblockitem)->init(dbsMy);
	tblwznmjamstatetrigcond = new MyTblWznmJAMStateTrigCond();
	((MyTblWznmJAMStateTrigCond*) tblwznmjamstatetrigcond)->init(dbsMy);
	tblwznmjavkeylistkey = new MyTblWznmJAVKeylistKey();
	((MyTblWznmJAVKeylistKey*) tblwznmjavkeylistkey)->init(dbsMy);
	tblwznmjmcardtitle = new MyTblWznmJMCardTitle();
	((MyTblWznmJMCardTitle*) tblwznmjmcardtitle)->init(dbsMy);
	tblwznmjmcontrol = new MyTblWznmJMControl();
	((MyTblWznmJMControl*) tblwznmjmcontrol)->init(dbsMy);
	tblwznmjmcontroltitle = new MyTblWznmJMControlTitle();
	((MyTblWznmJMControlTitle*) tblwznmjmcontroltitle)->init(dbsMy);
	tblwznmjmerrortitle = new MyTblWznmJMErrorTitle();
	((MyTblWznmJMErrorTitle*) tblwznmjmerrortitle)->init(dbsMy);
	tblwznmjmimpexpcolstub = new MyTblWznmJMImpexpcolStub();
	((MyTblWznmJMImpexpcolStub*) tblwznmjmimpexpcolstub)->init(dbsMy);
	tblwznmjmimpexpcplxtitle = new MyTblWznmJMImpexpcplxTitle();
	((MyTblWznmJMImpexpcplxTitle*) tblwznmjmimpexpcplxtitle)->init(dbsMy);
	tblwznmjmlocaletitle = new MyTblWznmJMLocaleTitle();
	((MyTblWznmJMLocaleTitle*) tblwznmjmlocaletitle)->init(dbsMy);
	tblwznmjmmodule = new MyTblWznmJMModule();
	((MyTblWznmJMModule*) tblwznmjmmodule)->init(dbsMy);
	tblwznmjmpersonlastname = new MyTblWznmJMPersonLastname();
	((MyTblWznmJMPersonLastname*) tblwznmjmpersonlastname)->init(dbsMy);
	tblwznmjmpresettitle = new MyTblWznmJMPresetTitle();
	((MyTblWznmJMPresetTitle*) tblwznmjmpresettitle)->init(dbsMy);
	tblwznmjmquerycolstub = new MyTblWznmJMQuerycolStub();
	((MyTblWznmJMQuerycolStub*) tblwznmjmquerycolstub)->init(dbsMy);
	tblwznmjmsquawktitle = new MyTblWznmJMSquawkTitle();
	((MyTblWznmJMSquawkTitle*) tblwznmjmsquawktitle)->init(dbsMy);
	tblwznmjmtagtitle = new MyTblWznmJMTagTitle();
	((MyTblWznmJMTagTitle*) tblwznmjmtagtitle)->init(dbsMy);
	tblwznmjmuserstate = new MyTblWznmJMUserState();
	((MyTblWznmJMUserState*) tblwznmjmuserstate)->init(dbsMy);
	tblwznmjmvectoritem = new MyTblWznmJMVectoritem();
	((MyTblWznmJMVectoritem*) tblwznmjmvectoritem)->init(dbsMy);
	tblwznmjmversion = new MyTblWznmJMVersion();
	((MyTblWznmJMVersion*) tblwznmjmversion)->init(dbsMy);
	tblwznmjmversionstate = new MyTblWznmJMVersionState();
	((MyTblWznmJMVersionState*) tblwznmjmversionstate)->init(dbsMy);
	tblwznmmapp = new MyTblWznmMApp();
	((MyTblWznmMApp*) tblwznmmapp)->init(dbsMy);
	tblwznmmblock = new MyTblWznmMBlock();
	((MyTblWznmMBlock*) tblwznmmblock)->init(dbsMy);
	tblwznmmcall = new MyTblWznmMCall();
	((MyTblWznmMCall*) tblwznmmcall)->init(dbsMy);
	tblwznmmcapability = new MyTblWznmMCapability();
	((MyTblWznmMCapability*) tblwznmmcapability)->init(dbsMy);
	tblwznmmcard = new MyTblWznmMCard();
	((MyTblWznmMCard*) tblwznmmcard)->init(dbsMy);
	tblwznmmcheck = new MyTblWznmMCheck();
	((MyTblWznmMCheck*) tblwznmmcheck)->init(dbsMy);
	tblwznmmcomponent = new MyTblWznmMComponent();
	((MyTblWznmMComponent*) tblwznmmcomponent)->init(dbsMy);
	tblwznmmcontrol = new MyTblWznmMControl();
	((MyTblWznmMControl*) tblwznmmcontrol)->init(dbsMy);
	tblwznmmdialog = new MyTblWznmMDialog();
	((MyTblWznmMDialog*) tblwznmmdialog)->init(dbsMy);
	tblwznmmerror = new MyTblWznmMError();
	((MyTblWznmMError*) tblwznmmerror)->init(dbsMy);
	tblwznmmevent = new MyTblWznmMEvent();
	((MyTblWznmMEvent*) tblwznmmevent)->init(dbsMy);
	tblwznmmfeed = new MyTblWznmMFeed();
	((MyTblWznmMFeed*) tblwznmmfeed)->init(dbsMy);
	tblwznmmfile = new MyTblWznmMFile();
	((MyTblWznmMFile*) tblwznmmfile)->init(dbsMy);
	tblwznmmimpexp = new MyTblWznmMImpexp();
	((MyTblWznmMImpexp*) tblwznmmimpexp)->init(dbsMy);
	tblwznmmimpexpcol = new MyTblWznmMImpexpcol();
	((MyTblWznmMImpexpcol*) tblwznmmimpexpcol)->init(dbsMy);
	tblwznmmimpexpcplx = new MyTblWznmMImpexpcplx();
	((MyTblWznmMImpexpcplx*) tblwznmmimpexpcplx)->init(dbsMy);
	tblwznmmjob = new MyTblWznmMJob();
	((MyTblWznmMJob*) tblwznmmjob)->init(dbsMy);
	tblwznmmlibrary = new MyTblWznmMLibrary();
	((MyTblWznmMLibrary*) tblwznmmlibrary)->init(dbsMy);
	tblwznmmlocale = new MyTblWznmMLocale();
	((MyTblWznmMLocale*) tblwznmmlocale)->init(dbsMy);
	tblwznmmmachine = new MyTblWznmMMachine();
	((MyTblWznmMMachine*) tblwznmmmachine)->init(dbsMy);
	tblwznmmmachtype = new MyTblWznmMMachtype();
	((MyTblWznmMMachtype*) tblwznmmmachtype)->init(dbsMy);
	tblwznmmmethod = new MyTblWznmMMethod();
	((MyTblWznmMMethod*) tblwznmmmethod)->init(dbsMy);
	tblwznmmmodule = new MyTblWznmMModule();
	((MyTblWznmMModule*) tblwznmmmodule)->init(dbsMy);
	tblwznmmop = new MyTblWznmMOp();
	((MyTblWznmMOp*) tblwznmmop)->init(dbsMy);
	tblwznmmoppack = new MyTblWznmMOppack();
	((MyTblWznmMOppack*) tblwznmmoppack)->init(dbsMy);
	tblwznmmpanel = new MyTblWznmMPanel();
	((MyTblWznmMPanel*) tblwznmmpanel)->init(dbsMy);
	tblwznmmperson = new MyTblWznmMPerson();
	((MyTblWznmMPerson*) tblwznmmperson)->init(dbsMy);
	tblwznmmpreset = new MyTblWznmMPreset();
	((MyTblWznmMPreset*) tblwznmmpreset)->init(dbsMy);
	tblwznmmproject = new MyTblWznmMProject();
	((MyTblWznmMProject*) tblwznmmproject)->init(dbsMy);
	tblwznmmquery = new MyTblWznmMQuery();
	((MyTblWznmMQuery*) tblwznmmquery)->init(dbsMy);
	tblwznmmquerycol = new MyTblWznmMQuerycol();
	((MyTblWznmMQuerycol*) tblwznmmquerycol)->init(dbsMy);
	tblwznmmquerymod = new MyTblWznmMQuerymod();
	((MyTblWznmMQuerymod*) tblwznmmquerymod)->init(dbsMy);
	tblwznmmrelation = new MyTblWznmMRelation();
	((MyTblWznmMRelation*) tblwznmmrelation)->init(dbsMy);
	tblwznmmrelease = new MyTblWznmMRelease();
	((MyTblWznmMRelease*) tblwznmmrelease)->init(dbsMy);
	tblwznmmrtblock = new MyTblWznmMRtblock();
	((MyTblWznmMRtblock*) tblwznmmrtblock)->init(dbsMy);
	tblwznmmrtdpch = new MyTblWznmMRtdpch();
	((MyTblWznmMRtdpch*) tblwznmmrtdpch)->init(dbsMy);
	tblwznmmrtjob = new MyTblWznmMRtjob();
	((MyTblWznmMRtjob*) tblwznmmrtjob)->init(dbsMy);
	tblwznmmsensitivity = new MyTblWznmMSensitivity();
	((MyTblWznmMSensitivity*) tblwznmmsensitivity)->init(dbsMy);
	tblwznmmsequence = new MyTblWznmMSequence();
	((MyTblWznmMSequence*) tblwznmmsequence)->init(dbsMy);
	tblwznmmsession = new MyTblWznmMSession();
	((MyTblWznmMSession*) tblwznmmsession)->init(dbsMy);
	tblwznmmsquawk = new MyTblWznmMSquawk();
	((MyTblWznmMSquawk*) tblwznmmsquawk)->init(dbsMy);
	tblwznmmstage = new MyTblWznmMStage();
	((MyTblWznmMStage*) tblwznmmstage)->init(dbsMy);
	tblwznmmstate = new MyTblWznmMState();
	((MyTblWznmMState*) tblwznmmstate)->init(dbsMy);
	tblwznmmstub = new MyTblWznmMStub();
	((MyTblWznmMStub*) tblwznmmstub)->init(dbsMy);
	tblwznmmsubset = new MyTblWznmMSubset();
	((MyTblWznmMSubset*) tblwznmmsubset)->init(dbsMy);
	tblwznmmtable = new MyTblWznmMTable();
	((MyTblWznmMTable*) tblwznmmtable)->init(dbsMy);
	tblwznmmtablecol = new MyTblWznmMTablecol();
	((MyTblWznmMTablecol*) tblwznmmtablecol)->init(dbsMy);
	tblwznmmtag = new MyTblWznmMTag();
	((MyTblWznmMTag*) tblwznmmtag)->init(dbsMy);
	tblwznmmuser = new MyTblWznmMUser();
	((MyTblWznmMUser*) tblwznmmuser)->init(dbsMy);
	tblwznmmusergroup = new MyTblWznmMUsergroup();
	((MyTblWznmMUsergroup*) tblwznmmusergroup)->init(dbsMy);
	tblwznmmvector = new MyTblWznmMVector();
	((MyTblWznmMVector*) tblwznmmvector)->init(dbsMy);
	tblwznmmvectoritem = new MyTblWznmMVectoritem();
	((MyTblWznmMVectoritem*) tblwznmmvectoritem)->init(dbsMy);
	tblwznmmversion = new MyTblWznmMVersion();
	((MyTblWznmMVersion*) tblwznmmversion)->init(dbsMy);
	tblwznmrmcallmstub = new MyTblWznmRMCallMStub();
	((MyTblWznmRMCallMStub*) tblwznmrmcallmstub)->init(dbsMy);
	tblwznmrmcapabilityuniversal = new MyTblWznmRMCapabilityUniversal();
	((MyTblWznmRMCapabilityUniversal*) tblwznmrmcapabilityuniversal)->init(dbsMy);
	tblwznmrmcomponentmlibrary = new MyTblWznmRMComponentMLibrary();
	((MyTblWznmRMComponentMLibrary*) tblwznmrmcomponentmlibrary)->init(dbsMy);
	tblwznmrmcomponentmoppack = new MyTblWznmRMComponentMOppack();
	((MyTblWznmRMComponentMOppack*) tblwznmrmcomponentmoppack)->init(dbsMy);
	tblwznmrmdialogmquery = new MyTblWznmRMDialogMQuery();
	((MyTblWznmRMDialogMQuery*) tblwznmrmdialogmquery)->init(dbsMy);
	tblwznmrmjobmjob = new MyTblWznmRMJobMJob();
	((MyTblWznmRMJobMJob*) tblwznmrmjobmjob)->init(dbsMy);
	tblwznmrmjobmop = new MyTblWznmRMJobMOp();
	((MyTblWznmRMJobMOp*) tblwznmrmjobmop)->init(dbsMy);
	tblwznmrmjobmoppack = new MyTblWznmRMJobMOppack();
	((MyTblWznmRMJobMOppack*) tblwznmrmjobmoppack)->init(dbsMy);
	tblwznmrmlibrarymoppack = new MyTblWznmRMLibraryMOppack();
	((MyTblWznmRMLibraryMOppack*) tblwznmrmlibrarymoppack)->init(dbsMy);
	tblwznmrmlocalemversion = new MyTblWznmRMLocaleMVersion();
	((MyTblWznmRMLocaleMVersion*) tblwznmrmlocalemversion)->init(dbsMy);
	tblwznmrmpanelmquery = new MyTblWznmRMPanelMQuery();
	((MyTblWznmRMPanelMQuery*) tblwznmrmpanelmquery)->init(dbsMy);
	tblwznmrmpersonmproject = new MyTblWznmRMPersonMProject();
	((MyTblWznmRMPersonMProject*) tblwznmrmpersonmproject)->init(dbsMy);
	tblwznmrmquerymtable = new MyTblWznmRMQueryMTable();
	((MyTblWznmRMQueryMTable*) tblwznmrmquerymtable)->init(dbsMy);
	tblwznmrmsquawkmstub = new MyTblWznmRMSquawkMStub();
	((MyTblWznmRMSquawkMStub*) tblwznmrmsquawkmstub)->init(dbsMy);
	tblwznmrmstubmstub = new MyTblWznmRMStubMStub();
	((MyTblWznmRMStubMStub*) tblwznmrmstubmstub)->init(dbsMy);
	tblwznmrmsubsetmsubset = new MyTblWznmRMSubsetMSubset();
	((MyTblWznmRMSubsetMSubset*) tblwznmrmsubsetmsubset)->init(dbsMy);
	tblwznmrmtablemvector = new MyTblWznmRMTableMVector();
	((MyTblWznmRMTableMVector*) tblwznmrmtablemvector)->init(dbsMy);
	tblwznmrmusergroupuniversal = new MyTblWznmRMUsergroupUniversal();
	((MyTblWznmRMUsergroupUniversal*) tblwznmrmusergroupuniversal)->init(dbsMy);
	tblwznmrmusermusergroup = new MyTblWznmRMUserMUsergroup();
	((MyTblWznmRMUserMUsergroup*) tblwznmrmusermusergroup)->init(dbsMy);
	tblwznmtmquerymodmquery = new MyTblWznmTMQuerymodMQuery();
	((MyTblWznmTMQuerymodMQuery*) tblwznmtmquerymodmquery)->init(dbsMy);

	tblwznmqapp1nevent = new MyTblWznmQApp1NEvent();
	((MyTblWznmQApp1NEvent*) tblwznmqapp1nevent)->init(dbsMy);
	tblwznmqapp1nrtjob = new MyTblWznmQApp1NRtjob();
	((MyTblWznmQApp1NRtjob*) tblwznmqapp1nrtjob)->init(dbsMy);
	tblwznmqappapp1nsequence = new MyTblWznmQAppApp1NSequence();
	((MyTblWznmQAppApp1NSequence*) tblwznmqappapp1nsequence)->init(dbsMy);
	tblwznmqapplist = new MyTblWznmQAppList();
	((MyTblWznmQAppList*) tblwznmqapplist)->init(dbsMy);
	tblwznmqappref1nfile = new MyTblWznmQAppRef1NFile();
	((MyTblWznmQAppRef1NFile*) tblwznmqappref1nfile)->init(dbsMy);
	tblwznmqblk1nrtdpch = new MyTblWznmQBlk1NRtdpch();
	((MyTblWznmQBlk1NRtdpch*) tblwznmqblk1nrtdpch)->init(dbsMy);
	tblwznmqblkaitem = new MyTblWznmQBlkAItem();
	((MyTblWznmQBlkAItem*) tblwznmqblkaitem)->init(dbsMy);
	tblwznmqblklist = new MyTblWznmQBlkList();
	((MyTblWznmQBlkList*) tblwznmqblklist)->init(dbsMy);
	tblwznmqblkref1nrtblock = new MyTblWznmQBlkRef1NRtblock();
	((MyTblWznmQBlkRef1NRtblock*) tblwznmqblkref1nrtblock)->init(dbsMy);
	tblwznmqcal1nsensitivity = new MyTblWznmQCal1NSensitivity();
	((MyTblWznmQCal1NSensitivity*) tblwznmqcal1nsensitivity)->init(dbsMy);
	tblwznmqcallist = new MyTblWznmQCalList();
	((MyTblWznmQCalList*) tblwznmqcallist)->init(dbsMy);
	tblwznmqcalmnstub = new MyTblWznmQCalMNStub();
	((MyTblWznmQCalMNStub*) tblwznmqcalmnstub)->init(dbsMy);
	tblwznmqcapapar = new MyTblWznmQCapAPar();
	((MyTblWznmQCapAPar*) tblwznmqcapapar)->init(dbsMy);
	tblwznmqcaplist = new MyTblWznmQCapList();
	((MyTblWznmQCapList*) tblwznmqcaplist)->init(dbsMy);
	tblwznmqcar1ndialog = new MyTblWznmQCar1NDialog();
	((MyTblWznmQCar1NDialog*) tblwznmqcar1ndialog)->init(dbsMy);
	tblwznmqcarcar1npanel = new MyTblWznmQCarCar1NPanel();
	((MyTblWznmQCarCar1NPanel*) tblwznmqcarcar1npanel)->init(dbsMy);
	tblwznmqcarhk1ncontrol = new MyTblWznmQCarHk1NControl();
	((MyTblWznmQCarHk1NControl*) tblwznmqcarhk1ncontrol)->init(dbsMy);
	tblwznmqcarlist = new MyTblWznmQCarList();
	((MyTblWznmQCarList*) tblwznmqcarlist)->init(dbsMy);
	tblwznmqchklist = new MyTblWznmQChkList();
	((MyTblWznmQChkList*) tblwznmqchklist)->init(dbsMy);
	tblwznmqchkref1ncall = new MyTblWznmQChkRef1NCall();
	((MyTblWznmQChkRef1NCall*) tblwznmqchkref1ncall)->init(dbsMy);
	tblwznmqcmp1nrelease = new MyTblWznmQCmp1NRelease();
	((MyTblWznmQCmp1NRelease*) tblwznmqcmp1nrelease)->init(dbsMy);
	tblwznmqcmplist = new MyTblWznmQCmpList();
	((MyTblWznmQCmpList*) tblwznmqcmplist)->init(dbsMy);
	tblwznmqcmpmnlibrary = new MyTblWznmQCmpMNLibrary();
	((MyTblWznmQCmpMNLibrary*) tblwznmqcmpmnlibrary)->init(dbsMy);
	tblwznmqcmpmnoppack = new MyTblWznmQCmpMNOppack();
	((MyTblWznmQCmpMNOppack*) tblwznmqcmpmnoppack)->init(dbsMy);
	tblwznmqconapar = new MyTblWznmQConAPar();
	((MyTblWznmQConAPar*) tblwznmqconapar)->init(dbsMy);
	tblwznmqconfedref1nrtblock = new MyTblWznmQConFedRef1NRtblock();
	((MyTblWznmQConFedRef1NRtblock*) tblwznmqconfedref1nrtblock)->init(dbsMy);
	tblwznmqconlist = new MyTblWznmQConList();
	((MyTblWznmQConList*) tblwznmqconlist)->init(dbsMy);
	tblwznmqconsup1ncontrol = new MyTblWznmQConSup1NControl();
	((MyTblWznmQConSup1NControl*) tblwznmqconsup1ncontrol)->init(dbsMy);
	tblwznmqctp1ntag = new MyTblWznmQCtp1NTag();
	((MyTblWznmQCtp1NTag*) tblwznmqctp1ntag)->init(dbsMy);
	tblwznmqctpapar = new MyTblWznmQCtpAPar();
	((MyTblWznmQCtpAPar*) tblwznmqctpapar)->init(dbsMy);
	tblwznmqctpkkey = new MyTblWznmQCtpKKey();
	((MyTblWznmQCtpKKey*) tblwznmqctpkkey)->init(dbsMy);
	tblwznmqctpkparkey = new MyTblWznmQCtpKParKey();
	((MyTblWznmQCtpKParKey*) tblwznmqctpkparkey)->init(dbsMy);
	tblwznmqctplist = new MyTblWznmQCtpList();
	((MyTblWznmQCtpList*) tblwznmqctplist)->init(dbsMy);
	tblwznmqctptpl1ncapability = new MyTblWznmQCtpTpl1NCapability();
	((MyTblWznmQCtpTpl1NCapability*) tblwznmqctptpl1ncapability)->init(dbsMy);
	tblwznmqdlghk1ncontrol = new MyTblWznmQDlgHk1NControl();
	((MyTblWznmQDlgHk1NControl*) tblwznmqdlghk1ncontrol)->init(dbsMy);
	tblwznmqdlglist = new MyTblWznmQDlgList();
	((MyTblWznmQDlgList*) tblwznmqdlglist)->init(dbsMy);
	tblwznmqdlgmnquery = new MyTblWznmQDlgMNQuery();
	((MyTblWznmQDlgMNQuery*) tblwznmqdlgmnquery)->init(dbsMy);
	tblwznmqdlgref1ncontrol = new MyTblWznmQDlgRef1NControl();
	((MyTblWznmQDlgRef1NControl*) tblwznmqdlgref1ncontrol)->init(dbsMy);
	tblwznmqerrlist = new MyTblWznmQErrList();
	((MyTblWznmQErrList*) tblwznmqerrlist)->init(dbsMy);
	tblwznmqevtlist = new MyTblWznmQEvtList();
	((MyTblWznmQEvtList*) tblwznmqevtlist)->init(dbsMy);
	tblwznmqfillist = new MyTblWznmQFilList();
	((MyTblWznmQFilList*) tblwznmqfillist)->init(dbsMy);
	tblwznmqiellist = new MyTblWznmQIelList();
	((MyTblWznmQIelList*) tblwznmqiellist)->init(dbsMy);
	tblwznmqiex1nimpexp = new MyTblWznmQIex1NImpexp();
	((MyTblWznmQIex1NImpexp*) tblwznmqiex1nimpexp)->init(dbsMy);
	tblwznmqiexhk1nvector = new MyTblWznmQIexHk1NVector();
	((MyTblWznmQIexHk1NVector*) tblwznmqiexhk1nvector)->init(dbsMy);
	tblwznmqiexlist = new MyTblWznmQIexList();
	((MyTblWznmQIexList*) tblwznmqiexlist)->init(dbsMy);
	tblwznmqiexref1ndialog = new MyTblWznmQIexRef1NDialog();
	((MyTblWznmQIexRef1NDialog*) tblwznmqiexref1ndialog)->init(dbsMy);
	tblwznmqimehk1nvector = new MyTblWznmQImeHk1NVector();
	((MyTblWznmQImeHk1NVector*) tblwznmqimehk1nvector)->init(dbsMy);
	tblwznmqimeime1nimpexpcol = new MyTblWznmQImeIme1NImpexpcol();
	((MyTblWznmQImeIme1NImpexpcol*) tblwznmqimeime1nimpexpcol)->init(dbsMy);
	tblwznmqimelist = new MyTblWznmQImeList();
	((MyTblWznmQImeList*) tblwznmqimelist)->init(dbsMy);
	tblwznmqimesup1nimpexp = new MyTblWznmQImeSup1NImpexp();
	((MyTblWznmQImeSup1NImpexp*) tblwznmqimesup1nimpexp)->init(dbsMy);
	tblwznmqjob1nmethod = new MyTblWznmQJob1NMethod();
	((MyTblWznmQJob1NMethod*) tblwznmqjob1nmethod)->init(dbsMy);
	tblwznmqjob1nrtjob = new MyTblWznmQJob1NRtjob();
	((MyTblWznmQJob1NRtjob*) tblwznmqjob1nrtjob)->init(dbsMy);
	tblwznmqjob1nsensitivity = new MyTblWznmQJob1NSensitivity();
	((MyTblWznmQJob1NSensitivity*) tblwznmqjob1nsensitivity)->init(dbsMy);
	tblwznmqjobacmd = new MyTblWznmQJobACmd();
	((MyTblWznmQJobACmd*) tblwznmqjobacmd)->init(dbsMy);
	tblwznmqjobavar = new MyTblWznmQJobAVar();
	((MyTblWznmQJobAVar*) tblwznmqjobavar)->init(dbsMy);
	tblwznmqjobhk1nvector = new MyTblWznmQJobHk1NVector();
	((MyTblWznmQJobHk1NVector*) tblwznmqjobhk1nvector)->init(dbsMy);
	tblwznmqjobjob1nstage = new MyTblWznmQJobJob1NStage();
	((MyTblWznmQJobJob1NStage*) tblwznmqjobjob1nstage)->init(dbsMy);
	tblwznmqjoblist = new MyTblWznmQJobList();
	((MyTblWznmQJobList*) tblwznmqjoblist)->init(dbsMy);
	tblwznmqjobmnop = new MyTblWznmQJobMNOp();
	((MyTblWznmQJobMNOp*) tblwznmqjobmnop)->init(dbsMy);
	tblwznmqjobmnoppack = new MyTblWznmQJobMNOppack();
	((MyTblWznmQJobMNOppack*) tblwznmqjobmnoppack)->init(dbsMy);
	tblwznmqjobref1nblock = new MyTblWznmQJobRef1NBlock();
	((MyTblWznmQJobRef1NBlock*) tblwznmqjobref1nblock)->init(dbsMy);
	tblwznmqjobsubmnjob = new MyTblWznmQJobSubMNJob();
	((MyTblWznmQJobSubMNJob*) tblwznmqjobsubmnjob)->init(dbsMy);
	tblwznmqjobsupmnjob = new MyTblWznmQJobSupMNJob();
	((MyTblWznmQJobSupMNJob*) tblwznmqjobsupmnjob)->init(dbsMy);
	tblwznmqlibamakefile = new MyTblWznmQLibAMakefile();
	((MyTblWznmQLibAMakefile*) tblwznmqlibamakefile)->init(dbsMy);
	tblwznmqlibapkglist = new MyTblWznmQLibAPkglist();
	((MyTblWznmQLibAPkglist*) tblwznmqlibapkglist)->init(dbsMy);
	tblwznmqliblist = new MyTblWznmQLibList();
	((MyTblWznmQLibList*) tblwznmqliblist)->init(dbsMy);
	tblwznmqlibmncomponent = new MyTblWznmQLibMNComponent();
	((MyTblWznmQLibMNComponent*) tblwznmqlibmncomponent)->init(dbsMy);
	tblwznmqlibmnoppack = new MyTblWznmQLibMNOppack();
	((MyTblWznmQLibMNOppack*) tblwznmqlibmnoppack)->init(dbsMy);
	tblwznmqlibref1nfile = new MyTblWznmQLibRef1NFile();
	((MyTblWznmQLibRef1NFile*) tblwznmqlibref1nfile)->init(dbsMy);
	tblwznmqloclist = new MyTblWznmQLocList();
	((MyTblWznmQLocList*) tblwznmqloclist)->init(dbsMy);
	tblwznmqlocmnversion = new MyTblWznmQLocMNVersion();
	((MyTblWznmQLocMNVersion*) tblwznmqlocmnversion)->init(dbsMy);
	tblwznmqmch1nrelease = new MyTblWznmQMch1NRelease();
	((MyTblWznmQMch1NRelease*) tblwznmqmch1nrelease)->init(dbsMy);
	tblwznmqmchapar = new MyTblWznmQMchAPar();
	((MyTblWznmQMchAPar*) tblwznmqmchapar)->init(dbsMy);
	tblwznmqmchlist = new MyTblWznmQMchList();
	((MyTblWznmQMchList*) tblwznmqmchlist)->init(dbsMy);
	tblwznmqmdllist = new MyTblWznmQMdlList();
	((MyTblWznmQMdlList*) tblwznmqmdllist)->init(dbsMy);
	tblwznmqmdlmdl1ncard = new MyTblWznmQMdlMdl1NCard();
	((MyTblWznmQMdlMdl1NCard*) tblwznmqmdlmdl1ncard)->init(dbsMy);
	tblwznmqmdlref1npanel = new MyTblWznmQMdlRef1NPanel();
	((MyTblWznmQMdlRef1NPanel*) tblwznmqmdlref1npanel)->init(dbsMy);
	tblwznmqmtdainvpar = new MyTblWznmQMtdAInvpar();
	((MyTblWznmQMtdAInvpar*) tblwznmqmtdainvpar)->init(dbsMy);
	tblwznmqmtdaretpar = new MyTblWznmQMtdARetpar();
	((MyTblWznmQMtdARetpar*) tblwznmqmtdaretpar)->init(dbsMy);
	tblwznmqmtdlist = new MyTblWznmQMtdList();
	((MyTblWznmQMtdList*) tblwznmqmtdlist)->init(dbsMy);
	tblwznmqmty1nmachine = new MyTblWznmQMty1NMachine();
	((MyTblWznmQMty1NMachine*) tblwznmqmty1nmachine)->init(dbsMy);
	tblwznmqmtyamakefile = new MyTblWznmQMtyAMakefile();
	((MyTblWznmQMtyAMakefile*) tblwznmqmtyamakefile)->init(dbsMy);
	tblwznmqmtylist = new MyTblWznmQMtyList();
	((MyTblWznmQMtyList*) tblwznmqmtylist)->init(dbsMy);
	tblwznmqopk1nop = new MyTblWznmQOpk1NOp();
	((MyTblWznmQOpk1NOp*) tblwznmqopk1nop)->init(dbsMy);
	tblwznmqopkainvarg = new MyTblWznmQOpkAInvarg();
	((MyTblWznmQOpkAInvarg*) tblwznmqopkainvarg)->init(dbsMy);
	tblwznmqopkaretval = new MyTblWznmQOpkARetval();
	((MyTblWznmQOpkARetval*) tblwznmqopkaretval)->init(dbsMy);
	tblwznmqopklist = new MyTblWznmQOpkList();
	((MyTblWznmQOpkList*) tblwznmqopklist)->init(dbsMy);
	tblwznmqopkmncomponent = new MyTblWznmQOpkMNComponent();
	((MyTblWznmQOpkMNComponent*) tblwznmqopkmncomponent)->init(dbsMy);
	tblwznmqopkmnjob = new MyTblWznmQOpkMNJob();
	((MyTblWznmQOpkMNJob*) tblwznmqopkmnjob)->init(dbsMy);
	tblwznmqopkmnlibrary = new MyTblWznmQOpkMNLibrary();
	((MyTblWznmQOpkMNLibrary*) tblwznmqopkmnlibrary)->init(dbsMy);
	tblwznmqopkref1nblock = new MyTblWznmQOpkRef1NBlock();
	((MyTblWznmQOpkRef1NBlock*) tblwznmqopkref1nblock)->init(dbsMy);
	tblwznmqopksqkmnstub = new MyTblWznmQOpkSqkMNStub();
	((MyTblWznmQOpkSqkMNStub*) tblwznmqopksqkmnstub)->init(dbsMy);
	tblwznmqopxainvarg = new MyTblWznmQOpxAInvarg();
	((MyTblWznmQOpxAInvarg*) tblwznmqopxainvarg)->init(dbsMy);
	tblwznmqopxaretval = new MyTblWznmQOpxARetval();
	((MyTblWznmQOpxARetval*) tblwznmqopxaretval)->init(dbsMy);
	tblwznmqopxlist = new MyTblWznmQOpxList();
	((MyTblWznmQOpxList*) tblwznmqopxlist)->init(dbsMy);
	tblwznmqopxmnjob = new MyTblWznmQOpxMNJob();
	((MyTblWznmQOpxMNJob*) tblwznmqopxmnjob)->init(dbsMy);
	tblwznmqopxref1nblock = new MyTblWznmQOpxRef1NBlock();
	((MyTblWznmQOpxRef1NBlock*) tblwznmqopxref1nblock)->init(dbsMy);
	tblwznmqopxsqkmnstub = new MyTblWznmQOpxSqkMNStub();
	((MyTblWznmQOpxSqkMNStub*) tblwznmqopxsqkmnstub)->init(dbsMy);
	tblwznmqpnlhk1ncontrol = new MyTblWznmQPnlHk1NControl();
	((MyTblWznmQPnlHk1NControl*) tblwznmqpnlhk1ncontrol)->init(dbsMy);
	tblwznmqpnllist = new MyTblWznmQPnlList();
	((MyTblWznmQPnlList*) tblwznmqpnllist)->init(dbsMy);
	tblwznmqpnlmnquery = new MyTblWznmQPnlMNQuery();
	((MyTblWznmQPnlMNQuery*) tblwznmqpnlmnquery)->init(dbsMy);
	tblwznmqpreselect = new MyTblWznmQPreselect();
	((MyTblWznmQPreselect*) tblwznmqpreselect)->init(dbsMy);
	tblwznmqprj1nversion = new MyTblWznmQPrj1NVersion();
	((MyTblWznmQPrj1NVersion*) tblwznmqprj1nversion)->init(dbsMy);
	tblwznmqprjlist = new MyTblWznmQPrjList();
	((MyTblWznmQPrjList*) tblwznmqprjlist)->init(dbsMy);
	tblwznmqprjmnperson = new MyTblWznmQPrjMNPerson();
	((MyTblWznmQPrjMNPerson*) tblwznmqprjmnperson)->init(dbsMy);
	tblwznmqprsadetail = new MyTblWznmQPrsADetail();
	((MyTblWznmQPrsADetail*) tblwznmqprsadetail)->init(dbsMy);
	tblwznmqprslist = new MyTblWznmQPrsList();
	((MyTblWznmQPrsList*) tblwznmqprslist)->init(dbsMy);
	tblwznmqprsmnproject = new MyTblWznmQPrsMNProject();
	((MyTblWznmQPrsMNProject*) tblwznmqprsmnproject)->init(dbsMy);
	tblwznmqpst1nquerymod = new MyTblWznmQPst1NQuerymod();
	((MyTblWznmQPst1NQuerymod*) tblwznmqpst1nquerymod)->init(dbsMy);
	tblwznmqpstlist = new MyTblWznmQPstList();
	((MyTblWznmQPstList*) tblwznmqpstlist)->init(dbsMy);
	tblwznmqqcolist = new MyTblWznmQQcoList();
	((MyTblWznmQQcoList*) tblwznmqqcolist)->init(dbsMy);
	tblwznmqqcoref1ncontrol = new MyTblWznmQQcoRef1NControl();
	((MyTblWznmQQcoRef1NControl*) tblwznmqqcoref1ncontrol)->init(dbsMy);
	tblwznmqqmdlist = new MyTblWznmQQmdList();
	((MyTblWznmQQmdList*) tblwznmqqmdlist)->init(dbsMy);
	tblwznmqqry1nquerymod = new MyTblWznmQQry1NQuerymod();
	((MyTblWznmQQry1NQuerymod*) tblwznmqqry1nquerymod)->init(dbsMy);
	tblwznmqqryaclause = new MyTblWznmQQryAClause();
	((MyTblWznmQQryAClause*) tblwznmqqryaclause)->init(dbsMy);
	tblwznmqqryaorder = new MyTblWznmQQryAOrder();
	((MyTblWznmQQryAOrder*) tblwznmqqryaorder)->init(dbsMy);
	tblwznmqqrylist = new MyTblWznmQQryList();
	((MyTblWznmQQryList*) tblwznmqqrylist)->init(dbsMy);
	tblwznmqqrymndialog = new MyTblWznmQQryMNDialog();
	((MyTblWznmQQryMNDialog*) tblwznmqqrymndialog)->init(dbsMy);
	tblwznmqqrymnpanel = new MyTblWznmQQryMNPanel();
	((MyTblWznmQQryMNPanel*) tblwznmqqrymnpanel)->init(dbsMy);
	tblwznmqqrymntable = new MyTblWznmQQryMNTable();
	((MyTblWznmQQryMNTable*) tblwznmqqrymntable)->init(dbsMy);
	tblwznmqqryqry1nquerycol = new MyTblWznmQQryQry1NQuerycol();
	((MyTblWznmQQryQry1NQuerycol*) tblwznmqqryqry1nquerycol)->init(dbsMy);
	tblwznmqqrysup1nquery = new MyTblWznmQQrySup1NQuery();
	((MyTblWznmQQrySup1NQuery*) tblwznmqqrysup1nquery)->init(dbsMy);
	tblwznmqrel1ntablecol = new MyTblWznmQRel1NTablecol();
	((MyTblWznmQRel1NTablecol*) tblwznmqrel1ntablecol)->init(dbsMy);
	tblwznmqrelatitle = new MyTblWznmQRelATitle();
	((MyTblWznmQRelATitle*) tblwznmqrelatitle)->init(dbsMy);
	tblwznmqrellist = new MyTblWznmQRelList();
	((MyTblWznmQRelList*) tblwznmqrellist)->init(dbsMy);
	tblwznmqrelref1ncontrol = new MyTblWznmQRelRef1NControl();
	((MyTblWznmQRelRef1NControl*) tblwznmqrelref1ncontrol)->init(dbsMy);
	tblwznmqrelref1ndialog = new MyTblWznmQRelRef1NDialog();
	((MyTblWznmQRelRef1NDialog*) tblwznmqrelref1ndialog)->init(dbsMy);
	tblwznmqrelref1npanel = new MyTblWznmQRelRef1NPanel();
	((MyTblWznmQRelRef1NPanel*) tblwznmqrelref1npanel)->init(dbsMy);
	tblwznmqrelsup1nrelation = new MyTblWznmQRelSup1NRelation();
	((MyTblWznmQRelSup1NRelation*) tblwznmqrelsup1nrelation)->init(dbsMy);
	tblwznmqrlslist = new MyTblWznmQRlsList();
	((MyTblWznmQRlsList*) tblwznmqrlslist)->init(dbsMy);
	tblwznmqrtj1nrtblock = new MyTblWznmQRtj1NRtblock();
	((MyTblWznmQRtj1NRtblock*) tblwznmqrtj1nrtblock)->init(dbsMy);
	tblwznmqrtj1nrtdpch = new MyTblWznmQRtj1NRtdpch();
	((MyTblWznmQRtj1NRtdpch*) tblwznmqrtj1nrtdpch)->init(dbsMy);
	tblwznmqrtjlist = new MyTblWznmQRtjList();
	((MyTblWznmQRtjList*) tblwznmqrtjlist)->init(dbsMy);
	tblwznmqrtjsup1nrtjob = new MyTblWznmQRtjSup1NRtjob();
	((MyTblWznmQRtjSup1NRtjob*) tblwznmqrtjsup1nrtjob)->init(dbsMy);
	tblwznmqsbs1nstub = new MyTblWznmQSbs1NStub();
	((MyTblWznmQSbs1NStub*) tblwznmqsbs1nstub)->init(dbsMy);
	tblwznmqsbs1ntablecol = new MyTblWznmQSbs1NTablecol();
	((MyTblWznmQSbs1NTablecol*) tblwznmqsbs1ntablecol)->init(dbsMy);
	tblwznmqsbsasbmnsubset = new MyTblWznmQSbsAsbMNSubset();
	((MyTblWznmQSbsAsbMNSubset*) tblwznmqsbsasbmnsubset)->init(dbsMy);
	tblwznmqsbsatitle = new MyTblWznmQSbsATitle();
	((MyTblWznmQSbsATitle*) tblwznmqsbsatitle)->init(dbsMy);
	tblwznmqsbsbsbmnsubset = new MyTblWznmQSbsBsbMNSubset();
	((MyTblWznmQSbsBsbMNSubset*) tblwznmqsbsbsbmnsubset)->init(dbsMy);
	tblwznmqsbsfrs1nrelation = new MyTblWznmQSbsFrs1NRelation();
	((MyTblWznmQSbsFrs1NRelation*) tblwznmqsbsfrs1nrelation)->init(dbsMy);
	tblwznmqsbslist = new MyTblWznmQSbsList();
	((MyTblWznmQSbsList*) tblwznmqsbslist)->init(dbsMy);
	tblwznmqsbspst1nquerymod = new MyTblWznmQSbsPst1NQuerymod();
	((MyTblWznmQSbsPst1NQuerymod*) tblwznmqsbspst1nquerymod)->init(dbsMy);
	tblwznmqsbstos1nrelation = new MyTblWznmQSbsTos1NRelation();
	((MyTblWznmQSbsTos1NRelation*) tblwznmqsbstos1nrelation)->init(dbsMy);
	tblwznmqselect = new MyTblWznmQSelect();
	((MyTblWznmQSelect*) tblwznmqselect)->init(dbsMy);
	tblwznmqseqlist = new MyTblWznmQSeqList();
	((MyTblWznmQSeqList*) tblwznmqseqlist)->init(dbsMy);
	tblwznmqseqseq1nstate = new MyTblWznmQSeqSeq1NState();
	((MyTblWznmQSeqSeq1NState*) tblwznmqseqseq1nstate)->init(dbsMy);
	tblwznmqsge1nsensitivity = new MyTblWznmQSge1NSensitivity();
	((MyTblWznmQSge1NSensitivity*) tblwznmqsge1nsensitivity)->init(dbsMy);
	tblwznmqsgelist = new MyTblWznmQSgeList();
	((MyTblWznmQSgeList*) tblwznmqsgelist)->init(dbsMy);
	tblwznmqsgesqkmnstub = new MyTblWznmQSgeSqkMNStub();
	((MyTblWznmQSgeSqkMNStub*) tblwznmqsgesqkmnstub)->init(dbsMy);
	tblwznmqstblist = new MyTblWznmQStbList();
	((MyTblWznmQStbList*) tblwznmqstblist)->init(dbsMy);
	tblwznmqstbmncall = new MyTblWznmQStbMNCall();
	((MyTblWznmQStbMNCall*) tblwznmqstbmncall)->init(dbsMy);
	tblwznmqstbmnsquawk = new MyTblWznmQStbMNSquawk();
	((MyTblWznmQStbMNSquawk*) tblwznmqstbmnsquawk)->init(dbsMy);
	tblwznmqstbsubmnstub = new MyTblWznmQStbSubMNStub();
	((MyTblWznmQStbSubMNStub*) tblwznmqstbsubmnstub)->init(dbsMy);
	tblwznmqstbsupmnstub = new MyTblWznmQStbSupMNStub();
	((MyTblWznmQStbSupMNStub*) tblwznmqstbsupmnstub)->init(dbsMy);
	tblwznmqsteatrig = new MyTblWznmQSteATrig();
	((MyTblWznmQSteATrig*) tblwznmqsteatrig)->init(dbsMy);
	tblwznmqstelist = new MyTblWznmQSteList();
	((MyTblWznmQSteList*) tblwznmqstelist)->init(dbsMy);
	tblwznmqtaglist = new MyTblWznmQTagList();
	((MyTblWznmQTagList*) tblwznmqtaglist)->init(dbsMy);
	tblwznmqtbl1ncheck = new MyTblWznmQTbl1NCheck();
	((MyTblWznmQTbl1NCheck*) tblwznmqtbl1ncheck)->init(dbsMy);
	tblwznmqtbl1nimpexp = new MyTblWznmQTbl1NImpexp();
	((MyTblWznmQTbl1NImpexp*) tblwznmqtbl1nimpexp)->init(dbsMy);
	tblwznmqtbl1nstub = new MyTblWznmQTbl1NStub();
	((MyTblWznmQTbl1NStub*) tblwznmqtbl1nstub)->init(dbsMy);
	tblwznmqtbl1nsubset = new MyTblWznmQTbl1NSubset();
	((MyTblWznmQTbl1NSubset*) tblwznmqtbl1nsubset)->init(dbsMy);
	tblwznmqtblaloadfct = new MyTblWznmQTblALoadfct();
	((MyTblWznmQTblALoadfct*) tblwznmqtblaloadfct)->init(dbsMy);
	tblwznmqtblatitle = new MyTblWznmQTblATitle();
	((MyTblWznmQTblATitle*) tblwznmqtblatitle)->init(dbsMy);
	tblwznmqtblfct1ntablecol = new MyTblWznmQTblFct1NTablecol();
	((MyTblWznmQTblFct1NTablecol*) tblwznmqtblfct1ntablecol)->init(dbsMy);
	tblwznmqtblfr1nrelation = new MyTblWznmQTblFr1NRelation();
	((MyTblWznmQTblFr1NRelation*) tblwznmqtblfr1nrelation)->init(dbsMy);
	tblwznmqtblhk1nvector = new MyTblWznmQTblHk1NVector();
	((MyTblWznmQTblHk1NVector*) tblwznmqtblhk1nvector)->init(dbsMy);
	tblwznmqtbllist = new MyTblWznmQTblList();
	((MyTblWznmQTblList*) tblwznmqtbllist)->init(dbsMy);
	tblwznmqtblmnquery = new MyTblWznmQTblMNQuery();
	((MyTblWznmQTblMNQuery*) tblwznmqtblmnquery)->init(dbsMy);
	tblwznmqtblmnvector = new MyTblWznmQTblMNVector();
	((MyTblWznmQTblMNVector*) tblwznmqtblmnvector)->init(dbsMy);
	tblwznmqtblpst1nquerymod = new MyTblWznmQTblPst1NQuerymod();
	((MyTblWznmQTblPst1NQuerymod*) tblwznmqtblpst1nquerymod)->init(dbsMy);
	tblwznmqtblref1ncall = new MyTblWznmQTblRef1NCall();
	((MyTblWznmQTblRef1NCall*) tblwznmqtblref1ncall)->init(dbsMy);
	tblwznmqtblref1ndialog = new MyTblWznmQTblRef1NDialog();
	((MyTblWznmQTblRef1NDialog*) tblwznmqtblref1ndialog)->init(dbsMy);
	tblwznmqtblref1npanel = new MyTblWznmQTblRef1NPanel();
	((MyTblWznmQTblRef1NPanel*) tblwznmqtblref1npanel)->init(dbsMy);
	tblwznmqtblref1nquerymod = new MyTblWznmQTblRef1NQuerymod();
	((MyTblWznmQTblRef1NQuerymod*) tblwznmqtblref1nquerymod)->init(dbsMy);
	tblwznmqtblref1nrtblock = new MyTblWznmQTblRef1NRtblock();
	((MyTblWznmQTblRef1NRtblock*) tblwznmqtblref1nrtblock)->init(dbsMy);
	tblwznmqtblsrc1nfeed = new MyTblWznmQTblSrc1NFeed();
	((MyTblWznmQTblSrc1NFeed*) tblwznmqtblsrc1nfeed)->init(dbsMy);
	tblwznmqtbltbl1ntablecol = new MyTblWznmQTblTbl1NTablecol();
	((MyTblWznmQTblTbl1NTablecol*) tblwznmqtbltbl1ntablecol)->init(dbsMy);
	tblwznmqtblto1nrelation = new MyTblWznmQTblTo1NRelation();
	((MyTblWznmQTblTo1NRelation*) tblwznmqtblto1nrelation)->init(dbsMy);
	tblwznmqtco1ncheck = new MyTblWznmQTco1NCheck();
	((MyTblWznmQTco1NCheck*) tblwznmqtco1ncheck)->init(dbsMy);
	tblwznmqtco1nimpexpcol = new MyTblWznmQTco1NImpexpcol();
	((MyTblWznmQTco1NImpexpcol*) tblwznmqtco1nimpexpcol)->init(dbsMy);
	tblwznmqtco1nquerycol = new MyTblWznmQTco1NQuerycol();
	((MyTblWznmQTco1NQuerycol*) tblwznmqtco1nquerycol)->init(dbsMy);
	tblwznmqtcoatitle = new MyTblWznmQTcoATitle();
	((MyTblWznmQTcoATitle*) tblwznmqtcoatitle)->init(dbsMy);
	tblwznmqtcolist = new MyTblWznmQTcoList();
	((MyTblWznmQTcoList*) tblwznmqtcolist)->init(dbsMy);
	tblwznmqtcoref1ncontrol = new MyTblWznmQTcoRef1NControl();
	((MyTblWznmQTcoRef1NControl*) tblwznmqtcoref1ncontrol)->init(dbsMy);
	tblwznmqtcoref1nquerymod = new MyTblWznmQTcoRef1NQuerymod();
	((MyTblWznmQTcoRef1NQuerymod*) tblwznmqtcoref1nquerymod)->init(dbsMy);
	tblwznmqusgaaccess = new MyTblWznmQUsgAAccess();
	((MyTblWznmQUsgAAccess*) tblwznmqusgaaccess)->init(dbsMy);
	tblwznmqusglist = new MyTblWznmQUsgList();
	((MyTblWznmQUsgList*) tblwznmqusglist)->init(dbsMy);
	tblwznmqusgmnuser = new MyTblWznmQUsgMNUser();
	((MyTblWznmQUsgMNUser*) tblwznmqusgmnuser)->init(dbsMy);
	tblwznmqusr1nsession = new MyTblWznmQUsr1NSession();
	((MyTblWznmQUsr1NSession*) tblwznmqusr1nsession)->init(dbsMy);
	tblwznmqusraaccess = new MyTblWznmQUsrAAccess();
	((MyTblWznmQUsrAAccess*) tblwznmqusraaccess)->init(dbsMy);
	tblwznmqusrlist = new MyTblWznmQUsrList();
	((MyTblWznmQUsrList*) tblwznmqusrlist)->init(dbsMy);
	tblwznmqusrmnusergroup = new MyTblWznmQUsrMNUsergroup();
	((MyTblWznmQUsrMNUsergroup*) tblwznmqusrmnusergroup)->init(dbsMy);
	tblwznmqvecatitle = new MyTblWznmQVecATitle();
	((MyTblWznmQVecATitle*) tblwznmqvecatitle)->init(dbsMy);
	tblwznmqvecfct1ntablecol = new MyTblWznmQVecFct1NTablecol();
	((MyTblWznmQVecFct1NTablecol*) tblwznmqvecfct1ntablecol)->init(dbsMy);
	tblwznmqveclist = new MyTblWznmQVecList();
	((MyTblWznmQVecList*) tblwznmqveclist)->init(dbsMy);
	tblwznmqvecmntable = new MyTblWznmQVecMNTable();
	((MyTblWznmQVecMNTable*) tblwznmqvecmntable)->init(dbsMy);
	tblwznmqvecpst1nquerymod = new MyTblWznmQVecPst1NQuerymod();
	((MyTblWznmQVecPst1NQuerymod*) tblwznmqvecpst1nquerymod)->init(dbsMy);
	tblwznmqvecref1npanel = new MyTblWznmQVecRef1NPanel();
	((MyTblWznmQVecRef1NPanel*) tblwznmqvecref1npanel)->init(dbsMy);
	tblwznmqvecsrc1nfeed = new MyTblWznmQVecSrc1NFeed();
	((MyTblWznmQVecSrc1NFeed*) tblwznmqvecsrc1nfeed)->init(dbsMy);
	tblwznmqvecvec1nvectoritem = new MyTblWznmQVecVec1NVectoritem();
	((MyTblWznmQVecVec1NVectoritem*) tblwznmqvecvec1nvectoritem)->init(dbsMy);
	tblwznmqver1nblock = new MyTblWznmQVer1NBlock();
	((MyTblWznmQVer1NBlock*) tblwznmqver1nblock)->init(dbsMy);
	tblwznmqver1ncall = new MyTblWznmQVer1NCall();
	((MyTblWznmQVer1NCall*) tblwznmqver1ncall)->init(dbsMy);
	tblwznmqver1ncapability = new MyTblWznmQVer1NCapability();
	((MyTblWznmQVer1NCapability*) tblwznmqver1ncapability)->init(dbsMy);
	tblwznmqver1ncomponent = new MyTblWznmQVer1NComponent();
	((MyTblWznmQVer1NComponent*) tblwznmqver1ncomponent)->init(dbsMy);
	tblwznmqver1nimpexpcplx = new MyTblWznmQVer1NImpexpcplx();
	((MyTblWznmQVer1NImpexpcplx*) tblwznmqver1nimpexpcplx)->init(dbsMy);
	tblwznmqver1njob = new MyTblWznmQVer1NJob();
	((MyTblWznmQVer1NJob*) tblwznmqver1njob)->init(dbsMy);
	tblwznmqver1noppack = new MyTblWznmQVer1NOppack();
	((MyTblWznmQVer1NOppack*) tblwznmqver1noppack)->init(dbsMy);
	tblwznmqver1npreset = new MyTblWznmQVer1NPreset();
	((MyTblWznmQVer1NPreset*) tblwznmqver1npreset)->init(dbsMy);
	tblwznmqver1nquery = new MyTblWznmQVer1NQuery();
	((MyTblWznmQVer1NQuery*) tblwznmqver1nquery)->init(dbsMy);
	tblwznmqver1nrelation = new MyTblWznmQVer1NRelation();
	((MyTblWznmQVer1NRelation*) tblwznmqver1nrelation)->init(dbsMy);
	tblwznmqver1ntable = new MyTblWznmQVer1NTable();
	((MyTblWznmQVer1NTable*) tblwznmqver1ntable)->init(dbsMy);
	tblwznmqver1nvector = new MyTblWznmQVer1NVector();
	((MyTblWznmQVer1NVector*) tblwznmqver1nvector)->init(dbsMy);
	tblwznmqverbvr1nversion = new MyTblWznmQVerBvr1NVersion();
	((MyTblWznmQVerBvr1NVersion*) tblwznmqverbvr1nversion)->init(dbsMy);
	tblwznmqverlist = new MyTblWznmQVerList();
	((MyTblWznmQVerList*) tblwznmqverlist)->init(dbsMy);
	tblwznmqvermnlocale = new MyTblWznmQVerMNLocale();
	((MyTblWznmQVerMNLocale*) tblwznmqvermnlocale)->init(dbsMy);
	tblwznmqverref1nfile = new MyTblWznmQVerRef1NFile();
	((MyTblWznmQVerRef1NFile*) tblwznmqverref1nfile)->init(dbsMy);
	tblwznmqverver1napp = new MyTblWznmQVerVer1NApp();
	((MyTblWznmQVerVer1NApp*) tblwznmqverver1napp)->init(dbsMy);
	tblwznmqverver1nerror = new MyTblWznmQVerVer1NError();
	((MyTblWznmQVerVer1NError*) tblwznmqverver1nerror)->init(dbsMy);
	tblwznmqverver1nmodule = new MyTblWznmQVerVer1NModule();
	((MyTblWznmQVerVer1NModule*) tblwznmqverver1nmodule)->init(dbsMy);
	tblwznmqvitlist = new MyTblWznmQVitList();
	((MyTblWznmQVitList*) tblwznmqvitlist)->init(dbsMy);
};

void DbsWznm::termMy() {
	mysql_close(dbsMy);
	mysql_thread_end();
};
#endif

#if defined(SBECORE_PG)
void DbsWznm::initPg() {
	// connect to PostgreSQL database
	dbsPg = PQsetdbLogin(ip.c_str(), to_string(port).c_str(), NULL, NULL, dbsname.c_str(), username.c_str(), password.c_str());

	if (PQstatus(dbsPg) == CONNECTION_BAD) {
		string dbms = "DbsWznm::initPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_CONN, {{"dbms",dbms}});
	};

	tblwznmaccrmuseruniversal = new PgTblWznmAccRMUserUniversal();
	((PgTblWznmAccRMUserUniversal*) tblwznmaccrmuseruniversal)->init(dbsPg);
	tblwznmamblockitem = new PgTblWznmAMBlockItem();
	((PgTblWznmAMBlockItem*) tblwznmamblockitem)->init(dbsPg);
	tblwznmamcapabilitypar = new PgTblWznmAMCapabilityPar();
	((PgTblWznmAMCapabilityPar*) tblwznmamcapabilitypar)->init(dbsPg);
	tblwznmamcontrolpar = new PgTblWznmAMControlPar();
	((PgTblWznmAMControlPar*) tblwznmamcontrolpar)->init(dbsPg);
	tblwznmamjobcmd = new PgTblWznmAMJobCmd();
	((PgTblWznmAMJobCmd*) tblwznmamjobcmd)->init(dbsPg);
	tblwznmamjobvar = new PgTblWznmAMJobVar();
	((PgTblWznmAMJobVar*) tblwznmamjobvar)->init(dbsPg);
	tblwznmamlibrarymakefile = new PgTblWznmAMLibraryMakefile();
	((PgTblWznmAMLibraryMakefile*) tblwznmamlibrarymakefile)->init(dbsPg);
	tblwznmamlibrarypkglist = new PgTblWznmAMLibraryPkglist();
	((PgTblWznmAMLibraryPkglist*) tblwznmamlibrarypkglist)->init(dbsPg);
	tblwznmammachinepar = new PgTblWznmAMMachinePar();
	((PgTblWznmAMMachinePar*) tblwznmammachinepar)->init(dbsPg);
	tblwznmammachtypemakefile = new PgTblWznmAMMachtypeMakefile();
	((PgTblWznmAMMachtypeMakefile*) tblwznmammachtypemakefile)->init(dbsPg);
	tblwznmammethodinvpar = new PgTblWznmAMMethodInvpar();
	((PgTblWznmAMMethodInvpar*) tblwznmammethodinvpar)->init(dbsPg);
	tblwznmammethodretpar = new PgTblWznmAMMethodRetpar();
	((PgTblWznmAMMethodRetpar*) tblwznmammethodretpar)->init(dbsPg);
	tblwznmamopinvarg = new PgTblWznmAMOpInvarg();
	((PgTblWznmAMOpInvarg*) tblwznmamopinvarg)->init(dbsPg);
	tblwznmamoppackinvarg = new PgTblWznmAMOppackInvarg();
	((PgTblWznmAMOppackInvarg*) tblwznmamoppackinvarg)->init(dbsPg);
	tblwznmamoppackretval = new PgTblWznmAMOppackRetval();
	((PgTblWznmAMOppackRetval*) tblwznmamoppackretval)->init(dbsPg);
	tblwznmamopretval = new PgTblWznmAMOpRetval();
	((PgTblWznmAMOpRetval*) tblwznmamopretval)->init(dbsPg);
	tblwznmampersondetail = new PgTblWznmAMPersonDetail();
	((PgTblWznmAMPersonDetail*) tblwznmampersondetail)->init(dbsPg);
	tblwznmamqueryclause = new PgTblWznmAMQueryClause();
	((PgTblWznmAMQueryClause*) tblwznmamqueryclause)->init(dbsPg);
	tblwznmamqueryorder = new PgTblWznmAMQueryOrder();
	((PgTblWznmAMQueryOrder*) tblwznmamqueryorder)->init(dbsPg);
	tblwznmamrelationtitle = new PgTblWznmAMRelationTitle();
	((PgTblWznmAMRelationTitle*) tblwznmamrelationtitle)->init(dbsPg);
	tblwznmamstateaction = new PgTblWznmAMStateAction();
	((PgTblWznmAMStateAction*) tblwznmamstateaction)->init(dbsPg);
	tblwznmamstatetrig = new PgTblWznmAMStateTrig();
	((PgTblWznmAMStateTrig*) tblwznmamstatetrig)->init(dbsPg);
	tblwznmamsubsettitle = new PgTblWznmAMSubsetTitle();
	((PgTblWznmAMSubsetTitle*) tblwznmamsubsettitle)->init(dbsPg);
	tblwznmamtablecoltitle = new PgTblWznmAMTablecolTitle();
	((PgTblWznmAMTablecolTitle*) tblwznmamtablecoltitle)->init(dbsPg);
	tblwznmamtableloadfct = new PgTblWznmAMTableLoadfct();
	((PgTblWznmAMTableLoadfct*) tblwznmamtableloadfct)->init(dbsPg);
	tblwznmamtabletitle = new PgTblWznmAMTableTitle();
	((PgTblWznmAMTableTitle*) tblwznmamtabletitle)->init(dbsPg);
	tblwznmamuseraccess = new PgTblWznmAMUserAccess();
	((PgTblWznmAMUserAccess*) tblwznmamuseraccess)->init(dbsPg);
	tblwznmamusergroupaccess = new PgTblWznmAMUsergroupAccess();
	((PgTblWznmAMUsergroupAccess*) tblwznmamusergroupaccess)->init(dbsPg);
	tblwznmamvectortitle = new PgTblWznmAMVectorTitle();
	((PgTblWznmAMVectorTitle*) tblwznmamvectortitle)->init(dbsPg);
	tblwznmavcontrolpar = new PgTblWznmAVControlPar();
	((PgTblWznmAVControlPar*) tblwznmavcontrolpar)->init(dbsPg);
	tblwznmavkeylistkey = new PgTblWznmAVKeylistKey();
	((PgTblWznmAVKeylistKey*) tblwznmavkeylistkey)->init(dbsPg);
	tblwznmavvaluelistval = new PgTblWznmAVValuelistVal();
	((PgTblWznmAVValuelistVal*) tblwznmavvaluelistval)->init(dbsPg);
	tblwznmcamblockitem = new PgTblWznmCAMBlockItem();
	((PgTblWznmCAMBlockItem*) tblwznmcamblockitem)->init(dbsPg);
	tblwznmcamjobvar = new PgTblWznmCAMJobVar();
	((PgTblWznmCAMJobVar*) tblwznmcamjobvar)->init(dbsPg);
	tblwznmcamopinvarg = new PgTblWznmCAMOpInvarg();
	((PgTblWznmCAMOpInvarg*) tblwznmcamopinvarg)->init(dbsPg);
	tblwznmcamoppackinvarg = new PgTblWznmCAMOppackInvarg();
	((PgTblWznmCAMOppackInvarg*) tblwznmcamoppackinvarg)->init(dbsPg);
	tblwznmcamoppackretval = new PgTblWznmCAMOppackRetval();
	((PgTblWznmCAMOppackRetval*) tblwznmcamoppackretval)->init(dbsPg);
	tblwznmcamopretval = new PgTblWznmCAMOpRetval();
	((PgTblWznmCAMOpRetval*) tblwznmcamopretval)->init(dbsPg);
	tblwznmccontrol = new PgTblWznmCControl();
	((PgTblWznmCControl*) tblwznmccontrol)->init(dbsPg);
	tblwznmcfile = new PgTblWznmCFile();
	((PgTblWznmCFile*) tblwznmcfile)->init(dbsPg);
	tblwznmcrelation = new PgTblWznmCRelation();
	((PgTblWznmCRelation*) tblwznmcrelation)->init(dbsPg);
	tblwznmhistrmuseruniversal = new PgTblWznmHistRMUserUniversal();
	((PgTblWznmHistRMUserUniversal*) tblwznmhistrmuseruniversal)->init(dbsPg);
	tblwznmjamblockitem = new PgTblWznmJAMBlockItem();
	((PgTblWznmJAMBlockItem*) tblwznmjamblockitem)->init(dbsPg);
	tblwznmjamstatetrigcond = new PgTblWznmJAMStateTrigCond();
	((PgTblWznmJAMStateTrigCond*) tblwznmjamstatetrigcond)->init(dbsPg);
	tblwznmjavkeylistkey = new PgTblWznmJAVKeylistKey();
	((PgTblWznmJAVKeylistKey*) tblwznmjavkeylistkey)->init(dbsPg);
	tblwznmjmcardtitle = new PgTblWznmJMCardTitle();
	((PgTblWznmJMCardTitle*) tblwznmjmcardtitle)->init(dbsPg);
	tblwznmjmcontrol = new PgTblWznmJMControl();
	((PgTblWznmJMControl*) tblwznmjmcontrol)->init(dbsPg);
	tblwznmjmcontroltitle = new PgTblWznmJMControlTitle();
	((PgTblWznmJMControlTitle*) tblwznmjmcontroltitle)->init(dbsPg);
	tblwznmjmerrortitle = new PgTblWznmJMErrorTitle();
	((PgTblWznmJMErrorTitle*) tblwznmjmerrortitle)->init(dbsPg);
	tblwznmjmimpexpcolstub = new PgTblWznmJMImpexpcolStub();
	((PgTblWznmJMImpexpcolStub*) tblwznmjmimpexpcolstub)->init(dbsPg);
	tblwznmjmimpexpcplxtitle = new PgTblWznmJMImpexpcplxTitle();
	((PgTblWznmJMImpexpcplxTitle*) tblwznmjmimpexpcplxtitle)->init(dbsPg);
	tblwznmjmlocaletitle = new PgTblWznmJMLocaleTitle();
	((PgTblWznmJMLocaleTitle*) tblwznmjmlocaletitle)->init(dbsPg);
	tblwznmjmmodule = new PgTblWznmJMModule();
	((PgTblWznmJMModule*) tblwznmjmmodule)->init(dbsPg);
	tblwznmjmpersonlastname = new PgTblWznmJMPersonLastname();
	((PgTblWznmJMPersonLastname*) tblwznmjmpersonlastname)->init(dbsPg);
	tblwznmjmpresettitle = new PgTblWznmJMPresetTitle();
	((PgTblWznmJMPresetTitle*) tblwznmjmpresettitle)->init(dbsPg);
	tblwznmjmquerycolstub = new PgTblWznmJMQuerycolStub();
	((PgTblWznmJMQuerycolStub*) tblwznmjmquerycolstub)->init(dbsPg);
	tblwznmjmsquawktitle = new PgTblWznmJMSquawkTitle();
	((PgTblWznmJMSquawkTitle*) tblwznmjmsquawktitle)->init(dbsPg);
	tblwznmjmtagtitle = new PgTblWznmJMTagTitle();
	((PgTblWznmJMTagTitle*) tblwznmjmtagtitle)->init(dbsPg);
	tblwznmjmuserstate = new PgTblWznmJMUserState();
	((PgTblWznmJMUserState*) tblwznmjmuserstate)->init(dbsPg);
	tblwznmjmvectoritem = new PgTblWznmJMVectoritem();
	((PgTblWznmJMVectoritem*) tblwznmjmvectoritem)->init(dbsPg);
	tblwznmjmversion = new PgTblWznmJMVersion();
	((PgTblWznmJMVersion*) tblwznmjmversion)->init(dbsPg);
	tblwznmjmversionstate = new PgTblWznmJMVersionState();
	((PgTblWznmJMVersionState*) tblwznmjmversionstate)->init(dbsPg);
	tblwznmmapp = new PgTblWznmMApp();
	((PgTblWznmMApp*) tblwznmmapp)->init(dbsPg);
	tblwznmmblock = new PgTblWznmMBlock();
	((PgTblWznmMBlock*) tblwznmmblock)->init(dbsPg);
	tblwznmmcall = new PgTblWznmMCall();
	((PgTblWznmMCall*) tblwznmmcall)->init(dbsPg);
	tblwznmmcapability = new PgTblWznmMCapability();
	((PgTblWznmMCapability*) tblwznmmcapability)->init(dbsPg);
	tblwznmmcard = new PgTblWznmMCard();
	((PgTblWznmMCard*) tblwznmmcard)->init(dbsPg);
	tblwznmmcheck = new PgTblWznmMCheck();
	((PgTblWznmMCheck*) tblwznmmcheck)->init(dbsPg);
	tblwznmmcomponent = new PgTblWznmMComponent();
	((PgTblWznmMComponent*) tblwznmmcomponent)->init(dbsPg);
	tblwznmmcontrol = new PgTblWznmMControl();
	((PgTblWznmMControl*) tblwznmmcontrol)->init(dbsPg);
	tblwznmmdialog = new PgTblWznmMDialog();
	((PgTblWznmMDialog*) tblwznmmdialog)->init(dbsPg);
	tblwznmmerror = new PgTblWznmMError();
	((PgTblWznmMError*) tblwznmmerror)->init(dbsPg);
	tblwznmmevent = new PgTblWznmMEvent();
	((PgTblWznmMEvent*) tblwznmmevent)->init(dbsPg);
	tblwznmmfeed = new PgTblWznmMFeed();
	((PgTblWznmMFeed*) tblwznmmfeed)->init(dbsPg);
	tblwznmmfile = new PgTblWznmMFile();
	((PgTblWznmMFile*) tblwznmmfile)->init(dbsPg);
	tblwznmmimpexp = new PgTblWznmMImpexp();
	((PgTblWznmMImpexp*) tblwznmmimpexp)->init(dbsPg);
	tblwznmmimpexpcol = new PgTblWznmMImpexpcol();
	((PgTblWznmMImpexpcol*) tblwznmmimpexpcol)->init(dbsPg);
	tblwznmmimpexpcplx = new PgTblWznmMImpexpcplx();
	((PgTblWznmMImpexpcplx*) tblwznmmimpexpcplx)->init(dbsPg);
	tblwznmmjob = new PgTblWznmMJob();
	((PgTblWznmMJob*) tblwznmmjob)->init(dbsPg);
	tblwznmmlibrary = new PgTblWznmMLibrary();
	((PgTblWznmMLibrary*) tblwznmmlibrary)->init(dbsPg);
	tblwznmmlocale = new PgTblWznmMLocale();
	((PgTblWznmMLocale*) tblwznmmlocale)->init(dbsPg);
	tblwznmmmachine = new PgTblWznmMMachine();
	((PgTblWznmMMachine*) tblwznmmmachine)->init(dbsPg);
	tblwznmmmachtype = new PgTblWznmMMachtype();
	((PgTblWznmMMachtype*) tblwznmmmachtype)->init(dbsPg);
	tblwznmmmethod = new PgTblWznmMMethod();
	((PgTblWznmMMethod*) tblwznmmmethod)->init(dbsPg);
	tblwznmmmodule = new PgTblWznmMModule();
	((PgTblWznmMModule*) tblwznmmmodule)->init(dbsPg);
	tblwznmmop = new PgTblWznmMOp();
	((PgTblWznmMOp*) tblwznmmop)->init(dbsPg);
	tblwznmmoppack = new PgTblWznmMOppack();
	((PgTblWznmMOppack*) tblwznmmoppack)->init(dbsPg);
	tblwznmmpanel = new PgTblWznmMPanel();
	((PgTblWznmMPanel*) tblwznmmpanel)->init(dbsPg);
	tblwznmmperson = new PgTblWznmMPerson();
	((PgTblWznmMPerson*) tblwznmmperson)->init(dbsPg);
	tblwznmmpreset = new PgTblWznmMPreset();
	((PgTblWznmMPreset*) tblwznmmpreset)->init(dbsPg);
	tblwznmmproject = new PgTblWznmMProject();
	((PgTblWznmMProject*) tblwznmmproject)->init(dbsPg);
	tblwznmmquery = new PgTblWznmMQuery();
	((PgTblWznmMQuery*) tblwznmmquery)->init(dbsPg);
	tblwznmmquerycol = new PgTblWznmMQuerycol();
	((PgTblWznmMQuerycol*) tblwznmmquerycol)->init(dbsPg);
	tblwznmmquerymod = new PgTblWznmMQuerymod();
	((PgTblWznmMQuerymod*) tblwznmmquerymod)->init(dbsPg);
	tblwznmmrelation = new PgTblWznmMRelation();
	((PgTblWznmMRelation*) tblwznmmrelation)->init(dbsPg);
	tblwznmmrelease = new PgTblWznmMRelease();
	((PgTblWznmMRelease*) tblwznmmrelease)->init(dbsPg);
	tblwznmmrtblock = new PgTblWznmMRtblock();
	((PgTblWznmMRtblock*) tblwznmmrtblock)->init(dbsPg);
	tblwznmmrtdpch = new PgTblWznmMRtdpch();
	((PgTblWznmMRtdpch*) tblwznmmrtdpch)->init(dbsPg);
	tblwznmmrtjob = new PgTblWznmMRtjob();
	((PgTblWznmMRtjob*) tblwznmmrtjob)->init(dbsPg);
	tblwznmmsensitivity = new PgTblWznmMSensitivity();
	((PgTblWznmMSensitivity*) tblwznmmsensitivity)->init(dbsPg);
	tblwznmmsequence = new PgTblWznmMSequence();
	((PgTblWznmMSequence*) tblwznmmsequence)->init(dbsPg);
	tblwznmmsession = new PgTblWznmMSession();
	((PgTblWznmMSession*) tblwznmmsession)->init(dbsPg);
	tblwznmmsquawk = new PgTblWznmMSquawk();
	((PgTblWznmMSquawk*) tblwznmmsquawk)->init(dbsPg);
	tblwznmmstage = new PgTblWznmMStage();
	((PgTblWznmMStage*) tblwznmmstage)->init(dbsPg);
	tblwznmmstate = new PgTblWznmMState();
	((PgTblWznmMState*) tblwznmmstate)->init(dbsPg);
	tblwznmmstub = new PgTblWznmMStub();
	((PgTblWznmMStub*) tblwznmmstub)->init(dbsPg);
	tblwznmmsubset = new PgTblWznmMSubset();
	((PgTblWznmMSubset*) tblwznmmsubset)->init(dbsPg);
	tblwznmmtable = new PgTblWznmMTable();
	((PgTblWznmMTable*) tblwznmmtable)->init(dbsPg);
	tblwznmmtablecol = new PgTblWznmMTablecol();
	((PgTblWznmMTablecol*) tblwznmmtablecol)->init(dbsPg);
	tblwznmmtag = new PgTblWznmMTag();
	((PgTblWznmMTag*) tblwznmmtag)->init(dbsPg);
	tblwznmmuser = new PgTblWznmMUser();
	((PgTblWznmMUser*) tblwznmmuser)->init(dbsPg);
	tblwznmmusergroup = new PgTblWznmMUsergroup();
	((PgTblWznmMUsergroup*) tblwznmmusergroup)->init(dbsPg);
	tblwznmmvector = new PgTblWznmMVector();
	((PgTblWznmMVector*) tblwznmmvector)->init(dbsPg);
	tblwznmmvectoritem = new PgTblWznmMVectoritem();
	((PgTblWznmMVectoritem*) tblwznmmvectoritem)->init(dbsPg);
	tblwznmmversion = new PgTblWznmMVersion();
	((PgTblWznmMVersion*) tblwznmmversion)->init(dbsPg);
	tblwznmrmcallmstub = new PgTblWznmRMCallMStub();
	((PgTblWznmRMCallMStub*) tblwznmrmcallmstub)->init(dbsPg);
	tblwznmrmcapabilityuniversal = new PgTblWznmRMCapabilityUniversal();
	((PgTblWznmRMCapabilityUniversal*) tblwznmrmcapabilityuniversal)->init(dbsPg);
	tblwznmrmcomponentmlibrary = new PgTblWznmRMComponentMLibrary();
	((PgTblWznmRMComponentMLibrary*) tblwznmrmcomponentmlibrary)->init(dbsPg);
	tblwznmrmcomponentmoppack = new PgTblWznmRMComponentMOppack();
	((PgTblWznmRMComponentMOppack*) tblwznmrmcomponentmoppack)->init(dbsPg);
	tblwznmrmdialogmquery = new PgTblWznmRMDialogMQuery();
	((PgTblWznmRMDialogMQuery*) tblwznmrmdialogmquery)->init(dbsPg);
	tblwznmrmjobmjob = new PgTblWznmRMJobMJob();
	((PgTblWznmRMJobMJob*) tblwznmrmjobmjob)->init(dbsPg);
	tblwznmrmjobmop = new PgTblWznmRMJobMOp();
	((PgTblWznmRMJobMOp*) tblwznmrmjobmop)->init(dbsPg);
	tblwznmrmjobmoppack = new PgTblWznmRMJobMOppack();
	((PgTblWznmRMJobMOppack*) tblwznmrmjobmoppack)->init(dbsPg);
	tblwznmrmlibrarymoppack = new PgTblWznmRMLibraryMOppack();
	((PgTblWznmRMLibraryMOppack*) tblwznmrmlibrarymoppack)->init(dbsPg);
	tblwznmrmlocalemversion = new PgTblWznmRMLocaleMVersion();
	((PgTblWznmRMLocaleMVersion*) tblwznmrmlocalemversion)->init(dbsPg);
	tblwznmrmpanelmquery = new PgTblWznmRMPanelMQuery();
	((PgTblWznmRMPanelMQuery*) tblwznmrmpanelmquery)->init(dbsPg);
	tblwznmrmpersonmproject = new PgTblWznmRMPersonMProject();
	((PgTblWznmRMPersonMProject*) tblwznmrmpersonmproject)->init(dbsPg);
	tblwznmrmquerymtable = new PgTblWznmRMQueryMTable();
	((PgTblWznmRMQueryMTable*) tblwznmrmquerymtable)->init(dbsPg);
	tblwznmrmsquawkmstub = new PgTblWznmRMSquawkMStub();
	((PgTblWznmRMSquawkMStub*) tblwznmrmsquawkmstub)->init(dbsPg);
	tblwznmrmstubmstub = new PgTblWznmRMStubMStub();
	((PgTblWznmRMStubMStub*) tblwznmrmstubmstub)->init(dbsPg);
	tblwznmrmsubsetmsubset = new PgTblWznmRMSubsetMSubset();
	((PgTblWznmRMSubsetMSubset*) tblwznmrmsubsetmsubset)->init(dbsPg);
	tblwznmrmtablemvector = new PgTblWznmRMTableMVector();
	((PgTblWznmRMTableMVector*) tblwznmrmtablemvector)->init(dbsPg);
	tblwznmrmusergroupuniversal = new PgTblWznmRMUsergroupUniversal();
	((PgTblWznmRMUsergroupUniversal*) tblwznmrmusergroupuniversal)->init(dbsPg);
	tblwznmrmusermusergroup = new PgTblWznmRMUserMUsergroup();
	((PgTblWznmRMUserMUsergroup*) tblwznmrmusermusergroup)->init(dbsPg);
	tblwznmtmquerymodmquery = new PgTblWznmTMQuerymodMQuery();
	((PgTblWznmTMQuerymodMQuery*) tblwznmtmquerymodmquery)->init(dbsPg);

	tblwznmqapp1nevent = new PgTblWznmQApp1NEvent();
	((PgTblWznmQApp1NEvent*) tblwznmqapp1nevent)->init(dbsPg);
	tblwznmqapp1nrtjob = new PgTblWznmQApp1NRtjob();
	((PgTblWznmQApp1NRtjob*) tblwznmqapp1nrtjob)->init(dbsPg);
	tblwznmqappapp1nsequence = new PgTblWznmQAppApp1NSequence();
	((PgTblWznmQAppApp1NSequence*) tblwznmqappapp1nsequence)->init(dbsPg);
	tblwznmqapplist = new PgTblWznmQAppList();
	((PgTblWznmQAppList*) tblwznmqapplist)->init(dbsPg);
	tblwznmqappref1nfile = new PgTblWznmQAppRef1NFile();
	((PgTblWznmQAppRef1NFile*) tblwznmqappref1nfile)->init(dbsPg);
	tblwznmqblk1nrtdpch = new PgTblWznmQBlk1NRtdpch();
	((PgTblWznmQBlk1NRtdpch*) tblwznmqblk1nrtdpch)->init(dbsPg);
	tblwznmqblkaitem = new PgTblWznmQBlkAItem();
	((PgTblWznmQBlkAItem*) tblwznmqblkaitem)->init(dbsPg);
	tblwznmqblklist = new PgTblWznmQBlkList();
	((PgTblWznmQBlkList*) tblwznmqblklist)->init(dbsPg);
	tblwznmqblkref1nrtblock = new PgTblWznmQBlkRef1NRtblock();
	((PgTblWznmQBlkRef1NRtblock*) tblwznmqblkref1nrtblock)->init(dbsPg);
	tblwznmqcal1nsensitivity = new PgTblWznmQCal1NSensitivity();
	((PgTblWznmQCal1NSensitivity*) tblwznmqcal1nsensitivity)->init(dbsPg);
	tblwznmqcallist = new PgTblWznmQCalList();
	((PgTblWznmQCalList*) tblwznmqcallist)->init(dbsPg);
	tblwznmqcalmnstub = new PgTblWznmQCalMNStub();
	((PgTblWznmQCalMNStub*) tblwznmqcalmnstub)->init(dbsPg);
	tblwznmqcapapar = new PgTblWznmQCapAPar();
	((PgTblWznmQCapAPar*) tblwznmqcapapar)->init(dbsPg);
	tblwznmqcaplist = new PgTblWznmQCapList();
	((PgTblWznmQCapList*) tblwznmqcaplist)->init(dbsPg);
	tblwznmqcar1ndialog = new PgTblWznmQCar1NDialog();
	((PgTblWznmQCar1NDialog*) tblwznmqcar1ndialog)->init(dbsPg);
	tblwznmqcarcar1npanel = new PgTblWznmQCarCar1NPanel();
	((PgTblWznmQCarCar1NPanel*) tblwznmqcarcar1npanel)->init(dbsPg);
	tblwznmqcarhk1ncontrol = new PgTblWznmQCarHk1NControl();
	((PgTblWznmQCarHk1NControl*) tblwznmqcarhk1ncontrol)->init(dbsPg);
	tblwznmqcarlist = new PgTblWznmQCarList();
	((PgTblWznmQCarList*) tblwznmqcarlist)->init(dbsPg);
	tblwznmqchklist = new PgTblWznmQChkList();
	((PgTblWznmQChkList*) tblwznmqchklist)->init(dbsPg);
	tblwznmqchkref1ncall = new PgTblWznmQChkRef1NCall();
	((PgTblWznmQChkRef1NCall*) tblwznmqchkref1ncall)->init(dbsPg);
	tblwznmqcmp1nrelease = new PgTblWznmQCmp1NRelease();
	((PgTblWznmQCmp1NRelease*) tblwznmqcmp1nrelease)->init(dbsPg);
	tblwznmqcmplist = new PgTblWznmQCmpList();
	((PgTblWznmQCmpList*) tblwznmqcmplist)->init(dbsPg);
	tblwznmqcmpmnlibrary = new PgTblWznmQCmpMNLibrary();
	((PgTblWznmQCmpMNLibrary*) tblwznmqcmpmnlibrary)->init(dbsPg);
	tblwznmqcmpmnoppack = new PgTblWznmQCmpMNOppack();
	((PgTblWznmQCmpMNOppack*) tblwznmqcmpmnoppack)->init(dbsPg);
	tblwznmqconapar = new PgTblWznmQConAPar();
	((PgTblWznmQConAPar*) tblwznmqconapar)->init(dbsPg);
	tblwznmqconfedref1nrtblock = new PgTblWznmQConFedRef1NRtblock();
	((PgTblWznmQConFedRef1NRtblock*) tblwznmqconfedref1nrtblock)->init(dbsPg);
	tblwznmqconlist = new PgTblWznmQConList();
	((PgTblWznmQConList*) tblwznmqconlist)->init(dbsPg);
	tblwznmqconsup1ncontrol = new PgTblWznmQConSup1NControl();
	((PgTblWznmQConSup1NControl*) tblwznmqconsup1ncontrol)->init(dbsPg);
	tblwznmqctp1ntag = new PgTblWznmQCtp1NTag();
	((PgTblWznmQCtp1NTag*) tblwznmqctp1ntag)->init(dbsPg);
	tblwznmqctpapar = new PgTblWznmQCtpAPar();
	((PgTblWznmQCtpAPar*) tblwznmqctpapar)->init(dbsPg);
	tblwznmqctpkkey = new PgTblWznmQCtpKKey();
	((PgTblWznmQCtpKKey*) tblwznmqctpkkey)->init(dbsPg);
	tblwznmqctpkparkey = new PgTblWznmQCtpKParKey();
	((PgTblWznmQCtpKParKey*) tblwznmqctpkparkey)->init(dbsPg);
	tblwznmqctplist = new PgTblWznmQCtpList();
	((PgTblWznmQCtpList*) tblwznmqctplist)->init(dbsPg);
	tblwznmqctptpl1ncapability = new PgTblWznmQCtpTpl1NCapability();
	((PgTblWznmQCtpTpl1NCapability*) tblwznmqctptpl1ncapability)->init(dbsPg);
	tblwznmqdlghk1ncontrol = new PgTblWznmQDlgHk1NControl();
	((PgTblWznmQDlgHk1NControl*) tblwznmqdlghk1ncontrol)->init(dbsPg);
	tblwznmqdlglist = new PgTblWznmQDlgList();
	((PgTblWznmQDlgList*) tblwznmqdlglist)->init(dbsPg);
	tblwznmqdlgmnquery = new PgTblWznmQDlgMNQuery();
	((PgTblWznmQDlgMNQuery*) tblwznmqdlgmnquery)->init(dbsPg);
	tblwznmqdlgref1ncontrol = new PgTblWznmQDlgRef1NControl();
	((PgTblWznmQDlgRef1NControl*) tblwznmqdlgref1ncontrol)->init(dbsPg);
	tblwznmqerrlist = new PgTblWznmQErrList();
	((PgTblWznmQErrList*) tblwznmqerrlist)->init(dbsPg);
	tblwznmqevtlist = new PgTblWznmQEvtList();
	((PgTblWznmQEvtList*) tblwznmqevtlist)->init(dbsPg);
	tblwznmqfillist = new PgTblWznmQFilList();
	((PgTblWznmQFilList*) tblwznmqfillist)->init(dbsPg);
	tblwznmqiellist = new PgTblWznmQIelList();
	((PgTblWznmQIelList*) tblwznmqiellist)->init(dbsPg);
	tblwznmqiex1nimpexp = new PgTblWznmQIex1NImpexp();
	((PgTblWznmQIex1NImpexp*) tblwznmqiex1nimpexp)->init(dbsPg);
	tblwznmqiexhk1nvector = new PgTblWznmQIexHk1NVector();
	((PgTblWznmQIexHk1NVector*) tblwznmqiexhk1nvector)->init(dbsPg);
	tblwznmqiexlist = new PgTblWznmQIexList();
	((PgTblWznmQIexList*) tblwznmqiexlist)->init(dbsPg);
	tblwznmqiexref1ndialog = new PgTblWznmQIexRef1NDialog();
	((PgTblWznmQIexRef1NDialog*) tblwznmqiexref1ndialog)->init(dbsPg);
	tblwznmqimehk1nvector = new PgTblWznmQImeHk1NVector();
	((PgTblWznmQImeHk1NVector*) tblwznmqimehk1nvector)->init(dbsPg);
	tblwznmqimeime1nimpexpcol = new PgTblWznmQImeIme1NImpexpcol();
	((PgTblWznmQImeIme1NImpexpcol*) tblwznmqimeime1nimpexpcol)->init(dbsPg);
	tblwznmqimelist = new PgTblWznmQImeList();
	((PgTblWznmQImeList*) tblwznmqimelist)->init(dbsPg);
	tblwznmqimesup1nimpexp = new PgTblWznmQImeSup1NImpexp();
	((PgTblWznmQImeSup1NImpexp*) tblwznmqimesup1nimpexp)->init(dbsPg);
	tblwznmqjob1nmethod = new PgTblWznmQJob1NMethod();
	((PgTblWznmQJob1NMethod*) tblwznmqjob1nmethod)->init(dbsPg);
	tblwznmqjob1nrtjob = new PgTblWznmQJob1NRtjob();
	((PgTblWznmQJob1NRtjob*) tblwznmqjob1nrtjob)->init(dbsPg);
	tblwznmqjob1nsensitivity = new PgTblWznmQJob1NSensitivity();
	((PgTblWznmQJob1NSensitivity*) tblwznmqjob1nsensitivity)->init(dbsPg);
	tblwznmqjobacmd = new PgTblWznmQJobACmd();
	((PgTblWznmQJobACmd*) tblwznmqjobacmd)->init(dbsPg);
	tblwznmqjobavar = new PgTblWznmQJobAVar();
	((PgTblWznmQJobAVar*) tblwznmqjobavar)->init(dbsPg);
	tblwznmqjobhk1nvector = new PgTblWznmQJobHk1NVector();
	((PgTblWznmQJobHk1NVector*) tblwznmqjobhk1nvector)->init(dbsPg);
	tblwznmqjobjob1nstage = new PgTblWznmQJobJob1NStage();
	((PgTblWznmQJobJob1NStage*) tblwznmqjobjob1nstage)->init(dbsPg);
	tblwznmqjoblist = new PgTblWznmQJobList();
	((PgTblWznmQJobList*) tblwznmqjoblist)->init(dbsPg);
	tblwznmqjobmnop = new PgTblWznmQJobMNOp();
	((PgTblWznmQJobMNOp*) tblwznmqjobmnop)->init(dbsPg);
	tblwznmqjobmnoppack = new PgTblWznmQJobMNOppack();
	((PgTblWznmQJobMNOppack*) tblwznmqjobmnoppack)->init(dbsPg);
	tblwznmqjobref1nblock = new PgTblWznmQJobRef1NBlock();
	((PgTblWznmQJobRef1NBlock*) tblwznmqjobref1nblock)->init(dbsPg);
	tblwznmqjobsubmnjob = new PgTblWznmQJobSubMNJob();
	((PgTblWznmQJobSubMNJob*) tblwznmqjobsubmnjob)->init(dbsPg);
	tblwznmqjobsupmnjob = new PgTblWznmQJobSupMNJob();
	((PgTblWznmQJobSupMNJob*) tblwznmqjobsupmnjob)->init(dbsPg);
	tblwznmqlibamakefile = new PgTblWznmQLibAMakefile();
	((PgTblWznmQLibAMakefile*) tblwznmqlibamakefile)->init(dbsPg);
	tblwznmqlibapkglist = new PgTblWznmQLibAPkglist();
	((PgTblWznmQLibAPkglist*) tblwznmqlibapkglist)->init(dbsPg);
	tblwznmqliblist = new PgTblWznmQLibList();
	((PgTblWznmQLibList*) tblwznmqliblist)->init(dbsPg);
	tblwznmqlibmncomponent = new PgTblWznmQLibMNComponent();
	((PgTblWznmQLibMNComponent*) tblwznmqlibmncomponent)->init(dbsPg);
	tblwznmqlibmnoppack = new PgTblWznmQLibMNOppack();
	((PgTblWznmQLibMNOppack*) tblwznmqlibmnoppack)->init(dbsPg);
	tblwznmqlibref1nfile = new PgTblWznmQLibRef1NFile();
	((PgTblWznmQLibRef1NFile*) tblwznmqlibref1nfile)->init(dbsPg);
	tblwznmqloclist = new PgTblWznmQLocList();
	((PgTblWznmQLocList*) tblwznmqloclist)->init(dbsPg);
	tblwznmqlocmnversion = new PgTblWznmQLocMNVersion();
	((PgTblWznmQLocMNVersion*) tblwznmqlocmnversion)->init(dbsPg);
	tblwznmqmch1nrelease = new PgTblWznmQMch1NRelease();
	((PgTblWznmQMch1NRelease*) tblwznmqmch1nrelease)->init(dbsPg);
	tblwznmqmchapar = new PgTblWznmQMchAPar();
	((PgTblWznmQMchAPar*) tblwznmqmchapar)->init(dbsPg);
	tblwznmqmchlist = new PgTblWznmQMchList();
	((PgTblWznmQMchList*) tblwznmqmchlist)->init(dbsPg);
	tblwznmqmdllist = new PgTblWznmQMdlList();
	((PgTblWznmQMdlList*) tblwznmqmdllist)->init(dbsPg);
	tblwznmqmdlmdl1ncard = new PgTblWznmQMdlMdl1NCard();
	((PgTblWznmQMdlMdl1NCard*) tblwznmqmdlmdl1ncard)->init(dbsPg);
	tblwznmqmdlref1npanel = new PgTblWznmQMdlRef1NPanel();
	((PgTblWznmQMdlRef1NPanel*) tblwznmqmdlref1npanel)->init(dbsPg);
	tblwznmqmtdainvpar = new PgTblWznmQMtdAInvpar();
	((PgTblWznmQMtdAInvpar*) tblwznmqmtdainvpar)->init(dbsPg);
	tblwznmqmtdaretpar = new PgTblWznmQMtdARetpar();
	((PgTblWznmQMtdARetpar*) tblwznmqmtdaretpar)->init(dbsPg);
	tblwznmqmtdlist = new PgTblWznmQMtdList();
	((PgTblWznmQMtdList*) tblwznmqmtdlist)->init(dbsPg);
	tblwznmqmty1nmachine = new PgTblWznmQMty1NMachine();
	((PgTblWznmQMty1NMachine*) tblwznmqmty1nmachine)->init(dbsPg);
	tblwznmqmtyamakefile = new PgTblWznmQMtyAMakefile();
	((PgTblWznmQMtyAMakefile*) tblwznmqmtyamakefile)->init(dbsPg);
	tblwznmqmtylist = new PgTblWznmQMtyList();
	((PgTblWznmQMtyList*) tblwznmqmtylist)->init(dbsPg);
	tblwznmqopk1nop = new PgTblWznmQOpk1NOp();
	((PgTblWznmQOpk1NOp*) tblwznmqopk1nop)->init(dbsPg);
	tblwznmqopkainvarg = new PgTblWznmQOpkAInvarg();
	((PgTblWznmQOpkAInvarg*) tblwznmqopkainvarg)->init(dbsPg);
	tblwznmqopkaretval = new PgTblWznmQOpkARetval();
	((PgTblWznmQOpkARetval*) tblwznmqopkaretval)->init(dbsPg);
	tblwznmqopklist = new PgTblWznmQOpkList();
	((PgTblWznmQOpkList*) tblwznmqopklist)->init(dbsPg);
	tblwznmqopkmncomponent = new PgTblWznmQOpkMNComponent();
	((PgTblWznmQOpkMNComponent*) tblwznmqopkmncomponent)->init(dbsPg);
	tblwznmqopkmnjob = new PgTblWznmQOpkMNJob();
	((PgTblWznmQOpkMNJob*) tblwznmqopkmnjob)->init(dbsPg);
	tblwznmqopkmnlibrary = new PgTblWznmQOpkMNLibrary();
	((PgTblWznmQOpkMNLibrary*) tblwznmqopkmnlibrary)->init(dbsPg);
	tblwznmqopkref1nblock = new PgTblWznmQOpkRef1NBlock();
	((PgTblWznmQOpkRef1NBlock*) tblwznmqopkref1nblock)->init(dbsPg);
	tblwznmqopksqkmnstub = new PgTblWznmQOpkSqkMNStub();
	((PgTblWznmQOpkSqkMNStub*) tblwznmqopksqkmnstub)->init(dbsPg);
	tblwznmqopxainvarg = new PgTblWznmQOpxAInvarg();
	((PgTblWznmQOpxAInvarg*) tblwznmqopxainvarg)->init(dbsPg);
	tblwznmqopxaretval = new PgTblWznmQOpxARetval();
	((PgTblWznmQOpxARetval*) tblwznmqopxaretval)->init(dbsPg);
	tblwznmqopxlist = new PgTblWznmQOpxList();
	((PgTblWznmQOpxList*) tblwznmqopxlist)->init(dbsPg);
	tblwznmqopxmnjob = new PgTblWznmQOpxMNJob();
	((PgTblWznmQOpxMNJob*) tblwznmqopxmnjob)->init(dbsPg);
	tblwznmqopxref1nblock = new PgTblWznmQOpxRef1NBlock();
	((PgTblWznmQOpxRef1NBlock*) tblwznmqopxref1nblock)->init(dbsPg);
	tblwznmqopxsqkmnstub = new PgTblWznmQOpxSqkMNStub();
	((PgTblWznmQOpxSqkMNStub*) tblwznmqopxsqkmnstub)->init(dbsPg);
	tblwznmqpnlhk1ncontrol = new PgTblWznmQPnlHk1NControl();
	((PgTblWznmQPnlHk1NControl*) tblwznmqpnlhk1ncontrol)->init(dbsPg);
	tblwznmqpnllist = new PgTblWznmQPnlList();
	((PgTblWznmQPnlList*) tblwznmqpnllist)->init(dbsPg);
	tblwznmqpnlmnquery = new PgTblWznmQPnlMNQuery();
	((PgTblWznmQPnlMNQuery*) tblwznmqpnlmnquery)->init(dbsPg);
	tblwznmqpreselect = new PgTblWznmQPreselect();
	((PgTblWznmQPreselect*) tblwznmqpreselect)->init(dbsPg);
	tblwznmqprj1nversion = new PgTblWznmQPrj1NVersion();
	((PgTblWznmQPrj1NVersion*) tblwznmqprj1nversion)->init(dbsPg);
	tblwznmqprjlist = new PgTblWznmQPrjList();
	((PgTblWznmQPrjList*) tblwznmqprjlist)->init(dbsPg);
	tblwznmqprjmnperson = new PgTblWznmQPrjMNPerson();
	((PgTblWznmQPrjMNPerson*) tblwznmqprjmnperson)->init(dbsPg);
	tblwznmqprsadetail = new PgTblWznmQPrsADetail();
	((PgTblWznmQPrsADetail*) tblwznmqprsadetail)->init(dbsPg);
	tblwznmqprslist = new PgTblWznmQPrsList();
	((PgTblWznmQPrsList*) tblwznmqprslist)->init(dbsPg);
	tblwznmqprsmnproject = new PgTblWznmQPrsMNProject();
	((PgTblWznmQPrsMNProject*) tblwznmqprsmnproject)->init(dbsPg);
	tblwznmqpst1nquerymod = new PgTblWznmQPst1NQuerymod();
	((PgTblWznmQPst1NQuerymod*) tblwznmqpst1nquerymod)->init(dbsPg);
	tblwznmqpstlist = new PgTblWznmQPstList();
	((PgTblWznmQPstList*) tblwznmqpstlist)->init(dbsPg);
	tblwznmqqcolist = new PgTblWznmQQcoList();
	((PgTblWznmQQcoList*) tblwznmqqcolist)->init(dbsPg);
	tblwznmqqcoref1ncontrol = new PgTblWznmQQcoRef1NControl();
	((PgTblWznmQQcoRef1NControl*) tblwznmqqcoref1ncontrol)->init(dbsPg);
	tblwznmqqmdlist = new PgTblWznmQQmdList();
	((PgTblWznmQQmdList*) tblwznmqqmdlist)->init(dbsPg);
	tblwznmqqry1nquerymod = new PgTblWznmQQry1NQuerymod();
	((PgTblWznmQQry1NQuerymod*) tblwznmqqry1nquerymod)->init(dbsPg);
	tblwznmqqryaclause = new PgTblWznmQQryAClause();
	((PgTblWznmQQryAClause*) tblwznmqqryaclause)->init(dbsPg);
	tblwznmqqryaorder = new PgTblWznmQQryAOrder();
	((PgTblWznmQQryAOrder*) tblwznmqqryaorder)->init(dbsPg);
	tblwznmqqrylist = new PgTblWznmQQryList();
	((PgTblWznmQQryList*) tblwznmqqrylist)->init(dbsPg);
	tblwznmqqrymndialog = new PgTblWznmQQryMNDialog();
	((PgTblWznmQQryMNDialog*) tblwznmqqrymndialog)->init(dbsPg);
	tblwznmqqrymnpanel = new PgTblWznmQQryMNPanel();
	((PgTblWznmQQryMNPanel*) tblwznmqqrymnpanel)->init(dbsPg);
	tblwznmqqrymntable = new PgTblWznmQQryMNTable();
	((PgTblWznmQQryMNTable*) tblwznmqqrymntable)->init(dbsPg);
	tblwznmqqryqry1nquerycol = new PgTblWznmQQryQry1NQuerycol();
	((PgTblWznmQQryQry1NQuerycol*) tblwznmqqryqry1nquerycol)->init(dbsPg);
	tblwznmqqrysup1nquery = new PgTblWznmQQrySup1NQuery();
	((PgTblWznmQQrySup1NQuery*) tblwznmqqrysup1nquery)->init(dbsPg);
	tblwznmqrel1ntablecol = new PgTblWznmQRel1NTablecol();
	((PgTblWznmQRel1NTablecol*) tblwznmqrel1ntablecol)->init(dbsPg);
	tblwznmqrelatitle = new PgTblWznmQRelATitle();
	((PgTblWznmQRelATitle*) tblwznmqrelatitle)->init(dbsPg);
	tblwznmqrellist = new PgTblWznmQRelList();
	((PgTblWznmQRelList*) tblwznmqrellist)->init(dbsPg);
	tblwznmqrelref1ncontrol = new PgTblWznmQRelRef1NControl();
	((PgTblWznmQRelRef1NControl*) tblwznmqrelref1ncontrol)->init(dbsPg);
	tblwznmqrelref1ndialog = new PgTblWznmQRelRef1NDialog();
	((PgTblWznmQRelRef1NDialog*) tblwznmqrelref1ndialog)->init(dbsPg);
	tblwznmqrelref1npanel = new PgTblWznmQRelRef1NPanel();
	((PgTblWznmQRelRef1NPanel*) tblwznmqrelref1npanel)->init(dbsPg);
	tblwznmqrelsup1nrelation = new PgTblWznmQRelSup1NRelation();
	((PgTblWznmQRelSup1NRelation*) tblwznmqrelsup1nrelation)->init(dbsPg);
	tblwznmqrlslist = new PgTblWznmQRlsList();
	((PgTblWznmQRlsList*) tblwznmqrlslist)->init(dbsPg);
	tblwznmqrtj1nrtblock = new PgTblWznmQRtj1NRtblock();
	((PgTblWznmQRtj1NRtblock*) tblwznmqrtj1nrtblock)->init(dbsPg);
	tblwznmqrtj1nrtdpch = new PgTblWznmQRtj1NRtdpch();
	((PgTblWznmQRtj1NRtdpch*) tblwznmqrtj1nrtdpch)->init(dbsPg);
	tblwznmqrtjlist = new PgTblWznmQRtjList();
	((PgTblWznmQRtjList*) tblwznmqrtjlist)->init(dbsPg);
	tblwznmqrtjsup1nrtjob = new PgTblWznmQRtjSup1NRtjob();
	((PgTblWznmQRtjSup1NRtjob*) tblwznmqrtjsup1nrtjob)->init(dbsPg);
	tblwznmqsbs1nstub = new PgTblWznmQSbs1NStub();
	((PgTblWznmQSbs1NStub*) tblwznmqsbs1nstub)->init(dbsPg);
	tblwznmqsbs1ntablecol = new PgTblWznmQSbs1NTablecol();
	((PgTblWznmQSbs1NTablecol*) tblwznmqsbs1ntablecol)->init(dbsPg);
	tblwznmqsbsasbmnsubset = new PgTblWznmQSbsAsbMNSubset();
	((PgTblWznmQSbsAsbMNSubset*) tblwznmqsbsasbmnsubset)->init(dbsPg);
	tblwznmqsbsatitle = new PgTblWznmQSbsATitle();
	((PgTblWznmQSbsATitle*) tblwznmqsbsatitle)->init(dbsPg);
	tblwznmqsbsbsbmnsubset = new PgTblWznmQSbsBsbMNSubset();
	((PgTblWznmQSbsBsbMNSubset*) tblwznmqsbsbsbmnsubset)->init(dbsPg);
	tblwznmqsbsfrs1nrelation = new PgTblWznmQSbsFrs1NRelation();
	((PgTblWznmQSbsFrs1NRelation*) tblwznmqsbsfrs1nrelation)->init(dbsPg);
	tblwznmqsbslist = new PgTblWznmQSbsList();
	((PgTblWznmQSbsList*) tblwznmqsbslist)->init(dbsPg);
	tblwznmqsbspst1nquerymod = new PgTblWznmQSbsPst1NQuerymod();
	((PgTblWznmQSbsPst1NQuerymod*) tblwznmqsbspst1nquerymod)->init(dbsPg);
	tblwznmqsbstos1nrelation = new PgTblWznmQSbsTos1NRelation();
	((PgTblWznmQSbsTos1NRelation*) tblwznmqsbstos1nrelation)->init(dbsPg);
	tblwznmqselect = new PgTblWznmQSelect();
	((PgTblWznmQSelect*) tblwznmqselect)->init(dbsPg);
	tblwznmqseqlist = new PgTblWznmQSeqList();
	((PgTblWznmQSeqList*) tblwznmqseqlist)->init(dbsPg);
	tblwznmqseqseq1nstate = new PgTblWznmQSeqSeq1NState();
	((PgTblWznmQSeqSeq1NState*) tblwznmqseqseq1nstate)->init(dbsPg);
	tblwznmqsge1nsensitivity = new PgTblWznmQSge1NSensitivity();
	((PgTblWznmQSge1NSensitivity*) tblwznmqsge1nsensitivity)->init(dbsPg);
	tblwznmqsgelist = new PgTblWznmQSgeList();
	((PgTblWznmQSgeList*) tblwznmqsgelist)->init(dbsPg);
	tblwznmqsgesqkmnstub = new PgTblWznmQSgeSqkMNStub();
	((PgTblWznmQSgeSqkMNStub*) tblwznmqsgesqkmnstub)->init(dbsPg);
	tblwznmqstblist = new PgTblWznmQStbList();
	((PgTblWznmQStbList*) tblwznmqstblist)->init(dbsPg);
	tblwznmqstbmncall = new PgTblWznmQStbMNCall();
	((PgTblWznmQStbMNCall*) tblwznmqstbmncall)->init(dbsPg);
	tblwznmqstbmnsquawk = new PgTblWznmQStbMNSquawk();
	((PgTblWznmQStbMNSquawk*) tblwznmqstbmnsquawk)->init(dbsPg);
	tblwznmqstbsubmnstub = new PgTblWznmQStbSubMNStub();
	((PgTblWznmQStbSubMNStub*) tblwznmqstbsubmnstub)->init(dbsPg);
	tblwznmqstbsupmnstub = new PgTblWznmQStbSupMNStub();
	((PgTblWznmQStbSupMNStub*) tblwznmqstbsupmnstub)->init(dbsPg);
	tblwznmqsteatrig = new PgTblWznmQSteATrig();
	((PgTblWznmQSteATrig*) tblwznmqsteatrig)->init(dbsPg);
	tblwznmqstelist = new PgTblWznmQSteList();
	((PgTblWznmQSteList*) tblwznmqstelist)->init(dbsPg);
	tblwznmqtaglist = new PgTblWznmQTagList();
	((PgTblWznmQTagList*) tblwznmqtaglist)->init(dbsPg);
	tblwznmqtbl1ncheck = new PgTblWznmQTbl1NCheck();
	((PgTblWznmQTbl1NCheck*) tblwznmqtbl1ncheck)->init(dbsPg);
	tblwznmqtbl1nimpexp = new PgTblWznmQTbl1NImpexp();
	((PgTblWznmQTbl1NImpexp*) tblwznmqtbl1nimpexp)->init(dbsPg);
	tblwznmqtbl1nstub = new PgTblWznmQTbl1NStub();
	((PgTblWznmQTbl1NStub*) tblwznmqtbl1nstub)->init(dbsPg);
	tblwznmqtbl1nsubset = new PgTblWznmQTbl1NSubset();
	((PgTblWznmQTbl1NSubset*) tblwznmqtbl1nsubset)->init(dbsPg);
	tblwznmqtblaloadfct = new PgTblWznmQTblALoadfct();
	((PgTblWznmQTblALoadfct*) tblwznmqtblaloadfct)->init(dbsPg);
	tblwznmqtblatitle = new PgTblWznmQTblATitle();
	((PgTblWznmQTblATitle*) tblwznmqtblatitle)->init(dbsPg);
	tblwznmqtblfct1ntablecol = new PgTblWznmQTblFct1NTablecol();
	((PgTblWznmQTblFct1NTablecol*) tblwznmqtblfct1ntablecol)->init(dbsPg);
	tblwznmqtblfr1nrelation = new PgTblWznmQTblFr1NRelation();
	((PgTblWznmQTblFr1NRelation*) tblwznmqtblfr1nrelation)->init(dbsPg);
	tblwznmqtblhk1nvector = new PgTblWznmQTblHk1NVector();
	((PgTblWznmQTblHk1NVector*) tblwznmqtblhk1nvector)->init(dbsPg);
	tblwznmqtbllist = new PgTblWznmQTblList();
	((PgTblWznmQTblList*) tblwznmqtbllist)->init(dbsPg);
	tblwznmqtblmnquery = new PgTblWznmQTblMNQuery();
	((PgTblWznmQTblMNQuery*) tblwznmqtblmnquery)->init(dbsPg);
	tblwznmqtblmnvector = new PgTblWznmQTblMNVector();
	((PgTblWznmQTblMNVector*) tblwznmqtblmnvector)->init(dbsPg);
	tblwznmqtblpst1nquerymod = new PgTblWznmQTblPst1NQuerymod();
	((PgTblWznmQTblPst1NQuerymod*) tblwznmqtblpst1nquerymod)->init(dbsPg);
	tblwznmqtblref1ncall = new PgTblWznmQTblRef1NCall();
	((PgTblWznmQTblRef1NCall*) tblwznmqtblref1ncall)->init(dbsPg);
	tblwznmqtblref1ndialog = new PgTblWznmQTblRef1NDialog();
	((PgTblWznmQTblRef1NDialog*) tblwznmqtblref1ndialog)->init(dbsPg);
	tblwznmqtblref1npanel = new PgTblWznmQTblRef1NPanel();
	((PgTblWznmQTblRef1NPanel*) tblwznmqtblref1npanel)->init(dbsPg);
	tblwznmqtblref1nquerymod = new PgTblWznmQTblRef1NQuerymod();
	((PgTblWznmQTblRef1NQuerymod*) tblwznmqtblref1nquerymod)->init(dbsPg);
	tblwznmqtblref1nrtblock = new PgTblWznmQTblRef1NRtblock();
	((PgTblWznmQTblRef1NRtblock*) tblwznmqtblref1nrtblock)->init(dbsPg);
	tblwznmqtblsrc1nfeed = new PgTblWznmQTblSrc1NFeed();
	((PgTblWznmQTblSrc1NFeed*) tblwznmqtblsrc1nfeed)->init(dbsPg);
	tblwznmqtbltbl1ntablecol = new PgTblWznmQTblTbl1NTablecol();
	((PgTblWznmQTblTbl1NTablecol*) tblwznmqtbltbl1ntablecol)->init(dbsPg);
	tblwznmqtblto1nrelation = new PgTblWznmQTblTo1NRelation();
	((PgTblWznmQTblTo1NRelation*) tblwznmqtblto1nrelation)->init(dbsPg);
	tblwznmqtco1ncheck = new PgTblWznmQTco1NCheck();
	((PgTblWznmQTco1NCheck*) tblwznmqtco1ncheck)->init(dbsPg);
	tblwznmqtco1nimpexpcol = new PgTblWznmQTco1NImpexpcol();
	((PgTblWznmQTco1NImpexpcol*) tblwznmqtco1nimpexpcol)->init(dbsPg);
	tblwznmqtco1nquerycol = new PgTblWznmQTco1NQuerycol();
	((PgTblWznmQTco1NQuerycol*) tblwznmqtco1nquerycol)->init(dbsPg);
	tblwznmqtcoatitle = new PgTblWznmQTcoATitle();
	((PgTblWznmQTcoATitle*) tblwznmqtcoatitle)->init(dbsPg);
	tblwznmqtcolist = new PgTblWznmQTcoList();
	((PgTblWznmQTcoList*) tblwznmqtcolist)->init(dbsPg);
	tblwznmqtcoref1ncontrol = new PgTblWznmQTcoRef1NControl();
	((PgTblWznmQTcoRef1NControl*) tblwznmqtcoref1ncontrol)->init(dbsPg);
	tblwznmqtcoref1nquerymod = new PgTblWznmQTcoRef1NQuerymod();
	((PgTblWznmQTcoRef1NQuerymod*) tblwznmqtcoref1nquerymod)->init(dbsPg);
	tblwznmqusgaaccess = new PgTblWznmQUsgAAccess();
	((PgTblWznmQUsgAAccess*) tblwznmqusgaaccess)->init(dbsPg);
	tblwznmqusglist = new PgTblWznmQUsgList();
	((PgTblWznmQUsgList*) tblwznmqusglist)->init(dbsPg);
	tblwznmqusgmnuser = new PgTblWznmQUsgMNUser();
	((PgTblWznmQUsgMNUser*) tblwznmqusgmnuser)->init(dbsPg);
	tblwznmqusr1nsession = new PgTblWznmQUsr1NSession();
	((PgTblWznmQUsr1NSession*) tblwznmqusr1nsession)->init(dbsPg);
	tblwznmqusraaccess = new PgTblWznmQUsrAAccess();
	((PgTblWznmQUsrAAccess*) tblwznmqusraaccess)->init(dbsPg);
	tblwznmqusrlist = new PgTblWznmQUsrList();
	((PgTblWznmQUsrList*) tblwznmqusrlist)->init(dbsPg);
	tblwznmqusrmnusergroup = new PgTblWznmQUsrMNUsergroup();
	((PgTblWznmQUsrMNUsergroup*) tblwznmqusrmnusergroup)->init(dbsPg);
	tblwznmqvecatitle = new PgTblWznmQVecATitle();
	((PgTblWznmQVecATitle*) tblwznmqvecatitle)->init(dbsPg);
	tblwznmqvecfct1ntablecol = new PgTblWznmQVecFct1NTablecol();
	((PgTblWznmQVecFct1NTablecol*) tblwznmqvecfct1ntablecol)->init(dbsPg);
	tblwznmqveclist = new PgTblWznmQVecList();
	((PgTblWznmQVecList*) tblwznmqveclist)->init(dbsPg);
	tblwznmqvecmntable = new PgTblWznmQVecMNTable();
	((PgTblWznmQVecMNTable*) tblwznmqvecmntable)->init(dbsPg);
	tblwznmqvecpst1nquerymod = new PgTblWznmQVecPst1NQuerymod();
	((PgTblWznmQVecPst1NQuerymod*) tblwznmqvecpst1nquerymod)->init(dbsPg);
	tblwznmqvecref1npanel = new PgTblWznmQVecRef1NPanel();
	((PgTblWznmQVecRef1NPanel*) tblwznmqvecref1npanel)->init(dbsPg);
	tblwznmqvecsrc1nfeed = new PgTblWznmQVecSrc1NFeed();
	((PgTblWznmQVecSrc1NFeed*) tblwznmqvecsrc1nfeed)->init(dbsPg);
	tblwznmqvecvec1nvectoritem = new PgTblWznmQVecVec1NVectoritem();
	((PgTblWznmQVecVec1NVectoritem*) tblwznmqvecvec1nvectoritem)->init(dbsPg);
	tblwznmqver1nblock = new PgTblWznmQVer1NBlock();
	((PgTblWznmQVer1NBlock*) tblwznmqver1nblock)->init(dbsPg);
	tblwznmqver1ncall = new PgTblWznmQVer1NCall();
	((PgTblWznmQVer1NCall*) tblwznmqver1ncall)->init(dbsPg);
	tblwznmqver1ncapability = new PgTblWznmQVer1NCapability();
	((PgTblWznmQVer1NCapability*) tblwznmqver1ncapability)->init(dbsPg);
	tblwznmqver1ncomponent = new PgTblWznmQVer1NComponent();
	((PgTblWznmQVer1NComponent*) tblwznmqver1ncomponent)->init(dbsPg);
	tblwznmqver1nimpexpcplx = new PgTblWznmQVer1NImpexpcplx();
	((PgTblWznmQVer1NImpexpcplx*) tblwznmqver1nimpexpcplx)->init(dbsPg);
	tblwznmqver1njob = new PgTblWznmQVer1NJob();
	((PgTblWznmQVer1NJob*) tblwznmqver1njob)->init(dbsPg);
	tblwznmqver1noppack = new PgTblWznmQVer1NOppack();
	((PgTblWznmQVer1NOppack*) tblwznmqver1noppack)->init(dbsPg);
	tblwznmqver1npreset = new PgTblWznmQVer1NPreset();
	((PgTblWznmQVer1NPreset*) tblwznmqver1npreset)->init(dbsPg);
	tblwznmqver1nquery = new PgTblWznmQVer1NQuery();
	((PgTblWznmQVer1NQuery*) tblwznmqver1nquery)->init(dbsPg);
	tblwznmqver1nrelation = new PgTblWznmQVer1NRelation();
	((PgTblWznmQVer1NRelation*) tblwznmqver1nrelation)->init(dbsPg);
	tblwznmqver1ntable = new PgTblWznmQVer1NTable();
	((PgTblWznmQVer1NTable*) tblwznmqver1ntable)->init(dbsPg);
	tblwznmqver1nvector = new PgTblWznmQVer1NVector();
	((PgTblWznmQVer1NVector*) tblwznmqver1nvector)->init(dbsPg);
	tblwznmqverbvr1nversion = new PgTblWznmQVerBvr1NVersion();
	((PgTblWznmQVerBvr1NVersion*) tblwznmqverbvr1nversion)->init(dbsPg);
	tblwznmqverlist = new PgTblWznmQVerList();
	((PgTblWznmQVerList*) tblwznmqverlist)->init(dbsPg);
	tblwznmqvermnlocale = new PgTblWznmQVerMNLocale();
	((PgTblWznmQVerMNLocale*) tblwznmqvermnlocale)->init(dbsPg);
	tblwznmqverref1nfile = new PgTblWznmQVerRef1NFile();
	((PgTblWznmQVerRef1NFile*) tblwznmqverref1nfile)->init(dbsPg);
	tblwznmqverver1napp = new PgTblWznmQVerVer1NApp();
	((PgTblWznmQVerVer1NApp*) tblwznmqverver1napp)->init(dbsPg);
	tblwznmqverver1nerror = new PgTblWznmQVerVer1NError();
	((PgTblWznmQVerVer1NError*) tblwznmqverver1nerror)->init(dbsPg);
	tblwznmqverver1nmodule = new PgTblWznmQVerVer1NModule();
	((PgTblWznmQVerVer1NModule*) tblwznmqverver1nmodule)->init(dbsPg);
	tblwznmqvitlist = new PgTblWznmQVitList();
	((PgTblWznmQVitList*) tblwznmqvitlist)->init(dbsPg);
};

void DbsWznm::termPg() {
	PQfinish(dbsPg);
};
#endif

void DbsWznm::begin() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) beginMy();
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) beginPg();
#endif
};

bool DbsWznm::commit() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return commitMy();
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return commitPg();
#endif

	return false;
};

void DbsWznm::rollback() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) rollbackMy();
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) rollbackPg();
#endif
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
void DbsWznm::beginMy() {
	if (mysql_query(dbsMy, "BEGIN")) {
		string dbms = "DbsWznm::beginMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","BEGIN"}});
	};
};

bool DbsWznm::commitMy() {
	if (mysql_query(dbsMy, "COMMIT")) {
		rollbackMy();
		return false;
	};

	return true;
};

void DbsWznm::rollbackMy() {
	if (mysql_query(dbsMy, "ROLLBACK")) {
		string dbms = "DbsWznm::rollbackMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","ROLLBACK"}});
	};
};
#endif

#if defined(SBECORE_PG)
void DbsWznm::beginPg() {
	PGresult* res;

	res = PQexec(dbsPg, "BEGIN");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "DbsWznm::beginPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","BEGIN"}});
	};

	PQclear(res);
};

bool DbsWznm::commitPg() {
	PGresult* res;

	res = PQexec(dbsPg, "COMMIT");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		rollbackPg();

		PQclear(res);
		return false;
	};

	PQclear(res);
	return true;
};

void DbsWznm::rollbackPg() {
	PGresult* res;

	res = PQexec(dbsPg, "ROLLBACK");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "DbsWznm::rollbackPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","ROLLBACK"}});
	};

	PQclear(res);
};
#endif

bool DbsWznm::loadUintBySQL(
			const string& sqlstr
			, uint& val
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadUintBySQLMy(sqlstr, val);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadUintBySQLPg(sqlstr, val);
#endif

	return false;
};

bool DbsWznm::loadStringBySQL(
			const string& sqlstr
			, string& val
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadStringBySQLMy(sqlstr, val);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadStringBySQLPg(sqlstr, val);
#endif

	return false;
};

bool DbsWznm::loadRefBySQL(
			const string& sqlstr
			, ubigint& ref
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadRefBySQLMy(sqlstr, ref);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadRefBySQLPg(sqlstr, ref);
#endif

	return false;
};

ubigint DbsWznm::loadRefsBySQL(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadRefsBySQLMy(sqlstr, append, refs);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadRefsBySQLPg(sqlstr, append, refs);
#endif

	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
bool DbsWznm::loadUintBySQLMy(
			const string& sqlstr
			, uint& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWznm::loadUintBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWznm::loadUintBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		val = atol((char*) dbrow[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

bool DbsWznm::loadStringBySQLMy(
			const string& sqlstr
			, string& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWznm::loadStringBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWznm::loadStringBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);
		val.assign(dbrow[0], dblengths[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

bool DbsWznm::loadRefBySQLMy(
			const string& sqlstr
			, ubigint& ref
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWznm::loadRefBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWznm::loadRefBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		ref = atoll((char*) dbrow[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

ubigint DbsWznm::loadRefsBySQLMy(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWznm::loadRefsBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWznm::loadRefsBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);
	if (!append) refs.resize(0);

	refs.reserve(refs.size() + numrow);

	while (numread < numrow) {
		dbrow = mysql_fetch_row(dbresult);
		refs.push_back(atoll((char*) dbrow[0]));
		numread++;
	};

	mysql_free_result(dbresult);
	
	return(numread);
};
#endif

#if defined(SBECORE_PG)
bool DbsWznm::loadUintBySQLPg(
			const string& sqlstr
			, uint& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "DbsWznm::loadUintBySQLPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val = atol(ptr);

		retval = true;
	};

	PQclear(res);

	return retval;
};

bool DbsWznm::loadStringBySQLPg(
			const string& sqlstr
			, string& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;

	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "DbsWznm::loadStringBySQLPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val.assign(ptr, PQgetlength(res, 0, 0));

		retval = true;
	};

	PQclear(res);

	return retval;
};

bool DbsWznm::loadRefBySQLPg(
			const string& sqlstr
			, ubigint& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "DbsWznm::loadRefBySQLPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	return retval;
};

ubigint DbsWznm::loadRefsBySQLPg(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	PGresult* res; ubigint numrow; ubigint numread = 0; char* ptr;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "DbsWznm::loadRefsBySQLPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = PQntuples(res);
	if (!append) refs.resize(0);

	refs.reserve(refs.size() + numrow);

	while (numread < numrow) {
		ptr = PQgetvalue(res, numread, 0); refs.push_back(atoll(ptr));
		numread++;
	};

	PQclear(res);

	return(numread);
};
#endif

void DbsWznm::executeQuery(
			const string& sqlstr
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY)
		if (mysql_real_query(dbsMy, sqlstr.c_str(), strlen(sqlstr.c_str()))) {
			string dbms = "DbsWznm::executeQuery() / MySQL / " + string(mysql_error(dbsMy));
			throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
		};
#endif

#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) {
		PGresult* res;

		res = PQexec(dbsPg, sqlstr.c_str());
		if (PQresultStatus(res) != PGRES_COMMAND_OK) {
			string dbms = "DbsWznm::executeQuery() / PgSQL / " + string(PQerrorMessage(dbsPg));
			throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
		};
	};
#endif

};

void DbsWznm::executeQueryDiv(
			const string& sqlstrmy
			, const string& sqlstrpg
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) executeQuery(sqlstrmy);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) executeQuery(sqlstrpg);
#endif
};

void DbsWznm::executeFile(
			const string& fullpath
		) {
	string sqlstr = "";
	char c;
	
	ifstream sqlfile(fullpath.c_str());

	while (sqlfile.get(c)) {
		switch (c) {
			case '\n':
				break;
			case '\t':
				break;
			case ';':
				executeQuery(sqlstr);
				sqlstr = "";
				break;
			default:
				sqlstr = sqlstr + c;
				break;
		};
	};
	sqlfile.close();
};

uint DbsWznm::getIxWSubsetByRefWznmMCall(
			const ubigint ref
		) {
	uint ixWSubset = 0;
	WznmMCall* rec = NULL;

	if (tblwznmmcall->loadRecByRef(ref, &rec)) {
		ixWSubset = getIxWSubsetByWznmMCall(rec);
		delete rec;
	};

	return ixWSubset;
};

uint DbsWznm::getIxWSubsetByWznmMCall(
			WznmMCall* rec
		) {
	uint ixWSubset = 0;
	uint dneIxWSubset = 0;

	vector<bool> args;
	bool a, b;

	if ((dneIxWSubset & TblWznmMCall::VecWSubset::SBSWZNMBMCALLCDC) == 0) {
		a = false; a = (rec->ixVBasetype == VecWznmVMCallBasetype::RECUPD);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMCallBasetype::TBLMOD);
		args.push_back(a);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		if (args.back()) {
			ixWSubset |= TblWznmMCall::VecWSubset::SBSWZNMBMCALLCDC;
		} else {
		};

		dneIxWSubset |= TblWznmMCall::VecWSubset::SBSWZNMBMCALLCDC;
		args.clear();
	};

	return ixWSubset;
};

uint DbsWznm::getIxWSubsetByRefWznmMCapability(
			const ubigint ref
		) {
	uint ixWSubset = 0;
	WznmMCapability* rec = NULL;

	if (tblwznmmcapability->loadRecByRef(ref, &rec)) {
		ixWSubset = getIxWSubsetByWznmMCapability(rec);
		delete rec;
	};

	return ixWSubset;
};

uint DbsWznm::getIxWSubsetByWznmMCapability(
			WznmMCapability* rec
		) {
	uint ixWSubset = 0;
	uint dneIxWSubset = 0;

	vector<bool> args;
	bool a, b;

	if ((dneIxWSubset & TblWznmMCapability::VecWSubset::SBSWZNMBMCAPABILITYCAP) == 0) {
		a = false; a = (rec->tplRefWznmMCapability == 0);
		args.push_back(a);
		a = args.back(); args.pop_back();
		args.push_back(!a);
		if (args.back()) {
			ixWSubset |= TblWznmMCapability::VecWSubset::SBSWZNMBMCAPABILITYCAP;
		} else {
			ixWSubset |= TblWznmMCapability::VecWSubset::SBSWZNMBMCAPABILITYCTP;
		};

		dneIxWSubset |= TblWznmMCapability::VecWSubset::SBSWZNMBMCAPABILITYCAP;
		dneIxWSubset |= TblWznmMCapability::VecWSubset::SBSWZNMBMCAPABILITYCTP;
		args.clear();
	};

	if ((dneIxWSubset & TblWznmMCapability::VecWSubset::SBSWZNMBMCAPABILITYCTP) == 0) {
		a = false; a = (rec->tplRefWznmMCapability == 0);
		args.push_back(a);
		if (args.back()) {
			ixWSubset |= TblWznmMCapability::VecWSubset::SBSWZNMBMCAPABILITYCTP;
		} else {
			ixWSubset |= TblWznmMCapability::VecWSubset::SBSWZNMBMCAPABILITYCAP;
		};

		dneIxWSubset |= TblWznmMCapability::VecWSubset::SBSWZNMBMCAPABILITYCTP;
		dneIxWSubset |= TblWznmMCapability::VecWSubset::SBSWZNMBMCAPABILITYCAP;
		args.clear();
	};

	return ixWSubset;
};

uint DbsWznm::getIxWSubsetByRefWznmMComponent(
			const ubigint ref
		) {
	uint ixWSubset = 0;
	WznmMComponent* rec = NULL;

	if (tblwznmmcomponent->loadRecByRef(ref, &rec)) {
		ixWSubset = getIxWSubsetByWznmMComponent(rec);
		delete rec;
	};

	return ixWSubset;
};

uint DbsWznm::getIxWSubsetByWznmMComponent(
			WznmMComponent* rec
		) {
	uint ixWSubset = 0;
	uint dneIxWSubset = 0;

	vector<bool> args;
	bool a, b;

	if ((dneIxWSubset & TblWznmMComponent::VecWSubset::SBSWZNMBMCOMPONENTCCP) == 0) {
		a = false; a = (rec->ixVBasetype == VecWznmVMComponentBasetype::WEBAPP);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMComponentBasetype::JAPI);
		args.push_back(a);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		a = args.back(); args.pop_back();
		args.push_back(!a);
		if (args.back()) {
			ixWSubset |= TblWznmMComponent::VecWSubset::SBSWZNMBMCOMPONENTCCP;
		} else {
		};

		dneIxWSubset |= TblWznmMComponent::VecWSubset::SBSWZNMBMCOMPONENTCCP;
		args.clear();
	};

	if ((dneIxWSubset & TblWznmMComponent::VecWSubset::SBSWZNMBMCOMPONENTOEN) == 0) {
		a = false; a = (rec->ixVBasetype == VecWznmVMComponentBasetype::OPENG);
		args.push_back(a);
		if (args.back()) {
			ixWSubset |= TblWznmMComponent::VecWSubset::SBSWZNMBMCOMPONENTOEN;
		} else {
		};

		dneIxWSubset |= TblWznmMComponent::VecWSubset::SBSWZNMBMCOMPONENTOEN;
		args.clear();
	};

	return ixWSubset;
};

uint DbsWznm::getIxWSubsetByRefWznmMControl(
			const ubigint ref
		) {
	uint ixWSubset = 0;
	WznmMControl* rec = NULL;

	if (tblwznmmcontrol->loadRecByRef(ref, &rec)) {
		ixWSubset = getIxWSubsetByWznmMControl(rec);
		delete rec;
	};

	return ixWSubset;
};

uint DbsWznm::getIxWSubsetByWznmMControl(
			WznmMControl* rec
		) {
	uint ixWSubset = 0;
	uint dneIxWSubset = 0;

	vector<bool> args;
	bool a, b;

	if ((dneIxWSubset & TblWznmMControl::VecWSubset::SBSWZNMBMCONTROLCAI) == 0) {
		a = false; a = (rec->ixVBasetype == VecWznmVMControlBasetype::BUT);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMControlBasetype::DLD);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMControlBasetype::MIT);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMControlBasetype::ULD);
		args.push_back(a);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		if (args.back()) {
			ixWSubset |= TblWznmMControl::VecWSubset::SBSWZNMBMCONTROLCAI;
			dneIxWSubset |= TblWznmMControl::VecWSubset::SBSWZNMBMCONTROLCFB;
		} else {
		};

		dneIxWSubset |= TblWznmMControl::VecWSubset::SBSWZNMBMCONTROLCAI;
		args.clear();
	};

	if ((dneIxWSubset & TblWznmMControl::VecWSubset::SBSWZNMBMCONTROLCFB) == 0) {
		a = false; a = (rec->ixVBasetype == VecWznmVMControlBasetype::ALR);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMControlBasetype::CSI);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMControlBasetype::DIT);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMControlBasetype::DSE);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMControlBasetype::LST);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMControlBasetype::MCB);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMControlBasetype::RBU);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMControlBasetype::SGE);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMControlBasetype::TOS);
		args.push_back(a);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		if (args.back()) {
			ixWSubset |= TblWznmMControl::VecWSubset::SBSWZNMBMCONTROLCFB;
			dneIxWSubset |= TblWznmMControl::VecWSubset::SBSWZNMBMCONTROLCAI;
		} else {
		};

		dneIxWSubset |= TblWznmMControl::VecWSubset::SBSWZNMBMCONTROLCFB;
		args.clear();
	};

	return ixWSubset;
};

uint DbsWznm::getIxWSubsetByRefWznmMTable(
			const ubigint ref
		) {
	uint ixWSubset = 0;
	WznmMTable* rec = NULL;

	if (tblwznmmtable->loadRecByRef(ref, &rec)) {
		ixWSubset = getIxWSubsetByWznmMTable(rec);
		delete rec;
	};

	return ixWSubset;
};

uint DbsWznm::getIxWSubsetByWznmMTable(
			WznmMTable* rec
		) {
	uint ixWSubset = 0;
	uint dneIxWSubset = 0;

	vector<bool> args;
	bool a, b;

	if ((dneIxWSubset & TblWznmMTable::VecWSubset::SBSWZNMBMTABLEMTB) == 0) {
		a = false; a = (rec->ixVBasetype == VecWznmVMTableBasetype::MAIN);
		args.push_back(a);
		if (args.back()) {
			ixWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLEMTB;
			ixWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLESTT;
			dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLESTT;
			dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLERLT;
			dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLEQTB;
		} else {
		};

		dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLEMTB;
		args.clear();
	};

	if ((dneIxWSubset & TblWznmMTable::VecWSubset::SBSWZNMBMTABLEQTB) == 0) {
		a = false; a = (rec->ixVBasetype == VecWznmVMTableBasetype::QRY);
		args.push_back(a);
		if (args.back()) {
			ixWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLEQTB;
			dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLERLT;
			dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLEMTB;
		} else {
			ixWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLESTT;
		};

		dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLEQTB;
		dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLESTT;
		args.clear();
	};

	if ((dneIxWSubset & TblWznmMTable::VecWSubset::SBSWZNMBMTABLERLT) == 0) {
		a = false; a = (rec->ixVBasetype == VecWznmVMTableBasetype::REL);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMTableBasetype::LIST);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMTableBasetype::OPR);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMTableBasetype::SUB1N);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWznmVMTableBasetype::SUBMN);
		args.push_back(a);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		if (args.back()) {
			ixWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLERLT;
			ixWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLESTT;
			dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLESTT;
			dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLEQTB;
			dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLEMTB;
		} else {
		};

		dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLERLT;
		args.clear();
	};

	if ((dneIxWSubset & TblWznmMTable::VecWSubset::SBSWZNMBMTABLESTT) == 0) {
		a = false; a = (rec->ixVBasetype == VecWznmVMTableBasetype::QRY);
		args.push_back(a);
		a = args.back(); args.pop_back();
		args.push_back(!a);
		if (args.back()) {
			ixWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLESTT;
		} else {
			dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLERLT;
			ixWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLEQTB;
			dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLEMTB;
		};

		dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLESTT;
		dneIxWSubset |= TblWznmMTable::VecWSubset::SBSWZNMBMTABLEQTB;
		args.clear();
	};

	return ixWSubset;
};

uint DbsWznm::getIxWSubsetByRefWznmMTablecol(
			const ubigint ref
		) {
	uint ixWSubset = 0;
	WznmMTablecol* rec = NULL;

	if (tblwznmmtablecol->loadRecByRef(ref, &rec)) {
		ixWSubset = getIxWSubsetByWznmMTablecol(rec);
		delete rec;
	};

	return ixWSubset;
};

uint DbsWznm::getIxWSubsetByWznmMTablecol(
			WznmMTablecol* rec
		) {
	uint ixWSubset = 0;
	uint dneIxWSubset = 0;

	vector<bool> args;
	bool a, b;

	if ((dneIxWSubset & TblWznmMTablecol::VecWSubset::SBSWZNMBMTABLECOLSTC) == 0) {
		a = false; a = ((getIxWSubsetByRefWznmMTable(rec->tblRefWznmMTable) & TblWznmMTable::VecWSubset::SBSWZNMBMTABLESTT) != 0);
		args.push_back(a);
		if (args.back()) {
			ixWSubset |= TblWznmMTablecol::VecWSubset::SBSWZNMBMTABLECOLSTC;
		} else {
		};

		dneIxWSubset |= TblWznmMTablecol::VecWSubset::SBSWZNMBMTABLECOLSTC;
		args.clear();
	};

	return ixWSubset;
};

uint DbsWznm::getIxWSubsetByRefWznmMVector(
			const ubigint ref
		) {
	uint ixWSubset = 0;
	WznmMVector* rec = NULL;

	if (tblwznmmvector->loadRecByRef(ref, &rec)) {
		ixWSubset = getIxWSubsetByWznmMVector(rec);
		delete rec;
	};

	return ixWSubset;
};

uint DbsWznm::getIxWSubsetByWznmMVector(
			WznmMVector* rec
		) {
	uint ixWSubset = 0;
	uint dneIxWSubset = 0;

	vector<bool> args;
	bool a, b;

	if ((dneIxWSubset & TblWznmMVector::VecWSubset::SBSWZNMBMVECTORKLS) == 0) {
		a = false; a = (rec->ixVBasetype == VecWznmVMVectorBasetype::KLST);
		args.push_back(a);
		if (args.back()) {
			ixWSubset |= TblWznmMVector::VecWSubset::SBSWZNMBMVECTORKLS;
		} else {
		};

		dneIxWSubset |= TblWznmMVector::VecWSubset::SBSWZNMBMVECTORKLS;
		args.clear();
	};

	return ixWSubset;
};

void DbsWznm::fillFeedFromKlst(
			const uint klsIxWznmVKeylist
			, const uint ixWznmVLocale
			, Feed& feed
		) {
	ListWznmAVKeylistKey klsAkeys;
	WznmAVKeylistKey* klsAkey = NULL;

	tblwznmavkeylistkey->loadRstByKls(klsIxWznmVKeylist, false, klsAkeys);

	feed.clear();
	for (unsigned int i = 0; i < klsAkeys.nodes.size(); i++) {
		klsAkey = klsAkeys.nodes[i];

		tblwznmjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixWznmVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

void DbsWznm::fillFeedFromKlstByMtbUref(
			const uint klsIxWznmVKeylist
			, const uint x1IxWznmVMaintable
			, const ubigint x1Uref
			, const uint ixWznmVLocale
			, Feed& feed
		) {
	ListWznmAVKeylistKey klsAkeys;
	WznmAVKeylistKey* klsAkey = NULL;

	tblwznmavkeylistkey->loadRstByKlsMtbUrf(klsIxWznmVKeylist, x1IxWznmVMaintable, x1Uref, false, klsAkeys);

	feed.clear();
	for (unsigned int i = 0; i < klsAkeys.nodes.size(); i++) {
		klsAkey = klsAkeys.nodes[i];

		tblwznmjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixWznmVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

string DbsWznm::getKlstTitleBySref(
			const uint klsIxWznmVKeylist
			, const string& sref
			, const uint ixWznmVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblwznmavkeylistkey->loadRefByKlsSrf(klsIxWznmVKeylist, sref, refKlk))
		if (!tblwznmjavkeylistkey->loadTitByKlkLcl(refKlk, ixWznmVLocale, retval))
			tblwznmavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

string DbsWznm::getKlstTitleByMtbUrefSref(
			const uint klsIxWznmVKeylist
			, const uint x1IxWznmVMaintable
			, const ubigint x1Uref
			, const string& sref
			, const uint ixWznmVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblwznmavkeylistkey->loadRefByKlsMtbUrfSrf(klsIxWznmVKeylist, x1IxWznmVMaintable, x1Uref, sref, refKlk))
		if (!tblwznmjavkeylistkey->loadTitByKlkLcl(refKlk, ixWznmVLocale, retval))
			tblwznmavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

void DbsWznm::fillFeedFromVlst(
			const uint vlsIxWznmVValuelist
			, const uint x1IxWznmVLocale
			, Feed& feed
		) {
	ListWznmAVValuelistVal vlsAvals;
	WznmAVValuelistVal* vlsAval = NULL;

	tblwznmavvaluelistval->loadRstByVlsLcl(vlsIxWznmVValuelist, x1IxWznmVLocale, false, vlsAvals);

	feed.clear();
	for (unsigned int i = 0; i < vlsAvals.nodes.size(); i++) {
		vlsAval = vlsAvals.nodes[i];

		feed.appendTitles(vlsAval->Val);
	};
};

