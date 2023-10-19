executable_name = main.exe
compiler_command = g++
source_files = $(wildcard source/*)

all: compile run

compile:
	@echo "Compiling program..."
	@${compiler_command} ${source_files} -o ${executable_name}
	@echo "Program compiled."

run:
	@echo "Running program..."
	@./${executable_name}
	@echo "program ended."

clean:
	@echo "Removing binaries..."
	@rm *.exe
	@echo "Binaries removed successfully"