# MQTT 使用说明

## 准备工作

在 BSP 目录下使用 menuconfig 命令打开 env 配置界面，选中 paho-mqtt 软件包，然后使用 `pkgs--update` 命令下载软件包并添加到工程中即可。

![1530238326775](assets/1530238326775.png)

## 测试介绍

### 使能测试程序

`tests/mqtt_test.c` 测试程序提供了一个`客户端`、`服务器`稳定性测试的例程，
用户可以通过简单配置 MQTT 服务器 URI，QOS 消息服务质量，既可完成 MQTT 客户端和服务器端的测试。

使用 MQTT 测试程序需要在 `menuconfig`  中使能 `Enable MQTT test`。

- 配置使能测试例程选项 `Enable MQTT test`

### 修改测试程序

将 `tests/mqtt_test.c` 程序中的如下配置，对应修改为您要测试的 MQTT 服务器配置信息即可。

```
#define MQTT_TEST_SERVER_URI    "tcp://iot.eclipse.org:1883"
#define MQTT_CLIENTID           "rtthread-mqtt"
#define MQTT_USERNAME           "admin"
#define MQTT_PASSWORD           "admin"
#define MQTT_SUBTOPIC           "/mqtt/test"
#define MQTT_PUBTOPIC           "/mqtt/test"
#define MQTT_WILLMSG            "Goodbye!"
#define MQTT_TEST_QOS           1
```

### 运行测试程序

- 使用 `mqtt_test start` 命令启动 MQTT 测试程序
- 使用 `mqtt_test stop` 命令停止 MQTT 测试程序

运行日志如下所示：

```
msh />mqtt_test start
[tls]mbedtls client struct init success...
[MQTT] ipv4 address port: 1884

...

[tls]Certificate verified success...
[MQTT] tls connect success...
[MQTT] Subscribe #0 /mqtt/test OK!
test start at '946725803'
==== MQTT Stability test ====
Server: ssl://yourserverhost.com:1884
QoS   : 1
Test duration(sec)            : 49463
Number of published  packages : 98860
Number of subscribed packages : 98860
Packet loss rate              : 0.00%
Number of reconnections       : 0
==== MQTT Stability test stop ====
```

## 背景信息（可选）

## 步骤一（可选）

## 步骤二（可选）

## 步骤三（可选）

## 预期结果（可选）

## 示例（可选）

## 完成后的操作（可选）

## 引用链接（可选）