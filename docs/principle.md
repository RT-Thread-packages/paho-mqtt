# MQTT 工作原理

![img](figures/mqtt_principle.png) 

实现MQTT协议需要客户端和服务器端。

在 MQTT 协议中有三种身份：发布者（Publish）、代理（Broker）（服务器）、订阅者（Subscribe）。其中消息的发布者和订阅者都是客户端，消息代理是服务器，消息发布者可以同时是订阅者。

发布者和订阅者可以通过消息代理向特定 Tocpic 发布消息，订阅者可以通过消息代理接收特定 Topic 的消息，这种方式可以实现高效的数据交换。

