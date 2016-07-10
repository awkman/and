#include <linux/module.h>
#include <linux/etherdevice.h>
#include <linux/if_arp.h>
#include "util.h"
#include "and_net_dev.h"

extern struct and_priv *and;

static int and_net_dev_ops_init(struct net_device *netdev)
{
	printk(KERN_INFO "%s\n", __func__);

	return 0;
}

static int and_net_dev_ops_open(struct net_device *netdev)
{
	printk(KERN_INFO "%s\n", __func__);

	if (netif_queue_stopped(netdev))
		netif_wake_queue(netdev);

	return 0;
}

static int and_net_dev_ops_stop(struct net_device *netdev)
{
	printk(KERN_INFO "%s\n", __func__);

	netif_stop_queue(netdev);

	return 0;
}

static netdev_tx_t and_net_dev_ops_start_xmit(struct sk_buff *skb, struct net_device *netdev)
{
	printk(KERN_INFO "%s\n", __func__);

	return NETDEV_TX_OK;
}

static int and_net_dev_ops_set_mac_addr(struct net_device *netdev, void *p)
{
	struct sockaddr *addr = p;

	printk(KERN_INFO "%s\n", __func__);

	if (!is_valid_ether_addr(addr->sa_data))
		return -EADDRNOTAVAIL;

	memcpy(netdev->dev_addr, addr->sa_data, ETH_ALEN);
	printk(KERN_INFO "%s: %s MAC address was changed to " MAC_ADDR "\n",
	  __func__, netdev->name, P_MAC_ADDR(netdev->dev_addr));
	
	return 0;
}

static int and_net_dev_ops_do_ioctl(struct net_device *netdev, struct ifreq *ifreq, int cmd)
{
	printk(KERN_INFO "%s\n", __func__);

	return 0;
}

static const struct net_device_ops and_net_dev_ops = {
	.ndo_init = and_net_dev_ops_init,
	.ndo_open = and_net_dev_ops_open,
	.ndo_stop = and_net_dev_ops_stop,
	.ndo_start_xmit = and_net_dev_ops_start_xmit,
	.ndo_set_mac_address = and_net_dev_ops_set_mac_addr,
	.ndo_do_ioctl = and_net_dev_ops_do_ioctl,
};

static void and_net_dev_setup(struct net_device *netdev)
{
	printk(KERN_INFO "%s\n", __func__);
	netdev->netdev_ops = &and_net_dev_ops;
}

int and_net_dev_init()
{
	struct net_device *netdev = NULL;
	int ret = 0;

	printk(KERN_INFO "%s\n", __func__);

	netdev = alloc_netdev(sizeof(*and), "and%d", NET_NAME_ENUM, and_net_dev_setup);
	if (!netdev)
		return -ENOMEM;

	netdev->type = ARPHRD_ETHER;
	netdev->addr_len = ETH_ALEN;

	ret = register_netdev(netdev);
	if (ret) {
		free_netdev(netdev);
		goto error;
	}

	and = netdev_priv(netdev);
	if (!and)
		return -ENOMEM;

	and->netdev = netdev;

	return 0;

error:
	printk(KERN_ERR "%s: failed\n", __func__);
	return ret;
}

void and_net_dev_exit(struct and_priv *and)
{
	printk(KERN_INFO "%s\n", __func__);

	if (and->netdev) {
		unregister_netdev(and->netdev);
		free_netdev(and->netdev);
	}

	kfree(and);
}
