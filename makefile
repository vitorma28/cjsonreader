arenafiles := $(wildcard src/arena/*.c)
jsonreaderfiles := $(wildcard src/jsonreader/*.c)
mapfiles := $(wildcard src/map/*.c)

testfile = build/test
finalfile = build/final

CC = gcc
ctestflags = -g

clibflags = -L./libs
vectorlib = -lvector


run_test:
	./build/test


map_test: tests/map/map_test.c $(arenafiles) $(mapfiles)
	@$(CC) $(ctestflags) -o $(testfile) tests/map/map_test.c $(arenafiles) $(mapfiles)
	@echo "Compilação de arquivo de teste de Map concluída."


arena_test: tests/arena/arena_test.c $(arenafiles)
	@$(CC) $(ctestflags) -o $(testfile) tests/arena/arena_test.c $(arenafiles)
	@echo "Arquivo de teste de arena foi criado com sucesso."

jsonreader_tbs_test: tests/jsonreader/jsonreader_tbs.c $(arenafiles) $(jsonreaderfiles) libs/libvector.a
	@$(CC) $(clibflags) $(ctestflags) -o $(testfile) tests/jsonreader/jsonreader_tbs.c $(arenafiles) $(jsonreaderfiles) $(vectorlib) 
	@echo "Teste de jsonreader_tbs foi compilado."
