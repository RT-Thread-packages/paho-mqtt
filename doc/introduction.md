# MQTT 介绍

> [MQTT](http://mqtt.org/)（Message Queuing Telemetry Transport，消息队列遥测传输协议），是一种基于发布/订阅（publish/subscribe）模式的“轻量级”通讯协议，该协议构建于TCP/IP协议上，由 IBM 在 1999 年发布。
>
> [Paho MQTT](http://www.eclipse.org/paho/downloads.php) 是 Eclipse 实现的 MQTT 协议的客户端，本软件包是在 Eclipse [paho-mqtt](https://github.com/eclipse/paho.mqtt.embedded-c) 源码包的基础上设计的一套 MQTT 客户端程序。

## 文件目录结构

``` {.c}
pahomqtt
│   README.md                       // 软件包使用说明
│   SConscript                      // RT-Thread 默认的构建脚本
├───docs 
│   │   api.md                      // API 使用说明
│   │   introduction.md             // 软件包详细介绍
│   │   port.md                     // 移植说明文档
│   └───user-guide.md               // 用户手册
├───MQTTClient-RT                   // 移植文件
├───MQTTPacket                      // 源文件
├───samples                         // 示例代码
│   └───mqtt_sample.c               // 软件包应用示例代码
└───tests                           // mqtt 功能测试程序
```

## MQTT  功能特点

可以通过 mqtt 软件包的基本功能是按照一定的规则向服务器订阅或者发布 topic，除此之外 RT-Thread MQTT 客户端还有如下功能特点：

- 断线自动重连
- pipe 模型，非阻塞 API
- 事件回调机制
- TLS 加密传输

## 常用术语介绍

**网络连接 Network Connection**

MQTT使用的底层传输协议基础设施。

- 客户端使用它连接服务端。
- 它提供有序的、可靠的、双向字节流传输。

**应用消息 Application Message**
MQTT协议通过网络传输应用数据。应用消息通过MQTT传输时，它们有关联的服务质量（QoS）和主题（Topic）。

**客户端 Client**
使用MQTT的程序或设备。客户端总是通过网络连接到服务端。它可以：

- 发布应用消息给其它相关的客户端。
- 订阅以请求接受相关的应用消息。
- 取消订阅以移除接受应用消息的请求。
- 从服务端断开连接。

**服务端 Server**
一个程序或设备，作为发送消息的客户端和请求订阅的客户端之间的中介。服务端接受来自客户端的网络连接。

- 接受客户端发布的应用消息。
- 处理客户端的订阅和取消订阅请求。
- 转发应用消息给符合条件的已订阅客户端。

**订阅 Subscription**
订阅包含一个主题过滤器（Topic Filter）和一个最大的服务质量（QoS）等级。订阅与单个会话（Session）关联。会话可以包含多于一个的订阅。会话的每个订阅都有一个不同的主题过滤器。

**主题名 Topic Name**
附加在应用消息上的一个标签，服务端已知且与订阅匹配。服务端发送应用消息的一个副本给每一个匹配的客户端订阅。

**主题过滤器 Topic Filter**
订阅中包含的一个表达式，用于表示相关的一个或多个主题。主题过滤器可以使用通配符。

**会话 Session**
客户端和服务端之间的状态交互。一些会话持续时长与网络连接一样，另一些可以在客户端和服务端的多个连续网络连接间扩展。

**控制报文 MQTT Control Packet**
通过网络连接发送的信息数据包。MQTT规范定义了十四种不同类型的控制报文，其中一个（PUBLISH报文）用于传输应用消息。