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
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Aprovacao.o \
	${OBJECTDIR}/Cliente.o \
	${OBJECTDIR}/CodigoPostal.o \
	${OBJECTDIR}/Coordenadas.o \
	${OBJECTDIR}/Data.o \
	${OBJECTDIR}/Encomenda.o \
	${OBJECTDIR}/Funcionario.o \
	${OBJECTDIR}/FuncoesGerais.o \
	${OBJECTDIR}/InfoMorada.o \
	${OBJECTDIR}/LP_Leitura.o \
	${OBJECTDIR}/LP_Utils.o \
	${OBJECTDIR}/Menu_adicionar_admin.o \
	${OBJECTDIR}/Menu_admin.o \
	${OBJECTDIR}/Menu_alterar_admin.o \
	${OBJECTDIR}/Menu_cliente.o \
	${OBJECTDIR}/Menu_eliminar_admin.o \
	${OBJECTDIR}/Menu_funcionario_aprovar.o \
	${OBJECTDIR}/Menu_funcionario_entrega.o \
	${OBJECTDIR}/Menu_listar_admin.o \
	${OBJECTDIR}/Menu_login.o \
	${OBJECTDIR}/Pesquisa.o \
	${OBJECTDIR}/Produto.o \
	${OBJECTDIR}/Produto_Encomenda.o \
	${OBJECTDIR}/ficheiros.o \
	${OBJECTDIR}/login.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fontes_g16.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fontes_g16.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fontes_g16 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Aprovacao.o: Aprovacao.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Aprovacao.o Aprovacao.c

${OBJECTDIR}/Cliente.o: Cliente.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cliente.o Cliente.c

${OBJECTDIR}/CodigoPostal.o: CodigoPostal.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CodigoPostal.o CodigoPostal.c

${OBJECTDIR}/Coordenadas.o: Coordenadas.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Coordenadas.o Coordenadas.c

${OBJECTDIR}/Data.o: Data.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Data.o Data.c

${OBJECTDIR}/Encomenda.o: Encomenda.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Encomenda.o Encomenda.c

${OBJECTDIR}/Funcionario.o: Funcionario.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Funcionario.o Funcionario.c

${OBJECTDIR}/FuncoesGerais.o: FuncoesGerais.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FuncoesGerais.o FuncoesGerais.c

${OBJECTDIR}/InfoMorada.o: InfoMorada.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InfoMorada.o InfoMorada.c

${OBJECTDIR}/LP_Leitura.o: LP_Leitura.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LP_Leitura.o LP_Leitura.c

${OBJECTDIR}/LP_Utils.o: LP_Utils.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LP_Utils.o LP_Utils.c

${OBJECTDIR}/Menu_adicionar_admin.o: Menu_adicionar_admin.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu_adicionar_admin.o Menu_adicionar_admin.c

${OBJECTDIR}/Menu_admin.o: Menu_admin.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu_admin.o Menu_admin.c

${OBJECTDIR}/Menu_alterar_admin.o: Menu_alterar_admin.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu_alterar_admin.o Menu_alterar_admin.c

${OBJECTDIR}/Menu_cliente.o: Menu_cliente.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu_cliente.o Menu_cliente.c

${OBJECTDIR}/Menu_eliminar_admin.o: Menu_eliminar_admin.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu_eliminar_admin.o Menu_eliminar_admin.c

${OBJECTDIR}/Menu_funcionario_aprovar.o: Menu_funcionario_aprovar.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu_funcionario_aprovar.o Menu_funcionario_aprovar.c

${OBJECTDIR}/Menu_funcionario_entrega.o: Menu_funcionario_entrega.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu_funcionario_entrega.o Menu_funcionario_entrega.c

${OBJECTDIR}/Menu_listar_admin.o: Menu_listar_admin.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu_listar_admin.o Menu_listar_admin.c

${OBJECTDIR}/Menu_login.o: Menu_login.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu_login.o Menu_login.c

${OBJECTDIR}/Pesquisa.o: Pesquisa.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Pesquisa.o Pesquisa.c

${OBJECTDIR}/Produto.o: Produto.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Produto.o Produto.c

${OBJECTDIR}/Produto_Encomenda.o: Produto_Encomenda.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Produto_Encomenda.o Produto_Encomenda.c

${OBJECTDIR}/ficheiros.o: ficheiros.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ficheiros.o ficheiros.c

${OBJECTDIR}/login.o: login.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/login.o login.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fontes_g16.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
