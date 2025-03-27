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
	const Sbecore::uint CRDWZNMBOX = 3;
	const Sbecore::uint CRDWZNMCAL = 4;
	const Sbecore::uint CRDWZNMCAP = 5;
	const Sbecore::uint CRDWZNMCAR = 6;
	const Sbecore::uint CRDWZNMCHK = 7;
	const Sbecore::uint CRDWZNMCMP = 8;
	const Sbecore::uint CRDWZNMCON = 9;
	const Sbecore::uint CRDWZNMCTP = 10;
	const Sbecore::uint CRDWZNMDLG = 11;
	const Sbecore::uint CRDWZNMERR = 12;
	const Sbecore::uint CRDWZNMEVT = 13;
	const Sbecore::uint CRDWZNMFIL = 14;
	const Sbecore::uint CRDWZNMIEL = 15;
	const Sbecore::uint CRDWZNMIEX = 16;
	const Sbecore::uint CRDWZNMIME = 17;
	const Sbecore::uint CRDWZNMJOB = 18;
	const Sbecore::uint CRDWZNMLIB = 19;
	const Sbecore::uint CRDWZNMLOC = 20;
	const Sbecore::uint CRDWZNMMCH = 21;
	const Sbecore::uint CRDWZNMMDL = 22;
	const Sbecore::uint CRDWZNMMTD = 23;
	const Sbecore::uint CRDWZNMNAV = 24;
	const Sbecore::uint CRDWZNMOPK = 25;
	const Sbecore::uint CRDWZNMOPX = 26;
	const Sbecore::uint CRDWZNMPNL = 27;
	const Sbecore::uint CRDWZNMPRJ = 28;
	const Sbecore::uint CRDWZNMPRS = 29;
	const Sbecore::uint CRDWZNMPST = 30;
	const Sbecore::uint CRDWZNMQCO = 31;
	const Sbecore::uint CRDWZNMQMD = 32;
	const Sbecore::uint CRDWZNMQRY = 33;
	const Sbecore::uint CRDWZNMREL = 34;
	const Sbecore::uint CRDWZNMRLS = 35;
	const Sbecore::uint CRDWZNMRTJ = 36;
	const Sbecore::uint CRDWZNMSBS = 37;
	const Sbecore::uint CRDWZNMSEQ = 38;
	const Sbecore::uint CRDWZNMSGE = 39;
	const Sbecore::uint CRDWZNMSHT = 40;
	const Sbecore::uint CRDWZNMSTB = 41;
	const Sbecore::uint CRDWZNMSTE = 42;
	const Sbecore::uint CRDWZNMTAG = 43;
	const Sbecore::uint CRDWZNMTBL = 44;
	const Sbecore::uint CRDWZNMTCO = 45;
	const Sbecore::uint CRDWZNMUSG = 46;
	const Sbecore::uint CRDWZNMUSR = 47;
	const Sbecore::uint CRDWZNMUTL = 48;
	const Sbecore::uint CRDWZNMVEC = 49;
	const Sbecore::uint CRDWZNMVER = 50;
	const Sbecore::uint CRDWZNMVIS = 51;
	const Sbecore::uint CRDWZNMVIT = 52;
	const Sbecore::uint DLGWZNMAPPIMPSTR = 53;
	const Sbecore::uint DLGWZNMAPPNEW = 54;
	const Sbecore::uint DLGWZNMAPPWRITE = 55;
	const Sbecore::uint DLGWZNMFILDOWNLOAD = 56;
	const Sbecore::uint DLGWZNMFILNEW = 57;
	const Sbecore::uint DLGWZNMMCHWRINISCR = 58;
	const Sbecore::uint DLGWZNMNAVLOAINI = 59;
	const Sbecore::uint DLGWZNMNAVMNGLIC = 60;
	const Sbecore::uint DLGWZNMPRJIMPEX = 61;
	const Sbecore::uint DLGWZNMPRJNEW = 62;
	const Sbecore::uint DLGWZNMRLSFINREPTR = 63;
	const Sbecore::uint DLGWZNMRLSSTAREPTR = 64;
	const Sbecore::uint DLGWZNMRLSWRITE = 65;
	const Sbecore::uint DLGWZNMUSRMNGKEYPAIR = 66;
	const Sbecore::uint DLGWZNMUTLEXTRIP = 67;
	const Sbecore::uint DLGWZNMUTLMRGIP = 68;
	const Sbecore::uint DLGWZNMVERBSCUI = 69;
	const Sbecore::uint DLGWZNMVERCUSTJOB = 70;
	const Sbecore::uint DLGWZNMVERCUSTJTR = 71;
	const Sbecore::uint DLGWZNMVERCUSTUI = 72;
	const Sbecore::uint DLGWZNMVERDBSTR = 73;
	const Sbecore::uint DLGWZNMVERDEPLOY = 74;
	const Sbecore::uint DLGWZNMVERFINMOD = 75;
	const Sbecore::uint DLGWZNMVERGENJTR = 76;
	const Sbecore::uint DLGWZNMVERGENUI = 77;
	const Sbecore::uint DLGWZNMVERGLOBAL = 78;
	const Sbecore::uint DLGWZNMVERIMPEXP = 79;
	const Sbecore::uint DLGWZNMVERNEW = 80;
	const Sbecore::uint DLGWZNMVEROPPACK = 81;
	const Sbecore::uint DLGWZNMVERWRINIMDL = 82;
	const Sbecore::uint DLGWZNMVISEXPSTR = 83;
	const Sbecore::uint DLGWZNMVISIMPSTR = 84;
	const Sbecore::uint DLGWZNMVISMISSFEAT = 85;
	const Sbecore::uint DLGWZNMVISNEW = 86;
	const Sbecore::uint DLGWZNMVISWRITE = 87;
	const Sbecore::uint JOBWZNMIEXAPP = 88;
	const Sbecore::uint JOBWZNMIEXBUI = 89;
	const Sbecore::uint JOBWZNMIEXDBS = 90;
	const Sbecore::uint JOBWZNMIEXDPL = 91;
	const Sbecore::uint JOBWZNMIEXGBL = 92;
	const Sbecore::uint JOBWZNMIEXIEX = 93;
	const Sbecore::uint JOBWZNMIEXINI = 94;
	const Sbecore::uint JOBWZNMIEXJOB = 95;
	const Sbecore::uint JOBWZNMIEXJTR = 96;
	const Sbecore::uint JOBWZNMIEXOPK = 97;
	const Sbecore::uint JOBWZNMIEXPRJ = 98;
	const Sbecore::uint JOBWZNMIEXUIX = 99;
	const Sbecore::uint JOBWZNMIEXVIS = 100;
	const Sbecore::uint JOBWZNMLICENSE = 101;
	const Sbecore::uint PNLWZNMAPP1NEVENT = 102;
	const Sbecore::uint PNLWZNMAPP1NRTJOB = 103;
	const Sbecore::uint PNLWZNMAPPAPP1NSEQUENCE = 104;
	const Sbecore::uint PNLWZNMAPPDETAIL = 105;
	const Sbecore::uint PNLWZNMAPPHEADBAR = 106;
	const Sbecore::uint PNLWZNMAPPLIST = 107;
	const Sbecore::uint PNLWZNMAPPREC = 108;
	const Sbecore::uint PNLWZNMAPPREF1NFILE = 109;
	const Sbecore::uint PNLWZNMBLK1NRTDPCH = 110;
	const Sbecore::uint PNLWZNMBLKAITEM = 111;
	const Sbecore::uint PNLWZNMBLKDETAIL = 112;
	const Sbecore::uint PNLWZNMBLKHEADBAR = 113;
	const Sbecore::uint PNLWZNMBLKLIST = 114;
	const Sbecore::uint PNLWZNMBLKREC = 115;
	const Sbecore::uint PNLWZNMBLKREF1NRTBLOCK = 116;
	const Sbecore::uint PNLWZNMBOXDETAIL = 117;
	const Sbecore::uint PNLWZNMBOXDSTMNBOX = 118;
	const Sbecore::uint PNLWZNMBOXHEADBAR = 119;
	const Sbecore::uint PNLWZNMBOXLIST = 120;
	const Sbecore::uint PNLWZNMBOXORGMNBOX = 121;
	const Sbecore::uint PNLWZNMBOXREC = 122;
	const Sbecore::uint PNLWZNMCAL1NSENSITIVITY = 123;
	const Sbecore::uint PNLWZNMCALDETAIL = 124;
	const Sbecore::uint PNLWZNMCALHEADBAR = 125;
	const Sbecore::uint PNLWZNMCALLIST = 126;
	const Sbecore::uint PNLWZNMCALMNSTUB = 127;
	const Sbecore::uint PNLWZNMCALREC = 128;
	const Sbecore::uint PNLWZNMCAPAPAR = 129;
	const Sbecore::uint PNLWZNMCAPDETAIL = 130;
	const Sbecore::uint PNLWZNMCAPHEADBAR = 131;
	const Sbecore::uint PNLWZNMCAPLIST = 132;
	const Sbecore::uint PNLWZNMCAPREC = 133;
	const Sbecore::uint PNLWZNMCAR1NDIALOG = 134;
	const Sbecore::uint PNLWZNMCARCAR1NPANEL = 135;
	const Sbecore::uint PNLWZNMCARDETAIL = 136;
	const Sbecore::uint PNLWZNMCARHEADBAR = 137;
	const Sbecore::uint PNLWZNMCARHK1NCONTROL = 138;
	const Sbecore::uint PNLWZNMCARLIST = 139;
	const Sbecore::uint PNLWZNMCARREC = 140;
	const Sbecore::uint PNLWZNMCHKDETAIL = 141;
	const Sbecore::uint PNLWZNMCHKHEADBAR = 142;
	const Sbecore::uint PNLWZNMCHKLIST = 143;
	const Sbecore::uint PNLWZNMCHKREC = 144;
	const Sbecore::uint PNLWZNMCHKREF1NCALL = 145;
	const Sbecore::uint PNLWZNMCMP1NRELEASE = 146;
	const Sbecore::uint PNLWZNMCMPDETAIL = 147;
	const Sbecore::uint PNLWZNMCMPHEADBAR = 148;
	const Sbecore::uint PNLWZNMCMPLIST = 149;
	const Sbecore::uint PNLWZNMCMPMNLIBRARY = 150;
	const Sbecore::uint PNLWZNMCMPMNOPPACK = 151;
	const Sbecore::uint PNLWZNMCMPREC = 152;
	const Sbecore::uint PNLWZNMCONAPAR = 153;
	const Sbecore::uint PNLWZNMCONDETAIL = 154;
	const Sbecore::uint PNLWZNMCONFEDREF1NRTBLOCK = 155;
	const Sbecore::uint PNLWZNMCONHEADBAR = 156;
	const Sbecore::uint PNLWZNMCONLIST = 157;
	const Sbecore::uint PNLWZNMCONREC = 158;
	const Sbecore::uint PNLWZNMCONSUP1NCONTROL = 159;
	const Sbecore::uint PNLWZNMCTP1NTAG = 160;
	const Sbecore::uint PNLWZNMCTPAPAR = 161;
	const Sbecore::uint PNLWZNMCTPDETAIL = 162;
	const Sbecore::uint PNLWZNMCTPHEADBAR = 163;
	const Sbecore::uint PNLWZNMCTPKKEY = 164;
	const Sbecore::uint PNLWZNMCTPKPARKEY = 165;
	const Sbecore::uint PNLWZNMCTPLIST = 166;
	const Sbecore::uint PNLWZNMCTPREC = 167;
	const Sbecore::uint PNLWZNMCTPTPL1NCAPABILITY = 168;
	const Sbecore::uint PNLWZNMDLGDETAIL = 169;
	const Sbecore::uint PNLWZNMDLGHEADBAR = 170;
	const Sbecore::uint PNLWZNMDLGHK1NCONTROL = 171;
	const Sbecore::uint PNLWZNMDLGLIST = 172;
	const Sbecore::uint PNLWZNMDLGMNQUERY = 173;
	const Sbecore::uint PNLWZNMDLGREC = 174;
	const Sbecore::uint PNLWZNMDLGREF1NCONTROL = 175;
	const Sbecore::uint PNLWZNMERRDETAIL = 176;
	const Sbecore::uint PNLWZNMERRHEADBAR = 177;
	const Sbecore::uint PNLWZNMERRLIST = 178;
	const Sbecore::uint PNLWZNMERRREC = 179;
	const Sbecore::uint PNLWZNMEVTDETAIL = 180;
	const Sbecore::uint PNLWZNMEVTHEADBAR = 181;
	const Sbecore::uint PNLWZNMEVTLIST = 182;
	const Sbecore::uint PNLWZNMEVTREC = 183;
	const Sbecore::uint PNLWZNMFILDETAIL = 184;
	const Sbecore::uint PNLWZNMFILHEADBAR = 185;
	const Sbecore::uint PNLWZNMFILLIST = 186;
	const Sbecore::uint PNLWZNMFILREC = 187;
	const Sbecore::uint PNLWZNMIELDETAIL = 188;
	const Sbecore::uint PNLWZNMIELHEADBAR = 189;
	const Sbecore::uint PNLWZNMIELLIST = 190;
	const Sbecore::uint PNLWZNMIELREC = 191;
	const Sbecore::uint PNLWZNMIEX1NIMPEXP = 192;
	const Sbecore::uint PNLWZNMIEXDETAIL = 193;
	const Sbecore::uint PNLWZNMIEXHEADBAR = 194;
	const Sbecore::uint PNLWZNMIEXHK1NVECTOR = 195;
	const Sbecore::uint PNLWZNMIEXLIST = 196;
	const Sbecore::uint PNLWZNMIEXREC = 197;
	const Sbecore::uint PNLWZNMIEXREF1NDIALOG = 198;
	const Sbecore::uint PNLWZNMIMEDETAIL = 199;
	const Sbecore::uint PNLWZNMIMEHEADBAR = 200;
	const Sbecore::uint PNLWZNMIMEHK1NVECTOR = 201;
	const Sbecore::uint PNLWZNMIMEIME1NIMPEXPCOL = 202;
	const Sbecore::uint PNLWZNMIMELIST = 203;
	const Sbecore::uint PNLWZNMIMEREC = 204;
	const Sbecore::uint PNLWZNMIMESUP1NIMPEXP = 205;
	const Sbecore::uint PNLWZNMJOB1NMETHOD = 206;
	const Sbecore::uint PNLWZNMJOB1NRTJOB = 207;
	const Sbecore::uint PNLWZNMJOB1NSENSITIVITY = 208;
	const Sbecore::uint PNLWZNMJOBACMD = 209;
	const Sbecore::uint PNLWZNMJOBAVAR = 210;
	const Sbecore::uint PNLWZNMJOBDETAIL = 211;
	const Sbecore::uint PNLWZNMJOBHEADBAR = 212;
	const Sbecore::uint PNLWZNMJOBHK1NVECTOR = 213;
	const Sbecore::uint PNLWZNMJOBJOB1NSTAGE = 214;
	const Sbecore::uint PNLWZNMJOBLIST = 215;
	const Sbecore::uint PNLWZNMJOBMNOP = 216;
	const Sbecore::uint PNLWZNMJOBMNOPPACK = 217;
	const Sbecore::uint PNLWZNMJOBREC = 218;
	const Sbecore::uint PNLWZNMJOBREF1NBLOCK = 219;
	const Sbecore::uint PNLWZNMJOBSUBMNJOB = 220;
	const Sbecore::uint PNLWZNMJOBSUPMNJOB = 221;
	const Sbecore::uint PNLWZNMLIBAMAKEFILE = 222;
	const Sbecore::uint PNLWZNMLIBAPKGLIST = 223;
	const Sbecore::uint PNLWZNMLIBDETAIL = 224;
	const Sbecore::uint PNLWZNMLIBHEADBAR = 225;
	const Sbecore::uint PNLWZNMLIBLIST = 226;
	const Sbecore::uint PNLWZNMLIBMNCOMPONENT = 227;
	const Sbecore::uint PNLWZNMLIBMNOPPACK = 228;
	const Sbecore::uint PNLWZNMLIBREC = 229;
	const Sbecore::uint PNLWZNMLIBREF1NFILE = 230;
	const Sbecore::uint PNLWZNMLOCDETAIL = 231;
	const Sbecore::uint PNLWZNMLOCHEADBAR = 232;
	const Sbecore::uint PNLWZNMLOCLIST = 233;
	const Sbecore::uint PNLWZNMLOCMNVERSION = 234;
	const Sbecore::uint PNLWZNMLOCREC = 235;
	const Sbecore::uint PNLWZNMMCH1NRELEASE = 236;
	const Sbecore::uint PNLWZNMMCHAMAKEFILE = 237;
	const Sbecore::uint PNLWZNMMCHAPAR = 238;
	const Sbecore::uint PNLWZNMMCHDETAIL = 239;
	const Sbecore::uint PNLWZNMMCHHEADBAR = 240;
	const Sbecore::uint PNLWZNMMCHLIST = 241;
	const Sbecore::uint PNLWZNMMCHREC = 242;
	const Sbecore::uint PNLWZNMMCHSUP1NMACHINE = 243;
	const Sbecore::uint PNLWZNMMDLDETAIL = 244;
	const Sbecore::uint PNLWZNMMDLHEADBAR = 245;
	const Sbecore::uint PNLWZNMMDLLIST = 246;
	const Sbecore::uint PNLWZNMMDLMDL1NCARD = 247;
	const Sbecore::uint PNLWZNMMDLREC = 248;
	const Sbecore::uint PNLWZNMMDLREF1NPANEL = 249;
	const Sbecore::uint PNLWZNMMTDAINVPAR = 250;
	const Sbecore::uint PNLWZNMMTDARETPAR = 251;
	const Sbecore::uint PNLWZNMMTDDETAIL = 252;
	const Sbecore::uint PNLWZNMMTDHEADBAR = 253;
	const Sbecore::uint PNLWZNMMTDLIST = 254;
	const Sbecore::uint PNLWZNMMTDREC = 255;
	const Sbecore::uint PNLWZNMNAVADMIN = 256;
	const Sbecore::uint PNLWZNMNAVAPPDEV = 257;
	const Sbecore::uint PNLWZNMNAVAUXFCT = 258;
	const Sbecore::uint PNLWZNMNAVCOMP = 259;
	const Sbecore::uint PNLWZNMNAVDBSTR = 260;
	const Sbecore::uint PNLWZNMNAVDEPLOY = 261;
	const Sbecore::uint PNLWZNMNAVGLOBAL = 262;
	const Sbecore::uint PNLWZNMNAVHEADBAR = 263;
	const Sbecore::uint PNLWZNMNAVJOB = 264;
	const Sbecore::uint PNLWZNMNAVPRE = 265;
	const Sbecore::uint PNLWZNMNAVPROJECT = 266;
	const Sbecore::uint PNLWZNMNAVUIX = 267;
	const Sbecore::uint PNLWZNMNAVVISUAL = 268;
	const Sbecore::uint PNLWZNMOPK1NOP = 269;
	const Sbecore::uint PNLWZNMOPKAINVARG = 270;
	const Sbecore::uint PNLWZNMOPKARETVAL = 271;
	const Sbecore::uint PNLWZNMOPKDETAIL = 272;
	const Sbecore::uint PNLWZNMOPKHEADBAR = 273;
	const Sbecore::uint PNLWZNMOPKLIST = 274;
	const Sbecore::uint PNLWZNMOPKMNCOMPONENT = 275;
	const Sbecore::uint PNLWZNMOPKMNJOB = 276;
	const Sbecore::uint PNLWZNMOPKMNLIBRARY = 277;
	const Sbecore::uint PNLWZNMOPKREC = 278;
	const Sbecore::uint PNLWZNMOPKREF1NBLOCK = 279;
	const Sbecore::uint PNLWZNMOPKSQKMNSTUB = 280;
	const Sbecore::uint PNLWZNMOPXAINVARG = 281;
	const Sbecore::uint PNLWZNMOPXARETVAL = 282;
	const Sbecore::uint PNLWZNMOPXDETAIL = 283;
	const Sbecore::uint PNLWZNMOPXHEADBAR = 284;
	const Sbecore::uint PNLWZNMOPXLIST = 285;
	const Sbecore::uint PNLWZNMOPXMNJOB = 286;
	const Sbecore::uint PNLWZNMOPXREC = 287;
	const Sbecore::uint PNLWZNMOPXREF1NBLOCK = 288;
	const Sbecore::uint PNLWZNMOPXSQKMNSTUB = 289;
	const Sbecore::uint PNLWZNMPNLDETAIL = 290;
	const Sbecore::uint PNLWZNMPNLHEADBAR = 291;
	const Sbecore::uint PNLWZNMPNLHK1NCONTROL = 292;
	const Sbecore::uint PNLWZNMPNLLIST = 293;
	const Sbecore::uint PNLWZNMPNLMNQUERY = 294;
	const Sbecore::uint PNLWZNMPNLREC = 295;
	const Sbecore::uint PNLWZNMPRJDETAIL = 296;
	const Sbecore::uint PNLWZNMPRJHEADBAR = 297;
	const Sbecore::uint PNLWZNMPRJLIST = 298;
	const Sbecore::uint PNLWZNMPRJMNPERSON = 299;
	const Sbecore::uint PNLWZNMPRJPRJ1NVERSION = 300;
	const Sbecore::uint PNLWZNMPRJREC = 301;
	const Sbecore::uint PNLWZNMPRSADETAIL = 302;
	const Sbecore::uint PNLWZNMPRSDETAIL = 303;
	const Sbecore::uint PNLWZNMPRSHEADBAR = 304;
	const Sbecore::uint PNLWZNMPRSLIST = 305;
	const Sbecore::uint PNLWZNMPRSMNPROJECT = 306;
	const Sbecore::uint PNLWZNMPRSREC = 307;
	const Sbecore::uint PNLWZNMPST1NQUERYMOD = 308;
	const Sbecore::uint PNLWZNMPSTDETAIL = 309;
	const Sbecore::uint PNLWZNMPSTHEADBAR = 310;
	const Sbecore::uint PNLWZNMPSTLIST = 311;
	const Sbecore::uint PNLWZNMPSTREC = 312;
	const Sbecore::uint PNLWZNMQCODETAIL = 313;
	const Sbecore::uint PNLWZNMQCOHEADBAR = 314;
	const Sbecore::uint PNLWZNMQCOLIST = 315;
	const Sbecore::uint PNLWZNMQCOREC = 316;
	const Sbecore::uint PNLWZNMQCOREF1NCONTROL = 317;
	const Sbecore::uint PNLWZNMQMDDETAIL = 318;
	const Sbecore::uint PNLWZNMQMDHEADBAR = 319;
	const Sbecore::uint PNLWZNMQMDLIST = 320;
	const Sbecore::uint PNLWZNMQMDREC = 321;
	const Sbecore::uint PNLWZNMQRY1NQUERYMOD = 322;
	const Sbecore::uint PNLWZNMQRYACLAUSE = 323;
	const Sbecore::uint PNLWZNMQRYAORDER = 324;
	const Sbecore::uint PNLWZNMQRYDETAIL = 325;
	const Sbecore::uint PNLWZNMQRYHEADBAR = 326;
	const Sbecore::uint PNLWZNMQRYLIST = 327;
	const Sbecore::uint PNLWZNMQRYMNDIALOG = 328;
	const Sbecore::uint PNLWZNMQRYMNPANEL = 329;
	const Sbecore::uint PNLWZNMQRYMNTABLE = 330;
	const Sbecore::uint PNLWZNMQRYQRY1NQUERYCOL = 331;
	const Sbecore::uint PNLWZNMQRYREC = 332;
	const Sbecore::uint PNLWZNMQRYSUP1NQUERY = 333;
	const Sbecore::uint PNLWZNMREL1NTABLECOL = 334;
	const Sbecore::uint PNLWZNMRELATITLE = 335;
	const Sbecore::uint PNLWZNMRELDETAIL = 336;
	const Sbecore::uint PNLWZNMRELHEADBAR = 337;
	const Sbecore::uint PNLWZNMRELLIST = 338;
	const Sbecore::uint PNLWZNMRELREC = 339;
	const Sbecore::uint PNLWZNMRELREF1NCONTROL = 340;
	const Sbecore::uint PNLWZNMRELREF1NDIALOG = 341;
	const Sbecore::uint PNLWZNMRELREF1NPANEL = 342;
	const Sbecore::uint PNLWZNMRELSUP1NRELATION = 343;
	const Sbecore::uint PNLWZNMRLSDETAIL = 344;
	const Sbecore::uint PNLWZNMRLSHEADBAR = 345;
	const Sbecore::uint PNLWZNMRLSLIST = 346;
	const Sbecore::uint PNLWZNMRLSREC = 347;
	const Sbecore::uint PNLWZNMRTJ1NRTBLOCK = 348;
	const Sbecore::uint PNLWZNMRTJ1NRTDPCH = 349;
	const Sbecore::uint PNLWZNMRTJDETAIL = 350;
	const Sbecore::uint PNLWZNMRTJHEADBAR = 351;
	const Sbecore::uint PNLWZNMRTJLIST = 352;
	const Sbecore::uint PNLWZNMRTJREC = 353;
	const Sbecore::uint PNLWZNMRTJSUP1NRTJOB = 354;
	const Sbecore::uint PNLWZNMSBS1NSTUB = 355;
	const Sbecore::uint PNLWZNMSBS1NTABLECOL = 356;
	const Sbecore::uint PNLWZNMSBSASBMNSUBSET = 357;
	const Sbecore::uint PNLWZNMSBSATITLE = 358;
	const Sbecore::uint PNLWZNMSBSBSBMNSUBSET = 359;
	const Sbecore::uint PNLWZNMSBSDETAIL = 360;
	const Sbecore::uint PNLWZNMSBSFRS1NRELATION = 361;
	const Sbecore::uint PNLWZNMSBSHEADBAR = 362;
	const Sbecore::uint PNLWZNMSBSLIST = 363;
	const Sbecore::uint PNLWZNMSBSPST1NQUERYMOD = 364;
	const Sbecore::uint PNLWZNMSBSREC = 365;
	const Sbecore::uint PNLWZNMSBSTOS1NRELATION = 366;
	const Sbecore::uint PNLWZNMSEQDETAIL = 367;
	const Sbecore::uint PNLWZNMSEQHEADBAR = 368;
	const Sbecore::uint PNLWZNMSEQLIST = 369;
	const Sbecore::uint PNLWZNMSEQREC = 370;
	const Sbecore::uint PNLWZNMSEQSEQ1NSTATE = 371;
	const Sbecore::uint PNLWZNMSGE1NSENSITIVITY = 372;
	const Sbecore::uint PNLWZNMSGEDETAIL = 373;
	const Sbecore::uint PNLWZNMSGEHEADBAR = 374;
	const Sbecore::uint PNLWZNMSGELIST = 375;
	const Sbecore::uint PNLWZNMSGEREC = 376;
	const Sbecore::uint PNLWZNMSGESQKMNSTUB = 377;
	const Sbecore::uint PNLWZNMSHT1NBOX = 378;
	const Sbecore::uint PNLWZNMSHTDETAIL = 379;
	const Sbecore::uint PNLWZNMSHTHEADBAR = 380;
	const Sbecore::uint PNLWZNMSHTLIST = 381;
	const Sbecore::uint PNLWZNMSHTREC = 382;
	const Sbecore::uint PNLWZNMSTBDETAIL = 383;
	const Sbecore::uint PNLWZNMSTBHEADBAR = 384;
	const Sbecore::uint PNLWZNMSTBLIST = 385;
	const Sbecore::uint PNLWZNMSTBMNCALL = 386;
	const Sbecore::uint PNLWZNMSTBMNSQUAWK = 387;
	const Sbecore::uint PNLWZNMSTBREC = 388;
	const Sbecore::uint PNLWZNMSTBSUBMNSTUB = 389;
	const Sbecore::uint PNLWZNMSTBSUPMNSTUB = 390;
	const Sbecore::uint PNLWZNMSTEAACTION = 391;
	const Sbecore::uint PNLWZNMSTEATRIG = 392;
	const Sbecore::uint PNLWZNMSTEDETAIL = 393;
	const Sbecore::uint PNLWZNMSTEHEADBAR = 394;
	const Sbecore::uint PNLWZNMSTELIST = 395;
	const Sbecore::uint PNLWZNMSTEREC = 396;
	const Sbecore::uint PNLWZNMTAGDETAIL = 397;
	const Sbecore::uint PNLWZNMTAGHEADBAR = 398;
	const Sbecore::uint PNLWZNMTAGLIST = 399;
	const Sbecore::uint PNLWZNMTAGREC = 400;
	const Sbecore::uint PNLWZNMTBL1NCHECK = 401;
	const Sbecore::uint PNLWZNMTBL1NIMPEXP = 402;
	const Sbecore::uint PNLWZNMTBL1NSTUB = 403;
	const Sbecore::uint PNLWZNMTBL1NSUBSET = 404;
	const Sbecore::uint PNLWZNMTBLALOADFCT = 405;
	const Sbecore::uint PNLWZNMTBLATITLE = 406;
	const Sbecore::uint PNLWZNMTBLDETAIL = 407;
	const Sbecore::uint PNLWZNMTBLFCT1NTABLECOL = 408;
	const Sbecore::uint PNLWZNMTBLFR1NRELATION = 409;
	const Sbecore::uint PNLWZNMTBLHEADBAR = 410;
	const Sbecore::uint PNLWZNMTBLHK1NVECTOR = 411;
	const Sbecore::uint PNLWZNMTBLLIST = 412;
	const Sbecore::uint PNLWZNMTBLMNQUERY = 413;
	const Sbecore::uint PNLWZNMTBLMNVECTOR = 414;
	const Sbecore::uint PNLWZNMTBLPST1NQUERYMOD = 415;
	const Sbecore::uint PNLWZNMTBLREC = 416;
	const Sbecore::uint PNLWZNMTBLREF1NCALL = 417;
	const Sbecore::uint PNLWZNMTBLREF1NDIALOG = 418;
	const Sbecore::uint PNLWZNMTBLREF1NPANEL = 419;
	const Sbecore::uint PNLWZNMTBLREF1NQUERYMOD = 420;
	const Sbecore::uint PNLWZNMTBLREF1NRTBLOCK = 421;
	const Sbecore::uint PNLWZNMTBLSRC1NFEED = 422;
	const Sbecore::uint PNLWZNMTBLTBL1NTABLECOL = 423;
	const Sbecore::uint PNLWZNMTBLTO1NRELATION = 424;
	const Sbecore::uint PNLWZNMTCO1NCHECK = 425;
	const Sbecore::uint PNLWZNMTCO1NIMPEXPCOL = 426;
	const Sbecore::uint PNLWZNMTCO1NQUERYCOL = 427;
	const Sbecore::uint PNLWZNMTCOATITLE = 428;
	const Sbecore::uint PNLWZNMTCODETAIL = 429;
	const Sbecore::uint PNLWZNMTCOHEADBAR = 430;
	const Sbecore::uint PNLWZNMTCOLIST = 431;
	const Sbecore::uint PNLWZNMTCOREC = 432;
	const Sbecore::uint PNLWZNMTCOREF1NCONTROL = 433;
	const Sbecore::uint PNLWZNMTCOREF1NQUERYMOD = 434;
	const Sbecore::uint PNLWZNMUSGAACCESS = 435;
	const Sbecore::uint PNLWZNMUSGDETAIL = 436;
	const Sbecore::uint PNLWZNMUSGHEADBAR = 437;
	const Sbecore::uint PNLWZNMUSGLIST = 438;
	const Sbecore::uint PNLWZNMUSGMNUSER = 439;
	const Sbecore::uint PNLWZNMUSGREC = 440;
	const Sbecore::uint PNLWZNMUSR1NSESSION = 441;
	const Sbecore::uint PNLWZNMUSRAACCESS = 442;
	const Sbecore::uint PNLWZNMUSRDETAIL = 443;
	const Sbecore::uint PNLWZNMUSRHEADBAR = 444;
	const Sbecore::uint PNLWZNMUSRLIST = 445;
	const Sbecore::uint PNLWZNMUSRMNUSERGROUP = 446;
	const Sbecore::uint PNLWZNMUSRREC = 447;
	const Sbecore::uint PNLWZNMUTLHEADBAR = 448;
	const Sbecore::uint PNLWZNMVECATITLE = 449;
	const Sbecore::uint PNLWZNMVECDETAIL = 450;
	const Sbecore::uint PNLWZNMVECFCT1NTABLECOL = 451;
	const Sbecore::uint PNLWZNMVECHEADBAR = 452;
	const Sbecore::uint PNLWZNMVECLIST = 453;
	const Sbecore::uint PNLWZNMVECMNTABLE = 454;
	const Sbecore::uint PNLWZNMVECPST1NQUERYMOD = 455;
	const Sbecore::uint PNLWZNMVECREC = 456;
	const Sbecore::uint PNLWZNMVECREF1NPANEL = 457;
	const Sbecore::uint PNLWZNMVECSRC1NFEED = 458;
	const Sbecore::uint PNLWZNMVECVEC1NVECTORITEM = 459;
	const Sbecore::uint PNLWZNMVER1NBLOCK = 460;
	const Sbecore::uint PNLWZNMVER1NCALL = 461;
	const Sbecore::uint PNLWZNMVER1NCAPABILITY = 462;
	const Sbecore::uint PNLWZNMVER1NCOMPONENT = 463;
	const Sbecore::uint PNLWZNMVER1NIMPEXPCPLX = 464;
	const Sbecore::uint PNLWZNMVER1NJOB = 465;
	const Sbecore::uint PNLWZNMVER1NOPPACK = 466;
	const Sbecore::uint PNLWZNMVER1NPRESET = 467;
	const Sbecore::uint PNLWZNMVER1NQUERY = 468;
	const Sbecore::uint PNLWZNMVER1NRELATION = 469;
	const Sbecore::uint PNLWZNMVER1NTABLE = 470;
	const Sbecore::uint PNLWZNMVER1NVECTOR = 471;
	const Sbecore::uint PNLWZNMVERBVR1NVERSION = 472;
	const Sbecore::uint PNLWZNMVERDETAIL = 473;
	const Sbecore::uint PNLWZNMVERHEADBAR = 474;
	const Sbecore::uint PNLWZNMVERLIST = 475;
	const Sbecore::uint PNLWZNMVERMNLOCALE = 476;
	const Sbecore::uint PNLWZNMVERREC = 477;
	const Sbecore::uint PNLWZNMVERREF1NFILE = 478;
	const Sbecore::uint PNLWZNMVERVER1NAPP = 479;
	const Sbecore::uint PNLWZNMVERVER1NERROR = 480;
	const Sbecore::uint PNLWZNMVERVER1NMODULE = 481;
	const Sbecore::uint PNLWZNMVERVER1NVISUAL = 482;
	const Sbecore::uint PNLWZNMVISDETAIL = 483;
	const Sbecore::uint PNLWZNMVISHEADBAR = 484;
	const Sbecore::uint PNLWZNMVISLIST = 485;
	const Sbecore::uint PNLWZNMVISREC = 486;
	const Sbecore::uint PNLWZNMVISREF1NFILE = 487;
	const Sbecore::uint PNLWZNMVISVIS1NSHEET = 488;
	const Sbecore::uint PNLWZNMVITDETAIL = 489;
	const Sbecore::uint PNLWZNMVITHEADBAR = 490;
	const Sbecore::uint PNLWZNMVITLIST = 491;
	const Sbecore::uint PNLWZNMVITREC = 492;
	const Sbecore::uint QRYWZNMAPP1NEVENT = 493;
	const Sbecore::uint QRYWZNMAPP1NRTJOB = 494;
	const Sbecore::uint QRYWZNMAPPAPP1NSEQUENCE = 495;
	const Sbecore::uint QRYWZNMAPPLIST = 496;
	const Sbecore::uint QRYWZNMAPPREF1NFILE = 497;
	const Sbecore::uint QRYWZNMBLK1NRTDPCH = 498;
	const Sbecore::uint QRYWZNMBLKAITEM = 499;
	const Sbecore::uint QRYWZNMBLKLIST = 500;
	const Sbecore::uint QRYWZNMBLKREF1NRTBLOCK = 501;
	const Sbecore::uint QRYWZNMBOXDSTMNBOX = 502;
	const Sbecore::uint QRYWZNMBOXLIST = 503;
	const Sbecore::uint QRYWZNMBOXORGMNBOX = 504;
	const Sbecore::uint QRYWZNMCAL1NSENSITIVITY = 505;
	const Sbecore::uint QRYWZNMCALLIST = 506;
	const Sbecore::uint QRYWZNMCALMNSTUB = 507;
	const Sbecore::uint QRYWZNMCAPAPAR = 508;
	const Sbecore::uint QRYWZNMCAPLIST = 509;
	const Sbecore::uint QRYWZNMCAR1NDIALOG = 510;
	const Sbecore::uint QRYWZNMCARCAR1NPANEL = 511;
	const Sbecore::uint QRYWZNMCARHK1NCONTROL = 512;
	const Sbecore::uint QRYWZNMCARLIST = 513;
	const Sbecore::uint QRYWZNMCHKLIST = 514;
	const Sbecore::uint QRYWZNMCHKREF1NCALL = 515;
	const Sbecore::uint QRYWZNMCMP1NRELEASE = 516;
	const Sbecore::uint QRYWZNMCMPLIST = 517;
	const Sbecore::uint QRYWZNMCMPMNLIBRARY = 518;
	const Sbecore::uint QRYWZNMCMPMNOPPACK = 519;
	const Sbecore::uint QRYWZNMCONAPAR = 520;
	const Sbecore::uint QRYWZNMCONFEDREF1NRTBLOCK = 521;
	const Sbecore::uint QRYWZNMCONLIST = 522;
	const Sbecore::uint QRYWZNMCONSUP1NCONTROL = 523;
	const Sbecore::uint QRYWZNMCTP1NTAG = 524;
	const Sbecore::uint QRYWZNMCTPAPAR = 525;
	const Sbecore::uint QRYWZNMCTPKKEY = 526;
	const Sbecore::uint QRYWZNMCTPKPARKEY = 527;
	const Sbecore::uint QRYWZNMCTPLIST = 528;
	const Sbecore::uint QRYWZNMCTPTPL1NCAPABILITY = 529;
	const Sbecore::uint QRYWZNMDLGHK1NCONTROL = 530;
	const Sbecore::uint QRYWZNMDLGLIST = 531;
	const Sbecore::uint QRYWZNMDLGMNQUERY = 532;
	const Sbecore::uint QRYWZNMDLGREF1NCONTROL = 533;
	const Sbecore::uint QRYWZNMERRLIST = 534;
	const Sbecore::uint QRYWZNMEVTLIST = 535;
	const Sbecore::uint QRYWZNMFILLIST = 536;
	const Sbecore::uint QRYWZNMIELLIST = 537;
	const Sbecore::uint QRYWZNMIEX1NIMPEXP = 538;
	const Sbecore::uint QRYWZNMIEXHK1NVECTOR = 539;
	const Sbecore::uint QRYWZNMIEXLIST = 540;
	const Sbecore::uint QRYWZNMIEXREF1NDIALOG = 541;
	const Sbecore::uint QRYWZNMIMEHK1NVECTOR = 542;
	const Sbecore::uint QRYWZNMIMEIME1NIMPEXPCOL = 543;
	const Sbecore::uint QRYWZNMIMELIST = 544;
	const Sbecore::uint QRYWZNMIMESUP1NIMPEXP = 545;
	const Sbecore::uint QRYWZNMJOB1NMETHOD = 546;
	const Sbecore::uint QRYWZNMJOB1NRTJOB = 547;
	const Sbecore::uint QRYWZNMJOB1NSENSITIVITY = 548;
	const Sbecore::uint QRYWZNMJOBACMD = 549;
	const Sbecore::uint QRYWZNMJOBAVAR = 550;
	const Sbecore::uint QRYWZNMJOBHK1NVECTOR = 551;
	const Sbecore::uint QRYWZNMJOBJOB1NSTAGE = 552;
	const Sbecore::uint QRYWZNMJOBLIST = 553;
	const Sbecore::uint QRYWZNMJOBMNOP = 554;
	const Sbecore::uint QRYWZNMJOBMNOPPACK = 555;
	const Sbecore::uint QRYWZNMJOBREF1NBLOCK = 556;
	const Sbecore::uint QRYWZNMJOBSUBMNJOB = 557;
	const Sbecore::uint QRYWZNMJOBSUPMNJOB = 558;
	const Sbecore::uint QRYWZNMLIBAMAKEFILE = 559;
	const Sbecore::uint QRYWZNMLIBAPKGLIST = 560;
	const Sbecore::uint QRYWZNMLIBLIST = 561;
	const Sbecore::uint QRYWZNMLIBMNCOMPONENT = 562;
	const Sbecore::uint QRYWZNMLIBMNOPPACK = 563;
	const Sbecore::uint QRYWZNMLIBREF1NFILE = 564;
	const Sbecore::uint QRYWZNMLOCLIST = 565;
	const Sbecore::uint QRYWZNMLOCMNVERSION = 566;
	const Sbecore::uint QRYWZNMMCH1NRELEASE = 567;
	const Sbecore::uint QRYWZNMMCHAMAKEFILE = 568;
	const Sbecore::uint QRYWZNMMCHAPAR = 569;
	const Sbecore::uint QRYWZNMMCHLIST = 570;
	const Sbecore::uint QRYWZNMMCHSUP1NMACHINE = 571;
	const Sbecore::uint QRYWZNMMDLLIST = 572;
	const Sbecore::uint QRYWZNMMDLMDL1NCARD = 573;
	const Sbecore::uint QRYWZNMMDLREF1NPANEL = 574;
	const Sbecore::uint QRYWZNMMTDAINVPAR = 575;
	const Sbecore::uint QRYWZNMMTDARETPAR = 576;
	const Sbecore::uint QRYWZNMMTDLIST = 577;
	const Sbecore::uint QRYWZNMOPK1NOP = 578;
	const Sbecore::uint QRYWZNMOPKAINVARG = 579;
	const Sbecore::uint QRYWZNMOPKARETVAL = 580;
	const Sbecore::uint QRYWZNMOPKLIST = 581;
	const Sbecore::uint QRYWZNMOPKMNCOMPONENT = 582;
	const Sbecore::uint QRYWZNMOPKMNJOB = 583;
	const Sbecore::uint QRYWZNMOPKMNLIBRARY = 584;
	const Sbecore::uint QRYWZNMOPKREF1NBLOCK = 585;
	const Sbecore::uint QRYWZNMOPKSQKMNSTUB = 586;
	const Sbecore::uint QRYWZNMOPXAINVARG = 587;
	const Sbecore::uint QRYWZNMOPXARETVAL = 588;
	const Sbecore::uint QRYWZNMOPXLIST = 589;
	const Sbecore::uint QRYWZNMOPXMNJOB = 590;
	const Sbecore::uint QRYWZNMOPXREF1NBLOCK = 591;
	const Sbecore::uint QRYWZNMOPXSQKMNSTUB = 592;
	const Sbecore::uint QRYWZNMPNLHK1NCONTROL = 593;
	const Sbecore::uint QRYWZNMPNLLIST = 594;
	const Sbecore::uint QRYWZNMPNLMNQUERY = 595;
	const Sbecore::uint QRYWZNMPRJLIST = 596;
	const Sbecore::uint QRYWZNMPRJMNPERSON = 597;
	const Sbecore::uint QRYWZNMPRJPRJ1NVERSION = 598;
	const Sbecore::uint QRYWZNMPRSADETAIL = 599;
	const Sbecore::uint QRYWZNMPRSLIST = 600;
	const Sbecore::uint QRYWZNMPRSMNPROJECT = 601;
	const Sbecore::uint QRYWZNMPST1NQUERYMOD = 602;
	const Sbecore::uint QRYWZNMPSTLIST = 603;
	const Sbecore::uint QRYWZNMQCOLIST = 604;
	const Sbecore::uint QRYWZNMQCOREF1NCONTROL = 605;
	const Sbecore::uint QRYWZNMQMDLIST = 606;
	const Sbecore::uint QRYWZNMQRY1NQUERYMOD = 607;
	const Sbecore::uint QRYWZNMQRYACLAUSE = 608;
	const Sbecore::uint QRYWZNMQRYAORDER = 609;
	const Sbecore::uint QRYWZNMQRYLIST = 610;
	const Sbecore::uint QRYWZNMQRYMNDIALOG = 611;
	const Sbecore::uint QRYWZNMQRYMNPANEL = 612;
	const Sbecore::uint QRYWZNMQRYMNTABLE = 613;
	const Sbecore::uint QRYWZNMQRYQRY1NQUERYCOL = 614;
	const Sbecore::uint QRYWZNMQRYSUP1NQUERY = 615;
	const Sbecore::uint QRYWZNMREL1NTABLECOL = 616;
	const Sbecore::uint QRYWZNMRELATITLE = 617;
	const Sbecore::uint QRYWZNMRELLIST = 618;
	const Sbecore::uint QRYWZNMRELREF1NCONTROL = 619;
	const Sbecore::uint QRYWZNMRELREF1NDIALOG = 620;
	const Sbecore::uint QRYWZNMRELREF1NPANEL = 621;
	const Sbecore::uint QRYWZNMRELSUP1NRELATION = 622;
	const Sbecore::uint QRYWZNMRLSLIST = 623;
	const Sbecore::uint QRYWZNMRTJ1NRTBLOCK = 624;
	const Sbecore::uint QRYWZNMRTJ1NRTDPCH = 625;
	const Sbecore::uint QRYWZNMRTJLIST = 626;
	const Sbecore::uint QRYWZNMRTJSUP1NRTJOB = 627;
	const Sbecore::uint QRYWZNMSBS1NSTUB = 628;
	const Sbecore::uint QRYWZNMSBS1NTABLECOL = 629;
	const Sbecore::uint QRYWZNMSBSASBMNSUBSET = 630;
	const Sbecore::uint QRYWZNMSBSATITLE = 631;
	const Sbecore::uint QRYWZNMSBSBSBMNSUBSET = 632;
	const Sbecore::uint QRYWZNMSBSFRS1NRELATION = 633;
	const Sbecore::uint QRYWZNMSBSLIST = 634;
	const Sbecore::uint QRYWZNMSBSPST1NQUERYMOD = 635;
	const Sbecore::uint QRYWZNMSBSTOS1NRELATION = 636;
	const Sbecore::uint QRYWZNMSEQLIST = 637;
	const Sbecore::uint QRYWZNMSEQSEQ1NSTATE = 638;
	const Sbecore::uint QRYWZNMSGE1NSENSITIVITY = 639;
	const Sbecore::uint QRYWZNMSGELIST = 640;
	const Sbecore::uint QRYWZNMSGESQKMNSTUB = 641;
	const Sbecore::uint QRYWZNMSHT1NBOX = 642;
	const Sbecore::uint QRYWZNMSHTLIST = 643;
	const Sbecore::uint QRYWZNMSTBLIST = 644;
	const Sbecore::uint QRYWZNMSTBMNCALL = 645;
	const Sbecore::uint QRYWZNMSTBMNSQUAWK = 646;
	const Sbecore::uint QRYWZNMSTBSUBMNSTUB = 647;
	const Sbecore::uint QRYWZNMSTBSUPMNSTUB = 648;
	const Sbecore::uint QRYWZNMSTEAACTION = 649;
	const Sbecore::uint QRYWZNMSTEATRIG = 650;
	const Sbecore::uint QRYWZNMSTELIST = 651;
	const Sbecore::uint QRYWZNMTAGLIST = 652;
	const Sbecore::uint QRYWZNMTBL1NCHECK = 653;
	const Sbecore::uint QRYWZNMTBL1NIMPEXP = 654;
	const Sbecore::uint QRYWZNMTBL1NSTUB = 655;
	const Sbecore::uint QRYWZNMTBL1NSUBSET = 656;
	const Sbecore::uint QRYWZNMTBLALOADFCT = 657;
	const Sbecore::uint QRYWZNMTBLATITLE = 658;
	const Sbecore::uint QRYWZNMTBLFCT1NTABLECOL = 659;
	const Sbecore::uint QRYWZNMTBLFR1NRELATION = 660;
	const Sbecore::uint QRYWZNMTBLHK1NVECTOR = 661;
	const Sbecore::uint QRYWZNMTBLLIST = 662;
	const Sbecore::uint QRYWZNMTBLMNQUERY = 663;
	const Sbecore::uint QRYWZNMTBLMNVECTOR = 664;
	const Sbecore::uint QRYWZNMTBLPST1NQUERYMOD = 665;
	const Sbecore::uint QRYWZNMTBLREF1NCALL = 666;
	const Sbecore::uint QRYWZNMTBLREF1NDIALOG = 667;
	const Sbecore::uint QRYWZNMTBLREF1NPANEL = 668;
	const Sbecore::uint QRYWZNMTBLREF1NQUERYMOD = 669;
	const Sbecore::uint QRYWZNMTBLREF1NRTBLOCK = 670;
	const Sbecore::uint QRYWZNMTBLSRC1NFEED = 671;
	const Sbecore::uint QRYWZNMTBLTBL1NTABLECOL = 672;
	const Sbecore::uint QRYWZNMTBLTO1NRELATION = 673;
	const Sbecore::uint QRYWZNMTCO1NCHECK = 674;
	const Sbecore::uint QRYWZNMTCO1NIMPEXPCOL = 675;
	const Sbecore::uint QRYWZNMTCO1NQUERYCOL = 676;
	const Sbecore::uint QRYWZNMTCOATITLE = 677;
	const Sbecore::uint QRYWZNMTCOLIST = 678;
	const Sbecore::uint QRYWZNMTCOREF1NCONTROL = 679;
	const Sbecore::uint QRYWZNMTCOREF1NQUERYMOD = 680;
	const Sbecore::uint QRYWZNMUSGAACCESS = 681;
	const Sbecore::uint QRYWZNMUSGLIST = 682;
	const Sbecore::uint QRYWZNMUSGMNUSER = 683;
	const Sbecore::uint QRYWZNMUSR1NSESSION = 684;
	const Sbecore::uint QRYWZNMUSRAACCESS = 685;
	const Sbecore::uint QRYWZNMUSRLIST = 686;
	const Sbecore::uint QRYWZNMUSRMNUSERGROUP = 687;
	const Sbecore::uint QRYWZNMVECATITLE = 688;
	const Sbecore::uint QRYWZNMVECFCT1NTABLECOL = 689;
	const Sbecore::uint QRYWZNMVECLIST = 690;
	const Sbecore::uint QRYWZNMVECMNTABLE = 691;
	const Sbecore::uint QRYWZNMVECPST1NQUERYMOD = 692;
	const Sbecore::uint QRYWZNMVECREF1NPANEL = 693;
	const Sbecore::uint QRYWZNMVECSRC1NFEED = 694;
	const Sbecore::uint QRYWZNMVECVEC1NVECTORITEM = 695;
	const Sbecore::uint QRYWZNMVER1NBLOCK = 696;
	const Sbecore::uint QRYWZNMVER1NCALL = 697;
	const Sbecore::uint QRYWZNMVER1NCAPABILITY = 698;
	const Sbecore::uint QRYWZNMVER1NCOMPONENT = 699;
	const Sbecore::uint QRYWZNMVER1NIMPEXPCPLX = 700;
	const Sbecore::uint QRYWZNMVER1NJOB = 701;
	const Sbecore::uint QRYWZNMVER1NOPPACK = 702;
	const Sbecore::uint QRYWZNMVER1NPRESET = 703;
	const Sbecore::uint QRYWZNMVER1NQUERY = 704;
	const Sbecore::uint QRYWZNMVER1NRELATION = 705;
	const Sbecore::uint QRYWZNMVER1NTABLE = 706;
	const Sbecore::uint QRYWZNMVER1NVECTOR = 707;
	const Sbecore::uint QRYWZNMVERBVR1NVERSION = 708;
	const Sbecore::uint QRYWZNMVERLIST = 709;
	const Sbecore::uint QRYWZNMVERMNLOCALE = 710;
	const Sbecore::uint QRYWZNMVERREF1NFILE = 711;
	const Sbecore::uint QRYWZNMVERVER1NAPP = 712;
	const Sbecore::uint QRYWZNMVERVER1NERROR = 713;
	const Sbecore::uint QRYWZNMVERVER1NMODULE = 714;
	const Sbecore::uint QRYWZNMVERVER1NVISUAL = 715;
	const Sbecore::uint QRYWZNMVISBOXCTX = 716;
	const Sbecore::uint QRYWZNMVISLINKCTX = 717;
	const Sbecore::uint QRYWZNMVISLIST = 718;
	const Sbecore::uint QRYWZNMVISREF1NFILE = 719;
	const Sbecore::uint QRYWZNMVISROWCTX = 720;
	const Sbecore::uint QRYWZNMVISVIS1NSHEET = 721;
	const Sbecore::uint QRYWZNMVITLIST = 722;
	const Sbecore::uint ROOTWZNM = 723;
	const Sbecore::uint SESSWZNM = 724;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
