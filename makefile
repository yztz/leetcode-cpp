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
	@if test -f solutions/s$*.cpp; then \
		echo "Error: solutions/s$*.cpp already exists. Aborting." 1>&2; \
		false; \
	else \
		cp solutions/template.cpp solutions/s$*.cpp; \
		code solutions/s$*.cpp; \
	fi


commit:
	@git add .
	@read -p "请输入 Commit 消息: " msg; \
	git commit -m "$$msg"
	@echo "--- 已成功提交到本地仓库 ---"

# 清理构建目录
clean:
	@echo "Cleaning build directory..."
	@rm -rf build