CMP = g++
MAIN = driver
CLASS1 = board
CLASS2 = minesweeper
EXEC = Minesweeper
FLAGS = -std=c++11

$(EXEC): $(MAIN).o $(CLASS1).o $(CLASS2).o
	$(CMP) $(FLAGS) $(MAIN).o $(CLASS1).o $(CLASS2).o -o $(EXEC)

$(MAIN).o: $(MAIN).cpp
	$(CMP) -c $(FLAGS) $(MAIN).cpp -o $(MAIN).o

$(CLASS1).o: $(CLASS1).cpp $(CLASS1).h
	$(CMP) -c $(FLAGS) $(CLASS1).cpp -o $(CLASS1).o

$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h
	$(CMP) -c $(FLAGS) $(CLASS2).cpp -o $(CLASS2).o

clean:
	rm $(EXEC)
	rm $(CLASS1).o
	rm $(CLASS2).o
	rm $(MAIN).o
