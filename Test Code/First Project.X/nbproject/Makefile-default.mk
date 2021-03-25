#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=hex
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/First_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=hex
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/First_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED="First code.asm" newAsmTemplate.asm

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED="${OBJECTDIR}/First code.o" ${OBJECTDIR}/newAsmTemplate.o
POSSIBLE_DEPFILES="${OBJECTDIR}/First code.o.d" ${OBJECTDIR}/newAsmTemplate.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/First\ code.o ${OBJECTDIR}/newAsmTemplate.o

# Source Files
SOURCEFILES=First code.asm newAsmTemplate.asm


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/First_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=EEPROM8
MP_LINKER_DEBUG_OPTION= 
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/First\ code.o: First\ code.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} "${OBJECTDIR}/First code.o".d 
	@${RM} "${OBJECTDIR}/First code.o" 
	@${FIXDEPS} dummy.d -e "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/First code.ERR" $(SILENT) -rsi ${MP_AS_DIR} -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG  -q -p$(MP_PROCESSOR_OPTION)  $(ASM_OPTIONS)    \"C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/First code.asm\" 
	@${MV}  "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/First code".O "${OBJECTDIR}/First code.o"
	@${MV}  "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/First code".ERR "${OBJECTDIR}/First code.o".err
	@${MV}  "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/First code".LST "${OBJECTDIR}/First code.o".lst
	@${DEP_GEN} -d "${OBJECTDIR}/First code.o"
	@${FIXDEPS} "${OBJECTDIR}/First code.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/newAsmTemplate.o: newAsmTemplate.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newAsmTemplate.o.d 
	@${RM} ${OBJECTDIR}/newAsmTemplate.o 
	@${FIXDEPS} dummy.d -e "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/newAsmTemplate.ERR" $(SILENT) -rsi ${MP_AS_DIR} -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG  -q -p$(MP_PROCESSOR_OPTION)  $(ASM_OPTIONS)    \"C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/newAsmTemplate.asm\" 
	@${MV}  "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/newAsmTemplate".O ${OBJECTDIR}/newAsmTemplate.o
	@${MV}  "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/newAsmTemplate".ERR ${OBJECTDIR}/newAsmTemplate.o.err
	@${MV}  "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/newAsmTemplate".LST ${OBJECTDIR}/newAsmTemplate.o.lst
	@${DEP_GEN} -d "${OBJECTDIR}/newAsmTemplate.o"
	@${FIXDEPS} "${OBJECTDIR}/newAsmTemplate.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
else
${OBJECTDIR}/First\ code.o: First\ code.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} "${OBJECTDIR}/First code.o".d 
	@${RM} "${OBJECTDIR}/First code.o" 
	@${FIXDEPS} dummy.d -e "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/First code.ERR" $(SILENT) -rsi ${MP_AS_DIR} -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION)  $(ASM_OPTIONS)    \"C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/First code.asm\" 
	@${MV}  "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/First code".O "${OBJECTDIR}/First code.o"
	@${MV}  "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/First code".ERR "${OBJECTDIR}/First code.o".err
	@${MV}  "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/First code".LST "${OBJECTDIR}/First code.o".lst
	@${DEP_GEN} -d "${OBJECTDIR}/First code.o"
	@${FIXDEPS} "${OBJECTDIR}/First code.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/newAsmTemplate.o: newAsmTemplate.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newAsmTemplate.o.d 
	@${RM} ${OBJECTDIR}/newAsmTemplate.o 
	@${FIXDEPS} dummy.d -e "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/newAsmTemplate.ERR" $(SILENT) -rsi ${MP_AS_DIR} -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION)  $(ASM_OPTIONS)    \"C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/newAsmTemplate.asm\" 
	@${MV}  "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/newAsmTemplate".O ${OBJECTDIR}/newAsmTemplate.o
	@${MV}  "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/newAsmTemplate".ERR ${OBJECTDIR}/newAsmTemplate.o.err
	@${MV}  "C:/Users/Onayo Moro/Documents/PIC assembly/First Project.X/newAsmTemplate".LST ${OBJECTDIR}/newAsmTemplate.o.lst
	@${DEP_GEN} -d "${OBJECTDIR}/newAsmTemplate.o"
	@${FIXDEPS} "${OBJECTDIR}/newAsmTemplate.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/First_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	@${MV}  "First code.HEX" dist/${CND_CONF}/${IMAGE_TYPE}/First_Project.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/First_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	@${MV}  "First code.HEX" dist/${CND_CONF}/${IMAGE_TYPE}/First_Project.X.${IMAGE_TYPE}.hex 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
