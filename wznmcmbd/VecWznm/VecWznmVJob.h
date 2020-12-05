/**
	* \file VecWznmVJob.h
	* vector VecWznmVJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef VECWZNMVJOB_H
#define VECWZNMVJOB_H

#include <sbecore/Xmlio.h>

/**
	* VecWznmVJob
	*/
namespace VecWznmVJob {
	const Sbecore::uint CRDWZNMAPP = 1;
	const Sbecore::uint CRDWZNMBLK = 2;
	const Sbecore::uint CRDWZNMCAL = 3;
	const Sbecore::uint CRDWZNMCAP = 4;
	const Sbecore::uint CRDWZNMCAR = 5;
	const Sbecore::uint CRDWZNMCHK = 6;
	const Sbecore::uint CRDWZNMCMP = 7;
	const Sbecore::uint CRDWZNMCON = 8;
	const Sbecore::uint CRDWZNMCTP = 9;
	const Sbecore::uint CRDWZNMDLG = 10;
	const Sbecore::uint CRDWZNMERR = 11;
	const Sbecore::uint CRDWZNMEVT = 12;
	const Sbecore::uint CRDWZNMFIL = 13;
	const Sbecore::uint CRDWZNMIEL = 14;
	const Sbecore::uint CRDWZNMIEX = 15;
	const Sbecore::uint CRDWZNMIME = 16;
	const Sbecore::uint CRDWZNMJOB = 17;
	const Sbecore::uint CRDWZNMLIB = 18;
	const Sbecore::uint CRDWZNMLOC = 19;
	const Sbecore::uint CRDWZNMMCH = 20;
	const Sbecore::uint CRDWZNMMDL = 21;
	const Sbecore::uint CRDWZNMMTD = 22;
	const Sbecore::uint CRDWZNMNAV = 23;
	const Sbecore::uint CRDWZNMOPK = 24;
	const Sbecore::uint CRDWZNMOPX = 25;
	const Sbecore::uint CRDWZNMPNL = 26;
	const Sbecore::uint CRDWZNMPRJ = 27;
	const Sbecore::uint CRDWZNMPRS = 28;
	const Sbecore::uint CRDWZNMPST = 29;
	const Sbecore::uint CRDWZNMQCO = 30;
	const Sbecore::uint CRDWZNMQMD = 31;
	const Sbecore::uint CRDWZNMQRY = 32;
	const Sbecore::uint CRDWZNMREL = 33;
	const Sbecore::uint CRDWZNMRLS = 34;
	const Sbecore::uint CRDWZNMRTJ = 35;
	const Sbecore::uint CRDWZNMSBS = 36;
	const Sbecore::uint CRDWZNMSEQ = 37;
	const Sbecore::uint CRDWZNMSGE = 38;
	const Sbecore::uint CRDWZNMSTB = 39;
	const Sbecore::uint CRDWZNMSTE = 40;
	const Sbecore::uint CRDWZNMTAG = 41;
	const Sbecore::uint CRDWZNMTBL = 42;
	const Sbecore::uint CRDWZNMTCO = 43;
	const Sbecore::uint CRDWZNMUSG = 44;
	const Sbecore::uint CRDWZNMUSR = 45;
	const Sbecore::uint CRDWZNMUTL = 46;
	const Sbecore::uint CRDWZNMVEC = 47;
	const Sbecore::uint CRDWZNMVER = 48;
	const Sbecore::uint CRDWZNMVIT = 49;
	const Sbecore::uint DLGWZNMAPPIMPSTR = 50;
	const Sbecore::uint DLGWZNMAPPNEW = 51;
	const Sbecore::uint DLGWZNMAPPWRITE = 52;
	const Sbecore::uint DLGWZNMFILDOWNLOAD = 53;
	const Sbecore::uint DLGWZNMFILNEW = 54;
	const Sbecore::uint DLGWZNMMCHWRINISCR = 55;
	const Sbecore::uint DLGWZNMNAVLOAINI = 56;
	const Sbecore::uint DLGWZNMNAVMNGLIC = 57;
	const Sbecore::uint DLGWZNMPRJIMPEX = 58;
	const Sbecore::uint DLGWZNMPRJNEW = 59;
	const Sbecore::uint DLGWZNMRLSFINREPTR = 60;
	const Sbecore::uint DLGWZNMRLSSTAREPTR = 61;
	const Sbecore::uint DLGWZNMRLSWRITE = 62;
	const Sbecore::uint DLGWZNMUSRMNGKEYPAIR = 63;
	const Sbecore::uint DLGWZNMUTLEXTRIP = 64;
	const Sbecore::uint DLGWZNMUTLMRGIP = 65;
	const Sbecore::uint DLGWZNMVERBSCUI = 66;
	const Sbecore::uint DLGWZNMVERCUSTJOB = 67;
	const Sbecore::uint DLGWZNMVERCUSTJTR = 68;
	const Sbecore::uint DLGWZNMVERCUSTUI = 69;
	const Sbecore::uint DLGWZNMVERDBSTR = 70;
	const Sbecore::uint DLGWZNMVERDEPLOY = 71;
	const Sbecore::uint DLGWZNMVERFINMOD = 72;
	const Sbecore::uint DLGWZNMVERGENJTR = 73;
	const Sbecore::uint DLGWZNMVERGENUI = 74;
	const Sbecore::uint DLGWZNMVERGLOBAL = 75;
	const Sbecore::uint DLGWZNMVERIMPEXP = 76;
	const Sbecore::uint DLGWZNMVERNEW = 77;
	const Sbecore::uint DLGWZNMVEROPPACK = 78;
	const Sbecore::uint DLGWZNMVERWRINIMDL = 79;
	const Sbecore::uint JOBWZNMIEXAPP = 80;
	const Sbecore::uint JOBWZNMIEXBUI = 81;
	const Sbecore::uint JOBWZNMIEXDBS = 82;
	const Sbecore::uint JOBWZNMIEXDPL = 83;
	const Sbecore::uint JOBWZNMIEXGBL = 84;
	const Sbecore::uint JOBWZNMIEXIEX = 85;
	const Sbecore::uint JOBWZNMIEXINI = 86;
	const Sbecore::uint JOBWZNMIEXJOB = 87;
	const Sbecore::uint JOBWZNMIEXJTR = 88;
	const Sbecore::uint JOBWZNMIEXOPK = 89;
	const Sbecore::uint JOBWZNMIEXPRJ = 90;
	const Sbecore::uint JOBWZNMIEXUIX = 91;
	const Sbecore::uint JOBWZNMLICENSE = 92;
	const Sbecore::uint PNLWZNMAPP1NEVENT = 93;
	const Sbecore::uint PNLWZNMAPP1NRTJOB = 94;
	const Sbecore::uint PNLWZNMAPPAPP1NSEQUENCE = 95;
	const Sbecore::uint PNLWZNMAPPDETAIL = 96;
	const Sbecore::uint PNLWZNMAPPHEADBAR = 97;
	const Sbecore::uint PNLWZNMAPPLIST = 98;
	const Sbecore::uint PNLWZNMAPPREC = 99;
	const Sbecore::uint PNLWZNMAPPREF1NFILE = 100;
	const Sbecore::uint PNLWZNMBLK1NRTDPCH = 101;
	const Sbecore::uint PNLWZNMBLKAITEM = 102;
	const Sbecore::uint PNLWZNMBLKDETAIL = 103;
	const Sbecore::uint PNLWZNMBLKHEADBAR = 104;
	const Sbecore::uint PNLWZNMBLKLIST = 105;
	const Sbecore::uint PNLWZNMBLKREC = 106;
	const Sbecore::uint PNLWZNMBLKREF1NRTBLOCK = 107;
	const Sbecore::uint PNLWZNMCAL1NSENSITIVITY = 108;
	const Sbecore::uint PNLWZNMCALDETAIL = 109;
	const Sbecore::uint PNLWZNMCALHEADBAR = 110;
	const Sbecore::uint PNLWZNMCALLIST = 111;
	const Sbecore::uint PNLWZNMCALMNSTUB = 112;
	const Sbecore::uint PNLWZNMCALREC = 113;
	const Sbecore::uint PNLWZNMCAPAPAR = 114;
	const Sbecore::uint PNLWZNMCAPDETAIL = 115;
	const Sbecore::uint PNLWZNMCAPHEADBAR = 116;
	const Sbecore::uint PNLWZNMCAPLIST = 117;
	const Sbecore::uint PNLWZNMCAPREC = 118;
	const Sbecore::uint PNLWZNMCAR1NDIALOG = 119;
	const Sbecore::uint PNLWZNMCARCAR1NPANEL = 120;
	const Sbecore::uint PNLWZNMCARDETAIL = 121;
	const Sbecore::uint PNLWZNMCARHEADBAR = 122;
	const Sbecore::uint PNLWZNMCARHK1NCONTROL = 123;
	const Sbecore::uint PNLWZNMCARLIST = 124;
	const Sbecore::uint PNLWZNMCARREC = 125;
	const Sbecore::uint PNLWZNMCHKDETAIL = 126;
	const Sbecore::uint PNLWZNMCHKHEADBAR = 127;
	const Sbecore::uint PNLWZNMCHKLIST = 128;
	const Sbecore::uint PNLWZNMCHKREC = 129;
	const Sbecore::uint PNLWZNMCHKREF1NCALL = 130;
	const Sbecore::uint PNLWZNMCMP1NRELEASE = 131;
	const Sbecore::uint PNLWZNMCMPDETAIL = 132;
	const Sbecore::uint PNLWZNMCMPHEADBAR = 133;
	const Sbecore::uint PNLWZNMCMPLIST = 134;
	const Sbecore::uint PNLWZNMCMPMNLIBRARY = 135;
	const Sbecore::uint PNLWZNMCMPMNOPPACK = 136;
	const Sbecore::uint PNLWZNMCMPREC = 137;
	const Sbecore::uint PNLWZNMCONAPAR = 138;
	const Sbecore::uint PNLWZNMCONDETAIL = 139;
	const Sbecore::uint PNLWZNMCONFEDREF1NRTBLOCK = 140;
	const Sbecore::uint PNLWZNMCONHEADBAR = 141;
	const Sbecore::uint PNLWZNMCONLIST = 142;
	const Sbecore::uint PNLWZNMCONREC = 143;
	const Sbecore::uint PNLWZNMCONSUP1NCONTROL = 144;
	const Sbecore::uint PNLWZNMCTP1NTAG = 145;
	const Sbecore::uint PNLWZNMCTPAPAR = 146;
	const Sbecore::uint PNLWZNMCTPDETAIL = 147;
	const Sbecore::uint PNLWZNMCTPHEADBAR = 148;
	const Sbecore::uint PNLWZNMCTPKKEY = 149;
	const Sbecore::uint PNLWZNMCTPKPARKEY = 150;
	const Sbecore::uint PNLWZNMCTPLIST = 151;
	const Sbecore::uint PNLWZNMCTPREC = 152;
	const Sbecore::uint PNLWZNMCTPTPL1NCAPABILITY = 153;
	const Sbecore::uint PNLWZNMDLGDETAIL = 154;
	const Sbecore::uint PNLWZNMDLGHEADBAR = 155;
	const Sbecore::uint PNLWZNMDLGHK1NCONTROL = 156;
	const Sbecore::uint PNLWZNMDLGLIST = 157;
	const Sbecore::uint PNLWZNMDLGMNQUERY = 158;
	const Sbecore::uint PNLWZNMDLGREC = 159;
	const Sbecore::uint PNLWZNMDLGREF1NCONTROL = 160;
	const Sbecore::uint PNLWZNMERRDETAIL = 161;
	const Sbecore::uint PNLWZNMERRHEADBAR = 162;
	const Sbecore::uint PNLWZNMERRLIST = 163;
	const Sbecore::uint PNLWZNMERRREC = 164;
	const Sbecore::uint PNLWZNMEVTDETAIL = 165;
	const Sbecore::uint PNLWZNMEVTHEADBAR = 166;
	const Sbecore::uint PNLWZNMEVTLIST = 167;
	const Sbecore::uint PNLWZNMEVTREC = 168;
	const Sbecore::uint PNLWZNMFILDETAIL = 169;
	const Sbecore::uint PNLWZNMFILHEADBAR = 170;
	const Sbecore::uint PNLWZNMFILLIST = 171;
	const Sbecore::uint PNLWZNMFILREC = 172;
	const Sbecore::uint PNLWZNMIELDETAIL = 173;
	const Sbecore::uint PNLWZNMIELHEADBAR = 174;
	const Sbecore::uint PNLWZNMIELLIST = 175;
	const Sbecore::uint PNLWZNMIELREC = 176;
	const Sbecore::uint PNLWZNMIEX1NIMPEXP = 177;
	const Sbecore::uint PNLWZNMIEXDETAIL = 178;
	const Sbecore::uint PNLWZNMIEXHEADBAR = 179;
	const Sbecore::uint PNLWZNMIEXHK1NVECTOR = 180;
	const Sbecore::uint PNLWZNMIEXLIST = 181;
	const Sbecore::uint PNLWZNMIEXREC = 182;
	const Sbecore::uint PNLWZNMIEXREF1NDIALOG = 183;
	const Sbecore::uint PNLWZNMIMEDETAIL = 184;
	const Sbecore::uint PNLWZNMIMEHEADBAR = 185;
	const Sbecore::uint PNLWZNMIMEHK1NVECTOR = 186;
	const Sbecore::uint PNLWZNMIMEIME1NIMPEXPCOL = 187;
	const Sbecore::uint PNLWZNMIMELIST = 188;
	const Sbecore::uint PNLWZNMIMEREC = 189;
	const Sbecore::uint PNLWZNMIMESUP1NIMPEXP = 190;
	const Sbecore::uint PNLWZNMJOB1NMETHOD = 191;
	const Sbecore::uint PNLWZNMJOB1NRTJOB = 192;
	const Sbecore::uint PNLWZNMJOB1NSENSITIVITY = 193;
	const Sbecore::uint PNLWZNMJOBACMD = 194;
	const Sbecore::uint PNLWZNMJOBAVAR = 195;
	const Sbecore::uint PNLWZNMJOBDETAIL = 196;
	const Sbecore::uint PNLWZNMJOBHEADBAR = 197;
	const Sbecore::uint PNLWZNMJOBHK1NVECTOR = 198;
	const Sbecore::uint PNLWZNMJOBJOB1NSTAGE = 199;
	const Sbecore::uint PNLWZNMJOBLIST = 200;
	const Sbecore::uint PNLWZNMJOBMNOP = 201;
	const Sbecore::uint PNLWZNMJOBMNOPPACK = 202;
	const Sbecore::uint PNLWZNMJOBREC = 203;
	const Sbecore::uint PNLWZNMJOBREF1NBLOCK = 204;
	const Sbecore::uint PNLWZNMJOBSUBMNJOB = 205;
	const Sbecore::uint PNLWZNMJOBSUPMNJOB = 206;
	const Sbecore::uint PNLWZNMLIBAMAKEFILE = 207;
	const Sbecore::uint PNLWZNMLIBAPKGLIST = 208;
	const Sbecore::uint PNLWZNMLIBDETAIL = 209;
	const Sbecore::uint PNLWZNMLIBHEADBAR = 210;
	const Sbecore::uint PNLWZNMLIBLIST = 211;
	const Sbecore::uint PNLWZNMLIBMNCOMPONENT = 212;
	const Sbecore::uint PNLWZNMLIBMNOPPACK = 213;
	const Sbecore::uint PNLWZNMLIBREC = 214;
	const Sbecore::uint PNLWZNMLIBREF1NFILE = 215;
	const Sbecore::uint PNLWZNMLOCDETAIL = 216;
	const Sbecore::uint PNLWZNMLOCHEADBAR = 217;
	const Sbecore::uint PNLWZNMLOCLIST = 218;
	const Sbecore::uint PNLWZNMLOCMNVERSION = 219;
	const Sbecore::uint PNLWZNMLOCREC = 220;
	const Sbecore::uint PNLWZNMMCH1NRELEASE = 221;
	const Sbecore::uint PNLWZNMMCHAMAKEFILE = 222;
	const Sbecore::uint PNLWZNMMCHAPAR = 223;
	const Sbecore::uint PNLWZNMMCHDETAIL = 224;
	const Sbecore::uint PNLWZNMMCHHEADBAR = 225;
	const Sbecore::uint PNLWZNMMCHLIST = 226;
	const Sbecore::uint PNLWZNMMCHREC = 227;
	const Sbecore::uint PNLWZNMMCHSUP1NMACHINE = 228;
	const Sbecore::uint PNLWZNMMDLDETAIL = 229;
	const Sbecore::uint PNLWZNMMDLHEADBAR = 230;
	const Sbecore::uint PNLWZNMMDLLIST = 231;
	const Sbecore::uint PNLWZNMMDLMDL1NCARD = 232;
	const Sbecore::uint PNLWZNMMDLREC = 233;
	const Sbecore::uint PNLWZNMMDLREF1NPANEL = 234;
	const Sbecore::uint PNLWZNMMTDAINVPAR = 235;
	const Sbecore::uint PNLWZNMMTDARETPAR = 236;
	const Sbecore::uint PNLWZNMMTDDETAIL = 237;
	const Sbecore::uint PNLWZNMMTDHEADBAR = 238;
	const Sbecore::uint PNLWZNMMTDLIST = 239;
	const Sbecore::uint PNLWZNMMTDREC = 240;
	const Sbecore::uint PNLWZNMNAVADMIN = 241;
	const Sbecore::uint PNLWZNMNAVAPPDEV = 242;
	const Sbecore::uint PNLWZNMNAVAUXFCT = 243;
	const Sbecore::uint PNLWZNMNAVCOMP = 244;
	const Sbecore::uint PNLWZNMNAVDBSTR = 245;
	const Sbecore::uint PNLWZNMNAVDEPLOY = 246;
	const Sbecore::uint PNLWZNMNAVGLOBAL = 247;
	const Sbecore::uint PNLWZNMNAVHEADBAR = 248;
	const Sbecore::uint PNLWZNMNAVJOB = 249;
	const Sbecore::uint PNLWZNMNAVPRE = 250;
	const Sbecore::uint PNLWZNMNAVPROJECT = 251;
	const Sbecore::uint PNLWZNMNAVUIX = 252;
	const Sbecore::uint PNLWZNMOPK1NOP = 253;
	const Sbecore::uint PNLWZNMOPKAINVARG = 254;
	const Sbecore::uint PNLWZNMOPKARETVAL = 255;
	const Sbecore::uint PNLWZNMOPKDETAIL = 256;
	const Sbecore::uint PNLWZNMOPKHEADBAR = 257;
	const Sbecore::uint PNLWZNMOPKLIST = 258;
	const Sbecore::uint PNLWZNMOPKMNCOMPONENT = 259;
	const Sbecore::uint PNLWZNMOPKMNJOB = 260;
	const Sbecore::uint PNLWZNMOPKMNLIBRARY = 261;
	const Sbecore::uint PNLWZNMOPKREC = 262;
	const Sbecore::uint PNLWZNMOPKREF1NBLOCK = 263;
	const Sbecore::uint PNLWZNMOPKSQKMNSTUB = 264;
	const Sbecore::uint PNLWZNMOPXAINVARG = 265;
	const Sbecore::uint PNLWZNMOPXARETVAL = 266;
	const Sbecore::uint PNLWZNMOPXDETAIL = 267;
	const Sbecore::uint PNLWZNMOPXHEADBAR = 268;
	const Sbecore::uint PNLWZNMOPXLIST = 269;
	const Sbecore::uint PNLWZNMOPXMNJOB = 270;
	const Sbecore::uint PNLWZNMOPXREC = 271;
	const Sbecore::uint PNLWZNMOPXREF1NBLOCK = 272;
	const Sbecore::uint PNLWZNMOPXSQKMNSTUB = 273;
	const Sbecore::uint PNLWZNMPNLDETAIL = 274;
	const Sbecore::uint PNLWZNMPNLHEADBAR = 275;
	const Sbecore::uint PNLWZNMPNLHK1NCONTROL = 276;
	const Sbecore::uint PNLWZNMPNLLIST = 277;
	const Sbecore::uint PNLWZNMPNLMNQUERY = 278;
	const Sbecore::uint PNLWZNMPNLREC = 279;
	const Sbecore::uint PNLWZNMPRJ1NVERSION = 280;
	const Sbecore::uint PNLWZNMPRJDETAIL = 281;
	const Sbecore::uint PNLWZNMPRJHEADBAR = 282;
	const Sbecore::uint PNLWZNMPRJLIST = 283;
	const Sbecore::uint PNLWZNMPRJMNPERSON = 284;
	const Sbecore::uint PNLWZNMPRJREC = 285;
	const Sbecore::uint PNLWZNMPRSADETAIL = 286;
	const Sbecore::uint PNLWZNMPRSDETAIL = 287;
	const Sbecore::uint PNLWZNMPRSHEADBAR = 288;
	const Sbecore::uint PNLWZNMPRSLIST = 289;
	const Sbecore::uint PNLWZNMPRSMNPROJECT = 290;
	const Sbecore::uint PNLWZNMPRSREC = 291;
	const Sbecore::uint PNLWZNMPST1NQUERYMOD = 292;
	const Sbecore::uint PNLWZNMPSTDETAIL = 293;
	const Sbecore::uint PNLWZNMPSTHEADBAR = 294;
	const Sbecore::uint PNLWZNMPSTLIST = 295;
	const Sbecore::uint PNLWZNMPSTREC = 296;
	const Sbecore::uint PNLWZNMQCODETAIL = 297;
	const Sbecore::uint PNLWZNMQCOHEADBAR = 298;
	const Sbecore::uint PNLWZNMQCOLIST = 299;
	const Sbecore::uint PNLWZNMQCOREC = 300;
	const Sbecore::uint PNLWZNMQCOREF1NCONTROL = 301;
	const Sbecore::uint PNLWZNMQMDDETAIL = 302;
	const Sbecore::uint PNLWZNMQMDHEADBAR = 303;
	const Sbecore::uint PNLWZNMQMDLIST = 304;
	const Sbecore::uint PNLWZNMQMDREC = 305;
	const Sbecore::uint PNLWZNMQRY1NQUERYMOD = 306;
	const Sbecore::uint PNLWZNMQRYACLAUSE = 307;
	const Sbecore::uint PNLWZNMQRYAORDER = 308;
	const Sbecore::uint PNLWZNMQRYDETAIL = 309;
	const Sbecore::uint PNLWZNMQRYHEADBAR = 310;
	const Sbecore::uint PNLWZNMQRYLIST = 311;
	const Sbecore::uint PNLWZNMQRYMNDIALOG = 312;
	const Sbecore::uint PNLWZNMQRYMNPANEL = 313;
	const Sbecore::uint PNLWZNMQRYMNTABLE = 314;
	const Sbecore::uint PNLWZNMQRYQRY1NQUERYCOL = 315;
	const Sbecore::uint PNLWZNMQRYREC = 316;
	const Sbecore::uint PNLWZNMQRYSUP1NQUERY = 317;
	const Sbecore::uint PNLWZNMREL1NTABLECOL = 318;
	const Sbecore::uint PNLWZNMRELATITLE = 319;
	const Sbecore::uint PNLWZNMRELDETAIL = 320;
	const Sbecore::uint PNLWZNMRELHEADBAR = 321;
	const Sbecore::uint PNLWZNMRELLIST = 322;
	const Sbecore::uint PNLWZNMRELREC = 323;
	const Sbecore::uint PNLWZNMRELREF1NCONTROL = 324;
	const Sbecore::uint PNLWZNMRELREF1NDIALOG = 325;
	const Sbecore::uint PNLWZNMRELREF1NPANEL = 326;
	const Sbecore::uint PNLWZNMRELSUP1NRELATION = 327;
	const Sbecore::uint PNLWZNMRLSDETAIL = 328;
	const Sbecore::uint PNLWZNMRLSHEADBAR = 329;
	const Sbecore::uint PNLWZNMRLSLIST = 330;
	const Sbecore::uint PNLWZNMRLSREC = 331;
	const Sbecore::uint PNLWZNMRTJ1NRTBLOCK = 332;
	const Sbecore::uint PNLWZNMRTJ1NRTDPCH = 333;
	const Sbecore::uint PNLWZNMRTJDETAIL = 334;
	const Sbecore::uint PNLWZNMRTJHEADBAR = 335;
	const Sbecore::uint PNLWZNMRTJLIST = 336;
	const Sbecore::uint PNLWZNMRTJREC = 337;
	const Sbecore::uint PNLWZNMRTJSUP1NRTJOB = 338;
	const Sbecore::uint PNLWZNMSBS1NSTUB = 339;
	const Sbecore::uint PNLWZNMSBS1NTABLECOL = 340;
	const Sbecore::uint PNLWZNMSBSASBMNSUBSET = 341;
	const Sbecore::uint PNLWZNMSBSATITLE = 342;
	const Sbecore::uint PNLWZNMSBSBSBMNSUBSET = 343;
	const Sbecore::uint PNLWZNMSBSDETAIL = 344;
	const Sbecore::uint PNLWZNMSBSFRS1NRELATION = 345;
	const Sbecore::uint PNLWZNMSBSHEADBAR = 346;
	const Sbecore::uint PNLWZNMSBSLIST = 347;
	const Sbecore::uint PNLWZNMSBSPST1NQUERYMOD = 348;
	const Sbecore::uint PNLWZNMSBSREC = 349;
	const Sbecore::uint PNLWZNMSBSTOS1NRELATION = 350;
	const Sbecore::uint PNLWZNMSEQDETAIL = 351;
	const Sbecore::uint PNLWZNMSEQHEADBAR = 352;
	const Sbecore::uint PNLWZNMSEQLIST = 353;
	const Sbecore::uint PNLWZNMSEQREC = 354;
	const Sbecore::uint PNLWZNMSEQSEQ1NSTATE = 355;
	const Sbecore::uint PNLWZNMSGE1NSENSITIVITY = 356;
	const Sbecore::uint PNLWZNMSGEDETAIL = 357;
	const Sbecore::uint PNLWZNMSGEHEADBAR = 358;
	const Sbecore::uint PNLWZNMSGELIST = 359;
	const Sbecore::uint PNLWZNMSGEREC = 360;
	const Sbecore::uint PNLWZNMSGESQKMNSTUB = 361;
	const Sbecore::uint PNLWZNMSTBDETAIL = 362;
	const Sbecore::uint PNLWZNMSTBHEADBAR = 363;
	const Sbecore::uint PNLWZNMSTBLIST = 364;
	const Sbecore::uint PNLWZNMSTBMNCALL = 365;
	const Sbecore::uint PNLWZNMSTBMNSQUAWK = 366;
	const Sbecore::uint PNLWZNMSTBREC = 367;
	const Sbecore::uint PNLWZNMSTBSUBMNSTUB = 368;
	const Sbecore::uint PNLWZNMSTBSUPMNSTUB = 369;
	const Sbecore::uint PNLWZNMSTEAACTION = 370;
	const Sbecore::uint PNLWZNMSTEATRIG = 371;
	const Sbecore::uint PNLWZNMSTEDETAIL = 372;
	const Sbecore::uint PNLWZNMSTEHEADBAR = 373;
	const Sbecore::uint PNLWZNMSTELIST = 374;
	const Sbecore::uint PNLWZNMSTEREC = 375;
	const Sbecore::uint PNLWZNMTAGDETAIL = 376;
	const Sbecore::uint PNLWZNMTAGHEADBAR = 377;
	const Sbecore::uint PNLWZNMTAGLIST = 378;
	const Sbecore::uint PNLWZNMTAGREC = 379;
	const Sbecore::uint PNLWZNMTBL1NCHECK = 380;
	const Sbecore::uint PNLWZNMTBL1NIMPEXP = 381;
	const Sbecore::uint PNLWZNMTBL1NSTUB = 382;
	const Sbecore::uint PNLWZNMTBL1NSUBSET = 383;
	const Sbecore::uint PNLWZNMTBLALOADFCT = 384;
	const Sbecore::uint PNLWZNMTBLATITLE = 385;
	const Sbecore::uint PNLWZNMTBLDETAIL = 386;
	const Sbecore::uint PNLWZNMTBLFCT1NTABLECOL = 387;
	const Sbecore::uint PNLWZNMTBLFR1NRELATION = 388;
	const Sbecore::uint PNLWZNMTBLHEADBAR = 389;
	const Sbecore::uint PNLWZNMTBLHK1NVECTOR = 390;
	const Sbecore::uint PNLWZNMTBLLIST = 391;
	const Sbecore::uint PNLWZNMTBLMNQUERY = 392;
	const Sbecore::uint PNLWZNMTBLMNVECTOR = 393;
	const Sbecore::uint PNLWZNMTBLPST1NQUERYMOD = 394;
	const Sbecore::uint PNLWZNMTBLREC = 395;
	const Sbecore::uint PNLWZNMTBLREF1NCALL = 396;
	const Sbecore::uint PNLWZNMTBLREF1NDIALOG = 397;
	const Sbecore::uint PNLWZNMTBLREF1NPANEL = 398;
	const Sbecore::uint PNLWZNMTBLREF1NQUERYMOD = 399;
	const Sbecore::uint PNLWZNMTBLREF1NRTBLOCK = 400;
	const Sbecore::uint PNLWZNMTBLSRC1NFEED = 401;
	const Sbecore::uint PNLWZNMTBLTBL1NTABLECOL = 402;
	const Sbecore::uint PNLWZNMTBLTO1NRELATION = 403;
	const Sbecore::uint PNLWZNMTCO1NCHECK = 404;
	const Sbecore::uint PNLWZNMTCO1NIMPEXPCOL = 405;
	const Sbecore::uint PNLWZNMTCO1NQUERYCOL = 406;
	const Sbecore::uint PNLWZNMTCOATITLE = 407;
	const Sbecore::uint PNLWZNMTCODETAIL = 408;
	const Sbecore::uint PNLWZNMTCOHEADBAR = 409;
	const Sbecore::uint PNLWZNMTCOLIST = 410;
	const Sbecore::uint PNLWZNMTCOREC = 411;
	const Sbecore::uint PNLWZNMTCOREF1NCONTROL = 412;
	const Sbecore::uint PNLWZNMTCOREF1NQUERYMOD = 413;
	const Sbecore::uint PNLWZNMUSGAACCESS = 414;
	const Sbecore::uint PNLWZNMUSGDETAIL = 415;
	const Sbecore::uint PNLWZNMUSGHEADBAR = 416;
	const Sbecore::uint PNLWZNMUSGLIST = 417;
	const Sbecore::uint PNLWZNMUSGMNUSER = 418;
	const Sbecore::uint PNLWZNMUSGREC = 419;
	const Sbecore::uint PNLWZNMUSR1NSESSION = 420;
	const Sbecore::uint PNLWZNMUSRAACCESS = 421;
	const Sbecore::uint PNLWZNMUSRDETAIL = 422;
	const Sbecore::uint PNLWZNMUSRHEADBAR = 423;
	const Sbecore::uint PNLWZNMUSRLIST = 424;
	const Sbecore::uint PNLWZNMUSRMNUSERGROUP = 425;
	const Sbecore::uint PNLWZNMUSRREC = 426;
	const Sbecore::uint PNLWZNMUTLHEADBAR = 427;
	const Sbecore::uint PNLWZNMVECATITLE = 428;
	const Sbecore::uint PNLWZNMVECDETAIL = 429;
	const Sbecore::uint PNLWZNMVECFCT1NTABLECOL = 430;
	const Sbecore::uint PNLWZNMVECHEADBAR = 431;
	const Sbecore::uint PNLWZNMVECLIST = 432;
	const Sbecore::uint PNLWZNMVECMNTABLE = 433;
	const Sbecore::uint PNLWZNMVECPST1NQUERYMOD = 434;
	const Sbecore::uint PNLWZNMVECREC = 435;
	const Sbecore::uint PNLWZNMVECREF1NPANEL = 436;
	const Sbecore::uint PNLWZNMVECSRC1NFEED = 437;
	const Sbecore::uint PNLWZNMVECVEC1NVECTORITEM = 438;
	const Sbecore::uint PNLWZNMVER1NBLOCK = 439;
	const Sbecore::uint PNLWZNMVER1NCALL = 440;
	const Sbecore::uint PNLWZNMVER1NCAPABILITY = 441;
	const Sbecore::uint PNLWZNMVER1NCOMPONENT = 442;
	const Sbecore::uint PNLWZNMVER1NIMPEXPCPLX = 443;
	const Sbecore::uint PNLWZNMVER1NJOB = 444;
	const Sbecore::uint PNLWZNMVER1NOPPACK = 445;
	const Sbecore::uint PNLWZNMVER1NPRESET = 446;
	const Sbecore::uint PNLWZNMVER1NQUERY = 447;
	const Sbecore::uint PNLWZNMVER1NRELATION = 448;
	const Sbecore::uint PNLWZNMVER1NTABLE = 449;
	const Sbecore::uint PNLWZNMVER1NVECTOR = 450;
	const Sbecore::uint PNLWZNMVERBVR1NVERSION = 451;
	const Sbecore::uint PNLWZNMVERDETAIL = 452;
	const Sbecore::uint PNLWZNMVERHEADBAR = 453;
	const Sbecore::uint PNLWZNMVERLIST = 454;
	const Sbecore::uint PNLWZNMVERMNLOCALE = 455;
	const Sbecore::uint PNLWZNMVERREC = 456;
	const Sbecore::uint PNLWZNMVERREF1NFILE = 457;
	const Sbecore::uint PNLWZNMVERVER1NAPP = 458;
	const Sbecore::uint PNLWZNMVERVER1NERROR = 459;
	const Sbecore::uint PNLWZNMVERVER1NMODULE = 460;
	const Sbecore::uint PNLWZNMVITDETAIL = 461;
	const Sbecore::uint PNLWZNMVITHEADBAR = 462;
	const Sbecore::uint PNLWZNMVITLIST = 463;
	const Sbecore::uint PNLWZNMVITREC = 464;
	const Sbecore::uint QRYWZNMAPP1NEVENT = 465;
	const Sbecore::uint QRYWZNMAPP1NRTJOB = 466;
	const Sbecore::uint QRYWZNMAPPAPP1NSEQUENCE = 467;
	const Sbecore::uint QRYWZNMAPPLIST = 468;
	const Sbecore::uint QRYWZNMAPPREF1NFILE = 469;
	const Sbecore::uint QRYWZNMBLK1NRTDPCH = 470;
	const Sbecore::uint QRYWZNMBLKAITEM = 471;
	const Sbecore::uint QRYWZNMBLKLIST = 472;
	const Sbecore::uint QRYWZNMBLKREF1NRTBLOCK = 473;
	const Sbecore::uint QRYWZNMCAL1NSENSITIVITY = 474;
	const Sbecore::uint QRYWZNMCALLIST = 475;
	const Sbecore::uint QRYWZNMCALMNSTUB = 476;
	const Sbecore::uint QRYWZNMCAPAPAR = 477;
	const Sbecore::uint QRYWZNMCAPLIST = 478;
	const Sbecore::uint QRYWZNMCAR1NDIALOG = 479;
	const Sbecore::uint QRYWZNMCARCAR1NPANEL = 480;
	const Sbecore::uint QRYWZNMCARHK1NCONTROL = 481;
	const Sbecore::uint QRYWZNMCARLIST = 482;
	const Sbecore::uint QRYWZNMCHKLIST = 483;
	const Sbecore::uint QRYWZNMCHKREF1NCALL = 484;
	const Sbecore::uint QRYWZNMCMP1NRELEASE = 485;
	const Sbecore::uint QRYWZNMCMPLIST = 486;
	const Sbecore::uint QRYWZNMCMPMNLIBRARY = 487;
	const Sbecore::uint QRYWZNMCMPMNOPPACK = 488;
	const Sbecore::uint QRYWZNMCONAPAR = 489;
	const Sbecore::uint QRYWZNMCONFEDREF1NRTBLOCK = 490;
	const Sbecore::uint QRYWZNMCONLIST = 491;
	const Sbecore::uint QRYWZNMCONSUP1NCONTROL = 492;
	const Sbecore::uint QRYWZNMCTP1NTAG = 493;
	const Sbecore::uint QRYWZNMCTPAPAR = 494;
	const Sbecore::uint QRYWZNMCTPKKEY = 495;
	const Sbecore::uint QRYWZNMCTPKPARKEY = 496;
	const Sbecore::uint QRYWZNMCTPLIST = 497;
	const Sbecore::uint QRYWZNMCTPTPL1NCAPABILITY = 498;
	const Sbecore::uint QRYWZNMDLGHK1NCONTROL = 499;
	const Sbecore::uint QRYWZNMDLGLIST = 500;
	const Sbecore::uint QRYWZNMDLGMNQUERY = 501;
	const Sbecore::uint QRYWZNMDLGREF1NCONTROL = 502;
	const Sbecore::uint QRYWZNMERRLIST = 503;
	const Sbecore::uint QRYWZNMEVTLIST = 504;
	const Sbecore::uint QRYWZNMFILLIST = 505;
	const Sbecore::uint QRYWZNMIELLIST = 506;
	const Sbecore::uint QRYWZNMIEX1NIMPEXP = 507;
	const Sbecore::uint QRYWZNMIEXHK1NVECTOR = 508;
	const Sbecore::uint QRYWZNMIEXLIST = 509;
	const Sbecore::uint QRYWZNMIEXREF1NDIALOG = 510;
	const Sbecore::uint QRYWZNMIMEHK1NVECTOR = 511;
	const Sbecore::uint QRYWZNMIMEIME1NIMPEXPCOL = 512;
	const Sbecore::uint QRYWZNMIMELIST = 513;
	const Sbecore::uint QRYWZNMIMESUP1NIMPEXP = 514;
	const Sbecore::uint QRYWZNMJOB1NMETHOD = 515;
	const Sbecore::uint QRYWZNMJOB1NRTJOB = 516;
	const Sbecore::uint QRYWZNMJOB1NSENSITIVITY = 517;
	const Sbecore::uint QRYWZNMJOBACMD = 518;
	const Sbecore::uint QRYWZNMJOBAVAR = 519;
	const Sbecore::uint QRYWZNMJOBHK1NVECTOR = 520;
	const Sbecore::uint QRYWZNMJOBJOB1NSTAGE = 521;
	const Sbecore::uint QRYWZNMJOBLIST = 522;
	const Sbecore::uint QRYWZNMJOBMNOP = 523;
	const Sbecore::uint QRYWZNMJOBMNOPPACK = 524;
	const Sbecore::uint QRYWZNMJOBREF1NBLOCK = 525;
	const Sbecore::uint QRYWZNMJOBSUBMNJOB = 526;
	const Sbecore::uint QRYWZNMJOBSUPMNJOB = 527;
	const Sbecore::uint QRYWZNMLIBAMAKEFILE = 528;
	const Sbecore::uint QRYWZNMLIBAPKGLIST = 529;
	const Sbecore::uint QRYWZNMLIBLIST = 530;
	const Sbecore::uint QRYWZNMLIBMNCOMPONENT = 531;
	const Sbecore::uint QRYWZNMLIBMNOPPACK = 532;
	const Sbecore::uint QRYWZNMLIBREF1NFILE = 533;
	const Sbecore::uint QRYWZNMLOCLIST = 534;
	const Sbecore::uint QRYWZNMLOCMNVERSION = 535;
	const Sbecore::uint QRYWZNMMCH1NRELEASE = 536;
	const Sbecore::uint QRYWZNMMCHAMAKEFILE = 537;
	const Sbecore::uint QRYWZNMMCHAPAR = 538;
	const Sbecore::uint QRYWZNMMCHLIST = 539;
	const Sbecore::uint QRYWZNMMCHSUP1NMACHINE = 540;
	const Sbecore::uint QRYWZNMMDLLIST = 541;
	const Sbecore::uint QRYWZNMMDLMDL1NCARD = 542;
	const Sbecore::uint QRYWZNMMDLREF1NPANEL = 543;
	const Sbecore::uint QRYWZNMMTDAINVPAR = 544;
	const Sbecore::uint QRYWZNMMTDARETPAR = 545;
	const Sbecore::uint QRYWZNMMTDLIST = 546;
	const Sbecore::uint QRYWZNMOPK1NOP = 547;
	const Sbecore::uint QRYWZNMOPKAINVARG = 548;
	const Sbecore::uint QRYWZNMOPKARETVAL = 549;
	const Sbecore::uint QRYWZNMOPKLIST = 550;
	const Sbecore::uint QRYWZNMOPKMNCOMPONENT = 551;
	const Sbecore::uint QRYWZNMOPKMNJOB = 552;
	const Sbecore::uint QRYWZNMOPKMNLIBRARY = 553;
	const Sbecore::uint QRYWZNMOPKREF1NBLOCK = 554;
	const Sbecore::uint QRYWZNMOPKSQKMNSTUB = 555;
	const Sbecore::uint QRYWZNMOPXAINVARG = 556;
	const Sbecore::uint QRYWZNMOPXARETVAL = 557;
	const Sbecore::uint QRYWZNMOPXLIST = 558;
	const Sbecore::uint QRYWZNMOPXMNJOB = 559;
	const Sbecore::uint QRYWZNMOPXREF1NBLOCK = 560;
	const Sbecore::uint QRYWZNMOPXSQKMNSTUB = 561;
	const Sbecore::uint QRYWZNMPNLHK1NCONTROL = 562;
	const Sbecore::uint QRYWZNMPNLLIST = 563;
	const Sbecore::uint QRYWZNMPNLMNQUERY = 564;
	const Sbecore::uint QRYWZNMPRJ1NVERSION = 565;
	const Sbecore::uint QRYWZNMPRJLIST = 566;
	const Sbecore::uint QRYWZNMPRJMNPERSON = 567;
	const Sbecore::uint QRYWZNMPRSADETAIL = 568;
	const Sbecore::uint QRYWZNMPRSLIST = 569;
	const Sbecore::uint QRYWZNMPRSMNPROJECT = 570;
	const Sbecore::uint QRYWZNMPST1NQUERYMOD = 571;
	const Sbecore::uint QRYWZNMPSTLIST = 572;
	const Sbecore::uint QRYWZNMQCOLIST = 573;
	const Sbecore::uint QRYWZNMQCOREF1NCONTROL = 574;
	const Sbecore::uint QRYWZNMQMDLIST = 575;
	const Sbecore::uint QRYWZNMQRY1NQUERYMOD = 576;
	const Sbecore::uint QRYWZNMQRYACLAUSE = 577;
	const Sbecore::uint QRYWZNMQRYAORDER = 578;
	const Sbecore::uint QRYWZNMQRYLIST = 579;
	const Sbecore::uint QRYWZNMQRYMNDIALOG = 580;
	const Sbecore::uint QRYWZNMQRYMNPANEL = 581;
	const Sbecore::uint QRYWZNMQRYMNTABLE = 582;
	const Sbecore::uint QRYWZNMQRYQRY1NQUERYCOL = 583;
	const Sbecore::uint QRYWZNMQRYSUP1NQUERY = 584;
	const Sbecore::uint QRYWZNMREL1NTABLECOL = 585;
	const Sbecore::uint QRYWZNMRELATITLE = 586;
	const Sbecore::uint QRYWZNMRELLIST = 587;
	const Sbecore::uint QRYWZNMRELREF1NCONTROL = 588;
	const Sbecore::uint QRYWZNMRELREF1NDIALOG = 589;
	const Sbecore::uint QRYWZNMRELREF1NPANEL = 590;
	const Sbecore::uint QRYWZNMRELSUP1NRELATION = 591;
	const Sbecore::uint QRYWZNMRLSLIST = 592;
	const Sbecore::uint QRYWZNMRTJ1NRTBLOCK = 593;
	const Sbecore::uint QRYWZNMRTJ1NRTDPCH = 594;
	const Sbecore::uint QRYWZNMRTJLIST = 595;
	const Sbecore::uint QRYWZNMRTJSUP1NRTJOB = 596;
	const Sbecore::uint QRYWZNMSBS1NSTUB = 597;
	const Sbecore::uint QRYWZNMSBS1NTABLECOL = 598;
	const Sbecore::uint QRYWZNMSBSASBMNSUBSET = 599;
	const Sbecore::uint QRYWZNMSBSATITLE = 600;
	const Sbecore::uint QRYWZNMSBSBSBMNSUBSET = 601;
	const Sbecore::uint QRYWZNMSBSFRS1NRELATION = 602;
	const Sbecore::uint QRYWZNMSBSLIST = 603;
	const Sbecore::uint QRYWZNMSBSPST1NQUERYMOD = 604;
	const Sbecore::uint QRYWZNMSBSTOS1NRELATION = 605;
	const Sbecore::uint QRYWZNMSEQLIST = 606;
	const Sbecore::uint QRYWZNMSEQSEQ1NSTATE = 607;
	const Sbecore::uint QRYWZNMSGE1NSENSITIVITY = 608;
	const Sbecore::uint QRYWZNMSGELIST = 609;
	const Sbecore::uint QRYWZNMSGESQKMNSTUB = 610;
	const Sbecore::uint QRYWZNMSTBLIST = 611;
	const Sbecore::uint QRYWZNMSTBMNCALL = 612;
	const Sbecore::uint QRYWZNMSTBMNSQUAWK = 613;
	const Sbecore::uint QRYWZNMSTBSUBMNSTUB = 614;
	const Sbecore::uint QRYWZNMSTBSUPMNSTUB = 615;
	const Sbecore::uint QRYWZNMSTEAACTION = 616;
	const Sbecore::uint QRYWZNMSTEATRIG = 617;
	const Sbecore::uint QRYWZNMSTELIST = 618;
	const Sbecore::uint QRYWZNMTAGLIST = 619;
	const Sbecore::uint QRYWZNMTBL1NCHECK = 620;
	const Sbecore::uint QRYWZNMTBL1NIMPEXP = 621;
	const Sbecore::uint QRYWZNMTBL1NSTUB = 622;
	const Sbecore::uint QRYWZNMTBL1NSUBSET = 623;
	const Sbecore::uint QRYWZNMTBLALOADFCT = 624;
	const Sbecore::uint QRYWZNMTBLATITLE = 625;
	const Sbecore::uint QRYWZNMTBLFCT1NTABLECOL = 626;
	const Sbecore::uint QRYWZNMTBLFR1NRELATION = 627;
	const Sbecore::uint QRYWZNMTBLHK1NVECTOR = 628;
	const Sbecore::uint QRYWZNMTBLLIST = 629;
	const Sbecore::uint QRYWZNMTBLMNQUERY = 630;
	const Sbecore::uint QRYWZNMTBLMNVECTOR = 631;
	const Sbecore::uint QRYWZNMTBLPST1NQUERYMOD = 632;
	const Sbecore::uint QRYWZNMTBLREF1NCALL = 633;
	const Sbecore::uint QRYWZNMTBLREF1NDIALOG = 634;
	const Sbecore::uint QRYWZNMTBLREF1NPANEL = 635;
	const Sbecore::uint QRYWZNMTBLREF1NQUERYMOD = 636;
	const Sbecore::uint QRYWZNMTBLREF1NRTBLOCK = 637;
	const Sbecore::uint QRYWZNMTBLSRC1NFEED = 638;
	const Sbecore::uint QRYWZNMTBLTBL1NTABLECOL = 639;
	const Sbecore::uint QRYWZNMTBLTO1NRELATION = 640;
	const Sbecore::uint QRYWZNMTCO1NCHECK = 641;
	const Sbecore::uint QRYWZNMTCO1NIMPEXPCOL = 642;
	const Sbecore::uint QRYWZNMTCO1NQUERYCOL = 643;
	const Sbecore::uint QRYWZNMTCOATITLE = 644;
	const Sbecore::uint QRYWZNMTCOLIST = 645;
	const Sbecore::uint QRYWZNMTCOREF1NCONTROL = 646;
	const Sbecore::uint QRYWZNMTCOREF1NQUERYMOD = 647;
	const Sbecore::uint QRYWZNMUSGAACCESS = 648;
	const Sbecore::uint QRYWZNMUSGLIST = 649;
	const Sbecore::uint QRYWZNMUSGMNUSER = 650;
	const Sbecore::uint QRYWZNMUSR1NSESSION = 651;
	const Sbecore::uint QRYWZNMUSRAACCESS = 652;
	const Sbecore::uint QRYWZNMUSRLIST = 653;
	const Sbecore::uint QRYWZNMUSRMNUSERGROUP = 654;
	const Sbecore::uint QRYWZNMVECATITLE = 655;
	const Sbecore::uint QRYWZNMVECFCT1NTABLECOL = 656;
	const Sbecore::uint QRYWZNMVECLIST = 657;
	const Sbecore::uint QRYWZNMVECMNTABLE = 658;
	const Sbecore::uint QRYWZNMVECPST1NQUERYMOD = 659;
	const Sbecore::uint QRYWZNMVECREF1NPANEL = 660;
	const Sbecore::uint QRYWZNMVECSRC1NFEED = 661;
	const Sbecore::uint QRYWZNMVECVEC1NVECTORITEM = 662;
	const Sbecore::uint QRYWZNMVER1NBLOCK = 663;
	const Sbecore::uint QRYWZNMVER1NCALL = 664;
	const Sbecore::uint QRYWZNMVER1NCAPABILITY = 665;
	const Sbecore::uint QRYWZNMVER1NCOMPONENT = 666;
	const Sbecore::uint QRYWZNMVER1NIMPEXPCPLX = 667;
	const Sbecore::uint QRYWZNMVER1NJOB = 668;
	const Sbecore::uint QRYWZNMVER1NOPPACK = 669;
	const Sbecore::uint QRYWZNMVER1NPRESET = 670;
	const Sbecore::uint QRYWZNMVER1NQUERY = 671;
	const Sbecore::uint QRYWZNMVER1NRELATION = 672;
	const Sbecore::uint QRYWZNMVER1NTABLE = 673;
	const Sbecore::uint QRYWZNMVER1NVECTOR = 674;
	const Sbecore::uint QRYWZNMVERBVR1NVERSION = 675;
	const Sbecore::uint QRYWZNMVERLIST = 676;
	const Sbecore::uint QRYWZNMVERMNLOCALE = 677;
	const Sbecore::uint QRYWZNMVERREF1NFILE = 678;
	const Sbecore::uint QRYWZNMVERVER1NAPP = 679;
	const Sbecore::uint QRYWZNMVERVER1NERROR = 680;
	const Sbecore::uint QRYWZNMVERVER1NMODULE = 681;
	const Sbecore::uint QRYWZNMVITLIST = 682;
	const Sbecore::uint ROOTWZNM = 683;
	const Sbecore::uint SESSWZNM = 684;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif



