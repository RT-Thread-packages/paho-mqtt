# Hello API

[MQTT](http://mqtt.org/)（Message Queuing Telemetry Transport，消息队列遥测传输协议），是一种基于发布/订阅（publish/subscribe）模式的“轻量级”通讯协议，该协议构建于TCP/IP协议上，由 IBM 在 1999 年发布。

## 打招呼

> 注意：对于函数介绍，必须遵循下面的格式

`int hello_func(void)`

> 在这里需要介绍 hello_func 函数的主要功能

| 参数              | 描述                                |
|:------------------|:------------------------------------|
|`无`               | 无参数                              |
| **返回**          | **描述**                                |
|0                  | 正确执行                            |
|-1                 | 失败                                |

示例(可选)

```c
#include <hello.h>

int func()
{
    hello_func();
    
    return 0;
}
```
