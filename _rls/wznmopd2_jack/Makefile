# file Makefile
# make file for Wznm operation daemon, release wznmopd2_jack
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

LINK = g++
LINKFLAGS =

INCPATH = -I$(SRCROOT)/dbswznm -I$(SRCROOT)/wznmopd2/VecWznm -I$(SRCROOT)/wznmopd2/IexWznm -I$(SRCROOT)/wznmopd2
INCPATH += -I$(SRCROOT)/wznmopd2/WznmCtpWrweb -I$(SRCROOT)/wznmopd2/WznmCtpWrsrv -I$(SRCROOT)/wznmopd2/WznmCtpWrstkit -I$(SRCROOT)/wznmopd2/WznmCtpGenui -I$(SRCROOT)/wznmopd2/WznmCtpGenjtr
INCPATH += -I/usr/include -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/include/postgresql -I/usr/local/include

PCHS = Wznmopd.h.gch

OBJS = Wznm.o WznmopdEngsrv.o WznmopdOpprc.o Wznmopd.o
OBJS += Wznmopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wznmopd2
LIBPATH += -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lwznmctpwrweb -lwznmctpwrsrv -lwznmctpwrstkit -lwznmctpgenui -lwznmctpgenjtr
LIBS += -liexwznm -lvecwznm -ldbswznm
LIBS += -lcurl -lmicrohttpd -lsbecore_my -lsbecore_pg
LIBS += -lmysqlclient -lpq -lsbecore_plus
LIBS += -lsbecore
LIBS += -lxml2
LIBS += -lz
LIBS += -lpthread

EXE = Wznmopd2

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
	mv $(EXE) $(BINROOT)/wznmopd2/

clean:
	rm -f *.gch
	rm -f *.o

