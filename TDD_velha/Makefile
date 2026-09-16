# Compatibilidade com o Catch antigo: evita o uso de SIGSTKSZ no Linux atual.
# A macro nao altera a logica dos testes nem do jogo da velha.
all: testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall -DCATCH_CONFIG_NO_POSIX_SIGNALS velha.o testa_velha.cpp -o testa_velha
	./testa_velha
	

compile: testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall -DCATCH_CONFIG_NO_POSIX_SIGNALS velha.o testa_velha.cpp -o testa_velha

velha.o : velha.cpp velha.hpp
	g++ -std=c++11 -Wall -c velha.cpp
	
testa_velha: 	testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall -DCATCH_CONFIG_NO_POSIX_SIGNALS velha.o testa_velha.cpp -o testa_velha
	
test: testa_velha	
	./testa_velha
	
cpplint: testa_velha.cpp   velha.cpp velha.hpp
	cpplint --exclude=catch.hpp --filter=-legal/copyright,-build/include_subdir *.cpp *.hpp
	
gcov: testa_velha.cpp   velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -c velha.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -DCATCH_CONFIG_NO_POSIX_SIGNALS velha.o testa_velha.cpp -o testa_velha
	./testa_velha
	gcov velha.cpp
	rm -f velha.o testa_velha
	 
debug: testa_velha.cpp   velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -g -c velha.cpp
	g++ -std=c++11 -Wall -g -DCATCH_CONFIG_NO_POSIX_SIGNALS velha.o testa_velha.cpp -o testa_velha
	gdb testa_velha
	
	
cppcheck: testa_velha.cpp   velha.cpp velha.hpp
	cppcheck --enable=warning --suppress='*:catch.hpp' .

valgrind: testa_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_velha


clean:
	rm -rf *.o *.exe *.gc* testa_velha 
	
	
