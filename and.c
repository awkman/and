
#include <linux/module.h>
#include <linux/slab.h>
#include "util.h"
#include "and_net_dev.h"

MODULE_AUTHOR("Jiang Sheng-Jhih");
MODULE_DESCRIPTION("Awk Network Driver");
MODULE_LICENSE("LGPL");

static unsigned short log_level = 3;
module_param(log_level, ushort, 0444);
MODULE_PARM_DESC(log_level, "Log level");

struct and_priv *and;

static int __init and_init(void)
{
	printk(KERN_INFO "%s: log_level = %d\n", __func__, log_level);

	and_net_dev_init();

	return 0;
}

static void __exit and_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);

	and_net_dev_exit(and);
}

module_init(and_init);
module_exit(and_exit);
