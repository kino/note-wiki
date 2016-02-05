%title Bash 特殊字符

%date 2016 2/2

## << Here Docuemnt

Here Document 用于将一段文本或代码作为标准输入传递给另外的程序或命令。
它使用一个终止标志符来表示输入终止，默认保留空格、换行符等。
如果需要去掉开头的tab，可以在终止标志符前加一个-，比如： <<-EOF
使用格式：

```bash
#!/bin/bash
command <<MyUniqueLimitString
some text
some more text 
MyUniqueLimitString

#还可以用作多人注释,冒号作为命令，表示什么也不做
:<<MyUniqueLimitString
some text
some more text 
MyUniqueLimitString
```

## <<< Here Strings

```bash
command <<< $word
command <<< "$word"

#将变量$word展开，并将其作为命令command的标准输入
```
