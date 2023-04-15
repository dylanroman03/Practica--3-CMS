# g++ -c cafe.cpp -o bin/cafe.o
# g++ -c tostado.cpp -o bin/tostado.o
g++ -w -c SitioWeb.cpp -o bin/SitioWeb.o
g++ -w -c Comercial.cpp -o bin/Comercial.o
g++ -w -c CMS.cpp -o bin/CMS.o
g++ -w -c main.cpp -o bin/main.o
# g++ -Lbin -o bin/main bin/cafe.o bin/tostado.o bin/expreso.o bin/descafeinado.o bin/casero.o bin/main.o
g++ -w -Lbin -o bin/main bin/SitioWeb.o bin/Comercial.o bin/CMS.o bin/main.o
bin/main