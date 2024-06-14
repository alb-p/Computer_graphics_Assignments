CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXrandr -lXi
A08: A08.cpp
	g++ $(CFLAGS) -o A08 -I headers -I models -I shaders -I textures A08.cpp $(LDFLAGS)

.PHONY: test clean

test: A08
	./A08
clean:
	rm -f A08

