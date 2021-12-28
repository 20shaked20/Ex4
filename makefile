#VARIABLES:
CC=gcc
AR=ar
OBJECTS_graph = edges.o graph.o nodes.o
# OBJECTS_Main = main.o
FLAGS= -Wall -g

#Make commands as a bunch:
all: graph


graph: $(graph.o) lib_graph.a
	$(CC) $(FLAGS) -o graph $(graph.o) lib_graph.a 

#Make commands as singles:

lib_graph.a: $(OBJECTS_graph) #static library for rec and normal
	$(AR) -rcs lib_graph.a $(OBJECTS_graph)

graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c


edges.o: edges.c graph.h
	$(CC) $(FLAGS) -c edges.c 

nodes.o: nodes.c graph.h
	$(CC) $(FLAGS) -c nodes.c 

.PHONY: clean all

clean:
	rm -f *.o *.so graph lib_graph.a