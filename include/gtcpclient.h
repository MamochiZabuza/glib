#ifndef _G_TCP_CLIENT_H_
#define _G_TCP_CLIENT_H_
#include "glib.h"
#include "gevent.h"

typedef enum
{
	TCP_CLIENT_STATUS_CREATED,
	TCP_CLIENT_STATUS_CONNECTED,
	TCP_CLIENT_STATUS_CLOSED,
	TCP_CLIENT_STATUS_ERROR
} GTcpClientStatus;

typedef struct _GTcpClient GTcpClient;
typedef struct _GTcpPacket GTcpPacket;

struct _GTcpPacket
{
	gint parse_state;
};

struct _GTcpClient 
{
	gint no;
	gstring url;
	gstring host;
	gint port;
	ghandle handle;
	GTcpClientStatus status;
	GTcpPacket * packet;	
	GEvent * event_packet_received;
	GEvent * event_status_changed;
	void (*delegate_parse_packet)(GTcpClient * self, gpointer buffer, gint buflen, gint * read);
};

GTcpClient * g_tcp_client_new(void);
void g_tcp_client_free(GTcpClient * self);

void g_tcp_client_process_packet(GTcpClient * self);
gboolean g_tcp_client_connect(GTcpClient * self, gstring url);
void g_tcp_client_disconnect(GTcpClient * self);
void g_tcp_client_send(GTcpClient* self, gpointer buffer, gint buflen);
gboolean g_tcp_client_is_active(GTcpClient* self);

void g_tcp_packet_begin_segment(GTcpPacket * self, gint size);
gboolean g_tcp_packet_read_segment(GTcpPacket * self, gpointer buffer, gint buflen, gint * read);
void g_tcp_packet_end_segment(GTcpPacket * self, gpointer * buffer, gint * buflen);
void g_tcp_packet_get_buffer(GTcpPacket * self, gpointer * buffer, gint * buflen);

void g_tcp_get_traffic(gint * income, gint * outcome);
void g_tcp_reset_traffic();

#endif