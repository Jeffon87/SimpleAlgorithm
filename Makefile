#设置编译器
CC=gcc
CFLAGS= -g  -Wall
#debug文件夹里的makefile文件需要最后执行，所以这里需要执行的子目录要排除debug文件夹，这里使用awk排除了debug文件夹，读取剩下的文件夹
#SUBDIRS=$(shell ls -l | grep ^d | awk '{if($$9 != "build" and $$9 != "old") print $$9}')
SUBDIRS=common algorithm sorts
#无需下一行的注释代码，因为我们已经知道debug里的makefile是最后执行的，所以最后直接去debug目录下执行指定的makefile文件就行，具体下面有注释
BUILD_DIR=build
#记住当前工程的根目录路径
ROOT_DIR=$(shell pwd)
#最终bin文件的名字，可以更改为自己需要的
BIN=ssh_mytest
#目标文件所在的目录
OBJS_DIR=$(BUILD_DIR)/objs
#bin文件所在的目录
BIN_DIR=$(BUILD_DIR)/bin
#获取当前目录下的c文件集，放在变量CUR_SOURCE中
CUR_SOURCE=${wildcard *.c}
#将对应的c文件名转为o文件后放在下面的CUR_OBJS变量中
CUR_OBJS=${patsubst %.c, %.o, $(CUR_SOURCE)}

#将以下变量导出到子shell中，本次相当于导出到子目录下的makefile中
export CC BIN OBJS_DIR BIN_DIR ROOT_DIR
#注意这里的顺序，需要先执行CUR_OBJS判断并生成build目录,然后在编译SUBDIRS最后才能是BUILD
#all:PREPARE1 $(CUR_OBJS) $(SUBDIRS) BUILD
all:PREPARE1 $(CUR_OBJS) $(SUBDIRS) BUILD
#递归执行子目录下的makefile文件，这是递归执行的关键
$(SUBDIRS):ECHO
	make -C $@
#直接去build目录下执行makefile文件
BUILD:
	make -C $(BUILD_DIR)
ECHO:
	@echo $(SUBDIRS)
# 准备Makefile文件
PREPARE1:
	@if [ ! -d "$(BUILD_DIR)" ]; \
	then \
		echo "Create the build folder $(OBJS_DIR) and $(BIN_DIR)"; \
		mkdir -p $(OBJS_DIR) $(BIN_DIR); \
	else \
		echo "The build folder $(OBJS_DIR) and $(BIN_DIR) exist"; \
	fi
	@while [ 1 ] ; do \
		if [ ! -d "$(OBJS_DIR)" ] ; then \
			continue; \
		else \
			break; \
		fi; \
	done 
	@if [ ! -f "$(BUILD_DIR)/Makefile" ]; then \
		echo "TOTALOBJS=$(ROOT_DIR)/$(OBJS_DIR)/*.o" >> $(BUILD_DIR)/Makefile; \
		echo "$(ROOT_DIR)/$(BIN_DIR)/$(BIN):\$$(TOTALOBJS)" >> $(BUILD_DIR)/Makefile; \
		echo "	$(CC) $(CFLAGS) -o \$$@ \$$^" >> $(BUILD_DIR)/Makefile; \
	fi

#将c文件编译为o文件，并放在指定放置目标文件的目录中即OBJS_DIR
$(CUR_OBJS):%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $(ROOT_DIR)/$(OBJS_DIR)/$@
clean:
	@rm $(ROOT_DIR)/$(OBJS_DIR)/*.o
	@rm -rf $(ROOT_DIR)/$(BIN_DIR)/*