/***************************************************************************
 *            ifaces.h
 *
 *  Mon Jun 27 04:56:18 2005
 *  Copyright 2005-2009 Jaime Penalba Estebanez <jpenalbae@gmail.com>
 *  Copyright 2006      Guillaume Pratte <guillaume@guillaumepratte.net>
 *  Copyright 2007-2008 Gustavo Chain
 *
 ****************************************************************************/

/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */


#ifndef _IFACES_H
#define _IFACES_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <pcap.h>
#include <netinet/if_ether.h>
#include "data_al.h"

   /* If system is Solaris */
   #if defined(sun) && (defined(__svr4__) || defined(__SVR4))
      #define PCAP_TOUT 20
      typedef uint64_t u_int64_t;
      typedef uint32_t u_int32_t;
      typedef uint16_t u_int16_t;
      typedef uint8_t  u_int8_t;
   #else
      #define PCAP_TOUT 0
   #endif


   /* Shitty globals */
   char errbuf[PCAP_ERRBUF_SIZE];

   /* Threads data structure */
   struct t_data {
      char *interface;
      char *source_ip;
      char *pcap_filter;
      struct ether_addr **ignore_macs;
   };

   /* Sniffer/Packet processing Functions */
   void *start_sniffer(void *);
   void process_arp_header(struct data_registry *, const u_char *);
   void process_packet(u_char *, struct pcap_pkthdr *, const u_char *);

   /* ARP Generation & Injection */
   void inject_init(char *);
   void forge_arp(char *, char *, char *);
   void inject_destroy();

#ifdef __cplusplus
}
#endif

#endif /* _IFACES_H */
