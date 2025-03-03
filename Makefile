# Variáveis
CC = gcc
CFLAGS = -Wall -I/usr/include/raylib -Iincludes
LDFLAGS = -L/usr/lib64
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Alvo principal
TARGET = main 

# Arquivos fonte
SRCS = $(wildcard src/*.c) 
OBJS = $(SRCS:.c=.o)

# Regra padrão
all: $(TARGET)

# Regra para compilar o alvo principal
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LIBS)

# Regra para compilar arquivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos compilados
clean:
	rm -f $(TARGET) $(OBJS)

# Limpar e compilar
compile:
	make clean
	make

# Limpar, compilar e abrir o arquivo
run:
	make clean
	make
	./main

