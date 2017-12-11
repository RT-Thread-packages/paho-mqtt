#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <rtthread.h>

#include "paho_mqtt.h"

#define MQTT_HOST				"iot.eclipse.org"			
#define MQTT_PORT				1883	
#define MQTT_CLIENTID			"my_clientID"
#define MQTT_USERNAME			"123456"
#define MQTT_PASSWORD			"123456"
#define MQTT_SUBTOPIC			"/mqtt/test"
#define MQTT_PUBTOPIC			"/mqtt/test"
#define MQTT_SENDMSG			"Hello world!"
#define MQTT_WILLMSG			"Goodbye!"

static MQTTClient client; /* 客户端实例 */

static void mqtt_callback(MQTTClient *c, MessageData *msg_data)
{
	*((char *)msg_data->message->payload + msg_data->message->payloadlen) = '\0';
    printf("mqtt_callback: %s %s\n", msg_data->topicName->lenstring.data, (char *)msg_data->message->payload);

    return;
}

static void mqtt_connect_callback(MQTTClient *c)
{
    printf("inter mqtt_connect_callback! \n");
}

static void mqtt_online_callback(MQTTClient *c)
{
    printf("inter mqtt_online_callback! \n");
}

static void mqtt_offline_callback(MQTTClient *c)
{
   printf("inter mqtt_offline_callback! \n");
}

static void mq_start(void)
{
    MQTTPacket_connectData condata = MQTTPacket_connectData_initializer;

    client.host = MQTT_HOST;
    client.port = MQTT_PORT;

    memcpy(&client.condata, &condata, sizeof(condata));
    client.condata.clientID.cstring = MQTT_CLIENTID;
    client.condata.keepAliveInterval = 60;
    client.condata.cleansession = 1;
    client.condata.username.cstring = MQTT_USERNAME;
    client.condata.password.cstring = MQTT_PASSWORD;

    /* create MQTT will. */
	if(1)
    {
        client.condata.willFlag = 1;
        client.condata.will.qos = 1;
        client.condata.will.retained = 0;
        client.condata.will.topicName.cstring = MQTT_PUBTOPIC; 
        client.condata.will.message.cstring = MQTT_WILLMSG;
    } /* create MQTT will. */

    /* malloc buffer. */
    client.buf_size = client.readbuf_size = 1024;
    client.buf = malloc(client.buf_size);
    client.readbuf = malloc(client.readbuf_size);
    if(!(client.buf && client.readbuf))
    {
        printf("no memory for MQTT client buffer!\n");
        goto _exit;
    }

    client.connect_callback = mqtt_connect_callback;
    client.online_callback = mqtt_online_callback;
    client.offline_callback = mqtt_offline_callback;

    /* set Subscribe table. */
    client.messageHandlers[0].topicFilter = MQTT_SUBTOPIC; /* 我想定阅的 topic */
    client.messageHandlers[0].callback = mqtt_callback;

    client.defaultMessageHandler = mqtt_callback;/* 默认消息回调 */

	paho_mqtt_start(&client);

_exit:
    return;
}

static void mq_publish(const char * send_str)
{
    MQTTMessage message;
	const char *msg_str = send_str;
	const char *topic = MQTT_PUBTOPIC;
    message.qos = 1;
    message.retained = 0;
    message.payload = (void*)msg_str;
    message.payloadlen = strlen(message.payload);

	MQTTPublish(&client, topic, &message);

    return;
}

#ifdef RT_USING_FINSH
#include <finsh.h>
FINSH_FUNCTION_EXPORT(mq_start, startup mqtt client);
FINSH_FUNCTION_EXPORT(mq_publish, publish mqtt msg);
#ifdef FINSH_USING_MSH
MSH_CMD_EXPORT(mq_start, startup mqtt client);

int mq_pub(int argc, char **argv)
{
	if(argc != 2 )
	{
		printf("More than two input parameters err!!\n");
		return 0;
	}
	mq_publish(argv[1]);

	return 0;
}
MSH_CMD_EXPORT(mq_pub, publish mqtt msg);
#endif /* FINSH_USING_MSH */
#endif /* RT_USING_FINSH */