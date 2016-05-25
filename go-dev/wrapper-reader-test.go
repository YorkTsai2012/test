/*
一个常见模式是 io.Reader 包裹另一个 `io.Reader`，然后通过某种形式修改数据流。

例如，gzip.NewReader 函数接受 `io.Reader`（压缩的数据流）并且返回同样实现了 io.Reader 的 `*gzip.Reader`（解压缩后的数据流）。

编写一个实现了 io.Reader 的 `rot13Reader`， 并从一个 io.Reader 读取， 利用 rot13 代换密码对数据流进行修改。

已经帮你构造了 rot13Reader 类型。 通过实现 Read 方法使其匹配 `io.Reader`。
*/

package main

import (
	"fmt"
	"io"
	"os"
	"strings"
)

type rot13Reader struct {
	r io.Reader
}

func (rot rot13Reader) Read(b []byte) (int, error) {
	n, err := rot.r.Read(b)
	if err != io.EOF {
		for i := 0; i < n; i++ {
			b[i] = b[i] + 1
		}
	}
    fmt.Printf("n = %v\n", n)
	return n, err
}

func main() {
	s := strings.NewReader("Lbh penpxrq gur pbqr!")
	r := rot13Reader{s}
	io.Copy(os.Stdout, &r)
	fmt.Println()
}
