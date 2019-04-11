# $Id: Makefile,v 1.5 2018-01-22 14:07:55-08 - - $

COMPILECPP  = g++ -std=gnu++17 -g -O0 -Wall -Wextra -Wold-style-cast
MAKEDEPCPP  = g++ -std=gnu++17 -MM

MKFILE   = Makefile
DEPFILE  = Makefile.dep
SOURCES  = string_set.cpp main.cpp auxlib.cpp
HEADERS  = string_set.h auxlib.h
OBJECTS  = ${SOURCES:.cpp=.o}
EXECBIN  = oc
SRCFILES = ${HEADERS} ${SOURCES} ${MKFILE}

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${COMPILECPP} ${OBJECTS} -o ${EXECBIN}

%.o : %.cpp
	${COMPILECPP} -c $<

ci :
	cid + ${SRCFILES}

clean :
	-rm ${OBJECTS} ${DEPFILE}

spotless : clean
	- rm ${EXECBIN} Listing.ps Listing.pdf test.out

${DEPFILE} :
	${MAKEDEPCPP} ${SOURCES} >${DEPFILE}

dep :
	- rm ${DEPFILE}
	${MAKE} --no-print-directory ${DEPFILE}

include ${DEPFILE}

test : ${EXECBIN}
	${EXECBIN} * * * >test.out 2>&1

lis : test
	mkpspdf Listing.ps ${SRCFILES} ${DEPFILE} test.out

again : ${SRCFILES}
	make --no-print-directory spotless dep ci test lis
