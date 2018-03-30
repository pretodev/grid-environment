
CXX=mpicxx
CXXFLAGS=-std=c++11 -Wall

TARGET=grid_env

SOURCES=main.cc agent.cc environment.cc

OBJECTS=$(SOURCES:.cc=.o)

all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf *.o $(TARGET)
