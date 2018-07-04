# MQTT 软件包介绍

> [Paho MQTT](http://www.eclipse.org/paho/downloads.php) 是 Eclipse 实现的 MQTT 协议的客户端，本软件包是在 Eclipse [paho-mqtt](https://github.com/eclipse/paho.mqtt.embedded-c) 源码包的基础上设计的一套 MQTT 客户端程序。
> 

## 文件目录结构

``` {.c}
pahomqtt
├───docs 
│   └───figures                     // 文档使用图片
│   │   api.md                      // API 使用说明
│   │   introduction.md             // 软件包详细介绍
│   │   principle.md                // 实现原理
│   │   README.md                   // 文档结构说明  
│   │   samples.md                  // 软件包示例
│   │   user-guide.md               // 使用指南
│   └───version.md                  // 版本
├───MQTTClient-RT                   // 移植文件
├───MQTTPacket                      // 源文件
├───samples                         // 示例代码
│   └───mqtt_sample.c               // 软件包应用示例代码
├───tests                           // mqtt 功能测试程序
│   LICENSE                         // 软件包许可证
│   README.md                       // 软件包使用说明
└───SConscript                      // RT-Thread 默认的构建脚本
```

## RT-Thread  软件包功能特点

RT-Thread MQTT 客户端功能特点如下：

- 断线自动重连
- pipe 模型，非阻塞 API
- 事件回调机制
- TLS 加密传输

## MQTT 简述

MQTT（Message Queuing Telemetry Transport，消息队列遥测传输协议），是一种基于发布/订阅（publish/subscribe）模式的“轻量级”通讯协议，该协议构建于TCP/IP协议上，由IBM在1999年发布。MQTT最大优点在于，可以以极少的代码和有限的带宽，为连接远程设备提供实时可靠的消息服务。作为一种低开销、低带宽占用的即时通讯协议，使其在物联网、小型设备、移动应用等方面有较广泛的应用。

MQTT是一个基于客户端-服务器的消息发布/订阅传输协议。MQTT协议是轻量、简单、开放和易于实现的，这些特点使它适用范围非常广泛。在很多情况下，包括受限的环境中，如：机器与机器（M2M）通信和物联网（IoT）。其在，通过卫星链路通信传感器、偶尔拨号的医疗设备、智能家居、及一些小型化设备中已广泛使用。

## MQTT  功能特点


MQTT协议运行在TCP/IP或其他网络协议，提供有序、无损、双向连接。其特点包括：

1. 使用的发布/订阅消息模式，它提供了一对多消息分发，以实现与应用程序的解耦。
2. 对负载内容屏蔽的消息传输机制。
3. 对传输消息有三种服务质量（QoS）：
	1. 最多一次，这一级别会发生消息丢失或重复，消息发布依赖于底层TCP/IP网络。即：<=1
	2. 至多一次，这一级别会确保消息到达，但消息可能会重复。即：>=1
	3. 只有一次，确保消息只有一次到达。即：＝1。在一些要求比较严格的计费系统中，可以使用此级别
4. 数据传输和协议交换的最小化（协议头部只有2字节），以减少网络流量
5. 通知机制，异常中断时通知传输双方
