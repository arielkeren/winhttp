CXX = g++
CXXFLAGS = -std=c++23 -Wall -Iinclude
LDFLAGS = -lws2_32

SOURCES = $(wildcard src/*.cpp src/**/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

winhttp: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o winhttp $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	if exist winhttp.exe del winhttp.exe
	if exist src\*.o del src\*.o

.PHONY: clean
