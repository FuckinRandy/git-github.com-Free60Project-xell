/*
 * Copyright (c) 2001, 2002 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
 
 
#ifndef __LWIPOPTS_H__
#define __LWIPOPTS_H__

#include <string.h>
#include <vsprintf.h>

#define NO_SYS 1
#define LWIP_CALLBACK_API 1

/* -------- TCP Timer Intervals ------- */
#define TCP_TMR_INTERVAL       1    /* The TCP timer interval in
                                       milliseconds. */

#define TCP_FAST_INTERVAL      2    /* the fine grained timeout in
                                       milliseconds */

#define TCP_SLOW_INTERVAL      5    /* the coarse grained timeout in
                                       milliseconds */

/* ---------- Memory options ---------- */
/* MEM_ALIGNMENT: should be set to the alignment of the CPU for which
   lwIP is compiled. 4 byte alignment -> define MEM_ALIGNMENT to 4, 2
   byte alignment -> define MEM_ALIGNMENT to 2. */
#define MEM_ALIGNMENT           4

/* MEM_SIZE: the size of the heap memory. If the application will send
a lot of data that needs to be copied, this should be set high. */
#define MEM_SIZE                65536

/* MEMP_NUM_PBUF: the number of memp struct pbufs. If the application
   sends a lot of data out of ROM (or other static memory), this
   should be set high. */
#define MEMP_NUM_PBUF           64
/* MEMP_NUM_UDP_PCB: the number of UDP protocol control blocks. One
   per active UDP "connection". */
#define MEMP_NUM_UDP_PCB        8
/* MEMP_NUM_TCP_PCB: the number of simulatenously active TCP
   connections. */
#define MEMP_NUM_TCP_PCB        8
/* MEMP_NUM_TCP_PCB_LISTEN: the number of listening TCP
   connections. */
#define MEMP_NUM_TCP_PCB_LISTEN 16
/* MEMP_NUM_TCP_SEG: the number of simultaneously queued TCP
   segments. */
#define MEMP_NUM_TCP_SEG        255

/* The following four are used only with the sequential API and can be
   set to 0 if the application only will use the raw API. */
/* MEMP_NUM_NETBUF: the number of struct netbufs. */
#define MEMP_NUM_NETBUF         0
/* MEMP_NUM_NETCONN: the number of struct netconns. */
#define MEMP_NUM_NETCONN        0
/* MEMP_NUM_APIMSG: the number of struct api_msg, used for
   communication between the TCP/IP stack and the sequential
   programs. */
#define MEMP_NUM_API_MSG        0
/* MEMP_NUM_TCPIPMSG: the number of struct tcpip_msg, which is used
   for sequential API communication and incoming packets. Used in
   src/api/tcpip.c. */
#define MEMP_NUM_TCPIP_MSG      0
/* MEMP_NUM_SYS_TIMEOUT: the number of simulateously active
   timeouts. */
#define MEMP_NUM_SYS_TIMEOUT    0

/* ---------- Pbuf options ---------- */
/* PBUF_POOL_SIZE: the number of buffers in the pbuf pool. */
#define PBUF_POOL_SIZE          512

/* PBUF_POOL_BUFSIZE: the size of each pbuf in the pbuf pool. */
#define PBUF_POOL_BUFSIZE       1536

/* PBUF_LINK_HLEN: the number of bytes that should be allocated for a
   link level header. */
#define PBUF_LINK_HLEN          16

/* ---------- TCP options ---------- */
#define LWIP_TCP                1
#define TCP_TTL                 255

/* Controls if TCP should queue segments that arrive out of
   order. Define to 0 if your device is low on memory. */
#define TCP_QUEUE_OOSEQ         1

/* TCP Maximum segment size. */
#define TCP_MSS                 1476

/* TCP sender buffer space (bytes). */
#define TCP_SND_BUF             32 * 1024

/* TCP sender buffer space (pbufs). This must be at least = 2 *
   TCP_SND_BUF/TCP_MSS for things to work. */
#define TCP_SND_QUEUELEN        2 * TCP_SND_BUF/TCP_MSS

/* TCP receive window. */
#define TCP_WND                 16 * 1024
//#define TCP_WND                 3000

/* Maximum number of retransmissions of data segments. */
#define TCP_MAXRTX              12

/* Maximum number of retransmissions of SYN segments. */
#define TCP_SYNMAXRTX           4

/* ---------- ARP options ---------- */
#define ARP_TABLE_SIZE 10
#define ARP_QUEUEING 1

/* ---------- IP options ---------- */
/* Define IP_FORWARD to 1 if you wish to have the ability to forward
   IP packets across network interfaces. If you are going to run lwIP
   on a device with only one network interface, define this to 0. */
#define IP_FORWARD              0

/* If defined to 1, IP options are allowed (but not parsed). If
   defined to 0, all packets with IP options are dropped. */
#define IP_OPTIONS              1

/* ---------- ICMP options ---------- */
#define ICMP_TTL                255


#define LWIP_DHCP               1

/* 1 if you want to do an ARP check on the offered address
   (recommended). */
#define DHCP_DOES_ARP_CHECK     0

/* ---------- UDP options ---------- */
#define LWIP_UDP                1
#define UDP_TTL                 255


/* ---------- Statistics options ---------- */
/*#define STATS*/

#ifdef STATS
#define LINK_STATS
#define IP_STATS
#define ICMP_STATS
#define UDP_STATS
#define TCP_STATS
#define MEM_STATS
#define MEMP_STATS
#define PBUF_STATS
#define SYS_STATS
#endif /* STATS */

#if 0

#define LWIP_DEBUG
#define DBG_TYPES_ON                    -1
#if 1
#define ETHARP_DEBUG                    (DBG_ON | DBG_TRACE)
#define NETIF_DEBUG                     (DBG_ON | DBG_TRACE)
#define PBUF_DEBUG                      DBG_OFF
#define API_LIB_DEBUG                   (DBG_ON | DBG_TRACE)
#define API_MSG_DEBUG                   (DBG_ON | DBG_TRACE)
#define SOCKETS_DEBUG                   (DBG_ON | DBG_TRACE)
#define ICMP_DEBUG                      (DBG_ON | DBG_TRACE)
#define INET_DEBUG                      (DBG_ON | DBG_TRACE)
#define IP_DEBUG                        (DBG_ON | DBG_TRACE)
#define IP_REASS_DEBUG                  (DBG_ON | DBG_TRACE)
#define RAW_DEBUG                       (DBG_ON | DBG_TRACE)
#define MEM_DEBUG                       DBG_OFF
#define MEMP_DEBUG                      DBG_OFF
#define SYS_DEBUG                       (DBG_ON | DBG_TRACE)
#define TCP_DEBUG                       (DBG_ON | DBG_TRACE)
#define TCP_INPUT_DEBUG                 (DBG_ON | DBG_TRACE)
#define TCP_FR_DEBUG                    (DBG_ON | DBG_TRACE)
#define TCP_RTO_DEBUG                   (DBG_ON | DBG_TRACE)
#define TCP_REXMIT_DEBUG                (DBG_ON | DBG_TRACE)
#define TCP_CWND_DEBUG                  (DBG_ON | DBG_TRACE)
#define TCP_WND_DEBUG                   (DBG_ON | DBG_TRACE)
#define TCP_OUTPUT_DEBUG                (DBG_ON | DBG_TRACE)
#define TCP_RST_DEBUG                   (DBG_ON | DBG_TRACE)
#define TCP_QLEN_DEBUG                  (DBG_ON | DBG_TRACE)
#define UDP_DEBUG                       (DBG_ON | DBG_TRACE)
#define TCPIP_DEBUG                     (DBG_ON | DBG_TRACE)
#define PPP_DEBUG                       (DBG_ON | DBG_TRACE)
#define SLIP_DEBUG                      (DBG_ON | DBG_TRACE)
#endif

#define DHCP_DEBUG                      (DBG_ON | DBG_TRACE)

#define DBG_MIN_LEVEL                   DBG_LEVEL_OFF
#endif

#endif /* __LWIPOPTS_H__ */
