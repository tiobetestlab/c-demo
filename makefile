# Project: dRTE_Demo

include dRTE/module.mk
include Inc/module.mk

# Collection of project files
PROJECT_SRC = $(DRTE_SRC)
PROJECT_INC = .\ $(DRTE_INC) $(GEN_INC)

CC      = gcc
OBJECTS = $(foreach file,$(PROJECT_SRC),$(addsuffix .o,$(file)))
OBJECTSWIN = $(subst /,\,$(OBJECTS))

OBJ     = engine_drte.o os.o z_component.o test_component.o $(OBJECTS)
OBJWIN  = engine_drte.o os.o z_component.o test_component.o $(OBJECTSWIN)
INCS    =  -I"./dRTE" -I"./Inc"
BIN     = dRTE_Demo
BINWIN     = dRTE_Demo.exe
CFLAGS  = -c $(INCS)
LFLAGS  =
TFLAGS  = -Wall -fprofile-arcs -ftest-coverage
RM      = rm-f
RMWIN   = del


.PHONY: all all-before all-after clean clean-custom

all: all-before dRTE_Demo all-after

#clean: clean-custom
#	${RM} $(OBJ) $(BIN)

clean: clean-custom
	${RMWIN} $(OBJWIN) $(BINWIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o "dRTE_Demo"

z_component.o: z_component.c
	$(CC) $(CFLAGS) z_component.c -o z_component.o

drte.o: dRTE/drte.c
	$(CC) $(CFLAGS) dRTE/drte.c -o dRTE/drte.o

drte_runtime.o: dRTE/drte_runtime.c
	$(CC) $(CFLAGS) dRTE/drte_runtime.c -o dRTE/drte_runtime.o

drte_os.o: dRTE/drte_os.c
	$(CC) $(CFLAGS) dRTE/drte_os.c -o dRTE/drte_os.o

os.o: os.c
	$(CC) $(CFLAGS) os.c -o os.o

engine_drte.o: engine_drte.c
	$(CC) $(CFLAGS) engine_drte.c -o engine_drte.o

listincludes:
	echo $(PROJECT_INC)