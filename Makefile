
SOURCES=$(wildcard *.cpp *.c)
OBJECTS_CPP=$(SOURCES:%.cpp=%.o)
OBJECTS=$(OBJECTS_CPP:%.c=%.o)
TARGET=ejemplo-fu

CURL_CFLAGS=$(curl-config --cflags)
CURL_LIBS=$(curl-config --libs)

CPPFLAGS= -I. -Wall -Wextra $(CURL_FLAGS)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK.cpp) $^ $(GLFW3_FLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

%.o: %.c
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS) *~
