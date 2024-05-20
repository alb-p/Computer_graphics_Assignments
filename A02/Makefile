CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXrandr -lXi
A02: A02.cpp
	g++ $(CFLAGS) -o A02 -I headers -I models -I shaders -I textures A02.cpp $(LDFLAGS)

.PHONY: test clean

test: A02
	./A02
clean:
	rm -f A02

