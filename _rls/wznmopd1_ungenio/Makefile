# file Makefile
# make file for Wznm operation daemon, release wznmopd1_ungenio
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

LINK = g++
LINKFLAGS =

INCPATH = -I$(SRCROOT)/dbswznm -I$(SRCROOT)/wznmopd1/VecWznm -I$(SRCROOT)/wznmopd1/IexWznm -I$(SRCROOT)/wznmopd1
INCPATH += -I$(SRCROOT)/wznmopd1/WznmWrweb -I$(SRCROOT)/wznmopd1/WznmWrsrv -I$(SRCROOT)/wznmopd1/WznmWrjapi -I$(SRCROOT)/wznmopd1/WznmWrdbs -I$(SRCROOT)/wznmopd1/WznmWrapp -I$(SRCROOT)/wznmopd1/WznmWrapi -I$(SRCROOT)/wznmopd1/WznmPrctree -I$(SRCROOT)/wznmopd1/WznmPrcfile -I$(SRCROOT)/wznmopd1/WznmGen -I$(SRCROOT)/wznmopd1/WznmCompl
INCPATH += -I/Library/PostgreSQL/9.6/include -I/usr/local/include -I/usr/local/include/curl -I/usr/local/include/libxml2 -I/usr/local/mysql/include

PCHS = Wznmopd.h.gch

OBJS = Wznm.o WznmopdEngsrv.o WznmopdOpprc.o Wznmopd.o
OBJS += Wznmopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wznmopd1
LIBPATH += -L/Library/PostgreSQL/9.6/lib -L/usr/local/lib -L/usr/local/mysql/lib
LIBPATH += 

LIBS = -lwznmwrweb -lwznmwrsrv -lwznmwrjapi -lwznmwrdbs -lwznmwrapp -lwznmwrapi -lwznmprctree -lwznmprcfile -lwznmgen -lwznmcompl
LIBS += -liexwznm -lvecwznm -ldbswznm
LIBS += -lcurl -lmicrohttpd -lsbecore_my -lsbecore_pg
LIBS += -lmysqlclient -lpq -lsbecore_plus
LIBS += -lsbecore
LIBS += -lxml2
LIBS += -lz
LIBS += 

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

