TARGET=and_net
CC=gcc
cc-flags-y := -g

obj-m += $(TARGET).o
$(TARGET)-objs := and.o and_net_dev.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
