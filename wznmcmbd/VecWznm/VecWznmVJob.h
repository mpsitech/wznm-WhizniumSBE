/**
	* \file VecWznmVJob.h
	* vector VecWznmVJob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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
	const Sbecore::uint CRDWZNMFIL = 12;
	const Sbecore::uint CRDWZNMIEL = 13;
	const Sbecore::uint CRDWZNMIEX = 14;
	const Sbecore::uint CRDWZNMIME = 15;
	const Sbecore::uint CRDWZNMJOB = 16;
	const Sbecore::uint CRDWZNMLIB = 17;
	const Sbecore::uint CRDWZNMLOC = 18;
	const Sbecore::uint CRDWZNMMCH = 19;
	const Sbecore::uint CRDWZNMMDL = 20;
	const Sbecore::uint CRDWZNMMTD = 21;
	const Sbecore::uint CRDWZNMMTY = 22;
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
	const Sbecore::uint DLGWZNMNAVLOAINI = 55;
	const Sbecore::uint DLGWZNMNAVMNGLIC = 56;
	const Sbecore::uint DLGWZNMPRJIMPEX = 57;
	const Sbecore::uint DLGWZNMPRJNEW = 58;
	const Sbecore::uint DLGWZNMRLSFINREPTR = 59;
	const Sbecore::uint DLGWZNMRLSSTAREPTR = 60;
	const Sbecore::uint DLGWZNMRLSWRITE = 61;
	const Sbecore::uint DLGWZNMUSRMNGKEYPAIR = 62;
	const Sbecore::uint DLGWZNMUTLEXTRIP = 63;
	const Sbecore::uint DLGWZNMUTLIEXCONV = 64;
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
	const Sbecore::uint DLGWZNMVERWRSTKIT = 79;
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
	const Sbecore::uint PNLWZNMAPP1NRTJOB = 93;
	const Sbecore::uint PNLWZNMAPPAPP1NSEQUENCE = 94;
	const Sbecore::uint PNLWZNMAPPDETAIL = 95;
	const Sbecore::uint PNLWZNMAPPHEADBAR = 96;
	const Sbecore::uint PNLWZNMAPPLIST = 97;
	const Sbecore::uint PNLWZNMAPPREC = 98;
	const Sbecore::uint PNLWZNMAPPREF1NFILE = 99;
	const Sbecore::uint PNLWZNMBLK1NRTDPCH = 100;
	const Sbecore::uint PNLWZNMBLKAITEM = 101;
	const Sbecore::uint PNLWZNMBLKDETAIL = 102;
	const Sbecore::uint PNLWZNMBLKHEADBAR = 103;
	const Sbecore::uint PNLWZNMBLKLIST = 104;
	const Sbecore::uint PNLWZNMBLKREC = 105;
	const Sbecore::uint PNLWZNMBLKREF1NRTBLOCK = 106;
	const Sbecore::uint PNLWZNMCAL1NSENSITIVITY = 107;
	const Sbecore::uint PNLWZNMCALDETAIL = 108;
	const Sbecore::uint PNLWZNMCALHEADBAR = 109;
	const Sbecore::uint PNLWZNMCALLIST = 110;
	const Sbecore::uint PNLWZNMCALMNSTUB = 111;
	const Sbecore::uint PNLWZNMCALREC = 112;
	const Sbecore::uint PNLWZNMCAPAPAR = 113;
	const Sbecore::uint PNLWZNMCAPDETAIL = 114;
	const Sbecore::uint PNLWZNMCAPHEADBAR = 115;
	const Sbecore::uint PNLWZNMCAPLIST = 116;
	const Sbecore::uint PNLWZNMCAPREC = 117;
	const Sbecore::uint PNLWZNMCAR1NDIALOG = 118;
	const Sbecore::uint PNLWZNMCARCAR1NPANEL = 119;
	const Sbecore::uint PNLWZNMCARDETAIL = 120;
	const Sbecore::uint PNLWZNMCARHEADBAR = 121;
	const Sbecore::uint PNLWZNMCARHK1NCONTROL = 122;
	const Sbecore::uint PNLWZNMCARLIST = 123;
	const Sbecore::uint PNLWZNMCARREC = 124;
	const Sbecore::uint PNLWZNMCHKDETAIL = 125;
	const Sbecore::uint PNLWZNMCHKHEADBAR = 126;
	const Sbecore::uint PNLWZNMCHKLIST = 127;
	const Sbecore::uint PNLWZNMCHKREC = 128;
	const Sbecore::uint PNLWZNMCHKREF1NCALL = 129;
	const Sbecore::uint PNLWZNMCMP1NRELEASE = 130;
	const Sbecore::uint PNLWZNMCMPDETAIL = 131;
	const Sbecore::uint PNLWZNMCMPHEADBAR = 132;
	const Sbecore::uint PNLWZNMCMPLIST = 133;
	const Sbecore::uint PNLWZNMCMPMNLIBRARY = 134;
	const Sbecore::uint PNLWZNMCMPMNOPPACK = 135;
	const Sbecore::uint PNLWZNMCMPREC = 136;
	const Sbecore::uint PNLWZNMCONAPAR = 137;
	const Sbecore::uint PNLWZNMCONDETAIL = 138;
	const Sbecore::uint PNLWZNMCONFEDREF1NRTBLOCK = 139;
	const Sbecore::uint PNLWZNMCONHEADBAR = 140;
	const Sbecore::uint PNLWZNMCONLIST = 141;
	const Sbecore::uint PNLWZNMCONREC = 142;
	const Sbecore::uint PNLWZNMCONSUP1NCONTROL = 143;
	const Sbecore::uint PNLWZNMCTP1NTAG = 144;
	const Sbecore::uint PNLWZNMCTPAPAR = 145;
	const Sbecore::uint PNLWZNMCTPDETAIL = 146;
	const Sbecore::uint PNLWZNMCTPHEADBAR = 147;
	const Sbecore::uint PNLWZNMCTPKKEY = 148;
	const Sbecore::uint PNLWZNMCTPKPARKEY = 149;
	const Sbecore::uint PNLWZNMCTPLIST = 150;
	const Sbecore::uint PNLWZNMCTPREC = 151;
	const Sbecore::uint PNLWZNMCTPTPL1NCAPABILITY = 152;
	const Sbecore::uint PNLWZNMDLGDETAIL = 153;
	const Sbecore::uint PNLWZNMDLGHEADBAR = 154;
	const Sbecore::uint PNLWZNMDLGHK1NCONTROL = 155;
	const Sbecore::uint PNLWZNMDLGLIST = 156;
	const Sbecore::uint PNLWZNMDLGMNQUERY = 157;
	const Sbecore::uint PNLWZNMDLGREC = 158;
	const Sbecore::uint PNLWZNMDLGREF1NCONTROL = 159;
	const Sbecore::uint PNLWZNMERRDETAIL = 160;
	const Sbecore::uint PNLWZNMERRHEADBAR = 161;
	const Sbecore::uint PNLWZNMERRLIST = 162;
	const Sbecore::uint PNLWZNMERRREC = 163;
	const Sbecore::uint PNLWZNMFILDETAIL = 164;
	const Sbecore::uint PNLWZNMFILHEADBAR = 165;
	const Sbecore::uint PNLWZNMFILLIST = 166;
	const Sbecore::uint PNLWZNMFILREC = 167;
	const Sbecore::uint PNLWZNMIELDETAIL = 168;
	const Sbecore::uint PNLWZNMIELHEADBAR = 169;
	const Sbecore::uint PNLWZNMIELLIST = 170;
	const Sbecore::uint PNLWZNMIELREC = 171;
	const Sbecore::uint PNLWZNMIEX1NIMPEXP = 172;
	const Sbecore::uint PNLWZNMIEXDETAIL = 173;
	const Sbecore::uint PNLWZNMIEXHEADBAR = 174;
	const Sbecore::uint PNLWZNMIEXHK1NVECTOR = 175;
	const Sbecore::uint PNLWZNMIEXLIST = 176;
	const Sbecore::uint PNLWZNMIEXREC = 177;
	const Sbecore::uint PNLWZNMIEXREF1NDIALOG = 178;
	const Sbecore::uint PNLWZNMIMEDETAIL = 179;
	const Sbecore::uint PNLWZNMIMEHEADBAR = 180;
	const Sbecore::uint PNLWZNMIMEHK1NVECTOR = 181;
	const Sbecore::uint PNLWZNMIMEIME1NIMPEXPCOL = 182;
	const Sbecore::uint PNLWZNMIMELIST = 183;
	const Sbecore::uint PNLWZNMIMEREC = 184;
	const Sbecore::uint PNLWZNMIMESUP1NIMPEXP = 185;
	const Sbecore::uint PNLWZNMJOB1NMETHOD = 186;
	const Sbecore::uint PNLWZNMJOB1NRTJOB = 187;
	const Sbecore::uint PNLWZNMJOB1NSENSITIVITY = 188;
	const Sbecore::uint PNLWZNMJOBACMD = 189;
	const Sbecore::uint PNLWZNMJOBAVAR = 190;
	const Sbecore::uint PNLWZNMJOBDETAIL = 191;
	const Sbecore::uint PNLWZNMJOBHEADBAR = 192;
	const Sbecore::uint PNLWZNMJOBHK1NVECTOR = 193;
	const Sbecore::uint PNLWZNMJOBJOB1NSTAGE = 194;
	const Sbecore::uint PNLWZNMJOBLIST = 195;
	const Sbecore::uint PNLWZNMJOBMNOP = 196;
	const Sbecore::uint PNLWZNMJOBMNOPPACK = 197;
	const Sbecore::uint PNLWZNMJOBREC = 198;
	const Sbecore::uint PNLWZNMJOBREF1NBLOCK = 199;
	const Sbecore::uint PNLWZNMJOBSUBMNJOB = 200;
	const Sbecore::uint PNLWZNMJOBSUPMNJOB = 201;
	const Sbecore::uint PNLWZNMLIBAMAKEFILE = 202;
	const Sbecore::uint PNLWZNMLIBAPKGLIST = 203;
	const Sbecore::uint PNLWZNMLIBDETAIL = 204;
	const Sbecore::uint PNLWZNMLIBHEADBAR = 205;
	const Sbecore::uint PNLWZNMLIBLIST = 206;
	const Sbecore::uint PNLWZNMLIBMNCOMPONENT = 207;
	const Sbecore::uint PNLWZNMLIBMNOPPACK = 208;
	const Sbecore::uint PNLWZNMLIBREC = 209;
	const Sbecore::uint PNLWZNMLIBREF1NFILE = 210;
	const Sbecore::uint PNLWZNMLOCDETAIL = 211;
	const Sbecore::uint PNLWZNMLOCHEADBAR = 212;
	const Sbecore::uint PNLWZNMLOCLIST = 213;
	const Sbecore::uint PNLWZNMLOCMNVERSION = 214;
	const Sbecore::uint PNLWZNMLOCREC = 215;
	const Sbecore::uint PNLWZNMMCH1NRELEASE = 216;
	const Sbecore::uint PNLWZNMMCHAPAR = 217;
	const Sbecore::uint PNLWZNMMCHDETAIL = 218;
	const Sbecore::uint PNLWZNMMCHHEADBAR = 219;
	const Sbecore::uint PNLWZNMMCHLIST = 220;
	const Sbecore::uint PNLWZNMMCHREC = 221;
	const Sbecore::uint PNLWZNMMDLDETAIL = 222;
	const Sbecore::uint PNLWZNMMDLHEADBAR = 223;
	const Sbecore::uint PNLWZNMMDLLIST = 224;
	const Sbecore::uint PNLWZNMMDLMDL1NCARD = 225;
	const Sbecore::uint PNLWZNMMDLREC = 226;
	const Sbecore::uint PNLWZNMMDLREF1NPANEL = 227;
	const Sbecore::uint PNLWZNMMTDAINVPAR = 228;
	const Sbecore::uint PNLWZNMMTDARETPAR = 229;
	const Sbecore::uint PNLWZNMMTDDETAIL = 230;
	const Sbecore::uint PNLWZNMMTDHEADBAR = 231;
	const Sbecore::uint PNLWZNMMTDLIST = 232;
	const Sbecore::uint PNLWZNMMTDREC = 233;
	const Sbecore::uint PNLWZNMMTY1NMACHINE = 234;
	const Sbecore::uint PNLWZNMMTYAMAKEFILE = 235;
	const Sbecore::uint PNLWZNMMTYDETAIL = 236;
	const Sbecore::uint PNLWZNMMTYHEADBAR = 237;
	const Sbecore::uint PNLWZNMMTYLIST = 238;
	const Sbecore::uint PNLWZNMMTYREC = 239;
	const Sbecore::uint PNLWZNMNAVADMIN = 240;
	const Sbecore::uint PNLWZNMNAVAPPDEV = 241;
	const Sbecore::uint PNLWZNMNAVAUXFCT = 242;
	const Sbecore::uint PNLWZNMNAVCOMP = 243;
	const Sbecore::uint PNLWZNMNAVDBSTR = 244;
	const Sbecore::uint PNLWZNMNAVDEPLOY = 245;
	const Sbecore::uint PNLWZNMNAVGLOBAL = 246;
	const Sbecore::uint PNLWZNMNAVHEADBAR = 247;
	const Sbecore::uint PNLWZNMNAVJOB = 248;
	const Sbecore::uint PNLWZNMNAVPRE = 249;
	const Sbecore::uint PNLWZNMNAVPROJECT = 250;
	const Sbecore::uint PNLWZNMNAVUIX = 251;
	const Sbecore::uint PNLWZNMOPK1NOP = 252;
	const Sbecore::uint PNLWZNMOPKAINVARG = 253;
	const Sbecore::uint PNLWZNMOPKARETVAL = 254;
	const Sbecore::uint PNLWZNMOPKDETAIL = 255;
	const Sbecore::uint PNLWZNMOPKHEADBAR = 256;
	const Sbecore::uint PNLWZNMOPKLIST = 257;
	const Sbecore::uint PNLWZNMOPKMNCOMPONENT = 258;
	const Sbecore::uint PNLWZNMOPKMNJOB = 259;
	const Sbecore::uint PNLWZNMOPKMNLIBRARY = 260;
	const Sbecore::uint PNLWZNMOPKREC = 261;
	const Sbecore::uint PNLWZNMOPKREF1NBLOCK = 262;
	const Sbecore::uint PNLWZNMOPKSQKMNSTUB = 263;
	const Sbecore::uint PNLWZNMOPXAINVARG = 264;
	const Sbecore::uint PNLWZNMOPXARETVAL = 265;
	const Sbecore::uint PNLWZNMOPXDETAIL = 266;
	const Sbecore::uint PNLWZNMOPXHEADBAR = 267;
	const Sbecore::uint PNLWZNMOPXLIST = 268;
	const Sbecore::uint PNLWZNMOPXMNJOB = 269;
	const Sbecore::uint PNLWZNMOPXREC = 270;
	const Sbecore::uint PNLWZNMOPXREF1NBLOCK = 271;
	const Sbecore::uint PNLWZNMOPXSQKMNSTUB = 272;
	const Sbecore::uint PNLWZNMPNLDETAIL = 273;
	const Sbecore::uint PNLWZNMPNLHEADBAR = 274;
	const Sbecore::uint PNLWZNMPNLHK1NCONTROL = 275;
	const Sbecore::uint PNLWZNMPNLLIST = 276;
	const Sbecore::uint PNLWZNMPNLMNQUERY = 277;
	const Sbecore::uint PNLWZNMPNLREC = 278;
	const Sbecore::uint PNLWZNMPRJ1NVERSION = 279;
	const Sbecore::uint PNLWZNMPRJDETAIL = 280;
	const Sbecore::uint PNLWZNMPRJHEADBAR = 281;
	const Sbecore::uint PNLWZNMPRJLIST = 282;
	const Sbecore::uint PNLWZNMPRJMNPERSON = 283;
	const Sbecore::uint PNLWZNMPRJREC = 284;
	const Sbecore::uint PNLWZNMPRSADETAIL = 285;
	const Sbecore::uint PNLWZNMPRSDETAIL = 286;
	const Sbecore::uint PNLWZNMPRSHEADBAR = 287;
	const Sbecore::uint PNLWZNMPRSLIST = 288;
	const Sbecore::uint PNLWZNMPRSMNPROJECT = 289;
	const Sbecore::uint PNLWZNMPRSREC = 290;
	const Sbecore::uint PNLWZNMPST1NQUERYMOD = 291;
	const Sbecore::uint PNLWZNMPSTDETAIL = 292;
	const Sbecore::uint PNLWZNMPSTHEADBAR = 293;
	const Sbecore::uint PNLWZNMPSTLIST = 294;
	const Sbecore::uint PNLWZNMPSTREC = 295;
	const Sbecore::uint PNLWZNMQCODETAIL = 296;
	const Sbecore::uint PNLWZNMQCOHEADBAR = 297;
	const Sbecore::uint PNLWZNMQCOLIST = 298;
	const Sbecore::uint PNLWZNMQCOREC = 299;
	const Sbecore::uint PNLWZNMQCOREF1NCONTROL = 300;
	const Sbecore::uint PNLWZNMQMDDETAIL = 301;
	const Sbecore::uint PNLWZNMQMDHEADBAR = 302;
	const Sbecore::uint PNLWZNMQMDLIST = 303;
	const Sbecore::uint PNLWZNMQMDREC = 304;
	const Sbecore::uint PNLWZNMQRY1NQUERYMOD = 305;
	const Sbecore::uint PNLWZNMQRYACLAUSE = 306;
	const Sbecore::uint PNLWZNMQRYAORDER = 307;
	const Sbecore::uint PNLWZNMQRYDETAIL = 308;
	const Sbecore::uint PNLWZNMQRYHEADBAR = 309;
	const Sbecore::uint PNLWZNMQRYLIST = 310;
	const Sbecore::uint PNLWZNMQRYMNDIALOG = 311;
	const Sbecore::uint PNLWZNMQRYMNPANEL = 312;
	const Sbecore::uint PNLWZNMQRYMNTABLE = 313;
	const Sbecore::uint PNLWZNMQRYQRY1NQUERYCOL = 314;
	const Sbecore::uint PNLWZNMQRYREC = 315;
	const Sbecore::uint PNLWZNMQRYSUP1NQUERY = 316;
	const Sbecore::uint PNLWZNMREL1NTABLECOL = 317;
	const Sbecore::uint PNLWZNMRELATITLE = 318;
	const Sbecore::uint PNLWZNMRELDETAIL = 319;
	const Sbecore::uint PNLWZNMRELHEADBAR = 320;
	const Sbecore::uint PNLWZNMRELLIST = 321;
	const Sbecore::uint PNLWZNMRELREC = 322;
	const Sbecore::uint PNLWZNMRELREF1NCONTROL = 323;
	const Sbecore::uint PNLWZNMRELREF1NDIALOG = 324;
	const Sbecore::uint PNLWZNMRELREF1NPANEL = 325;
	const Sbecore::uint PNLWZNMRELSUP1NRELATION = 326;
	const Sbecore::uint PNLWZNMRLSDETAIL = 327;
	const Sbecore::uint PNLWZNMRLSHEADBAR = 328;
	const Sbecore::uint PNLWZNMRLSLIST = 329;
	const Sbecore::uint PNLWZNMRLSREC = 330;
	const Sbecore::uint PNLWZNMRTJ1NRTBLOCK = 331;
	const Sbecore::uint PNLWZNMRTJ1NRTDPCH = 332;
	const Sbecore::uint PNLWZNMRTJDETAIL = 333;
	const Sbecore::uint PNLWZNMRTJHEADBAR = 334;
	const Sbecore::uint PNLWZNMRTJLIST = 335;
	const Sbecore::uint PNLWZNMRTJREC = 336;
	const Sbecore::uint PNLWZNMRTJSUP1NRTJOB = 337;
	const Sbecore::uint PNLWZNMSBS1NSTUB = 338;
	const Sbecore::uint PNLWZNMSBS1NTABLECOL = 339;
	const Sbecore::uint PNLWZNMSBSASBMNSUBSET = 340;
	const Sbecore::uint PNLWZNMSBSATITLE = 341;
	const Sbecore::uint PNLWZNMSBSBSBMNSUBSET = 342;
	const Sbecore::uint PNLWZNMSBSDETAIL = 343;
	const Sbecore::uint PNLWZNMSBSFRS1NRELATION = 344;
	const Sbecore::uint PNLWZNMSBSHEADBAR = 345;
	const Sbecore::uint PNLWZNMSBSLIST = 346;
	const Sbecore::uint PNLWZNMSBSPST1NQUERYMOD = 347;
	const Sbecore::uint PNLWZNMSBSREC = 348;
	const Sbecore::uint PNLWZNMSBSTOS1NRELATION = 349;
	const Sbecore::uint PNLWZNMSEQDETAIL = 350;
	const Sbecore::uint PNLWZNMSEQHEADBAR = 351;
	const Sbecore::uint PNLWZNMSEQLIST = 352;
	const Sbecore::uint PNLWZNMSEQREC = 353;
	const Sbecore::uint PNLWZNMSEQSEQ1NSTATE = 354;
	const Sbecore::uint PNLWZNMSGE1NSENSITIVITY = 355;
	const Sbecore::uint PNLWZNMSGEDETAIL = 356;
	const Sbecore::uint PNLWZNMSGEHEADBAR = 357;
	const Sbecore::uint PNLWZNMSGELIST = 358;
	const Sbecore::uint PNLWZNMSGEREC = 359;
	const Sbecore::uint PNLWZNMSGESQKMNSTUB = 360;
	const Sbecore::uint PNLWZNMSTBDETAIL = 361;
	const Sbecore::uint PNLWZNMSTBHEADBAR = 362;
	const Sbecore::uint PNLWZNMSTBLIST = 363;
	const Sbecore::uint PNLWZNMSTBMNCALL = 364;
	const Sbecore::uint PNLWZNMSTBMNSQUAWK = 365;
	const Sbecore::uint PNLWZNMSTBREC = 366;
	const Sbecore::uint PNLWZNMSTBSUBMNSTUB = 367;
	const Sbecore::uint PNLWZNMSTBSUPMNSTUB = 368;
	const Sbecore::uint PNLWZNMSTEASTEP = 369;
	const Sbecore::uint PNLWZNMSTEDETAIL = 370;
	const Sbecore::uint PNLWZNMSTEHEADBAR = 371;
	const Sbecore::uint PNLWZNMSTELIST = 372;
	const Sbecore::uint PNLWZNMSTEREC = 373;
	const Sbecore::uint PNLWZNMTAGDETAIL = 374;
	const Sbecore::uint PNLWZNMTAGHEADBAR = 375;
	const Sbecore::uint PNLWZNMTAGLIST = 376;
	const Sbecore::uint PNLWZNMTAGREC = 377;
	const Sbecore::uint PNLWZNMTBL1NCHECK = 378;
	const Sbecore::uint PNLWZNMTBL1NIMPEXP = 379;
	const Sbecore::uint PNLWZNMTBL1NSTUB = 380;
	const Sbecore::uint PNLWZNMTBL1NSUBSET = 381;
	const Sbecore::uint PNLWZNMTBLALOADFCT = 382;
	const Sbecore::uint PNLWZNMTBLATITLE = 383;
	const Sbecore::uint PNLWZNMTBLDETAIL = 384;
	const Sbecore::uint PNLWZNMTBLFCT1NTABLECOL = 385;
	const Sbecore::uint PNLWZNMTBLFR1NRELATION = 386;
	const Sbecore::uint PNLWZNMTBLHEADBAR = 387;
	const Sbecore::uint PNLWZNMTBLHK1NVECTOR = 388;
	const Sbecore::uint PNLWZNMTBLLIST = 389;
	const Sbecore::uint PNLWZNMTBLMNQUERY = 390;
	const Sbecore::uint PNLWZNMTBLMNVECTOR = 391;
	const Sbecore::uint PNLWZNMTBLPST1NQUERYMOD = 392;
	const Sbecore::uint PNLWZNMTBLREC = 393;
	const Sbecore::uint PNLWZNMTBLREF1NCALL = 394;
	const Sbecore::uint PNLWZNMTBLREF1NDIALOG = 395;
	const Sbecore::uint PNLWZNMTBLREF1NPANEL = 396;
	const Sbecore::uint PNLWZNMTBLREF1NQUERYMOD = 397;
	const Sbecore::uint PNLWZNMTBLREF1NRTBLOCK = 398;
	const Sbecore::uint PNLWZNMTBLSRC1NFEED = 399;
	const Sbecore::uint PNLWZNMTBLTBL1NTABLECOL = 400;
	const Sbecore::uint PNLWZNMTBLTO1NRELATION = 401;
	const Sbecore::uint PNLWZNMTCO1NCHECK = 402;
	const Sbecore::uint PNLWZNMTCO1NIMPEXPCOL = 403;
	const Sbecore::uint PNLWZNMTCO1NQUERYCOL = 404;
	const Sbecore::uint PNLWZNMTCOATITLE = 405;
	const Sbecore::uint PNLWZNMTCODETAIL = 406;
	const Sbecore::uint PNLWZNMTCOHEADBAR = 407;
	const Sbecore::uint PNLWZNMTCOLIST = 408;
	const Sbecore::uint PNLWZNMTCOREC = 409;
	const Sbecore::uint PNLWZNMTCOREF1NCONTROL = 410;
	const Sbecore::uint PNLWZNMTCOREF1NQUERYMOD = 411;
	const Sbecore::uint PNLWZNMUSGAACCESS = 412;
	const Sbecore::uint PNLWZNMUSGDETAIL = 413;
	const Sbecore::uint PNLWZNMUSGHEADBAR = 414;
	const Sbecore::uint PNLWZNMUSGLIST = 415;
	const Sbecore::uint PNLWZNMUSGMNUSER = 416;
	const Sbecore::uint PNLWZNMUSGREC = 417;
	const Sbecore::uint PNLWZNMUSR1NSESSION = 418;
	const Sbecore::uint PNLWZNMUSRAACCESS = 419;
	const Sbecore::uint PNLWZNMUSRDETAIL = 420;
	const Sbecore::uint PNLWZNMUSRHEADBAR = 421;
	const Sbecore::uint PNLWZNMUSRLIST = 422;
	const Sbecore::uint PNLWZNMUSRMNUSERGROUP = 423;
	const Sbecore::uint PNLWZNMUSRREC = 424;
	const Sbecore::uint PNLWZNMUTLHEADBAR = 425;
	const Sbecore::uint PNLWZNMVECATITLE = 426;
	const Sbecore::uint PNLWZNMVECDETAIL = 427;
	const Sbecore::uint PNLWZNMVECFCT1NTABLECOL = 428;
	const Sbecore::uint PNLWZNMVECHEADBAR = 429;
	const Sbecore::uint PNLWZNMVECLIST = 430;
	const Sbecore::uint PNLWZNMVECMNTABLE = 431;
	const Sbecore::uint PNLWZNMVECPST1NQUERYMOD = 432;
	const Sbecore::uint PNLWZNMVECREC = 433;
	const Sbecore::uint PNLWZNMVECREF1NPANEL = 434;
	const Sbecore::uint PNLWZNMVECSRC1NFEED = 435;
	const Sbecore::uint PNLWZNMVECVEC1NVECTORITEM = 436;
	const Sbecore::uint PNLWZNMVER1NBLOCK = 437;
	const Sbecore::uint PNLWZNMVER1NCALL = 438;
	const Sbecore::uint PNLWZNMVER1NCAPABILITY = 439;
	const Sbecore::uint PNLWZNMVER1NCOMPONENT = 440;
	const Sbecore::uint PNLWZNMVER1NIMPEXPCPLX = 441;
	const Sbecore::uint PNLWZNMVER1NJOB = 442;
	const Sbecore::uint PNLWZNMVER1NOPPACK = 443;
	const Sbecore::uint PNLWZNMVER1NPRESET = 444;
	const Sbecore::uint PNLWZNMVER1NQUERY = 445;
	const Sbecore::uint PNLWZNMVER1NRELATION = 446;
	const Sbecore::uint PNLWZNMVER1NTABLE = 447;
	const Sbecore::uint PNLWZNMVER1NVECTOR = 448;
	const Sbecore::uint PNLWZNMVERBVR1NVERSION = 449;
	const Sbecore::uint PNLWZNMVERDETAIL = 450;
	const Sbecore::uint PNLWZNMVERHEADBAR = 451;
	const Sbecore::uint PNLWZNMVERLIST = 452;
	const Sbecore::uint PNLWZNMVERMNLOCALE = 453;
	const Sbecore::uint PNLWZNMVERREC = 454;
	const Sbecore::uint PNLWZNMVERREF1NFILE = 455;
	const Sbecore::uint PNLWZNMVERVER1NAPP = 456;
	const Sbecore::uint PNLWZNMVERVER1NERROR = 457;
	const Sbecore::uint PNLWZNMVERVER1NMODULE = 458;
	const Sbecore::uint PNLWZNMVITDETAIL = 459;
	const Sbecore::uint PNLWZNMVITHEADBAR = 460;
	const Sbecore::uint PNLWZNMVITLIST = 461;
	const Sbecore::uint PNLWZNMVITREC = 462;
	const Sbecore::uint QRYWZNMAPP1NRTJOB = 463;
	const Sbecore::uint QRYWZNMAPPAPP1NSEQUENCE = 464;
	const Sbecore::uint QRYWZNMAPPLIST = 465;
	const Sbecore::uint QRYWZNMAPPREF1NFILE = 466;
	const Sbecore::uint QRYWZNMBLK1NRTDPCH = 467;
	const Sbecore::uint QRYWZNMBLKAITEM = 468;
	const Sbecore::uint QRYWZNMBLKLIST = 469;
	const Sbecore::uint QRYWZNMBLKREF1NRTBLOCK = 470;
	const Sbecore::uint QRYWZNMCAL1NSENSITIVITY = 471;
	const Sbecore::uint QRYWZNMCALLIST = 472;
	const Sbecore::uint QRYWZNMCALMNSTUB = 473;
	const Sbecore::uint QRYWZNMCAPAPAR = 474;
	const Sbecore::uint QRYWZNMCAPLIST = 475;
	const Sbecore::uint QRYWZNMCAR1NDIALOG = 476;
	const Sbecore::uint QRYWZNMCARCAR1NPANEL = 477;
	const Sbecore::uint QRYWZNMCARHK1NCONTROL = 478;
	const Sbecore::uint QRYWZNMCARLIST = 479;
	const Sbecore::uint QRYWZNMCHKLIST = 480;
	const Sbecore::uint QRYWZNMCHKREF1NCALL = 481;
	const Sbecore::uint QRYWZNMCMP1NRELEASE = 482;
	const Sbecore::uint QRYWZNMCMPLIST = 483;
	const Sbecore::uint QRYWZNMCMPMNLIBRARY = 484;
	const Sbecore::uint QRYWZNMCMPMNOPPACK = 485;
	const Sbecore::uint QRYWZNMCONAPAR = 486;
	const Sbecore::uint QRYWZNMCONFEDREF1NRTBLOCK = 487;
	const Sbecore::uint QRYWZNMCONLIST = 488;
	const Sbecore::uint QRYWZNMCONSUP1NCONTROL = 489;
	const Sbecore::uint QRYWZNMCTP1NTAG = 490;
	const Sbecore::uint QRYWZNMCTPAPAR = 491;
	const Sbecore::uint QRYWZNMCTPKKEY = 492;
	const Sbecore::uint QRYWZNMCTPKPARKEY = 493;
	const Sbecore::uint QRYWZNMCTPLIST = 494;
	const Sbecore::uint QRYWZNMCTPTPL1NCAPABILITY = 495;
	const Sbecore::uint QRYWZNMDLGHK1NCONTROL = 496;
	const Sbecore::uint QRYWZNMDLGLIST = 497;
	const Sbecore::uint QRYWZNMDLGMNQUERY = 498;
	const Sbecore::uint QRYWZNMDLGREF1NCONTROL = 499;
	const Sbecore::uint QRYWZNMERRLIST = 500;
	const Sbecore::uint QRYWZNMFILLIST = 501;
	const Sbecore::uint QRYWZNMIELLIST = 502;
	const Sbecore::uint QRYWZNMIEX1NIMPEXP = 503;
	const Sbecore::uint QRYWZNMIEXHK1NVECTOR = 504;
	const Sbecore::uint QRYWZNMIEXLIST = 505;
	const Sbecore::uint QRYWZNMIEXREF1NDIALOG = 506;
	const Sbecore::uint QRYWZNMIMEHK1NVECTOR = 507;
	const Sbecore::uint QRYWZNMIMEIME1NIMPEXPCOL = 508;
	const Sbecore::uint QRYWZNMIMELIST = 509;
	const Sbecore::uint QRYWZNMIMESUP1NIMPEXP = 510;
	const Sbecore::uint QRYWZNMJOB1NMETHOD = 511;
	const Sbecore::uint QRYWZNMJOB1NRTJOB = 512;
	const Sbecore::uint QRYWZNMJOB1NSENSITIVITY = 513;
	const Sbecore::uint QRYWZNMJOBACMD = 514;
	const Sbecore::uint QRYWZNMJOBAVAR = 515;
	const Sbecore::uint QRYWZNMJOBHK1NVECTOR = 516;
	const Sbecore::uint QRYWZNMJOBJOB1NSTAGE = 517;
	const Sbecore::uint QRYWZNMJOBLIST = 518;
	const Sbecore::uint QRYWZNMJOBMNOP = 519;
	const Sbecore::uint QRYWZNMJOBMNOPPACK = 520;
	const Sbecore::uint QRYWZNMJOBREF1NBLOCK = 521;
	const Sbecore::uint QRYWZNMJOBSUBMNJOB = 522;
	const Sbecore::uint QRYWZNMJOBSUPMNJOB = 523;
	const Sbecore::uint QRYWZNMLIBAMAKEFILE = 524;
	const Sbecore::uint QRYWZNMLIBAPKGLIST = 525;
	const Sbecore::uint QRYWZNMLIBLIST = 526;
	const Sbecore::uint QRYWZNMLIBMNCOMPONENT = 527;
	const Sbecore::uint QRYWZNMLIBMNOPPACK = 528;
	const Sbecore::uint QRYWZNMLIBREF1NFILE = 529;
	const Sbecore::uint QRYWZNMLOCLIST = 530;
	const Sbecore::uint QRYWZNMLOCMNVERSION = 531;
	const Sbecore::uint QRYWZNMMCH1NRELEASE = 532;
	const Sbecore::uint QRYWZNMMCHAPAR = 533;
	const Sbecore::uint QRYWZNMMCHLIST = 534;
	const Sbecore::uint QRYWZNMMDLLIST = 535;
	const Sbecore::uint QRYWZNMMDLMDL1NCARD = 536;
	const Sbecore::uint QRYWZNMMDLREF1NPANEL = 537;
	const Sbecore::uint QRYWZNMMTDAINVPAR = 538;
	const Sbecore::uint QRYWZNMMTDARETPAR = 539;
	const Sbecore::uint QRYWZNMMTDLIST = 540;
	const Sbecore::uint QRYWZNMMTY1NMACHINE = 541;
	const Sbecore::uint QRYWZNMMTYAMAKEFILE = 542;
	const Sbecore::uint QRYWZNMMTYLIST = 543;
	const Sbecore::uint QRYWZNMOPK1NOP = 544;
	const Sbecore::uint QRYWZNMOPKAINVARG = 545;
	const Sbecore::uint QRYWZNMOPKARETVAL = 546;
	const Sbecore::uint QRYWZNMOPKLIST = 547;
	const Sbecore::uint QRYWZNMOPKMNCOMPONENT = 548;
	const Sbecore::uint QRYWZNMOPKMNJOB = 549;
	const Sbecore::uint QRYWZNMOPKMNLIBRARY = 550;
	const Sbecore::uint QRYWZNMOPKREF1NBLOCK = 551;
	const Sbecore::uint QRYWZNMOPKSQKMNSTUB = 552;
	const Sbecore::uint QRYWZNMOPXAINVARG = 553;
	const Sbecore::uint QRYWZNMOPXARETVAL = 554;
	const Sbecore::uint QRYWZNMOPXLIST = 555;
	const Sbecore::uint QRYWZNMOPXMNJOB = 556;
	const Sbecore::uint QRYWZNMOPXREF1NBLOCK = 557;
	const Sbecore::uint QRYWZNMOPXSQKMNSTUB = 558;
	const Sbecore::uint QRYWZNMPNLHK1NCONTROL = 559;
	const Sbecore::uint QRYWZNMPNLLIST = 560;
	const Sbecore::uint QRYWZNMPNLMNQUERY = 561;
	const Sbecore::uint QRYWZNMPRJ1NVERSION = 562;
	const Sbecore::uint QRYWZNMPRJLIST = 563;
	const Sbecore::uint QRYWZNMPRJMNPERSON = 564;
	const Sbecore::uint QRYWZNMPRSADETAIL = 565;
	const Sbecore::uint QRYWZNMPRSLIST = 566;
	const Sbecore::uint QRYWZNMPRSMNPROJECT = 567;
	const Sbecore::uint QRYWZNMPST1NQUERYMOD = 568;
	const Sbecore::uint QRYWZNMPSTLIST = 569;
	const Sbecore::uint QRYWZNMQCOLIST = 570;
	const Sbecore::uint QRYWZNMQCOREF1NCONTROL = 571;
	const Sbecore::uint QRYWZNMQMDLIST = 572;
	const Sbecore::uint QRYWZNMQRY1NQUERYMOD = 573;
	const Sbecore::uint QRYWZNMQRYACLAUSE = 574;
	const Sbecore::uint QRYWZNMQRYAORDER = 575;
	const Sbecore::uint QRYWZNMQRYLIST = 576;
	const Sbecore::uint QRYWZNMQRYMNDIALOG = 577;
	const Sbecore::uint QRYWZNMQRYMNPANEL = 578;
	const Sbecore::uint QRYWZNMQRYMNTABLE = 579;
	const Sbecore::uint QRYWZNMQRYQRY1NQUERYCOL = 580;
	const Sbecore::uint QRYWZNMQRYSUP1NQUERY = 581;
	const Sbecore::uint QRYWZNMREL1NTABLECOL = 582;
	const Sbecore::uint QRYWZNMRELATITLE = 583;
	const Sbecore::uint QRYWZNMRELLIST = 584;
	const Sbecore::uint QRYWZNMRELREF1NCONTROL = 585;
	const Sbecore::uint QRYWZNMRELREF1NDIALOG = 586;
	const Sbecore::uint QRYWZNMRELREF1NPANEL = 587;
	const Sbecore::uint QRYWZNMRELSUP1NRELATION = 588;
	const Sbecore::uint QRYWZNMRLSLIST = 589;
	const Sbecore::uint QRYWZNMRTJ1NRTBLOCK = 590;
	const Sbecore::uint QRYWZNMRTJ1NRTDPCH = 591;
	const Sbecore::uint QRYWZNMRTJLIST = 592;
	const Sbecore::uint QRYWZNMRTJSUP1NRTJOB = 593;
	const Sbecore::uint QRYWZNMSBS1NSTUB = 594;
	const Sbecore::uint QRYWZNMSBS1NTABLECOL = 595;
	const Sbecore::uint QRYWZNMSBSASBMNSUBSET = 596;
	const Sbecore::uint QRYWZNMSBSATITLE = 597;
	const Sbecore::uint QRYWZNMSBSBSBMNSUBSET = 598;
	const Sbecore::uint QRYWZNMSBSFRS1NRELATION = 599;
	const Sbecore::uint QRYWZNMSBSLIST = 600;
	const Sbecore::uint QRYWZNMSBSPST1NQUERYMOD = 601;
	const Sbecore::uint QRYWZNMSBSTOS1NRELATION = 602;
	const Sbecore::uint QRYWZNMSEQLIST = 603;
	const Sbecore::uint QRYWZNMSEQSEQ1NSTATE = 604;
	const Sbecore::uint QRYWZNMSGE1NSENSITIVITY = 605;
	const Sbecore::uint QRYWZNMSGELIST = 606;
	const Sbecore::uint QRYWZNMSGESQKMNSTUB = 607;
	const Sbecore::uint QRYWZNMSTBLIST = 608;
	const Sbecore::uint QRYWZNMSTBMNCALL = 609;
	const Sbecore::uint QRYWZNMSTBMNSQUAWK = 610;
	const Sbecore::uint QRYWZNMSTBSUBMNSTUB = 611;
	const Sbecore::uint QRYWZNMSTBSUPMNSTUB = 612;
	const Sbecore::uint QRYWZNMSTEASTEP = 613;
	const Sbecore::uint QRYWZNMSTELIST = 614;
	const Sbecore::uint QRYWZNMTAGLIST = 615;
	const Sbecore::uint QRYWZNMTBL1NCHECK = 616;
	const Sbecore::uint QRYWZNMTBL1NIMPEXP = 617;
	const Sbecore::uint QRYWZNMTBL1NSTUB = 618;
	const Sbecore::uint QRYWZNMTBL1NSUBSET = 619;
	const Sbecore::uint QRYWZNMTBLALOADFCT = 620;
	const Sbecore::uint QRYWZNMTBLATITLE = 621;
	const Sbecore::uint QRYWZNMTBLFCT1NTABLECOL = 622;
	const Sbecore::uint QRYWZNMTBLFR1NRELATION = 623;
	const Sbecore::uint QRYWZNMTBLHK1NVECTOR = 624;
	const Sbecore::uint QRYWZNMTBLLIST = 625;
	const Sbecore::uint QRYWZNMTBLMNQUERY = 626;
	const Sbecore::uint QRYWZNMTBLMNVECTOR = 627;
	const Sbecore::uint QRYWZNMTBLPST1NQUERYMOD = 628;
	const Sbecore::uint QRYWZNMTBLREF1NCALL = 629;
	const Sbecore::uint QRYWZNMTBLREF1NDIALOG = 630;
	const Sbecore::uint QRYWZNMTBLREF1NPANEL = 631;
	const Sbecore::uint QRYWZNMTBLREF1NQUERYMOD = 632;
	const Sbecore::uint QRYWZNMTBLREF1NRTBLOCK = 633;
	const Sbecore::uint QRYWZNMTBLSRC1NFEED = 634;
	const Sbecore::uint QRYWZNMTBLTBL1NTABLECOL = 635;
	const Sbecore::uint QRYWZNMTBLTO1NRELATION = 636;
	const Sbecore::uint QRYWZNMTCO1NCHECK = 637;
	const Sbecore::uint QRYWZNMTCO1NIMPEXPCOL = 638;
	const Sbecore::uint QRYWZNMTCO1NQUERYCOL = 639;
	const Sbecore::uint QRYWZNMTCOATITLE = 640;
	const Sbecore::uint QRYWZNMTCOLIST = 641;
	const Sbecore::uint QRYWZNMTCOREF1NCONTROL = 642;
	const Sbecore::uint QRYWZNMTCOREF1NQUERYMOD = 643;
	const Sbecore::uint QRYWZNMUSGAACCESS = 644;
	const Sbecore::uint QRYWZNMUSGLIST = 645;
	const Sbecore::uint QRYWZNMUSGMNUSER = 646;
	const Sbecore::uint QRYWZNMUSR1NSESSION = 647;
	const Sbecore::uint QRYWZNMUSRAACCESS = 648;
	const Sbecore::uint QRYWZNMUSRLIST = 649;
	const Sbecore::uint QRYWZNMUSRMNUSERGROUP = 650;
	const Sbecore::uint QRYWZNMVECATITLE = 651;
	const Sbecore::uint QRYWZNMVECFCT1NTABLECOL = 652;
	const Sbecore::uint QRYWZNMVECLIST = 653;
	const Sbecore::uint QRYWZNMVECMNTABLE = 654;
	const Sbecore::uint QRYWZNMVECPST1NQUERYMOD = 655;
	const Sbecore::uint QRYWZNMVECREF1NPANEL = 656;
	const Sbecore::uint QRYWZNMVECSRC1NFEED = 657;
	const Sbecore::uint QRYWZNMVECVEC1NVECTORITEM = 658;
	const Sbecore::uint QRYWZNMVER1NBLOCK = 659;
	const Sbecore::uint QRYWZNMVER1NCALL = 660;
	const Sbecore::uint QRYWZNMVER1NCAPABILITY = 661;
	const Sbecore::uint QRYWZNMVER1NCOMPONENT = 662;
	const Sbecore::uint QRYWZNMVER1NIMPEXPCPLX = 663;
	const Sbecore::uint QRYWZNMVER1NJOB = 664;
	const Sbecore::uint QRYWZNMVER1NOPPACK = 665;
	const Sbecore::uint QRYWZNMVER1NPRESET = 666;
	const Sbecore::uint QRYWZNMVER1NQUERY = 667;
	const Sbecore::uint QRYWZNMVER1NRELATION = 668;
	const Sbecore::uint QRYWZNMVER1NTABLE = 669;
	const Sbecore::uint QRYWZNMVER1NVECTOR = 670;
	const Sbecore::uint QRYWZNMVERBVR1NVERSION = 671;
	const Sbecore::uint QRYWZNMVERLIST = 672;
	const Sbecore::uint QRYWZNMVERMNLOCALE = 673;
	const Sbecore::uint QRYWZNMVERREF1NFILE = 674;
	const Sbecore::uint QRYWZNMVERVER1NAPP = 675;
	const Sbecore::uint QRYWZNMVERVER1NERROR = 676;
	const Sbecore::uint QRYWZNMVERVER1NMODULE = 677;
	const Sbecore::uint QRYWZNMVITLIST = 678;
	const Sbecore::uint ROOTWZNM = 679;
	const Sbecore::uint SESSWZNM = 680;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
