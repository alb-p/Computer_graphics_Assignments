CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXrandr -lXi
A04: A04.cpp
	g++ $(CFLAGS) -o A04 -I headers -I models -I shaders -I textures A04.cpp $(LDFLAGS)

.PHONY: test clean

test: A04
	./A04
clean:
	rm -f A04

