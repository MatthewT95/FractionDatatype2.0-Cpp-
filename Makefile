executable_name = main.exe
compiler_command = g++
source_files = source/*

all: compile run

compile:
	${compiler_command} ${source_files} -o ${executable_name}

run:
	./${executable_name}

clean:
	rm *.exe