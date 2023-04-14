# g++ -c cafe.cpp -o bin/cafe.o
# g++ -c tostado.cpp -o bin/tostado.o
# g++ -c expreso.cpp -o bin/expreso.o
# g++ -c descafeinado.cpp -o bin/descafeinado.o
# g++ -c casero.cpp -o bin/casero.o
g++ -c main.cpp -o bin/main.o
# g++ -Lbin -o bin/main bin/cafe.o bin/tostado.o bin/expreso.o bin/descafeinado.o bin/casero.o bin/main.o
g++ -Lbin -o bin/main bin/main.o
bin/main