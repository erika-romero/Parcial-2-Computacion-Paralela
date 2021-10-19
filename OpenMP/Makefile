GCC = gcc
FLAGS = -ansi -pedantic -Wall -std=c99
C_FLAGS = -fopenmp
PROGRAMAS = matrizApp


matrizApp:
	$(GCC) $(FLAGS) funcionmatriz.c -c $(C_FLAGS)
	$(GCC) $(FLAGS) ctime.c -c $(C_FLAGS)
	$(GCC) $(FLAGS) $@.c -c $(C_FLAGS)
	$(GCC) $(FLAGS) -o $@ $@.o funcionmatriz.o ctime.o $(C_FLAGS)

clean:
	$(RM) $(PROGRAMAS) *.o
