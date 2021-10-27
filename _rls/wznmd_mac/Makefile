# file Makefile
# make file for Wznm daemon, release wznmd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 25 Oct 2021
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DWZNMD

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbswznm -I$(BUILDROOT)/wznmd/VecWznm -I$(BUILDROOT)/wznmd/IexWznm -I$(BUILDROOT)/wznmd
INCPATH += -I$(BUILDROOT)/wznmd/CrdWznmNav -I$(BUILDROOT)/wznmd/CrdWznmUsg -I$(BUILDROOT)/wznmd/CrdWznmUsr -I$(BUILDROOT)/wznmd/CrdWznmPrs -I$(BUILDROOT)/wznmd/CrdWznmFil -I$(BUILDROOT)/wznmd/CrdWznmLoc -I$(BUILDROOT)/wznmd/CrdWznmTag -I$(BUILDROOT)/wznmd/CrdWznmCtp -I$(BUILDROOT)/wznmd/CrdWznmMch -I$(BUILDROOT)/wznmd/CrdWznmLib -I$(BUILDROOT)/wznmd/CrdWznmPrj -I$(BUILDROOT)/wznmd/CrdWznmVer -I$(BUILDROOT)/wznmd/CrdWznmCap -I$(BUILDROOT)/wznmd/CrdWznmErr -I$(BUILDROOT)/wznmd/CrdWznmTbl -I$(BUILDROOT)/wznmd/CrdWznmTco -I$(BUILDROOT)/wznmd/CrdWznmSbs -I$(BUILDROOT)/wznmd/CrdWznmRel -I$(BUILDROOT)/wznmd/CrdWznmVec -I$(BUILDROOT)/wznmd/CrdWznmVit -I$(BUILDROOT)/wznmd/CrdWznmChk -I$(BUILDROOT)/wznmd/CrdWznmStb -I$(BUILDROOT)/wznmd/CrdWznmIex -I$(BUILDROOT)/wznmd/CrdWznmIme -I$(BUILDROOT)/wznmd/CrdWznmIel -I$(BUILDROOT)/wznmd/CrdWznmPst -I$(BUILDROOT)/wznmd/CrdWznmMdl -I$(BUILDROOT)/wznmd/CrdWznmCar -I$(BUILDROOT)/wznmd/CrdWznmDlg -I$(BUILDROOT)/wznmd/CrdWznmPnl -I$(BUILDROOT)/wznmd/CrdWznmQry -I$(BUILDROOT)/wznmd/CrdWznmQco -I$(BUILDROOT)/wznmd/CrdWznmQmd -I$(BUILDROOT)/wznmd/CrdWznmCon -I$(BUILDROOT)/wznmd/CrdWznmOpk -I$(BUILDROOT)/wznmd/CrdWznmOpx -I$(BUILDROOT)/wznmd/CrdWznmJob -I$(BUILDROOT)/wznmd/CrdWznmSge -I$(BUILDROOT)/wznmd/CrdWznmMtd -I$(BUILDROOT)/wznmd/CrdWznmBlk -I$(BUILDROOT)/wznmd/CrdWznmCal -I$(BUILDROOT)/wznmd/CrdWznmCmp -I$(BUILDROOT)/wznmd/CrdWznmRls -I$(BUILDROOT)/wznmd/CrdWznmApp -I$(BUILDROOT)/wznmd/CrdWznmRtj -I$(BUILDROOT)/wznmd/CrdWznmEvt -I$(BUILDROOT)/wznmd/CrdWznmSeq -I$(BUILDROOT)/wznmd/CrdWznmSte -I$(BUILDROOT)/wznmd/CrdWznmUtl
INCPATH += -I${WHIZSDKROOT}/build -I${WHIZSDKROOT}/build/apiwzlm -I/usr/local/include -I/usr/local/include/curl -I/usr/local/include/libxml2 -I/usr/local/mysql/include

PCHS = Wznmd.h.gch

OBJS = Wznm.o WznmdAppsrv.o WznmdJobprc.o WznmdOpprc.o WznmdOpengcli.o WznmdOpengsrv.o Wznmd.o
OBJS += RootWznm.o SessWznm.o JobWznmLicense.o
OBJS += WznmWrweb_blks.o SqkWznmWrweb.o WznmWrjapi_blks.o SqkWznmWrjapi.o WznmWrsrv_blks.o SqkWznmWrsrv.o WznmWrdbs_blks.o SqkWznmWrdbs.o WznmWrapi_blks.o SqkWznmWrapi.o WznmWrapp_blks.o SqkWznmWrapp.o WznmPrctree_blks.o SqkWznmPrctree.o WznmGen_blks.o SqkWznmGen.o WznmPrcfile_blks.o SqkWznmPrcfile.o WznmCtpWrweb_blks.o SqkWznmCtpWrweb.o WznmCtpWrstkit_blks.o SqkWznmCtpWrstkit.o WznmCtpWrsrv_blks.o SqkWznmCtpWrsrv.o WznmCtpGenui_blks.o SqkWznmCtpGenui.o WznmCompl_blks.o SqkWznmCompl.o WznmCtpGenjtr_blks.o SqkWznmCtpGenjtr.o
OBJS += Wznmd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wznmd
LIBPATH += -L${WHIZSDKROOT}/lib -L/usr/local/lib -L/usr/local/mysql/lib

LIBS = -lcrdwznmnav -lcrdwznmusg -lcrdwznmusr -lcrdwznmprs -lcrdwznmfil -lcrdwznmloc -lcrdwznmtag -lcrdwznmctp -lcrdwznmmch -lcrdwznmlib -lcrdwznmprj -lcrdwznmver -lcrdwznmcap -lcrdwznmerr -lcrdwznmtbl -lcrdwznmtco -lcrdwznmsbs -lcrdwznmrel -lcrdwznmvec -lcrdwznmvit -lcrdwznmchk -lcrdwznmstb -lcrdwznmiex -lcrdwznmime -lcrdwznmiel -lcrdwznmpst -lcrdwznmmdl -lcrdwznmcar -lcrdwznmdlg -lcrdwznmpnl -lcrdwznmqry -lcrdwznmqco -lcrdwznmqmd -lcrdwznmcon -lcrdwznmopk -lcrdwznmopx -lcrdwznmjob -lcrdwznmsge -lcrdwznmmtd -lcrdwznmblk -lcrdwznmcal -lcrdwznmcmp -lcrdwznmrls -lcrdwznmapp -lcrdwznmrtj -lcrdwznmevt -lcrdwznmseq -lcrdwznmste -lcrdwznmutl
LIBS += -liexwznm -lvecwznm -ldbswznm
LIBS += -lapiwzlm -lcurl -lgit2 -lmicrohttpd -lsbecore_mon -lsbecore_my
LIBS += -lmysqlclient -lsbecore_plus
LIBS += -lsbecore
LIBS += -ljsoncpp -lssl -lxml2
LIBS += -lcrypto

EXE = Wznmd

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(PCHS) $(EXE)

$(EXE):	$(OBJS)
	$(LINK) $(LINKFLAGS) $(OBJS) $(LIBPATH) $(LIBS) -o $(EXE)
	rm -f *.o

pch:	$(PCHS)

install:
	mv $(EXE) $(BINROOT)/wznmd/

clean:
	rm -f *.gch
	rm -f *.o
