#ifndef __UDP_H__
#define __UDP_H__

#include "vban.h"
#include <stdint.h>
#include "pico/stdlib.h"

// Buffer size config
#define DEF_UDP_PAYLOAD_SIZE    (DEF_VBAN_HEAD_SIZE+DEF_VBAN_PCM_SIZE)
// Ethernet
#define DEF_ETH_DST_MAC         (0xFFFFFFFFFFFF)    // L2 Broadcast
#define DEF_ETH_SRC_MAC         (0x123456789ABC)    // Dummy

// IP Header
#define DEF_IP_ADR_SRC1         (192)
#define DEF_IP_ADR_SRC2         (168)
#define DEF_IP_ADR_SRC3         (37)
#define DEF_IP_ADR_SRC4         (24)

#define DEF_IP_DST_DST1         (192)
#define DEF_IP_DST_DST2         (168)
#define DEF_IP_DST_DST3         (37)
#define DEF_IP_DST_DST4         (19)

// UDP Header
#define DEF_UDP_SRC_PORTNUM     (DEF_VBAN_PORTNUM)
#define DEF_UDP_DST_PORTNUM     (DEF_VBAN_PORTNUM)
#define DEF_UDP_LEN             (DEF_UDP_PAYLOAD_SIZE + 8)

// -------------------
// Preamble     7
// SFD          1
// Ether        14
// IP Header    20
// UDP Header   8
// UDP Payload  x
// FCS          4
// -------------------
//              x + 54
#define DEF_UDP_BUF_SIZE        (DEF_UDP_PAYLOAD_SIZE + 54)


void udp_init(void);
void __time_critical_func(udp_packet_gen)(uint32_t *buf, uint8_t *udp_payload);

#endif //__UDP_H__
