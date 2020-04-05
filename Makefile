CC=gcc
CFLAG=-Wall -g
EXEC=main

$(EXEC):$(EXEC).c
	@echo Program is compiling
	@$(CC) -o $(EXEC) $(EXEC).c
	@echo "Compilation is finished"
plot:
	@echo Plotting the fft of both filtered and unfiltered noise
	@python plot.py
clean:
	rm *.exe