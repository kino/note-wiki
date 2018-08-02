%title 丢包的原因


导致端口丢包的原因总结起来包括如下几种可能性：

1. 由于某些接口、链路、双工异常导致的CRC错误、Alignment帧bit丢失等常见错误，此类报文交换机将予以丢弃
   * 查看端口计数，是否由较多CRC、冲突帧等。
   * show interface，show interface counter
2. QOS限速、Rate-limit配置导致的数据包正常丢弃。（不计入端口统计计数）
3. 端口BLOCK（STP）导致的数据包正常丢弃。（计入端口统计计数）
   * 查看端口生成树状态。
   * show spanning-tree summary，show spanning-tree interface
4. 对端设备发送的速率过快导致本端交换机buffer不足，而又没有流控导致的丢包
   * 尝试两端打开流控，观察。
5. 多端口向一个端口发送报文，超出这个端口的转发能力，导致的HOL队头阻塞丢包
   * 尝试调整端口速率和打开流控，观察。
6. 针对特殊TCP/UDP运用，最后需要通过在PC端抓包确认故障特点。

参考下面的信息收集方法：
其中最常见的4/5两种类型的溢出，通过查看端口的计数器，定位受影响的端口并打开两端的流控一般都能解决问题。
从目前实际遇到的案例来看，也基本都是由于以上两种原因导致的丢包故障。如仍无法解决，请收集上层计数与底层计数信息提供后台分析判断。

注意：收集上下层信息的同时，注意收集信息的充分性，多次收集的上层信息必须有发现drop 计数的递增，这几次收集间隔中底层的信息都必须相应收集到。