

/*
实现一个 Reader 类型，它不断生成 ASCII 字符 'A' 的流。
*/
package main

import "golang.org/x/tour/reader"

type MyReader struct{}

// TODO: Add a Read([]byte) (int, error) method to MyReader.

func (r MyReader) Read(b []byte) (int, error) {
    b[0] = byte('A')
    return 1, nil
}

func main() {
    reader.Validate(MyReader{})
}


