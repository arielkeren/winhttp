CXX = g++
CXXFLAGS = -std=c++23 -Wall -Iinclude
LDFLAGS = -lws2_32

SOURCES = $(wildcard src/*.cpp src/**/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

winweb: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o winweb $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	if exist winweb.exe del winweb.exe
	if exist src\*.o del src\*.o

.PHONY: clean
