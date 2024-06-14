CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXrandr -lXi
A07: A07.cpp
	g++ $(CFLAGS) -o A07 -I headers -I models -I shaders -I textures A07.cpp $(LDFLAGS)

.PHONY: test clean

test: A07
	./A07
clean:
	rm -f A07

