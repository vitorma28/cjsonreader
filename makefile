arenafiles := $(wildcard src/arena/*.c)
jsonreaderfiles := $(wildcard src/jsonreader/*.c)
mapfiles := $(wildcard src/map/*.c)

testfile = build/test
finalfile = build/final


arena_test: tests/arena/arena_test.c $(arenafiles)
	@gcc -o $(testfile) tests/arena/arena_test.c $(arenafiles)
	@echo "Arquivo de teste de arena foi criado com sucesso."
