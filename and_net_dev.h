#ifndef __AND_NET_DEV_H__
#define __AND_NET_DEV_H__

#include <linux/netdevice.h>
#include "util.h"

int and_net_dev_init(void);
void and_net_dev_exit(struct and_priv *and);

#endif
