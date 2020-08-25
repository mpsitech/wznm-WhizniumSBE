# file Makefile
# make file for Wznm daemon, release wznmd_ungenio
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DWZNMD

LINK = g++
LINKFLAGS =

INCPATH = -I$(SRCROOT)/dbswznm -I$(SRCROOT)/wznmd/VecWznm -I$(SRCROOT)/wznmd/IexWznm -I$(SRCROOT)/wznmd
INCPATH += -I$(SRCROOT)/wznmd/CrdWznmUsg -I$(SRCROOT)/wznmd/CrdWznmUsr -I$(SRCROOT)/wznmd/CrdWznmPrs -I$(SRCROOT)/wznmd/CrdWznmFil -I$(SRCROOT)/wznmd/CrdWznmNav -I$(SRCROOT)/wznmd/CrdWznmLoc -I$(SRCROOT)/wznmd/CrdWznmTag -I$(SRCROOT)/wznmd/CrdWznmCtp -I$(SRCROOT)/wznmd/CrdWznmMty -I$(SRCROOT)/wznmd/CrdWznmMch -I$(SRCROOT)/wznmd/CrdWznmLib -I$(SRCROOT)/wznmd/CrdWznmPrj -I$(SRCROOT)/wznmd/CrdWznmVer -I$(SRCROOT)/wznmd/CrdWznmCap -I$(SRCROOT)/wznmd/CrdWznmErr -I$(SRCROOT)/wznmd/CrdWznmTbl -I$(SRCROOT)/wznmd/CrdWznmTco -I$(SRCROOT)/wznmd/CrdWznmSbs -I$(SRCROOT)/wznmd/CrdWznmRel -I$(SRCROOT)/wznmd/CrdWznmVec -I$(SRCROOT)/wznmd/CrdWznmVit -I$(SRCROOT)/wznmd/CrdWznmChk -I$(SRCROOT)/wznmd/CrdWznmStb -I$(SRCROOT)/wznmd/CrdWznmIex -I$(SRCROOT)/wznmd/CrdWznmIme -I$(SRCROOT)/wznmd/CrdWznmIel -I$(SRCROOT)/wznmd/CrdWznmPst -I$(SRCROOT)/wznmd/CrdWznmMdl -I$(SRCROOT)/wznmd/CrdWznmCar -I$(SRCROOT)/wznmd/CrdWznmDlg -I$(SRCROOT)/wznmd/CrdWznmPnl -I$(SRCROOT)/wznmd/CrdWznmQry -I$(SRCROOT)/wznmd/CrdWznmQco -I$(SRCROOT)/wznmd/CrdWznmQmd -I$(SRCROOT)/wznmd/CrdWznmCon -I$(SRCROOT)/wznmd/CrdWznmOpk -I$(SRCROOT)/wznmd/CrdWznmOpx -I$(SRCROOT)/wznmd/CrdWznmJob -I$(SRCROOT)/wznmd/CrdWznmSge -I$(SRCROOT)/wznmd/CrdWznmMtd -I$(SRCROOT)/wznmd/CrdWznmBlk -I$(SRCROOT)/wznmd/CrdWznmCal -I$(SRCROOT)/wznmd/CrdWznmCmp -I$(SRCROOT)/wznmd/CrdWznmRls -I$(SRCROOT)/wznmd/CrdWznmApp -I$(SRCROOT)/wznmd/CrdWznmRtj -I$(SRCROOT)/wznmd/CrdWznmEvt -I$(SRCROOT)/wznmd/CrdWznmSeq -I$(SRCROOT)/wznmd/CrdWznmSte -I$(SRCROOT)/wznmd/CrdWznmUtl
INCPATH += -I/Library/PostgreSQL/9.6/include -I/usr/local/include -I/usr/local/include/curl -I/usr/local/include/libxml2 -I/usr/local/mysql/include

PCHS = Wznmd.h.gch

OBJS = Wznm.o WznmdAppsrv.o WznmdJobprc.o WznmdOpprc.o WznmdOpengcli.o WznmdOpengsrv.o Wznmd.o
OBJS += RootWznm.o SessWznm.o JobWznmLicense.o
OBJS += WznmWrsrv_blks.o SqkWznmWrsrv.o WznmWrweb_blks.o SqkWznmWrweb.o WznmWrjapi_blks.o SqkWznmWrjapi.o WznmWrdbs_blks.o SqkWznmWrdbs.o WznmPrctree_blks.o SqkWznmPrctree.o WznmWrapp_blks.o SqkWznmWrapp.o WznmWrapi_blks.o SqkWznmWrapi.o WznmPrcfile_blks.o SqkWznmPrcfile.o WznmGen_blks.o SqkWznmGen.o WznmCtpWrweb_blks.o SqkWznmCtpWrweb.o WznmCtpWrsrv_blks.o SqkWznmCtpWrsrv.o WznmCtpGenui_blks.o SqkWznmCtpGenui.o WznmCtpWrstkit_blks.o SqkWznmCtpWrstkit.o WznmCtpGenjtr_blks.o SqkWznmCtpGenjtr.o WznmCompl_blks.o SqkWznmCompl.o
OBJS += Wznmd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wznmd
LIBPATH += -L/Library/PostgreSQL/9.6/lib -L/usr/local/lib -L/usr/local/mysql/lib
LIBPATH += 

LIBS = -lcrdwznmusg -lcrdwznmusr -lcrdwznmprs -lcrdwznmfil -lcrdwznmnav -lcrdwznmloc -lcrdwznmtag -lcrdwznmctp -lcrdwznmmty -lcrdwznmmch -lcrdwznmlib -lcrdwznmprj -lcrdwznmver -lcrdwznmcap -lcrdwznmerr -lcrdwznmtbl -lcrdwznmtco -lcrdwznmsbs -lcrdwznmrel -lcrdwznmvec -lcrdwznmvit -lcrdwznmchk -lcrdwznmstb -lcrdwznmiex -lcrdwznmime -lcrdwznmiel -lcrdwznmpst -lcrdwznmmdl -lcrdwznmcar -lcrdwznmdlg -lcrdwznmpnl -lcrdwznmqry -lcrdwznmqco -lcrdwznmqmd -lcrdwznmcon -lcrdwznmopk -lcrdwznmopx -lcrdwznmjob -lcrdwznmsge -lcrdwznmmtd -lcrdwznmblk -lcrdwznmcal -lcrdwznmcmp -lcrdwznmrls -lcrdwznmapp -lcrdwznmrtj -lcrdwznmevt -lcrdwznmseq -lcrdwznmste -lcrdwznmutl
LIBS += -liexwznm -lvecwznm -ldbswznm
LIBS += -lapiwzlm -lcurl -lgit2 -ljsoncpp -lmicrohttpd -lsbecore_mon -lsbecore_my -lsbecore_pg
LIBS += -lmysqlclient -lpq -lsbecore_plus -lssl
LIBS += -lcrypto -lsbecore
LIBS += -lxml2
LIBS += -lz
LIBS += 

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

