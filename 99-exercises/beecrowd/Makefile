.PHONY: clean
clean:
	@rm -rf ./.bin

.PHONY: build.cpp
build.cpp:
	@mkdir -p ./.bin
	@g++ -std=c++20 -o ./.bin/$(TARGET) $(shell find $(TARGET)*/$(TARGET).cpp)

.PHONY: run.cpp
run.cpp:
	@./.bin/$(TARGET)

.PHONY: run.python
run.python:
	@python $(shell find $(TARGET)*/$(TARGET).py)