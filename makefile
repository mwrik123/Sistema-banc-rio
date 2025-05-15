#makefile para sistema
#cirado por marina 14/05/2025

PROG = sistema
CPP = clang++
CPPFLAGS = -O0 -g -Wall -pedantic -I"C:\Users\marin\OneDrive\Documentos\projetos c++\sistema bancario"
OBJS = mainsistbanc.o sistemabanc.o

$(PROG) : $(OBJS)
	$(CPP) -o $(PROG) $(OBJS)

mainsistbanc.o :
	$(CPP) $(CPPFLAGS) -c mainsistbanc.cpp
sistemabanc.o : sistemabanc.hpp
	$(CPP) $(CPPFLAGS) -c sistemabanc.cpp
clean:
	rm -f core $(PROG) $(OBJS)