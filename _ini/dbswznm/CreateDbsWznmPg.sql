-- CREATE ROLE mpsitech LOGIN
-- 	UNENCRYPTED PASSWORD 'asdf1234'
-- 	NOSUPERUSER INHERIT NOCREATEDB NOCREATEROLE;
-- COMMENT ON ROLE mpsitech IS 'MPSI Technologies GmbH';

CREATE DATABASE "DbsWznm"
	WITH ENCODING='UTF8'
	OWNER = mpsitech
	CONNECTION LIMIT = -1;

DROP TABLE IF EXISTS TblWznmAccRMUserUniversal;
DROP TABLE IF EXISTS TblWznmAMBlockItem;
DROP TABLE IF EXISTS TblWznmAMCapabilityPar;
DROP TABLE IF EXISTS TblWznmAMControlPar;
DROP TABLE IF EXISTS TblWznmAMJobCmd;
DROP TABLE IF EXISTS TblWznmAMJobVar;
DROP TABLE IF EXISTS TblWznmAMLibraryMakefile;
DROP TABLE IF EXISTS TblWznmAMLibraryPkglist;
DROP TABLE IF EXISTS TblWznmAMMachinePar;
DROP TABLE IF EXISTS TblWznmAMMachtypeMakefile;
DROP TABLE IF EXISTS TblWznmAMMethodInvpar;
DROP TABLE IF EXISTS TblWznmAMMethodRetpar;
DROP TABLE IF EXISTS TblWznmAMOpInvarg;
DROP TABLE IF EXISTS TblWznmAMOppackInvarg;
DROP TABLE IF EXISTS TblWznmAMOppackRetval;
DROP TABLE IF EXISTS TblWznmAMOpRetval;
DROP TABLE IF EXISTS TblWznmAMPersonDetail;
DROP TABLE IF EXISTS TblWznmAMQueryClause;
DROP TABLE IF EXISTS TblWznmAMQueryOrder;
DROP TABLE IF EXISTS TblWznmAMRelationTitle;
DROP TABLE IF EXISTS TblWznmAMStateStep;
DROP TABLE IF EXISTS TblWznmAMSubsetTitle;
DROP TABLE IF EXISTS TblWznmAMTablecolTitle;
DROP TABLE IF EXISTS TblWznmAMTableLoadfct;
DROP TABLE IF EXISTS TblWznmAMTableTitle;
DROP TABLE IF EXISTS TblWznmAMUserAccess;
DROP TABLE IF EXISTS TblWznmAMUsergroupAccess;
DROP TABLE IF EXISTS TblWznmAMVectorTitle;
DROP TABLE IF EXISTS TblWznmAVControlPar;
DROP TABLE IF EXISTS TblWznmAVKeylistKey;
DROP TABLE IF EXISTS TblWznmAVValuelistVal;
DROP SEQUENCE IF EXISTS TblWznmCAMBlockItem;
DROP SEQUENCE IF EXISTS TblWznmCAMJobVar;
DROP SEQUENCE IF EXISTS TblWznmCAMOpInvarg;
DROP SEQUENCE IF EXISTS TblWznmCAMOppackInvarg;
DROP SEQUENCE IF EXISTS TblWznmCAMOppackRetval;
DROP SEQUENCE IF EXISTS TblWznmCAMOpRetval;
DROP SEQUENCE IF EXISTS TblWznmCControl;
DROP SEQUENCE IF EXISTS TblWznmCFile;
DROP SEQUENCE IF EXISTS TblWznmCRelation;
DROP TABLE IF EXISTS TblWznmHistRMUserUniversal;
DROP TABLE IF EXISTS TblWznmJAMBlockItem;
DROP TABLE IF EXISTS TblWznmJAVKeylistKey;
DROP TABLE IF EXISTS TblWznmJMCardTitle;
DROP TABLE IF EXISTS TblWznmJMControl;
DROP TABLE IF EXISTS TblWznmJMControlTitle;
DROP TABLE IF EXISTS TblWznmJMErrorTitle;
DROP TABLE IF EXISTS TblWznmJMImpexpcolStub;
DROP TABLE IF EXISTS TblWznmJMImpexpcplxTitle;
DROP TABLE IF EXISTS TblWznmJMLocaleTitle;
DROP TABLE IF EXISTS TblWznmJMModule;
DROP TABLE IF EXISTS TblWznmJMPersonLastname;
DROP TABLE IF EXISTS TblWznmJMPresetTitle;
DROP TABLE IF EXISTS TblWznmJMQuerycolStub;
DROP TABLE IF EXISTS TblWznmJMSquawkTitle;
DROP TABLE IF EXISTS TblWznmJMTagTitle;
DROP TABLE IF EXISTS TblWznmJMUserState;
DROP TABLE IF EXISTS TblWznmJMVectoritem;
DROP TABLE IF EXISTS TblWznmJMVersion;
DROP TABLE IF EXISTS TblWznmJMVersionState;
DROP TABLE IF EXISTS TblWznmMApp;
DROP TABLE IF EXISTS TblWznmMBlock;
DROP TABLE IF EXISTS TblWznmMCall;
DROP TABLE IF EXISTS TblWznmMCapability;
DROP TABLE IF EXISTS TblWznmMCard;
DROP TABLE IF EXISTS TblWznmMCheck;
DROP TABLE IF EXISTS TblWznmMComponent;
DROP TABLE IF EXISTS TblWznmMControl;
DROP TABLE IF EXISTS TblWznmMDialog;
DROP TABLE IF EXISTS TblWznmMError;
DROP TABLE IF EXISTS TblWznmMFeed;
DROP TABLE IF EXISTS TblWznmMFile;
DROP TABLE IF EXISTS TblWznmMImpexp;
DROP TABLE IF EXISTS TblWznmMImpexpcol;
DROP TABLE IF EXISTS TblWznmMImpexpcplx;
DROP TABLE IF EXISTS TblWznmMJob;
DROP TABLE IF EXISTS TblWznmMLibrary;
DROP TABLE IF EXISTS TblWznmMLocale;
DROP TABLE IF EXISTS TblWznmMMachine;
DROP TABLE IF EXISTS TblWznmMMachtype;
DROP TABLE IF EXISTS TblWznmMMethod;
DROP TABLE IF EXISTS TblWznmMModule;
DROP TABLE IF EXISTS TblWznmMOp;
DROP TABLE IF EXISTS TblWznmMOppack;
DROP TABLE IF EXISTS TblWznmMPanel;
DROP TABLE IF EXISTS TblWznmMPerson;
DROP TABLE IF EXISTS TblWznmMPreset;
DROP TABLE IF EXISTS TblWznmMProject;
DROP TABLE IF EXISTS TblWznmMQuery;
DROP TABLE IF EXISTS TblWznmMQuerycol;
DROP TABLE IF EXISTS TblWznmMQuerymod;
DROP TABLE IF EXISTS TblWznmMRelation;
DROP TABLE IF EXISTS TblWznmMRelease;
DROP TABLE IF EXISTS TblWznmMRtblock;
DROP TABLE IF EXISTS TblWznmMRtdpch;
DROP TABLE IF EXISTS TblWznmMRtjob;
DROP TABLE IF EXISTS TblWznmMSensitivity;
DROP TABLE IF EXISTS TblWznmMSequence;
DROP TABLE IF EXISTS TblWznmMSession;
DROP TABLE IF EXISTS TblWznmMSquawk;
DROP TABLE IF EXISTS TblWznmMStage;
DROP TABLE IF EXISTS TblWznmMState;
DROP TABLE IF EXISTS TblWznmMStub;
DROP TABLE IF EXISTS TblWznmMSubset;
DROP TABLE IF EXISTS TblWznmMTable;
DROP TABLE IF EXISTS TblWznmMTablecol;
DROP TABLE IF EXISTS TblWznmMTag;
DROP TABLE IF EXISTS TblWznmMUser;
DROP TABLE IF EXISTS TblWznmMUsergroup;
DROP TABLE IF EXISTS TblWznmMVector;
DROP TABLE IF EXISTS TblWznmMVectoritem;
DROP TABLE IF EXISTS TblWznmMVersion;
DROP TABLE IF EXISTS TblWznmRMCallMStub;
DROP TABLE IF EXISTS TblWznmRMCapabilityUniversal;
DROP TABLE IF EXISTS TblWznmRMComponentMLibrary;
DROP TABLE IF EXISTS TblWznmRMComponentMOppack;
DROP TABLE IF EXISTS TblWznmRMDialogMQuery;
DROP TABLE IF EXISTS TblWznmRMJobMJob;
DROP TABLE IF EXISTS TblWznmRMJobMOp;
DROP TABLE IF EXISTS TblWznmRMJobMOppack;
DROP TABLE IF EXISTS TblWznmRMLibraryMOppack;
DROP TABLE IF EXISTS TblWznmRMLocaleMVersion;
DROP TABLE IF EXISTS TblWznmRMPanelMQuery;
DROP TABLE IF EXISTS TblWznmRMPersonMProject;
DROP TABLE IF EXISTS TblWznmRMQueryMTable;
DROP TABLE IF EXISTS TblWznmRMSquawkMStub;
DROP TABLE IF EXISTS TblWznmRMStubMStub;
DROP TABLE IF EXISTS TblWznmRMSubsetMSubset;
DROP TABLE IF EXISTS TblWznmRMTableMVector;
DROP TABLE IF EXISTS TblWznmRMUsergroupUniversal;
DROP TABLE IF EXISTS TblWznmRMUserMUsergroup;
DROP TABLE IF EXISTS TblWznmTMQuerymodMQuery;

DROP TABLE IF EXISTS TblWznmQApp1NRtjob;
DROP TABLE IF EXISTS TblWznmQAppApp1NSequence;
DROP TABLE IF EXISTS TblWznmQAppList;
DROP TABLE IF EXISTS TblWznmQAppRef1NFile;
DROP TABLE IF EXISTS TblWznmQBlk1NRtdpch;
DROP TABLE IF EXISTS TblWznmQBlkAItem;
DROP TABLE IF EXISTS TblWznmQBlkList;
DROP TABLE IF EXISTS TblWznmQBlkRef1NRtblock;
DROP TABLE IF EXISTS TblWznmQCal1NSensitivity;
DROP TABLE IF EXISTS TblWznmQCalList;
DROP TABLE IF EXISTS TblWznmQCalMNStub;
DROP TABLE IF EXISTS TblWznmQCapAPar;
DROP TABLE IF EXISTS TblWznmQCapList;
DROP TABLE IF EXISTS TblWznmQCar1NDialog;
DROP TABLE IF EXISTS TblWznmQCarCar1NPanel;
DROP TABLE IF EXISTS TblWznmQCarHk1NControl;
DROP TABLE IF EXISTS TblWznmQCarList;
DROP TABLE IF EXISTS TblWznmQChkList;
DROP TABLE IF EXISTS TblWznmQChkRef1NCall;
DROP TABLE IF EXISTS TblWznmQCmp1NRelease;
DROP TABLE IF EXISTS TblWznmQCmpList;
DROP TABLE IF EXISTS TblWznmQCmpMNLibrary;
DROP TABLE IF EXISTS TblWznmQCmpMNOppack;
DROP TABLE IF EXISTS TblWznmQConAPar;
DROP TABLE IF EXISTS TblWznmQConFedRef1NRtblock;
DROP TABLE IF EXISTS TblWznmQConList;
DROP TABLE IF EXISTS TblWznmQConSup1NControl;
DROP TABLE IF EXISTS TblWznmQCtp1NTag;
DROP TABLE IF EXISTS TblWznmQCtpAPar;
DROP TABLE IF EXISTS TblWznmQCtpKKey;
DROP TABLE IF EXISTS TblWznmQCtpKParKey;
DROP TABLE IF EXISTS TblWznmQCtpList;
DROP TABLE IF EXISTS TblWznmQCtpTpl1NCapability;
DROP TABLE IF EXISTS TblWznmQDlgHk1NControl;
DROP TABLE IF EXISTS TblWznmQDlgList;
DROP TABLE IF EXISTS TblWznmQDlgMNQuery;
DROP TABLE IF EXISTS TblWznmQDlgRef1NControl;
DROP TABLE IF EXISTS TblWznmQErrList;
DROP TABLE IF EXISTS TblWznmQFilList;
DROP TABLE IF EXISTS TblWznmQIelList;
DROP TABLE IF EXISTS TblWznmQIex1NImpexp;
DROP TABLE IF EXISTS TblWznmQIexHk1NVector;
DROP TABLE IF EXISTS TblWznmQIexList;
DROP TABLE IF EXISTS TblWznmQIexRef1NDialog;
DROP TABLE IF EXISTS TblWznmQImeHk1NVector;
DROP TABLE IF EXISTS TblWznmQImeIme1NImpexpcol;
DROP TABLE IF EXISTS TblWznmQImeList;
DROP TABLE IF EXISTS TblWznmQImeSup1NImpexp;
DROP TABLE IF EXISTS TblWznmQJob1NMethod;
DROP TABLE IF EXISTS TblWznmQJob1NRtjob;
DROP TABLE IF EXISTS TblWznmQJob1NSensitivity;
DROP TABLE IF EXISTS TblWznmQJobACmd;
DROP TABLE IF EXISTS TblWznmQJobAVar;
DROP TABLE IF EXISTS TblWznmQJobHk1NVector;
DROP TABLE IF EXISTS TblWznmQJobJob1NStage;
DROP TABLE IF EXISTS TblWznmQJobList;
DROP TABLE IF EXISTS TblWznmQJobMNOp;
DROP TABLE IF EXISTS TblWznmQJobMNOppack;
DROP TABLE IF EXISTS TblWznmQJobRef1NBlock;
DROP TABLE IF EXISTS TblWznmQJobSubMNJob;
DROP TABLE IF EXISTS TblWznmQJobSupMNJob;
DROP TABLE IF EXISTS TblWznmQLibAMakefile;
DROP TABLE IF EXISTS TblWznmQLibAPkglist;
DROP TABLE IF EXISTS TblWznmQLibList;
DROP TABLE IF EXISTS TblWznmQLibMNComponent;
DROP TABLE IF EXISTS TblWznmQLibMNOppack;
DROP TABLE IF EXISTS TblWznmQLibRef1NFile;
DROP TABLE IF EXISTS TblWznmQLocList;
DROP TABLE IF EXISTS TblWznmQLocMNVersion;
DROP TABLE IF EXISTS TblWznmQMch1NRelease;
DROP TABLE IF EXISTS TblWznmQMchAPar;
DROP TABLE IF EXISTS TblWznmQMchList;
DROP TABLE IF EXISTS TblWznmQMdlList;
DROP TABLE IF EXISTS TblWznmQMdlMdl1NCard;
DROP TABLE IF EXISTS TblWznmQMdlRef1NPanel;
DROP TABLE IF EXISTS TblWznmQMtdAInvpar;
DROP TABLE IF EXISTS TblWznmQMtdARetpar;
DROP TABLE IF EXISTS TblWznmQMtdList;
DROP TABLE IF EXISTS TblWznmQMty1NMachine;
DROP TABLE IF EXISTS TblWznmQMtyAMakefile;
DROP TABLE IF EXISTS TblWznmQMtyList;
DROP TABLE IF EXISTS TblWznmQOpk1NOp;
DROP TABLE IF EXISTS TblWznmQOpkAInvarg;
DROP TABLE IF EXISTS TblWznmQOpkARetval;
DROP TABLE IF EXISTS TblWznmQOpkList;
DROP TABLE IF EXISTS TblWznmQOpkMNComponent;
DROP TABLE IF EXISTS TblWznmQOpkMNJob;
DROP TABLE IF EXISTS TblWznmQOpkMNLibrary;
DROP TABLE IF EXISTS TblWznmQOpkRef1NBlock;
DROP TABLE IF EXISTS TblWznmQOpkSqkMNStub;
DROP TABLE IF EXISTS TblWznmQOpxAInvarg;
DROP TABLE IF EXISTS TblWznmQOpxARetval;
DROP TABLE IF EXISTS TblWznmQOpxList;
DROP TABLE IF EXISTS TblWznmQOpxMNJob;
DROP TABLE IF EXISTS TblWznmQOpxRef1NBlock;
DROP TABLE IF EXISTS TblWznmQOpxSqkMNStub;
DROP TABLE IF EXISTS TblWznmQPnlHk1NControl;
DROP TABLE IF EXISTS TblWznmQPnlList;
DROP TABLE IF EXISTS TblWznmQPnlMNQuery;
DROP TABLE IF EXISTS TblWznmQPreselect;
DROP TABLE IF EXISTS TblWznmQPrj1NVersion;
DROP TABLE IF EXISTS TblWznmQPrjList;
DROP TABLE IF EXISTS TblWznmQPrjMNPerson;
DROP TABLE IF EXISTS TblWznmQPrsADetail;
DROP TABLE IF EXISTS TblWznmQPrsList;
DROP TABLE IF EXISTS TblWznmQPrsMNProject;
DROP TABLE IF EXISTS TblWznmQPst1NQuerymod;
DROP TABLE IF EXISTS TblWznmQPstList;
DROP TABLE IF EXISTS TblWznmQQcoList;
DROP TABLE IF EXISTS TblWznmQQcoRef1NControl;
DROP TABLE IF EXISTS TblWznmQQmdList;
DROP TABLE IF EXISTS TblWznmQQry1NQuerymod;
DROP TABLE IF EXISTS TblWznmQQryAClause;
DROP TABLE IF EXISTS TblWznmQQryAOrder;
DROP TABLE IF EXISTS TblWznmQQryList;
DROP TABLE IF EXISTS TblWznmQQryMNDialog;
DROP TABLE IF EXISTS TblWznmQQryMNPanel;
DROP TABLE IF EXISTS TblWznmQQryMNTable;
DROP TABLE IF EXISTS TblWznmQQryQry1NQuerycol;
DROP TABLE IF EXISTS TblWznmQQrySup1NQuery;
DROP TABLE IF EXISTS TblWznmQRel1NTablecol;
DROP TABLE IF EXISTS TblWznmQRelATitle;
DROP TABLE IF EXISTS TblWznmQRelList;
DROP TABLE IF EXISTS TblWznmQRelRef1NControl;
DROP TABLE IF EXISTS TblWznmQRelRef1NDialog;
DROP TABLE IF EXISTS TblWznmQRelRef1NPanel;
DROP TABLE IF EXISTS TblWznmQRelSup1NRelation;
DROP TABLE IF EXISTS TblWznmQRlsList;
DROP TABLE IF EXISTS TblWznmQRtj1NRtblock;
DROP TABLE IF EXISTS TblWznmQRtj1NRtdpch;
DROP TABLE IF EXISTS TblWznmQRtjList;
DROP TABLE IF EXISTS TblWznmQRtjSup1NRtjob;
DROP TABLE IF EXISTS TblWznmQSbs1NStub;
DROP TABLE IF EXISTS TblWznmQSbs1NTablecol;
DROP TABLE IF EXISTS TblWznmQSbsAsbMNSubset;
DROP TABLE IF EXISTS TblWznmQSbsATitle;
DROP TABLE IF EXISTS TblWznmQSbsBsbMNSubset;
DROP TABLE IF EXISTS TblWznmQSbsFrs1NRelation;
DROP TABLE IF EXISTS TblWznmQSbsList;
DROP TABLE IF EXISTS TblWznmQSbsPst1NQuerymod;
DROP TABLE IF EXISTS TblWznmQSbsTos1NRelation;
DROP TABLE IF EXISTS TblWznmQSelect;
DROP TABLE IF EXISTS TblWznmQSeqList;
DROP TABLE IF EXISTS TblWznmQSeqSeq1NState;
DROP TABLE IF EXISTS TblWznmQSge1NSensitivity;
DROP TABLE IF EXISTS TblWznmQSgeList;
DROP TABLE IF EXISTS TblWznmQSgeSqkMNStub;
DROP TABLE IF EXISTS TblWznmQStbList;
DROP TABLE IF EXISTS TblWznmQStbMNCall;
DROP TABLE IF EXISTS TblWznmQStbMNSquawk;
DROP TABLE IF EXISTS TblWznmQStbSubMNStub;
DROP TABLE IF EXISTS TblWznmQStbSupMNStub;
DROP TABLE IF EXISTS TblWznmQSteAStep;
DROP TABLE IF EXISTS TblWznmQSteList;
DROP TABLE IF EXISTS TblWznmQTagList;
DROP TABLE IF EXISTS TblWznmQTbl1NCheck;
DROP TABLE IF EXISTS TblWznmQTbl1NImpexp;
DROP TABLE IF EXISTS TblWznmQTbl1NStub;
DROP TABLE IF EXISTS TblWznmQTbl1NSubset;
DROP TABLE IF EXISTS TblWznmQTblALoadfct;
DROP TABLE IF EXISTS TblWznmQTblATitle;
DROP TABLE IF EXISTS TblWznmQTblFct1NTablecol;
DROP TABLE IF EXISTS TblWznmQTblFr1NRelation;
DROP TABLE IF EXISTS TblWznmQTblHk1NVector;
DROP TABLE IF EXISTS TblWznmQTblList;
DROP TABLE IF EXISTS TblWznmQTblMNQuery;
DROP TABLE IF EXISTS TblWznmQTblMNVector;
DROP TABLE IF EXISTS TblWznmQTblPst1NQuerymod;
DROP TABLE IF EXISTS TblWznmQTblRef1NCall;
DROP TABLE IF EXISTS TblWznmQTblRef1NDialog;
DROP TABLE IF EXISTS TblWznmQTblRef1NPanel;
DROP TABLE IF EXISTS TblWznmQTblRef1NQuerymod;
DROP TABLE IF EXISTS TblWznmQTblRef1NRtblock;
DROP TABLE IF EXISTS TblWznmQTblSrc1NFeed;
DROP TABLE IF EXISTS TblWznmQTblTbl1NTablecol;
DROP TABLE IF EXISTS TblWznmQTblTo1NRelation;
DROP TABLE IF EXISTS TblWznmQTco1NCheck;
DROP TABLE IF EXISTS TblWznmQTco1NImpexpcol;
DROP TABLE IF EXISTS TblWznmQTco1NQuerycol;
DROP TABLE IF EXISTS TblWznmQTcoATitle;
DROP TABLE IF EXISTS TblWznmQTcoList;
DROP TABLE IF EXISTS TblWznmQTcoRef1NControl;
DROP TABLE IF EXISTS TblWznmQTcoRef1NQuerymod;
DROP TABLE IF EXISTS TblWznmQUsgAAccess;
DROP TABLE IF EXISTS TblWznmQUsgList;
DROP TABLE IF EXISTS TblWznmQUsgMNUser;
DROP TABLE IF EXISTS TblWznmQUsr1NSession;
DROP TABLE IF EXISTS TblWznmQUsrAAccess;
DROP TABLE IF EXISTS TblWznmQUsrList;
DROP TABLE IF EXISTS TblWznmQUsrMNUsergroup;
DROP TABLE IF EXISTS TblWznmQVecATitle;
DROP TABLE IF EXISTS TblWznmQVecFct1NTablecol;
DROP TABLE IF EXISTS TblWznmQVecList;
DROP TABLE IF EXISTS TblWznmQVecMNTable;
DROP TABLE IF EXISTS TblWznmQVecPst1NQuerymod;
DROP TABLE IF EXISTS TblWznmQVecRef1NPanel;
DROP TABLE IF EXISTS TblWznmQVecSrc1NFeed;
DROP TABLE IF EXISTS TblWznmQVecVec1NVectoritem;
DROP TABLE IF EXISTS TblWznmQVer1NBlock;
DROP TABLE IF EXISTS TblWznmQVer1NCall;
DROP TABLE IF EXISTS TblWznmQVer1NCapability;
DROP TABLE IF EXISTS TblWznmQVer1NComponent;
DROP TABLE IF EXISTS TblWznmQVer1NImpexpcplx;
DROP TABLE IF EXISTS TblWznmQVer1NJob;
DROP TABLE IF EXISTS TblWznmQVer1NOppack;
DROP TABLE IF EXISTS TblWznmQVer1NPreset;
DROP TABLE IF EXISTS TblWznmQVer1NQuery;
DROP TABLE IF EXISTS TblWznmQVer1NRelation;
DROP TABLE IF EXISTS TblWznmQVer1NTable;
DROP TABLE IF EXISTS TblWznmQVer1NVector;
DROP TABLE IF EXISTS TblWznmQVerBvr1NVersion;
DROP TABLE IF EXISTS TblWznmQVerList;
DROP TABLE IF EXISTS TblWznmQVerMNLocale;
DROP TABLE IF EXISTS TblWznmQVerRef1NFile;
DROP TABLE IF EXISTS TblWznmQVerVer1NApp;
DROP TABLE IF EXISTS TblWznmQVerVer1NError;
DROP TABLE IF EXISTS TblWznmQVerVer1NModule;
DROP TABLE IF EXISTS TblWznmQVitList;

CREATE TABLE TblWznmAccRMUserUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMUser BIGINT,
	unvIxWznmVMaintable INT,
	unvUref BIGINT,
	ixWznmVRecaccess INT
);
ALTER TABLE TblWznmAccRMUserUniversal OWNER TO epsi;
CREATE INDEX TblWznmAccRMUserUniversal_refWznmMUser ON TblWznmAccRMUserUniversal (refWznmMUser);
CREATE INDEX TblWznmAccRMUserUniversal_unvIxWznmVMaintable ON TblWznmAccRMUserUniversal (unvIxWznmVMaintable);
CREATE INDEX TblWznmAccRMUserUniversal_unvUref ON TblWznmAccRMUserUniversal (unvUref);

CREATE TABLE TblWznmAMBlockItem(
	ref BIGSERIAL PRIMARY KEY,
	refWznmCAMBlockItem BIGINT,
	blkRefWznmMBlock BIGINT,
	blkNum INT,
	ixVBasetype INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMControl BIGINT,
	refWznmMVector BIGINT,
	refWznmMFeed BIGINT,
	refWznmMTable BIGINT,
	refWznmMBlock BIGINT,
	refJ BIGINT,
	Defval VARCHAR(192),
	refWznmMVectoritem BIGINT,
	Comment TEXT
);
ALTER TABLE TblWznmAMBlockItem OWNER TO epsi;
CREATE INDEX TblWznmAMBlockItem_refWznmCAMBlockItem ON TblWznmAMBlockItem (refWznmCAMBlockItem);
CREATE INDEX TblWznmAMBlockItem_blkRefWznmMBlock ON TblWznmAMBlockItem (blkRefWznmMBlock);
CREATE INDEX TblWznmAMBlockItem_blkNum ON TblWznmAMBlockItem (blkNum);
CREATE INDEX TblWznmAMBlockItem_sref ON TblWznmAMBlockItem (sref);

CREATE TABLE TblWznmAMCapabilityPar(
	ref BIGSERIAL PRIMARY KEY,
	cpbRefWznmMCapability BIGINT,
	cpbNum INT,
	x1SrefKKey VARCHAR(50),
	Val TEXT
);
ALTER TABLE TblWznmAMCapabilityPar OWNER TO epsi;
CREATE INDEX TblWznmAMCapabilityPar_cpbRefWznmMCapability ON TblWznmAMCapabilityPar (cpbRefWznmMCapability);
CREATE INDEX TblWznmAMCapabilityPar_cpbNum ON TblWznmAMCapabilityPar (cpbNum);
CREATE INDEX TblWznmAMCapabilityPar_x1SrefKKey ON TblWznmAMCapabilityPar (x1SrefKKey);

CREATE TABLE TblWznmAMControlPar(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMControl BIGINT,
	x1SrefKKey VARCHAR(50),
	x2RefWznmMLocale BIGINT,
	osrefKVal VARCHAR(50)
);
ALTER TABLE TblWznmAMControlPar OWNER TO epsi;
CREATE INDEX TblWznmAMControlPar_refWznmMControl ON TblWznmAMControlPar (refWznmMControl);
CREATE INDEX TblWznmAMControlPar_x1SrefKKey ON TblWznmAMControlPar (x1SrefKKey);
CREATE INDEX TblWznmAMControlPar_x2RefWznmMLocale ON TblWznmAMControlPar (x2RefWznmMLocale);

CREATE TABLE TblWznmAMJobCmd(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMJob BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWznmAMJobCmd OWNER TO epsi;
CREATE INDEX TblWznmAMJobCmd_refWznmMJob ON TblWznmAMJobCmd (refWznmMJob);
CREATE INDEX TblWznmAMJobCmd_sref ON TblWznmAMJobCmd (sref);

CREATE TABLE TblWznmAMJobVar(
	ref BIGSERIAL PRIMARY KEY,
	refWznmCAMJobVar BIGINT,
	jobRefWznmMJob BIGINT,
	jobNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Length INT,
	Shr SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWznmAMJobVar OWNER TO epsi;
CREATE INDEX TblWznmAMJobVar_refWznmCAMJobVar ON TblWznmAMJobVar (refWznmCAMJobVar);
CREATE INDEX TblWznmAMJobVar_jobRefWznmMJob ON TblWznmAMJobVar (jobRefWznmMJob);
CREATE INDEX TblWznmAMJobVar_jobNum ON TblWznmAMJobVar (jobNum);
CREATE INDEX TblWznmAMJobVar_sref ON TblWznmAMJobVar (sref);

CREATE TABLE TblWznmAMLibraryMakefile(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMLibrary BIGINT,
	x1RefIxVTbl INT,
	x1RefUref BIGINT,
	x2SrefKTag VARCHAR(50),
	Val TEXT
);
ALTER TABLE TblWznmAMLibraryMakefile OWNER TO epsi;
CREATE INDEX TblWznmAMLibraryMakefile_refWznmMLibrary ON TblWznmAMLibraryMakefile (refWznmMLibrary);
CREATE INDEX TblWznmAMLibraryMakefile_x1RefIxVTbl ON TblWznmAMLibraryMakefile (x1RefIxVTbl);
CREATE INDEX TblWznmAMLibraryMakefile_x1RefUref ON TblWznmAMLibraryMakefile (x1RefUref);
CREATE INDEX TblWznmAMLibraryMakefile_x2SrefKTag ON TblWznmAMLibraryMakefile (x2SrefKTag);

CREATE TABLE TblWznmAMLibraryPkglist(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMLibrary BIGINT,
	x1RefIxVTbl INT,
	x1RefUref BIGINT,
	Pkglist TEXT
);
ALTER TABLE TblWznmAMLibraryPkglist OWNER TO epsi;
CREATE INDEX TblWznmAMLibraryPkglist_refWznmMLibrary ON TblWznmAMLibraryPkglist (refWznmMLibrary);
CREATE INDEX TblWznmAMLibraryPkglist_x1RefIxVTbl ON TblWznmAMLibraryPkglist (x1RefIxVTbl);
CREATE INDEX TblWznmAMLibraryPkglist_x1RefUref ON TblWznmAMLibraryPkglist (x1RefUref);

CREATE TABLE TblWznmAMMachinePar(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMMachine BIGINT,
	x1SrefKKey VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWznmAMMachinePar OWNER TO epsi;
CREATE INDEX TblWznmAMMachinePar_refWznmMMachine ON TblWznmAMMachinePar (refWznmMMachine);
CREATE INDEX TblWznmAMMachinePar_x1SrefKKey ON TblWznmAMMachinePar (x1SrefKKey);

CREATE TABLE TblWznmAMMachtypeMakefile(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMMachtype BIGINT,
	x1SrefKTag VARCHAR(50),
	Val TEXT
);
ALTER TABLE TblWznmAMMachtypeMakefile OWNER TO epsi;
CREATE INDEX TblWznmAMMachtypeMakefile_refWznmMMachtype ON TblWznmAMMachtypeMakefile (refWznmMMachtype);
CREATE INDEX TblWznmAMMachtypeMakefile_x1SrefKTag ON TblWznmAMMachtypeMakefile (x1SrefKTag);

CREATE TABLE TblWznmAMMethodInvpar(
	ref BIGSERIAL PRIMARY KEY,
	mtdRefWznmMMethod BIGINT,
	mtdNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Length INT,
	Comment TEXT
);
ALTER TABLE TblWznmAMMethodInvpar OWNER TO epsi;
CREATE INDEX TblWznmAMMethodInvpar_mtdRefWznmMMethod ON TblWznmAMMethodInvpar (mtdRefWznmMMethod);
CREATE INDEX TblWznmAMMethodInvpar_mtdNum ON TblWznmAMMethodInvpar (mtdNum);
CREATE INDEX TblWznmAMMethodInvpar_sref ON TblWznmAMMethodInvpar (sref);

CREATE TABLE TblWznmAMMethodRetpar(
	ref BIGSERIAL PRIMARY KEY,
	mtdRefWznmMMethod BIGINT,
	mtdNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Length INT,
	Comment TEXT
);
ALTER TABLE TblWznmAMMethodRetpar OWNER TO epsi;
CREATE INDEX TblWznmAMMethodRetpar_mtdRefWznmMMethod ON TblWznmAMMethodRetpar (mtdRefWznmMMethod);
CREATE INDEX TblWznmAMMethodRetpar_mtdNum ON TblWznmAMMethodRetpar (mtdNum);
CREATE INDEX TblWznmAMMethodRetpar_sref ON TblWznmAMMethodRetpar (sref);

CREATE TABLE TblWznmAMOpInvarg(
	ref BIGSERIAL PRIMARY KEY,
	refWznmCAMOpInvarg BIGINT,
	opxRefWznmMOp BIGINT,
	opxNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Defval VARCHAR(192),
	refWznmMVectoritem BIGINT,
	Comment TEXT
);
ALTER TABLE TblWznmAMOpInvarg OWNER TO epsi;
CREATE INDEX TblWznmAMOpInvarg_refWznmCAMOpInvarg ON TblWznmAMOpInvarg (refWznmCAMOpInvarg);
CREATE INDEX TblWznmAMOpInvarg_opxRefWznmMOp ON TblWznmAMOpInvarg (opxRefWznmMOp);
CREATE INDEX TblWznmAMOpInvarg_opxNum ON TblWznmAMOpInvarg (opxNum);
CREATE INDEX TblWznmAMOpInvarg_sref ON TblWznmAMOpInvarg (sref);

CREATE TABLE TblWznmAMOppackInvarg(
	ref BIGSERIAL PRIMARY KEY,
	refWznmCAMOppackInvarg BIGINT,
	opkRefWznmMOppack BIGINT,
	opkNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Defval VARCHAR(192),
	refWznmMVectoritem BIGINT,
	Comment TEXT
);
ALTER TABLE TblWznmAMOppackInvarg OWNER TO epsi;
CREATE INDEX TblWznmAMOppackInvarg_refWznmCAMOppackInvarg ON TblWznmAMOppackInvarg (refWznmCAMOppackInvarg);
CREATE INDEX TblWznmAMOppackInvarg_opkRefWznmMOppack ON TblWznmAMOppackInvarg (opkRefWznmMOppack);
CREATE INDEX TblWznmAMOppackInvarg_opkNum ON TblWznmAMOppackInvarg (opkNum);
CREATE INDEX TblWznmAMOppackInvarg_sref ON TblWznmAMOppackInvarg (sref);

CREATE TABLE TblWznmAMOppackRetval(
	ref BIGSERIAL PRIMARY KEY,
	refWznmCAMOppackRetval BIGINT,
	opkRefWznmMOppack BIGINT,
	opkNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Comment TEXT
);
ALTER TABLE TblWznmAMOppackRetval OWNER TO epsi;
CREATE INDEX TblWznmAMOppackRetval_refWznmCAMOppackRetval ON TblWznmAMOppackRetval (refWznmCAMOppackRetval);
CREATE INDEX TblWznmAMOppackRetval_opkRefWznmMOppack ON TblWznmAMOppackRetval (opkRefWznmMOppack);
CREATE INDEX TblWznmAMOppackRetval_opkNum ON TblWznmAMOppackRetval (opkNum);
CREATE INDEX TblWznmAMOppackRetval_sref ON TblWznmAMOppackRetval (sref);

CREATE TABLE TblWznmAMOpRetval(
	ref BIGSERIAL PRIMARY KEY,
	refWznmCAMOpRetval BIGINT,
	opxRefWznmMOp BIGINT,
	opxNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Comment TEXT
);
ALTER TABLE TblWznmAMOpRetval OWNER TO epsi;
CREATE INDEX TblWznmAMOpRetval_refWznmCAMOpRetval ON TblWznmAMOpRetval (refWznmCAMOpRetval);
CREATE INDEX TblWznmAMOpRetval_opxRefWznmMOp ON TblWznmAMOpRetval (opxRefWznmMOp);
CREATE INDEX TblWznmAMOpRetval_opxNum ON TblWznmAMOpRetval (opxNum);
CREATE INDEX TblWznmAMOpRetval_sref ON TblWznmAMOpRetval (sref);

CREATE TABLE TblWznmAMPersonDetail(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMPerson BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWznmAMPersonDetail OWNER TO epsi;
CREATE INDEX TblWznmAMPersonDetail_refWznmMPerson ON TblWznmAMPersonDetail (refWznmMPerson);
CREATE INDEX TblWznmAMPersonDetail_x1SrefKType ON TblWznmAMPersonDetail (x1SrefKType);

CREATE TABLE TblWznmAMQueryClause(
	ref BIGSERIAL PRIMARY KEY,
	qryRefWznmMQuery BIGINT,
	qryNum INT,
	x1RefWznmMQuerymod BIGINT,
	ixVBasetype INT,
	Clause VARCHAR(1024),
	refWznmMPreset BIGINT,
	refWznmMVector BIGINT,
	refWznmMVectoritem BIGINT
);
ALTER TABLE TblWznmAMQueryClause OWNER TO epsi;
CREATE INDEX TblWznmAMQueryClause_qryRefWznmMQuery ON TblWznmAMQueryClause (qryRefWznmMQuery);
CREATE INDEX TblWznmAMQueryClause_qryNum ON TblWznmAMQueryClause (qryNum);
CREATE INDEX TblWznmAMQueryClause_x1RefWznmMQuerymod ON TblWznmAMQueryClause (x1RefWznmMQuerymod);

CREATE TABLE TblWznmAMQueryOrder(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMQuery BIGINT,
	Short VARCHAR(30),
	srefsWznmMTablecol VARCHAR(192)
);
ALTER TABLE TblWznmAMQueryOrder OWNER TO epsi;
CREATE INDEX TblWznmAMQueryOrder_refWznmMQuery ON TblWznmAMQueryOrder (refWznmMQuery);

CREATE TABLE TblWznmAMRelationTitle(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMRelation BIGINT,
	x1IxVType INT,
	x2RefWznmMLocale BIGINT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmAMRelationTitle OWNER TO epsi;
CREATE INDEX TblWznmAMRelationTitle_refWznmMRelation ON TblWznmAMRelationTitle (refWznmMRelation);
CREATE INDEX TblWznmAMRelationTitle_x1IxVType ON TblWznmAMRelationTitle (x1IxVType);
CREATE INDEX TblWznmAMRelationTitle_x2RefWznmMLocale ON TblWznmAMRelationTitle (x2RefWznmMLocale);

CREATE TABLE TblWznmAMStateStep(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMState BIGINT,
	snxRefWznmMState BIGINT,
	ixVTrigger INT,
	refWznmMRtjob BIGINT,
	refWznmMVectoritem BIGINT,
	xsref VARCHAR(50),
	refWznmMRtdpch BIGINT,
	srefsMask VARCHAR(192),
	Cond TEXT,
	Custcode SMALLINT
);
ALTER TABLE TblWznmAMStateStep OWNER TO epsi;
CREATE INDEX TblWznmAMStateStep_refWznmMState ON TblWznmAMStateStep (refWznmMState);

CREATE TABLE TblWznmAMSubsetTitle(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMSubset BIGINT,
	x1IxVType INT,
	x2RefWznmMLocale BIGINT,
	ixWznmVGender INT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmAMSubsetTitle OWNER TO epsi;
CREATE INDEX TblWznmAMSubsetTitle_refWznmMSubset ON TblWznmAMSubsetTitle (refWznmMSubset);
CREATE INDEX TblWznmAMSubsetTitle_x1IxVType ON TblWznmAMSubsetTitle (x1IxVType);
CREATE INDEX TblWznmAMSubsetTitle_x2RefWznmMLocale ON TblWznmAMSubsetTitle (x2RefWznmMLocale);

CREATE TABLE TblWznmAMTablecolTitle(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMTablecol BIGINT,
	x1IxVType INT,
	x2RefWznmMLocale BIGINT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmAMTablecolTitle OWNER TO epsi;
CREATE INDEX TblWznmAMTablecolTitle_refWznmMTablecol ON TblWznmAMTablecolTitle (refWznmMTablecol);
CREATE INDEX TblWznmAMTablecolTitle_x1IxVType ON TblWznmAMTablecolTitle (x1IxVType);
CREATE INDEX TblWznmAMTablecolTitle_x2RefWznmMLocale ON TblWznmAMTablecolTitle (x2RefWznmMLocale);

CREATE TABLE TblWznmAMTableLoadfct(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMTable BIGINT,
	ixVLoadtype INT,
	Fctname VARCHAR(50),
	ldSrefWznmMTablecol VARCHAR(50),
	lbySrefsWznmMTablecol VARCHAR(192),
	ordSrefsWznmMTablecol VARCHAR(192),
	ixVLimtype INT
);
ALTER TABLE TblWznmAMTableLoadfct OWNER TO epsi;
CREATE INDEX TblWznmAMTableLoadfct_refWznmMTable ON TblWznmAMTableLoadfct (refWznmMTable);
CREATE INDEX TblWznmAMTableLoadfct_Fctname ON TblWznmAMTableLoadfct (Fctname);

CREATE TABLE TblWznmAMTableTitle(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMTable BIGINT,
	x1IxVType INT,
	x2RefWznmMLocale BIGINT,
	ixWznmVGender INT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmAMTableTitle OWNER TO epsi;
CREATE INDEX TblWznmAMTableTitle_refWznmMTable ON TblWznmAMTableTitle (refWznmMTable);
CREATE INDEX TblWznmAMTableTitle_x1IxVType ON TblWznmAMTableTitle (x1IxVType);
CREATE INDEX TblWznmAMTableTitle_x2RefWznmMLocale ON TblWznmAMTableTitle (x2RefWznmMLocale);

CREATE TABLE TblWznmAMUserAccess(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMUser BIGINT,
	x1IxWznmVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWznmWAccess INT
);
ALTER TABLE TblWznmAMUserAccess OWNER TO epsi;
CREATE INDEX TblWznmAMUserAccess_refWznmMUser ON TblWznmAMUserAccess (refWznmMUser);
CREATE INDEX TblWznmAMUserAccess_x1IxWznmVFeatgroup ON TblWznmAMUserAccess (x1IxWznmVFeatgroup);
CREATE INDEX TblWznmAMUserAccess_x2FeaSrefUix ON TblWznmAMUserAccess (x2FeaSrefUix);

CREATE TABLE TblWznmAMUsergroupAccess(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMUsergroup BIGINT,
	x1IxWznmVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWznmWAccess INT
);
ALTER TABLE TblWznmAMUsergroupAccess OWNER TO epsi;
CREATE INDEX TblWznmAMUsergroupAccess_refWznmMUsergroup ON TblWznmAMUsergroupAccess (refWznmMUsergroup);
CREATE INDEX TblWznmAMUsergroupAccess_x1IxWznmVFeatgroup ON TblWznmAMUsergroupAccess (x1IxWznmVFeatgroup);
CREATE INDEX TblWznmAMUsergroupAccess_x2FeaSrefUix ON TblWznmAMUsergroupAccess (x2FeaSrefUix);

CREATE TABLE TblWznmAMVectorTitle(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMVector BIGINT,
	x1IxVType INT,
	x2RefWznmMLocale BIGINT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmAMVectorTitle OWNER TO epsi;
CREATE INDEX TblWznmAMVectorTitle_refWznmMVector ON TblWznmAMVectorTitle (refWznmMVector);
CREATE INDEX TblWznmAMVectorTitle_x1IxVType ON TblWznmAMVectorTitle (x1IxVType);
CREATE INDEX TblWznmAMVectorTitle_x2RefWznmMLocale ON TblWznmAMVectorTitle (x2RefWznmMLocale);

CREATE TABLE TblWznmAVControlPar(
	ref BIGSERIAL PRIMARY KEY,
	ixWznmVControl INT,
	x1RefWznmMUser BIGINT,
	x2IxWznmVLocale INT,
	Par VARCHAR(192),
	Val VARCHAR(192)
);
ALTER TABLE TblWznmAVControlPar OWNER TO epsi;
CREATE INDEX TblWznmAVControlPar_ixWznmVControl ON TblWznmAVControlPar (ixWznmVControl);
CREATE INDEX TblWznmAVControlPar_x1RefWznmMUser ON TblWznmAVControlPar (x1RefWznmMUser);
CREATE INDEX TblWznmAVControlPar_x2IxWznmVLocale ON TblWznmAVControlPar (x2IxWznmVLocale);

CREATE TABLE TblWznmAVKeylistKey(
	ref BIGSERIAL PRIMARY KEY,
	klsIxWznmVKeylist INT,
	klsNum INT,
	x1IxWznmVMaintable INT,
	x1Uref BIGINT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT,
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWznmAVKeylistKey OWNER TO epsi;
CREATE INDEX TblWznmAVKeylistKey_klsNum ON TblWznmAVKeylistKey (klsNum);
CREATE INDEX TblWznmAVKeylistKey_x1IxWznmVMaintable ON TblWznmAVKeylistKey (x1IxWznmVMaintable);
CREATE INDEX TblWznmAVKeylistKey_x1Uref ON TblWznmAVKeylistKey (x1Uref);
CREATE INDEX TblWznmAVKeylistKey_sref ON TblWznmAVKeylistKey (sref);

CREATE TABLE TblWznmAVValuelistVal(
	ref BIGSERIAL PRIMARY KEY,
	vlsIxWznmVValuelist INT,
	vlsNum INT,
	x1IxWznmVLocale INT,
	Val VARCHAR(192)
);
ALTER TABLE TblWznmAVValuelistVal OWNER TO epsi;
CREATE INDEX TblWznmAVValuelistVal_vlsIxWznmVValuelist ON TblWznmAVValuelistVal (vlsIxWznmVValuelist);
CREATE INDEX TblWznmAVValuelistVal_vlsNum ON TblWznmAVValuelistVal (vlsNum);
CREATE INDEX TblWznmAVValuelistVal_x1IxWznmVLocale ON TblWznmAVValuelistVal (x1IxWznmVLocale);

CREATE SEQUENCE TblWznmCAMBlockItem INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWznmCAMBlockItem OWNER TO epsi;

CREATE SEQUENCE TblWznmCAMJobVar INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWznmCAMJobVar OWNER TO epsi;

CREATE SEQUENCE TblWznmCAMOpInvarg INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWznmCAMOpInvarg OWNER TO epsi;

CREATE SEQUENCE TblWznmCAMOppackInvarg INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWznmCAMOppackInvarg OWNER TO epsi;

CREATE SEQUENCE TblWznmCAMOppackRetval INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWznmCAMOppackRetval OWNER TO epsi;

CREATE SEQUENCE TblWznmCAMOpRetval INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWznmCAMOpRetval OWNER TO epsi;

CREATE SEQUENCE TblWznmCControl INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWznmCControl OWNER TO epsi;

CREATE SEQUENCE TblWznmCFile INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWznmCFile OWNER TO epsi;

CREATE SEQUENCE TblWznmCRelation INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWznmCRelation OWNER TO epsi;

CREATE TABLE TblWznmHistRMUserUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMUser BIGINT,
	unvIxWznmVMaintable INT,
	unvUref BIGINT,
	ixWznmVCard INT,
	ixWznmVPreset INT,
	preIxWznmVMaintable INT,
	preUref BIGINT,
	start INT
);
ALTER TABLE TblWznmHistRMUserUniversal OWNER TO epsi;
CREATE INDEX TblWznmHistRMUserUniversal_refWznmMUser ON TblWznmHistRMUserUniversal (refWznmMUser);
CREATE INDEX TblWznmHistRMUserUniversal_unvIxWznmVMaintable ON TblWznmHistRMUserUniversal (unvIxWznmVMaintable);
CREATE INDEX TblWznmHistRMUserUniversal_unvUref ON TblWznmHistRMUserUniversal (unvUref);
CREATE INDEX TblWznmHistRMUserUniversal_ixWznmVCard ON TblWznmHistRMUserUniversal (ixWznmVCard);
CREATE INDEX TblWznmHistRMUserUniversal_ixWznmVPreset ON TblWznmHistRMUserUniversal (ixWznmVPreset);
CREATE INDEX TblWznmHistRMUserUniversal_preIxWznmVMaintable ON TblWznmHistRMUserUniversal (preIxWznmVMaintable);
CREATE INDEX TblWznmHistRMUserUniversal_preUref ON TblWznmHistRMUserUniversal (preUref);
CREATE INDEX TblWznmHistRMUserUniversal_start ON TblWznmHistRMUserUniversal (start);

CREATE TABLE TblWznmJAMBlockItem(
	ref BIGSERIAL PRIMARY KEY,
	refWznmAMBlockItem BIGINT,
	x1RefWznmMRelease BIGINT,
	Defval VARCHAR(192),
	refWznmMVectoritem BIGINT
);
ALTER TABLE TblWznmJAMBlockItem OWNER TO epsi;
CREATE INDEX TblWznmJAMBlockItem_refWznmAMBlockItem ON TblWznmJAMBlockItem (refWznmAMBlockItem);
CREATE INDEX TblWznmJAMBlockItem_x1RefWznmMRelease ON TblWznmJAMBlockItem (x1RefWznmMRelease);

CREATE TABLE TblWznmJAVKeylistKey(
	ref BIGSERIAL PRIMARY KEY,
	refWznmAVKeylistKey BIGINT,
	x1IxWznmVLocale INT,
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWznmJAVKeylistKey OWNER TO epsi;
CREATE INDEX TblWznmJAVKeylistKey_refWznmAVKeylistKey ON TblWznmJAVKeylistKey (refWznmAVKeylistKey);
CREATE INDEX TblWznmJAVKeylistKey_x1IxWznmVLocale ON TblWznmJAVKeylistKey (x1IxWznmVLocale);

CREATE TABLE TblWznmJMCardTitle(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMCard BIGINT,
	x1RefWznmMLocale BIGINT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmJMCardTitle OWNER TO epsi;
CREATE INDEX TblWznmJMCardTitle_refWznmMCard ON TblWznmJMCardTitle (refWznmMCard);
CREATE INDEX TblWznmJMCardTitle_x1RefWznmMLocale ON TblWznmJMCardTitle (x1RefWznmMLocale);

CREATE TABLE TblWznmJMControl(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMControl BIGINT,
	x1RefWznmMVectoritem BIGINT,
	x2RefWznmMPreset BIGINT,
	stdRefWznmMStub BIGINT,
	shoRefWznmMStub BIGINT
);
ALTER TABLE TblWznmJMControl OWNER TO epsi;
CREATE INDEX TblWznmJMControl_refWznmMControl ON TblWznmJMControl (refWznmMControl);
CREATE INDEX TblWznmJMControl_x1RefWznmMVectoritem ON TblWznmJMControl (x1RefWznmMVectoritem);
CREATE INDEX TblWznmJMControl_x2RefWznmMPreset ON TblWznmJMControl (x2RefWznmMPreset);

CREATE TABLE TblWznmJMControlTitle(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMControl BIGINT,
	x1RefWznmMLocale BIGINT,
	Title VARCHAR(192)
);
ALTER TABLE TblWznmJMControlTitle OWNER TO epsi;
CREATE INDEX TblWznmJMControlTitle_refWznmMControl ON TblWznmJMControlTitle (refWznmMControl);
CREATE INDEX TblWznmJMControlTitle_x1RefWznmMLocale ON TblWznmJMControlTitle (x1RefWznmMLocale);

CREATE TABLE TblWznmJMErrorTitle(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMError BIGINT,
	x1RefWznmMLocale BIGINT,
	Title VARCHAR(192)
);
ALTER TABLE TblWznmJMErrorTitle OWNER TO epsi;
CREATE INDEX TblWznmJMErrorTitle_refWznmMError ON TblWznmJMErrorTitle (refWznmMError);
CREATE INDEX TblWznmJMErrorTitle_x1RefWznmMLocale ON TblWznmJMErrorTitle (x1RefWznmMLocale);

CREATE TABLE TblWznmJMImpexpcolStub(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMImpexpcol BIGINT,
	x1RefWznmMVectoritem BIGINT,
	refWznmMStub BIGINT
);
ALTER TABLE TblWznmJMImpexpcolStub OWNER TO epsi;
CREATE INDEX TblWznmJMImpexpcolStub_refWznmMImpexpcol ON TblWznmJMImpexpcolStub (refWznmMImpexpcol);
CREATE INDEX TblWznmJMImpexpcolStub_x1RefWznmMVectoritem ON TblWznmJMImpexpcolStub (x1RefWznmMVectoritem);

CREATE TABLE TblWznmJMImpexpcplxTitle(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMImpexpcplx BIGINT,
	x1RefWznmMLocale BIGINT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmJMImpexpcplxTitle OWNER TO epsi;
CREATE INDEX TblWznmJMImpexpcplxTitle_refWznmMImpexpcplx ON TblWznmJMImpexpcplxTitle (refWznmMImpexpcplx);
CREATE INDEX TblWznmJMImpexpcplxTitle_x1RefWznmMLocale ON TblWznmJMImpexpcplxTitle (x1RefWznmMLocale);

CREATE TABLE TblWznmJMLocaleTitle(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMLocale BIGINT,
	x1RefWznmMLocale BIGINT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmJMLocaleTitle OWNER TO epsi;
CREATE INDEX TblWznmJMLocaleTitle_refWznmMLocale ON TblWznmJMLocaleTitle (refWznmMLocale);
CREATE INDEX TblWznmJMLocaleTitle_x1RefWznmMLocale ON TblWznmJMLocaleTitle (x1RefWznmMLocale);

CREATE TABLE TblWznmJMModule(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMModule BIGINT,
	x1RefWznmMLocale BIGINT,
	Title VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWznmJMModule OWNER TO epsi;
CREATE INDEX TblWznmJMModule_refWznmMModule ON TblWznmJMModule (refWznmMModule);
CREATE INDEX TblWznmJMModule_x1RefWznmMLocale ON TblWznmJMModule (x1RefWznmMLocale);

CREATE TABLE TblWznmJMPersonLastname(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMPerson BIGINT,
	x1Startd INT,
	Lastname VARCHAR(50)
);
ALTER TABLE TblWznmJMPersonLastname OWNER TO epsi;
CREATE INDEX TblWznmJMPersonLastname_refWznmMPerson ON TblWznmJMPersonLastname (refWznmMPerson);
CREATE INDEX TblWznmJMPersonLastname_x1Startd ON TblWznmJMPersonLastname (x1Startd);
CREATE INDEX TblWznmJMPersonLastname_Lastname ON TblWznmJMPersonLastname (Lastname);

CREATE TABLE TblWznmJMPresetTitle(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMPreset BIGINT,
	x1RefWznmMLocale BIGINT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmJMPresetTitle OWNER TO epsi;
CREATE INDEX TblWznmJMPresetTitle_refWznmMPreset ON TblWznmJMPresetTitle (refWznmMPreset);
CREATE INDEX TblWznmJMPresetTitle_x1RefWznmMLocale ON TblWznmJMPresetTitle (x1RefWznmMLocale);

CREATE TABLE TblWznmJMQuerycolStub(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMQuerycol BIGINT,
	x1RefWznmMVectoritem BIGINT,
	x2RefWznmMPreset BIGINT,
	refWznmMStub BIGINT
);
ALTER TABLE TblWznmJMQuerycolStub OWNER TO epsi;
CREATE INDEX TblWznmJMQuerycolStub_refWznmMQuerycol ON TblWznmJMQuerycolStub (refWznmMQuerycol);
CREATE INDEX TblWznmJMQuerycolStub_x1RefWznmMVectoritem ON TblWznmJMQuerycolStub (x1RefWznmMVectoritem);
CREATE INDEX TblWznmJMQuerycolStub_x2RefWznmMPreset ON TblWznmJMQuerycolStub (x2RefWznmMPreset);

CREATE TABLE TblWznmJMSquawkTitle(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMSquawk BIGINT,
	x1RefWznmMLocale BIGINT,
	Title VARCHAR(192)
);
ALTER TABLE TblWznmJMSquawkTitle OWNER TO epsi;
CREATE INDEX TblWznmJMSquawkTitle_refWznmMSquawk ON TblWznmJMSquawkTitle (refWznmMSquawk);
CREATE INDEX TblWznmJMSquawkTitle_x1RefWznmMLocale ON TblWznmJMSquawkTitle (x1RefWznmMLocale);

CREATE TABLE TblWznmJMTagTitle(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMTag BIGINT,
	x1RefWznmMLocale BIGINT,
	Title VARCHAR(192)
);
ALTER TABLE TblWznmJMTagTitle OWNER TO epsi;
CREATE INDEX TblWznmJMTagTitle_refWznmMTag ON TblWznmJMTagTitle (refWznmMTag);
CREATE INDEX TblWznmJMTagTitle_x1RefWznmMLocale ON TblWznmJMTagTitle (x1RefWznmMLocale);

CREATE TABLE TblWznmJMUserState(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMUser BIGINT,
	x1Start INT,
	ixVState INT
);
ALTER TABLE TblWznmJMUserState OWNER TO epsi;
CREATE INDEX TblWznmJMUserState_refWznmMUser ON TblWznmJMUserState (refWznmMUser);
CREATE INDEX TblWznmJMUserState_x1Start ON TblWznmJMUserState (x1Start);

CREATE TABLE TblWznmJMVectoritem(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMVectoritem BIGINT,
	x1RefWznmMLocale BIGINT,
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWznmJMVectoritem OWNER TO epsi;
CREATE INDEX TblWznmJMVectoritem_refWznmMVectoritem ON TblWznmJMVectoritem (refWznmMVectoritem);
CREATE INDEX TblWznmJMVectoritem_x1RefWznmMLocale ON TblWznmJMVectoritem (x1RefWznmMLocale);

CREATE TABLE TblWznmJMVersion(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMVersion BIGINT,
	x1RefWznmMLocale BIGINT,
	About1 TEXT,
	About2 TEXT,
	About3 TEXT
);
ALTER TABLE TblWznmJMVersion OWNER TO epsi;
CREATE INDEX TblWznmJMVersion_refWznmMVersion ON TblWznmJMVersion (refWznmMVersion);
CREATE INDEX TblWznmJMVersion_x1RefWznmMLocale ON TblWznmJMVersion (x1RefWznmMLocale);

CREATE TABLE TblWznmJMVersionState(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMVersion BIGINT,
	x1Start INT,
	ixVState INT
);
ALTER TABLE TblWznmJMVersionState OWNER TO epsi;
CREATE INDEX TblWznmJMVersionState_refWznmMVersion ON TblWznmJMVersionState (refWznmMVersion);
CREATE INDEX TblWznmJMVersionState_x1Start ON TblWznmJMVersionState (x1Start);

CREATE TABLE TblWznmMApp(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	ixVTarget INT,
	verRefWznmMVersion BIGINT,
	verNum INT,
	Short VARCHAR(10),
	Title VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWznmMApp OWNER TO epsi;
CREATE INDEX TblWznmMApp_grp ON TblWznmMApp (grp);
CREATE INDEX TblWznmMApp_own ON TblWznmMApp (own);
CREATE INDEX TblWznmMApp_ixVTarget ON TblWznmMApp (ixVTarget);
CREATE INDEX TblWznmMApp_verRefWznmMVersion ON TblWznmMApp (verRefWznmMVersion);
CREATE INDEX TblWznmMApp_verNum ON TblWznmMApp (verNum);
CREATE INDEX TblWznmMApp_Title ON TblWznmMApp (Title);

CREATE TABLE TblWznmMBlock(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	reaIxWznmWScope INT,
	wriIxWznmWScope INT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWznmMBlock OWNER TO epsi;
CREATE INDEX TblWznmMBlock_ixVBasetype ON TblWznmMBlock (ixVBasetype);
CREATE INDEX TblWznmMBlock_refWznmMVersion ON TblWznmMBlock (refWznmMVersion);
CREATE INDEX TblWznmMBlock_refIxVTbl ON TblWznmMBlock (refIxVTbl);
CREATE INDEX TblWznmMBlock_refUref ON TblWznmMBlock (refUref);
CREATE INDEX TblWznmMBlock_reaIxWznmWScope ON TblWznmMBlock (reaIxWznmWScope);
CREATE INDEX TblWznmMBlock_wriIxWznmWScope ON TblWznmMBlock (wriIxWznmWScope);
CREATE INDEX TblWznmMBlock_sref ON TblWznmMBlock (sref);

CREATE TABLE TblWznmMCall(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	invIxWznmWArgtype INT,
	retIxWznmWArgtype INT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWznmMCall OWNER TO epsi;
CREATE INDEX TblWznmMCall_ixVBasetype ON TblWznmMCall (ixVBasetype);
CREATE INDEX TblWznmMCall_refWznmMVersion ON TblWznmMCall (refWznmMVersion);
CREATE INDEX TblWznmMCall_refIxVTbl ON TblWznmMCall (refIxVTbl);
CREATE INDEX TblWznmMCall_refUref ON TblWznmMCall (refUref);
CREATE INDEX TblWznmMCall_invIxWznmWArgtype ON TblWznmMCall (invIxWznmWArgtype);
CREATE INDEX TblWznmMCall_retIxWznmWArgtype ON TblWznmMCall (retIxWznmWArgtype);
CREATE INDEX TblWznmMCall_sref ON TblWznmMCall (sref);

CREATE TABLE TblWznmMCapability(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMVersion BIGINT,
	tplRefWznmMCapability BIGINT,
	sref VARCHAR(50),
	ixWArtefact INT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmMCapability OWNER TO epsi;
CREATE INDEX TblWznmMCapability_refWznmMVersion ON TblWznmMCapability (refWznmMVersion);
CREATE INDEX TblWznmMCapability_tplRefWznmMCapability ON TblWznmMCapability (tplRefWznmMCapability);
CREATE INDEX TblWznmMCapability_sref ON TblWznmMCapability (sref);

CREATE TABLE TblWznmMCard(
	ref BIGSERIAL PRIMARY KEY,
	mdlRefWznmMModule BIGINT,
	mdlNum INT,
	refIxVTbl INT,
	refUref BIGINT,
	refWznmMJob BIGINT,
	sref VARCHAR(50),
	refJTitle BIGINT,
	Title VARCHAR(50),
	Avail VARCHAR(1024),
	Active VARCHAR(1024)
);
ALTER TABLE TblWznmMCard OWNER TO epsi;
CREATE INDEX TblWznmMCard_mdlRefWznmMModule ON TblWznmMCard (mdlRefWznmMModule);
CREATE INDEX TblWznmMCard_mdlNum ON TblWznmMCard (mdlNum);
CREATE INDEX TblWznmMCard_refIxVTbl ON TblWznmMCard (refIxVTbl);
CREATE INDEX TblWznmMCard_refUref ON TblWznmMCard (refUref);
CREATE INDEX TblWznmMCard_refWznmMJob ON TblWznmMCard (refWznmMJob);
CREATE INDEX TblWznmMCard_sref ON TblWznmMCard (sref);

CREATE TABLE TblWznmMCheck(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmMTable BIGINT,
	refWznmMTablecol BIGINT,
	refWznmMCall BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWznmMCheck OWNER TO epsi;
CREATE INDEX TblWznmMCheck_ixVBasetype ON TblWznmMCheck (ixVBasetype);
CREATE INDEX TblWznmMCheck_refWznmMTable ON TblWznmMCheck (refWznmMTable);
CREATE INDEX TblWznmMCheck_refWznmMTablecol ON TblWznmMCheck (refWznmMTablecol);
CREATE INDEX TblWznmMCheck_refWznmMCall ON TblWznmMCheck (refWznmMCall);
CREATE INDEX TblWznmMCheck_sref ON TblWznmMCheck (sref);

CREATE TABLE TblWznmMComponent(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(100),
	Comment TEXT
);
ALTER TABLE TblWznmMComponent OWNER TO epsi;
CREATE INDEX TblWznmMComponent_ixVBasetype ON TblWznmMComponent (ixVBasetype);
CREATE INDEX TblWznmMComponent_refWznmMVersion ON TblWznmMComponent (refWznmMVersion);
CREATE INDEX TblWznmMComponent_sref ON TblWznmMComponent (sref);

CREATE TABLE TblWznmMControl(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmCControl BIGINT,
	hkIxVTbl INT,
	hkUref BIGINT,
	hkNum INT,
	hkIxVSection INT,
	refIxVTbl INT,
	refUref BIGINT,
	supRefWznmMControl BIGINT,
	supLvl SMALLINT,
	supNum INT,
	ixVScope INT,
	refWznmMFeed BIGINT,
	sref VARCHAR(50),
	ixVSubtype INT,
	srefsWznmMTag VARCHAR(192),
	refJTitle BIGINT,
	Title VARCHAR(192),
	refJ BIGINT,
	stdRefWznmMStub BIGINT,
	shoRefWznmMStub BIGINT,
	Avail VARCHAR(1024),
	Active VARCHAR(1024),
	srefsKOption VARCHAR(192)
);
ALTER TABLE TblWznmMControl OWNER TO epsi;
CREATE INDEX TblWznmMControl_ixVBasetype ON TblWznmMControl (ixVBasetype);
CREATE INDEX TblWznmMControl_refWznmCControl ON TblWznmMControl (refWznmCControl);
CREATE INDEX TblWznmMControl_hkIxVTbl ON TblWznmMControl (hkIxVTbl);
CREATE INDEX TblWznmMControl_hkUref ON TblWznmMControl (hkUref);
CREATE INDEX TblWznmMControl_hkNum ON TblWznmMControl (hkNum);
CREATE INDEX TblWznmMControl_hkIxVSection ON TblWznmMControl (hkIxVSection);
CREATE INDEX TblWznmMControl_refIxVTbl ON TblWznmMControl (refIxVTbl);
CREATE INDEX TblWznmMControl_refUref ON TblWznmMControl (refUref);
CREATE INDEX TblWznmMControl_supRefWznmMControl ON TblWznmMControl (supRefWznmMControl);
CREATE INDEX TblWznmMControl_supLvl ON TblWznmMControl (supLvl);
CREATE INDEX TblWznmMControl_supNum ON TblWznmMControl (supNum);
CREATE INDEX TblWznmMControl_ixVScope ON TblWznmMControl (ixVScope);
CREATE INDEX TblWznmMControl_refWznmMFeed ON TblWznmMControl (refWznmMFeed);
CREATE INDEX TblWznmMControl_sref ON TblWznmMControl (sref);

CREATE TABLE TblWznmMDialog(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmMCard BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	refWznmMJob BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWznmMDialog OWNER TO epsi;
CREATE INDEX TblWznmMDialog_ixVBasetype ON TblWznmMDialog (ixVBasetype);
CREATE INDEX TblWznmMDialog_refWznmMCard ON TblWznmMDialog (refWznmMCard);
CREATE INDEX TblWznmMDialog_refIxVTbl ON TblWznmMDialog (refIxVTbl);
CREATE INDEX TblWznmMDialog_refUref ON TblWznmMDialog (refUref);
CREATE INDEX TblWznmMDialog_refWznmMJob ON TblWznmMDialog (refWznmMJob);
CREATE INDEX TblWznmMDialog_sref ON TblWznmMDialog (sref);

CREATE TABLE TblWznmMError(
	ref BIGSERIAL PRIMARY KEY,
	verRefWznmMVersion BIGINT,
	verNum INT,
	sref VARCHAR(50),
	refJTitle BIGINT,
	Title VARCHAR(192)
);
ALTER TABLE TblWznmMError OWNER TO epsi;
CREATE INDEX TblWznmMError_verRefWznmMVersion ON TblWznmMError (verRefWznmMVersion);
CREATE INDEX TblWznmMError_verNum ON TblWznmMError (verNum);
CREATE INDEX TblWznmMError_sref ON TblWznmMError (sref);

CREATE TABLE TblWznmMFeed(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMControl BIGINT,
	srcIxVTbl INT,
	srcUref BIGINT,
	sref VARCHAR(50),
	srefsWznmMVectoritem VARCHAR(192),
	srefsWznmMTag VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWznmMFeed OWNER TO epsi;
CREATE INDEX TblWznmMFeed_refWznmMControl ON TblWznmMFeed (refWznmMControl);
CREATE INDEX TblWznmMFeed_srcIxVTbl ON TblWznmMFeed (srcIxVTbl);
CREATE INDEX TblWznmMFeed_srcUref ON TblWznmMFeed (srcUref);
CREATE INDEX TblWznmMFeed_sref ON TblWznmMFeed (sref);

CREATE TABLE TblWznmMFile(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refWznmCFile BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	Archived INT,
	Filename VARCHAR(50),
	Archivename VARCHAR(30),
	srefKMimetype VARCHAR(50),
	Size INT,
	Comment TEXT
);
ALTER TABLE TblWznmMFile OWNER TO epsi;
CREATE INDEX TblWznmMFile_grp ON TblWznmMFile (grp);
CREATE INDEX TblWznmMFile_own ON TblWznmMFile (own);
CREATE INDEX TblWznmMFile_refWznmCFile ON TblWznmMFile (refWznmCFile);
CREATE INDEX TblWznmMFile_refIxVTbl ON TblWznmMFile (refIxVTbl);
CREATE INDEX TblWznmMFile_refUref ON TblWznmMFile (refUref);
CREATE INDEX TblWznmMFile_Filename ON TblWznmMFile (Filename);

CREATE TABLE TblWznmMImpexp(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMImpexpcplx BIGINT,
	supRefWznmMImpexp BIGINT,
	supLvl SMALLINT,
	refWznmMTable BIGINT,
	sref VARCHAR(50),
	ixWIop INT,
	rtrSrefsWznmMImpexpcol VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWznmMImpexp OWNER TO epsi;
CREATE INDEX TblWznmMImpexp_refWznmMImpexpcplx ON TblWznmMImpexp (refWznmMImpexpcplx);
CREATE INDEX TblWznmMImpexp_supRefWznmMImpexp ON TblWznmMImpexp (supRefWznmMImpexp);
CREATE INDEX TblWznmMImpexp_supLvl ON TblWznmMImpexp (supLvl);
CREATE INDEX TblWznmMImpexp_refWznmMTable ON TblWznmMImpexp (refWznmMTable);
CREATE INDEX TblWznmMImpexp_sref ON TblWznmMImpexp (sref);

CREATE TABLE TblWznmMImpexpcol(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	ixWOccurrence INT,
	imeRefWznmMImpexp BIGINT,
	imeNum INT,
	refWznmMTablecol BIGINT,
	sref VARCHAR(50),
	Short VARCHAR(10),
	refWznmMImpexp BIGINT,
	ixVConvtype INT,
	Defval VARCHAR(192),
	refWznmMPreset BIGINT,
	refJStub BIGINT,
	refWznmMStub BIGINT,
	refWznmMVectoritem BIGINT
);
ALTER TABLE TblWznmMImpexpcol OWNER TO epsi;
CREATE INDEX TblWznmMImpexpcol_ixVBasetype ON TblWznmMImpexpcol (ixVBasetype);
CREATE INDEX TblWznmMImpexpcol_ixWOccurrence ON TblWznmMImpexpcol (ixWOccurrence);
CREATE INDEX TblWznmMImpexpcol_imeRefWznmMImpexp ON TblWznmMImpexpcol (imeRefWznmMImpexp);
CREATE INDEX TblWznmMImpexpcol_imeNum ON TblWznmMImpexpcol (imeNum);
CREATE INDEX TblWznmMImpexpcol_refWznmMTablecol ON TblWznmMImpexpcol (refWznmMTablecol);
CREATE INDEX TblWznmMImpexpcol_sref ON TblWznmMImpexpcol (sref);

CREATE TABLE TblWznmMImpexpcplx(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMVersion BIGINT,
	refWznmMJob BIGINT,
	sref VARCHAR(50),
	Short VARCHAR(5),
	refJTitle BIGINT,
	Title VARCHAR(50),
	Minversion VARCHAR(10),
	Comment TEXT
);
ALTER TABLE TblWznmMImpexpcplx OWNER TO epsi;
CREATE INDEX TblWznmMImpexpcplx_refWznmMVersion ON TblWznmMImpexpcplx (refWznmMVersion);
CREATE INDEX TblWznmMImpexpcplx_refWznmMJob ON TblWznmMImpexpcplx (refWznmMJob);
CREATE INDEX TblWznmMImpexpcplx_sref ON TblWznmMImpexpcplx (sref);

CREATE TABLE TblWznmMJob(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	sref VARCHAR(50),
	Global SMALLINT,
	Clisrv SMALLINT,
	Shrdat SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWznmMJob OWNER TO epsi;
CREATE INDEX TblWznmMJob_ixVBasetype ON TblWznmMJob (ixVBasetype);
CREATE INDEX TblWznmMJob_refWznmMVersion ON TblWznmMJob (refWznmMVersion);
CREATE INDEX TblWznmMJob_refIxVTbl ON TblWznmMJob (refIxVTbl);
CREATE INDEX TblWznmMJob_refUref ON TblWznmMJob (refUref);
CREATE INDEX TblWznmMJob_sref ON TblWznmMJob (sref);
CREATE INDEX TblWznmMJob_Global ON TblWznmMJob (Global);

CREATE TABLE TblWznmMLibrary(
	ref BIGSERIAL PRIMARY KEY,
	sref VARCHAR(50),
	Title VARCHAR(50),
	Version VARCHAR(30),
	srefKLictype VARCHAR(50),
	depSrefsWznmMLibrary VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWznmMLibrary OWNER TO epsi;
CREATE INDEX TblWznmMLibrary_sref ON TblWznmMLibrary (sref);

CREATE TABLE TblWznmMLocale(
	ref BIGSERIAL PRIMARY KEY,
	sref VARCHAR(50),
	refJTitle BIGINT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmMLocale OWNER TO epsi;
CREATE INDEX TblWznmMLocale_sref ON TblWznmMLocale (sref);

CREATE TABLE TblWznmMMachine(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMMachtype BIGINT,
	sref VARCHAR(50),
	ixWznmWCloudtype INT,
	Comment TEXT
);
ALTER TABLE TblWznmMMachine OWNER TO epsi;
CREATE INDEX TblWznmMMachine_refWznmMMachtype ON TblWznmMMachine (refWznmMMachtype);
CREATE INDEX TblWznmMMachine_sref ON TblWznmMMachine (sref);

CREATE TABLE TblWznmMMachtype(
	ref BIGSERIAL PRIMARY KEY,
	sref VARCHAR(50),
	ixVArch INT,
	srefKOs VARCHAR(50),
	cchRefWznmMMachine BIGINT,
	srefKPkgmgr VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWznmMMachtype OWNER TO epsi;
CREATE INDEX TblWznmMMachtype_sref ON TblWznmMMachtype (sref);

CREATE TABLE TblWznmMMethod(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMJob BIGINT,
	sref VARCHAR(50),
	Execsrv SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWznmMMethod OWNER TO epsi;
CREATE INDEX TblWznmMMethod_refWznmMJob ON TblWznmMMethod (refWznmMJob);
CREATE INDEX TblWznmMMethod_sref ON TblWznmMMethod (sref);

CREATE TABLE TblWznmMModule(
	ref BIGSERIAL PRIMARY KEY,
	verRefWznmMVersion BIGINT,
	verNum INT,
	sref VARCHAR(50),
	refJ BIGINT,
	Title VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWznmMModule OWNER TO epsi;
CREATE INDEX TblWznmMModule_verRefWznmMVersion ON TblWznmMModule (verRefWznmMVersion);
CREATE INDEX TblWznmMModule_verNum ON TblWznmMModule (verNum);
CREATE INDEX TblWznmMModule_sref ON TblWznmMModule (sref);

CREATE TABLE TblWznmMOp(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMOppack BIGINT,
	refWznmMSquawk BIGINT,
	sref VARCHAR(50),
	Shrdat SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWznmMOp OWNER TO epsi;
CREATE INDEX TblWznmMOp_refWznmMOppack ON TblWznmMOp (refWznmMOppack);
CREATE INDEX TblWznmMOp_refWznmMSquawk ON TblWznmMOp (refWznmMSquawk);
CREATE INDEX TblWznmMOp_sref ON TblWznmMOp (sref);

CREATE TABLE TblWznmMOppack(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	refWznmMSquawk BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(192),
	Shrdat SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWznmMOppack OWNER TO epsi;
CREATE INDEX TblWznmMOppack_ixVBasetype ON TblWznmMOppack (ixVBasetype);
CREATE INDEX TblWznmMOppack_refWznmMVersion ON TblWznmMOppack (refWznmMVersion);
CREATE INDEX TblWznmMOppack_refWznmMSquawk ON TblWznmMOppack (refWznmMSquawk);
CREATE INDEX TblWznmMOppack_sref ON TblWznmMOppack (sref);

CREATE TABLE TblWznmMPanel(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	carRefWznmMCard BIGINT,
	carNum INT,
	refIxVTbl INT,
	refUref BIGINT,
	refWznmMJob BIGINT,
	sref VARCHAR(50),
	Detach SMALLINT,
	Avail VARCHAR(1024),
	Comment TEXT
);
ALTER TABLE TblWznmMPanel OWNER TO epsi;
CREATE INDEX TblWznmMPanel_ixVBasetype ON TblWznmMPanel (ixVBasetype);
CREATE INDEX TblWznmMPanel_carRefWznmMCard ON TblWznmMPanel (carRefWznmMCard);
CREATE INDEX TblWznmMPanel_carNum ON TblWznmMPanel (carNum);
CREATE INDEX TblWznmMPanel_refIxVTbl ON TblWznmMPanel (refIxVTbl);
CREATE INDEX TblWznmMPanel_refUref ON TblWznmMPanel (refUref);
CREATE INDEX TblWznmMPanel_refWznmMJob ON TblWznmMPanel (refWznmMJob);
CREATE INDEX TblWznmMPanel_sref ON TblWznmMPanel (sref);

CREATE TABLE TblWznmMPerson(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	ixWDerivate INT,
	ixVSex INT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	refJLastname BIGINT,
	Lastname VARCHAR(50),
	telRefADetail BIGINT,
	telVal VARCHAR(192),
	emlRefADetail BIGINT,
	emlVal VARCHAR(192),
	Salutation VARCHAR(100)
);
ALTER TABLE TblWznmMPerson OWNER TO epsi;
CREATE INDEX TblWznmMPerson_grp ON TblWznmMPerson (grp);
CREATE INDEX TblWznmMPerson_own ON TblWznmMPerson (own);
CREATE INDEX TblWznmMPerson_ixWDerivate ON TblWznmMPerson (ixWDerivate);
CREATE INDEX TblWznmMPerson_Lastname ON TblWznmMPerson (Lastname);

CREATE TABLE TblWznmMPreset(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMVersion BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	ixVScope INT,
	sref VARCHAR(50),
	ixWznmWArgtype INT,
	refJTitle BIGINT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmMPreset OWNER TO epsi;
CREATE INDEX TblWznmMPreset_refWznmMVersion ON TblWznmMPreset (refWznmMVersion);
CREATE INDEX TblWznmMPreset_refIxVTbl ON TblWznmMPreset (refIxVTbl);
CREATE INDEX TblWznmMPreset_refUref ON TblWznmMPreset (refUref);
CREATE INDEX TblWznmMPreset_ixVScope ON TblWznmMPreset (ixVScope);
CREATE INDEX TblWznmMPreset_sref ON TblWznmMPreset (sref);
CREATE INDEX TblWznmMPreset_ixWznmWArgtype ON TblWznmMPreset (ixWznmWArgtype);

CREATE TABLE TblWznmMProject(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refWznmMVersion BIGINT,
	Short VARCHAR(5),
	Title VARCHAR(50),
	Giturl VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWznmMProject OWNER TO epsi;
CREATE INDEX TblWznmMProject_grp ON TblWznmMProject (grp);
CREATE INDEX TblWznmMProject_own ON TblWznmMProject (own);
CREATE INDEX TblWznmMProject_refWznmMVersion ON TblWznmMProject (refWznmMVersion);
CREATE INDEX TblWznmMProject_Short ON TblWznmMProject (Short);
CREATE INDEX TblWznmMProject_Title ON TblWznmMProject (Title);

CREATE TABLE TblWznmMQuery(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	supRefWznmMQuery BIGINT,
	supIxVSubrole INT,
	refRTable BIGINT,
	refWznmMTable BIGINT,
	qtbRefWznmMTable BIGINT,
	refWznmMJob BIGINT,
	sref VARCHAR(50),
	Limofs SMALLINT,
	inoRefAOrder BIGINT,
	inoSrefsWznmMTablecol VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWznmMQuery OWNER TO epsi;
CREATE INDEX TblWznmMQuery_ixVBasetype ON TblWznmMQuery (ixVBasetype);
CREATE INDEX TblWznmMQuery_refWznmMVersion ON TblWznmMQuery (refWznmMVersion);
CREATE INDEX TblWznmMQuery_supRefWznmMQuery ON TblWznmMQuery (supRefWznmMQuery);
CREATE INDEX TblWznmMQuery_supIxVSubrole ON TblWznmMQuery (supIxVSubrole);
CREATE INDEX TblWznmMQuery_refWznmMTable ON TblWznmMQuery (refWznmMTable);
CREATE INDEX TblWznmMQuery_qtbRefWznmMTable ON TblWznmMQuery (qtbRefWznmMTable);
CREATE INDEX TblWznmMQuery_refWznmMJob ON TblWznmMQuery (refWznmMJob);
CREATE INDEX TblWznmMQuery_sref ON TblWznmMQuery (sref);

CREATE TABLE TblWznmMQuerycol(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	ixWOccurrence INT,
	qryRefWznmMQuery BIGINT,
	qryNum INT,
	refWznmMTablecol BIGINT,
	sref VARCHAR(50),
	Short VARCHAR(10),
	refWznmMStub BIGINT
);
ALTER TABLE TblWznmMQuerycol OWNER TO epsi;
CREATE INDEX TblWznmMQuerycol_ixVBasetype ON TblWznmMQuerycol (ixVBasetype);
CREATE INDEX TblWznmMQuerycol_ixWOccurrence ON TblWznmMQuerycol (ixWOccurrence);
CREATE INDEX TblWznmMQuerycol_qryRefWznmMQuery ON TblWznmMQuerycol (qryRefWznmMQuery);
CREATE INDEX TblWznmMQuerycol_qryNum ON TblWznmMQuerycol (qryNum);
CREATE INDEX TblWznmMQuerycol_refWznmMTablecol ON TblWznmMQuerycol (refWznmMTablecol);
CREATE INDEX TblWznmMQuerycol_sref ON TblWznmMQuerycol (sref);

CREATE TABLE TblWznmMQuerymod(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	qryRefWznmMQuery BIGINT,
	qryNum INT,
	refWznmMPreset BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	Avail VARCHAR(1024)
);
ALTER TABLE TblWznmMQuerymod OWNER TO epsi;
CREATE INDEX TblWznmMQuerymod_ixVBasetype ON TblWznmMQuerymod (ixVBasetype);
CREATE INDEX TblWznmMQuerymod_qryRefWznmMQuery ON TblWznmMQuerymod (qryRefWznmMQuery);
CREATE INDEX TblWznmMQuerymod_qryNum ON TblWznmMQuerymod (qryNum);
CREATE INDEX TblWznmMQuerymod_refWznmMPreset ON TblWznmMQuerymod (refWznmMPreset);
CREATE INDEX TblWznmMQuerymod_refIxVTbl ON TblWznmMQuerymod (refIxVTbl);
CREATE INDEX TblWznmMQuerymod_refUref ON TblWznmMQuerymod (refUref);

CREATE TABLE TblWznmMRelation(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmCRelation BIGINT,
	refWznmMVersion BIGINT,
	supRefWznmMRelation BIGINT,
	supIxVSubrole INT,
	frRefWznmMTable BIGINT,
	frsRefWznmMSubset BIGINT,
	toRefWznmMTable BIGINT,
	tosRefWznmMSubset BIGINT,
	refWznmMTable BIGINT,
	Prefix VARCHAR(10),
	srefsKOption VARCHAR(192)
);
ALTER TABLE TblWznmMRelation OWNER TO epsi;
CREATE INDEX TblWznmMRelation_ixVBasetype ON TblWznmMRelation (ixVBasetype);
CREATE INDEX TblWznmMRelation_refWznmCRelation ON TblWznmMRelation (refWznmCRelation);
CREATE INDEX TblWznmMRelation_refWznmMVersion ON TblWznmMRelation (refWznmMVersion);
CREATE INDEX TblWznmMRelation_supRefWznmMRelation ON TblWznmMRelation (supRefWznmMRelation);
CREATE INDEX TblWznmMRelation_supIxVSubrole ON TblWznmMRelation (supIxVSubrole);
CREATE INDEX TblWznmMRelation_frRefWznmMTable ON TblWznmMRelation (frRefWznmMTable);
CREATE INDEX TblWznmMRelation_frsRefWznmMSubset ON TblWznmMRelation (frsRefWznmMSubset);
CREATE INDEX TblWznmMRelation_toRefWznmMTable ON TblWznmMRelation (toRefWznmMTable);
CREATE INDEX TblWznmMRelation_tosRefWznmMSubset ON TblWznmMRelation (tosRefWznmMSubset);
CREATE INDEX TblWznmMRelation_refWznmMTable ON TblWznmMRelation (refWznmMTable);

CREATE TABLE TblWznmMRelease(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMComponent BIGINT,
	refWznmMMachine BIGINT,
	sref VARCHAR(50),
	srefsKOption VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWznmMRelease OWNER TO epsi;
CREATE INDEX TblWznmMRelease_refWznmMComponent ON TblWznmMRelease (refWznmMComponent);
CREATE INDEX TblWznmMRelease_refWznmMMachine ON TblWznmMRelease (refWznmMMachine);
CREATE INDEX TblWznmMRelease_sref ON TblWznmMRelease (sref);

CREATE TABLE TblWznmMRtblock(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMRtjob BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	sref VARCHAR(50),
	srcSrefsWznmAMBlockItem VARCHAR(192)
);
ALTER TABLE TblWznmMRtblock OWNER TO epsi;
CREATE INDEX TblWznmMRtblock_refWznmMRtjob ON TblWznmMRtblock (refWznmMRtjob);
CREATE INDEX TblWznmMRtblock_refIxVTbl ON TblWznmMRtblock (refIxVTbl);
CREATE INDEX TblWznmMRtblock_refUref ON TblWznmMRtblock (refUref);
CREATE INDEX TblWznmMRtblock_sref ON TblWznmMRtblock (sref);

CREATE TABLE TblWznmMRtdpch(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMRtjob BIGINT,
	refWznmMBlock BIGINT,
	sref VARCHAR(50),
	Merge SMALLINT
);
ALTER TABLE TblWznmMRtdpch OWNER TO epsi;
CREATE INDEX TblWznmMRtdpch_refWznmMRtjob ON TblWznmMRtdpch (refWznmMRtjob);
CREATE INDEX TblWznmMRtdpch_refWznmMBlock ON TblWznmMRtdpch (refWznmMBlock);
CREATE INDEX TblWznmMRtdpch_sref ON TblWznmMRtdpch (sref);

CREATE TABLE TblWznmMRtjob(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMApp BIGINT,
	supRefWznmMRtjob BIGINT,
	supLvl SMALLINT,
	refWznmMJob BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWznmMRtjob OWNER TO epsi;
CREATE INDEX TblWznmMRtjob_refWznmMApp ON TblWznmMRtjob (refWznmMApp);
CREATE INDEX TblWznmMRtjob_supRefWznmMRtjob ON TblWznmMRtjob (supRefWznmMRtjob);
CREATE INDEX TblWznmMRtjob_supLvl ON TblWznmMRtjob (supLvl);
CREATE INDEX TblWznmMRtjob_refWznmMJob ON TblWznmMRtjob (refWznmMJob);
CREATE INDEX TblWznmMRtjob_sref ON TblWznmMRtjob (sref);

CREATE TABLE TblWznmMSensitivity(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmMJob BIGINT,
	refWznmMStage BIGINT,
	refWznmMCall BIGINT,
	ixVJactype INT,
	ixVJobmask INT,
	Jobshort VARCHAR(30),
	Argpatt VARCHAR(192),
	refWznmMControl BIGINT,
	Srefmask VARCHAR(192),
	ixVAction INT,
	csgRefWznmMStage BIGINT,
	Custcode SMALLINT
);
ALTER TABLE TblWznmMSensitivity OWNER TO epsi;
CREATE INDEX TblWznmMSensitivity_ixVBasetype ON TblWznmMSensitivity (ixVBasetype);
CREATE INDEX TblWznmMSensitivity_refWznmMJob ON TblWznmMSensitivity (refWznmMJob);
CREATE INDEX TblWznmMSensitivity_refWznmMStage ON TblWznmMSensitivity (refWznmMStage);
CREATE INDEX TblWznmMSensitivity_refWznmMCall ON TblWznmMSensitivity (refWznmMCall);

CREATE TABLE TblWznmMSequence(
	ref BIGSERIAL PRIMARY KEY,
	appRefWznmMApp BIGINT,
	appNum INT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWznmMSequence OWNER TO epsi;
CREATE INDEX TblWznmMSequence_appRefWznmMApp ON TblWznmMSequence (appRefWznmMApp);
CREATE INDEX TblWznmMSequence_appNum ON TblWznmMSequence (appNum);
CREATE INDEX TblWznmMSequence_sref ON TblWznmMSequence (sref);

CREATE TABLE TblWznmMSession(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMUser BIGINT,
	start INT,
	stop INT,
	Ip VARCHAR(30)
);
ALTER TABLE TblWznmMSession OWNER TO epsi;
CREATE INDEX TblWznmMSession_refWznmMUser ON TblWznmMSession (refWznmMUser);
CREATE INDEX TblWznmMSession_start ON TblWznmMSession (start);

CREATE TABLE TblWznmMSquawk(
	ref BIGSERIAL PRIMARY KEY,
	refIxVTbl INT,
	refUref BIGINT,
	refJTitle BIGINT,
	Title VARCHAR(192),
	Example VARCHAR(192)
);
ALTER TABLE TblWznmMSquawk OWNER TO epsi;
CREATE INDEX TblWznmMSquawk_refIxVTbl ON TblWznmMSquawk (refIxVTbl);
CREATE INDEX TblWznmMSquawk_refUref ON TblWznmMSquawk (refUref);

CREATE TABLE TblWznmMStage(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	jobRefWznmMJob BIGINT,
	jobNum INT,
	refWznmMSquawk BIGINT,
	sref VARCHAR(50),
	Monitvl INT,
	snxRefWznmMStage BIGINT,
	fnxRefWznmMStage BIGINT,
	enxRefWznmMStage BIGINT,
	Comment TEXT
);
ALTER TABLE TblWznmMStage OWNER TO epsi;
CREATE INDEX TblWznmMStage_ixVBasetype ON TblWznmMStage (ixVBasetype);
CREATE INDEX TblWznmMStage_jobRefWznmMJob ON TblWznmMStage (jobRefWznmMJob);
CREATE INDEX TblWznmMStage_jobNum ON TblWznmMStage (jobNum);
CREATE INDEX TblWznmMStage_refWznmMSquawk ON TblWznmMStage (refWznmMSquawk);
CREATE INDEX TblWznmMStage_sref ON TblWznmMStage (sref);

CREATE TABLE TblWznmMState(
	ref BIGSERIAL PRIMARY KEY,
	seqRefWznmMSequence BIGINT,
	seqNum INT,
	sref VARCHAR(50),
	eacIxVAction INT,
	erjRefWznmMRtjob BIGINT,
	eveRefWznmMVector BIGINT,
	eviRefWznmMVectoritem BIGINT,
	esnRefWznmMState BIGINT,
	lacIxVAction INT,
	Custstep SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWznmMState OWNER TO epsi;
CREATE INDEX TblWznmMState_seqRefWznmMSequence ON TblWznmMState (seqRefWznmMSequence);
CREATE INDEX TblWznmMState_seqNum ON TblWznmMState (seqNum);
CREATE INDEX TblWznmMState_sref ON TblWznmMState (sref);

CREATE TABLE TblWznmMStub(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmMTable BIGINT,
	refWznmMSubset BIGINT,
	sref VARCHAR(50),
	Hierarch SMALLINT,
	refWznmMTablecol BIGINT,
	Localized SMALLINT,
	Example VARCHAR(192)
);
ALTER TABLE TblWznmMStub OWNER TO epsi;
CREATE INDEX TblWznmMStub_ixVBasetype ON TblWznmMStub (ixVBasetype);
CREATE INDEX TblWznmMStub_refWznmMTable ON TblWznmMStub (refWznmMTable);
CREATE INDEX TblWznmMStub_refWznmMSubset ON TblWznmMStub (refWznmMSubset);
CREATE INDEX TblWznmMStub_sref ON TblWznmMStub (sref);

CREATE TABLE TblWznmMSubset(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMTable BIGINT,
	refWznmMPreset BIGINT,
	refWznmMCard BIGINT,
	sref VARCHAR(50),
	Short VARCHAR(10),
	Cond VARCHAR(1024),
	Comment TEXT
);
ALTER TABLE TblWznmMSubset OWNER TO epsi;
CREATE INDEX TblWznmMSubset_refWznmMTable ON TblWznmMSubset (refWznmMTable);
CREATE INDEX TblWznmMSubset_refWznmMPreset ON TblWznmMSubset (refWznmMPreset);
CREATE INDEX TblWznmMSubset_refWznmMCard ON TblWznmMSubset (refWznmMCard);
CREATE INDEX TblWznmMSubset_sref ON TblWznmMSubset (sref);

CREATE TABLE TblWznmMTable(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	refWznmMPreset BIGINT,
	refWznmMCard BIGINT,
	sref VARCHAR(50),
	Short VARCHAR(10),
	unqSrefsWznmMTablecol VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWznmMTable OWNER TO epsi;
CREATE INDEX TblWznmMTable_ixVBasetype ON TblWznmMTable (ixVBasetype);
CREATE INDEX TblWznmMTable_refWznmMVersion ON TblWznmMTable (refWznmMVersion);
CREATE INDEX TblWznmMTable_refIxVTbl ON TblWznmMTable (refIxVTbl);
CREATE INDEX TblWznmMTable_refUref ON TblWznmMTable (refUref);
CREATE INDEX TblWznmMTable_refWznmMPreset ON TblWznmMTable (refWznmMPreset);
CREATE INDEX TblWznmMTable_refWznmMCard ON TblWznmMTable (refWznmMCard);
CREATE INDEX TblWznmMTable_sref ON TblWznmMTable (sref);

CREATE TABLE TblWznmMTablecol(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	tblRefWznmMTable BIGINT,
	tblNum INT,
	refWznmMSubset BIGINT,
	refWznmMRelation BIGINT,
	fctIxVTbl INT,
	fctUref BIGINT,
	sref VARCHAR(50),
	Short VARCHAR(10),
	ixVSubtype INT,
	ixVAxisfct INT,
	srefsKOption VARCHAR(192),
	Principal SMALLINT,
	Eponymous SMALLINT
);
ALTER TABLE TblWznmMTablecol OWNER TO epsi;
CREATE INDEX TblWznmMTablecol_ixVBasetype ON TblWznmMTablecol (ixVBasetype);
CREATE INDEX TblWznmMTablecol_tblRefWznmMTable ON TblWznmMTablecol (tblRefWznmMTable);
CREATE INDEX TblWznmMTablecol_tblNum ON TblWznmMTablecol (tblNum);
CREATE INDEX TblWznmMTablecol_refWznmMSubset ON TblWznmMTablecol (refWznmMSubset);
CREATE INDEX TblWznmMTablecol_refWznmMRelation ON TblWznmMTablecol (refWznmMRelation);
CREATE INDEX TblWznmMTablecol_fctIxVTbl ON TblWznmMTablecol (fctIxVTbl);
CREATE INDEX TblWznmMTablecol_fctUref ON TblWznmMTablecol (fctUref);
CREATE INDEX TblWznmMTablecol_sref ON TblWznmMTablecol (sref);

CREATE TABLE TblWznmMTag(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMCapability BIGINT,
	sref VARCHAR(50),
	osrefWznmKTaggrp VARCHAR(50),
	refJTitle BIGINT,
	Title VARCHAR(192)
);
ALTER TABLE TblWznmMTag OWNER TO epsi;
CREATE INDEX TblWznmMTag_refWznmMCapability ON TblWznmMTag (refWznmMCapability);
CREATE INDEX TblWznmMTag_sref ON TblWznmMTag (sref);
CREATE INDEX TblWznmMTag_osrefWznmKTaggrp ON TblWznmMTag (osrefWznmKTaggrp);

CREATE TABLE TblWznmMUser(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refRUsergroup BIGINT,
	refWznmMUsergroup BIGINT,
	refWznmMPerson BIGINT,
	sref VARCHAR(50),
	refJState BIGINT,
	ixVState INT,
	ixWznmVLocale INT,
	ixWznmVUserlevel INT,
	Password VARCHAR(30),
	Fullkey TEXT,
	Comment TEXT
);
ALTER TABLE TblWznmMUser OWNER TO epsi;
CREATE INDEX TblWznmMUser_grp ON TblWznmMUser (grp);
CREATE INDEX TblWznmMUser_own ON TblWznmMUser (own);
CREATE INDEX TblWznmMUser_refWznmMUsergroup ON TblWznmMUser (refWznmMUsergroup);
CREATE INDEX TblWznmMUser_refWznmMPerson ON TblWznmMUser (refWznmMPerson);
CREATE INDEX TblWznmMUser_sref ON TblWznmMUser (sref);

CREATE TABLE TblWznmMUsergroup(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWznmMUsergroup OWNER TO epsi;
CREATE INDEX TblWznmMUsergroup_grp ON TblWznmMUsergroup (grp);
CREATE INDEX TblWznmMUsergroup_own ON TblWznmMUsergroup (own);
CREATE INDEX TblWznmMUsergroup_sref ON TblWznmMUsergroup (sref);

CREATE TABLE TblWznmMVector(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	hkIxVTbl INT,
	hkUref BIGINT,
	refWznmMPreset BIGINT,
	sref VARCHAR(50),
	osrefWznmKTaggrp VARCHAR(50),
	srefsKOption VARCHAR(192)
);
ALTER TABLE TblWznmMVector OWNER TO epsi;
CREATE INDEX TblWznmMVector_ixVBasetype ON TblWznmMVector (ixVBasetype);
CREATE INDEX TblWznmMVector_refWznmMVersion ON TblWznmMVector (refWznmMVersion);
CREATE INDEX TblWznmMVector_hkIxVTbl ON TblWznmMVector (hkIxVTbl);
CREATE INDEX TblWznmMVector_hkUref ON TblWznmMVector (hkUref);
CREATE INDEX TblWznmMVector_refWznmMPreset ON TblWznmMVector (refWznmMPreset);
CREATE INDEX TblWznmMVector_sref ON TblWznmMVector (sref);
CREATE INDEX TblWznmMVector_osrefWznmKTaggrp ON TblWznmMVector (osrefWznmKTaggrp);

CREATE TABLE TblWznmMVectoritem(
	ref BIGSERIAL PRIMARY KEY,
	vecRefWznmMVector BIGINT,
	vecNum INT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT,
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWznmMVectoritem OWNER TO epsi;
CREATE INDEX TblWznmMVectoritem_vecRefWznmMVector ON TblWznmMVectoritem (vecRefWznmMVector);
CREATE INDEX TblWznmMVectoritem_vecNum ON TblWznmMVectoritem (vecNum);
CREATE INDEX TblWznmMVectoritem_sref ON TblWznmMVectoritem (sref);

CREATE TABLE TblWznmMVersion(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	prjRefWznmMProject BIGINT,
	prjNum INT,
	bvrRefWznmMVersion BIGINT,
	refRLocale BIGINT,
	refWznmMLocale BIGINT,
	Major SMALLINT,
	Minor SMALLINT,
	Sub SMALLINT,
	refJState BIGINT,
	ixVState INT,
	ixWDbmstype INT,
	ixWOption INT,
	refJ BIGINT,
	About1 TEXT,
	About2 TEXT,
	About3 TEXT,
	Comment TEXT
);
ALTER TABLE TblWznmMVersion OWNER TO epsi;
CREATE INDEX TblWznmMVersion_grp ON TblWznmMVersion (grp);
CREATE INDEX TblWznmMVersion_own ON TblWznmMVersion (own);
CREATE INDEX TblWznmMVersion_prjRefWznmMProject ON TblWznmMVersion (prjRefWznmMProject);
CREATE INDEX TblWznmMVersion_prjNum ON TblWznmMVersion (prjNum);
CREATE INDEX TblWznmMVersion_bvrRefWznmMVersion ON TblWznmMVersion (bvrRefWznmMVersion);
CREATE INDEX TblWznmMVersion_refWznmMLocale ON TblWznmMVersion (refWznmMLocale);
CREATE INDEX TblWznmMVersion_ixVState ON TblWznmMVersion (ixVState);

CREATE TABLE TblWznmRMCallMStub(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMCall BIGINT,
	refWznmMStub BIGINT
);
ALTER TABLE TblWznmRMCallMStub OWNER TO epsi;
CREATE INDEX TblWznmRMCallMStub_refWznmMCall ON TblWznmRMCallMStub (refWznmMCall);
CREATE INDEX TblWznmRMCallMStub_refWznmMStub ON TblWznmRMCallMStub (refWznmMStub);

CREATE TABLE TblWznmRMCapabilityUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMCapability BIGINT,
	unvIxWznmVMaintable INT,
	unvUref BIGINT,
	srefKKey VARCHAR(50)
);
ALTER TABLE TblWznmRMCapabilityUniversal OWNER TO epsi;
CREATE INDEX TblWznmRMCapabilityUniversal_refWznmMCapability ON TblWznmRMCapabilityUniversal (refWznmMCapability);
CREATE INDEX TblWznmRMCapabilityUniversal_unvIxWznmVMaintable ON TblWznmRMCapabilityUniversal (unvIxWznmVMaintable);
CREATE INDEX TblWznmRMCapabilityUniversal_unvUref ON TblWznmRMCapabilityUniversal (unvUref);

CREATE TABLE TblWznmRMComponentMLibrary(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMComponent BIGINT,
	refWznmMLibrary BIGINT
);
ALTER TABLE TblWznmRMComponentMLibrary OWNER TO epsi;
CREATE INDEX TblWznmRMComponentMLibrary_refWznmMComponent ON TblWznmRMComponentMLibrary (refWznmMComponent);
CREATE INDEX TblWznmRMComponentMLibrary_refWznmMLibrary ON TblWznmRMComponentMLibrary (refWznmMLibrary);

CREATE TABLE TblWznmRMComponentMOppack(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMComponent BIGINT,
	refWznmMOppack BIGINT
);
ALTER TABLE TblWznmRMComponentMOppack OWNER TO epsi;
CREATE INDEX TblWznmRMComponentMOppack_refWznmMComponent ON TblWznmRMComponentMOppack (refWznmMComponent);
CREATE INDEX TblWznmRMComponentMOppack_refWznmMOppack ON TblWznmRMComponentMOppack (refWznmMOppack);

CREATE TABLE TblWznmRMDialogMQuery(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMDialog BIGINT,
	refWznmMQuery BIGINT
);
ALTER TABLE TblWznmRMDialogMQuery OWNER TO epsi;
CREATE INDEX TblWznmRMDialogMQuery_refWznmMDialog ON TblWznmRMDialogMQuery (refWznmMDialog);
CREATE INDEX TblWznmRMDialogMQuery_refWznmMQuery ON TblWznmRMDialogMQuery (refWznmMQuery);

CREATE TABLE TblWznmRMJobMJob(
	ref BIGSERIAL PRIMARY KEY,
	supRefWznmMJob BIGINT,
	subRefWznmMJob BIGINT,
	Short VARCHAR(30),
	Multi SMALLINT,
	ixVConstract INT
);
ALTER TABLE TblWznmRMJobMJob OWNER TO epsi;
CREATE INDEX TblWznmRMJobMJob_supRefWznmMJob ON TblWznmRMJobMJob (supRefWznmMJob);
CREATE INDEX TblWznmRMJobMJob_subRefWznmMJob ON TblWznmRMJobMJob (subRefWznmMJob);

CREATE TABLE TblWznmRMJobMOp(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMJob BIGINT,
	refWznmMOp BIGINT
);
ALTER TABLE TblWznmRMJobMOp OWNER TO epsi;
CREATE INDEX TblWznmRMJobMOp_refWznmMJob ON TblWznmRMJobMOp (refWznmMJob);
CREATE INDEX TblWznmRMJobMOp_refWznmMOp ON TblWznmRMJobMOp (refWznmMOp);

CREATE TABLE TblWznmRMJobMOppack(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMJob BIGINT,
	refWznmMOppack BIGINT
);
ALTER TABLE TblWznmRMJobMOppack OWNER TO epsi;
CREATE INDEX TblWznmRMJobMOppack_refWznmMJob ON TblWznmRMJobMOppack (refWznmMJob);
CREATE INDEX TblWznmRMJobMOppack_refWznmMOppack ON TblWznmRMJobMOppack (refWznmMOppack);

CREATE TABLE TblWznmRMLibraryMOppack(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMLibrary BIGINT,
	refWznmMOppack BIGINT
);
ALTER TABLE TblWznmRMLibraryMOppack OWNER TO epsi;
CREATE INDEX TblWznmRMLibraryMOppack_refWznmMLibrary ON TblWznmRMLibraryMOppack (refWznmMLibrary);
CREATE INDEX TblWznmRMLibraryMOppack_refWznmMOppack ON TblWznmRMLibraryMOppack (refWznmMOppack);

CREATE TABLE TblWznmRMLocaleMVersion(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMLocale BIGINT,
	refWznmMVersion BIGINT
);
ALTER TABLE TblWznmRMLocaleMVersion OWNER TO epsi;
CREATE INDEX TblWznmRMLocaleMVersion_refWznmMLocale ON TblWznmRMLocaleMVersion (refWznmMLocale);
CREATE INDEX TblWznmRMLocaleMVersion_refWznmMVersion ON TblWznmRMLocaleMVersion (refWznmMVersion);

CREATE TABLE TblWznmRMPanelMQuery(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMPanel BIGINT,
	refWznmMQuery BIGINT
);
ALTER TABLE TblWznmRMPanelMQuery OWNER TO epsi;
CREATE INDEX TblWznmRMPanelMQuery_refWznmMPanel ON TblWznmRMPanelMQuery (refWznmMPanel);
CREATE INDEX TblWznmRMPanelMQuery_refWznmMQuery ON TblWznmRMPanelMQuery (refWznmMQuery);

CREATE TABLE TblWznmRMPersonMProject(
	ref BIGSERIAL PRIMARY KEY,
	x1Startd INT,
	x1Stopd INT,
	refWznmMPerson BIGINT,
	refWznmMProject BIGINT,
	srefKFunction VARCHAR(50)
);
ALTER TABLE TblWznmRMPersonMProject OWNER TO epsi;
CREATE INDEX TblWznmRMPersonMProject_x1Startd ON TblWznmRMPersonMProject (x1Startd);
CREATE INDEX TblWznmRMPersonMProject_x1Stopd ON TblWznmRMPersonMProject (x1Stopd);
CREATE INDEX TblWznmRMPersonMProject_refWznmMPerson ON TblWznmRMPersonMProject (refWznmMPerson);
CREATE INDEX TblWznmRMPersonMProject_refWznmMProject ON TblWznmRMPersonMProject (refWznmMProject);

CREATE TABLE TblWznmRMQueryMTable(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMQuery BIGINT,
	refWznmMTable BIGINT,
	Source SMALLINT,
	Prefix VARCHAR(5)
);
ALTER TABLE TblWznmRMQueryMTable OWNER TO epsi;
CREATE INDEX TblWznmRMQueryMTable_refWznmMQuery ON TblWznmRMQueryMTable (refWznmMQuery);
CREATE INDEX TblWznmRMQueryMTable_refWznmMTable ON TblWznmRMQueryMTable (refWznmMTable);

CREATE TABLE TblWznmRMSquawkMStub(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMSquawk BIGINT,
	refWznmMStub BIGINT
);
ALTER TABLE TblWznmRMSquawkMStub OWNER TO epsi;
CREATE INDEX TblWznmRMSquawkMStub_refWznmMSquawk ON TblWznmRMSquawkMStub (refWznmMSquawk);
CREATE INDEX TblWznmRMSquawkMStub_refWznmMStub ON TblWznmRMSquawkMStub (refWznmMStub);

CREATE TABLE TblWznmRMStubMStub(
	ref BIGSERIAL PRIMARY KEY,
	supRefWznmMStub BIGINT,
	subRefWznmMStub BIGINT
);
ALTER TABLE TblWznmRMStubMStub OWNER TO epsi;
CREATE INDEX TblWznmRMStubMStub_supRefWznmMStub ON TblWznmRMStubMStub (supRefWznmMStub);
CREATE INDEX TblWznmRMStubMStub_subRefWznmMStub ON TblWznmRMStubMStub (subRefWznmMStub);

CREATE TABLE TblWznmRMSubsetMSubset(
	ref BIGSERIAL PRIMARY KEY,
	asbRefWznmMSubset BIGINT,
	bsbRefWznmMSubset BIGINT,
	ixVReltype INT
);
ALTER TABLE TblWznmRMSubsetMSubset OWNER TO epsi;
CREATE INDEX TblWznmRMSubsetMSubset_asbRefWznmMSubset ON TblWznmRMSubsetMSubset (asbRefWznmMSubset);
CREATE INDEX TblWznmRMSubsetMSubset_bsbRefWznmMSubset ON TblWznmRMSubsetMSubset (bsbRefWznmMSubset);

CREATE TABLE TblWznmRMTableMVector(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMTable BIGINT,
	refWznmMSubset BIGINT,
	refWznmMVector BIGINT
);
ALTER TABLE TblWznmRMTableMVector OWNER TO epsi;
CREATE INDEX TblWznmRMTableMVector_refWznmMTable ON TblWznmRMTableMVector (refWznmMTable);
CREATE INDEX TblWznmRMTableMVector_refWznmMSubset ON TblWznmRMTableMVector (refWznmMSubset);
CREATE INDEX TblWznmRMTableMVector_refWznmMVector ON TblWznmRMTableMVector (refWznmMVector);

CREATE TABLE TblWznmRMUsergroupUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMUsergroup BIGINT,
	unvIxWznmVMaintable INT,
	unvUref BIGINT,
	ixWznmVRecaccess INT
);
ALTER TABLE TblWznmRMUsergroupUniversal OWNER TO epsi;
CREATE INDEX TblWznmRMUsergroupUniversal_refWznmMUsergroup ON TblWznmRMUsergroupUniversal (refWznmMUsergroup);
CREATE INDEX TblWznmRMUsergroupUniversal_unvIxWznmVMaintable ON TblWznmRMUsergroupUniversal (unvIxWznmVMaintable);
CREATE INDEX TblWznmRMUsergroupUniversal_unvUref ON TblWznmRMUsergroupUniversal (unvUref);

CREATE TABLE TblWznmRMUserMUsergroup(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMUser BIGINT,
	refWznmMUsergroup BIGINT,
	ixWznmVUserlevel INT
);
ALTER TABLE TblWznmRMUserMUsergroup OWNER TO epsi;
CREATE INDEX TblWznmRMUserMUsergroup_refWznmMUser ON TblWznmRMUserMUsergroup (refWznmMUser);
CREATE INDEX TblWznmRMUserMUsergroup_refWznmMUsergroup ON TblWznmRMUserMUsergroup (refWznmMUsergroup);

CREATE TABLE TblWznmTMQuerymodMQuery(
	ref BIGSERIAL PRIMARY KEY,
	refWznmMQuerymod BIGINT,
	refR BIGINT
);
ALTER TABLE TblWznmTMQuerymodMQuery OWNER TO epsi;
CREATE INDEX TblWznmTMQuerymodMQuery_refWznmMQuerymod ON TblWznmTMQuerymodMQuery (refWznmMQuerymod);
CREATE INDEX TblWznmTMQuerymodMQuery_refR ON TblWznmTMQuerymodMQuery (refR);

CREATE TABLE TblWznmQApp1NRtjob(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQApp1NRtjob OWNER TO epsi;
CREATE INDEX TblWznmQApp1NRtjob_jref ON TblWznmQApp1NRtjob (jref);
CREATE INDEX TblWznmQApp1NRtjob_jnum ON TblWznmQApp1NRtjob (jnum);

CREATE TABLE TblWznmQAppApp1NSequence(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	appNum INT
);
ALTER TABLE TblWznmQAppApp1NSequence OWNER TO epsi;
CREATE INDEX TblWznmQAppApp1NSequence_jref ON TblWznmQAppApp1NSequence (jref);
CREATE INDEX TblWznmQAppApp1NSequence_jnum ON TblWznmQAppApp1NSequence (jnum);

CREATE TABLE TblWznmQAppList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	Short VARCHAR(10),
	Title VARCHAR(50),
	ixVTarget INT,
	verRefWznmMVersion BIGINT
);
ALTER TABLE TblWznmQAppList OWNER TO epsi;
CREATE INDEX TblWznmQAppList_jref ON TblWznmQAppList (jref);
CREATE INDEX TblWznmQAppList_jnum ON TblWznmQAppList (jnum);

CREATE TABLE TblWznmQAppRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQAppRef1NFile OWNER TO epsi;
CREATE INDEX TblWznmQAppRef1NFile_jref ON TblWznmQAppRef1NFile (jref);
CREATE INDEX TblWznmQAppRef1NFile_jnum ON TblWznmQAppRef1NFile (jnum);

CREATE TABLE TblWznmQBlk1NRtdpch(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQBlk1NRtdpch OWNER TO epsi;
CREATE INDEX TblWznmQBlk1NRtdpch_jref ON TblWznmQBlk1NRtdpch (jref);
CREATE INDEX TblWznmQBlk1NRtdpch_jnum ON TblWznmQBlk1NRtdpch (jnum);

CREATE TABLE TblWznmQBlkAItem(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	blkNum INT,
	ixVBasetype INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMControl BIGINT,
	refWznmMVector BIGINT,
	refWznmMFeed BIGINT,
	refWznmMTable BIGINT,
	refWznmMBlock BIGINT,
	refJ BIGINT,
	Defval VARCHAR(192),
	refWznmMVectoritem BIGINT,
	Comment TEXT
);
ALTER TABLE TblWznmQBlkAItem OWNER TO epsi;
CREATE INDEX TblWznmQBlkAItem_jref ON TblWznmQBlkAItem (jref);
CREATE INDEX TblWznmQBlkAItem_jnum ON TblWznmQBlkAItem (jnum);

CREATE TABLE TblWznmQBlkList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	refIxVTbl INT,
	refUref BIGINT
);
ALTER TABLE TblWznmQBlkList OWNER TO epsi;
CREATE INDEX TblWznmQBlkList_jref ON TblWznmQBlkList (jref);
CREATE INDEX TblWznmQBlkList_jnum ON TblWznmQBlkList (jnum);

CREATE TABLE TblWznmQBlkRef1NRtblock(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQBlkRef1NRtblock OWNER TO epsi;
CREATE INDEX TblWznmQBlkRef1NRtblock_jref ON TblWznmQBlkRef1NRtblock (jref);
CREATE INDEX TblWznmQBlkRef1NRtblock_jnum ON TblWznmQBlkRef1NRtblock (jnum);

CREATE TABLE TblWznmQCal1NSensitivity(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQCal1NSensitivity OWNER TO epsi;
CREATE INDEX TblWznmQCal1NSensitivity_jref ON TblWznmQCal1NSensitivity (jref);
CREATE INDEX TblWznmQCal1NSensitivity_jnum ON TblWznmQCal1NSensitivity (jnum);

CREATE TABLE TblWznmQCalList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	invIxWznmWArgtype INT,
	retIxWznmWArgtype INT
);
ALTER TABLE TblWznmQCalList OWNER TO epsi;
CREATE INDEX TblWznmQCalList_jref ON TblWznmQCalList (jref);
CREATE INDEX TblWznmQCalList_jnum ON TblWznmQCalList (jnum);

CREATE TABLE TblWznmQCalMNStub(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQCalMNStub OWNER TO epsi;
CREATE INDEX TblWznmQCalMNStub_jref ON TblWznmQCalMNStub (jref);
CREATE INDEX TblWznmQCalMNStub_jnum ON TblWznmQCalMNStub (jnum);

CREATE TABLE TblWznmQCapAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	cpbNum INT,
	x1SrefKKey VARCHAR(50),
	Val TEXT
);
ALTER TABLE TblWznmQCapAPar OWNER TO epsi;
CREATE INDEX TblWznmQCapAPar_jref ON TblWznmQCapAPar (jref);
CREATE INDEX TblWznmQCapAPar_jnum ON TblWznmQCapAPar (jnum);

CREATE TABLE TblWznmQCapList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	refWznmMVersion BIGINT,
	tplRefWznmMCapability BIGINT,
	ixWArtefact INT
);
ALTER TABLE TblWznmQCapList OWNER TO epsi;
CREATE INDEX TblWznmQCapList_jref ON TblWznmQCapList (jref);
CREATE INDEX TblWznmQCapList_jnum ON TblWznmQCapList (jnum);

CREATE TABLE TblWznmQCar1NDialog(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQCar1NDialog OWNER TO epsi;
CREATE INDEX TblWznmQCar1NDialog_jref ON TblWznmQCar1NDialog (jref);
CREATE INDEX TblWznmQCar1NDialog_jnum ON TblWznmQCar1NDialog (jnum);

CREATE TABLE TblWznmQCarCar1NPanel(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	carNum INT
);
ALTER TABLE TblWznmQCarCar1NPanel OWNER TO epsi;
CREATE INDEX TblWznmQCarCar1NPanel_jref ON TblWznmQCarCar1NPanel (jref);
CREATE INDEX TblWznmQCarCar1NPanel_jnum ON TblWznmQCarCar1NPanel (jnum);

CREATE TABLE TblWznmQCarHk1NControl(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	hkNum INT
);
ALTER TABLE TblWznmQCarHk1NControl OWNER TO epsi;
CREATE INDEX TblWznmQCarHk1NControl_jref ON TblWznmQCarHk1NControl (jref);
CREATE INDEX TblWznmQCarHk1NControl_jnum ON TblWznmQCarHk1NControl (jnum);

CREATE TABLE TblWznmQCarList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	mdlRefWznmMModule BIGINT,
	refIxVTbl INT,
	refUref BIGINT
);
ALTER TABLE TblWznmQCarList OWNER TO epsi;
CREATE INDEX TblWznmQCarList_jref ON TblWznmQCarList (jref);
CREATE INDEX TblWznmQCarList_jnum ON TblWznmQCarList (jnum);

CREATE TABLE TblWznmQChkList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	refWznmMTable BIGINT,
	refWznmMTablecol BIGINT
);
ALTER TABLE TblWznmQChkList OWNER TO epsi;
CREATE INDEX TblWznmQChkList_jref ON TblWznmQChkList (jref);
CREATE INDEX TblWznmQChkList_jnum ON TblWznmQChkList (jnum);

CREATE TABLE TblWznmQChkRef1NCall(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQChkRef1NCall OWNER TO epsi;
CREATE INDEX TblWznmQChkRef1NCall_jref ON TblWznmQChkRef1NCall (jref);
CREATE INDEX TblWznmQChkRef1NCall_jnum ON TblWznmQChkRef1NCall (jnum);

CREATE TABLE TblWznmQCmp1NRelease(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQCmp1NRelease OWNER TO epsi;
CREATE INDEX TblWznmQCmp1NRelease_jref ON TblWznmQCmp1NRelease (jref);
CREATE INDEX TblWznmQCmp1NRelease_jnum ON TblWznmQCmp1NRelease (jnum);

CREATE TABLE TblWznmQCmpList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(100),
	ixVBasetype INT,
	refWznmMVersion BIGINT
);
ALTER TABLE TblWznmQCmpList OWNER TO epsi;
CREATE INDEX TblWznmQCmpList_jref ON TblWznmQCmpList (jref);
CREATE INDEX TblWznmQCmpList_jnum ON TblWznmQCmpList (jnum);

CREATE TABLE TblWznmQCmpMNLibrary(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQCmpMNLibrary OWNER TO epsi;
CREATE INDEX TblWznmQCmpMNLibrary_jref ON TblWznmQCmpMNLibrary (jref);
CREATE INDEX TblWznmQCmpMNLibrary_jnum ON TblWznmQCmpMNLibrary (jnum);

CREATE TABLE TblWznmQCmpMNOppack(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQCmpMNOppack OWNER TO epsi;
CREATE INDEX TblWznmQCmpMNOppack_jref ON TblWznmQCmpMNOppack (jref);
CREATE INDEX TblWznmQCmpMNOppack_jnum ON TblWznmQCmpMNOppack (jnum);

CREATE TABLE TblWznmQConAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKKey VARCHAR(50),
	x2RefWznmMLocale BIGINT,
	osrefKVal VARCHAR(50)
);
ALTER TABLE TblWznmQConAPar OWNER TO epsi;
CREATE INDEX TblWznmQConAPar_jref ON TblWznmQConAPar (jref);
CREATE INDEX TblWznmQConAPar_jnum ON TblWznmQConAPar (jnum);

CREATE TABLE TblWznmQConFedRef1NRtblock(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQConFedRef1NRtblock OWNER TO epsi;
CREATE INDEX TblWznmQConFedRef1NRtblock_jref ON TblWznmQConFedRef1NRtblock (jref);
CREATE INDEX TblWznmQConFedRef1NRtblock_jnum ON TblWznmQConFedRef1NRtblock (jnum);

CREATE TABLE TblWznmQConList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(192),
	ixVBasetype INT,
	hkIxVTbl INT,
	hkUref BIGINT,
	hkIxVSection INT,
	refIxVTbl INT,
	refUref BIGINT,
	supRefWznmMControl BIGINT,
	ixVSubtype INT
);
ALTER TABLE TblWznmQConList OWNER TO epsi;
CREATE INDEX TblWznmQConList_jref ON TblWznmQConList (jref);
CREATE INDEX TblWznmQConList_jnum ON TblWznmQConList (jnum);

CREATE TABLE TblWznmQConSup1NControl(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	supNum INT
);
ALTER TABLE TblWznmQConSup1NControl OWNER TO epsi;
CREATE INDEX TblWznmQConSup1NControl_jref ON TblWznmQConSup1NControl (jref);
CREATE INDEX TblWznmQConSup1NControl_jnum ON TblWznmQConSup1NControl (jnum);

CREATE TABLE TblWznmQCtp1NTag(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQCtp1NTag OWNER TO epsi;
CREATE INDEX TblWznmQCtp1NTag_jref ON TblWznmQCtp1NTag (jref);
CREATE INDEX TblWznmQCtp1NTag_jnum ON TblWznmQCtp1NTag (jnum);

CREATE TABLE TblWznmQCtpAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	cpbNum INT,
	x1SrefKKey VARCHAR(50),
	Val TEXT
);
ALTER TABLE TblWznmQCtpAPar OWNER TO epsi;
CREATE INDEX TblWznmQCtpAPar_jref ON TblWznmQCtpAPar (jref);
CREATE INDEX TblWznmQCtpAPar_jnum ON TblWznmQCtpAPar (jnum);

CREATE TABLE TblWznmQCtpKKey(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT,
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWznmQCtpKKey OWNER TO epsi;
CREATE INDEX TblWznmQCtpKKey_jref ON TblWznmQCtpKKey (jref);
CREATE INDEX TblWznmQCtpKKey_jnum ON TblWznmQCtpKKey (jnum);

CREATE TABLE TblWznmQCtpKParKey(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT,
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWznmQCtpKParKey OWNER TO epsi;
CREATE INDEX TblWznmQCtpKParKey_jref ON TblWznmQCtpKParKey (jref);
CREATE INDEX TblWznmQCtpKParKey_jnum ON TblWznmQCtpKParKey (jnum);

CREATE TABLE TblWznmQCtpList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	refWznmMVersion BIGINT,
	ixWArtefact INT
);
ALTER TABLE TblWznmQCtpList OWNER TO epsi;
CREATE INDEX TblWznmQCtpList_jref ON TblWznmQCtpList (jref);
CREATE INDEX TblWznmQCtpList_jnum ON TblWznmQCtpList (jnum);

CREATE TABLE TblWznmQCtpTpl1NCapability(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQCtpTpl1NCapability OWNER TO epsi;
CREATE INDEX TblWznmQCtpTpl1NCapability_jref ON TblWznmQCtpTpl1NCapability (jref);
CREATE INDEX TblWznmQCtpTpl1NCapability_jnum ON TblWznmQCtpTpl1NCapability (jnum);

CREATE TABLE TblWznmQDlgHk1NControl(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	hkNum INT
);
ALTER TABLE TblWznmQDlgHk1NControl OWNER TO epsi;
CREATE INDEX TblWznmQDlgHk1NControl_jref ON TblWznmQDlgHk1NControl (jref);
CREATE INDEX TblWznmQDlgHk1NControl_jnum ON TblWznmQDlgHk1NControl (jnum);

CREATE TABLE TblWznmQDlgList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	refWznmMCard BIGINT,
	refIxVTbl INT,
	refUref BIGINT
);
ALTER TABLE TblWznmQDlgList OWNER TO epsi;
CREATE INDEX TblWznmQDlgList_jref ON TblWznmQDlgList (jref);
CREATE INDEX TblWznmQDlgList_jnum ON TblWznmQDlgList (jnum);

CREATE TABLE TblWznmQDlgMNQuery(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQDlgMNQuery OWNER TO epsi;
CREATE INDEX TblWznmQDlgMNQuery_jref ON TblWznmQDlgMNQuery (jref);
CREATE INDEX TblWznmQDlgMNQuery_jnum ON TblWznmQDlgMNQuery (jnum);

CREATE TABLE TblWznmQDlgRef1NControl(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQDlgRef1NControl OWNER TO epsi;
CREATE INDEX TblWznmQDlgRef1NControl_jref ON TblWznmQDlgRef1NControl (jref);
CREATE INDEX TblWznmQDlgRef1NControl_jnum ON TblWznmQDlgRef1NControl (jnum);

CREATE TABLE TblWznmQErrList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(192),
	verRefWznmMVersion BIGINT
);
ALTER TABLE TblWznmQErrList OWNER TO epsi;
CREATE INDEX TblWznmQErrList_jref ON TblWznmQErrList (jref);
CREATE INDEX TblWznmQErrList_jnum ON TblWznmQErrList (jnum);

CREATE TABLE TblWznmQFilList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	Filename VARCHAR(50),
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	srefKMimetype VARCHAR(50),
	Size INT
);
ALTER TABLE TblWznmQFilList OWNER TO epsi;
CREATE INDEX TblWznmQFilList_jref ON TblWznmQFilList (jref);
CREATE INDEX TblWznmQFilList_jnum ON TblWznmQFilList (jnum);

CREATE TABLE TblWznmQIelList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Short VARCHAR(10),
	ixVBasetype INT,
	imeRefWznmMImpexp BIGINT,
	refWznmMTablecol BIGINT,
	ixVConvtype INT
);
ALTER TABLE TblWznmQIelList OWNER TO epsi;
CREATE INDEX TblWznmQIelList_jref ON TblWznmQIelList (jref);
CREATE INDEX TblWznmQIelList_jnum ON TblWznmQIelList (jnum);

CREATE TABLE TblWznmQIex1NImpexp(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQIex1NImpexp OWNER TO epsi;
CREATE INDEX TblWznmQIex1NImpexp_jref ON TblWznmQIex1NImpexp (jref);
CREATE INDEX TblWznmQIex1NImpexp_jnum ON TblWznmQIex1NImpexp (jnum);

CREATE TABLE TblWznmQIexHk1NVector(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQIexHk1NVector OWNER TO epsi;
CREATE INDEX TblWznmQIexHk1NVector_jref ON TblWznmQIexHk1NVector (jref);
CREATE INDEX TblWznmQIexHk1NVector_jnum ON TblWznmQIexHk1NVector (jnum);

CREATE TABLE TblWznmQIexList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Short VARCHAR(5),
	Title VARCHAR(50),
	refWznmMVersion BIGINT,
	Minversion VARCHAR(10)
);
ALTER TABLE TblWznmQIexList OWNER TO epsi;
CREATE INDEX TblWznmQIexList_jref ON TblWznmQIexList (jref);
CREATE INDEX TblWznmQIexList_jnum ON TblWznmQIexList (jnum);

CREATE TABLE TblWznmQIexRef1NDialog(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQIexRef1NDialog OWNER TO epsi;
CREATE INDEX TblWznmQIexRef1NDialog_jref ON TblWznmQIexRef1NDialog (jref);
CREATE INDEX TblWznmQIexRef1NDialog_jnum ON TblWznmQIexRef1NDialog (jnum);

CREATE TABLE TblWznmQImeHk1NVector(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQImeHk1NVector OWNER TO epsi;
CREATE INDEX TblWznmQImeHk1NVector_jref ON TblWznmQImeHk1NVector (jref);
CREATE INDEX TblWznmQImeHk1NVector_jnum ON TblWznmQImeHk1NVector (jnum);

CREATE TABLE TblWznmQImeIme1NImpexpcol(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	imeNum INT
);
ALTER TABLE TblWznmQImeIme1NImpexpcol OWNER TO epsi;
CREATE INDEX TblWznmQImeIme1NImpexpcol_jref ON TblWznmQImeIme1NImpexpcol (jref);
CREATE INDEX TblWznmQImeIme1NImpexpcol_jnum ON TblWznmQImeIme1NImpexpcol (jnum);

CREATE TABLE TblWznmQImeList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	refWznmMImpexpcplx BIGINT,
	supRefWznmMImpexp BIGINT,
	refWznmMTable BIGINT
);
ALTER TABLE TblWznmQImeList OWNER TO epsi;
CREATE INDEX TblWznmQImeList_jref ON TblWznmQImeList (jref);
CREATE INDEX TblWznmQImeList_jnum ON TblWznmQImeList (jnum);

CREATE TABLE TblWznmQImeSup1NImpexp(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQImeSup1NImpexp OWNER TO epsi;
CREATE INDEX TblWznmQImeSup1NImpexp_jref ON TblWznmQImeSup1NImpexp (jref);
CREATE INDEX TblWznmQImeSup1NImpexp_jnum ON TblWznmQImeSup1NImpexp (jnum);

CREATE TABLE TblWznmQJob1NMethod(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQJob1NMethod OWNER TO epsi;
CREATE INDEX TblWznmQJob1NMethod_jref ON TblWznmQJob1NMethod (jref);
CREATE INDEX TblWznmQJob1NMethod_jnum ON TblWznmQJob1NMethod (jnum);

CREATE TABLE TblWznmQJob1NRtjob(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQJob1NRtjob OWNER TO epsi;
CREATE INDEX TblWznmQJob1NRtjob_jref ON TblWznmQJob1NRtjob (jref);
CREATE INDEX TblWznmQJob1NRtjob_jnum ON TblWznmQJob1NRtjob (jnum);

CREATE TABLE TblWznmQJob1NSensitivity(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQJob1NSensitivity OWNER TO epsi;
CREATE INDEX TblWznmQJob1NSensitivity_jref ON TblWznmQJob1NSensitivity (jref);
CREATE INDEX TblWznmQJob1NSensitivity_jnum ON TblWznmQJob1NSensitivity (jnum);

CREATE TABLE TblWznmQJobACmd(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWznmQJobACmd OWNER TO epsi;
CREATE INDEX TblWznmQJobACmd_jref ON TblWznmQJobACmd (jref);
CREATE INDEX TblWznmQJobACmd_jnum ON TblWznmQJobACmd (jnum);

CREATE TABLE TblWznmQJobAVar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	jobNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Length INT,
	Shr SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWznmQJobAVar OWNER TO epsi;
CREATE INDEX TblWznmQJobAVar_jref ON TblWznmQJobAVar (jref);
CREATE INDEX TblWznmQJobAVar_jnum ON TblWznmQJobAVar (jnum);

CREATE TABLE TblWznmQJobHk1NVector(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQJobHk1NVector OWNER TO epsi;
CREATE INDEX TblWznmQJobHk1NVector_jref ON TblWznmQJobHk1NVector (jref);
CREATE INDEX TblWznmQJobHk1NVector_jnum ON TblWznmQJobHk1NVector (jnum);

CREATE TABLE TblWznmQJobJob1NStage(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	jobNum INT
);
ALTER TABLE TblWznmQJobJob1NStage OWNER TO epsi;
CREATE INDEX TblWznmQJobJob1NStage_jref ON TblWznmQJobJob1NStage (jref);
CREATE INDEX TblWznmQJobJob1NStage_jnum ON TblWznmQJobJob1NStage (jnum);

CREATE TABLE TblWznmQJobList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	Global SMALLINT,
	Clisrv SMALLINT,
	Shrdat SMALLINT
);
ALTER TABLE TblWznmQJobList OWNER TO epsi;
CREATE INDEX TblWznmQJobList_jref ON TblWznmQJobList (jref);
CREATE INDEX TblWznmQJobList_jnum ON TblWznmQJobList (jnum);

CREATE TABLE TblWznmQJobMNOp(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQJobMNOp OWNER TO epsi;
CREATE INDEX TblWznmQJobMNOp_jref ON TblWznmQJobMNOp (jref);
CREATE INDEX TblWznmQJobMNOp_jnum ON TblWznmQJobMNOp (jnum);

CREATE TABLE TblWznmQJobMNOppack(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQJobMNOppack OWNER TO epsi;
CREATE INDEX TblWznmQJobMNOppack_jref ON TblWznmQJobMNOppack (jref);
CREATE INDEX TblWznmQJobMNOppack_jnum ON TblWznmQJobMNOppack (jnum);

CREATE TABLE TblWznmQJobRef1NBlock(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQJobRef1NBlock OWNER TO epsi;
CREATE INDEX TblWznmQJobRef1NBlock_jref ON TblWznmQJobRef1NBlock (jref);
CREATE INDEX TblWznmQJobRef1NBlock_jnum ON TblWznmQJobRef1NBlock (jnum);

CREATE TABLE TblWznmQJobSubMNJob(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	Short VARCHAR(30),
	Multi SMALLINT,
	ixVConstract INT
);
ALTER TABLE TblWznmQJobSubMNJob OWNER TO epsi;
CREATE INDEX TblWznmQJobSubMNJob_jref ON TblWznmQJobSubMNJob (jref);
CREATE INDEX TblWznmQJobSubMNJob_jnum ON TblWznmQJobSubMNJob (jnum);

CREATE TABLE TblWznmQJobSupMNJob(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	Short VARCHAR(30),
	Multi SMALLINT,
	ixVConstract INT
);
ALTER TABLE TblWznmQJobSupMNJob OWNER TO epsi;
CREATE INDEX TblWznmQJobSupMNJob_jref ON TblWznmQJobSupMNJob (jref);
CREATE INDEX TblWznmQJobSupMNJob_jnum ON TblWznmQJobSupMNJob (jnum);

CREATE TABLE TblWznmQLibAMakefile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1RefIxVTbl INT,
	x1RefUref BIGINT,
	x2SrefKTag VARCHAR(50),
	Val TEXT
);
ALTER TABLE TblWznmQLibAMakefile OWNER TO epsi;
CREATE INDEX TblWznmQLibAMakefile_jref ON TblWznmQLibAMakefile (jref);
CREATE INDEX TblWznmQLibAMakefile_jnum ON TblWznmQLibAMakefile (jnum);

CREATE TABLE TblWznmQLibAPkglist(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1RefIxVTbl INT,
	x1RefUref BIGINT,
	Pkglist TEXT
);
ALTER TABLE TblWznmQLibAPkglist OWNER TO epsi;
CREATE INDEX TblWznmQLibAPkglist_jref ON TblWznmQLibAPkglist (jref);
CREATE INDEX TblWznmQLibAPkglist_jnum ON TblWznmQLibAPkglist (jnum);

CREATE TABLE TblWznmQLibList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	Version VARCHAR(30),
	srefKLictype VARCHAR(50)
);
ALTER TABLE TblWznmQLibList OWNER TO epsi;
CREATE INDEX TblWznmQLibList_jref ON TblWznmQLibList (jref);
CREATE INDEX TblWznmQLibList_jnum ON TblWznmQLibList (jnum);

CREATE TABLE TblWznmQLibMNComponent(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQLibMNComponent OWNER TO epsi;
CREATE INDEX TblWznmQLibMNComponent_jref ON TblWznmQLibMNComponent (jref);
CREATE INDEX TblWznmQLibMNComponent_jnum ON TblWznmQLibMNComponent (jnum);

CREATE TABLE TblWznmQLibMNOppack(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQLibMNOppack OWNER TO epsi;
CREATE INDEX TblWznmQLibMNOppack_jref ON TblWznmQLibMNOppack (jref);
CREATE INDEX TblWznmQLibMNOppack_jnum ON TblWznmQLibMNOppack (jnum);

CREATE TABLE TblWznmQLibRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQLibRef1NFile OWNER TO epsi;
CREATE INDEX TblWznmQLibRef1NFile_jref ON TblWznmQLibRef1NFile (jref);
CREATE INDEX TblWznmQLibRef1NFile_jnum ON TblWznmQLibRef1NFile (jnum);

CREATE TABLE TblWznmQLocList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50)
);
ALTER TABLE TblWznmQLocList OWNER TO epsi;
CREATE INDEX TblWznmQLocList_jref ON TblWznmQLocList (jref);
CREATE INDEX TblWznmQLocList_jnum ON TblWznmQLocList (jnum);

CREATE TABLE TblWznmQLocMNVersion(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQLocMNVersion OWNER TO epsi;
CREATE INDEX TblWznmQLocMNVersion_jref ON TblWznmQLocMNVersion (jref);
CREATE INDEX TblWznmQLocMNVersion_jnum ON TblWznmQLocMNVersion (jnum);

CREATE TABLE TblWznmQMch1NRelease(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQMch1NRelease OWNER TO epsi;
CREATE INDEX TblWznmQMch1NRelease_jref ON TblWznmQMch1NRelease (jref);
CREATE INDEX TblWznmQMch1NRelease_jnum ON TblWznmQMch1NRelease (jnum);

CREATE TABLE TblWznmQMchAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKKey VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWznmQMchAPar OWNER TO epsi;
CREATE INDEX TblWznmQMchAPar_jref ON TblWznmQMchAPar (jref);
CREATE INDEX TblWznmQMchAPar_jnum ON TblWznmQMchAPar (jnum);

CREATE TABLE TblWznmQMchList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	refWznmMMachtype BIGINT
);
ALTER TABLE TblWznmQMchList OWNER TO epsi;
CREATE INDEX TblWznmQMchList_jref ON TblWznmQMchList (jref);
CREATE INDEX TblWznmQMchList_jnum ON TblWznmQMchList (jnum);

CREATE TABLE TblWznmQMdlList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	verRefWznmMVersion BIGINT
);
ALTER TABLE TblWznmQMdlList OWNER TO epsi;
CREATE INDEX TblWznmQMdlList_jref ON TblWznmQMdlList (jref);
CREATE INDEX TblWznmQMdlList_jnum ON TblWznmQMdlList (jnum);

CREATE TABLE TblWznmQMdlMdl1NCard(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	mdlNum INT
);
ALTER TABLE TblWznmQMdlMdl1NCard OWNER TO epsi;
CREATE INDEX TblWznmQMdlMdl1NCard_jref ON TblWznmQMdlMdl1NCard (jref);
CREATE INDEX TblWznmQMdlMdl1NCard_jnum ON TblWznmQMdlMdl1NCard (jnum);

CREATE TABLE TblWznmQMdlRef1NPanel(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQMdlRef1NPanel OWNER TO epsi;
CREATE INDEX TblWznmQMdlRef1NPanel_jref ON TblWznmQMdlRef1NPanel (jref);
CREATE INDEX TblWznmQMdlRef1NPanel_jnum ON TblWznmQMdlRef1NPanel (jnum);

CREATE TABLE TblWznmQMtdAInvpar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	mtdNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Length INT,
	Comment TEXT
);
ALTER TABLE TblWznmQMtdAInvpar OWNER TO epsi;
CREATE INDEX TblWznmQMtdAInvpar_jref ON TblWznmQMtdAInvpar (jref);
CREATE INDEX TblWznmQMtdAInvpar_jnum ON TblWznmQMtdAInvpar (jnum);

CREATE TABLE TblWznmQMtdARetpar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	mtdNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Length INT,
	Comment TEXT
);
ALTER TABLE TblWznmQMtdARetpar OWNER TO epsi;
CREATE INDEX TblWznmQMtdARetpar_jref ON TblWznmQMtdARetpar (jref);
CREATE INDEX TblWznmQMtdARetpar_jnum ON TblWznmQMtdARetpar (jnum);

CREATE TABLE TblWznmQMtdList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	refWznmMJob BIGINT,
	Execsrv SMALLINT
);
ALTER TABLE TblWznmQMtdList OWNER TO epsi;
CREATE INDEX TblWznmQMtdList_jref ON TblWznmQMtdList (jref);
CREATE INDEX TblWznmQMtdList_jnum ON TblWznmQMtdList (jnum);

CREATE TABLE TblWznmQMty1NMachine(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQMty1NMachine OWNER TO epsi;
CREATE INDEX TblWznmQMty1NMachine_jref ON TblWznmQMty1NMachine (jref);
CREATE INDEX TblWznmQMty1NMachine_jnum ON TblWznmQMty1NMachine (jnum);

CREATE TABLE TblWznmQMtyAMakefile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKTag VARCHAR(50),
	Val TEXT
);
ALTER TABLE TblWznmQMtyAMakefile OWNER TO epsi;
CREATE INDEX TblWznmQMtyAMakefile_jref ON TblWznmQMtyAMakefile (jref);
CREATE INDEX TblWznmQMtyAMakefile_jnum ON TblWznmQMtyAMakefile (jnum);

CREATE TABLE TblWznmQMtyList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVArch INT,
	srefKOs VARCHAR(50)
);
ALTER TABLE TblWznmQMtyList OWNER TO epsi;
CREATE INDEX TblWznmQMtyList_jref ON TblWznmQMtyList (jref);
CREATE INDEX TblWznmQMtyList_jnum ON TblWznmQMtyList (jnum);

CREATE TABLE TblWznmQOpk1NOp(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQOpk1NOp OWNER TO epsi;
CREATE INDEX TblWznmQOpk1NOp_jref ON TblWznmQOpk1NOp (jref);
CREATE INDEX TblWznmQOpk1NOp_jnum ON TblWznmQOpk1NOp (jnum);

CREATE TABLE TblWznmQOpkAInvarg(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	opkNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Defval VARCHAR(192),
	refWznmMVectoritem BIGINT,
	Comment TEXT
);
ALTER TABLE TblWznmQOpkAInvarg OWNER TO epsi;
CREATE INDEX TblWznmQOpkAInvarg_jref ON TblWznmQOpkAInvarg (jref);
CREATE INDEX TblWznmQOpkAInvarg_jnum ON TblWznmQOpkAInvarg (jnum);

CREATE TABLE TblWznmQOpkARetval(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	opkNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Comment TEXT
);
ALTER TABLE TblWznmQOpkARetval OWNER TO epsi;
CREATE INDEX TblWznmQOpkARetval_jref ON TblWznmQOpkARetval (jref);
CREATE INDEX TblWznmQOpkARetval_jnum ON TblWznmQOpkARetval (jnum);

CREATE TABLE TblWznmQOpkList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(192),
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	Shrdat SMALLINT
);
ALTER TABLE TblWznmQOpkList OWNER TO epsi;
CREATE INDEX TblWznmQOpkList_jref ON TblWznmQOpkList (jref);
CREATE INDEX TblWznmQOpkList_jnum ON TblWznmQOpkList (jnum);

CREATE TABLE TblWznmQOpkMNComponent(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQOpkMNComponent OWNER TO epsi;
CREATE INDEX TblWznmQOpkMNComponent_jref ON TblWznmQOpkMNComponent (jref);
CREATE INDEX TblWznmQOpkMNComponent_jnum ON TblWznmQOpkMNComponent (jnum);

CREATE TABLE TblWznmQOpkMNJob(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQOpkMNJob OWNER TO epsi;
CREATE INDEX TblWznmQOpkMNJob_jref ON TblWznmQOpkMNJob (jref);
CREATE INDEX TblWznmQOpkMNJob_jnum ON TblWznmQOpkMNJob (jnum);

CREATE TABLE TblWznmQOpkMNLibrary(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQOpkMNLibrary OWNER TO epsi;
CREATE INDEX TblWznmQOpkMNLibrary_jref ON TblWznmQOpkMNLibrary (jref);
CREATE INDEX TblWznmQOpkMNLibrary_jnum ON TblWznmQOpkMNLibrary (jnum);

CREATE TABLE TblWznmQOpkRef1NBlock(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQOpkRef1NBlock OWNER TO epsi;
CREATE INDEX TblWznmQOpkRef1NBlock_jref ON TblWznmQOpkRef1NBlock (jref);
CREATE INDEX TblWznmQOpkRef1NBlock_jnum ON TblWznmQOpkRef1NBlock (jnum);

CREATE TABLE TblWznmQOpkSqkMNStub(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQOpkSqkMNStub OWNER TO epsi;
CREATE INDEX TblWznmQOpkSqkMNStub_jref ON TblWznmQOpkSqkMNStub (jref);
CREATE INDEX TblWznmQOpkSqkMNStub_jnum ON TblWznmQOpkSqkMNStub (jnum);

CREATE TABLE TblWznmQOpxAInvarg(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	opxNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Defval VARCHAR(192),
	refWznmMVectoritem BIGINT,
	Comment TEXT
);
ALTER TABLE TblWznmQOpxAInvarg OWNER TO epsi;
CREATE INDEX TblWznmQOpxAInvarg_jref ON TblWznmQOpxAInvarg (jref);
CREATE INDEX TblWznmQOpxAInvarg_jnum ON TblWznmQOpxAInvarg (jnum);

CREATE TABLE TblWznmQOpxARetval(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	opxNum INT,
	sref VARCHAR(50),
	ixWznmVVartype INT,
	refWznmMVector BIGINT,
	Comment TEXT
);
ALTER TABLE TblWznmQOpxARetval OWNER TO epsi;
CREATE INDEX TblWznmQOpxARetval_jref ON TblWznmQOpxARetval (jref);
CREATE INDEX TblWznmQOpxARetval_jnum ON TblWznmQOpxARetval (jnum);

CREATE TABLE TblWznmQOpxList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	refWznmMOppack BIGINT,
	Shrdat SMALLINT
);
ALTER TABLE TblWznmQOpxList OWNER TO epsi;
CREATE INDEX TblWznmQOpxList_jref ON TblWznmQOpxList (jref);
CREATE INDEX TblWznmQOpxList_jnum ON TblWznmQOpxList (jnum);

CREATE TABLE TblWznmQOpxMNJob(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQOpxMNJob OWNER TO epsi;
CREATE INDEX TblWznmQOpxMNJob_jref ON TblWznmQOpxMNJob (jref);
CREATE INDEX TblWznmQOpxMNJob_jnum ON TblWznmQOpxMNJob (jnum);

CREATE TABLE TblWznmQOpxRef1NBlock(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQOpxRef1NBlock OWNER TO epsi;
CREATE INDEX TblWznmQOpxRef1NBlock_jref ON TblWznmQOpxRef1NBlock (jref);
CREATE INDEX TblWznmQOpxRef1NBlock_jnum ON TblWznmQOpxRef1NBlock (jnum);

CREATE TABLE TblWznmQOpxSqkMNStub(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQOpxSqkMNStub OWNER TO epsi;
CREATE INDEX TblWznmQOpxSqkMNStub_jref ON TblWznmQOpxSqkMNStub (jref);
CREATE INDEX TblWznmQOpxSqkMNStub_jnum ON TblWznmQOpxSqkMNStub (jnum);

CREATE TABLE TblWznmQPnlHk1NControl(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	hkNum INT
);
ALTER TABLE TblWznmQPnlHk1NControl OWNER TO epsi;
CREATE INDEX TblWznmQPnlHk1NControl_jref ON TblWznmQPnlHk1NControl (jref);
CREATE INDEX TblWznmQPnlHk1NControl_jnum ON TblWznmQPnlHk1NControl (jnum);

CREATE TABLE TblWznmQPnlList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	carRefWznmMCard BIGINT,
	refIxVTbl INT,
	refUref BIGINT
);
ALTER TABLE TblWznmQPnlList OWNER TO epsi;
CREATE INDEX TblWznmQPnlList_jref ON TblWznmQPnlList (jref);
CREATE INDEX TblWznmQPnlList_jnum ON TblWznmQPnlList (jnum);

CREATE TABLE TblWznmQPnlMNQuery(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQPnlMNQuery OWNER TO epsi;
CREATE INDEX TblWznmQPnlMNQuery_jref ON TblWznmQPnlMNQuery (jref);
CREATE INDEX TblWznmQPnlMNQuery_jnum ON TblWznmQPnlMNQuery (jnum);

CREATE TABLE TblWznmQPreselect(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQPreselect OWNER TO epsi;
CREATE INDEX TblWznmQPreselect_jref ON TblWznmQPreselect (jref);

CREATE TABLE TblWznmQPrj1NVersion(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	prjNum INT
);
ALTER TABLE TblWznmQPrj1NVersion OWNER TO epsi;
CREATE INDEX TblWznmQPrj1NVersion_jref ON TblWznmQPrj1NVersion (jref);
CREATE INDEX TblWznmQPrj1NVersion_jnum ON TblWznmQPrj1NVersion (jnum);

CREATE TABLE TblWznmQPrjList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	Short VARCHAR(5),
	Title VARCHAR(50),
	refWznmMVersion BIGINT,
	Giturl VARCHAR(192)
);
ALTER TABLE TblWznmQPrjList OWNER TO epsi;
CREATE INDEX TblWznmQPrjList_jref ON TblWznmQPrjList (jref);
CREATE INDEX TblWznmQPrjList_jnum ON TblWznmQPrjList (jnum);

CREATE TABLE TblWznmQPrjMNPerson(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Startd INT,
	x1Stopd INT,
	srefKFunction VARCHAR(50)
);
ALTER TABLE TblWznmQPrjMNPerson OWNER TO epsi;
CREATE INDEX TblWznmQPrjMNPerson_jref ON TblWznmQPrjMNPerson (jref);
CREATE INDEX TblWznmQPrjMNPerson_jnum ON TblWznmQPrjMNPerson (jnum);

CREATE TABLE TblWznmQPrsADetail(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWznmQPrsADetail OWNER TO epsi;
CREATE INDEX TblWznmQPrsADetail_jref ON TblWznmQPrsADetail (jref);
CREATE INDEX TblWznmQPrsADetail_jnum ON TblWznmQPrsADetail (jnum);

CREATE TABLE TblWznmQPrsList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	Lastname VARCHAR(50),
	ixVSex INT,
	telVal VARCHAR(192),
	emlVal VARCHAR(192)
);
ALTER TABLE TblWznmQPrsList OWNER TO epsi;
CREATE INDEX TblWznmQPrsList_jref ON TblWznmQPrsList (jref);
CREATE INDEX TblWznmQPrsList_jnum ON TblWznmQPrsList (jnum);

CREATE TABLE TblWznmQPrsMNProject(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Startd INT,
	x1Stopd INT,
	srefKFunction VARCHAR(50)
);
ALTER TABLE TblWznmQPrsMNProject OWNER TO epsi;
CREATE INDEX TblWznmQPrsMNProject_jref ON TblWznmQPrsMNProject (jref);
CREATE INDEX TblWznmQPrsMNProject_jnum ON TblWznmQPrsMNProject (jnum);

CREATE TABLE TblWznmQPst1NQuerymod(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQPst1NQuerymod OWNER TO epsi;
CREATE INDEX TblWznmQPst1NQuerymod_jref ON TblWznmQPst1NQuerymod (jref);
CREATE INDEX TblWznmQPst1NQuerymod_jnum ON TblWznmQPst1NQuerymod (jnum);

CREATE TABLE TblWznmQPstList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	refWznmMVersion BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	ixWznmWArgtype INT
);
ALTER TABLE TblWznmQPstList OWNER TO epsi;
CREATE INDEX TblWznmQPstList_jref ON TblWznmQPstList (jref);
CREATE INDEX TblWznmQPstList_jnum ON TblWznmQPstList (jnum);

CREATE TABLE TblWznmQQcoList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Short VARCHAR(10),
	ixVBasetype INT,
	qryRefWznmMQuery BIGINT,
	refWznmMTablecol BIGINT
);
ALTER TABLE TblWznmQQcoList OWNER TO epsi;
CREATE INDEX TblWznmQQcoList_jref ON TblWznmQQcoList (jref);
CREATE INDEX TblWznmQQcoList_jnum ON TblWznmQQcoList (jnum);

CREATE TABLE TblWznmQQcoRef1NControl(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQQcoRef1NControl OWNER TO epsi;
CREATE INDEX TblWznmQQcoRef1NControl_jref ON TblWznmQQcoRef1NControl (jref);
CREATE INDEX TblWznmQQcoRef1NControl_jnum ON TblWznmQQcoRef1NControl (jnum);

CREATE TABLE TblWznmQQmdList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	ixVBasetype INT,
	qryRefWznmMQuery BIGINT,
	refWznmMPreset BIGINT,
	refIxVTbl INT,
	refUref BIGINT
);
ALTER TABLE TblWznmQQmdList OWNER TO epsi;
CREATE INDEX TblWznmQQmdList_jref ON TblWznmQQmdList (jref);
CREATE INDEX TblWznmQQmdList_jnum ON TblWznmQQmdList (jnum);

CREATE TABLE TblWznmQQry1NQuerymod(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	qryNum INT
);
ALTER TABLE TblWznmQQry1NQuerymod OWNER TO epsi;
CREATE INDEX TblWznmQQry1NQuerymod_jref ON TblWznmQQry1NQuerymod (jref);
CREATE INDEX TblWznmQQry1NQuerymod_jnum ON TblWznmQQry1NQuerymod (jnum);

CREATE TABLE TblWznmQQryAClause(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	qryNum INT,
	x1RefWznmMQuerymod BIGINT,
	ixVBasetype INT,
	Clause VARCHAR(1024),
	refWznmMPreset BIGINT,
	refWznmMVector BIGINT,
	refWznmMVectoritem BIGINT
);
ALTER TABLE TblWznmQQryAClause OWNER TO epsi;
CREATE INDEX TblWznmQQryAClause_jref ON TblWznmQQryAClause (jref);
CREATE INDEX TblWznmQQryAClause_jnum ON TblWznmQQryAClause (jnum);

CREATE TABLE TblWznmQQryAOrder(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Short VARCHAR(30),
	srefsWznmMTablecol VARCHAR(192)
);
ALTER TABLE TblWznmQQryAOrder OWNER TO epsi;
CREATE INDEX TblWznmQQryAOrder_jref ON TblWznmQQryAOrder (jref);
CREATE INDEX TblWznmQQryAOrder_jnum ON TblWznmQQryAOrder (jnum);

CREATE TABLE TblWznmQQryList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	supRefWznmMQuery BIGINT,
	supIxVSubrole INT,
	refWznmMTable BIGINT,
	qtbRefWznmMTable BIGINT
);
ALTER TABLE TblWznmQQryList OWNER TO epsi;
CREATE INDEX TblWznmQQryList_jref ON TblWznmQQryList (jref);
CREATE INDEX TblWznmQQryList_jnum ON TblWznmQQryList (jnum);

CREATE TABLE TblWznmQQryMNDialog(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQQryMNDialog OWNER TO epsi;
CREATE INDEX TblWznmQQryMNDialog_jref ON TblWznmQQryMNDialog (jref);
CREATE INDEX TblWznmQQryMNDialog_jnum ON TblWznmQQryMNDialog (jnum);

CREATE TABLE TblWznmQQryMNPanel(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQQryMNPanel OWNER TO epsi;
CREATE INDEX TblWznmQQryMNPanel_jref ON TblWznmQQryMNPanel (jref);
CREATE INDEX TblWznmQQryMNPanel_jnum ON TblWznmQQryMNPanel (jnum);

CREATE TABLE TblWznmQQryMNTable(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	Source SMALLINT,
	Prefix VARCHAR(5)
);
ALTER TABLE TblWznmQQryMNTable OWNER TO epsi;
CREATE INDEX TblWznmQQryMNTable_jref ON TblWznmQQryMNTable (jref);
CREATE INDEX TblWznmQQryMNTable_jnum ON TblWznmQQryMNTable (jnum);

CREATE TABLE TblWznmQQryQry1NQuerycol(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	qryNum INT
);
ALTER TABLE TblWznmQQryQry1NQuerycol OWNER TO epsi;
CREATE INDEX TblWznmQQryQry1NQuerycol_jref ON TblWznmQQryQry1NQuerycol (jref);
CREATE INDEX TblWznmQQryQry1NQuerycol_jnum ON TblWznmQQryQry1NQuerycol (jnum);

CREATE TABLE TblWznmQQrySup1NQuery(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQQrySup1NQuery OWNER TO epsi;
CREATE INDEX TblWznmQQrySup1NQuery_jref ON TblWznmQQrySup1NQuery (jref);
CREATE INDEX TblWznmQQrySup1NQuery_jnum ON TblWznmQQrySup1NQuery (jnum);

CREATE TABLE TblWznmQRel1NTablecol(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQRel1NTablecol OWNER TO epsi;
CREATE INDEX TblWznmQRel1NTablecol_jref ON TblWznmQRel1NTablecol (jref);
CREATE INDEX TblWznmQRel1NTablecol_jnum ON TblWznmQRel1NTablecol (jnum);

CREATE TABLE TblWznmQRelATitle(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxVType INT,
	x2RefWznmMLocale BIGINT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmQRelATitle OWNER TO epsi;
CREATE INDEX TblWznmQRelATitle_jref ON TblWznmQRelATitle (jref);
CREATE INDEX TblWznmQRelATitle_jnum ON TblWznmQRelATitle (jnum);

CREATE TABLE TblWznmQRelList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	frRefWznmMTable BIGINT,
	frsRefWznmMSubset BIGINT,
	toRefWznmMTable BIGINT,
	tosRefWznmMSubset BIGINT,
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	supRefWznmMRelation BIGINT,
	supIxVSubrole INT,
	refWznmMTable BIGINT,
	Prefix VARCHAR(10)
);
ALTER TABLE TblWznmQRelList OWNER TO epsi;
CREATE INDEX TblWznmQRelList_jref ON TblWznmQRelList (jref);
CREATE INDEX TblWznmQRelList_jnum ON TblWznmQRelList (jnum);

CREATE TABLE TblWznmQRelRef1NControl(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQRelRef1NControl OWNER TO epsi;
CREATE INDEX TblWznmQRelRef1NControl_jref ON TblWznmQRelRef1NControl (jref);
CREATE INDEX TblWznmQRelRef1NControl_jnum ON TblWznmQRelRef1NControl (jnum);

CREATE TABLE TblWznmQRelRef1NDialog(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQRelRef1NDialog OWNER TO epsi;
CREATE INDEX TblWznmQRelRef1NDialog_jref ON TblWznmQRelRef1NDialog (jref);
CREATE INDEX TblWznmQRelRef1NDialog_jnum ON TblWznmQRelRef1NDialog (jnum);

CREATE TABLE TblWznmQRelRef1NPanel(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQRelRef1NPanel OWNER TO epsi;
CREATE INDEX TblWznmQRelRef1NPanel_jref ON TblWznmQRelRef1NPanel (jref);
CREATE INDEX TblWznmQRelRef1NPanel_jnum ON TblWznmQRelRef1NPanel (jnum);

CREATE TABLE TblWznmQRelSup1NRelation(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQRelSup1NRelation OWNER TO epsi;
CREATE INDEX TblWznmQRelSup1NRelation_jref ON TblWznmQRelSup1NRelation (jref);
CREATE INDEX TblWznmQRelSup1NRelation_jnum ON TblWznmQRelSup1NRelation (jnum);

CREATE TABLE TblWznmQRlsList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	refWznmMComponent BIGINT,
	refWznmMMachine BIGINT
);
ALTER TABLE TblWznmQRlsList OWNER TO epsi;
CREATE INDEX TblWznmQRlsList_jref ON TblWznmQRlsList (jref);
CREATE INDEX TblWznmQRlsList_jnum ON TblWznmQRlsList (jnum);

CREATE TABLE TblWznmQRtj1NRtblock(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQRtj1NRtblock OWNER TO epsi;
CREATE INDEX TblWznmQRtj1NRtblock_jref ON TblWznmQRtj1NRtblock (jref);
CREATE INDEX TblWznmQRtj1NRtblock_jnum ON TblWznmQRtj1NRtblock (jnum);

CREATE TABLE TblWznmQRtj1NRtdpch(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQRtj1NRtdpch OWNER TO epsi;
CREATE INDEX TblWznmQRtj1NRtdpch_jref ON TblWznmQRtj1NRtdpch (jref);
CREATE INDEX TblWznmQRtj1NRtdpch_jnum ON TblWznmQRtj1NRtdpch (jnum);

CREATE TABLE TblWznmQRtjList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	refWznmMApp BIGINT,
	supRefWznmMRtjob BIGINT,
	refWznmMJob BIGINT
);
ALTER TABLE TblWznmQRtjList OWNER TO epsi;
CREATE INDEX TblWznmQRtjList_jref ON TblWznmQRtjList (jref);
CREATE INDEX TblWznmQRtjList_jnum ON TblWznmQRtjList (jnum);

CREATE TABLE TblWznmQRtjSup1NRtjob(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQRtjSup1NRtjob OWNER TO epsi;
CREATE INDEX TblWznmQRtjSup1NRtjob_jref ON TblWznmQRtjSup1NRtjob (jref);
CREATE INDEX TblWznmQRtjSup1NRtjob_jnum ON TblWznmQRtjSup1NRtjob (jnum);

CREATE TABLE TblWznmQSbs1NStub(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQSbs1NStub OWNER TO epsi;
CREATE INDEX TblWznmQSbs1NStub_jref ON TblWznmQSbs1NStub (jref);
CREATE INDEX TblWznmQSbs1NStub_jnum ON TblWznmQSbs1NStub (jnum);

CREATE TABLE TblWznmQSbs1NTablecol(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQSbs1NTablecol OWNER TO epsi;
CREATE INDEX TblWznmQSbs1NTablecol_jref ON TblWznmQSbs1NTablecol (jref);
CREATE INDEX TblWznmQSbs1NTablecol_jnum ON TblWznmQSbs1NTablecol (jnum);

CREATE TABLE TblWznmQSbsAsbMNSubset(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixVReltype INT
);
ALTER TABLE TblWznmQSbsAsbMNSubset OWNER TO epsi;
CREATE INDEX TblWznmQSbsAsbMNSubset_jref ON TblWznmQSbsAsbMNSubset (jref);
CREATE INDEX TblWznmQSbsAsbMNSubset_jnum ON TblWznmQSbsAsbMNSubset (jnum);

CREATE TABLE TblWznmQSbsATitle(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxVType INT,
	x2RefWznmMLocale BIGINT,
	ixWznmVGender INT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmQSbsATitle OWNER TO epsi;
CREATE INDEX TblWznmQSbsATitle_jref ON TblWznmQSbsATitle (jref);
CREATE INDEX TblWznmQSbsATitle_jnum ON TblWznmQSbsATitle (jnum);

CREATE TABLE TblWznmQSbsBsbMNSubset(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixVReltype INT
);
ALTER TABLE TblWznmQSbsBsbMNSubset OWNER TO epsi;
CREATE INDEX TblWznmQSbsBsbMNSubset_jref ON TblWznmQSbsBsbMNSubset (jref);
CREATE INDEX TblWznmQSbsBsbMNSubset_jnum ON TblWznmQSbsBsbMNSubset (jnum);

CREATE TABLE TblWznmQSbsFrs1NRelation(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQSbsFrs1NRelation OWNER TO epsi;
CREATE INDEX TblWznmQSbsFrs1NRelation_jref ON TblWznmQSbsFrs1NRelation (jref);
CREATE INDEX TblWznmQSbsFrs1NRelation_jnum ON TblWznmQSbsFrs1NRelation (jnum);

CREATE TABLE TblWznmQSbsList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Short VARCHAR(10),
	refWznmMTable BIGINT
);
ALTER TABLE TblWznmQSbsList OWNER TO epsi;
CREATE INDEX TblWznmQSbsList_jref ON TblWznmQSbsList (jref);
CREATE INDEX TblWznmQSbsList_jnum ON TblWznmQSbsList (jnum);

CREATE TABLE TblWznmQSbsPst1NQuerymod(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQSbsPst1NQuerymod OWNER TO epsi;
CREATE INDEX TblWznmQSbsPst1NQuerymod_jref ON TblWznmQSbsPst1NQuerymod (jref);
CREATE INDEX TblWznmQSbsPst1NQuerymod_jnum ON TblWznmQSbsPst1NQuerymod (jnum);

CREATE TABLE TblWznmQSbsTos1NRelation(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQSbsTos1NRelation OWNER TO epsi;
CREATE INDEX TblWznmQSbsTos1NRelation_jref ON TblWznmQSbsTos1NRelation (jref);
CREATE INDEX TblWznmQSbsTos1NRelation_jnum ON TblWznmQSbsTos1NRelation (jnum);

CREATE TABLE TblWznmQSelect(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ix INT,
	ref BIGINT
);
ALTER TABLE TblWznmQSelect OWNER TO epsi;
CREATE INDEX TblWznmQSelect_jref ON TblWznmQSelect (jref);
CREATE INDEX TblWznmQSelect_ix ON TblWznmQSelect (ix);

CREATE TABLE TblWznmQSeqList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	appRefWznmMApp BIGINT
);
ALTER TABLE TblWznmQSeqList OWNER TO epsi;
CREATE INDEX TblWznmQSeqList_jref ON TblWznmQSeqList (jref);
CREATE INDEX TblWznmQSeqList_jnum ON TblWznmQSeqList (jnum);

CREATE TABLE TblWznmQSeqSeq1NState(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	seqNum INT
);
ALTER TABLE TblWznmQSeqSeq1NState OWNER TO epsi;
CREATE INDEX TblWznmQSeqSeq1NState_jref ON TblWznmQSeqSeq1NState (jref);
CREATE INDEX TblWznmQSeqSeq1NState_jnum ON TblWznmQSeqSeq1NState (jnum);

CREATE TABLE TblWznmQSge1NSensitivity(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQSge1NSensitivity OWNER TO epsi;
CREATE INDEX TblWznmQSge1NSensitivity_jref ON TblWznmQSge1NSensitivity (jref);
CREATE INDEX TblWznmQSge1NSensitivity_jnum ON TblWznmQSge1NSensitivity (jnum);

CREATE TABLE TblWznmQSgeList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	jobRefWznmMJob BIGINT
);
ALTER TABLE TblWznmQSgeList OWNER TO epsi;
CREATE INDEX TblWznmQSgeList_jref ON TblWznmQSgeList (jref);
CREATE INDEX TblWznmQSgeList_jnum ON TblWznmQSgeList (jnum);

CREATE TABLE TblWznmQSgeSqkMNStub(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQSgeSqkMNStub OWNER TO epsi;
CREATE INDEX TblWznmQSgeSqkMNStub_jref ON TblWznmQSgeSqkMNStub (jref);
CREATE INDEX TblWznmQSgeSqkMNStub_jnum ON TblWznmQSgeSqkMNStub (jnum);

CREATE TABLE TblWznmQStbList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	refWznmMTable BIGINT,
	refWznmMSubset BIGINT,
	Example VARCHAR(192)
);
ALTER TABLE TblWznmQStbList OWNER TO epsi;
CREATE INDEX TblWznmQStbList_jref ON TblWznmQStbList (jref);
CREATE INDEX TblWznmQStbList_jnum ON TblWznmQStbList (jnum);

CREATE TABLE TblWznmQStbMNCall(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQStbMNCall OWNER TO epsi;
CREATE INDEX TblWznmQStbMNCall_jref ON TblWznmQStbMNCall (jref);
CREATE INDEX TblWznmQStbMNCall_jnum ON TblWznmQStbMNCall (jnum);

CREATE TABLE TblWznmQStbMNSquawk(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQStbMNSquawk OWNER TO epsi;
CREATE INDEX TblWznmQStbMNSquawk_jref ON TblWznmQStbMNSquawk (jref);
CREATE INDEX TblWznmQStbMNSquawk_jnum ON TblWznmQStbMNSquawk (jnum);

CREATE TABLE TblWznmQStbSubMNStub(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQStbSubMNStub OWNER TO epsi;
CREATE INDEX TblWznmQStbSubMNStub_jref ON TblWznmQStbSubMNStub (jref);
CREATE INDEX TblWznmQStbSubMNStub_jnum ON TblWznmQStbSubMNStub (jnum);

CREATE TABLE TblWznmQStbSupMNStub(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQStbSupMNStub OWNER TO epsi;
CREATE INDEX TblWznmQStbSupMNStub_jref ON TblWznmQStbSupMNStub (jref);
CREATE INDEX TblWznmQStbSupMNStub_jnum ON TblWznmQStbSupMNStub (jnum);

CREATE TABLE TblWznmQSteAStep(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	snxRefWznmMState BIGINT,
	ixVTrigger INT,
	refWznmMRtjob BIGINT,
	refWznmMVectoritem BIGINT,
	xsref VARCHAR(50),
	refWznmMRtdpch BIGINT,
	srefsMask VARCHAR(192),
	Cond TEXT,
	Custcode SMALLINT
);
ALTER TABLE TblWznmQSteAStep OWNER TO epsi;
CREATE INDEX TblWznmQSteAStep_jref ON TblWznmQSteAStep (jref);
CREATE INDEX TblWznmQSteAStep_jnum ON TblWznmQSteAStep (jnum);

CREATE TABLE TblWznmQSteList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	seqRefWznmMSequence BIGINT,
	eacIxVAction INT,
	lacIxVAction INT,
	Custstep SMALLINT
);
ALTER TABLE TblWznmQSteList OWNER TO epsi;
CREATE INDEX TblWznmQSteList_jref ON TblWznmQSteList (jref);
CREATE INDEX TblWznmQSteList_jnum ON TblWznmQSteList (jnum);

CREATE TABLE TblWznmQTagList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(192),
	refWznmMCapability BIGINT,
	osrefWznmKTaggrp VARCHAR(50)
);
ALTER TABLE TblWznmQTagList OWNER TO epsi;
CREATE INDEX TblWznmQTagList_jref ON TblWznmQTagList (jref);
CREATE INDEX TblWznmQTagList_jnum ON TblWznmQTagList (jnum);

CREATE TABLE TblWznmQTbl1NCheck(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTbl1NCheck OWNER TO epsi;
CREATE INDEX TblWznmQTbl1NCheck_jref ON TblWznmQTbl1NCheck (jref);
CREATE INDEX TblWznmQTbl1NCheck_jnum ON TblWznmQTbl1NCheck (jnum);

CREATE TABLE TblWznmQTbl1NImpexp(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTbl1NImpexp OWNER TO epsi;
CREATE INDEX TblWznmQTbl1NImpexp_jref ON TblWznmQTbl1NImpexp (jref);
CREATE INDEX TblWznmQTbl1NImpexp_jnum ON TblWznmQTbl1NImpexp (jnum);

CREATE TABLE TblWznmQTbl1NStub(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTbl1NStub OWNER TO epsi;
CREATE INDEX TblWznmQTbl1NStub_jref ON TblWznmQTbl1NStub (jref);
CREATE INDEX TblWznmQTbl1NStub_jnum ON TblWznmQTbl1NStub (jnum);

CREATE TABLE TblWznmQTbl1NSubset(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTbl1NSubset OWNER TO epsi;
CREATE INDEX TblWznmQTbl1NSubset_jref ON TblWznmQTbl1NSubset (jref);
CREATE INDEX TblWznmQTbl1NSubset_jnum ON TblWznmQTbl1NSubset (jnum);

CREATE TABLE TblWznmQTblALoadfct(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	ixVLoadtype INT,
	Fctname VARCHAR(50),
	ldSrefWznmMTablecol VARCHAR(50),
	lbySrefsWznmMTablecol VARCHAR(192),
	ordSrefsWznmMTablecol VARCHAR(192),
	ixVLimtype INT
);
ALTER TABLE TblWznmQTblALoadfct OWNER TO epsi;
CREATE INDEX TblWznmQTblALoadfct_jref ON TblWznmQTblALoadfct (jref);
CREATE INDEX TblWznmQTblALoadfct_jnum ON TblWznmQTblALoadfct (jnum);

CREATE TABLE TblWznmQTblATitle(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxVType INT,
	x2RefWznmMLocale BIGINT,
	ixWznmVGender INT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmQTblATitle OWNER TO epsi;
CREATE INDEX TblWznmQTblATitle_jref ON TblWznmQTblATitle (jref);
CREATE INDEX TblWznmQTblATitle_jnum ON TblWznmQTblATitle (jnum);

CREATE TABLE TblWznmQTblFct1NTablecol(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTblFct1NTablecol OWNER TO epsi;
CREATE INDEX TblWznmQTblFct1NTablecol_jref ON TblWznmQTblFct1NTablecol (jref);
CREATE INDEX TblWznmQTblFct1NTablecol_jnum ON TblWznmQTblFct1NTablecol (jnum);

CREATE TABLE TblWznmQTblFr1NRelation(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTblFr1NRelation OWNER TO epsi;
CREATE INDEX TblWznmQTblFr1NRelation_jref ON TblWznmQTblFr1NRelation (jref);
CREATE INDEX TblWznmQTblFr1NRelation_jnum ON TblWznmQTblFr1NRelation (jnum);

CREATE TABLE TblWznmQTblHk1NVector(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTblHk1NVector OWNER TO epsi;
CREATE INDEX TblWznmQTblHk1NVector_jref ON TblWznmQTblHk1NVector (jref);
CREATE INDEX TblWznmQTblHk1NVector_jnum ON TblWznmQTblHk1NVector (jnum);

CREATE TABLE TblWznmQTblList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Short VARCHAR(10),
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	refIxVTbl INT,
	refUref BIGINT
);
ALTER TABLE TblWznmQTblList OWNER TO epsi;
CREATE INDEX TblWznmQTblList_jref ON TblWznmQTblList (jref);
CREATE INDEX TblWznmQTblList_jnum ON TblWznmQTblList (jnum);

CREATE TABLE TblWznmQTblMNQuery(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	Source SMALLINT,
	Prefix VARCHAR(5)
);
ALTER TABLE TblWznmQTblMNQuery OWNER TO epsi;
CREATE INDEX TblWznmQTblMNQuery_jref ON TblWznmQTblMNQuery (jref);
CREATE INDEX TblWznmQTblMNQuery_jnum ON TblWznmQTblMNQuery (jnum);

CREATE TABLE TblWznmQTblMNVector(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	refWznmMSubset BIGINT
);
ALTER TABLE TblWznmQTblMNVector OWNER TO epsi;
CREATE INDEX TblWznmQTblMNVector_jref ON TblWznmQTblMNVector (jref);
CREATE INDEX TblWznmQTblMNVector_jnum ON TblWznmQTblMNVector (jnum);

CREATE TABLE TblWznmQTblPst1NQuerymod(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTblPst1NQuerymod OWNER TO epsi;
CREATE INDEX TblWznmQTblPst1NQuerymod_jref ON TblWznmQTblPst1NQuerymod (jref);
CREATE INDEX TblWznmQTblPst1NQuerymod_jnum ON TblWznmQTblPst1NQuerymod (jnum);

CREATE TABLE TblWznmQTblRef1NCall(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTblRef1NCall OWNER TO epsi;
CREATE INDEX TblWznmQTblRef1NCall_jref ON TblWznmQTblRef1NCall (jref);
CREATE INDEX TblWznmQTblRef1NCall_jnum ON TblWznmQTblRef1NCall (jnum);

CREATE TABLE TblWznmQTblRef1NDialog(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTblRef1NDialog OWNER TO epsi;
CREATE INDEX TblWznmQTblRef1NDialog_jref ON TblWznmQTblRef1NDialog (jref);
CREATE INDEX TblWznmQTblRef1NDialog_jnum ON TblWznmQTblRef1NDialog (jnum);

CREATE TABLE TblWznmQTblRef1NPanel(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTblRef1NPanel OWNER TO epsi;
CREATE INDEX TblWznmQTblRef1NPanel_jref ON TblWznmQTblRef1NPanel (jref);
CREATE INDEX TblWznmQTblRef1NPanel_jnum ON TblWznmQTblRef1NPanel (jnum);

CREATE TABLE TblWznmQTblRef1NQuerymod(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTblRef1NQuerymod OWNER TO epsi;
CREATE INDEX TblWznmQTblRef1NQuerymod_jref ON TblWznmQTblRef1NQuerymod (jref);
CREATE INDEX TblWznmQTblRef1NQuerymod_jnum ON TblWznmQTblRef1NQuerymod (jnum);

CREATE TABLE TblWznmQTblRef1NRtblock(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTblRef1NRtblock OWNER TO epsi;
CREATE INDEX TblWznmQTblRef1NRtblock_jref ON TblWznmQTblRef1NRtblock (jref);
CREATE INDEX TblWznmQTblRef1NRtblock_jnum ON TblWznmQTblRef1NRtblock (jnum);

CREATE TABLE TblWznmQTblSrc1NFeed(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTblSrc1NFeed OWNER TO epsi;
CREATE INDEX TblWznmQTblSrc1NFeed_jref ON TblWznmQTblSrc1NFeed (jref);
CREATE INDEX TblWznmQTblSrc1NFeed_jnum ON TblWznmQTblSrc1NFeed (jnum);

CREATE TABLE TblWznmQTblTbl1NTablecol(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	tblNum INT
);
ALTER TABLE TblWznmQTblTbl1NTablecol OWNER TO epsi;
CREATE INDEX TblWznmQTblTbl1NTablecol_jref ON TblWznmQTblTbl1NTablecol (jref);
CREATE INDEX TblWznmQTblTbl1NTablecol_jnum ON TblWznmQTblTbl1NTablecol (jnum);

CREATE TABLE TblWznmQTblTo1NRelation(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTblTo1NRelation OWNER TO epsi;
CREATE INDEX TblWznmQTblTo1NRelation_jref ON TblWznmQTblTo1NRelation (jref);
CREATE INDEX TblWznmQTblTo1NRelation_jnum ON TblWznmQTblTo1NRelation (jnum);

CREATE TABLE TblWznmQTco1NCheck(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTco1NCheck OWNER TO epsi;
CREATE INDEX TblWznmQTco1NCheck_jref ON TblWznmQTco1NCheck (jref);
CREATE INDEX TblWznmQTco1NCheck_jnum ON TblWznmQTco1NCheck (jnum);

CREATE TABLE TblWznmQTco1NImpexpcol(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTco1NImpexpcol OWNER TO epsi;
CREATE INDEX TblWznmQTco1NImpexpcol_jref ON TblWznmQTco1NImpexpcol (jref);
CREATE INDEX TblWznmQTco1NImpexpcol_jnum ON TblWznmQTco1NImpexpcol (jnum);

CREATE TABLE TblWznmQTco1NQuerycol(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTco1NQuerycol OWNER TO epsi;
CREATE INDEX TblWznmQTco1NQuerycol_jref ON TblWznmQTco1NQuerycol (jref);
CREATE INDEX TblWznmQTco1NQuerycol_jnum ON TblWznmQTco1NQuerycol (jnum);

CREATE TABLE TblWznmQTcoATitle(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxVType INT,
	x2RefWznmMLocale BIGINT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmQTcoATitle OWNER TO epsi;
CREATE INDEX TblWznmQTcoATitle_jref ON TblWznmQTcoATitle (jref);
CREATE INDEX TblWznmQTcoATitle_jnum ON TblWznmQTcoATitle (jnum);

CREATE TABLE TblWznmQTcoList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Short VARCHAR(10),
	ixVBasetype INT,
	tblRefWznmMTable BIGINT,
	fctIxVTbl INT,
	ixVSubtype INT,
	ixVAxisfct INT
);
ALTER TABLE TblWznmQTcoList OWNER TO epsi;
CREATE INDEX TblWznmQTcoList_jref ON TblWznmQTcoList (jref);
CREATE INDEX TblWznmQTcoList_jnum ON TblWznmQTcoList (jnum);

CREATE TABLE TblWznmQTcoRef1NControl(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTcoRef1NControl OWNER TO epsi;
CREATE INDEX TblWznmQTcoRef1NControl_jref ON TblWznmQTcoRef1NControl (jref);
CREATE INDEX TblWznmQTcoRef1NControl_jnum ON TblWznmQTcoRef1NControl (jnum);

CREATE TABLE TblWznmQTcoRef1NQuerymod(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQTcoRef1NQuerymod OWNER TO epsi;
CREATE INDEX TblWznmQTcoRef1NQuerymod_jref ON TblWznmQTcoRef1NQuerymod (jref);
CREATE INDEX TblWznmQTcoRef1NQuerymod_jnum ON TblWznmQTcoRef1NQuerymod (jnum);

CREATE TABLE TblWznmQUsgAAccess(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxWznmVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWznmWAccess INT
);
ALTER TABLE TblWznmQUsgAAccess OWNER TO epsi;
CREATE INDEX TblWznmQUsgAAccess_jref ON TblWznmQUsgAAccess (jref);
CREATE INDEX TblWznmQUsgAAccess_jnum ON TblWznmQUsgAAccess (jnum);

CREATE TABLE TblWznmQUsgList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50)
);
ALTER TABLE TblWznmQUsgList OWNER TO epsi;
CREATE INDEX TblWznmQUsgList_jref ON TblWznmQUsgList (jref);
CREATE INDEX TblWznmQUsgList_jnum ON TblWznmQUsgList (jnum);

CREATE TABLE TblWznmQUsgMNUser(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixWznmVUserlevel INT
);
ALTER TABLE TblWznmQUsgMNUser OWNER TO epsi;
CREATE INDEX TblWznmQUsgMNUser_jref ON TblWznmQUsgMNUser (jref);
CREATE INDEX TblWznmQUsgMNUser_jnum ON TblWznmQUsgMNUser (jnum);

CREATE TABLE TblWznmQUsr1NSession(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQUsr1NSession OWNER TO epsi;
CREATE INDEX TblWznmQUsr1NSession_jref ON TblWznmQUsr1NSession (jref);
CREATE INDEX TblWznmQUsr1NSession_jnum ON TblWznmQUsr1NSession (jnum);

CREATE TABLE TblWznmQUsrAAccess(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxWznmVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWznmWAccess INT
);
ALTER TABLE TblWznmQUsrAAccess OWNER TO epsi;
CREATE INDEX TblWznmQUsrAAccess_jref ON TblWznmQUsrAAccess (jref);
CREATE INDEX TblWznmQUsrAAccess_jnum ON TblWznmQUsrAAccess (jnum);

CREATE TABLE TblWznmQUsrList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	refWznmMPerson BIGINT,
	sref VARCHAR(50),
	refWznmMUsergroup BIGINT,
	ixVState INT,
	ixWznmVLocale INT,
	ixWznmVUserlevel INT
);
ALTER TABLE TblWznmQUsrList OWNER TO epsi;
CREATE INDEX TblWznmQUsrList_jref ON TblWznmQUsrList (jref);
CREATE INDEX TblWznmQUsrList_jnum ON TblWznmQUsrList (jnum);

CREATE TABLE TblWznmQUsrMNUsergroup(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixWznmVUserlevel INT
);
ALTER TABLE TblWznmQUsrMNUsergroup OWNER TO epsi;
CREATE INDEX TblWznmQUsrMNUsergroup_jref ON TblWznmQUsrMNUsergroup (jref);
CREATE INDEX TblWznmQUsrMNUsergroup_jnum ON TblWznmQUsrMNUsergroup (jnum);

CREATE TABLE TblWznmQVecATitle(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxVType INT,
	x2RefWznmMLocale BIGINT,
	Title VARCHAR(50)
);
ALTER TABLE TblWznmQVecATitle OWNER TO epsi;
CREATE INDEX TblWznmQVecATitle_jref ON TblWznmQVecATitle (jref);
CREATE INDEX TblWznmQVecATitle_jnum ON TblWznmQVecATitle (jnum);

CREATE TABLE TblWznmQVecFct1NTablecol(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVecFct1NTablecol OWNER TO epsi;
CREATE INDEX TblWznmQVecFct1NTablecol_jref ON TblWznmQVecFct1NTablecol (jref);
CREATE INDEX TblWznmQVecFct1NTablecol_jnum ON TblWznmQVecFct1NTablecol (jnum);

CREATE TABLE TblWznmQVecList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	refWznmMVersion BIGINT,
	hkIxVTbl INT,
	hkUref BIGINT,
	osrefWznmKTaggrp VARCHAR(50)
);
ALTER TABLE TblWznmQVecList OWNER TO epsi;
CREATE INDEX TblWznmQVecList_jref ON TblWznmQVecList (jref);
CREATE INDEX TblWznmQVecList_jnum ON TblWznmQVecList (jnum);

CREATE TABLE TblWznmQVecMNTable(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	refWznmMSubset BIGINT
);
ALTER TABLE TblWznmQVecMNTable OWNER TO epsi;
CREATE INDEX TblWznmQVecMNTable_jref ON TblWznmQVecMNTable (jref);
CREATE INDEX TblWznmQVecMNTable_jnum ON TblWznmQVecMNTable (jnum);

CREATE TABLE TblWznmQVecPst1NQuerymod(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVecPst1NQuerymod OWNER TO epsi;
CREATE INDEX TblWznmQVecPst1NQuerymod_jref ON TblWznmQVecPst1NQuerymod (jref);
CREATE INDEX TblWznmQVecPst1NQuerymod_jnum ON TblWznmQVecPst1NQuerymod (jnum);

CREATE TABLE TblWznmQVecRef1NPanel(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVecRef1NPanel OWNER TO epsi;
CREATE INDEX TblWznmQVecRef1NPanel_jref ON TblWznmQVecRef1NPanel (jref);
CREATE INDEX TblWznmQVecRef1NPanel_jnum ON TblWznmQVecRef1NPanel (jnum);

CREATE TABLE TblWznmQVecSrc1NFeed(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVecSrc1NFeed OWNER TO epsi;
CREATE INDEX TblWznmQVecSrc1NFeed_jref ON TblWznmQVecSrc1NFeed (jref);
CREATE INDEX TblWznmQVecSrc1NFeed_jnum ON TblWznmQVecSrc1NFeed (jnum);

CREATE TABLE TblWznmQVecVec1NVectoritem(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	vecNum INT
);
ALTER TABLE TblWznmQVecVec1NVectoritem OWNER TO epsi;
CREATE INDEX TblWznmQVecVec1NVectoritem_jref ON TblWznmQVecVec1NVectoritem (jref);
CREATE INDEX TblWznmQVecVec1NVectoritem_jnum ON TblWznmQVecVec1NVectoritem (jnum);

CREATE TABLE TblWznmQVer1NBlock(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVer1NBlock OWNER TO epsi;
CREATE INDEX TblWznmQVer1NBlock_jref ON TblWznmQVer1NBlock (jref);
CREATE INDEX TblWznmQVer1NBlock_jnum ON TblWznmQVer1NBlock (jnum);

CREATE TABLE TblWznmQVer1NCall(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVer1NCall OWNER TO epsi;
CREATE INDEX TblWznmQVer1NCall_jref ON TblWznmQVer1NCall (jref);
CREATE INDEX TblWznmQVer1NCall_jnum ON TblWznmQVer1NCall (jnum);

CREATE TABLE TblWznmQVer1NCapability(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVer1NCapability OWNER TO epsi;
CREATE INDEX TblWznmQVer1NCapability_jref ON TblWznmQVer1NCapability (jref);
CREATE INDEX TblWznmQVer1NCapability_jnum ON TblWznmQVer1NCapability (jnum);

CREATE TABLE TblWznmQVer1NComponent(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVer1NComponent OWNER TO epsi;
CREATE INDEX TblWznmQVer1NComponent_jref ON TblWznmQVer1NComponent (jref);
CREATE INDEX TblWznmQVer1NComponent_jnum ON TblWznmQVer1NComponent (jnum);

CREATE TABLE TblWznmQVer1NImpexpcplx(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVer1NImpexpcplx OWNER TO epsi;
CREATE INDEX TblWznmQVer1NImpexpcplx_jref ON TblWznmQVer1NImpexpcplx (jref);
CREATE INDEX TblWznmQVer1NImpexpcplx_jnum ON TblWznmQVer1NImpexpcplx (jnum);

CREATE TABLE TblWznmQVer1NJob(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVer1NJob OWNER TO epsi;
CREATE INDEX TblWznmQVer1NJob_jref ON TblWznmQVer1NJob (jref);
CREATE INDEX TblWznmQVer1NJob_jnum ON TblWznmQVer1NJob (jnum);

CREATE TABLE TblWznmQVer1NOppack(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVer1NOppack OWNER TO epsi;
CREATE INDEX TblWznmQVer1NOppack_jref ON TblWznmQVer1NOppack (jref);
CREATE INDEX TblWznmQVer1NOppack_jnum ON TblWznmQVer1NOppack (jnum);

CREATE TABLE TblWznmQVer1NPreset(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVer1NPreset OWNER TO epsi;
CREATE INDEX TblWznmQVer1NPreset_jref ON TblWznmQVer1NPreset (jref);
CREATE INDEX TblWznmQVer1NPreset_jnum ON TblWznmQVer1NPreset (jnum);

CREATE TABLE TblWznmQVer1NQuery(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVer1NQuery OWNER TO epsi;
CREATE INDEX TblWznmQVer1NQuery_jref ON TblWznmQVer1NQuery (jref);
CREATE INDEX TblWznmQVer1NQuery_jnum ON TblWznmQVer1NQuery (jnum);

CREATE TABLE TblWznmQVer1NRelation(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVer1NRelation OWNER TO epsi;
CREATE INDEX TblWznmQVer1NRelation_jref ON TblWznmQVer1NRelation (jref);
CREATE INDEX TblWznmQVer1NRelation_jnum ON TblWznmQVer1NRelation (jnum);

CREATE TABLE TblWznmQVer1NTable(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVer1NTable OWNER TO epsi;
CREATE INDEX TblWznmQVer1NTable_jref ON TblWznmQVer1NTable (jref);
CREATE INDEX TblWznmQVer1NTable_jnum ON TblWznmQVer1NTable (jnum);

CREATE TABLE TblWznmQVer1NVector(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVer1NVector OWNER TO epsi;
CREATE INDEX TblWznmQVer1NVector_jref ON TblWznmQVer1NVector (jref);
CREATE INDEX TblWznmQVer1NVector_jnum ON TblWznmQVer1NVector (jnum);

CREATE TABLE TblWznmQVerBvr1NVersion(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVerBvr1NVersion OWNER TO epsi;
CREATE INDEX TblWznmQVerBvr1NVersion_jref ON TblWznmQVerBvr1NVersion (jref);
CREATE INDEX TblWznmQVerBvr1NVersion_jnum ON TblWznmQVerBvr1NVersion (jnum);

CREATE TABLE TblWznmQVerList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	prjRefWznmMProject BIGINT,
	Major SMALLINT,
	Minor SMALLINT,
	Sub SMALLINT,
	bvrRefWznmMVersion BIGINT,
	refWznmMLocale BIGINT,
	ixVState INT,
	ixWDbmstype INT
);
ALTER TABLE TblWznmQVerList OWNER TO epsi;
CREATE INDEX TblWznmQVerList_jref ON TblWznmQVerList (jref);
CREATE INDEX TblWznmQVerList_jnum ON TblWznmQVerList (jnum);

CREATE TABLE TblWznmQVerMNLocale(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWznmQVerMNLocale OWNER TO epsi;
CREATE INDEX TblWznmQVerMNLocale_jref ON TblWznmQVerMNLocale (jref);
CREATE INDEX TblWznmQVerMNLocale_jnum ON TblWznmQVerMNLocale (jnum);

CREATE TABLE TblWznmQVerRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWznmQVerRef1NFile OWNER TO epsi;
CREATE INDEX TblWznmQVerRef1NFile_jref ON TblWznmQVerRef1NFile (jref);
CREATE INDEX TblWznmQVerRef1NFile_jnum ON TblWznmQVerRef1NFile (jnum);

CREATE TABLE TblWznmQVerVer1NApp(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	verNum INT
);
ALTER TABLE TblWznmQVerVer1NApp OWNER TO epsi;
CREATE INDEX TblWznmQVerVer1NApp_jref ON TblWznmQVerVer1NApp (jref);
CREATE INDEX TblWznmQVerVer1NApp_jnum ON TblWznmQVerVer1NApp (jnum);

CREATE TABLE TblWznmQVerVer1NError(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	verNum INT
);
ALTER TABLE TblWznmQVerVer1NError OWNER TO epsi;
CREATE INDEX TblWznmQVerVer1NError_jref ON TblWznmQVerVer1NError (jref);
CREATE INDEX TblWznmQVerVer1NError_jnum ON TblWznmQVerVer1NError (jnum);

CREATE TABLE TblWznmQVerVer1NModule(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	verNum INT
);
ALTER TABLE TblWznmQVerVer1NModule OWNER TO epsi;
CREATE INDEX TblWznmQVerVer1NModule_jref ON TblWznmQVerVer1NModule (jref);
CREATE INDEX TblWznmQVerVer1NModule_jnum ON TblWznmQVerVer1NModule (jnum);

CREATE TABLE TblWznmQVitList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(192),
	vecRefWznmMVector BIGINT
);
ALTER TABLE TblWznmQVitList OWNER TO epsi;
CREATE INDEX TblWznmQVitList_jref ON TblWznmQVitList (jref);
CREATE INDEX TblWznmQVitList_jnum ON TblWznmQVitList (jnum);

