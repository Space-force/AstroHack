ARDUINO_DIR="main"

$(ARDUINO_DIR)/secrets.h:
	@cp secrets.default.h $(ARDUINO_DIR)/secrets.h
