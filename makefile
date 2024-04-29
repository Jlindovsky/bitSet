CC = gcc
FLAGS = -Wall -Wextra -Werror -O2 -lm

INCLUDES = -I.

OBJP = error.o eratosthenes.o primes.o
OBJI = error-i.o eratosthenes-i.o primes-i.o
OBJS = error.o eratosthenes.o ppm.o steg-decode.o
Primes = primes
Primesi = primes-i
STEG = steg-decode

all: $(Primes) $(Primesi) $(STEG)

$(Primes): $(OBJP)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJP) -o $(Primes)
$(Primesi): $(OBJI)
	$(CC) $(FLAGS) -DUSE_INLINE $(INCLUDES) $(OBJI) -o $(Primesi)
$(STEG): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -o $(STEG)

%-i.o: %.c
	$(CC) $(FLAGS) -DUSE_INLINE $(INCLUDES) -c $< -o $@

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

run: $(Primes) $(Primesi)
	ulimit -s 3000; ./$(Primes)
	ulimit -s 3000; ./$(Primesi)
	
run_steg: $(STEG)
	./$(STEG) du1-obrazek.ppm
	
clean:
	rm -f $(OBJP) $(OBJI) $(OBJS) $(Primes) $(Primesi) $(STEG)


