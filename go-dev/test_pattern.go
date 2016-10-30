
package main

import (
    "errors"
    "regexp"
    "fmt"
)

func main() {
    var re *regexp.Regexp = nil
    var err error
    var pattern string = ".*.go"
    if re, err = regexp.Compile(pattern); err != nil {
        fmt.Println("err", err)
        return
    }
    var fileName = "ucloud.cn/ulog/logext.go"
    if re.Match([]byte(fileName)) {
        fmt.Println("match", fileName)
    } else {
        fmt.Println("don't match", fileName)
    }

    var count int = 0
    fmt.Println("out count=", count)
    count++
    fmt.Println("out count=", count)
    for ; count < 4; count++ {
        fmt.Println("count=", count)
    }

    err = errors.New("TestError")
    fmt.Println(err)
    err = nil
    fmt.Println(err)
}
