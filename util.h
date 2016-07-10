#ifndef __UTIL_H_
#define __UTIL_H_

#define MAC_ADDR "%02x:%02x:%02x:%02x:%02x:%02x"
#define P_MAC_ADDR(addr) addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]

struct and_priv {
	struct net_device *netdev;
};

#endif
