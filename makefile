# Makefile

.PHONY: all s% clean

# 默认目标，编译所有文件
all:
	@echo "Compiling all solutions..."
	@mkdir -p build
	@cd build && cmake .. && make

# 编译并运行指定文件，例如 make s1
s%:
	@echo "Building and running solution s$*..."
	@mkdir -p build
	@cd build && cmake .. && make s$*
	@echo "--- Output of s$*.cpp ---"
	@./build/s$*
	@echo "---------  End  ---------"

f%:
	@echo "Generating template for solution s$*..."
	@cp solutions/template.cpp solutions/s$*.cpp

# 清理构建目录
clean:
	@echo "Cleaning build directory..."
	@rm -rf build