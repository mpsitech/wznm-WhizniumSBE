# file Makefile
# make file for Wznm operation daemon, release wznmopd2_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 13 Jan 2021
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbswznm -I$(BUILDROOT)/wznmopd2/VecWznm -I$(BUILDROOT)/wznmopd2/IexWznm -I$(BUILDROOT)/wznmopd2
INCPATH += -I$(BUILDROOT)/wznmopd2/WznmCtpGenjtr -I$(BUILDROOT)/wznmopd2/WznmCtpGenui -I$(BUILDROOT)/wznmopd2/WznmCtpWrstkit -I$(BUILDROOT)/wznmopd2/WznmCtpWrsrv -I$(BUILDROOT)/wznmopd2/WznmCtpWrweb
INCPATH += -I${WHIZSDKROOT}/build -I/usr/include -I/usr/include/libxml2 -I/usr/include/mariadb

PCHS = Wznmopd.h.gch

OBJS = Wznm.o WznmopdEngsrv.o WznmopdOpprc.o Wznmopd.o
OBJS += Wznmopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wznmopd2
LIBPATH += -L${WHIZSDKROOT}/lib -L/usr/lib/x86_64-linux-gnu
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lwznmctpgenjtr -lwznmctpgenui -lwznmctpwrstkit -lwznmctpwrsrv -lwznmctpwrweb
LIBS += -liexwznm -lvecwznm -ldbswznm
LIBS += -lcurl -lmicrohttpd -lsbecore_mar
LIBS += -lmariadbclient -lsbecore_plus
LIBS += -lsbecore
LIBS += -lxml2
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
