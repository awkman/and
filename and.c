
#include <linux/module.h>
#include "and_net_dev.h"

MODULE_AUTHOR("Jiang Sheng-Jhih");
MODULE_DESCRIPTION("Awk Network Driver");
MODULE_LICENSE("LGPL");


static int __init and_init(void)
{
	printk(KERN_INFO "%s\n", __func__);
	and_net_dev_init();
	return 0;
}

static void __exit and_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(and_init);
module_exit(and_exit);
