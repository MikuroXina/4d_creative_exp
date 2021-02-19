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
ifeq "$(wildcard nbproject/Makefile-local-device.mk)" "nbproject/Makefile-local-device.mk"
include nbproject/Makefile-local-device.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=device
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp-master.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp-master.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
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
SOURCEFILES_QUOTED_IF_SPACED=src/audio_output/wav_player.cpp src/lcd_renderer/lcd.cpp src/scene/scene.cpp src/scene/camera.cpp src/main.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/audio_output/wav_player.o ${OBJECTDIR}/src/lcd_renderer/lcd.o ${OBJECTDIR}/src/scene/scene.o ${OBJECTDIR}/src/scene/camera.o ${OBJECTDIR}/src/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/audio_output/wav_player.o.d ${OBJECTDIR}/src/lcd_renderer/lcd.o.d ${OBJECTDIR}/src/scene/scene.o.d ${OBJECTDIR}/src/scene/camera.o.d ${OBJECTDIR}/src/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/audio_output/wav_player.o ${OBJECTDIR}/src/lcd_renderer/lcd.o ${OBJECTDIR}/src/scene/scene.o ${OBJECTDIR}/src/scene/camera.o ${OBJECTDIR}/src/main.o

# Source Files
SOURCEFILES=src/audio_output/wav_player.cpp src/lcd_renderer/lcd.cpp src/scene/scene.cpp src/scene/camera.cpp src/main.cpp



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
	${MAKE}  -f nbproject/Makefile-device.mk dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp-master.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX170F256D
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/audio_output/wav_player.o: src/audio_output/wav_player.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/audio_output" 
	@${RM} ${OBJECTDIR}/src/audio_output/wav_player.o.d 
	@${RM} ${OBJECTDIR}/src/audio_output/wav_player.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MMD -MF "${OBJECTDIR}/src/audio_output/wav_player.o.d" -o ${OBJECTDIR}/src/audio_output/wav_player.o src/audio_output/wav_player.cpp   -DXPRJ_device=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/src/audio_output/wav_player.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/lcd_renderer/lcd.o: src/lcd_renderer/lcd.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/lcd_renderer" 
	@${RM} ${OBJECTDIR}/src/lcd_renderer/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/lcd_renderer/lcd.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MMD -MF "${OBJECTDIR}/src/lcd_renderer/lcd.o.d" -o ${OBJECTDIR}/src/lcd_renderer/lcd.o src/lcd_renderer/lcd.cpp   -DXPRJ_device=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/src/lcd_renderer/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/scene/scene.o: src/scene/scene.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/scene" 
	@${RM} ${OBJECTDIR}/src/scene/scene.o.d 
	@${RM} ${OBJECTDIR}/src/scene/scene.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MMD -MF "${OBJECTDIR}/src/scene/scene.o.d" -o ${OBJECTDIR}/src/scene/scene.o src/scene/scene.cpp   -DXPRJ_device=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/src/scene/scene.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/scene/camera.o: src/scene/camera.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/scene" 
	@${RM} ${OBJECTDIR}/src/scene/camera.o.d 
	@${RM} ${OBJECTDIR}/src/scene/camera.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MMD -MF "${OBJECTDIR}/src/scene/camera.o.d" -o ${OBJECTDIR}/src/scene/camera.o src/scene/camera.cpp   -DXPRJ_device=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/src/scene/camera.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/main.o: src/main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.cpp   -DXPRJ_device=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/src/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/src/audio_output/wav_player.o: src/audio_output/wav_player.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/audio_output" 
	@${RM} ${OBJECTDIR}/src/audio_output/wav_player.o.d 
	@${RM} ${OBJECTDIR}/src/audio_output/wav_player.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MMD -MF "${OBJECTDIR}/src/audio_output/wav_player.o.d" -o ${OBJECTDIR}/src/audio_output/wav_player.o src/audio_output/wav_player.cpp   -DXPRJ_device=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/src/audio_output/wav_player.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/lcd_renderer/lcd.o: src/lcd_renderer/lcd.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/lcd_renderer" 
	@${RM} ${OBJECTDIR}/src/lcd_renderer/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/lcd_renderer/lcd.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MMD -MF "${OBJECTDIR}/src/lcd_renderer/lcd.o.d" -o ${OBJECTDIR}/src/lcd_renderer/lcd.o src/lcd_renderer/lcd.cpp   -DXPRJ_device=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/src/lcd_renderer/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/scene/scene.o: src/scene/scene.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/scene" 
	@${RM} ${OBJECTDIR}/src/scene/scene.o.d 
	@${RM} ${OBJECTDIR}/src/scene/scene.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MMD -MF "${OBJECTDIR}/src/scene/scene.o.d" -o ${OBJECTDIR}/src/scene/scene.o src/scene/scene.cpp   -DXPRJ_device=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/src/scene/scene.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/scene/camera.o: src/scene/camera.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/scene" 
	@${RM} ${OBJECTDIR}/src/scene/camera.o.d 
	@${RM} ${OBJECTDIR}/src/scene/camera.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MMD -MF "${OBJECTDIR}/src/scene/camera.o.d" -o ${OBJECTDIR}/src/scene/camera.o src/scene/camera.cpp   -DXPRJ_device=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/src/scene/camera.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/main.o: src/main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.cpp   -DXPRJ_device=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/src/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp-master.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp-master.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_device=$(CND_CONF)  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=2048,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp-master.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp-master.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_device=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=2048,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp-master.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/device
	${RM} -r dist/device

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
