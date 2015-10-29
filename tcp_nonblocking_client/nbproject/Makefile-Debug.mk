#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/tcp_nonblocking_client.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../../../../Netbeans/svn_vng/xallocatorlib/lib/libxallocator.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../bin/tcp_nonblocking_client

../bin/tcp_nonblocking_client: ../../../../Netbeans/svn_vng/xallocatorlib/lib/libxallocator.a

../bin/tcp_nonblocking_client: ${OBJECTFILES}
	${MKDIR} -p ../bin
	${LINK.cc} -o ../bin/tcp_nonblocking_client ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/tcp_nonblocking_client.o: src/tcp_nonblocking_client.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../Netbeans/svn_vng/xallocatorlib/inc -Iinc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tcp_nonblocking_client.o src/tcp_nonblocking_client.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ../bin/tcp_nonblocking_client

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
