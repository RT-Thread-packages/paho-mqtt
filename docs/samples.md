#  MQTT 示例程序

## 获取示例
本节介绍获取 paho-mqtt 软件包后，首先需要在 BSP 目录下打开 env 配置界面，然后遵循如下配置流程。

- 配置使能示例选项 `Enable MQTT example`
- 配置使能测试例程 `Enable MQTT test`
- 配置使能 TLS 安全传输选项 `Enable support tls protocol`
- 设置 MQTT 能订阅的最大 topic 主题数量 `Max pahomqtt subscribe topic handlers`
- 配置包版本选为最新版 `latest_version`

![](figures/paho-mqtt-menuconfig.png)

## 运行示例
`samples/mqtt_sample.c` 例程提供了一个基础的 MQTT 发布订阅演示，在 RT-Thread MSH 中运行 MQTT 示例，需要开启 MSH 的支持。

测试服务器使用 Eclipse 的测试服务器，地址 `iot.eclipse.org` ，端口 `1883`.

- 开启 MSH  
使用 menuconfig 开启 MSH 支持：
```.{c}
  RT-Thread Components --->
      Command shell --->
          [*] Using module shell
          [*]     Using module shell in default
          [ ]     Only using module shell
```
- MSH log

启动 MQTT 客户端：
```.{c}
msh />
msh />mq_start
inter mqtt_connect_callback! 
ipv4 address port: 1883
[MQTT] HOST =  'iot.eclipse.org'
msh />[MQTT] Subscribe #0 /mqtt/test OK!
inter mqtt_online_callback! 
msh />
```
发布消息：
```.{c}
msh />
msh />mq_pub hello-rtthread
msh />mqtt sub callback: /mqtt/test hello-rtthread

msh />
```

