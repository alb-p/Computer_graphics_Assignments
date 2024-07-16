CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXrandr -lXi
A09: A09.cpp
	g++ $(CFLAGS) -o A09 -I headers -I models -I shaders -I textures A09.cpp $(LDFLAGS)

.PHONY: test clean

test: A09
	./A09
clean:
	rm -f A09

