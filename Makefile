
SOURCES=$(wildcard *.cpp *.c)
OBJECTS_CPP=$(SOURCES:%.cpp=%.o)
OBJECTS=$(OBJECTS_CPP:%.c=%.o)
TARGET=ejemplo-fu

CURL_CFLAGS=`curl-config --cflags`
CURL_LIBS=`curl-config --libs`

CPPFLAGS= -I. -Wall -Wextra $(CURL_CFLAGS)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK.cpp) $^ $(CURL_LIBS) -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS) *~
