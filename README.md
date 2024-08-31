# Tbin
#### Translate binary formats to text
This simple tool can be used to translate different binary formats to ascii text.

Currently supported:
- Binary -> ASCII
- Hexadecimal -> ASCII

Support for more formats + text to binary format translation is coming

## Install
Required:
- git
- make
- C compiler (gcc for example)

This program may not compile on Windows, since there is no "getopt" implementation there (thank you Microsoft :D)

#### Using the install script

1. Clone the repository
```
git clone https://github.com/GHaxZ/tbin.git
```

2. Go inside the directory
```
cd tbin
```

3. Use make to compile and install the binary
```
sudo make install
```

If everything went well you should be able to simply run the command "tbin"
```
tbin -h
```

#### Compiling yourself
If you don't have make installed or simply want to do so, you can compile yourself.

1. Clone the repository
```
git clone https://github.com/GHaxZ/tbin.git
```

2. Go inside the directory
```
cd tbin
```

3. Compile yourself using gcc for example
```
gcc ./src/main.c ./src/argparse.c ./src/translate.c ./src/exit.c -o ./out/tbin
```
There is now a compiled binary in the "./out/" directory

4. Move the installed binary into a directory which is added to your PATH
   (on Unix systems /usr/local/bin is the usual place for this)
```
mv ./out/tbin /usr/local/bin
```
If you have permission problems, run as root (sudo)
```
sudo mv ./out/tbin /usr/local/bin
```

If everything went well you should be able to simply run the command "tbin"
```
tbin -h
```
