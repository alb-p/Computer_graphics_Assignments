CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXrandr -lXi
A03: A03.cpp
	g++ $(CFLAGS) -o A03 -I headers -I models -I shaders -I textures A03.cpp $(LDFLAGS)

.PHONY: test clean

test: A03
	./A03
clean:
	rm -f A03

