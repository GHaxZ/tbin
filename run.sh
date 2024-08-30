gcc ./src/main.c ./src/argparse.c ./src/translate.c ./src/exit.c -o ./out/tbin || exit

./out/tbin "$@"

