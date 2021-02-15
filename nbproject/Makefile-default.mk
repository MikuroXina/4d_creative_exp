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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=src/main.cpp src/audio_output/wav_player.cpp src/lcd_renderer/lcd.cpp src/scene/scene.cpp src/scene/camera.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/audio_output/wav_player.o ${OBJECTDIR}/src/lcd_renderer/lcd.o ${OBJECTDIR}/src/scene/scene.o ${OBJECTDIR}/src/scene/camera.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/src/audio_output/wav_player.o.d ${OBJECTDIR}/src/lcd_renderer/lcd.o.d ${OBJECTDIR}/src/scene/scene.o.d ${OBJECTDIR}/src/scene/camera.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/audio_output/wav_player.o ${OBJECTDIR}/src/lcd_renderer/lcd.o ${OBJECTDIR}/src/scene/scene.o ${OBJECTDIR}/src/scene/camera.o

# Source Files
SOURCEFILES=src/main.cpp src/audio_output/wav_player.cpp src/lcd_renderer/lcd.cpp src/scene/scene.cpp src/scene/camera.cpp



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/src/main.o: src/main.cpp  .generated_files/eb798a7167fa1cc3f68c0c6f4fb55b7430e3958b.flag .generated_files/916d9e6eb100a173d7a86f8a4b24e1f52e53ec0a.flag
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MP -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/audio_output/wav_player.o: src/audio_output/wav_player.cpp  .generated_files/2dbae5bca79c8c5c1fd138660575274f35cacda0.flag .generated_files/916d9e6eb100a173d7a86f8a4b24e1f52e53ec0a.flag
	@${MKDIR} "${OBJECTDIR}/src/audio_output" 
	@${RM} ${OBJECTDIR}/src/audio_output/wav_player.o.d 
	@${RM} ${OBJECTDIR}/src/audio_output/wav_player.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MP -MMD -MF "${OBJECTDIR}/src/audio_output/wav_player.o.d" -o ${OBJECTDIR}/src/audio_output/wav_player.o src/audio_output/wav_player.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/lcd_renderer/lcd.o: src/lcd_renderer/lcd.cpp  .generated_files/5c01cb8e72cef7d53df28e770e70f4f11647d121.flag .generated_files/916d9e6eb100a173d7a86f8a4b24e1f52e53ec0a.flag
	@${MKDIR} "${OBJECTDIR}/src/lcd_renderer" 
	@${RM} ${OBJECTDIR}/src/lcd_renderer/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/lcd_renderer/lcd.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MP -MMD -MF "${OBJECTDIR}/src/lcd_renderer/lcd.o.d" -o ${OBJECTDIR}/src/lcd_renderer/lcd.o src/lcd_renderer/lcd.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/scene/scene.o: src/scene/scene.cpp  .generated_files/212efbca4737b988b1f0f32f01730d701ebb33ed.flag .generated_files/916d9e6eb100a173d7a86f8a4b24e1f52e53ec0a.flag
	@${MKDIR} "${OBJECTDIR}/src/scene" 
	@${RM} ${OBJECTDIR}/src/scene/scene.o.d 
	@${RM} ${OBJECTDIR}/src/scene/scene.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MP -MMD -MF "${OBJECTDIR}/src/scene/scene.o.d" -o ${OBJECTDIR}/src/scene/scene.o src/scene/scene.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/scene/camera.o: src/scene/camera.cpp  .generated_files/391215d83c5d369b5bdf7bf4563655e94b7cf7cb.flag .generated_files/916d9e6eb100a173d7a86f8a4b24e1f52e53ec0a.flag
	@${MKDIR} "${OBJECTDIR}/src/scene" 
	@${RM} ${OBJECTDIR}/src/scene/camera.o.d 
	@${RM} ${OBJECTDIR}/src/scene/camera.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MP -MMD -MF "${OBJECTDIR}/src/scene/camera.o.d" -o ${OBJECTDIR}/src/scene/camera.o src/scene/camera.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/src/main.o: src/main.cpp  .generated_files/9612a9994ac5dd2d8a6f8dcb63839350e9f4c1de.flag .generated_files/916d9e6eb100a173d7a86f8a4b24e1f52e53ec0a.flag
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MP -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/audio_output/wav_player.o: src/audio_output/wav_player.cpp  .generated_files/c2312137e7aabfa3bb3d679812c90598b6476213.flag .generated_files/916d9e6eb100a173d7a86f8a4b24e1f52e53ec0a.flag
	@${MKDIR} "${OBJECTDIR}/src/audio_output" 
	@${RM} ${OBJECTDIR}/src/audio_output/wav_player.o.d 
	@${RM} ${OBJECTDIR}/src/audio_output/wav_player.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MP -MMD -MF "${OBJECTDIR}/src/audio_output/wav_player.o.d" -o ${OBJECTDIR}/src/audio_output/wav_player.o src/audio_output/wav_player.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/lcd_renderer/lcd.o: src/lcd_renderer/lcd.cpp  .generated_files/7b1d4decdd87bfed003539a09218b05b648080d6.flag .generated_files/916d9e6eb100a173d7a86f8a4b24e1f52e53ec0a.flag
	@${MKDIR} "${OBJECTDIR}/src/lcd_renderer" 
	@${RM} ${OBJECTDIR}/src/lcd_renderer/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/lcd_renderer/lcd.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MP -MMD -MF "${OBJECTDIR}/src/lcd_renderer/lcd.o.d" -o ${OBJECTDIR}/src/lcd_renderer/lcd.o src/lcd_renderer/lcd.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/scene/scene.o: src/scene/scene.cpp  .generated_files/12703f5865e126400846adee4d8f13724aafe12.flag .generated_files/916d9e6eb100a173d7a86f8a4b24e1f52e53ec0a.flag
	@${MKDIR} "${OBJECTDIR}/src/scene" 
	@${RM} ${OBJECTDIR}/src/scene/scene.o.d 
	@${RM} ${OBJECTDIR}/src/scene/scene.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MP -MMD -MF "${OBJECTDIR}/src/scene/scene.o.d" -o ${OBJECTDIR}/src/scene/scene.o src/scene/scene.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/scene/camera.o: src/scene/camera.cpp  .generated_files/c154999e665b397aac1c595864650750ef88afcb.flag .generated_files/916d9e6eb100a173d7a86f8a4b24e1f52e53ec0a.flag
	@${MKDIR} "${OBJECTDIR}/src/scene" 
	@${RM} ${OBJECTDIR}/src/scene/camera.o.d 
	@${RM} ${OBJECTDIR}/src/scene/camera.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -MP -MMD -MF "${OBJECTDIR}/src/scene/camera.o.d" -o ${OBJECTDIR}/src/scene/camera.o src/scene/camera.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_SIMULATOR=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/4d_creative_exp.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
