
#include <linux/module.h>

MODULE_AUTHOR("Jiang Sheng-Jhih");
MODULE_DESCRIPTION("Awk Network Driver");
MODULE_LICENSE("LGPL");


static int __init and_init(void)
{
	printk(KERN_INFO "%s\n", __func__);
	return 0;
}

static void __exit and_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(and_init);
module_exit(and_exit);
