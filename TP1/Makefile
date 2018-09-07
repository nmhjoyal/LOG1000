EXEC = site/pari

all: $(EXEC)

$(EXEC): build/main.o build/hashMap.o build/SomeKeyHash.o
	g++ -o $(EXEC) build/main.o build/hashMap.o build/SomeKeyHash.o
	@echo "making pari"

build/main.o: src/main.cpp src/hashMap.h
	g++ -o build/main.o -c src/main.cpp
	@echo "making main.o"

build/hashMap.o: src/hashMap.cpp src/hashMap.h
	g++ -o build/hashMap.o -c src/hashMap.cpp
	@echo "making hashMap.o"


build/SomeKeyHash.o: src/SomeKeyHash.cpp src/SomeKeyHash.h
	g++ -o build/SomeKeyHash.o -c src/SomeKeyHash.cpp
	@echo "making SomeKeyHash.o"

clean:
	rm -rf build/*.o build/*.out
	@echo "clearing .o & .out"
      #enlevez les fichiers générés

mrproper: clean
	rm -rf $(EXEC)
	@echo "clearing EXEC"
      #enlevez les dossiers générés
