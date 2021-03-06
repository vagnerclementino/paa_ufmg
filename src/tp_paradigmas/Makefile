CC=g++
CFLAGS= -g -c -Wall -D__USE_FIXED_PROTOTYPES__ -lm
#
# Compiler flags:
# -c -- Compile or assemble the source files, but do not link.
# -g -- Enable debugging
# -Wall -- Turn on all warnings 
# -D__USE_FIXED_PROTOTYPES__ -- Force the compiler to use the correct headers
# -ansi -- Don't use GNU extensions. Stick to ANSI C.
PROGRAM_NAME=tp_paradigmas
CRIADOR=Vagner Clementino
PAA_LIB_PATH=../lib
SRC_FOLDER=./src
BIN_DIR=./bin
IN_DIR=./inputs
OUT_DIR=./outputs
OBJS=$(SRC_FOLDER)/main.o \
	$(SRC_FOLDER)/Brain.o \
	$(SRC_FOLDER)/TPInstance.o \
	$(SRC_FOLDER)/TPParadigmas.o \
	$(PAA_LIB_PATH)/FileManager.o \
	$(PAA_LIB_PATH)/PAAException.o \
	$(PAA_LIB_PATH)/TrabalhoPratico.o \

#INPUTFILE= $(pwd)entradas/input.txt
INPUTFILE=$(IN_DIR)/input.txt
OUTPUTFILE=$(OUT_DIR)/output.txt 

all: app_structure msg_user linking $(BIN_DIR)/$(PROGRAM_NAME)
	@echo "Executando o programa..."
	@rm -f $(OBJS) *.gch
	@./$(BIN_DIR)/$(PROGRAM_NAME)

app_structure:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(IN_DIR)
	@mkdir -p $(OUT_DIR)
	
msg_user:
	@echo "Executando o makefile do programa " \
	 	  "$(PROGRAM_NAME) criado por $(CRIADOR)."
	
linking: $(OBJS)
	@$(CC) -o $(BIN_DIR)/$(PROGRAM_NAME) $(OBJS)
	@echo "Linking executado com sucesso."

main.o: $(SRC_FOLDER)/main.cpp
	@$(CC) $(CFLAGS) main.cpp

FileManager.o: $(PAA_LIB_PATH)/FileManager.h $(PAA_LIB_PATH)/FileManager.cpp
	@$(CC) $(CFLAGS) $(PAA_LIB_PATH)/FileManager.cpp

PAAException.o: $(PAA_LIB_PATH)/PAAException.h $(PAA_LIB_PATH)/PAAException.cpp
	@$(CC) $(CFLAGS) $(PAA_LIB_PATH)/PAAException.cpp

TrabalhoPratico.o: TrabalhoPratico.h TrabalhoPratico.cpp
	@$(CC) $(CFLAGS) $(PAA_LIB_PATH)/TrabalhoPratico.cpp

#Instance.o: Instance.h
#	@$(CC) $(CFLAGS) $(PAA_LIB_PATH)/Instance.h

#Solution.o: Solution.h
#	@$(CC) $(CFLAGS) $(PAA_LIB_PATH)/Solution.cpp

Brain.o: Brain.h Brain.cpp
	@$(CC) $(CFLAGS) $(PAA_LIB_PATH)/Brain.cpp

TPInstance.o: TPInstance.h TPInstance.cpp
	@$(CC) $(CFLAGS) $(PAA_LIB_PATH)/TPInstance.cpp

TPParadigmas.o: TPParadigmas.h TPParadigmas.cpp
	@$(CC) $(CFLAGS) $(PAA_LIB_PATH)/TPParadigmas.cpp				
clean:
	@echo "Removendo arquivos temporários e o executável..."
	@rm -f $(OBJS) *.gch $(PROGRAM_NAME)
	@echo "Arquivos removidos com sucesso."