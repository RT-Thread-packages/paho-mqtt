# MQTT 软件包移植说明

MQTT 软件包已经被移植到 RT-Thread 操作系统上，在 BSP 目录下使用 menuconfig 命令打开 env 配置界面，选中 paho-mqtt 软件包，然后使用 `pkgs--update` 命令下载软件包并添加到工程中即可。

![1530238326775](assets/1530238326775.png)