obj-m  += module_1.o

KERNEL_DIR ?= /home/worker/android-kernel/common

all:
    make -C $(KERNEL_DIR) M=$(PWD) modules

clean:
    make -C $(KERNEL_DIR) M=$(PWD) clean
