all: build/Makefile
	$(MAKE) -C build

build/Makefile: CMakeLists.txt
	cmake -S . -B build

install: all
	$(MAKE) -C build install

clean:
	$(MAKE) -C build clean
	rm -rf build/
