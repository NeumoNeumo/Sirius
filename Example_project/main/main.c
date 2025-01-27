
#include "kinit.h"
#include <linux/init.h>
#include <linux/module.h>


//运行的程序堆栈大小不要超过16kb，如果有更大内存需求请进入/kernel/config/中调整或者另外创建独立的任务

//你可以通过注释掉下面代码来选择你需要的模块模块间高度解耦，只需在main.c中声明需要的模块即可，不需要的模块注释掉即可

int __init spi_init(void);
module_init(spi_init);

int __init st7789_driver_init(void);
module_init(st7789_driver_init);

// int __init button0_driver_init(void);
// module_init(button0_driver_init);

int __init i2c_2_dev_init(void);
module_init(i2c_2_dev_init);

int __init i2c_1_dev_init(void);
module_init(i2c_1_dev_init);

int __init tty1_init(void);
module_init(tty1_init);

void add_i2cdetect_console_app(void);
AppInit_init(add_i2cdetect_console_app);

void add_pikapython_console_app(void);
AppInit_init(add_pikapython_console_app);

void install_test();
AppInit_init(install_test);

void lv_demo_install(void);
AppInit_init(lv_demo_install);


//espidf中只有rsicv gcc支持module_init初始化宏，如果模块没有被正确链接请注释上方所有部分并使用下面代码

// int __init button0_driver_init(void);
// int __init i2c_2_dev_init(void);
// int __init i2c_1_dev_init(void);
// int __init spi_init(void);
// int __init st7789_driver_init(void);
// void add_i2cdetect_console_app(void);
// void add_pikapython_console_app(void);
// void start_console(void);
// void __init __init__(void);
// void app_main(){
// __init__();     
// button0_driver_init();
// i2c_2_dev_init();
// i2c_1_dev_init();
// spi_init();
// st7789_driver_init();
// add_i2cdetect_console_app();
// add_pikapython_console_app();
// start_console();
// }



