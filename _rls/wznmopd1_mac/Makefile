# file Makefile
# make file for Wznm operation daemon, release wznmopd1_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Emily Johnson (auto-generation)
# date created: 28 Mar 2022
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbswznm -I$(BUILDROOT)/wznmopd1/VecWznm -I$(BUILDROOT)/wznmopd1/IexWznm -I$(BUILDROOT)/wznmopd1
INCPATH += -I$(BUILDROOT)/wznmopd1/WznmWrweb -I$(BUILDROOT)/wznmopd1/WznmWrvue -I$(BUILDROOT)/wznmopd1/WznmWrsrv -I$(BUILDROOT)/wznmopd1/WznmWrsapi -I$(BUILDROOT)/wznmopd1/WznmWrjapi -I$(BUILDROOT)/wznmopd1/WznmWrdbs -I$(BUILDROOT)/wznmopd1/WznmWrapp -I$(BUILDROOT)/wznmopd1/WznmWrapi -I$(BUILDROOT)/wznmopd1/WznmPrctree -I$(BUILDROOT)/wznmopd1/WznmPrcfile -I$(BUILDROOT)/wznmopd1/WznmGen -I$(BUILDROOT)/wznmopd1/WznmCompl
INCPATH += -I${WHIZSDKROOT}/build -I/opt/homebrew/include -I/opt/homebrew/opt/curl/include -I/opt/homebrew/opt/libmicrohttpd/include -I/opt/homebrew/opt/libxml2/include -I/usr/local/mysql/include

PCHS = Wznmopd.h.gch

OBJS = Wznm.o WznmopdEngsrv.o WznmopdOpprc.o Wznmopd.o
OBJS += Wznmopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wznmopd1
LIBPATH += -L${WHIZSDKROOT}/lib -L/opt/homebrew/lib -L/opt/homebrew/opt/curl/lib -L/opt/homebrew/opt/libmicrohttpd/lib -L/opt/homebrew/opt/libxml2/include -L/usr/local/mysql/lib

LIBS = -lwznmwrweb -lwznmwrvue -lwznmwrsrv -lwznmwrsapi -lwznmwrjapi -lwznmwrdbs -lwznmwrapp -lwznmwrapi -lwznmprctree -lwznmprcfile -lwznmgen -lwznmcompl
LIBS += -liexwznm -lvecwznm -ldbswznm
LIBS += -lcurl -lmicrohttpd -lsbecore_my
LIBS += -lmysqlclient -lsbecore_plus
LIBS += -lsbecore
LIBS += -ljsoncpp -lxml2

EXE = Wznmopd1

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
	mv $(EXE) $(BINROOT)/wznmopd1/

clean:
	rm -f *.gch
	rm -f *.o
