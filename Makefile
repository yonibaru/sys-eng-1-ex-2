CC = gcc
CFLAGS = -Wall -g
all: my_graph my_Knapsack
# Creating Executables
my_graph: lib_my_mat.a my_graph.o
	$(CC) $(CFLAGS) -o my_graph my_graph.o lib_my_mat.a
my_Knapsack: my_Knapsack.o
	$(CC) $(CFLAGS) -o my_Knapsack my_Knapsack.o lib_my_mat.a
# Create our library
lib_my_mat.a: my_mat.o
	ar -rcs lib_my_mat.a my_mat.o
# Build object files
my_graph.o: my_graph.c
	$(CC) $(CFLAGS) -c my_graph.c
my_mat.o: my_mat.c
	$(CC) $(CFLAGS) -c my_mat.c
my_Knapsack.o: my_Knapsack.c
	$(CC) $(CFLAGS) -c my_Knapsack.c
# Clean build files
clean:
	rm -f *.o *.a my_graph my_Knapsack
