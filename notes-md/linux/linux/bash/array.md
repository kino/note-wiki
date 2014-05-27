%title Bash 数组

%date 2014-05-13 Tue 09:13 PM

## Array 初始化

```bash
 # 方法一
 area[11]=23
 area[13]=37
 area[51]=UFOs
 

 # 方法二
 # array_name=( XXX YYY ZZZ ... )
 area2=( zero one two three four )
 
 # 方法三
 # array_name=([xx]=XXX [yy]=YYY ...)
 area3=([17]=seventeen [24]=twenty-four)
 
 # 用引号包含空格
 array2=( [0]="first element" [1]="second element" [3]="fourth element" )
 #            ^     ^       ^     ^      ^       ^     ^      ^       ^
 
 # 使用自动扩展
 base64_charset=( {A..Z} {a..z} {0..9} + / = )
 
 # 数组操作允许用于普通变量，相当于只有一个element的数组
```

## Array 取值

```bash
 echo ${area[11]}
 
 #未初始化的返回空白blank
 echo ${area[43]}
 
 area[5]=`expr ${area[11]} + ${area[13]}`

 #失败，因为数字与字符串不能相加
 area[6]=`expr ${area[11]} + ${area[51]}`
```

## Array 长度操作

```bash
 array=( zero one two three four five )
 # Element 0   1   2    3     4    5
 
 echo ${array[0]}       #  zero
 echo ${array:0}        #  zero
                        #  Parameter expansion of first element,
                        #+ starting at position # 0 (1st character).
 echo ${array:1}        #  ero
                        #  Parameter expansion of first element,
                        #+ starting at position # 1 (2nd character).
 
 echo "--------------"
 
 echo ${#array[0]}      #  4
                        #  Length of first element of array.
 echo ${#array}         #  4
                        #  Length of first element of array.
                        #  (Alternate notation)
 
 echo ${#array[1]}      #  3
                        #  Length of second element of array.
                        #  Arrays in Bash have zero-based indexing.
 
 echo ${#array[*]}      #  6
                        #  Number of elements in array.
 echo ${#array[@]}      #  6
                        #  Number of elements in array.
```

## Array 字符串操作

```bash
 #  In general, any string operation using the ${name ... } notation
 #+ can be applied to all string elements in an array,
 #+ with the ${name[@] ... } or ${name[*] ...} notation.
 
 
 arrayZ=( one two three four five five )
 
 echo
 
 # Trailing Substring Extraction
 echo ${arrayZ[@]:0}     # one two three four five five
 #                ^        All elements.
 
 echo ${arrayZ[@]:1}     # two three four five five
 #                ^        All elements following element[0].
 
 echo ${arrayZ[@]:1:2}   # two three
 #                  ^      Only the two elements after element[0].
 
 # 其它类似
```

## Array 片段

## Array 修改


## Array 循环读取
