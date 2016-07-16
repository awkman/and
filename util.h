#ifndef __UTIL_H_
#define __UTIL_H_


#define MAC_ADDR "%02x:%02x:%02x:%02x:%02x:%02x"
#define IP_ADDR "%u.%u.%u.%u"
#define P_MAC_ADDR(addr) addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]
#define P_IP_ADDR(addr) NTH_BYTE(addr, 3), NTH_BYTE(addr, 2), NTH_BYTE(addr, 1), NTH_BYTE(addr, 0)
#define NTH_BYTE(val, n) (val >> (n * 8) & 0xff)
#define DEV_NAME "and"

struct and_priv {
	struct net_device *netdev;
	struct notifier_block nb;
};

#endif
