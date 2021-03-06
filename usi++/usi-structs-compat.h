/*
 * This file is part of the libusi++ packet capturing/sending framework.
 *
 * (C) 2000-2015 by Sebastian Krahmer,
 *                  sebastian [dot] krahmer [at] gmail [dot] com
 *
 * libusi++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libusi++ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with psc.  If not, see <http://www.gnu.org/licenses/>.
 */

// include this if you want uppercase enums for compatibility

#ifndef usipp_usi_structs_compat_h
#define usipp_usi_structs_compat_h


/* putting an own version of
 * iphdr, udphdr, tcphdr, icmphdr and pseudohdr
 * in usipp namespace to avoid collision with
 * kernel ones. Mostly the IP etc. structs from system to system differ
 * and are often broken. Some of this was just copied from standard .h files,
 * but changed to an enum rather than a define.
 */

namespace usipp {


enum  {
	MAXHOSTLEN = 1000,
	ETH_ALEN = 6,
	ETH_A_LEN = 6
};


/*
 *	These are the defined Ethernet Protocol ID's.
 */
enum {
	ETH_P_LOOP	= 0x0060,	// Ethernet Loopback packet
	ETH_P_ECHO	= 0x0200,	// Ethernet Echo packet
	ETH_P_PUP	= 0x0400,	// Xerox PUP packet
	ETH_P_IP	= 0x0800,	// Internet Protocol packet
	ETH_P_X25	= 0x0805,	// CCITT X.25
	ETH_P_ARP	= 0x0806,	// Address Resolution packet
	ETH_P_BPQ	= 0x08FF,	// G8BPQ AX.25 Ethernet Packet	[ NOT AN OFFICIALLY REGISTERED ID ]
	ETH_P_DEC	= 0x6000,	// DEC Assigned proto
	ETH_P_DNA_DL	= 0x6001,	// DEC DNA Dump/Load
	ETH_P_DNA_RC	= 0x6002,	// DEC DNA Remote Console
	ETH_P_DNA_RT	= 0x6003,	// DEC DNA Routing
	ETH_P_LAT	= 0x6004,	// DEC LAT
	ETH_P_DIAG	= 0x6005,	// DEC Diagnostics
	ETH_P_CUST	= 0x6006,	// DEC Customer use
	ETH_P_SCA	= 0x6007,	// DEC Systems Comms Arch
	ETH_P_RARP	= 0x8035,	// Reverse Addr Res packet
	ETH_P_ATALK	= 0x809B,	// Appletalk DDP
	ETH_P_AARP	= 0x80F3,	// Appletalk AARP
	ETH_P_IPX	= 0x8137,	// IPX over DIX
	ETH_P_IPV6	= 0x86DD,	// IPv6 over bluebook
	ETH_P_EAPOL	= 0x888E,	// 802.1x EAP over LAN
	ETH_P_PAE	= ETH_P_EAPOL,	// Port Access Entry
	ETH_P_PRE_AUTH	= 0x88C7,	// WPA2 pre auth

/*
 *	Non DIX types. Won't clash for 1500 types.
 */

	ETH_P_802_3	= 0x0001,	// Dummy type for 802.3 frames
	ETH_P_AX25	= 0x0002,	// Dummy protocol id for AX.25
	ETH_P_ALL	= 0x0003,	// Every packet (be careful!!!)
	ETH_P_802_2	= 0x0004,	// 802.2 frames
	ETH_P_SNAP	= 0x0005,	// Internal only
	ETH_P_DDCMP	= 0x0006,	// DEC DDCMP: Internal only
	ETH_P_WAN_PPP	= 0x0007,	// Dummy type for WAN PPP frames
	ETH_P_PPP_MP	= 0x0008,	// Dummy type for PPP MP frames
	ETH_P_LOCALTALK = 0x0009,	// Localtalk pseudo type
	ETH_P_PPPTALK	= 0x0010,	// Dummy type for Atalk over PPP
	ETH_P_TR_802_2	= 0x0011,	// 802.2 frames
	ETH_P_MOBITEX	= 0x0015,	// Mobitex (kaz@cafe.net)
	ETH_P_CONTROL	= 0x0016,	// Card specific control frames
	ETH_P_IRDA	= 0x0017	// Linux/IR
};


/* ARP protocol opcodes. */
enum {
	ARPOP_REQUEST =	1,		// ARP request.
	ARPOP_REPLY   =	2,		// ARP reply.
	ARPOP_RREQUEST=	3,		// RARP request.
	ARPOP_RREPLY  =	4,		// RARP reply.
};


/* ARP protocol HARDWARE identifiers. */
enum {
	ARPHRD_NETROM =	0,		// From KA9Q: NET/ROM pseudo.
	ARPHRD_ETHER  =	1,		// Ethernet 10/100Mbps.
	ARPHRD_EETHER =	2,		// Experimental Ethernet.
	ARPHRD_AX25   =	3,		// AX.25 Level 2.
	ARPHRD_PRONET =	4,		// PROnet token ring.
	ARPHRD_CHAOS  =	5,		// Chaosnet.
	ARPHRD_IEEE802 = 6,		// IEEE 802.2 Ethernet/TR/TB.
	ARPHRD_ARCNET  = 7,		// ARCnet.
	ARPHRD_APPLETLK = 8,		// APPLEtalk.
	ARPHRD_DLCI  =	15,		// Frame Relay DLCI.
	ARPHRD_METRICOM = 23,		// Metricom STRIP (new IANA id).

	/* Dummy types for non ARP hardware */
	ARPHRD_SLIP  =	256,
	ARPHRD_CSLIP =	257,
	ARPHRD_SLIP6 =	258,
	ARPHRD_CSLIP6 =	259,
	ARPHRD_RSRVD =	260,		/* Notional KISS type.  */
	ARPHRD_ADAPT =	264,
	ARPHRD_ROSE  =	270,
	ARPHRD_X25   =	271,		/* CCITT X.25.  */
	ARPHRD_PPP   =	512,
	ARPHRD_HDLC  =	513,		/* (Cisco) HDLC.  */
	ARPHRD_LAPB  =	516,		/* LAPB.  */

	ARPHRD_TUNNEL =	768,		/* IPIP tunnel.  */
	ARPHRD_TUNNEL6 = 769,		/* IPIP6 tunnel.  */
	ARPHRD_FRAD  =	770,            /* Frame Relay Access Device.  */
	ARPHRD_SKIP  =	771,		/* SKIP vif.  */
	ARPHRD_LOOPBACK = 772,		/* Loopback device.  */
	ARPHRD_LOCALTLK = 773,		/* Localtalk device.  */
	ARPHRD_FDDI  =	774,		/* Fiber Distributed Data Interface. */
	ARPHRD_BIF   =	775,            /* AP1000 BIF.  */
	ARPHRD_SIT   =	776,		/* sit0 device - IPv6-in-IPv4.  */
	ARPHRD_IPDDP =	777,		/* IP-in-DDP tunnel.  */
	ARPHRD_IPGRE =	778,		/* GRE over IP.  */
	ARPHRD_PIMREG =	779,		/* PIMSM register interface.  */
	ARPHRD_HIPPI  =	780,		/* High Performance Parallel I'face. */
	ARPHRD_ASH   =	781,		/* (Nexus Electronics) Ash.  */
	ARPHRD_ECONET =	782,		/* Acorn Econet.  */
	ARPHRD_IRDA  =	783,		/* Linux/IR.  */
	ARPHRD_FCPP  =	784,		/* Point to point fibrechanel.  */
	ARPHRD_FCAL  =	785,		/* Fibrechanel arbitrated loop.  */
	ARPHRD_FCPL  =	786,		/* Fibrechanel public loop.  */
	ARPHRD_FCPFABRIC =  787		/* Fibrechanel fabric.  */
};


enum {
	ICMP_ECHOREPLY	   =	0,	// Echo Reply
	ICMP_DEST_UNREACH  =	3,	// Destination Unreachable
	ICMP_SOURCE_QUENCH =	4,	// Source Quench
	ICMP_REDIRECT	   =	5,	// Redirect (change route)
	ICMP_ECHO	   =	8,	// Echo Request
	ICMP_TIME_EXCEEDED =	11,	// Time Exceeded
	ICMP_PARAMETERPROB =	12,	// Parameter Problem
	ICMP_TIMESTAMP	   =	13,	// Timestamp Request
	ICMP_TIMESTAMPREPLY=	14,	// Timestamp Reply
	ICMP_INFO_REQUEST  =	15,	// Information Request
	ICMP_INFO_REPLY	   =	16,	// Information Reply
	ICMP_ADDRESS	   =	17,	// Address Mask Reques
	ICMP_ADDRESSREPLY  =	18,	// Address Mask Reply
	NR_ICMP_TYPES	   =	18
};


// Codes for UNREACH.
enum {
	ICMP_NET_UNREACH   =	0,	// Network Unreachable
	ICMP_HOST_UNREACH  =	1,	// Host Unreachable
	ICMP_PROT_UNREACH  =	2,	// Protocol Unreachable
	ICMP_PORT_UNREACH  =	3,	// Port Unreachable
	ICMP_FRAG_NEEDED   =	4,	// Fragmentation Needed/DF set
	ICMP_SR_FAILED	   =	5,	// Source Route failed
	ICMP_NET_UNKNOWN   =	6,
	ICMP_HOST_UNKNOWN  =	7,
	ICMP_HOST_ISOLATED =	8,
	ICMP_NET_ANO	   =	9,
	ICMP_HOST_ANO	   =	10,
	ICMP_NET_UNR_TOS   =	11,
	ICMP_HOST_UNR_TOS  =	12,
	ICMP_PKT_FILTERED  =	13,	// Packet filtered
	ICMP_PREC_VIOLATION =	14,	// Precedence violation
	ICMP_PREC_CUTOFF    =	15,	// Precedence cut off
	NR_ICMP_UNREACH	    =	15	// instead of hardcoding immediate value
};


// Codes for REDIRECT.
enum {
	ICMP_REDIR_NET	   =	0,	// Redirect Net
	ICMP_REDIR_HOST	   =	1,	// Redirect Host
	ICMP_REDIR_NETTOS  =	2,	// Redirect Net for TOS
	ICMP_REDIR_HOSTTOS =	3	// Redirect Host for TOS
};


// Codes for TIME_EXCEEDED.
enum {
	ICMP_EXC_TTL =	0,	// TTL count exceeded
	ICMP_EXC_FRAGTIME = 1	// Fragment Reass time exceeded
};


enum {
	TH_FIN	= 0x001,
	TH_SYN	= 0x002,
	TH_RST	= 0x004,
	TH_PUSH	= 0x008,
	TH_ACK	= 0x010,
	TH_URG	= 0x020,
	TH_ECE  = 0x040,
	TH_CWR  = 0x080,
	TH_NS   = 0x100
};


enum {
	IP_RF = 0x8000,
	IP_DF = 0x4000,
	IP_MF = 0x2000,
	IP_OFFMASK = 0x1fff
};


enum {
	TCPOPT_EOL	=	0,
	TCPOPT_NOP	=	1,
	TCPOPT_MAXSEG	=	2,
	TCPOLEN_MAXSEG	=	4,
	TCPOPT_WINDOW	=	3,
	TCPOLEN_WINDOW	=	3,
	TCPOPT_SACK_PERMITTED =	4,			// Experimental
	TCPOLEN_SACK_PERMITTED=	2,
	TCPOPT_SACK	=	5,			// Experimental
	TCPOPT_TIMESTAMP   =	8,
	TCPOLEN_TIMESTAMP  =	10,
	TCPOLEN_TSTAMP_APPA  =	(TCPOLEN_TIMESTAMP+2)	// appendix A
};


enum {
	IPV6_FL_A_GET  	=	0,
	IPV6_FL_A_PUT   =	1,
	IPV6_FL_A_RENEW =	2,
	IPV6_FL_F_CREATE   =    1,
	IPV6_FL_F_EXCL     =    2,
	IPV6_FL_S_NONE     =    0,
	IPV6_FL_S_EXCL     =    1,
	IPV6_FL_S_PROCESS  =    2,
	IPV6_FL_S_USER     =    3,
	IPV6_FL_S_ANY      =    255
};



/*
 *      Bitmask constant declarations to help applications select out the
 *      flow label and priority fields.
 *
 *      Note that this are in host byte order while the flowinfo field of
 *      sockaddr_in6 is in network byte order.
 */

enum {
	IPV6_FLOWINFO_FLOWLABEL    =     0x000fffff,
	IPV6_FLOWINFO_PRIORITY     =     0x0ff00000
};


/*
 *      IPv6 TLV options.
 */
enum {
	IPV6_TLV_PAD0     =      0,
	IPV6_TLV_PADN     =      1,
	IPV6_TLV_ROUTERALERT  =  5,
	IPV6_TLV_JUMBO        =  194
};



// icmp6 types and options
enum {
	ICMP6_DST_UNREACH	=      1,
	ICMP6_PACKET_TOO_BIG	=      2,
	ICMP6_TIME_EXCEEDED	=      3,
	ICMP6_PARAM_PROB	=      4,

	ICMP6_INFOMSG_MASK	=	0x80,		// all informational messages

	ICMP6_ECHO_REQUEST	=	128,
	ICMP6_ECHO_REPLY	=	129,
	ICMP6_MEMBERSHIP_QUERY	=	130,
	ICMP6_MEMBERSHIP_REPORT	=	131,
	ICMP6_MEMBERSHIP_REDUCTION	=	132,

	ICMP6_DST_UNREACH_NOROUTE	= 	0,	// no route to destination
	ICMP6_DST_UNREACH_ADMIN		=	1,	// communication with destination
                                        		// administratively prohibited
	ICMP6_DST_UNREACH_NOTNEIGHBOR	= 	2,	// not a neighbor
	ICMP6_DST_UNREACH_ADDR		=	3,	// address unreachable
	ICMP6_DST_UNREACH_NOPORT	=	4,	// bad port

	ICMP6_TIME_EXCEED_TRANSIT	=	0,	// Hop Limit == 0 in transit
	ICMP6_TIME_EXCEED_REASSEMBLY	=	1,	// Reassembly time out

	ICMP6_PARAMPROB_HEADER		=	0,	// erroneous header field
	ICMP6_PARAMPROB_NEXTHEADER	=	1,	// unrecognized Next Header
	ICMP6_PARAMPROB_OPTION		=	2,	// unrecognized IPv6 option

	ICMP6_ND_ROUTER_SOLICIT		=	133,
	ICMP6_ND_ROUTER_ADVERT		=	134,
	ICMP6_ND_NEIGHBOR_SOLICIT	=	135,
	ICMP6_ND_NEIGHBOR_ADVERT	=	136,
	ICMP6_ND_REDIRECT		=	137,

	ND_OPT_SOURCE_LL_ADDR	=	1,
	ND_OPT_TARGET_LL_ADDR	=	2,
	ND_OPT_PREFIX_INFO	=	3,
	ND_OPT_REDIRECT_HDR	=	4,
	ND_OPT_MTU		=	5,
	ND_OPT_ROUTE_INFO	=	24,
	ND_OPT_RDNSS		=	25,
	ND_OPT_DNSSL		=	31
};


enum {
	NEXT_HDR_HBH	= 0,		// hop by hop
	NEXT_HDR_RH	= 43,		// routing header
	NEXT_HDR_FH	= 44,		// fragmentation header
	NEXT_HDR_DOH	= 60,		// destination option
	NEXT_HDR_MOB	= 135		// mobility header
};


enum {
	TX_TAG_NONE	= 0,
	RX_TAG_NONE	= 0,

	TX_TAG_IP	= 0x1000,
	TX_TAG_IP6,
	TX_TAG_DNET_IP,
	TX_TAG_DNET_ETH,
	TX_TAG_PCAP,
	TX_TAG_PCAP_ETH,
	TX_TAG_STRING,

	RX_TAG_PCAP	= 0x2000
};


// IANA assigned protocol numbers. OSX defines them in in.h so we need to #ifdef around it
enum {
#ifndef IPPROTO_IP
	IPPROTO_IP		= 0,
#endif
#ifndef IPPROTO_HOPOPTS
	IPPROTO_HOPOPTS		= 0,		/* IPv6 Hop-by-Hop options.  */
#endif
#ifndef IPPROTO_ICMP
	IPPROTO_ICMP		= 1,		/* Internet Control Message Protocol.  */
#endif
#ifndef IPPROTO_IGMP
	IPPROTO_IGMP		= 2,		/* Internet Group Management Protocol. */
#endif
#ifndef IPPROTO_IPIP
	IPPROTO_IPIP		= 4,		/* IPIP tunnels (older KA9Q tunnels use 94).  */
#endif
#ifndef IPPROTO_TCP
	IPPROTO_TCP		= 6,		/* Transmission Control Protocol.  */
#endif
#ifndef IPPROTO_EGP
	IPPROTO_EGP		= 8,		/* Exterior Gateway Protocol.  */
#endif
#ifndef IPPROTO_PUP
	IPPROTO_PUP		= 12,		/* PUP protocol.  */
#endif
#ifndef IPPROTO_UDP
	IPPROTO_UDP		= 17,		/* User Datagram Protocol.  */
#endif
#ifndef IPPROTO_IDP
	IPPROTO_IDP		= 22,		/* XNS IDP protocol.  */
#endif
#ifndef IPPROTO_TP
	IPPROTO_TP		= 29,		/* SO Transport Protocol Class 4.  */
#endif
#ifndef IPPROTO_DCCP
	IPPROTO_DCCP		= 33,		/* Datagram Congestion Control Protocol.  */
#endif
#ifndef IPPROTO_IPV6
	IPPROTO_IPV6		= 41,		/* IPv6 header.  */
#endif
#ifndef IPPROTO_ROUTING
	IPPROTO_ROUTING		= 43,		/* IPv6 routing header.  */
#endif
#ifndef IPPROTO_FRAGMENT
	IPPROTO_FRAGMENT	= 44,		/* IPv6 fragmentation header.  */
#endif
#ifndef IPPROTO_RSVP
	IPPROTO_RSVP		= 46,		/* Reservation Protocol.  */
#endif
#ifndef IPPROTO_GRE
	IPPROTO_GRE		= 47,		/* General Routing Encapsulation.  */
#endif
#ifndef IPPROTO_ESP
	IPPROTO_ESP		= 50,		/* encapsulating security payload.  */
#endif
#ifndef IPPROTO_AH
	IPPROTO_AH		= 51,		/* authentication header.  */
#endif
#ifndef IPPROTO_ICMPV6
	IPPROTO_ICMPV6		= 58,		/* ICMPv6.  */
#endif
#ifndef IPPROTO_NONE
	IPPROTO_NONE		= 59,		/* IPv6 no next header.  */
#endif
#ifndef IPPROTO_DSTOPTS
	IPPROTO_DSTOPTS		= 60,		/* IPv6 destination options.  */
#endif
#ifndef IPPROTO_MTP
	IPPROTO_MTP		= 92,		/* Multicast Transport Protocol.  */
#endif
#ifndef IPPROTO_IPIP
	IPOROTO_IPIP		= 94,		/* IP in IP encapsulation */
#endif
#ifndef IPPROTO_ENCAP
	IPPROTO_ENCAP		= 98,		/* Encapsulation Header.  */
#endif
#ifndef IPPROTO_PIM
	IPPROTO_PIM		= 103,		/* Protocol Independent Multicast.  */
#endif
#ifndef IPPROTO_COMP
	IPPROTO_COMP		= 108,		/* Compression Header Protocol.  */
#endif
#ifndef IPPROTO_SCTP
	IPPROTO_SCTP		= 132,		/* Stream Control Transmission Protocol.  */
#endif
#ifndef IPPROTO_UDPLITE
	IPPROTO_UDPLITE		= 136,		/* UDP-Lite protocol.  */
#endif
	//IPPROTO_RAW		= 255,		/* Raw IP packets, use OS, its not a packet protocol  */

	IPPROTO_USIPP		= 255		/* dummy to have at least one enum */
};



} // namespace usipp


#endif

