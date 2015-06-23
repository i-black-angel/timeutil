TARGET = timeutil

$(TARGET): main.o
	$(LINK.cc) $< -o $@

.PHONY: clean
clean:
	@$(RM) *.o
	@$(RM) $(TARGET)
