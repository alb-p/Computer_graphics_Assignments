CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXrandr -lXi
A06: A06.cpp
	g++ $(CFLAGS) -o A06 -I headers -I models -I shaders -I textures A06.cpp $(LDFLAGS)

.PHONY: test clean

test: A06
	./A06
clean:
	rm -f A06

