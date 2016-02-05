%title 使用十六进制编辑文件

%date  02/05/2016 Fri 

## 以二进制方式打开文件

以二进制方式打开，是为了防止内容丢失

```bash
vim -b filename
```

或打开后使用vim内部命令

```bash
:set binary
```

## 使用外部命令xxd将内容转换为十六进制后编辑

使用vim命令：

```bash
:%!xxd
```

## 编辑后使用xxd转换回来后保存

使用vim命令：

```bash
:%!xxd -r
```

