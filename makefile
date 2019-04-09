CPP  = g++
RES  =
OBJ  = card.o deck.o go_fish.o player.o $(RES)
LINKOBJ  = card.o deck.o go_fish.o player.o $(RES)
BIN  = gofish
CXXFLAGS = $(CXXINCS)
CFLAGS = $(INCS)
RM = rm -f


all: gofish

clean:
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o gofish $(LIBS)

card.o: Card.cpp
	$(CPP) -c Card.cpp -o Card.o $(CXXFLAGS)

deck.o: Deck.cpp
	$(CPP) -c Deck.cpp -o Deck.o $(CXXFLAGS)

go_fish.o: GoFish.cpp
	$(CPP) -c GoFish.cpp -o GoFish.o $(CXXFLAGS)

player.o: Player.cpp
	$(CPP) -c Player.cpp -o Player.o $(CXXFLAGS)