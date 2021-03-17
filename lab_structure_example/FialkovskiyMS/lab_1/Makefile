FLAGS = -std=c++17 -Wall -Wextra
BUILD = build
SOURCE = source
TEST = test

$(shell  mkdir -p $(BUILD))

app: $(BUILD)/main.o $(BUILD)/labyrinth.o
	g++ $(BUILD)/main.o $(BUILD)/labyrinth.o -o app $(FLAGS)

tests: $(BUILD)/tests-main.o $(BUILD)/labyrinth.o $(BUILD)/tests-labyrinth.o
	g++ $(BUILD)/tests-main.o $(BUILD)/labyrinth.o $(BUILD)/tests-labyrinth.o $(FLAGS) -o run_tests


$(BUILD)/main.o: $(SOURCE)/main.cpp
	g++ -c $(SOURCE)/main.cpp $(FLAGS) -o $(BUILD)/main.o

$(BUILD)/labyrinth.o: $(SOURCE)/labyrinth.cpp
	g++ -c $(SOURCE)/labyrinth.cpp $(FLAGS) -o $(BUILD)/labyrinth.o

$(BUILD)/tests-main.o: $(TEST)/tests-main.cpp
	g++ -c $(TEST)/tests-main.cpp $(FLAGS) -o $(BUILD)/tests-main.o

$(BUILD)/tests-labyrinth.o: $(TEST)/tests-labyrinth.cpp
	g++ -c $(TEST)/tests-labyrinth.cpp $(FLAGS) -o $(BUILD)/tests-labyrinth.o

clean:
	rm -rf BUILD/


