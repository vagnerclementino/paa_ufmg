CC=g++
CFLAGS= -g -c -Wall -D__USE_FIXED_PROTOTYPES__ -lm
#
# Compiler flags:
# -c -- Compile or assemble the source files, but do not link.
# -g -- Enable debugging
# -Wall -- Turn on all warnings 
# -D__USE_FIXED_PROTOTYPES__ -- Force the compiler to use the correct headers
# -ansi -- Don't use GNU extensions. Stick to ANSI C.
PROGRAM_NAME=tp0
CRIADOR=Vagner Clementino
PAA_LIB_PATH=../lib
OBJS=main.o \
	TP0.o \
	$(PAA_LIB_PATH)/FileManager.o \
	$(PAA_LIB_PATH)/PAAException.o \
	$(PAA_LIB_PATH)/TrabalhoPratico.o 

#INPUTFILE= $(pwd)entradas/input.txt
INPUTFILE=input.txt
OUTPUTFILE=output.txt

 

all: msg_user linking
	@echo "Executando o programa..."
	@rm -f $(OBJS) *.gch
	@./$(PROGRAM_NAME)
	
msg_user:
	@echo "Executando o makefile do programa" \
	       "$(PROGRAM_NAME) criado por $(CRIADOR)."
	
linking: $(OBJS)
	@$(CC) -o $(PROGRAM_NAME) $(OBJS)
	@echo "Linking executado com sucesso."

main.o: main.cpp
	@$(CC) $(CFLAGS) main.cpp

TP0.o: TP0.h TP0.cpp
	@$(CC) $(CFLAGS) TP0.cpp

FileManager.o: $(PAA_LIB_PATH)/FileManager.h $(PAA_LIB_PATH)/FileManager.cpp
	@$(CC) $(CFLAGS) $(PAA_LIB_PATH)/FileManager.cpp

PAAException.o: $(PAA_LIB_PATH)/PAAException.h $(PAA_LIB_PATH)/PAAException.cpp
	@$(CC) $(CFLAGS) $(PAA_LIB_PATH)/PAAException.cpp

TrabalhoPratico.o: TrabalhoPratico.h TrabalhoPratico.cpp
	@$(CC) $(CFLAGS) $(PAA_LIB_PATH)/TrabalhoPratico.cpp
clean:
	@echo "Removendo arquivos temporários e o executável..."
	@rm -f $(OBJS) *.gch $(PROGRAM_NAME)
	@echo "Arquivos removidos com sucesso."
