# file Makefile
# make file for Wznm combined daemon, release wznmcmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 5 Jan 2025
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DWZNMCMBD

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbswznm -I$(BUILDROOT)/wznmcmbd/VecWznm -I$(BUILDROOT)/wznmcmbd/IexWznm -I$(BUILDROOT)/wznmcmbd
INCPATH += -I$(BUILDROOT)/wznmcmbd/CrdWznmUsg -I$(BUILDROOT)/wznmcmbd/CrdWznmUsr -I$(BUILDROOT)/wznmcmbd/CrdWznmPrs -I$(BUILDROOT)/wznmcmbd/CrdWznmFil -I$(BUILDROOT)/wznmcmbd/CrdWznmNav -I$(BUILDROOT)/wznmcmbd/CrdWznmLoc -I$(BUILDROOT)/wznmcmbd/CrdWznmTag -I$(BUILDROOT)/wznmcmbd/CrdWznmCtp -I$(BUILDROOT)/wznmcmbd/CrdWznmMch -I$(BUILDROOT)/wznmcmbd/CrdWznmLib -I$(BUILDROOT)/wznmcmbd/CrdWznmPrj -I$(BUILDROOT)/wznmcmbd/CrdWznmVer -I$(BUILDROOT)/wznmcmbd/CrdWznmCap -I$(BUILDROOT)/wznmcmbd/CrdWznmErr -I$(BUILDROOT)/wznmcmbd/CrdWznmTbl -I$(BUILDROOT)/wznmcmbd/CrdWznmTco -I$(BUILDROOT)/wznmcmbd/CrdWznmSbs -I$(BUILDROOT)/wznmcmbd/CrdWznmRel -I$(BUILDROOT)/wznmcmbd/CrdWznmVec -I$(BUILDROOT)/wznmcmbd/CrdWznmVit -I$(BUILDROOT)/wznmcmbd/CrdWznmChk -I$(BUILDROOT)/wznmcmbd/CrdWznmStb -I$(BUILDROOT)/wznmcmbd/CrdWznmIex -I$(BUILDROOT)/wznmcmbd/CrdWznmIme -I$(BUILDROOT)/wznmcmbd/CrdWznmIel -I$(BUILDROOT)/wznmcmbd/CrdWznmPst -I$(BUILDROOT)/wznmcmbd/CrdWznmMdl -I$(BUILDROOT)/wznmcmbd/CrdWznmCar -I$(BUILDROOT)/wznmcmbd/CrdWznmDlg -I$(BUILDROOT)/wznmcmbd/CrdWznmPnl -I$(BUILDROOT)/wznmcmbd/CrdWznmQry -I$(BUILDROOT)/wznmcmbd/CrdWznmQco -I$(BUILDROOT)/wznmcmbd/CrdWznmQmd -I$(BUILDROOT)/wznmcmbd/CrdWznmCon -I$(BUILDROOT)/wznmcmbd/CrdWznmOpk -I$(BUILDROOT)/wznmcmbd/CrdWznmOpx -I$(BUILDROOT)/wznmcmbd/CrdWznmJob -I$(BUILDROOT)/wznmcmbd/CrdWznmSge -I$(BUILDROOT)/wznmcmbd/CrdWznmMtd -I$(BUILDROOT)/wznmcmbd/CrdWznmBlk -I$(BUILDROOT)/wznmcmbd/CrdWznmCal -I$(BUILDROOT)/wznmcmbd/CrdWznmCmp -I$(BUILDROOT)/wznmcmbd/CrdWznmRls -I$(BUILDROOT)/wznmcmbd/CrdWznmVis -I$(BUILDROOT)/wznmcmbd/CrdWznmSht -I$(BUILDROOT)/wznmcmbd/CrdWznmBox -I$(BUILDROOT)/wznmcmbd/CrdWznmApp -I$(BUILDROOT)/wznmcmbd/CrdWznmRtj -I$(BUILDROOT)/wznmcmbd/CrdWznmEvt -I$(BUILDROOT)/wznmcmbd/CrdWznmSeq -I$(BUILDROOT)/wznmcmbd/CrdWznmSte -I$(BUILDROOT)/wznmcmbd/CrdWznmUtl
INCPATH += -I$(BUILDROOT)/wznmcmbd/WznmWrswapi -I$(BUILDROOT)/wznmcmbd/WznmWrsrv -I$(BUILDROOT)/wznmcmbd/WznmWrvis -I$(BUILDROOT)/wznmcmbd/WznmWrvue -I$(BUILDROOT)/wznmcmbd/WznmWrweb -I$(BUILDROOT)/wznmcmbd/WznmWrcsapi -I$(BUILDROOT)/wznmcmbd/WznmWrdbs -I$(BUILDROOT)/wznmcmbd/WznmWrjapi -I$(BUILDROOT)/wznmcmbd/WznmWrpyapi -I$(BUILDROOT)/wznmcmbd/WznmWrapi -I$(BUILDROOT)/wznmcmbd/WznmWrapp -I$(BUILDROOT)/wznmcmbd/WznmCtpGenui -I$(BUILDROOT)/wznmcmbd/WznmCtpWrsrv -I$(BUILDROOT)/wznmcmbd/WznmCtpWrstkit -I$(BUILDROOT)/wznmcmbd/WznmPrctree -I$(BUILDROOT)/wznmcmbd/WznmPrcfile -I$(BUILDROOT)/wznmcmbd/WznmGen -I$(BUILDROOT)/wznmcmbd/WznmCtpWrweb -I$(BUILDROOT)/wznmcmbd/WznmCtpGenjtr -I$(BUILDROOT)/wznmcmbd/WznmComplvis -I$(BUILDROOT)/wznmcmbd/WznmCompl
INCPATH += -I${WHIZSDKROOT}/build -I${WHIZSDKROOT}/build/apiwzlm -I/usr/include -I/usr/include/jsoncpp -I/usr/include/libxml2 -I/usr/include/mariadb

PCHS = Wznmcmbd.h.gch

OBJS = Wznm.o WznmcmbdAppsrv.o WznmcmbdJobprc.o WznmcmbdOpprc.o Wznmcmbd.o
OBJS += RootWznm.o SessWznm.o JobWznmLicense.o
OBJS += Wznmcmbd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wznmcmbd
LIBPATH += -L${WHIZSDKROOT}/lib -L/usr/lib/x86_64-linux-gnu
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lcrdwznmusg -lcrdwznmusr -lcrdwznmprs -lcrdwznmfil -lcrdwznmnav -lcrdwznmloc -lcrdwznmtag -lcrdwznmctp -lcrdwznmmch -lcrdwznmlib -lcrdwznmprj -lcrdwznmver -lcrdwznmcap -lcrdwznmerr -lcrdwznmtbl -lcrdwznmtco -lcrdwznmsbs -lcrdwznmrel -lcrdwznmvec -lcrdwznmvit -lcrdwznmchk -lcrdwznmstb -lcrdwznmiex -lcrdwznmime -lcrdwznmiel -lcrdwznmpst -lcrdwznmmdl -lcrdwznmcar -lcrdwznmdlg -lcrdwznmpnl -lcrdwznmqry -lcrdwznmqco -lcrdwznmqmd -lcrdwznmcon -lcrdwznmopk -lcrdwznmopx -lcrdwznmjob -lcrdwznmsge -lcrdwznmmtd -lcrdwznmblk -lcrdwznmcal -lcrdwznmcmp -lcrdwznmrls -lcrdwznmvis -lcrdwznmsht -lcrdwznmbox -lcrdwznmapp -lcrdwznmrtj -lcrdwznmevt -lcrdwznmseq -lcrdwznmste -lcrdwznmutl
LIBS += -lwznmwrswapi -lwznmwrsrv -lwznmwrvis -lwznmwrvue -lwznmwrweb -lwznmwrcsapi -lwznmwrdbs -lwznmwrjapi -lwznmwrpyapi -lwznmwrapi -lwznmwrapp -lwznmctpgenui -lwznmctpwrsrv -lwznmctpwrstkit -lwznmprctree -lwznmprcfile -lwznmgen -lwznmctpwrweb -lwznmctpgenjtr -lwznmcomplvis -lwznmcompl
LIBS += -liexwznm -lvecwznm -ldbswznm
LIBS += -lapiwzlm -lcurl -lgit2 -lmicrohttpd -lsbecore_mar -lsbecore_mon
LIBS += -lmariadbclient -lsbecore_plus
LIBS += -lsbecore
LIBS += -ljsoncpp -lssl -lxml2
LIBS += -lcrypto
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

pch:	$(PCHS)

install:
	mv $(EXE) $(BINROOT)/wznmcmbd/

clean:
	rm -f *.gch
	rm -f *.o
