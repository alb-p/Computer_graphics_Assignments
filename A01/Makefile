CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXrandr -lXi
A01: A01.cpp
	g++ $(CFLAGS) -o A01 -I headers -I models -I shaders -I textures A01.cpp $(LDFLAGS)

.PHONY: test clean

test: A01
	./A01
clean:
	rm -f A01

