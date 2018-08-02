%title Commands

%date 2015-03-11 Wen 06:33 PM

## 限制抓包个数

```bash
 tcpdump -c100
```

## 写入文件

```bash
 tcpdump -c100 -w o.dump
 tcpdump -c100 | tee o.dump
```

## 指定设备

```bash
 tcpdump -i eth0
```

## 过滤地址

```bash
 tcpdump host 10.2.6.201
 tcpdump src 10.2.6.201
 tcpdump dst 10.2.6.201
 # 过滤网络
 tcpdump net 10.2.6
```

## 过滤协议

```bash
tcpdump ip
tcpdump tcp
tcpdump udp
```
## 过滤size

```bash
tcpdump greater 200
```

## 过滤端口

```bash
tcpdump port 8080
```
 
