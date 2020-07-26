# file Makefile
# make file for Wznm combined daemon, release wznmcmbd_genio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DWZNMCMBD

LINK = g++
LINKFLAGS =

INCPATH = -I$(SRCROOT)/dbswznm -I$(SRCROOT)/wznmcmbd/VecWznm -I$(SRCROOT)/wznmcmbd/IexWznm -I$(SRCROOT)/wznmcmbd
INCPATH += -I$(SRCROOT)/wznmcmbd/CrdWznmUsg -I$(SRCROOT)/wznmcmbd/CrdWznmUsr -I$(SRCROOT)/wznmcmbd/CrdWznmPrs -I$(SRCROOT)/wznmcmbd/CrdWznmFil -I$(SRCROOT)/wznmcmbd/CrdWznmNav -I$(SRCROOT)/wznmcmbd/CrdWznmLoc -I$(SRCROOT)/wznmcmbd/CrdWznmTag -I$(SRCROOT)/wznmcmbd/CrdWznmCtp -I$(SRCROOT)/wznmcmbd/CrdWznmMty -I$(SRCROOT)/wznmcmbd/CrdWznmMch -I$(SRCROOT)/wznmcmbd/CrdWznmLib -I$(SRCROOT)/wznmcmbd/CrdWznmPrj -I$(SRCROOT)/wznmcmbd/CrdWznmVer -I$(SRCROOT)/wznmcmbd/CrdWznmCap -I$(SRCROOT)/wznmcmbd/CrdWznmErr -I$(SRCROOT)/wznmcmbd/CrdWznmTbl -I$(SRCROOT)/wznmcmbd/CrdWznmTco -I$(SRCROOT)/wznmcmbd/CrdWznmSbs -I$(SRCROOT)/wznmcmbd/CrdWznmRel -I$(SRCROOT)/wznmcmbd/CrdWznmVec -I$(SRCROOT)/wznmcmbd/CrdWznmVit -I$(SRCROOT)/wznmcmbd/CrdWznmChk -I$(SRCROOT)/wznmcmbd/CrdWznmStb -I$(SRCROOT)/wznmcmbd/CrdWznmIex -I$(SRCROOT)/wznmcmbd/CrdWznmIme -I$(SRCROOT)/wznmcmbd/CrdWznmIel -I$(SRCROOT)/wznmcmbd/CrdWznmPst -I$(SRCROOT)/wznmcmbd/CrdWznmMdl -I$(SRCROOT)/wznmcmbd/CrdWznmCar -I$(SRCROOT)/wznmcmbd/CrdWznmDlg -I$(SRCROOT)/wznmcmbd/CrdWznmPnl -I$(SRCROOT)/wznmcmbd/CrdWznmQry -I$(SRCROOT)/wznmcmbd/CrdWznmQco -I$(SRCROOT)/wznmcmbd/CrdWznmQmd -I$(SRCROOT)/wznmcmbd/CrdWznmCon -I$(SRCROOT)/wznmcmbd/CrdWznmOpk -I$(SRCROOT)/wznmcmbd/CrdWznmOpx -I$(SRCROOT)/wznmcmbd/CrdWznmJob -I$(SRCROOT)/wznmcmbd/CrdWznmSge -I$(SRCROOT)/wznmcmbd/CrdWznmMtd -I$(SRCROOT)/wznmcmbd/CrdWznmBlk -I$(SRCROOT)/wznmcmbd/CrdWznmCal -I$(SRCROOT)/wznmcmbd/CrdWznmCmp -I$(SRCROOT)/wznmcmbd/CrdWznmRls -I$(SRCROOT)/wznmcmbd/CrdWznmApp -I$(SRCROOT)/wznmcmbd/CrdWznmRtj -I$(SRCROOT)/wznmcmbd/CrdWznmSeq -I$(SRCROOT)/wznmcmbd/CrdWznmSte -I$(SRCROOT)/wznmcmbd/CrdWznmUtl
INCPATH += -I$(SRCROOT)/wznmcmbd/WznmWrweb -I$(SRCROOT)/wznmcmbd/WznmWrjapi -I$(SRCROOT)/wznmcmbd/WznmWrsrv -I$(SRCROOT)/wznmcmbd/WznmWrdbs -I$(SRCROOT)/wznmcmbd/WznmWrapp -I$(SRCROOT)/wznmcmbd/WznmPrctree -I$(SRCROOT)/wznmcmbd/WznmWrapi -I$(SRCROOT)/wznmcmbd/WznmGen -I$(SRCROOT)/wznmcmbd/WznmPrcfile -I$(SRCROOT)/wznmcmbd/WznmCtpWrsrv -I$(SRCROOT)/wznmcmbd/WznmCtpWrweb -I$(SRCROOT)/wznmcmbd/WznmCtpWrstkit -I$(SRCROOT)/wznmcmbd/WznmCtpGenui -I$(SRCROOT)/wznmcmbd/WznmCompl -I$(SRCROOT)/wznmcmbd/WznmCtpGenjtr
INCPATH += -I/usr/include -I/usr/include/jsoncpp -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/include/postgresql -I/usr/local/include

PCHS = Wznmcmbd.h.gch

OBJS = Wznm.o WznmcmbdAppsrv.o WznmcmbdJobprc.o WznmcmbdOpprc.o Wznmcmbd.o
OBJS += RootWznm.o SessWznm.o JobWznmLicense.o
OBJS += Wznmcmbd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wznmcmbd
LIBPATH += -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lcrdwznmusg -lcrdwznmusr -lcrdwznmprs -lcrdwznmfil -lcrdwznmnav -lcrdwznmloc -lcrdwznmtag -lcrdwznmctp -lcrdwznmmty -lcrdwznmmch -lcrdwznmlib -lcrdwznmprj -lcrdwznmver -lcrdwznmcap -lcrdwznmerr -lcrdwznmtbl -lcrdwznmtco -lcrdwznmsbs -lcrdwznmrel -lcrdwznmvec -lcrdwznmvit -lcrdwznmchk -lcrdwznmstb -lcrdwznmiex -lcrdwznmime -lcrdwznmiel -lcrdwznmpst -lcrdwznmmdl -lcrdwznmcar -lcrdwznmdlg -lcrdwznmpnl -lcrdwznmqry -lcrdwznmqco -lcrdwznmqmd -lcrdwznmcon -lcrdwznmopk -lcrdwznmopx -lcrdwznmjob -lcrdwznmsge -lcrdwznmmtd -lcrdwznmblk -lcrdwznmcal -lcrdwznmcmp -lcrdwznmrls -lcrdwznmapp -lcrdwznmrtj -lcrdwznmseq -lcrdwznmste -lcrdwznmutl
LIBS += -lwznmwrweb -lwznmwrjapi -lwznmwrsrv -lwznmwrdbs -lwznmwrapp -lwznmprctree -lwznmwrapi -lwznmgen -lwznmprcfile -lwznmctpwrsrv -lwznmctpwrweb -lwznmctpwrstkit -lwznmctpgenui -lwznmcompl -lwznmctpgenjtr
LIBS += -liexwznm -lvecwznm -ldbswznm
LIBS += -lapiwzlm -lcurl -lgit2 -ljsoncpp -lmicrohttpd -lsbecore_mon -lsbecore_my -lsbecore_pg
LIBS += -lmysqlclient -lpq -lsbecore_plus -lssl
LIBS += -lcrypto -lsbecore
LIBS += -lxml2
LIBS += -lz
LIBS += -lpthread

EXE = Wznmcmbd

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
	mv $(EXE) $(BINROOT)/wznmcmbd/

clean:
	rm -f *.gch
	rm -f *.o

