#ifndef __PAHO_MQTT_H__
#define __PAHO_MQTT_H__

#include <stdint.h>

#include <MQTTPacket.h>

#ifndef MAX_MESSAGE_HANDLERS
#define MAX_MESSAGE_HANDLERS    1 /* redefinable - how many subscriptions do you want? */
#endif

#define MAX_PACKET_ID           65535 /* according to the MQTT specification - do not change! */

enum QoS { QOS0, QOS1, QOS2 };

/* all failure return codes must be negative */
enum returnCode { BUFFER_OVERFLOW = -2, FAILURE = -1, SUCCESS = 0 };

typedef struct MQTTMessage
{
    enum QoS qos;
    unsigned char retained;
    unsigned char dup;
    unsigned short id;
    void *payload;
    size_t payloadlen;
} MQTTMessage;

typedef struct MessageData
{
    MQTTMessage* message;
    MQTTString* topicName;
} MessageData;

typedef struct MQTTClient MQTTClient;

struct MQTTClient
{
    const char *host;
    int port;
    int sock;

    MQTTPacket_connectData condata;

    unsigned int next_packetid, command_timeout_ms;
    size_t buf_size, readbuf_size;
    unsigned char *buf, *readbuf;
    unsigned int keepAliveInterval;
    int isconnected;
    uint32_t tick_ping;

    void (*connect_callback) (MQTTClient*); /* 连接过程回调 */
    void (*online_callback) (MQTTClient*);  /* 成功上线回调 */
    void (*offline_callback) (MQTTClient*); /* 离线状态回调 */

    struct MessageHandlers
    {
        const char* topicFilter;
        void (*callback) (MQTTClient*, MessageData*);
    } messageHandlers[MAX_MESSAGE_HANDLERS]; /* Message handlers are indexed by subscription topic */

    void (*defaultMessageHandler) (MQTTClient*, MessageData*);

    /* publish sock */
    int pub_sock;
    int pub_port;
};

extern int paho_mqtt_start(MQTTClient *client);
extern int MQTTPublish(MQTTClient* c, const char* topicName, MQTTMessage* message); /* copy */

#endif /* __PAHO_MQTT_H__ */
