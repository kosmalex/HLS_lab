include_dirs := -I../ac_types/include/ -I../ac_math/include/

main.elf: main.c
	g++ main.c $(include_dirs) -o main.elf
	./main.elf

clean:
	rm *.elf
